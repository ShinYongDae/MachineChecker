
// MachineCheckerView.cpp : CMachineCheckerView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MachineChecker.h"
#endif

#include "MainFrm.h"
#include "MachineCheckerDoc.h"
#include "MachineCheckerView.h"

#include "DlgIO.h"
#include "DlgLight.h"
#include "DlgMotion.h"
#include "DlgCamera1.h"
#include "DlgCamera2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMachineCheckerView

IMPLEMENT_DYNCREATE(CMachineCheckerView, CFormView)

BEGIN_MESSAGE_MAP(CMachineCheckerView, CFormView)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CMachineCheckerView::OnBnClickedBtnOpen)
END_MESSAGE_MAP()

//CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
//CGvisLcmView *pView = (CGvisLcmView *)pFrame->GetActiveView();
//CGvisLcmDoc *pDoc = (CGvisLcmDoc *)pFrame->GetActiveDocument();

// CMachineCheckerView 생성/소멸

CMachineCheckerView::CMachineCheckerView()
	: CFormView(IDD_MACHINECHECKER_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMachineCheckerView::~CMachineCheckerView()
{
}

void CMachineCheckerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMachineCheckerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMachineCheckerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	InitMenu();
}


// CMachineCheckerView 진단

#ifdef _DEBUG
void CMachineCheckerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMachineCheckerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMachineCheckerDoc* CMachineCheckerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMachineCheckerDoc)));
	return (CMachineCheckerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMachineCheckerView 메시지 처리기
void CMachineCheckerView::InitMenu()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_bAutoMenuEnable = FALSE;
	CMenu *pMenu = pFrame->GetMenu();
	//pMenu->CheckMenuItem(ID_IO, MF_CHECKED);//MF_UNCHECKED

	CMenu *pSubMenu = pMenu->GetSubMenu(1); // 0:도움말, 1:Devices
	pSubMenu->EnableMenuItem(ID_IO, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_LIGHT, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_MOTION, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_CAMERA1, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pSubMenu->EnableMenuItem(ID_CAMERA2, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);


	//pSubMenu->EnableMenuItem(ID_APP_ABOUT, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	//pSubMenu->EnableMenuItem(ID_IO, MF_GRAYED);
	//pSubMenu->ModifyMenu(ID_IO, MF_BYPOSITION, MF_POPUP, _T("Input/Output"));
}


void CMachineCheckerView::OnBnClickedBtnOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	CString sPath = FileBrowse();

	if (sPath.IsEmpty())
		return;

	GetDlgItem(IDC_STC_PATH)->SetWindowText(sPath);
	CString sData, sVal;
	if (!pDoc->LoadConfig(sPath, sData))
		AfxMessageBox(_T("LoadConfig failed!"));
	sVal.Format(_T("Machine Checker Version : %s"), pDoc->GetProgramVersion());
	pFrame->SetWindowTextW(sVal);
	GetDlgItem(IDC_EDIT_CONFIG)->SetWindowText(sData);

	CMenu *pMenu = pFrame->GetMenu();
	CMenu *pSubMenu = pMenu->GetSubMenu(1); // 0:도움말, 1:Devices
	pSubMenu->EnableMenuItem(ID_IO, MF_BYCOMMAND | MF_ENABLED);
	pSubMenu->EnableMenuItem(ID_LIGHT, MF_BYCOMMAND | MF_ENABLED);
	pSubMenu->EnableMenuItem(ID_MOTION, MF_BYCOMMAND | MF_ENABLED);
	pSubMenu->EnableMenuItem(ID_CAMERA1, MF_BYCOMMAND | MF_ENABLED);
	pSubMenu->EnableMenuItem(ID_CAMERA2, MF_BYCOMMAND | MF_ENABLED);

}

CString CMachineCheckerView::FileBrowse()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	/* Load from file */
	CString FilePath;
	CFileFind finder;
	CString SrchPath, filePos, strTitleMsg, strErrMsg;

	CWaitCursor mCursor;

	CString DirPath[10];
	CString strWorkDir;
	BOOL bResult;

	CString strMcNum, sPath=_T("");
	int nAoiMachineNum = 0;

	// File Open Filter 
	static TCHAR BASED_CODE szFilter[] = _T("Config Files (*.cfg;*.ini)|*.cfg;*.ini|All Files (*.*)|*.*||");

	// CFileDialog 
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);

	// Win2k Style FileDialog Box
	dlg.m_ofn.lStructSize = sizeof(OPENFILENAME) + 12; // +12를 Win2k Style로 다이얼로그 박스가 Open됨.

	// Open Directory
	TCHAR strPrevDir[MAX_PATH];
	DWORD dwLength = GetCurrentDirectory(MAX_PATH, strPrevDir);

	if (!pDoc->GetPathPrevConfigFolder().IsEmpty())
	{
		filePos = pDoc->GetPathPrevConfigFolder() + _T("\\*.*");
		strWorkDir = filePos;
	}
	else
	{
		strWorkDir = strPrevDir;
	}
	dlg.m_ofn.lpstrInitialDir = strWorkDir;

	bResult = 0;

	// Dialog Open
	if (dlg.DoModal() == IDOK)
	{
		sPath = FilePath = dlg.GetPathName();

		CString sFileName;
		int nPos = FilePath.ReverseFind('\\');
		sFileName = FilePath.Right(FilePath.GetLength() - nPos - 1);
		pDoc->SetNamePrevConfigFile(sFileName);
		pDoc->SetPathPrevConfigFolder(FilePath.Left(nPos));
		return sPath;
	}

	return sPath;
}

void CMachineCheckerView::DispIO()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	CDlgIO Dlg;
	Dlg.DoModal();
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispLight()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	CDlgLight Dlg;
	Dlg.DoModal();
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispMotion()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	CDlgMotion Dlg;
	Dlg.DoModal();
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispCamera1()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	CDlgCamera1 Dlg;
	Dlg.DoModal();
	pFrame->ShowWindow(SW_NORMAL);
}

void CMachineCheckerView::DispCamera2()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->ShowWindow(SW_MINIMIZE);
	CDlgCamera2 Dlg;
	Dlg.DoModal();
	pFrame->ShowWindow(SW_NORMAL);
}
