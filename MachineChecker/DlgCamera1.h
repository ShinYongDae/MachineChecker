#pragma once


// CDlgCamera1 ��ȭ �����Դϴ�.

class CDlgCamera1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgCamera1)

public:
	CDlgCamera1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgCamera1();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
