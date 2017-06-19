
// MFC��ʱ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC��ʱ��.h"
#include "MFC��ʱ��Dlg.h"
#include "afxdialogex.h"

#include	"afxwin.h "	//�߳�

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




UINT DemoC(LPVOID pParam)		//���ڽ��պ���ʾ
{
	CMFC��ʱ��Dlg * pMyClass = (CMFC��ʱ��Dlg*)pParam;

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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFC��ʱ��Dlg �Ի���



CMFC��ʱ��Dlg::CMFC��ʱ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC��ʱ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TimeDis, m_time);
}

BEGIN_MESSAGE_MAP(CMFC��ʱ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Timer, &CMFC��ʱ��Dlg::OnBnClickedTimer)
	ON_BN_CLICKED(IDC_Reset, &CMFC��ʱ��Dlg::OnBnClickedReset)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFC��ʱ��Dlg ��Ϣ�������

BOOL CMFC��ʱ��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC��ʱ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC��ʱ��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC��ʱ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC��ʱ��Dlg::OnBnClickedTimer()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//nIDEvent����ʱ��ID��
	//nElapse����ʱ����ʱʱ�䣬��λΪ���룻
	//�ص���������ΪNULL���ɡ�
	SetTimer(1, 1, NULL);
}


void CMFC��ʱ��Dlg::OnBnClickedReset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
	m_time.SetWindowTextW(_T("00:00:00"));
}


void CMFC��ʱ��Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	static	UINT	mm = 0;
	static	UINT	ss = 0;
	static	UINT	mss = 0;
	CString	str;
	switch (nIDEvent)
	{
	case	1:
		AfxBeginThread(DemoC, this);			//���ڽ��պ���ʾ�߳�
		break;

	}
	
	CDialogEx::OnTimer(nIDEvent);


	//// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	//AfxBeginThread(DemoC, this);			//���ڽ��պ���ʾ�߳�
	//CDialogEx::OnTimer(nIDEvent);
}
