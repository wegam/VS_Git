
// MFC定时器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC定时器.h"
#include "MFC定时器Dlg.h"
#include "afxdialogex.h"

#include	"afxwin.h "	//线程

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




UINT DemoC(LPVOID pParam)		//串口接收和显示
{
	CMFC定时器Dlg * pMyClass = (CMFC定时器Dlg*)pParam;

	static	UINT	mm = 0;
	static	UINT	ss = 0;
	static	UINT	mss = 0;
	CString	str;

		mss++;
		if (mss == 99)
		{
			mss = 0; ss++;
		}
		if (ss == 59)
		{
			ss = 0; mm++;
		}
		str.Format(_T("%02i:%02i:%02i"), mm, ss, mss);
		pMyClass->m_time.SetWindowTextW(str);

	return 0;

}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFC定时器Dlg 对话框



CMFC定时器Dlg::CMFC定时器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC定时器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TimeDis, m_time);
}

BEGIN_MESSAGE_MAP(CMFC定时器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Timer, &CMFC定时器Dlg::OnBnClickedTimer)
	ON_BN_CLICKED(IDC_Reset, &CMFC定时器Dlg::OnBnClickedReset)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFC定时器Dlg 消息处理程序

BOOL CMFC定时器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC定时器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC定时器Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC定时器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC定时器Dlg::OnBnClickedTimer()
{
	// TODO: 在此添加控件通知处理程序代码
	//nIDEvent，定时器ID；
	//nElapse，定时器定时时间，单位为毫秒；
	//回调函数，设为NULL即可。
	SetTimer(1, 1, NULL);
}


void CMFC定时器Dlg::OnBnClickedReset()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);
	m_time.SetWindowTextW(_T("00:00:00"));
}


void CMFC定时器Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	static	UINT	mm = 0;
	static	UINT	ss = 0;
	static	UINT	mss = 0;
	CString	str;
	switch (nIDEvent)
	{
	case	1:
		AfxBeginThread(DemoC, this);			//串口接收和显示线程
		break;

	}
	
	CDialogEx::OnTimer(nIDEvent);


	//// TODO: 在此添加消息处理程序代码和/或调用默认值
	//static	UINT	mm = 0;
	//static	UINT	ss = 0;
	//static	UINT	mss = 0;
	//CString	str;
	//switch (nIDEvent)
	//{
	//case	1:
	//	mss++;
	//	if (mss == 100)
	//	{
	//		mss = 0; ss++;
	//	}
	//	if (ss == 59)
	//	{
	//		ss = 0; mm++;
	//	}
	//	str.Format(_T("%02i:%02i:%02i"), mm, ss, mss);
	//	m_time.SetWindowTextW(str);
	//	break;

	//}
	//AfxBeginThread(DemoC, this);			//串口接收和显示线程
	//CDialogEx::OnTimer(nIDEvent);
}
