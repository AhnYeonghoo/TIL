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
// 생성자/ 소멸자
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

// 송수신지 주소를 설정하는 함수들입니다
void CChatAppLayer::SetSourceAddress(unsigned int src_addr)
{
	m_Ether->SetSourceAddress((unsigned char*)&src_addr);
}

void CChatAppLayer::SetDestinAddress(unsigned int dst_addr)
{
	m_Ether->SetDestinAddress((unsigned char*)&dst_addr);
}

// 헤더를 리셋해주는 함수들입니다
void CChatAppLayer::ResetHeader()
{
	m_sHeader.app_unused = 0;
	m_sHeader.app_length = 0x0000;
	m_sHeader.app_type = 0x00;
	memset(m_sHeader.app_data, 0, APP_DATA_SIZE);
}

// 송수신지 주소를 가져오는 함수들입니다
unsigned char* CChatAppLayer::GetSourceAddress()
{
	return m_Ether->GetSourceAddress();
}

unsigned char* CChatAppLayer::GetDestinAddress()
{
	return m_Ether->GetDestinAddress();
}

// ipc2019Dlg에서 send 버튼이 누르고 데이터가 들어오는 함수입니다.
BOOL CChatAppLayer::Send(unsigned char* ppayload, int nlength)
{
	m_sHeader.app_length = (unsigned short)nlength;

	// ethernet 계층으로 보냅니다.
	BOOL bSuccess = FALSE;
	memcpy(m_sHeader.app_data, ppayload, nlength > APP_DATA_SIZE ? APP_DATA_SIZE : nlength);
	bSuccess = this->GetUnderLayer()->Send((unsigned char*)&m_sHeader, nlength + APP_HEADER_SIZE);
	return bSuccess;  // 제대로 넘겨졌는지 BOOL로 반환합니다
}

// Eternet 계층에서 데이터가 들어오는 함수입니다.
BOOL CChatAppLayer::Receive(unsigned char* ppayload)
{
	PCHAT_APP_HEADER app_hdr = (PCHAT_APP_HEADER)ppayload;

	unsigned char GetBuff[APP_DATA_SIZE]; // 32비트 크기의 App Data Size만큼의 GetBuff를 선언합니다.
	memset(GetBuff, '\0', APP_DATA_SIZE);  // GetBuff를 초기화해줍니다.
	memcpy(GetBuff, app_hdr->app_data, app_hdr->app_length > APP_DATA_SIZE ? APP_DATA_SIZE : app_hdr->app_length);
	CNILayer* m_NI = (CNILayer*)this->GetUnderLayer()->GetUnderLayer();

	// 메세지를 포맷 형식으로 ChatDlg 계층으로 넘겨줍니다.
	CString Msg;
	Msg.Format(_T("[%.2X-%.2X-%.2X-%.2X-%.2X-%.2X:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X] %s"),
		m_NI->r_srcAdd[0], m_NI->r_srcAdd[1], m_NI->r_srcAdd[2], m_NI->r_srcAdd[3], m_NI->r_srcAdd[4], m_NI->r_srcAdd[5],
		m_NI->r_dstAdd[0], m_NI->r_dstAdd[1], m_NI->r_dstAdd[2], m_NI->r_dstAdd[3], m_NI->r_dstAdd[4], m_NI->r_dstAdd[5],
		(char*)GetBuff);

	if (!memcmp(app_hdr->app_data, "ACK", 3)) {
		this->GetUpperLayer(0)->Receive(app_hdr->app_data);
		//만약 ACK 메세지라면 위호 보낼때 "ACK"를 확인할 수 있도록 해줍니다.
	}
	else {
		this->GetUpperLayer(0)->Receive((unsigned char*)Msg.GetBuffer(0));
		//일반 채팅이라면 메세지 형식으로 바로 보내줍니다.
	}
	return TRUE;
}


