// EthernetLayer.h: interface for the CEthernetLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ETHERNETLAYER_H__7857C9C2_B459_4DC8_B9B3_4E6C8B587B29__INCLUDED_)
#define AFX_ETHERNETLAYER_H__7857C9C2_B459_4DC8_B9B3_4E6C8B587B29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseLayer.h"
#include "pch.h"
#include "NILayer.h"

class CEthernetLayer
	: public CBaseLayer
{
private:
	inline void		ResetHeader();
	CNILayer*		m_NI;

public:
	BOOL			Receive(unsigned char* ppayload);   // NI 계층에서 받아온 데이터를 ChatApp 계층으로 넘겨주는 함수
	BOOL			Send(unsigned char* ppayload, int nlength); // ChatApp 계층에서 온 데이터를 NI 계층으로 넘겨주는 함수
	// 송수신지 주소에 관련된 함수들입니다
	void			SetDestinAddress(unsigned char* pAddress);
	void			SetSourceAddress(unsigned char* pAddress);
	unsigned char* GetDestinAddress();
	unsigned char* GetSourceAddress();

	CEthernetLayer(char* pName);
	virtual ~CEthernetLayer();

	typedef struct _MAC_ADDR {
		unsigned char s_ether_addr[6];
	}MAC_ADDR, *CMAC_ADDR;

	typedef struct _ETHERNET_HEADER {

		MAC_ADDR    	enet_dstaddr;		// destination address of ethernet layer (MAC)
		MAC_ADDR	    enet_srcaddr;		// source address of ethernet layer (MAC)
		unsigned short	enet_type;		// type of ethernet layer
		unsigned char	enet_data[ETHER_MAX_DATA_SIZE]; // frame data

	} ETHERNET_HEADER, * PETHERNET_HEADER;

	ETHERNET_HEADER	m_sHeader; // 사실상 m_sHeader에 데이터가 들어가 전송이 됩니다.
};

#endif // !defined(AFX_ETHERNETLAYER_H__7857C9C2_B459_4DC8_B9B3_4E6C8B587B29__INCLUDED_)
