
// MFCApplication7.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCApplication7App:
// �� Ŭ������ ������ ���ؼ��� MFCApplication7.cpp�� �����Ͻʽÿ�.
//

class CMFCApplication7App : public CWinApp
{
public:
	CMFCApplication7App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication7App theApp;