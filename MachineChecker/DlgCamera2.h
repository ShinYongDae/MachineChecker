#pragma once


// CDlgCamera2 대화 상자입니다.

class CDlgCamera2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgCamera2)

public:
	CDlgCamera2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgCamera2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
