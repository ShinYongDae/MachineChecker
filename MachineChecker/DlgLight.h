#pragma once


// CDlgLight ��ȭ �����Դϴ�.

class CDlgLight : public CDialog
{
	DECLARE_DYNAMIC(CDlgLight)

public:
	CDlgLight(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgLight();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
