// kpatchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "kpatch.h"
#include "kpatchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

char gv_DisBuffer[E_TEMP_RECV_BUF_SIZE];
////////////////

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CkpatchDlg dialog




CkpatchDlg::CkpatchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CkpatchDlg::IDD, pParent)
	,m_pFile(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkpatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COM, m_cmbCom);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, m_cmbBaud);
	DDX_Control(pDX, IDC_TABLE1, m_ChartCtrl1);
	DDX_Control(pDX, IDC_TABLE2, m_ChartCtrl2);
	
}

BEGIN_MESSAGE_MAP(CkpatchDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_CBN_DROPDOWN(IDC_COMBO_COM, &CkpatchDlg::OnCbnDropdownComboCom)
	ON_WM_SERIAL(OnSerialMsg)
	ON_BN_CLICKED(IDC_BUTTON_BRW, &CkpatchDlg::OnBnClickedButtonBrw)
	ON_BN_CLICKED(IDC_BUTTON_START, &CkpatchDlg::OnBnClickedButtonStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_UPDATE_XY, &CkpatchDlg::OnBnClickedUpdateXy)
	ON_BN_CLICKED(IDC_LOG_DECODE, &CkpatchDlg::OnBnClickedLogDecode)
	ON_BN_CLICKED(IDC_CHECK1, &CkpatchDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RESET_DIS, &CkpatchDlg::OnBnClickedResetDis)
	ON_BN_CLICKED(IDC_CHECK2, &CkpatchDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CkpatchDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_FILTER, &CkpatchDlg::OnBnClickedFilter)
END_MESSAGE_MAP()


// CkpatchDlg message handlers

BOOL CkpatchDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	Init();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CkpatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CkpatchDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CkpatchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CkpatchDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnCancel();
}

void CkpatchDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnOK();
}
CString g_szUsage;
#if 0
const TCHAR g_szUsage[]=
{
	_T("1.选择输出文件.\r\n2.选择正确的串口和波特率.\r\n3.点Start开始.\r\n4.如有数据收到,计数器中会显示收到的字节数.\r\n")
	_T("5.点Stop停止. 此时数据才被写入文件.\r\n")
	_T("6.请填写AD数据前的标识字符串\r\n")

	
};
#endif
void CkpatchDlg::InitTable(void)
{


	m_ChartCtrl1.Init();
	m_ChartCtrl2.Init();


	((CComboBox*)GetDlgItem(IDC_COMBOX))->InsertString(X_TIME, _T("时间"));
	((CComboBox*)GetDlgItem(IDC_COMBOX))->InsertString(X_INDEX, _T("ID"));
	((CComboBox*)GetDlgItem(IDC_COMBOX))->SetCurSel(X_TIME);
	((CComboBox*)GetDlgItem(IDC_COMBOY))->InsertString(Y_ADJDIFFVAL, _T("相邻差值"));
	((CComboBox*)GetDlgItem(IDC_COMBOY))->InsertString(Y_ADVAL, _T("当前AD值"));
	((CComboBox*)GetDlgItem(IDC_COMBOY))->InsertString(Y_FIRSTDIFFVAL, _T("和第一次值的差值"));
	((CComboBox*)GetDlgItem(IDC_COMBOY))->SetCurSel(Y_ADJDIFFVAL);
	OnBnClickedUpdateXy();

}
void CkpatchDlg::Init()
{
	VEC_STR vec;
	size_t i;
	CSerial::GetComList(vec);

	m_cmbBaud.SetCurSel(0);
	for(i=0;i<vec.size();++i)
	{
		m_cmbCom.AddString(vec[i].c_str());
	}
	if(vec.size()>0)
	{
		m_cmbCom.SetCurSel(vec.size()-1);
	}
	SetDlgItemText(IDC_EDIT_FN,_T("dump.txt"));
	SetDlgItemText(IDC_EDIT2,g_szUsage);
	SetDlgItemText(IDC_FLG_STR, _T("CH1:"));
	SetDlgItemText(IDC_FLG_STR2, _T("CH2:"));
	((CEdit*)GetDlgItem(IDC_FLG_STR))->SetLimitText(63);
	((CEdit*)GetDlgItem(IDC_FLG_STR2))->SetLimitText(63);
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(1);
	InitTable();
	OnBnClickedCheck1();
}
void CkpatchDlg::OnCbnDropdownComboCom()
{
	// TODO: Add your control notification handler code here
	VEC_STR vec;
	CSerial::GetComList(vec);

	m_cmbCom.ResetContent();
	for(size_t i=0;i<vec.size();++i)
	{
		m_cmbCom.AddString(vec[i].c_str());
	}
	if(vec.size()>0 )
	{
		m_cmbCom.SetCurSel(vec.size()-1);
	}
}

