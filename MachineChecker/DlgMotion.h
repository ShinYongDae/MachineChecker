#pragma once


// CDlgMotion ��ȭ �����Դϴ�.

class CDlgMotion : public CDialog
{
	DECLARE_DYNAMIC(CDlgMotion)

public:
	CDlgMotion(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMotion();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MOTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
