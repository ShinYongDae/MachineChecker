
// MachineCheckerView.cpp : CMachineCheckerView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CMachineCheckerView ����/�Ҹ�

CMachineCheckerView::CMachineCheckerView()
	: CFormView(IDD_MACHINECHECKER_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMachineCheckerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	InitMenu();
}


// CMachineCheckerView ����

#ifdef _DEBUG
void CMachineCheckerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMachineCheckerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMachineCheckerDoc* CMachineCheckerView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMachineCheckerDoc)));
	return (CMachineCheckerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMachineCheckerView �޽��� ó����
void CMachineCheckerView::InitMenu()
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_bAutoMenuEnable = FALSE;
	CMenu *pMenu = pFrame->GetMenu();
	//pMenu->CheckMenuItem(ID_IO, MF_CHECKED);//MF_UNCHECKED

	CMenu *pSubMenu = pMenu->GetSubMenu(1); // 0:����, 1:Devices
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	CMenu *pSubMenu = pMenu->GetSubMenu(1); // 0:����, 1:Devices
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
	dlg.m_ofn.lStructSize = sizeof(OPENFILENAME) + 12; // +12�� Win2k Style�� ���̾�α� �ڽ��� Open��.

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