void CkpatchDlg::OnBnClickedButtonBrw()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE
		,_T("*.txt")
		,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT
		,_T("uart  data file (*.txt)|*.txt|All Files (*.*)|*.*||")
		,this);
	if( dlg.DoModal()==IDOK )
	{
		SetDlgItemText(IDC_EDIT_FN,dlg.GetPathName());
	}

}
#define ShowMsg	AfxMessageBox

BOOL CkpatchDlg::IsInputValid()
{
	BOOL bOk=FALSE;
	GetDlgItemText(IDC_EDIT_FN,m_strFn);
	if(m_strFn.IsEmpty())
	{
		ShowMsg(_T("Please select output file first!"));
	}
	else
	{
		try
		{
			if(m_pFile !=NULL)
			{
				delete m_pFile;
				m_pFile=NULL;
			}
			m_pFile=new CFile(m_strFn,CFile::modeWrite | CFile::modeCreate);
			bOk=TRUE;
		}
		catch (CFileException* e)
		{
			e->ReportError();
			e->Delete();
		}
		catch (CException* e)
		{
			e->ReportError();
			e->Delete();
		}
	}
	return bOk;
}
void CkpatchDlg::EnableUI(BOOL bOp/*=TRUE*/)
{
	GetDlgItem(IDC_COMBO_COM)->EnableWindow(bOp);
	GetDlgItem(IDC_COMBO_BAUDRATE)->EnableWindow(bOp);
	GetDlgItem(IDC_BUTTON_BRW)->EnableWindow(bOp);
}
void  CkpatchDlg::UpdateFilterPara(void)
{
	CString FileName, tmp;
	CTime tm = CTime::GetCurrentTime();
	FileName.Format(_T("dump%s.txt"), tm.Format(_T("%Y-%m-%d_%H_%M_%S")));

	SetDlgItemText(IDC_EDIT_FN, FileName);

	if (IsInputValid())
	{

		char flgstr[DECODE_CMD_MAX_LEN];
		GetDlgItemText(IDC_FLG_STR, tmp);

		//注意：以下n和len的值大小不同,n是按字符计算的，len是按字节计算的
		int n = tmp.GetLength();
		//获取宽字节字符的大小，大小是按字节计算的
		int len = WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), NULL, 0, NULL, NULL);
		//为多字节字符数组申请空间，数组大小为按字节计算的宽字节字节大小

		//宽字节编码转换成多字节编码
		WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), (char*)flgstr, len, NULL, NULL);
		flgstr[len] = '\0';   //多字节字符以’\0′结束
		m_ChartCtrl1.SetFlgStr(flgstr);
		tmp.Replace(_T(":"), _T("："));
		tmp.Replace(_T("\\"), _T("、"));
		tmp.Replace(_T("/"), _T("、"));
		tmp.Replace(_T("*"), _T(""));
		tmp.Replace(_T("<"), _T("《"));
		tmp.Replace(_T(">"), _T("》"));
		tmp.Replace(_T("|"), _T(""));
		//tmp.Left(_T(":"));
		FileName.Format(_T("AD_%s_%s.csv"), tmp, tm.Format(_T("%Y-%m-%d_%H_%M_%S")));
		m_ChartCtrl1.CreatecRecordFile(FileName);
		//reset to 0. if using U0, it will be set after connect is established.

		GetDlgItemText(IDC_FLG_STR2, tmp);

		//注意：以下n和len的值大小不同,n是按字符计算的，len是按字节计算的
		n = tmp.GetLength();
		//获取宽字节字符的大小，大小是按字节计算的
		len = WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), NULL, 0, NULL, NULL);
		//为多字节字符数组申请空间，数组大小为按字节计算的宽字节字节大小

		//宽字节编码转换成多字节编码
		WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), (char*)flgstr, len, NULL, NULL);
		flgstr[len] = '\0';   //多字节字符以’\0′结束
		m_ChartCtrl2.SetFlgStr(flgstr);
		tmp.Replace(_T(":"), _T("："));
		tmp.Replace(_T("\\"), _T("、"));
		tmp.Replace(_T("/"), _T("、"));
		tmp.Replace(_T("*"), _T(""));
		tmp.Replace(_T("<"), _T("《"));
		tmp.Replace(_T(">"), _T("》"));
		tmp.Replace(_T("|"), _T(""));
		//tmp.Left(_T(":"));
		FileName.Format(_T("AD_%s_%s.csv"), tmp, tm.Format(_T("%Y-%m-%d_%H_%M_%S")));
		m_ChartCtrl2.CreatecRecordFile(FileName);
	}

}
void CkpatchDlg::OnBnClickedButtonStart()
{
	// TODO: Add your control notification handler code here
	//test code
	// 	g_Flash.GenFlashTypeFromFile("flash.txt",0x20,0x10);
	// 	FillListWithFlashInfo();
	CString strCom;
	m_cmbCom.GetWindowText(strCom);
	//_SYSTEMTIME
	memset(gv_DisBuffer, 0x0, E_TEMP_RECV_BUF_SIZE);
	if(m_serial.IsOpen())
	{
		if( m_serial.Close() == ERROR_SUCCESS)
		{
			KillTimer(m_nTimerID);
			
	
	
			SetDlgItemText(IDC_BUTTON_START,_T("打开"));
			EnableUI(TRUE);
		}
		else
		{
			ShowMsg(_T("Close Error!"));
		}
	}
	else
	{
	

		if (m_strFn.IsEmpty())
		{
			UpdateFilterPara();
		}
			m_serial.SetDefaultParameters((CSerial::EBaudrate) a_PCSpeedValue[m_cmbBaud.GetCurSel()]);

			if (m_serial.Open(strCom, this, WM_NULL, NULL, E_BUFFER_SIZE, E_BUFFER_SIZE) == ERROR_SUCCESS)
			{
				m_serial.Purge();
				m_serial.SetupHandshaking(CSerial::EHandshakeOff);
				//m_serial.SetMask();
				//m_State=S_DLD_INIT;
				//m_serial.StartListener();
				m_ReceivedCount = 0;

				SetDlgItemInt(IDC_EDIT1, m_ReceivedCount, FALSE);
				SetDlgItemText(IDC_BUTTON_START, _T("关闭"));
				EnableUI(FALSE);
				m_nTimerID = SetTimer(1, 500, NULL);
			}
			else
			{
				//TCHAR caBuf[256];
				//_stprintf_s(caBuf, sizeof(caBuf), _T("Error %s: %u"), LPCTSTR(strCom), GetLastError());
				//ShowMsg(caBuf);
				CString strbuf;
				strbuf.Format(_T("Error %s: %u"), LPCTSTR(strCom), GetLastError());
				ShowMsg(strbuf);
				
			}
	
	}
}


