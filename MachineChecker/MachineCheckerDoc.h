
// MachineCheckerDoc.h : CMachineCheckerDoc Ŭ������ �������̽�
//


#pragma once

struct stInfo
{
	CString sMachineName;

	stInfo()
	{
		sMachineName = _T("");
	}
};

struct stConfig
{
	stInfo Info;
};

class CMachineCheckerDoc : public CDocument
{
	stConfig m_stConfig;
	CString m_sPathPrevConfigFolder, m_sNamePrevConfigFile;

protected: // serialization������ ��������ϴ�.
	CMachineCheckerDoc();
	DECLARE_DYNCREATE(CMachineCheckerDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	CString GetPathPrevConfigFolder();
	CString GetNamePrevConfigFile();
	void SetPathPrevConfigFolder(CString sPath);
	void SetNamePrevConfigFile(CString sName);
	BOOL LoadConfig(CString sPath, CString& sData);

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMachineCheckerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
