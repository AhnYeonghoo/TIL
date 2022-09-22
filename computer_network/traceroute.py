import argparse
import socket
import struct
import sys
import os
import time
from functools import reduce

UDP_PORT = 33501

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
        fragment = (self.f_rsv << 15) + (self.f_dtf << 14) + (self.f_mrf << 13) + (self.f_offset & 0x1FFF)
        
        header = struct.pack('!BBHHHBBH4s4s', ver_hl, self.tos, self.tol, self.fid, fragment, self.ttl, self.proto,
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
        self.type= type
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
        header = struct.unpack('|' + str(size) + 'H', header)
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
        
        icmp_hdr.type, icmp_hdr.code, icmp_hdr.checksum, icmp_hdr.id, icmp_hdr.seq = struct.unpack('!BBHHH', raw_data)
        icmp_hdr.data = payload
        return icmp_hdr

class UDPHdr:
    UDP_DEFAULT_SIZE = 8

    def __init__(self, src_port=5555, dst_port=5555, data=''):
        self.src_port = src_port
        self.dst_port = dst_port
        self.packet_length = 0
        self.checksum = 0
        self.data = data if isinstance(data, bytes) else data.encode()

    @classmethod
    def make_udp_checksum(cls):
        return 0
        
    def assemble(self):
        self.packet_length = len(self.data) + UDPHdr.UDP_DEFAULT_SIZE
        sdl_part = struct.pack("!HHH", self.src_port, self.dst_port, self.packet_length)
        checksum = self.make_udp_checksum()
        checksum = struct.pack("!H", checksum)
        
        return sdl_part + checksum + self.data
        
    @classmethod
    def disassemble(cls, raw_data):
        udp_hdr = UDPHdr()
        if len(raw_data) > cls.UDP_DEFAULT_SIZE:
            payload = raw_data[cls.UDP_DEFAULT_SIZE:]
            raw_data = raw_data[:cls.UDP_DEFAULT_SIZE]
        else:
            payload = ''.encode()
        udp_hdr.src_port, udp_hdr.dst_port, udp_hdr.packet_length, \
        udp_hdr.checksum = struct.unpack('!HHHH', raw_data)
        udp_hdr.data = payload

        return udp_hdr
    
def generate_request(sock, count, echo_id, length, ttl, protocol, udp_port):
    data = 'a' * length
    sock.setsockopt(socket.SOL_IP, socket.IP_TTL, ttl)
        
    request_packet = ICMPHdr(id=echo_id, data=data) if protocol == socket.IPPROTO_ICMP \
        else UDPHdr(src_port=udp_port, dst_port=udp_port, data=data)
        
    for i in range(count):
        if protocol == socket.IPPROTO_ICMP:
            request_packet.seq = i
        yield request_packet

def recv_resp(sock, echo_id, protocol, timeout, sent_packet):
    time_left = timeout
    
    try:
        while True:
            sock.settimeout(time_left)
            started_time = time.time()
            pkt, addr = sock.recvfrom(65535)
            received_time = time.time()
            ip = IPHdr.disassemble(pkt)
            icmp = ICMPHdr.disassemble(ip.data)

            if icmp.type == 11 and icmp.code == 0:
                if protocol == socket.IPPROTO_UDP:
                    if check_response_udp(sent_packet=sent_packet, recv_packet=icmp):
                        return received_time, addr, False
                    else:
                        if check_response_icmp(sent_packet=sent_packet, recv_packet=icmp):
                            return received_time, addr, False
                    
                elif icmp.type == 0 and icmp.code == 0:
                    if icmp.id == echo_id:
                        return received_time, addr, True
                
                elif icmp.type == 3 and icmp.code == 3:
                    if protocol == socket.IPPROTO_UDP:
                        if check_response_udp(sent_packet=sent_packet, recv_packet=icmp):
                            return received_time, addr, True
                
                time_left = time_left - (received_time - started_time)
        
                if time_left <= 0:
                    return None, None, False

    except socket.timeout:
        return None, None, False
        

def check_response_udp(sent_packet, recv_packet):
    ref_ip_hdr = IPHdr.disassemble(recv_packet.data)
    ref_udp_hdr = UDPHdr.disassemble(ref_ip_hdr.data)
    
    return ref_udp_hdr.src_port == sent_packet.src_port and ref_udp_hdr.dst_port == sent_packet.dst_port

def check_response_icmp(sent_packet, recv_packet):
    ref_ip_hdr = IPHdr.disassemble(recv_packet.data)
    ref_icmp_hdr = ICMPHdr.disassemble(ref_ip_hdr.data)
    
    return ref_icmp_hdr.id == sent_packet.id

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='simple traceoute by famous')
    parser.add_argument('host', type=str, metavar='DST ADDR', help='destination address')
    parser.add_argument('size', type=int, nargs='?', default=60, metavar='PACKET_SIZE',
    help='IP packet size, include header size')
    parser.add_argument('-I', type=int, nargs='?', metavar='ICMP ECHO', help='using ICMP ECHO_REQUEST',
    const=socket.IPPROTO_ICMP )
    parser.add_argument('-U', type=int, nargs='?', metavar='UDP', help='using UDP', const=socket.IPPROTO_UDP)
    parser.add_argument('-t', type=float, metavar='RECV_TIME_OUT', help='request timeout', default=1)
    parser.add_argument('-c', type=int, metavar='MAX_HOP', help='max hop count', default=30)
    parser.add_argument('-p', type=int, metavar='PORT_NUM', help='destination port number')
    args = parser.parse_args()
    host = args.host
    timeout = args.t
    packet_size = args.size
    max_hop = args.c
    port = args.p if args else UDP_PORT

    try:
        dst_addr = socket.gethostbyname(host)
        print('traceroute to {0} ({1}), {2} hops max, {3} byte packets.'.format(host, dst_addr, max_hop, packet_size))
    except socket.gaierror:
        print('Can not resolve server address from {0}'.format(host))
        sys.exit(-1)
    
    echo_id = os.getpid() & 0xFFFF
    finished = False
    
    send_protocol = socket.IPPROTO_UDP if args.U else socket.IPPROTO_ICMP
    
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_RAW, send_protocol) as send_socket:
            send_socket.connect((dst_addr, 0))
            for hop in range(1, max_hop + 1):
                print('{0}{1}'.format(hop, ' ' * (5 - len(str(hop)))), end='')
                
                messages = ['','','','']
                tries = 3
                got_response = False
                seq = 0
                
                for request_packet in generate_request(sock=send_socket, count=3, echo_id=echo_id, length=packet_size,
                                            ttl=hop, protocol=send_protocol, udp_port=port):
                        with socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_RAW, socket.IPPROTO_ICMP) as recv_socket:
                            send_socket.send(request_packet.assemble())
                            sent_time = time.time()

                            received_time, addr, finished = recv_resp(sock=recv_socket, echo_id=echo_id, 
                                                                                        protocol=send_protocol,
                                                                                        timeout=timeout,
                                                                                        sent_packet=request_packet)
                            if received_time:
                                messages[seq] = ' {rtt:.3f} ms'.format(rtt=(received_time - sent_time) * 1000)
                                got_response = True
                            else:
                                messages[seq] = '*'
                            seq += 1
                        
                        if got_response and received_time:
                            try:
                                messages[tries] = '[{0}, {1}]'.format(socket.gethostbyaddr(addr[0])[0], addr[0])
                            except socket.gaierror:
                                messages[tries] = '[{0}, {1}]'.format(addr[0], addr[0])
                            except socket.herror:
                                messages[tries] = '[{0}, {1}]'.format(addr[0], addr[0])

                        else:
                            messages[tries] = ''
                            print('   '.join(messages) + ' ')

                            if finished:
                                break
                        
    except PermissionError:
        print("No permission for creating raw socket, try superuser...")
        sys.exit(-1)
    except KeyboardInterrupt:
        print('\nquit')
        sys.exit(0)
