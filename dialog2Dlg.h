
// dialog2Dlg.h : header file
//

#pragma once


// Cdialog2Dlg dialog
class Cdialog2Dlg : public CDialogEx
{
// Construction
public:
	Cdialog2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCheck();
	afx_msg void OnBnClickedRadio1();
	int m_fruit;
	BOOL m_cloths;
	BOOL m_pants;
	BOOL m_hats;
};
