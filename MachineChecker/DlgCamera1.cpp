// DlgCamera1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCamera1.h"
#include "afxdialogex.h"


// CDlgCamera1 대화 상자입니다.

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


// CDlgCamera1 메시지 처리기입니다.


BOOL CDlgCamera1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
