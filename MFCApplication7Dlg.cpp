
// MFCApplication7Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "MFCApplication7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMFCApplication7Dlg 대화 상자



CMFCApplication7Dlg::CMFCApplication7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION7_DIALOG, pParent)
	, m_nChoiceNum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_VIEW, m_Rect);
	DDX_Text(pDX, IDC_EDIT_CHOICENUM, m_nChoiceNum);
	DDV_MinMaxInt(pDX, m_nChoiceNum, 1, 5);
}

BEGIN_MESSAGE_MAP(CMFCApplication7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DRAW_SADARI, &CMFCApplication7Dlg::OnClickedButtonDrawSadari)
	ON_BN_CLICKED(IDC_BUTTON_START, &CMFCApplication7Dlg::OnClickedButtonStart)
END_MESSAGE_MAP()


// CMFCApplication7Dlg 메시지 처리기

BOOL CMFCApplication7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication7Dlg::OnPaint()
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

		CDC *pic = m_Rect.GetWindowDC();
		CRect rect;
		GetWindowRect(rect);
		ScreenToClient(rect);
		pic->FillRect(rect, WHITE_BRUSH);

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication7Dlg::OnClickedButtonDrawSadari()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InitArray(); // 사다리 구조가 들어갈 공간을 초기화
	MakeSadari(); // 배열에 가로줄과 세로줄을 생성하여 저장
	DrawSadari(); // 배열에 설정된 구조를 이용 대화상자 화면에 출력
}


void CMFCApplication7Dlg::OnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDC *pic = m_Rect.GetWindowDC();
	CRect rectView;
	COLORREF rgb = NULL;
	GetWindowRect(rectView);
	ScreenToClient(rectView);

	HWND hWnd = m_Rect.GetSafeHwnd();
	HDC hdc = ::GetDC(hWnd);
	CString number;
	
	int line;
	char *p = NULL;
	int player, n = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int x3 = 0, y3 = 0, x4 = 0, y4 = 0;

	UpdateData(TRUE);
	player = m_nChoiceNum;
	player = player * 3 - 3;

	switch (m_nChoiceNum) // 번호에 따라 RGB 설정
	{
	case 1:
		rgb = RGB(255, 0, 0); 
		number = "1";
		break;
	case 2:
		rgb = RGB(0, 255, 0); 
		number = "2";
		break;
	case 3:
		rgb = RGB(0, 0, 255);
		number = "3";
		break;
	case 4:
		rgb = RGB(0, 255, 255); 
		number = "4";
		break;
	case 5:
		rgb = RGB(255, 255, 0); 
		number = "5";
		break;
	default: 
		rgb = NULL;
	}
	
	CPen pen(PS_SOLID, 5, rgb); //사다리경로 rgb값바꾸기
	pic->SelectObject(&pen);

	line = 0;
	p = &m_sadari[line][player];

	x1 = 50 + player * 30; // 시작 위치
	y1 = 50 + line * 30; // 시작 위치
	x3 = x1; // 시작 번호 위치
	y3 = y1 - 30;  // 시작 번호 위치

	while (line < 10 && m_nChoiceNum >0 && m_nChoiceNum < 6) {
		::TextOut(hdc, x3, y3, number, number.GetLength());
		if (*(p - 1) == '-' || *(p + 1) == '-') {
			if (*(p - 1) == '-') {
				p = p - 3;
				p = p + 13;
				pic->MoveTo(x1, y1);
				player = player - 3;
				x2 = 50 + player * 30;
				y2 = 50 + line * 30;
				pic->LineTo(x2, y2);
				x1 = x2;
				y1 = y2;
			}
			else if (*(p + 1) == '-') {
				p = p + 3;
				p = p + 13;
				pic->MoveTo(x1, y1);
				player = player + 3;
				x2 = 50 + player * 30;
				y2 = 50 + line * 30;
				pic->LineTo(x2, y2);
				x1 = x2;
				y1 = y2;
			}
			pic->MoveTo(x1, y1);

			line++;

			y2 = 50 + line * 30;
			pic->LineTo(x2, y2);

			x1 = x2;
			y1 = y2;
		}
		else
		{
			pic->MoveTo(x1, y1);
			p = p + 13;

			line++;
			y2 = 50 + line * 30;
			pic->LineTo(x1, y2);
			y1 = y2;
		}
	}
	x4 = x1; // 도착 번호 위치
	y4 = y1 + 10; // 도착 번호 위치
	::TextOut(hdc, x4, y4, number, number.GetLength());

}

void CMFCApplication7Dlg::InitArray()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 13; x++)
		{
			m_sadari[y][x] = ' ';
		}
	}

}


void CMFCApplication7Dlg::MakeSadari()
{
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 13; j++) {
			if (j % 3 == 0) {
				m_sadari[i][j] = '|';
			}
			else if (j % 3 == 1) {
				if ((rand() % 3) == 2) {
					if (m_sadari[i][j - 2] != '-' && i > 0) {
						m_sadari[i][j] = '-';
							m_sadari[i][j + 1] = '-';
					}
				}
			}
		}
	}
}


void CMFCApplication7Dlg::DrawSadari()
{
	CDC *pic = m_Rect.GetWindowDC();
	CRect rectView;
	GetWindowRect(rectView);
	ScreenToClient(rectView);
	pic->FillRect(rectView, WHITE_BRUSH);

	CPen pen(PS_SOLID, 2, RGB(0, 0, 0)); 
	pic->SelectObject(&pen);

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 13; x++) {
			if ('|' == m_sadari[y][x]) {
				pic->MoveTo(50 + x * 30, 50 + y * 30);
				pic->LineTo(50 + x * 30, 50 + (y + 1) * 30);
			}
			else if ('-' == m_sadari[y][x]) {
				pic->MoveTo(20 + x * 30, 50 + y * 30);
				pic->LineTo(50 + (x + 1) * 30, 50 + y * 30);
			}
		}
	}
	pen.DeleteObject();

}


