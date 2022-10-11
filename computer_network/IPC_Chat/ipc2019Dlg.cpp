
// ipc2019Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ipc2019.h"
#include "ipc2019Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define _CRT_SECURE_NO_WARNINGS

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cipc2019Dlg 대화 상자


// 생성자입니다.
Cipc2019Dlg::Cipc2019Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IPC2019_DIALOG, pParent)
	, CBaseLayer("ChatDlg")
	, m_bSendReady(FALSE)
	, m_nAckReady( -1 )
	, m_stMessage(_T(""))
	, m_srcAddr(_T(""))
	, m_dstAddr(_T(""))
{
	//대화 상자 멤버 초기화 완료

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//Protocol Layer Setting
	m_LayerMgr.AddLayer(new CChatAppLayer("ChatApp"));    // 각각의 계층을 넣어주고 이름을 넣습니다.
	m_LayerMgr.AddLayer(new CEthernetLayer("Ethernet"));
	m_LayerMgr.AddLayer(new CNILayer("NI"));
	m_LayerMgr.AddLayer(this); // 지금 현재 계층도 넣어줘야 합니다

	// 레이어를 연결한다. (레이어 생성)
	m_LayerMgr.ConnectLayers("NI ( *Ethernet ( *ChatApp ( *ChatDlg )))");  
	// 순서를 맞춰 아래부터 위까지 계층 이름을 넣어줍니다.

	// 각 레이어들을 가져옵니다.
	m_ChatApp = (CChatAppLayer*)m_LayerMgr.GetLayer("ChatApp");
	m_Ether = (CEthernetLayer*)m_LayerMgr.GetLayer("Ethernet");
	m_CNI = (CNILayer*)m_LayerMgr.GetLayer("NI");
}

// 데이터가 변환되는 함수입니다
void Cipc2019Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_NI, m_NICset);
	DDX_Text(pDX, IDC_EDIT_SRC, m_srcAddr);
	DDX_Text(pDX, IDC_EDIT_DST, m_dstAddr);
	DDX_Text(pDX, IDC_EDIT_MSG, m_stMessage);
	DDX_Control(pDX, IDC_LIST_CHAT, m_ListChat);
}

// 레지스트리에 등록하기 위한 변수
UINT nRegSendMsg;
UINT nRegAckMsg;
// 레지스트리에 등록하기 위한 변수

// ex. 전송 후 time out 전까지 기다리는 동안 이 곳이 실행 됩니다.
BEGIN_MESSAGE_MAP(Cipc2019Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADDR, &Cipc2019Dlg::OnBnClickedButtonAddr)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &Cipc2019Dlg::OnBnClickedButtonSend)
	ON_WM_TIMER()

	ON_REGISTERED_MESSAGE(nRegSendMsg, OnRegSendMsg)
		// Ack 레지스터 등록
	ON_REGISTERED_MESSAGE(nRegAckMsg, OnRegAckMsg)
	
END_MESSAGE_MAP()


// Cipc2019Dlg 메시지 처리기
BOOL Cipc2019Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CEdit* pSrcEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pSrcEdit->EnableWindow(FALSE);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	
	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SetRegstryMessage();
	SetDlgState(IPC_INITIALIZING);

	// 어댑터를 comboBox에 집어넣습니다.
	for (int i = 0; i < m_CNI->getAdapterNum(); i++) {
		char* temp = m_CNI->getAdapterName(i);
		
		m_NICset.AddString(temp);
	}
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cipc2019Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cipc2019Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cipc2019Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Send 버튼을 누르면 실행되는 함수입니다.
void Cipc2019Dlg::OnBnClickedButtonSend()
{
	UpdateData(TRUE);

	if (!m_stMessage.IsEmpty())
	{	
		// 2초 타이머 설정 후 AckReady를 0으로 해줍니다
		SetTimer(1, 2000, NULL);
		m_nAckReady = 0;

		// 데이터를 보내줍니다
		SendData();
		m_stMessage = "";

		(CEdit*)GetDlgItem(IDC_EDIT3)->SetFocus();
	}

	UpdateData(FALSE);
}

// 레지스트리 메세지 설정 함수
void Cipc2019Dlg::SetRegstryMessage()
{
	nRegSendMsg = RegisterWindowMessage(_T("Send IPC Message"));
	nRegAckMsg = RegisterWindowMessage(_T("Ack IPC Message"));

}

