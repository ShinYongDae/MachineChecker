#pragma once


// CDlgCamera1 대화 상자입니다.

class CDlgCamera1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgCamera1)

public:
	CDlgCamera1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgCamera1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
