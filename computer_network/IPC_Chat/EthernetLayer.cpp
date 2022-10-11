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
// ������/ �Ҹ���
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

// ����� �����ϴ� �Լ��Դϴ�
void CEthernetLayer::ResetHeader()
{
	memset(m_sHeader.enet_data, ETHER_MAX_DATA_SIZE, 6);
	m_sHeader.enet_type = 0;
}

// �ۼ����� �ּҸ� �޾ƿ��� �Լ����Դϴ�.
unsigned char* CEthernetLayer::GetSourceAddress()
{
	//return m_NI->GetSourceAddress();
	return 0x00;
}

unsigned char* CEthernetLayer::GetDestinAddress()
{
	return (unsigned char*)&m_sHeader.enet_dstaddr;
}

// �ۼ����� �ּҸ� �����ϴ� �Լ����Դϴ�.
// �߿��� ���� �̴��� �ּҸ� unsigned char�� ����� �־��� ������
// ������ ���� �Ҵ����ݴϴ�.
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

// ChatApp���� �����͸� �޾ƿ� NI �������� �Ѱ��ִ� �Լ��Դϴ�
BOOL CEthernetLayer::Send(unsigned char* ppayload, int nlength)
{
	memcpy(m_sHeader.enet_data, ppayload, nlength);

	BOOL bSuccess = FALSE;
	bSuccess = this->GetUnderLayer()->Send((unsigned char*)&m_sHeader, nlength + ETHER_HEADER_SIZE);
	return bSuccess;
}

// ���� �������� �޾ƿ� �����͸� ����� �����ϰ� ChatApp ���� �Ѱ��ݴϴ�.
BOOL CEthernetLayer::Receive(unsigned char* ppayload)
{
	PETHERNET_HEADER pFrame = (PETHERNET_HEADER)ppayload;
	
	BOOL bSuccess = FALSE;
	bSuccess = this->GetUpperLayer(0)->Receive(pFrame->enet_data);
	return bSuccess;
}
