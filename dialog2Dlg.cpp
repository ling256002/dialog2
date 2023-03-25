
// dialog2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "dialog2.h"
#include "dialog2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cdialog2Dlg dialog



Cdialog2Dlg::Cdialog2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2_DIALOG, pParent)
	, m_fruit(0)
	, m_cloths(FALSE)
	, m_pants(FALSE)
	, m_hats(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdialog2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Radio(pDX, IDC_RADIO1, m_fruit);
	DDX_Check(pDX, IDC_CHECK1, m_cloths);
	DDX_Check(pDX, IDC_CHECK2, m_pants);
	DDX_Check(pDX, IDC_CHECK3, m_hats);*/
}

BEGIN_MESSAGE_MAP(Cdialog2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CHECK, &Cdialog2Dlg::OnBnClickedBtnCheck)
	/*ON_BN_CLICKED(IDC_RADIO1, &Cdialog2Dlg::OnBnClickedRadio1)*/
END_MESSAGE_MAP()


// Cdialog2Dlg message handlers

BOOL Cdialog2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CListBox* list = (CListBox*)GetDlgItem(IDC_LIST1);
	list->AddString(_T("上海")); //把text的内容添加到列表框中
	list->AddString(_T("深圳"));
	list->AddString(_T("北京"));
	list->AddString(_T("广州"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cdialog2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cdialog2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cdialog2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cdialog2Dlg::OnBnClickedBtnCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取文本框的内容
	CString text;

	////得到文本框对象
	//CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	//edit->GetWindowText(text); //把文本框的内容放入text中
	//edit->SetWindowText(_T("")); //把文本框输入内容设置为空（清空输入的内容）

	//// 将文本添加到列表框
	//CListBox* list = (CListBox*)GetDlgItem(IDC_LIST1);
	//if (!(text.IsEmpty()))
	//{
	//	list->AddString(text); //把text的内容添加到列表框中
	//}

	CListBox* list = (CListBox*)GetDlgItem(IDC_LIST1);
	int choose = list->GetCurSel();
	list->GetText(choose, text);
	MessageBox(text);

	CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	edit->SetWindowText(text);

}


void Cdialog2Dlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	//MessageBox(_T("点击了单选！！"));
}
