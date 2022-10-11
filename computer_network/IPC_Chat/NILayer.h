// FileLayer.h: interface for the CFileLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILELAYER_H__D67222B3_1B00_4C77_84A4_CEF6D572E181__INCLUDED_)
#define AFX_FILELAYER_H__D67222B3_1B00_4C77_84A4_CEF6D572E181__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "BaseLayer.h"
#include "pch.h"
#include <pcap.h>
#include <tchar.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <Packet32.h>
#pragma comment(lib, "packet.lib")
#include "EthernetLayer.h"
class CNILayer
	: public CBaseLayer
{
private:
	// 어댑터를 받아오기 위한 변수들입니다.
	pcap_t* m_AdapterObject;
	pcap_if_t* m_allDevs;
	unsigned char m_MacAddress[6];  // 현재 컴퓨터의 MAC address입니다.
	char m_adapterName[1024];
	int m_iNumAdapter;
	int m_selectedNum;
public:
	void	baseReceive();    // Eternet 계층으로 데이터를 넘겨주는 함수입니다
	BOOL	Send(unsigned char* ppayload, int nlength);   // 패킷 데이터를 보내 줍니다
	void	SetNICList();

	// 어댑터 set get 함수입니다.
	void	setAdapterNum(int index);    
	int		getAdapterNum();
	char*	getAdapterName(int index);
	void	setMacAddress();
	// MAC 어드레스를 가져오는 함수입니다 (송수신지)
	unsigned char*	getMacAddress();
	unsigned char* getReceiveMacAddress();

	CNILayer(char* pName, pcap_t* pAdapterObject=NULL, int iNumAdapter=0);
	virtual ~CNILayer();

	// 송수신 어드레스를 가져올 수 있도록 변수를 만듭니다
	unsigned char r_dstAdd[6];
	unsigned char r_srcAdd[6];
};

#endif // !defined(AFX_FILELAYER_H__D67222B3_1B00_4C77_84A4_CEF6D572E181__INCLUDED_)