u8		vg_RecvBuffer[E_TEMP_RECV_BUF_SIZE];
void DisDataCopy(char *pdest, UINT destLen, char* psoure, UINT len)
{
	UINT MaxLen = destLen - 1;
	try
	{
		UINT i, dellen;
		UINT destStrlen = strlen((char*)pdest);
		if (destStrlen > MaxLen)
		{
			destStrlen = MaxLen;
		}

		if (destStrlen > 0)
		{
			if ((destStrlen + len)> MaxLen)
			{

				if (len > MaxLen)
				{
					UINT mvlen = len - MaxLen;
					for (i = 0; i < MaxLen; i++)
					{
						pdest[i] = psoure[i + mvlen];
					}
				}
				else
				{
					dellen = destStrlen + len - MaxLen;
					UINT mvlen = MaxLen - dellen;
					if (mvlen > MaxLen)
					{
						UINT pos = mvlen - MaxLen;
						for (i = 0; i < MaxLen; i++)
						{
							pdest[i] = psoure[i + pos];
						}
					}
					else
					{
						for (i = 0; i < mvlen; i++)
						{

							pdest[i] = pdest[i + dellen];
						}
						for (i = 0; i < len; i++)
						{
							pdest[mvlen + i] = psoure[i];
						}
					}
				}
				pdest[MaxLen] = 0;
				return;



			}
		}
		for (i = 0; (i < len)&&( i<MaxLen); i++)
		{
			pdest[destStrlen + i] = psoure[i];
		}
	}

	catch (CException* e)
	{
		e->ReportError();
		e->Delete();
	}
	
	pdest[MaxLen] = 0;
}



