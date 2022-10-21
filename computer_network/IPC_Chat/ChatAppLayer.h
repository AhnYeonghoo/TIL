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
	BOOL			Receive(unsigned char* ppayload);     // �̴��� �������� ���� �����͸� ChatDlg�� ������ �Լ�
	BOOL			Send(unsigned char* ppayload, int nlength);     // ChatDlg���� ���� �����͸� �̴��� ������ ������ �Լ�
	// �� ������ �ּҿ� ���� �Լ����Դϴ�
	unsigned char*  GetDestinAddress();
	unsigned char*  GetSourceAddress();
	void			SetDestinAddress(unsigned int dst_addr);
	void			SetSourceAddress(unsigned int src_addr);

	CChatAppLayer(char* pName);
	virtual ~CChatAppLayer();

	// chatapp header�Դϴ�.
	typedef struct _CHAT_APP_HEADER {

		unsigned short	app_length; // total length of the data
		unsigned char	app_type; // type of application data
		unsigned char   app_unused; // ������� �ʴ� ���
		unsigned char	app_data[APP_DATA_SIZE]; // application data

	} CHAT_APP_HEADER, * PCHAT_APP_HEADER;

protected:
	CHAT_APP_HEADER		m_sHeader;    // 
	enum {
		DATA_TYPE_CONT = 0x01,
		DATA_TYPE_END = 0x02
	};
};

#endif // !defined(AFX_CHATAPPLAYER_H__E78615DE_0F23_41A9_B814_34E2B3697EF2__INCLUDED_)










