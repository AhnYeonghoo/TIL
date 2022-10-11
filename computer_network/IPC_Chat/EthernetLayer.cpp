// EthernetLayer.cpp: implementation of the CEthernetLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "pch.h"
#include "EthernetLayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// 생성자/ 소멸자
//////////////////////////////////////////////////////////////////////

CEthernetLayer::CEthernetLayer(char* pName)
	: CBaseLayer(pName)
{
	m_NI = (CNILayer*)this->GetUnderLayer();
	ResetHeader();
}

CEthernetLayer::~CEthernetLayer()
{
}

// 헤더를 리셋하는 함수입니다
void CEthernetLayer::ResetHeader()
{
	memset(m_sHeader.enet_data, ETHER_MAX_DATA_SIZE, 6);
	m_sHeader.enet_type = 0;
}

// 송수신지 주소를 받아오는 함수들입니다.
unsigned char* CEthernetLayer::GetSourceAddress()
{
	//return m_NI->GetSourceAddress();
	return 0x00;
}

unsigned char* CEthernetLayer::GetDestinAddress()
{
	return (unsigned char*)&m_sHeader.enet_dstaddr;
}

// 송수신지 주소를 설정하는 함수들입니다.
// 중요한 점은 이더넷 주소를 unsigned char로 만들어 주었기 때문에
// 다음과 같이 할당해줍니다.
void CEthernetLayer::SetSourceAddress(unsigned char* pAddress)
{
	m_sHeader.enet_srcaddr.s_ether_addr[0] = pAddress[0];
	m_sHeader.enet_srcaddr.s_ether_addr[1] = pAddress[1];
	m_sHeader.enet_srcaddr.s_ether_addr[2] = pAddress[2];
	m_sHeader.enet_srcaddr.s_ether_addr[3] = pAddress[3];
	m_sHeader.enet_srcaddr.s_ether_addr[4] = pAddress[4];
	m_sHeader.enet_srcaddr.s_ether_addr[5] = pAddress[5];
}

void CEthernetLayer::SetDestinAddress(unsigned char* pAddress)
{
	m_sHeader.enet_dstaddr.s_ether_addr[0] = pAddress[0];
	m_sHeader.enet_dstaddr.s_ether_addr[1] = pAddress[1];
	m_sHeader.enet_dstaddr.s_ether_addr[2] = pAddress[2];
	m_sHeader.enet_dstaddr.s_ether_addr[3] = pAddress[3];
	m_sHeader.enet_dstaddr.s_ether_addr[4] = pAddress[4];
	m_sHeader.enet_dstaddr.s_ether_addr[5] = pAddress[5];
}

// ChatApp에서 데이터를 받아와 NI 계층으로 넘겨주는 함수입니다
BOOL CEthernetLayer::Send(unsigned char* ppayload, int nlength)
{
	memcpy(m_sHeader.enet_data, ppayload, nlength);

	BOOL bSuccess = FALSE;
	bSuccess = this->GetUnderLayer()->Send((unsigned char*)&m_sHeader, nlength + ETHER_HEADER_SIZE);
	return bSuccess;
}

// 파일 계층에서 받아온 데이터를 헤더를 제거하고 ChatApp 으로 넘겨줍니다.
BOOL CEthernetLayer::Receive(unsigned char* ppayload)
{
	PETHERNET_HEADER pFrame = (PETHERNET_HEADER)ppayload;
	
	BOOL bSuccess = FALSE;
	bSuccess = this->GetUpperLayer(0)->Receive(pFrame->enet_data);
	return bSuccess;
}