afx_msg LRESULT CkpatchDlg::OnSerialMsg (WPARAM wParam, LPARAM lParam)
{
	CSerial::EEvent eEvent = CSerial::EEvent(LOWORD(wParam));
	CSerial::EError eError = CSerial::EError(HIWORD(wParam));
	DWORD vl_Temp;
	// lParam: User-defined 32-bit integer (type LPARAM)
	switch (eEvent)
	{
	case CSerialMFC::EEventRecv:
		if(m_pFile !=NULL)
		{
			while(1)
			{
				memset(vg_RecvBuffer, 0x0, E_TEMP_RECV_BUF_SIZE);
				m_serial.Read(vg_RecvBuffer,E_TEMP_RECV_BUF_SIZE,&vl_Temp);
				if(vl_Temp > 0)
				{
					m_ReceivedCount+=vl_Temp;


					DisDataCopy((char*)gv_DisBuffer, E_TEMP_RECV_BUF_SIZE , (char*)vg_RecvBuffer, vl_Temp);
					int dislen = strlen(gv_DisBuffer)+1;
					GbkToUnicode((char*)gv_DisBuffer, dislen, g_szUsage.GetBuffer(dislen), dislen);
					
					g_szUsage.ReleaseBuffer();
					
					m_ChartCtrl1.UnPacket((char*)vg_RecvBuffer, vl_Temp);
					m_ChartCtrl2.UnPacket((char*)vg_RecvBuffer, vl_Temp);
					m_pFile->Write(vg_RecvBuffer,vl_Temp);
				}
				else
				{
					break;
				}
			}
		}
		break;
	}
	// Return successful
	return 0;

}

void CkpatchDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == m_nTimerID)
	{
		CString tmp;
		static int time=0;
		SetDlgItemInt(IDC_EDIT1,m_ReceivedCount,FALSE);

		SetDlgItemText(IDC_EDIT2, g_szUsage);
		((CEdit*)GetDlgItem(IDC_EDIT2))->SetSel(E_TEMP_RECV_BUF_SIZE, E_TEMP_RECV_BUF_SIZE, FALSE);
		//GetDlgItem(IDC_EDIT2)->SetFocus();
		SetDlgItemText(IDC_DIS_VAL, m_ChartCtrl1.GetLastStr());
		tmp.Format(_T("%d"), m_ChartCtrl1.GetAdjMaxDiffVal());
		SetDlgItemText(IDC_VAL_MAX, tmp);
		tmp.Format(_T("%d"), m_ChartCtrl1.GetAdjMinDiffVal());
		SetDlgItemText(IDC_VAL_MIN, tmp);
		
		///////////////////////
		SetDlgItemText(IDC_DIS_VAL2, m_ChartCtrl2.GetLastStr());
		tmp.Format(_T("%d"), m_ChartCtrl2.GetAdjMaxDiffVal());
		SetDlgItemText(IDC_VAL_MAX2, tmp);
		tmp.Format(_T("%d"), m_ChartCtrl2.GetAdjMinDiffVal());
		SetDlgItemText(IDC_VAL_MIN2, tmp);
		/////////////////////////////
		SetDlgItemInt(IDC_EDIT1, m_ReceivedCount, FALSE);

	
	
	}
	else if (nIDEvent == TABLE_UPDATE_TIMER)
	{
		m_ChartCtrl1.RefreshUi();
		m_ChartCtrl2.RefreshUi();
	}
	CDialog::OnTimer(nIDEvent);
}


void CkpatchDlg::OnBnClickedUpdateXy()
{
	// TODO:  在此添加控件通知处理程序代码
	t_SerieX x;
	t_SerieY y;
	x = (t_SerieX)((CComboBox*)GetDlgItem(IDC_COMBOX))->GetCurSel();
	y = (t_SerieY)((CComboBox*)GetDlgItem(IDC_COMBOY))->GetCurSel();
	m_ChartCtrl1.SetSerieXY(x,y);
	m_ChartCtrl2.SetSerieXY(x,y);
}
void CkpatchDlg::SetFlgstr(void)
{
	CString tmp;
	char flgstr[DECODE_CMD_MAX_LEN];
	GetDlgItemText(IDC_FLG_STR, tmp);

	//注意：以下n和len的值大小不同,n是按字符计算的，len是按字节计算的
	int n = tmp.GetLength();
	//获取宽字节字符的大小，大小是按字节计算的
	int len = WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), NULL, 0, NULL, NULL);
	//为多字节字符数组申请空间，数组大小为按字节计算的宽字节字节大小

	//宽字节编码转换成多字节编码
	WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), (char*)flgstr, len, NULL, NULL);
	flgstr[len] = '\0';   //多字节字符以’\0′结束
	m_ChartCtrl1.SetFlgStr(flgstr);
	GetDlgItemText(IDC_FLG_STR2, tmp);

	//注意：以下n和len的值大小不同,n是按字符计算的，len是按字节计算的
	n = tmp.GetLength();
	//获取宽字节字符的大小，大小是按字节计算的
	len = WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), NULL, 0, NULL, NULL);
	//为多字节字符数组申请空间，数组大小为按字节计算的宽字节字节大小

	//宽字节编码转换成多字节编码
	WideCharToMultiByte(CP_ACP, 0, tmp, tmp.GetLength(), (char*)flgstr, len, NULL, NULL);
	flgstr[len] = '\0';   //多字节字符以’\0′结束
	m_ChartCtrl2.SetFlgStr(flgstr);
}

