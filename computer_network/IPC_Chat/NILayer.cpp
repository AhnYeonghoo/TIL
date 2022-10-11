#include "stdafx.h"
#include "pch.h"
#include "NILayer.h"
#include "EthernetLayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif
#define _CRT_SECURE_NO_WARNINGS

//////////////////////////////////////////////////////////////////////
// 생성자/ 소멸자
//////////////////////////////////////////////////////////////////////

CNILayer::CNILayer(char* pName, pcap_t* pAdapterObject, int iNumAdapter)
	: CBaseLayer(pName)
{
	m_AdapterObject = pAdapterObject;
	m_iNumAdapter = iNumAdapter;
	SetNICList();
}

CNILayer::~CNILayer()
{
}

// NICList를 설정해주는 함수입니다.
void CNILayer::SetNICList() {
	pcap_if_t* d;
	char errbuf[256];

	if (pcap_findalldevs(&m_allDevs, errbuf) == -1) {
		AfxMessageBox(_T("에러!"));
		exit(1);
	}

	for (d = m_allDevs; d; d = d->next)
		m_iNumAdapter++;
}

// 어댑터를 열어주고 설정합니다.
void CNILayer::setAdapterNum(int index)
{
	char errbuf[256];
	getAdapterName(index);

	if ((m_AdapterObject = pcap_open_live(m_adapterName, 65536, 1, 1000, errbuf)) == NULL)
	{
		fprintf(stderr, "\n어댑터 연결이 불가합니다.\n");
		exit(1);
	}
	m_selectedNum = index;
}

// adapter 개수를 가져옵니다.
int CNILayer::getAdapterNum()
{
	return m_iNumAdapter;
}

// 모든 어댑터 이름을 가져옵니다.
char* CNILayer::getAdapterName(int index)
{
	pcap_if_t* d = m_allDevs; 

	for (int i = 0; i < index; i++)
		d = d->next; 

	strcpy_s(m_adapterName, d->name);

	return m_adapterName;
	// ppt와 동일하게 작성했습니다.
}

// MAC 주소를 설정해줍니다.
void CNILayer::setMacAddress()
{
	LPADAPTER pAdapter = 0;
	DWORD dwErrorCode;
	PPACKET_OID_DATA OidData;
	BOOL Status;
	
	SetNICList();

	OidData = (PPACKET_OID_DATA)malloc(sizeof(PACKET_OID_DATA));
	OidData->Oid = 0x01010101;
	OidData->Length = 6;

	getAdapterName(m_selectedNum);//get adapter name
	pAdapter = PacketOpenAdapter(m_adapterName);//open adapter

	PacketRequest(pAdapter, FALSE, OidData);

	m_MacAddress[0] = OidData->Data[0]; m_MacAddress[1] = OidData->Data[1];
	m_MacAddress[2] = OidData->Data[2]; m_MacAddress[3] = OidData->Data[3];
	m_MacAddress[4] = OidData->Data[4]; m_MacAddress[5] = OidData->Data[5];
	// ppt와 동일하게 작성했습니다.
}

// MAC 주소를 가져오는 함수입니다.
unsigned char* CNILayer::getMacAddress()
{
	return m_MacAddress;
}

// Receive 시에 MAC 어드레스를 가져옵니다.
unsigned char* CNILayer::getReceiveMacAddress() {
	return r_srcAdd;
}

// Send 해주는 함수입니다.
BOOL CNILayer::Send(unsigned char* ppayload, int nlength)
{
	// 패킷을 전송하고 안된다면 메세지를 띄워줍니다.
	if (pcap_sendpacket(m_AdapterObject, ppayload, nlength)) {
		AfxMessageBox(_T("패킷 전송 실패"));
		return FALSE;
	}
	return TRUE;
}

// 쓰레드를 통해 계속 실행되는 함수입니다.
void CNILayer::baseReceive()
{
	struct pcap_pkthdr* header;
	const u_char* pkt_data;
	unsigned char data[ETHER_MAX_SIZE];
	int result;

	while ((result = pcap_next_ex(m_AdapterObject, &header, &pkt_data)) >= 0) {
		CEthernetLayer::ETHERNET_HEADER* temp = (CEthernetLayer::ETHERNET_HEADER*)pkt_data;
		if (result == 0 || temp->enet_type != 1)
			break;

		bool flag = true;
		for (int i = 0; i < 6; i++) {
			if (temp->enet_dstaddr.s_ether_addr[i] != m_MacAddress[i]) flag = false;
		}
		if (!flag) break;

		for (int i = 0; i < 6; i++) {
			r_srcAdd[i] = temp->enet_srcaddr.s_ether_addr[i];
			r_dstAdd[i] = temp->enet_dstaddr.s_ether_addr[i];
		}
		memcpy(data, pkt_data, ETHER_MAX_SIZE);
		BOOL bSuccess = FALSE;
		bSuccess = this->GetUpperLayer(0)->Receive(data);
		break;
	}
	// 패킷을 계속 받고 주소와 type이 같은 것을 구분하여 보내줍니다.
}