// ChatAppLayer.cpp: implementation of the CChatAppLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "pch.h"
#include "ChatAppLayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// ������/ �Ҹ���
//////////////////////////////////////////////////////////////////////

CChatAppLayer::CChatAppLayer(char* pName)
	: CBaseLayer(pName),
	mp_Dlg(NULL)
{
	m_Ether = (CEthernetLayer*)this->GetUnderLayer();
	ResetHeader();
}

CChatAppLayer::~CChatAppLayer()
{

}

// �ۼ����� �ּҸ� �����ϴ� �Լ����Դϴ�
void CChatAppLayer::SetSourceAddress(unsigned int src_addr)
{
	m_Ether->SetSourceAddress((unsigned char*)&src_addr);
}

void CChatAppLayer::SetDestinAddress(unsigned int dst_addr)
{
	m_Ether->SetDestinAddress((unsigned char*)&dst_addr);
}

// ����� �������ִ� �Լ����Դϴ�
void CChatAppLayer::ResetHeader()
{
	m_sHeader.app_unused = 0;
	m_sHeader.app_length = 0x0000;
	m_sHeader.app_type = 0x00;
	memset(m_sHeader.app_data, 0, APP_DATA_SIZE);
}

// �ۼ����� �ּҸ� �������� �Լ����Դϴ�
unsigned char* CChatAppLayer::GetSourceAddress()
{
	return m_Ether->GetSourceAddress();
}

unsigned char* CChatAppLayer::GetDestinAddress()
{
	return m_Ether->GetDestinAddress();
}

// ipc2019Dlg���� send ��ư�� ������ �����Ͱ� ������ �Լ��Դϴ�.
BOOL CChatAppLayer::Send(unsigned char* ppayload, int nlength)
{
	m_sHeader.app_length = (unsigned short)nlength;

	// ethernet �������� �����ϴ�.
	BOOL bSuccess = FALSE;
	memcpy(m_sHeader.app_data, ppayload, nlength > APP_DATA_SIZE ? APP_DATA_SIZE : nlength);
	bSuccess = this->GetUnderLayer()->Send((unsigned char*)&m_sHeader, nlength + APP_HEADER_SIZE);
	return bSuccess;  // ����� �Ѱ������� BOOL�� ��ȯ�մϴ�
}

// Eternet �������� �����Ͱ� ������ �Լ��Դϴ�.
BOOL CChatAppLayer::Receive(unsigned char* ppayload)
{
	PCHAT_APP_HEADER app_hdr = (PCHAT_APP_HEADER)ppayload;

	unsigned char GetBuff[APP_DATA_SIZE]; // 32��Ʈ ũ���� App Data Size��ŭ�� GetBuff�� �����մϴ�.
	memset(GetBuff, '\0', APP_DATA_SIZE);  // GetBuff�� �ʱ�ȭ���ݴϴ�.
	memcpy(GetBuff, app_hdr->app_data, app_hdr->app_length > APP_DATA_SIZE ? APP_DATA_SIZE : app_hdr->app_length);
	CNILayer* m_NI = (CNILayer*)this->GetUnderLayer()->GetUnderLayer();

	// �޼����� ���� �������� ChatDlg �������� �Ѱ��ݴϴ�.
	CString Msg;
	Msg.Format(_T("[%.2X-%.2X-%.2X-%.2X-%.2X-%.2X:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X] %s"),
		m_NI->r_srcAdd[0], m_NI->r_srcAdd[1], m_NI->r_srcAdd[2], m_NI->r_srcAdd[3], m_NI->r_srcAdd[4], m_NI->r_srcAdd[5],
		m_NI->r_dstAdd[0], m_NI->r_dstAdd[1], m_NI->r_dstAdd[2], m_NI->r_dstAdd[3], m_NI->r_dstAdd[4], m_NI->r_dstAdd[5],
		(char*)GetBuff);

	if (!memcmp(app_hdr->app_data, "ACK", 3)) {
		this->GetUpperLayer(0)->Receive(app_hdr->app_data);
		//���� ACK �޼������ ��ȣ ������ "ACK"�� Ȯ���� �� �ֵ��� ���ݴϴ�.
	}
	else {
		this->GetUpperLayer(0)->Receive((unsigned char*)Msg.GetBuffer(0));
		//�Ϲ� ä���̶�� �޼��� �������� �ٷ� �����ݴϴ�.
	}
	return TRUE;
}


