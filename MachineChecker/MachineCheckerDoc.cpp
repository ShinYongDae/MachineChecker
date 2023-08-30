
// MachineCheckerDoc.cpp : CMachineCheckerDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// CMachineCheckerDoc 생성/소멸

CMachineCheckerDoc::CMachineCheckerDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	m_sPathPrevConfigFolder = _T("");
}

CMachineCheckerDoc::~CMachineCheckerDoc()
{
}

BOOL CMachineCheckerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMachineCheckerDoc serialization

void CMachineCheckerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMachineCheckerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void CMachineCheckerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CMachineCheckerDoc 진단

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


// CMachineCheckerDoc 명령
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

CString CMachineCheckerDoc::GetProgramVersion()
{
	return m_stConfig.Info.sProgramVersion;
}

BOOL CMachineCheckerDoc::LoadConfig(CString sPath, CString& sData)
{
	int i;
	CString str, sItem;
	TCHAR szData[MAX_PATH];
	sData = _T("");

	sData += _T("[Info]");
	sData += _T("\r\n");
	if (0 < ::GetPrivateProfileString(_T("Info"), _T("Program Version"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Info.sProgramVersion = CString(szData);
	else
		m_stConfig.Info.sProgramVersion = _T("");

	if (0 < ::GetPrivateProfileString(_T("Info"), _T("Machine Name"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Info.sMachineName = CString(szData);
	else
		m_stConfig.Info.sMachineName = _T("");

	str.Format(_T("%s: %s"), _T("Machine Name"), m_stConfig.Info.sMachineName);
	sData += str;
	sData += _T("\r\n");

	sData += _T("\r\n");
	sData += _T("[Devices]");
	sData += _T("\r\n");
	if (0 < ::GetPrivateProfileString(_T("Devices"), _T("IO"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.sIO = CString(szData);
	else
		m_stConfig.Devices.sIO = _T("");

	str.Format(_T("%s: %s"), _T("IO"), m_stConfig.Devices.sIO);
	sData += str;
	sData += _T("\r\n");

	if (0 < ::GetPrivateProfileString(_T("Devices"), _T("Light Num"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.nNumLight = _ttoi(szData);
	else
		m_stConfig.Devices.nNumLight = 0;

	for (i = 0; i < m_stConfig.Devices.nNumLight; i++)
	{
		sItem.Format(_T("Light%d"), i + 1);
		if (0 < ::GetPrivateProfileString(_T("Devices"), sItem, NULL, szData, sizeof(szData), sPath))
			m_stConfig.Devices.sLight[i] = CString(szData);
		else
			m_stConfig.Devices.sLight[i] = _T("");

		str.Format(_T("%s: %s"), sItem, m_stConfig.Devices.sLight[i]);
		sData += str;
		sData += _T("\r\n");
	}

	if (0 < ::GetPrivateProfileString(_T("Devices"), _T("Motion"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.sMotion = CString(szData);
	else
		m_stConfig.Devices.sMotion = CString(szData);

	str.Format(_T("%s: %s"), _T("Motion"), m_stConfig.Devices.sMotion);
	sData += str;
	sData += _T("\r\n");

	if (0 < ::GetPrivateProfileString(_T("Devices"), _T("Camera Num"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.nNumCamera = _ttoi(szData);
	else
		m_stConfig.Devices.nNumCamera = 0;

	for (i = 0; i < m_stConfig.Devices.nNumCamera; i++)
	{
		sItem.Format(_T("Camera%d"), i + 1);
		if (0 < ::GetPrivateProfileString(_T("Devices"), sItem, NULL, szData, sizeof(szData), sPath))
			m_stConfig.Devices.sCamera[i] = CString(szData);
		else
			m_stConfig.Devices.sCamera[i] = _T("");

		str.Format(_T("%s: %s"), sItem, m_stConfig.Devices.sCamera[i]);
		sData += str;
		sData += _T("\r\n");
	}

	if (0 < ::GetPrivateProfileString(_T("Devices"), _T("Trigger"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.sTrigger = CString(szData);
	else
		m_stConfig.Devices.sTrigger = CString(szData);

	str.Format(_T("%s: %s"), _T("Trigger"), m_stConfig.Devices.sTrigger);
	sData += str;
	sData += _T("\r\n");

	if (0 < ::GetPrivateProfileString(_T("Devices"), _T("2D Barcode"), NULL, szData, sizeof(szData), sPath))
		m_stConfig.Devices.s2DBarcode = CString(szData);
	else
		m_stConfig.Devices.s2DBarcode = CString(szData);

	str.Format(_T("%s: %s"), _T("2D Barcode"), m_stConfig.Devices.s2DBarcode);
	sData += str;
	sData += _T("\r\n");

	return TRUE;
}
