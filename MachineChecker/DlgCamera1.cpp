// DlgCamera1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCamera1.h"
#include "afxdialogex.h"


// CDlgCamera1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgCamera1, CDialog)

CDlgCamera1::CDlgCamera1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_CAMERA1, pParent)
{

}

CDlgCamera1::~CDlgCamera1()
{
}

void CDlgCamera1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCamera1, CDialog)
END_MESSAGE_MAP()


// CDlgCamera1 �޽��� ó�����Դϴ�.


BOOL CDlgCamera1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
