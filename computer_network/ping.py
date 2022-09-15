from asyncio import protocols
from msilib import sequence
import socket
import struct
import sys
import time
import os
import statistics
from functools import reduce
import argparse


class IPHdr:
    IP_DEFAULT_SIZE = 20
    
    def __init__(self, proto=socket.IPPROTO_ICMP, src='0.0.0.0', dst='127.0.0.1', data=''):
        self.src = socket.inet_aton(src)
        self.dst = socket.inet_aton(dst)
        self.proto = proto
        self.ip_ver = 4
        self.ip_hl = 5
        self.tos = 0
        self.tol = 0
        self.fid = 0
        self.f_rsv = 0
        self.f_dtf = 0
        self.f_mrf = 0
        self.f_offset = 0
        self.ttl = 255
        self.checksum = 0
        self.data = data if isinstance(data, bytes) else data.encode()
        

    def assemble(self):
        ver_hl = (self.ip_ver << 4) + self.ip_hl
        flagment = (self.f_rsv << 15) + (self.f_dtf << 14) + (self.f_mrf << 13) + (self.f_offset & 0x1FFF)
            
        header = struct.pack('!BBHHHBBH4s4s', ver_hl, self.tos, self.tol, self.fid, flagment, self.ttl, self.proto, 
        self.checksum, self.src, self.dst)

        header += self.data

        return header
        
    @classmethod
    def disassemble(cls, raw_data):
        ip_hdr = IPHdr()
        if len(raw_data) > cls.IP_DEFAULT_SIZE:
            payload = raw_data[cls.IP_DEFAULT_SIZE:]
            raw_data = raw_data[:cls.IP_DEFAULT_SIZE]
        else:
            payload = ''.encode()
        ip = struct.unpack('!BBHHHBBH', raw_data[:-8])

        ip_hdr.ip_ver = ip[0] >> 4
        ip_hdr.ip_hl = ip[0] & 0x0F
        ip_hdr.tos = ip[1]
        ip_hdr.tol = ip[2]
        ip_hdr.fid = ip[3]
        flag = ip[4] >> 13
        ip_hdr.f_rsv = flag >> 2
        ip_hdr.f_dtf = (flag & 0x02) >> 1
        ip_hdr.f_mrf = flag & 0x01
        ip_hdr.f_offset = ip[4] & 0x1FFF
        ip_hdr.ttl = ip[5]
        ip_hdr.proto = ip[6]
        ip_hdr.checksum = ip[7]
        ip_hdr.src = raw_data[12:16]
        ip_hdr.dst = raw_data[16:20]
        ip_hdr.data = payload

        return ip_hdr


class ICMPHdr:
    ICMP_DEFAULT_SIZE = 8
    
    def __init__(self, type=8, code=0, checksum=0, id=0, seq=0, data=''):
        self.type = type
        self.code = code
        self.checksum = checksum
        self.id = id
        self.seq = seq
        self.data = data if isinstance(data, bytes) else data.encode()

    @staticmethod
    def make_checksum(header):
        size = len(header)
        if (size % 2) == 1:
            header += b'\x00'
            size += 1
        size = size // 2
        header = struct.unpack('!' + str(size) + 'H', header)
        sum = reduce(lambda x, y: x + y, header)
        chksum = (sum >> 16) + (sum & 0xffff)
        chksum += chksum >> 16
        chksum = (chksum ^ 0xffff)

        return chksum

    def assemble(self):
        type_code_part = struct.pack('BB', self.type, self.code)
        id_seq_part = struct.pack('!HH', self.id, self.seq)
        checksum = self.make_checksum(type_code_part + b'\x00\x00' + id_seq_part + self.data)
        self.checksum = checksum

        return type_code_part + struct.pack('!H', self.checksum) + id_seq_part + self.data

    @classmethod
    def disassemble(cls, raw_data):
        icmp_hdr = cls()
        if len(raw_data) > cls.ICMP_DEFAULT_SIZE:
            payload = raw_data[cls.ICMP_DEFAULT_SIZE:]
            raw_data = raw_data[:cls.ICMP_DEFAULT_SIZE]
        else:
            payload = ''.encode()
            
        icmp_hdr.type, icmp_hdr.code, icmp_hdr.checksum, icmp_hdr.id, icmp_hdr.seq = struct.unpack('!BBHHH', raw_data )
        icmp_hdr.data = payload

        return icmp_hdr
        

