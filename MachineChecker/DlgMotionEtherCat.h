#pragma once


// CDlgMotionEtherCat ��ȭ �����Դϴ�.

class CDlgMotionEtherCat : public CDialog
{
	DECLARE_DYNAMIC(CDlgMotionEtherCat)

	void Init();
	void Close();

public:
	CDlgMotionEtherCat(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMotionEtherCat();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MOTION_ETHERCAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