void CkpatchDlg::OnBnClickedLogDecode()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strFile ;
	TCHAR Buffer[MAX_PATH];
	DWORD dwRet;
	//获取当前程序路径
	dwRet = GetCurrentDirectory(MAX_PATH, Buffer);
	if (dwRet == 0)
	{
		//PrintMsg("GetCurrentDirectory failed (%d)\n", GetLastError());
		return;
	}
	if (dwRet > MAX_PATH)
	{
		//PrintMsg("Buffer too small; need %d characters\n", dwRet);
		return;
	}

	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT , _T("log Files (*.txt)|*.txt|All Files (*.*)|*.*|"));
	//CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, _T("log Files (*.txt)|*.txt|All Files (*.*)|*.*|"), NULL);
	TCHAR   buf[20480] = _T(" ");
	dlgFile.m_ofn.lpstrFile = buf;
	dlgFile.m_ofn.nMaxFile = 2048;
	dlgFile.m_ofn.lpstrInitialDir = (LPCTSTR)Buffer;//初始化最初的路径。  

	if (dlgFile.DoModal())
	{
		strFile = dlgFile.GetPathName();
	}
	if (strFile.IsEmpty())
	{
		AfxMessageBox(_T("没有可以分析文件"));
	}
	else
	{
#if 0
		CStdioFile file;
		CString line;
		ULONGLONG d;
		int len;
		m_ChartCtrl1.Clear();
		m_ChartCtrl2.Clear();
		SetFlgstr();
		file.Open(strFile, CFile::modeRead);
		
		while (file.ReadString(line))
		{
			d = file.GetPosition();
			file.ReadString(line);

			char  readbuf[1024];
			len=UnicodeToGbk(line.GetBuffer(line.GetLength()), line.GetLength(), readbuf, 1024);
			line.ReleaseBuffer();
			readbuf[len++] = '\r';
			readbuf[len++] = '\n';
			readbuf[len] = '0';
			m_ChartCtrl1.UnPacket(readbuf, len);
			m_ChartCtrl2.UnPacket(readbuf, len);;
			
			//TRACE("line=%d\n", d);
		}
		file.Close();
#else
		CFile File;
		CFileException fileException;
		if (File.Open(strFile,CFile::modeRead, &fileException))
		{

			char  readbuf[1024];
			
			int len = File.Read(readbuf, 1024);
			SetFlgstr();
			while (len > 0)
			{
				m_ChartCtrl1.UnPacket((char*)readbuf, len);
				m_ChartCtrl2.UnPacket((char*)readbuf, len);
				len = File.Read(readbuf, 1024);
			}
			File.Close();
		}
#endif
		
	}

}


void CkpatchDlg::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK1))
	{
	   SetTimer(TABLE_UPDATE_TIMER, TABLE_UPDATE_TIMEOUT, NULL);
	}
	else
	{
		KillTimer(TABLE_UPDATE_TIMER);
	}
}


void CkpatchDlg::OnBnClickedResetDis()
{
	// TODO:  在此添加控件通知处理程序代码
	m_ChartCtrl1.ReStart();
	m_ChartCtrl2.ReStart();

}


void CkpatchDlg::OnBnClickedCheck2()
{
	// TODO:  在此添加控件通知处理程序代码
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK2))
	{
		m_ChartCtrl1.SetFigure(FIGURE_DECIMAL);
	}
	else
	{
		m_ChartCtrl1.SetFigure(FIGURE_HEX);
	}
}


void CkpatchDlg::OnBnClickedCheck3()
{
	// TODO:  在此添加控件通知处理程序代码
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK3))
	{
		m_ChartCtrl1.SetFigure(FIGURE_DECIMAL);
	}
	else
	{
		m_ChartCtrl1.SetFigure(FIGURE_HEX);
	}
}


void CkpatchDlg::OnBnClickedFilter()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_pFile != NULL)
	{
		if (m_pFile->GetLength()==0){
			CString tmp;
			tmp = m_pFile->GetFilePath();
			m_pFile->Close();
			//AfxMessageBox(tmp);
			DeleteFile(tmp);
		}
		else
		{
			m_pFile->Close();
		}

		
		
		
		delete m_pFile;
		m_pFile = NULL;
	}
	UpdateFilterPara();
}
