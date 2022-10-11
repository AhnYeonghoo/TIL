#pragma once
// ChatAppLayer.h: interface for the CChatAppLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHATAPPLAYER_H__E78615DE_0F23_41A9_B814_34E2B3697EF2__INCLUDED_)
#define AFX_CHATAPPLAYER_H__E78615DE_0F23_41A9_B814_34E2B3697EF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseLayer.h"
#include "pch.h"
#include "EthernetLayer.h"

class CChatAppLayer
	: public CBaseLayer
{
private:
	inline void		ResetHeader();
	CObject* mp_Dlg;      
	CEthernetLayer* m_Ether;

public:
	BOOL			Receive(unsigned char* ppayload);     // 이더넷 계층에서 받은 데이터를 ChatDlg로 보내는 함수
	BOOL			Send(unsigned char* ppayload, int nlength);     // ChatDlg에서 받은 데이터를 이더넷 계층로 보내는 함수
	// 송 수신지 주소에 관한 함수들입니다
	unsigned char*  GetDestinAddress();
	unsigned char*  GetSourceAddress();
	void			SetDestinAddress(unsigned int dst_addr);
	void			SetSourceAddress(unsigned int src_addr);

	CChatAppLayer(char* pName);
	virtual ~CChatAppLayer();

	// chatapp header입니다.
	typedef struct _CHAT_APP_HEADER {

		unsigned short	app_length; // total length of the data
		unsigned char	app_type; // type of application data
		unsigned char   app_unused; // 사용하지 않는 변수입니다.
		unsigned char	app_data[APP_DATA_SIZE]; // application data

	} CHAT_APP_HEADER, * PCHAT_APP_HEADER;

protected:
	CHAT_APP_HEADER		m_sHeader;    // 실질적으로 CHAT_APP_HEADER에 데이터를 넣고 전송이 됩니다.

	enum {
		DATA_TYPE_CONT = 0x01,
		DATA_TYPE_END = 0x02
	};
};

#endif // !defined(AFX_CHATAPPLAYER_H__E78615DE_0F23_41A9_B814_34E2B3697EF2__INCLUDED_)










