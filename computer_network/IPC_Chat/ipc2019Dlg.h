
// ipc2019Dlg.h: 헤더 파일
//

#pragma once

#include "LayerManager.h"	// Added by ClassView
#include "ChatAppLayer.h"	// Added by ClassView
#include "EthernetLayer.h"	// Added by ClassView
#include "NILayer.h"	// Added by ClassView
#include "resource.h"
#include "stdafx.h"
// Cipc2019Dlg 대화 상자

class Cipc2019Dlg : public CDialogEx, public CBaseLayer
{
// 생성입니다.
public:
	Cipc2019Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.



// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IPC2019_DIALOG };
#endif

	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	UINT m_unDstAddr;
//	UINT unSrcAddr;
//	CString m_stMessage;
//	CListBox m_ListChat;
	
	afx_msg void OnTimer(UINT nIDEvent);


public:
	BOOL			Receive(unsigned char* ppayload);   // 데이터를 받아오는 함수입니다.
	inline void		SendData();    // 입력받은 데이터를 보내주는 함수입니다.

private:
	CLayerManager	m_LayerMgr;     // 코드에서 사용될 레이어 매니저 입니다.
	int				m_nAckReady;    // Ack가 준비 되었는지 확인해주는 변수로 -1 0의 값을 가지게 됩니다.
	CWinThread*		m_RecvThread;

	enum {
		IPC_INITIALIZING,
		IPC_READYTOSEND,
		IPC_WAITFORACK,
		IPC_ERROR,
		IPC_BROADCASTMODE,
		IPC_UNICASTMODE,
		IPC_ADDR_SET,
		IPC_ADDR_RESET
	};

	void			SetDlgState(int state);
	inline void		EndofProcess();
	inline void		SetRegstryMessage();
	// Send Ack에 대한 함수
	LRESULT			OnRegSendMsg(WPARAM wParam, LPARAM lParam);
	LRESULT			OnRegAckMsg(WPARAM wParam, LPARAM lParam);
	BOOL			m_bSendReady;

	// Dlg와 연결되어 있는 가장 높은 계층인 ChatApp을 가리키는 포인터입니다.
	CChatAppLayer* m_ChatApp;
	CEthernetLayer* m_Ether;
	CNILayer* m_CNI;

	// Implementation
	UINT			m_wParam;
	DWORD			m_lParam;
public:
	// 버튼 클릭시 실행되는 함수입니다.
	afx_msg void OnBnClickedButtonAddr();
	afx_msg void OnBnClickedButtonSend();
	static UINT ReceiveThread(LPVOID pParam);
	// 송수신 주소
	unsigned char* macSrcAddr;
	unsigned char macDstAddr[6];
	// 애플리케이션 화면에 관련된 변수입니다.
	CString m_srcAddr;
	CString m_dstAddr;
	CComboBox m_NICset;
	CString m_stMessage;
	CListBox m_ListChat;
	afx_msg void OnCbnSelchangeComboNi();
	// 16진수 변환 함수입니다.
	BOOL			ConvertHex(CString cs, unsigned char* hex);
};