// 데이터를 보내는 함수
void Cipc2019Dlg::SendData()
{
	CString MsgHeader;
	// 송수신지 정보 담기
	MsgHeader.Format(_T("[%.2X-%.2X-%.2X-%.2X-%.2X-%.2X:%.2X-%.2X-%.2X-%.2X-%.2X-%.2X] "), 
		macSrcAddr[0], macSrcAddr[1], macSrcAddr[2], macSrcAddr[3], macSrcAddr[4], macSrcAddr[5],
		macDstAddr[0], macDstAddr[1], macDstAddr[2], macDstAddr[3], macDstAddr[4], macDstAddr[5]);

	// 보낸 데이터를 채팅앱에 띄워줍니다.
	m_ListChat.AddString(MsgHeader + m_stMessage);

	// 보내주기 위해서 모두 담아 준비합니다
	int nlength = m_stMessage.GetLength();
	unsigned char* ppayload = new unsigned char[nlength + 1];
	memcpy(ppayload, (unsigned char*)(LPCTSTR)m_stMessage, nlength);
	ppayload[nlength] = '\0';

	// 보낼 data와 메시지 길이를 Send함수로 다음 계층에 넘겨줍니다.
	this->GetUnderLayer()->Send((unsigned char*)(LPCTSTR)m_stMessage, m_stMessage.GetLength());
}

// 데이터를 받아오는 함수입니다.
BOOL Cipc2019Dlg::Receive(unsigned char* ppayload)
{
	// 만약 ACK 메세지라면 함수를 실행시켜줍니다.
	if (!memcmp(ppayload, "ACK", 3))
	{
		OnRegAckMsg(m_wParam, m_lParam);
	}
	else {  // ACK가 아니면
		// 받은 데이터를 화면에 추가해줍니다.
		m_ListChat.AddString((LPCTSTR)ppayload);
		unsigned char dst[6];
		for (int i = 0; i < 6; i++) dst[i] = m_CNI->r_srcAdd[i];

		// 송수신지를 변환하여 ACK 메세지를 보냅니다
		m_Ether->SetDestinAddress(dst);
		this->GetUnderLayer()->Send((unsigned char*)"ACK", 3);
		m_Ether->SetDestinAddress(macDstAddr);
	}
	return TRUE;
}

BOOL Cipc2019Dlg::PreTranslateMessage(MSG* pMsg)
{
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			if (::GetDlgCtrlID(::GetFocus()) == IDC_EDIT3)
				OnBnClickedButtonSend();					
			return FALSE;
		case VK_ESCAPE: return FALSE;
		}
		break;
	}

	return CDialog::PreTranslateMessage(pMsg);
}


void Cipc2019Dlg::SetDlgState(int state)
{
	UpdateData(TRUE);

	CButton* pChkButton = (CButton*)GetDlgItem(IDC_CHECK1);
	CButton* pSendButton = (CButton*)GetDlgItem(bt_send);
	CButton* pSetAddrButton = (CButton*)GetDlgItem(bt_setting);
	CEdit* pMsgEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
	CEdit* pSrcEdit = (CEdit*)GetDlgItem(IDC_EDIT_SRC);
	CEdit* pDstEdit = (CEdit*)GetDlgItem(IDC_EDIT_DST);

	switch (state)
	{
	case IPC_INITIALIZING:
		pSendButton->EnableWindow(FALSE);
		pMsgEdit->EnableWindow(FALSE);
		m_ListChat.EnableWindow(FALSE);
		break;
	case IPC_READYTOSEND:
		pSendButton->EnableWindow(TRUE);
		pMsgEdit->EnableWindow(TRUE);
		m_ListChat.EnableWindow(TRUE);
		break;
	case IPC_WAITFORACK:	break;
	case IPC_ERROR:		break;
	case IPC_UNICASTMODE:
		pDstEdit->EnableWindow(TRUE);
		break;
	case IPC_BROADCASTMODE:
		pDstEdit->EnableWindow(FALSE);
		break;
	case IPC_ADDR_SET:
		pSetAddrButton->SetWindowText(_T("재설정(&R)"));
		pSrcEdit->EnableWindow(FALSE);
		pDstEdit->EnableWindow(FALSE);
		break;
	case IPC_ADDR_RESET:
		pSetAddrButton->SetWindowText(_T("설정(&O)"));
		pDstEdit->EnableWindow(TRUE);
		break;
	}

	UpdateData(FALSE);
}

// 프로세스 종료시 소멸
void Cipc2019Dlg::EndofProcess()
{
	m_LayerMgr.DeAllocLayer();
}

