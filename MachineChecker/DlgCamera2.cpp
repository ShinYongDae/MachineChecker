// DlgCamera2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCamera2.h"
#include "afxdialogex.h"


// CDlgCamera2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgCamera2, CDialog)

CDlgCamera2::CDlgCamera2(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_CAMERA2, pParent)
{

}

CDlgCamera2::~CDlgCamera2()
{
}

void CDlgCamera2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCamera2, CDialog)
END_MESSAGE_MAP()


// CDlgCamera2 �޽��� ó�����Դϴ�.


BOOL CDlgCamera2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
