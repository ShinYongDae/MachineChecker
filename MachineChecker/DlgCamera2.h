#pragma once


// CDlgCamera2 ��ȭ �����Դϴ�.

class CDlgCamera2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgCamera2)

public:
	CDlgCamera2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgCamera2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