def gen_echo_req(count, id, data_len):
    data = 'a' * data_len
    icmp = ICMPHdr(id=id, data=data)
    
    for i in range(count):
        icmp.seq = i
        yield icmp

def recv_echo_resp(sock, id, seq, timeout):
    time_left = timeout
    
    try:
        while True:
            sock.settimeout(time_left)
            
            started_time = time.time()
            pkt = sock.recv(65535)
            received_time =time.time()
            
            ip = IPHdr.disassemble(pkt)
            echo_resp = ICMPHdr.disassemble(ip.data)
            
            if echo_resp.id == id and echo_resp.seq == seq and echo_resp.type == 0:
                return received_time, ip.src, len(pkt) - ip.ip_hl*4, ip.ttl, echo_resp.seq
                
            time_left = time_left - (received_time - started_time)
                
            if time_left <= 0:
                return None, None, None, None, None

    except socket.timeout:
        return None, None, None, None, None
                
def print_ping_statistics(dst_addr, sent_packets, recv_packets, rtts):
    print('--- {} ping statistics ---'.format(dst_addr))
    
    loss_rate = float(sent_packets - recv_packets) / sent_packets * 100
    
    print('{sent} packets transmitted, {recv} packets received, {loss:.3f}% packet loss'.format(
        sent=sent_packets,
        recv=recv_packets, loss=loss_rate))

    rtt_avg = sum(rtts) / float(len(rtts))
    
    print('round-trip min/avg/max/std-dev = {rtt_min:.3f}/{rtt_avg:.3f}/{rtt_max:.3f}/{rtt_std:.3f} ms'.format(
        rtt_min=min(rtts) * 1000, rtt_avg=rtt_avg * 1000, rtt_max=max(rtts) * 1000,
        rtt_std=statistics.stdev(rtts) * 1000))

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='ping by famous')
    parser.add_argument('host', type=str, metavar='DST ADDR', help='destination address')
    parser.add_argument('len', type=int, nargs='?', metavar='LENGTH', help='payload length', default=10)
    parser.add_argument('-c', type=int, metavar='COUNT', help='number of iteration', default=5)
    parser.add_argument('-w', type=int, metavar='TIMEOUT', help='receive timeout', default=3)
    parser.add_argument('-i', type=int, metavar='INTERVAL', help='send INTERVAL', default=1)
    args = parser.parse_args()
    host = args.host
    length = args.len
    count = args.c
    timeout = args.w
    interval = args.i

    rtt_list = []
    sent_packet_count = 0
    recv_packet_count = 0

    try:
        dst_addr = socket.gethostbyname(host)
        print('PING {0} ({1}) {2}({3}) bytes of data.'.format(dst_addr, host, length,
                                                            length + ICMPHdr.ICMP_DEFAULT_SIZE + 20))

    except socket.gaierror:
        print('Can not resolve host ip address from {0}'.format(host))
        sys.exit(-1)
        
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP) as sock:
            sock.connect((dst_addr, 0))

            echo_id = os.getpid() & 0xFFFF

            for echo_req in gen_echo_req(count=count, data_len=length, id=echo_id):
                sock.send(echo_req.assemble())
                sent_time = time.time()
                sent_packet_count += 1
                received_time, src_addr, data_length, ttl, seq = recv_echo_resp(
                sock=sock, id=echo_req.id,seq=echo_req.seq, timeout=timeout
            )

            if received_time:
                src_addr = socket.inet_ntoa(src_addr)
                rtt = (received_time - sent_time)

                rtt_list.append(rtt)

                print('{data_length} bytes from {src_addr}: icmp seq={seq} ttl={ttl} time={rtt:.3f} ms'
                .format(data_length=data_length,src_addr=src_addr, seq=seq, ttl=ttl, rtt=rtt*1000))

                recv_packet_count += 1

            else:
                print('receive timeout... ')

            time.sleep(interval)
            
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(e)
        sys.exit(-1)
            
    print_ping_statistics(dst_addr=dst_addr, sent_packets=sent_packet_count, recv_packets=recv_packet_count,
    rtts=rtt_list)
