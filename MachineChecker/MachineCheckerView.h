
// MachineCheckerView.h : CMachineCheckerView Ŭ������ �������̽�
//

#pragma once


class CMachineCheckerView : public CFormView
{
	CString FileBrowse();

protected: // serialization������ ��������ϴ�.
	CMachineCheckerView();
	DECLARE_DYNCREATE(CMachineCheckerView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MACHINECHECKER_FORM };
#endif

// Ư���Դϴ�.
public:
	CMachineCheckerDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMachineCheckerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpen();
};

#ifndef _DEBUG  // MachineCheckerView.cpp�� ����� ����
inline CMachineCheckerDoc* CMachineCheckerView::GetDocument() const
   { return reinterpret_cast<CMachineCheckerDoc*>(m_pDocument); }
#endif

