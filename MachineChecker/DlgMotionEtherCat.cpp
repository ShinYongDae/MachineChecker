// DlgMotionEtherCat.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgMotionEtherCat.h"
#include "afxdialogex.h"


// CDlgMotionEtherCat ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgMotionEtherCat, CDialog)

CDlgMotionEtherCat::CDlgMotionEtherCat(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_MOTION_ETHERCAT, pParent)
{

}

CDlgMotionEtherCat::~CDlgMotionEtherCat()
{
}

void CDlgMotionEtherCat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMotionEtherCat, CDialog)
END_MESSAGE_MAP()


// CDlgMotionEtherCat �޽��� ó�����Դϴ�.


BOOL CDlgMotionEtherCat::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgMotionEtherCat::Init()
{
}

void CDlgMotionEtherCat::Close()
{
}
