// DlgMotion.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgMotion.h"
#include "afxdialogex.h"


// CDlgMotion ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgMotion, CDialog)

CDlgMotion::CDlgMotion(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_MOTION, pParent)
{

}

CDlgMotion::~CDlgMotion()
{
	Close();
}

void CDlgMotion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMotion, CDialog)
END_MESSAGE_MAP()


// CDlgMotion �޽��� ó�����Դϴ�.


BOOL CDlgMotion::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgMotion::Init()
{
}

void CDlgMotion::Close()
{
}
