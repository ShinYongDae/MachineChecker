
// MachineCheckerDoc.cpp : CMachineCheckerDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MachineChecker.h"
#endif

#include "MachineCheckerDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMachineCheckerDoc

IMPLEMENT_DYNCREATE(CMachineCheckerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMachineCheckerDoc, CDocument)
END_MESSAGE_MAP()


// CMachineCheckerDoc ����/�Ҹ�

CMachineCheckerDoc::CMachineCheckerDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	m_sPathPrevConfigFolder = _T("");
}

CMachineCheckerDoc::~CMachineCheckerDoc()
{
}

BOOL CMachineCheckerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMachineCheckerDoc serialization

void CMachineCheckerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMachineCheckerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMachineCheckerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMachineCheckerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMachineCheckerDoc ����

#ifdef _DEBUG
void CMachineCheckerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMachineCheckerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMachineCheckerDoc ���
CString CMachineCheckerDoc::GetPathPrevConfigFolder()
{
	return m_sPathPrevConfigFolder;
}

CString CMachineCheckerDoc::GetNamePrevConfigFile()
{
	return m_sNamePrevConfigFile;
}

void CMachineCheckerDoc::SetPathPrevConfigFolder(CString sPath)
{
	m_sPathPrevConfigFolder = sPath;
}

void CMachineCheckerDoc::SetNamePrevConfigFile(CString sName)
{
	m_sNamePrevConfigFile = sName;
}

BOOL CMachineCheckerDoc::LoadConfig(CString sPath, CString& sData)
{
	CString str;
	TCHAR szData[MAX_PATH];
	sData = _T("");

	if (0 < ::GetPrivateProfileString(_T("Info"), _T("Machine Name"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Info.sMachineName = CString(szData);
	else
		m_stConfig.Info.sMachineName = _T("");

	str.Format(_T("%s: %s"), _T("Machine Name"), m_stConfig.Info.sMachineName);
	sData += str;
	sData += _T("\r\n");

	return TRUE;
}
