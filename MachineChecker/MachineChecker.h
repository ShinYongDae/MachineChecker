
// MachineChecker.h : MachineChecker ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMachineCheckerApp:
// �� Ŭ������ ������ ���ؼ��� MachineChecker.cpp�� �����Ͻʽÿ�.
//

class CMachineCheckerApp : public CWinApp
{
public:
	CMachineCheckerApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMachineCheckerApp theApp;
