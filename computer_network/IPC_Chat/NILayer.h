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
	// ����͸� �޾ƿ��� ���� �������Դϴ�.
	pcap_t* m_AdapterObject;
	pcap_if_t* m_allDevs;
	unsigned char m_MacAddress[6];  // ���� ��ǻ���� MAC address�Դϴ�.
	char m_adapterName[1024];
	int m_iNumAdapter;
	int m_selectedNum;
public:
	void	baseReceive();    // Eternet �������� �����͸� �Ѱ��ִ� �Լ��Դϴ�
	BOOL	Send(unsigned char* ppayload, int nlength);   // ��Ŷ �����͸� ���� �ݴϴ�
	void	SetNICList();

	// ����� set get �Լ��Դϴ�.
	void	setAdapterNum(int index);    
	int		getAdapterNum();
	char*	getAdapterName(int index);
	void	setMacAddress();
	
	unsigned char*	getMacAddress();
	unsigned char* getReceiveMacAddress();

	CNILayer(char* pName, pcap_t* pAdapterObject=NULL, int iNumAdapter=0);
	virtual ~CNILayer();

	// �ۼ��� ��巹���� ������ �� �ֵ��� ������ ����ϴ�
	unsigned char r_dstAdd[6];
	unsigned char r_srcAdd[6];
};

#endif // !defined(AFX_FILELAYER_H__D67222B3_1B00_4C77_84A4_CEF6D572E181__INCLUDED_)
