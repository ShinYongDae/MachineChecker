// DlgLight.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgLight.h"
#include "afxdialogex.h"


// CDlgLight ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgLight, CDialog)

CDlgLight::CDlgLight(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_LIGHT, pParent)
{

}

CDlgLight::~CDlgLight()
{
}

void CDlgLight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLight, CDialog)
END_MESSAGE_MAP()


// CDlgLight �޽��� ó�����Դϴ�.


BOOL CDlgLight::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
