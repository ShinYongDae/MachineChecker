// DlgCamera2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCamera2.h"
#include "afxdialogex.h"


// CDlgCamera2 대화 상자입니다.

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


// CDlgCamera2 메시지 처리기입니다.


BOOL CDlgCamera2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
