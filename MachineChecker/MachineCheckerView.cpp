
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


void CMachineCheckerView::OnBnClickedBtnOpen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();

	CString sPath = FileBrowse();

	if (sPath.IsEmpty())
		return;

	GetDlgItem(IDC_STC_PATH)->SetWindowText(sPath);
	CString sData;
	if (!pDoc->LoadConfig(sPath, sData))
		AfxMessageBox(_T("LoadConfig failed!"));
	GetDlgItem(IDC_EDIT_CONFIG)->SetWindowText(sData);
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
