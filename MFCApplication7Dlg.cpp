
// MFCApplication7Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "MFCApplication7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFCApplication7Dlg ��ȭ ����



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


// CMFCApplication7Dlg �޽��� ó����

BOOL CMFCApplication7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApplication7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCApplication7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication7Dlg::OnClickedButtonDrawSadari()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InitArray(); // ��ٸ� ������ �� ������ �ʱ�ȭ
	MakeSadari(); // �迭�� �����ٰ� �������� �����Ͽ� ����
	DrawSadari(); // �迭�� ������ ������ �̿� ��ȭ���� ȭ�鿡 ���
}


void CMFCApplication7Dlg::OnClickedButtonStart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	switch (m_nChoiceNum) // ��ȣ�� ���� RGB ����
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
	
	CPen pen(PS_SOLID, 5, rgb); //��ٸ���� rgb���ٲٱ�
	pic->SelectObject(&pen);

	line = 0;
	p = &m_sadari[line][player];

	x1 = 50 + player * 30; // ���� ��ġ
	y1 = 50 + line * 30; // ���� ��ġ
	x3 = x1; // ���� ��ȣ ��ġ
	y3 = y1 - 30;  // ���� ��ȣ ��ġ

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
	x4 = x1; // ���� ��ȣ ��ġ
	y4 = y1 + 10; // ���� ��ȣ ��ġ
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