// Send메시지 레지스트리가 켜졌을 때
LRESULT Cipc2019Dlg::OnRegSendMsg(WPARAM wParam, LPARAM lParam)
{
	if (m_nAckReady) {
		if (m_CNI->Receive())
		{
			// 메시지를 받았다면 Ack 신호를 브로드캐스트로 날립니다.
			::SendMessage(HWND_BROADCAST, nRegAckMsg, 0, 0);
		}
	}
	return 0;
}

LRESULT Cipc2019Dlg::OnRegAckMsg(WPARAM wParam, LPARAM lParam)
{
	if (!m_nAckReady) { // Ack 신호를 받으면 타이머를 멈춥니다.
		m_nAckReady = -1;
		KillTimer(1);
	}

	return 0;
}

void Cipc2019Dlg::OnTimer(UINT nIDEvent)
{
	// 타이머 설정한것을 넘겼을때 아래 메시지가 나옵니다.
	m_ListChat.AddString(_T(">> The last message was time-out.."));
	m_nAckReady = -1;
	KillTimer(1);

	CDialog::OnTimer(nIDEvent);
}

// 주소지 설정 버튼을 눌렀을 때 실행되는 함수입니다.
void Cipc2019Dlg::OnBnClickedButtonAddr()
{
	UpdateData(TRUE);

	if (m_bSendReady) {
		m_bSendReady = FALSE;
		SetDlgState(IPC_ADDR_RESET);
		SetDlgState(IPC_INITIALIZING);
	}
	else {
		m_bSendReady = TRUE;
		SetDlgState(IPC_ADDR_SET);

		CString Msg;
		m_CNI->setAdapterNum(m_NICset.GetCurSel());

		// MAC 어드레스를 설정하고 얻습니다
		m_CNI->setMacAddress();
		macSrcAddr = m_CNI->getMacAddress();
		Msg.Format(_T("%.2X-%.2X-%.2X-%.2X-%.2X-%.2X"),
			macSrcAddr[0], macSrcAddr[1], macSrcAddr[2],
			macSrcAddr[3], macSrcAddr[4], macSrcAddr[5]);
		SetDlgItemText(IDC_EDIT_SRC, Msg);

		//save des
		m_dstAddr.MakeLower();	// change LowwerBound
		ConvertHex(m_dstAddr, macDstAddr);	// CString change to Hex
		
		Msg.Format(_T("%.2X-%.2X-%.2X-%.2X-%.2X-%.2X"),
			macDstAddr[0], macDstAddr[1], macDstAddr[2],
			macDstAddr[3], macDstAddr[4], macDstAddr[5]);
		SetDlgItemText(IDC_EDIT_DST, Msg);

		// 이더넷 계층에 주소를 설정합니다
		m_Ether->SetSourceAddress(macSrcAddr);
		m_Ether->SetDestinAddress(macDstAddr);
		
		SetDlgState(IPC_ADDR_SET);
		SetDlgState(IPC_READYTOSEND);

		// 쓰레드로 NI 계층의 receive를 실행합니다.
		m_RecvThread = AfxBeginThread(ReceiveThread, this);
	}
}

// receive가 실행되는 함수입니다 (쓰레드) -> static으로 선언했습니다.
UINT Cipc2019Dlg::ReceiveThread(LPVOID pParam)
{
	Cipc2019Dlg* obj = (Cipc2019Dlg*)pParam;

	//if m_bSendReady is on, start Thread
	while (obj->m_bSendReady == TRUE)
	{
		// NI 계층에서 실행시킵니다.
		CNILayer* bLayer = (CNILayer*)(obj->m_LayerMgr.GetLayer("NI"));
		bLayer->baseReceive();
	}
	return 0;
}

// 16진수로 변환하는 함수입니다.
BOOL Cipc2019Dlg::ConvertHex(CString cs, unsigned char* hex)//change string to hex
{
	int i;
	char* srcStr = cs.GetBuffer(0);

	for (i = 0; i < 12; i++) {
		// error
		if (srcStr[i] < '0' || (srcStr[i] > '9' && srcStr[i] < 'a') || srcStr[i] > 'f')
			return FALSE;
	}
	for (i = 0; i < 12; i = i + 2) {
		hex[i / 2] = (((srcStr[i] > '9') ? (srcStr[i] - 87) : (srcStr[i] - '0')) << 4 |
			((srcStr[i + 1] > '9') ? (srcStr[i + 1] - 87) : (srcStr[i + 1] - '0')));
	}
	return TRUE;
}