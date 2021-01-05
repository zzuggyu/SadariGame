
// MFCApplication7Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CMFCApplication7Dlg ��ȭ ����
class CMFCApplication7Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCApplication7Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Rect;
	int m_nChoiceNum;
	afx_msg void OnClickedButtonDrawSadari();
	afx_msg void OnClickedButtonStart();
	char m_sadari[10][13];
//	void intArray();
	void MakeSadari();
	void DrawSadari();
	void InitArray();
};
