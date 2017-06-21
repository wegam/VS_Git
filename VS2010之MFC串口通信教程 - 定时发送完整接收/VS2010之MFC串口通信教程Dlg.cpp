
// VS2010之MFC串口通信教程Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VS2010之MFC串口通信教程.h"
#include "VS2010之MFC串口通信教程Dlg.h"
#include "afxdialogex.h"

#include	"stdlib.h"		//malloc动态申请内存空间
#include	"windows.h"		//malloc动态申请内存空间
#include	"iostream"		//malloc动态申请内存空间
#include	"stdarg.h"			//用于获取不确定个数的参数
#include	"string.h"			//用于printf
#include	"intsafe.h"

#include	"process.h"
#include	"time.h"
#include	"stdio.h"


#include	"string.h"
#include	"sstream"

#include	"afxwin.h "

#include	"locale.h "





#ifdef _DEBUG
#define new DEBUG_NEW
#endif


bool	bSave = false;
CFile file;
CString filename;
CString m_txt = _T("");		//输出字符串

UINT CVS2010之MFC串口通信教程Dlg::DemoB(LPVOID pParam)
{
	return 0;
}

UINT DemoA(LPVOID pParam)
{
	CVS2010之MFC串口通信教程Dlg * pMyClass = (CVS2010之MFC串口通信教程Dlg*)pParam;

	CString m_SD = _T("");
		SYSTEMTIME time;
		::GetLocalTime(&time);
		//自动换行
		if (pMyClass->m_CHECKRTN.GetCheck())
		{
			/**(str + k) = '\t';
			*(str + k + 1) = '\n';*/
			m_SD.Format(_T("%04d年%02d月%02d日%02d:%02d:%02d:%03d->\t\n"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		}
		else
		{
			m_SD.Format(_T("%04d年%02d月%02d日%02d:%02d:%02d:%03d->"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		}

		//::SetDlgItemText(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_EDIT_Send, m_SD);

		//滚动条处于最下方，如下的代码将实现这一功能2
		CEdit*pedit = (CEdit*)pMyClass->GetDlgItem(IDC_EDIT_Send);
		unsigned long   nline = pedit->GetLimitText();
		nline += m_SD.GetLength();
		SetFocus(0);		//设定光标位置为第一行第一位
		nline = pedit->GetLineCount();		//获取新行
		pedit->SetSel(-1, -1);				//将光标放置到最后一行起始位，从上往下
		pedit->ReplaceSel(m_SD, true);		//插入显示数据

	return 0;
}

UINT DemoC(LPVOID pParam)		//串口接收和显示
{
	CVS2010之MFC串口通信教程Dlg * pMyClass = (CVS2010之MFC串口通信教程Dlg*)pParam;

	char str[2048] = { 0 };
	long k = 0;
	long len=0;
	long rxcount=0;
	long   nline;
	long   newline;
	CString m_SD = _T("");		//输出字符串
	//CString m_txt = _T("");		//输出字符串
	CString m_EDIT_Dcont;
	CString m_EDIT_Rxcont;
	CString pOut;
	Sleep(100);
	

	VARIANT InputData = pMyClass->m_mscom.get_Input(); //读缓冲区
	COleSafeArray fs;
	fs = InputData; //VARIANT型变À量转换为COleSafeArray型变量
	len = fs.GetOneDimSize();
	pMyClass->SetDlgItemInt(IDC_EDIT_Txcont, len, 1);
	

	
	if (len > 0)
	{
		//更新行数---增加一行
		newline = pMyClass->GetDlgItemInt(IDC_EDIT_Dcont);
		nline = newline;
		newline = newline + 1;
		pMyClass->SetDlgItemInt(IDC_EDIT_Dcont, newline, 1);
		//打印时间
		if (pMyClass->m_PRINTTIME.GetCheck())
		{
			SYSTEMTIME time;
			::GetLocalTime(&time);
			//m_SD.Format(_T("%04d年%02d月%02d日%02d:%02d:%02d:%03d->\t"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
			m_SD.Format(_T("%04d-%02d-%02d %02d:%02d:%02d:%03d->\t"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		}
		//转换为BYTE型数组
		for (k = 0; k<len; k++)
			fs.GetElement(&k, str + k); //转换为BYTE型数组
		//CChineseCode::UTF_8ToGB2312((CString&)pOut, str,10);
		/*byte byt[] = System.Text.Encoding.Unicode.GetBytes(System.Text.Encoding.Unicode.GetString(new byte[]{ 0,29, 223,0 }));*/
		//#假设收到的数据数组 byte dat[100]; 数据长度 int num
		//CString str, tem;
		if (pMyClass->m_Hex.GetCheck())
		{
			//*********************************十六进制转换成字符串--开始
			CString tem;
			CString tem1;
			for (int i = 0; i < len; i++)
			{
				tem.Format(_T("%02x "), str[i]);				
				m_SD += tem;
			}			
			//*********************************十六进制转换成字符串--结束
		}
		else
			m_SD += str; // 接收到编辑框里面

		//自动换行
		if (pMyClass->m_CHECKRTN.GetCheck())
		{
			//*(str + k) = '\t';
			//*(str + k + 1) = '\n';
			m_SD += '\r';
			m_SD += '\n';
		}
//************************************************************窗口打印--开始
		////*************20161015
		//CEdit*pedit = (CEdit*)pMyClass->GetDlgItem(IDC_EDIT_Rev);
		//unsigned long   nline = pedit->GetLimitText();
		////nline += m_SD.GetLength();
		//nline = pedit->GetLineCount();		//获取新行
		//m_EDIT_Dcont.Format(_T("%05ld"), nline);
		//pedit->ShowCaret();     //hEdit是编辑框句柄 

		//pedit->SetFocus();				//设定光标位置为第一行第一位
		//pedit->SetSel(nline, -1, TRUE);				//将光标放置到最后一行起始位，从上往下
		//pedit->SetSel(-1, -1);				//将光标放置到最后一行起始位，从上往下
		//pedit->ReplaceSel(m_EDIT_Dcont+": "+m_SD, true);		//插入显示数据
		
		//*************20161016	
		//*************获取行数

		CEdit*pedit = (CEdit*)pMyClass->GetDlgItem(IDC_EDIT_Rev);

		m_EDIT_Dcont.Format(_T("%05ld"), nline);	//数字转换为字符

		pedit->ShowCaret();							//hEdit是编辑框句柄 

		m_SD = m_EDIT_Dcont + ": " + m_SD;

		pedit->SetFocus();							//设定光标位置为第一行第一位
		pedit->SetSel(nline, -1, TRUE);				//将光标放置到最后一行起始位，从上往下
		pedit->SetSel(-1, -1);						//将光标放置到最后一行起始位，从上往下
													//Sleep(500);
													//pedit->ReplaceSel(m_EDIT_Dcont + ": " + m_SD, true);		//插入显示数据
		pedit->ReplaceSel(m_SD, true);				//插入显示数据
		
		//CEdit*pedit = (CEdit*)pMyClass->GetDlgItem(IDC_EDIT_Rev);
		//unsigned long   nline = pedit->GetLimitText();
		////nline += m_SD.GetLength();
		////Sleep(1);
		//nline = pedit->GetLineCount();			//获取新行
		//m_EDIT_Dcont.Format(_T("%05ld"), nline);
		//pedit->ShowCaret();						//hEdit是编辑框句柄 

		//m_SD = m_EDIT_Dcont + ": " + m_SD;
		//
		//pedit->SetFocus();						//设定光标位置为第一行第一位
		//pedit->SetSel(nline, -1, TRUE);			//将光标放置到最后一行起始位，从上往下
		//pedit->SetSel(-1, -1);					//将光标放置到最后一行起始位，从上往下
		////Sleep(500);
		////pedit->ReplaceSel(m_EDIT_Dcont + ": " + m_SD, true);		//插入显示数据
		//pedit->ReplaceSel(m_SD, true);			//插入显示数据

//************************************************************窗口打印--开始
		//显示已接收字节数计数
		CEdit* pEDIT_Rxcont = (CEdit*)pMyClass->GetDlgItem(IDC_EDIT_Rxcont);
		unsigned long  m_Rxcont;
		m_Rxcont = pEDIT_Rxcont->GetDlgItemInt(IDC_EDIT_Rxcont);
		m_Rxcont += len;
		pEDIT_Rxcont->GetDlgItemInt(m_Rxcont);

//************************************************************保存到文件--开始
		if (bSave==true)
		{
			//CFile file;
			//CString filepath, filename, s;
			//CString m_strFolderPath = _T("d:\\串口接收数据");
			//SYSTEMTIME time;
			//::GetLocalTime(&time);
			//s.Format(_T("%04d-%02d-%02d-%02d.txt"), time.wYear, time.wMonth, time.wDay, time.wHour);
			//filepath = _T("d:\\串口接收数据\\"); //文件位置
			//filename = s;  //文件名 
			//filename = filepath + filename;  //文件路径 
			//file.Open(filename, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);//建立文件 
			//s = "";
			////s.Format(_T("%04d-%02d-%02d-%02d-%02d-%02d\r\n"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
			//s = m_EDIT_Dcont + ": " + m_txt;
			//UINT nLen = s.GetLength() * 2; // 得到18而不是11
			//file.SeekToEnd();
			//file.Write(s, nLen);
			//file.Close();  //关闭文件
			///*AfxBeginThread(DemoD, this);*/
			//m_txt = m_EDIT_Rxcont+": " + m_txt;
			//DemoE(m_txt);	//写入文本文件
			m_txt = m_SD;
			AfxBeginThread(DemoE,NULL);	//写入文本文件
		}
		else
		{
			//file.Close();  //关闭文件
		}

//************************************************************保存到文件--结束



//******************************************

	}
	
	return 0;
}
UINT DemoD(LPVOID pParam)			//打开和关闭文件
{
	CVS2010之MFC串口通信教程Dlg * pMyClass = (CVS2010之MFC串口通信教程Dlg*)pParam;

	if (bSave == true)
	{
			CString s;
			SYSTEMTIME time;
			::GetLocalTime(&time);
			filename = _T("d:\\串口接收数据\\"); //文件位置
			s.Format(_T("%04d-%02d-%02d-%02d.txt"), time.wYear, time.wMonth, time.wDay, time.wHour);
			filename += s;  //文件路径+文件名 
			
//			if (file.Open(filename, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))//建立文件 
//			{
//				filename += "\t\n";
//				//file.Write(filename, filename.GetLength() * 2);
//				m_txt.Format(_T("创建时间：\t%04d-%02d-%02d-%02d-%02d-%02d-%03d\r\n"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
//
//				//file.SeekToBegin();
//				//file.Write(m_txt, m_txt.GetLength() * 2);
//
//
////********************************* Unicode 转 Ansi 字符串，写入txt文件----开始
//				if (!m_txt)
//					return NULL;
//
//				int strleng = ::WideCharToMultiByte(CP_ACP, NULL, m_txt, wcslen(m_txt), NULL, 0, NULL, FALSE);
//				char* str = new char[strleng + 1];
//				::WideCharToMultiByte(CP_ACP, NULL, m_txt, wcslen(m_txt), str, strleng, NULL, FALSE);
//				str[strleng] = '\0';
//
//				file.SeekToEnd();
//				file.Write(str, strlen(str));		//以ANSI格式写入
////********************************* Unicode 转 Ansi 字符串，写入txt文件----结束
//
//				bSave = true;
//			}
			if (file.Open(filename, CFile::modeReadWrite))//建立文件
			{

			}
			else
			{
				if (file.Open(filename, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))//建立文件 
				{
					//filename += "\r\n";
					//file.Write(filename, filename.GetLength() * 2);
					m_txt.Format(_T("创建时间: %04d-%02d-%02d %02d:%02d:%02d:%03d\r\n"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
					m_txt = _T("创建路径：") + filename + "\r\n" + m_txt;
					//file.SeekToBegin();
					//file.Write(m_txt, m_txt.GetLength() * 2);


					//********************************* Unicode 转 Ansi 字符串，写入txt文件----开始
					if (!m_txt)
						return NULL;

					int strleng = ::WideCharToMultiByte(CP_ACP, NULL, m_txt, wcslen(m_txt), NULL, 0, NULL, FALSE);
					char* str = new char[strleng + 1];
					::WideCharToMultiByte(CP_ACP, NULL, m_txt, wcslen(m_txt), str, strleng, NULL, FALSE);
					str[strleng] = '\0';

					file.SeekToEnd();
					file.Write(str, strlen(str));		//以ANSI格式写入
														//********************************* Unicode 转 Ansi 字符串，写入txt文件----结束

					bSave = true;
				}
			}
	}
	else
	{
			bSave = false;
			file.Close();  //关闭文件
			
	}
	//if (pMyClass->m_SAVEF.GetCheck())
	//{
	//	CString s;
	//	SYSTEMTIME time;
	//	::GetLocalTime(&time);
	//	filename = _T("d:\\串口接收数据\\"); //文件位置
	//	s.Format(_T("%04d-%02d-%02d-%02d.txt"), time.wYear, time.wMonth, time.wDay, time.wHour);
	//	filename += s;  //文件路径+文件名 
	//	if (file.Open(filename, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))//建立文件 
	//	{
	//		//Sleep(10);
	//		bSave = true;
	//	}

	//}
	//else if(bSave == true)
	//{
	//	//file.Abort();	//终止文件操作
	//	//file.Flush();
	//	//file.Close();  //关闭文件
	//	bSave = false;
	//	//Sleep(10);
	//	file.Close();  //关闭文件
	//}
	return 0;
}
UINT DemoE(LPVOID pParam)			//写入数据到文本
{
	if (bSave == true)
	{

		//wchar_t *pUnicode = TEXT("Convert Unicode to ANSI, Unicode 转换为 ANSI");
		//char    *pANSI = NULL;
		//int      nByte = 0;
		//// step.1
		//nByte = WideCharToMultiByte(CP_ACP, 0, pUnicode, -1, NULL, 0, NULL, NULL);
		//// step.2
		//pANSI = (char*)malloc(nByte);
		//// step.3
		//WideCharToMultiByte(CP_ACP, 0, pUnicode, -1, pANSI, nByte, NULL, NULL);
		//// step.4
		//printf_s("ANSI = %s\n", pANSI);
		//// step.5
		//free(pANSI);

		////wchar_t *pUnicode = TEXT("Convert Unicode to ANSI, Unicode 转换为 ANSI");
		//char    *pANSI = NULL;
		//int      nByte = 0;
		//// step.1
		//nByte = WideCharToMultiByte(CP_ACP, 0, m_txt, -1, NULL, 0, NULL, NULL);
		//// step.2
		//pANSI = (char*)malloc(nByte);
		//// step.3
		//WideCharToMultiByte(CP_ACP, 0, m_txt, -1, pANSI, nByte, NULL, NULL);
		//// step.4
		////printf_s("ANSI = %s\n", pANSI);
		//
		////pANSI[nByte] = '\0';

		//file.SeekToEnd();
		////file.Write(pANSI, nByte *sizeof(char));
		//file.Write(pANSI,160);
		//// step.5
		//free(pANSI);
		//char* UnicodeToAnsi(TCHAR* wstr)
		//{
			//if (!m_txt)
			//	return NULL;
	
			//int strleng = ::WideCharToMultiByte(CP_ACP, NULL, m_txt, wcslen(m_txt), NULL, 0, NULL, FALSE);
			//char* str = new char[strleng + 1];
			//::WideCharToMultiByte(CP_ACP, NULL, m_txt, wcslen(m_txt), str, strleng, NULL, FALSE);
			//str[strleng] = '\0';
			
		//	return str;
		//}

		//file.SeekToEnd();
		//file.Write(str, strlen(str));		//以ANSI格式写入
		//char* str;
		//str = UnicodeToAnsi(m_txt);
		file.SeekToEnd();
		file.Write(UnicodeToAnsi(m_txt), strlen(UnicodeToAnsi(m_txt)));		//以ANSI格式写入
			
	}
	else
	{
//		Sleep(1);
//		file.Close();  //关闭文件
	}
	return 0;
}
UINT Comm_Read(LPVOID pParam)
{
	CVS2010之MFC串口通信教程Dlg * pMyClass = (CVS2010之MFC串口通信教程Dlg*)pParam;

	char str[2048] = { 0 };
	long k = 0;
	long len = 0;
	long rxcount = 0;
	long   nline;
	long   newline;
	long  m_Rxcont;
	CString m_SD = _T("");		//输出字符串
								//CString m_txt = _T("");		//输出字符串
	CString m_EDIT_Dcont;
	CString m_EDIT_Rxcont;
	CString pOut;

	VARIANT InputData = pMyClass->m_mscom.get_Input(); //读缓冲区
	COleSafeArray fs;
	fs = InputData; //VARIANT型变À量转换为COleSafeArray型变量
	len = fs.GetOneDimSize();

	//*********************************显示已接收字节数计数
	m_Rxcont = pMyClass->GetDlgItemInt(IDC_EDIT_Rxcont);
	m_Rxcont += len;
	pMyClass->SetDlgItemInt(IDC_EDIT_Rxcont, m_Rxcont);
	//*********************************更新行数---增加一行
	nline = pMyClass->GetDlgItemInt(IDC_EDIT_Dcont);
	nline = nline + 1;
	pMyClass->SetDlgItemInt(IDC_EDIT_Dcont, nline, 1);

	if (len > 0)
	{
		//*********************************打印时间
		if (pMyClass->m_PRINTTIME.GetCheck())
		{
			SYSTEMTIME time;
			::GetLocalTime(&time);
			m_SD.Format(_T("%04d-%02d-%02d %02d:%02d:%02d:%03d->\t"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		}
		//*********************************转换为BYTE型数组
		for (k = 0; k < len; k++)
			fs.GetElement(&k, str + k); //转换为BYTE型数组

		if (pMyClass->m_Hex.GetCheck())
		{
			//*********************************十六进制转换成字符串--开始
			CString tem;
			CString tem1;
			for (int i = 0; i < len; i++)
			{
				tem.Format(_T("%02x"), str[i]);
				m_SD += tem;
			}
			//*********************************十六进制转换成字符串--结束
		}
		else
			m_SD += str; // 接收到编辑框里面

						 //自动换行
		if (pMyClass->m_CHECKRTN.GetCheck())
		{
			m_SD += '\r';
			m_SD += '\n';
		}
		//************************************************************窗口打印--开始
		//*************20161016	
		//*************获取行数

		CEdit*pedit = (CEdit*)pMyClass->GetDlgItem(IDC_EDIT_Rev);

		m_EDIT_Dcont.Format(_T("%05ld"), nline);	//数字转换为字符

		pedit->ShowCaret();							//hEdit是编辑框句柄 

		m_SD = m_EDIT_Dcont + ": " + m_SD;

		pedit->SetFocus();							//设定光标位置为第一行第一位
		pedit->SetSel(nline, -1, TRUE);				//将光标放置到最后一行起始位，从上往下
		pedit->SetSel(-1, -1);						//将光标放置到最后一行起始位，从上往下

		pedit->ReplaceSel(m_SD, true);				//插入显示数据


		

		//************************************************************保存到文件--开始
		if (bSave == true)
		{
			m_txt = m_SD;
			AfxBeginThread(DemoE, NULL);	//写入文本文件
		}
		else
		{
			//file.Close();  //关闭文件
		}
	}

		//************************************************************保存到文件--结束
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
//    Unicode 转 Ansi 字符串函数
//    入口参数：TCHAR*        (Unicode字符串指针)
//    返回数据：char*         (Ansi字符串指针)
/////////////////////////////////////////////////////////////////////////////////
char* UnicodeToAnsi(CString wstr)
{
	if (!wstr)
		return NULL;
	int strleng = ::WideCharToMultiByte(CP_ACP, NULL, wstr, wcslen(wstr), NULL, 0, NULL, FALSE);
	char* str = new char[strleng + 1];
	::WideCharToMultiByte(CP_ACP, NULL, wstr, wcslen(wstr), str, strleng, NULL, FALSE);
	str[strleng] = '\0';
	return str;
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


// CVS2010之MFC串口通信教程Dlg 对话框



CVS2010之MFC串口通信教程Dlg::CVS2010之MFC串口通信教程Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VS2010MFC_DIALOG, pParent)
	, m_EditReceive(_T(""))
	, m_EditSend(_T(""))
	, m_times(_T(""))
	, m_EDIT_Dcont(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVS2010之MFC串口通信教程Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Rev, m_EditReceive);
	DDX_Text(pDX, IDC_EDIT_Send, m_EditSend);
	DDX_Control(pDX, IDC_COMBO1, m_comb1);
	DDX_Control(pDX, IDC_COMBO2, m_comb2);
	DDX_Control(pDX, IDC_MSCOMM1, m_mscom);
	//  DDX_Check(pDX, IDC_CHECK1, 自动换行);
	//  DDX_Check(pDX, IDC_CHECK1, m_Check);
	DDX_Control(pDX, IDC_CRN, m_CHECKRTN);
	DDX_Control(pDX, IDC_PRINTTIME, m_PRINTTIME);
	//  DDX_Text(pDX, IDC_EDIT_Dcont, m_EDIT_Dcont);
	//  DDX_Text(pDX, IDC_EDIT_Rxcont, m_EDIT_Rxcont);
	DDX_Control(pDX, IDC_Hex, m_Hex);
	DDX_Control(pDX, IDC_SAVEF, m_SAVEF);
	DDX_Control(pDX, IDC_CHECKTS, m_CHECKTS);
	DDX_Text(pDX, IDC_EDIT1, m_times);
	DDX_Text(pDX, IDC_EDIT_Dcont, m_EDIT_Dcont);
}

BEGIN_MESSAGE_MAP(CVS2010之MFC串口通信教程Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CLEAN, &CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonClean)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_CHECK1, &CVS2010之MFC串口通信教程Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CRN, &CVS2010之MFC串口通信教程Dlg::OnBnClickedCrn)
	ON_BN_CLICKED(IDC_PRINTTIME, &CVS2010之MFC串口通信教程Dlg::OnBnClickedPrinttime)
	ON_BN_CLICKED(IDC_SAVEF, &CVS2010之MFC串口通信教程Dlg::OnBnClickedSavef)
	ON_BN_CLICKED(IDC_CHECKTS, &CVS2010之MFC串口通信教程Dlg::OnBnClickedCheck2)
	ON_EN_CHANGE(IDC_EDIT1, &CVS2010之MFC串口通信教程Dlg::OnEnChangeEdit1)

	ON_WM_TIMER()
	
	

END_MESSAGE_MAP()


// CVS2010之MFC串口通信教程Dlg 消息处理程序

BOOL CVS2010之MFC串口通信教程Dlg::OnInitDialog()			//初始化对话框程序
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

	//默认选中复选框

	UpdateData(true);

	//初始化显示框
	SetDlgItemInt(IDC_EDIT_Dcont, 0,1);
	SetDlgItemInt(IDC_EDIT_Rxcont, 0, 1);
	SetDlgItemInt(IDC_EDIT_Txcont, 0, 1);

	//自动换行
	CheckDlgButton(IDC_CRN, 1);				//默认选中复选框--自动换行
	//打印时间
	CheckDlgButton(IDC_PRINTTIME, 1);		//默认选中复选框--打印时间
	//Hex显示
	CheckDlgButton(IDC_Hex, 1);				//默认选中复选框--打印时间
	//保存数据
	CheckDlgButton(IDC_SAVEF, 1);			//默认选中复选框--保存数据

	UpdateData(false);

	// 串口选择组合框
	CString str;
	int i;
	for (i = 0; i<15; i++)
	{
		str.Format(_T("com %d"), i + 1);
		m_comb1.InsertString(i, str);
	}
	m_comb1.SetCurSel(0);//预置COM口
						 //波特率选择组合框
	CString str1[] = { _T("300"),_T("600"),_T("1200"),_T("2400"),_T("4800"),_T("9600"),
		_T("19200"),_T("38400"),_T("43000"),_T("56000"),_T("57600"),_T("115200"),_T("256000") };
	for (int i = 0; i<13; i++)
	{
		int judge_tf = m_comb2.AddString(str1[i]);
		if ((judge_tf == CB_ERR) || (judge_tf == CB_ERRSPACE))
			MessageBox(_T("build baud error!"));
	}
	//m_comb2.SetCurSel(5);//预置波特率为"9600"
	m_comb2.SetCurSel(11);//预置波特率为"256000"



	 //*********************************************创建文件---开始
	CString m_strFolderPath = _T("d:\\串口接收数据");
	// 判断路径是否存在 
	if (!PathIsDirectory(m_strFolderPath))
	{
		CString strMsg;
		strMsg.Format(_T("指定路径\"%s\"不存在，是否创建?"), m_strFolderPath);
		if (AfxMessageBox(strMsg, MB_YESNO) == IDYES)
		{
			if (!CreateDirectory(m_strFolderPath, NULL))
			{
				strMsg.Format(_T("创建路径\"%s\"失败！是否继续?"), m_strFolderPath);
				if (AfxMessageBox(strMsg, MB_YESNO) == IDYES)
					return 0;
			}
		}
	}
	//OnBnClickedSavef();			//判断保存数据选择状态及做相应的动作
	//CFile file;
	//file.Open(%%1, CFile::modeCreate | CFile::modeWrite);
	//以下一一种建立并写入TXT文件的方式  

	CFile file;
	CString filepath, filename, s;
	SYSTEMTIME time;
	::GetLocalTime(&time);
	s.Format(_T("%04d-%02d-%02d-%02d.txt"), time.wYear, time.wMonth, time.wDay, time.wHour);
	filepath = _T("d:\\串口接收数据\\"); //文件位置
	filename = s;  //文件名 
	filename = filepath + filename;  //文件路径 
	file.Open(filename, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);//建立文件 
	s = "";
	s.Format(_T("%04d-%02d-%02d-%02d-%02d-%02d\r\n"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
	int nLen = s.GetLength()*2; // 得到18而不是11
	file.SeekToEnd();
	file.Write(s, nLen);
	file.Close();  //关闭文件
	OnBnClickedSavef();			//判断保存数据选择状态及做相应的动作
	//*********************************************创建文件---结束

	//设置默认定时发送间隔时间
	//GetDlgItemInt(IDC_EDIT1);
	//SetDlgItemText(IDC_EDIT_Rxcont, m_EDIT_Rxcont);//不使用UpdateData(FALSE);的原因是该函数会刷新整个对话框的数据，而SetDlgItemText()只更新接收编辑框的数据。
	SetDlgItemInt(IDC_EDIT1,1000);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE

}

void CVS2010之MFC串口通信教程Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVS2010之MFC串口通信教程Dlg::OnPaint()
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
HCURSOR CVS2010之MFC串口通信教程Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonOpen()		//打开串口
{
	// TODO: 在此添加控件通知处理程序代码

	CString str, str1, n; //定义字符串
	GetDlgItemText(IDC_BUTTON_OPEN, str);
	CWnd *h1;
	h1 = GetDlgItem(IDC_BUTTON_OPEN); //指向控件的caption
	//m_CHECKRTN.GetCheck()
	//OnLbuttonDown();//

		if (!m_mscom.get_PortOpen())
		{
			m_comb2.GetLBText(m_comb2.GetCurSel(), str1);//取得所选的字符串，并存放在str1里面
			str1 = str1 + ',' + 'n' + ',' + '8' + ',' + '1'; //这句话很关键
			m_mscom.put_CommPort((m_comb1.GetCurSel() + 1)); //选择串口
			m_mscom.put_InputMode(1);		//设置输入方式为二进制方式
			m_mscom.put_Settings(str1);		//波特率为（波特率组Á合框）无校验，8数据位，1个停止位
			m_mscom.put_InputLen(2048);		//设置当前接收区数据长度为2048
			m_mscom.put_OutBufferSize(2048);		//设置当前接收区数据长度为1024
			m_mscom.put_RThreshold(1);		//缓冲区一个字符引发事件
			m_mscom.put_InputLen(2048);		//接收数据
//			m_mscom.put_CTSTimeout(1);


			m_mscom.put_RTSEnable(1);		//设置RT允许
			//配置其它参数
			//m_mscom.put_CTSHolding(0);		//设置RT允许
			m_mscom.put_DTREnable(1);		//设置RT允许
			m_mscom.put_RTSEnable(0);		//设置RT允许
			m_mscom.put_CDTimeout(0);		//设置RT允许

			m_mscom.put_PortOpen(true);		//打开串口
			if (m_mscom.get_PortOpen())
			{
				str = _T("关闭串口");
				UpdateData(true);
				h1->SetWindowText(str); //改变按钮名称为‘’关闭串口”
			}
			//bSave = true;			//保存文件标志
			//OnBnClickedSavef();
			//CheckDlgButton(IDC_SAVEF, 1);			//默认选中复选框--关闭保存数据
			if (m_SAVEF.GetCheck()&&(bSave == true))
			{
				bSave = true;			//保存文件标志
				//DemoD(NULL);		//打开和关闭文件
			}
			else if(m_SAVEF.GetCheck() && (bSave == false))
			{
				//bSave = false;			//保存文件标志
				//bSave = true;			//保存文件标志
				OnBnClickedSavef();
			}
			//DemoD(NULL);		//打开和关闭文件
			//OnBnClickedSavef();
		}
		else
		{
			m_mscom.put_PortOpen(false);
			if (str != _T("打开串口"))
			{
				str = _T("打开串口");
				UpdateData(true);
				h1->SetWindowText(str); //改变按钮名称为打开串口
				
				//bSave = false;			//保存文件标志
				//file.Close();			//关闭文件
				//保存数据
				//CheckDlgButton(IDC_SAVEF, 0);			//默认选中复选框--关闭保存数据
				//bSave = false;			//保存文件标志
				//DemoD(NULL);				//打开和关闭文件
				if (m_SAVEF.GetCheck() && (bSave == true))
				{
					bSave = false;			//保存文件标志
					DemoD(NULL);			//打开和关闭文件
					//OnBnClickedSavef();
				}
				else if (m_SAVEF.GetCheck() && (bSave == false))
				{
					//bSave = false;			//保存文件标志
					//bSave = true;			//保存文件标志
					//OnBnClickedSavef();
				}
				//file.Close();			//关闭文件
			}
			
		}

//		AfxBeginThread(DemoC, this);
}


void CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonSend()		//发送数据
{
	// TODO: 在此添加控件通知处理程序代码
	CString str = _T("");
	long	lenth = 0;

	UpdateData(true); //更新控件数据
	//*********************************获取字符串
	GetDlgItemText(IDC_EDIT_Send,str);
	//*********************************获取字符串长度
	//lenth = str.GetLength();				//获取字符串长度
	//lenth = (str.GetLength()) * sizeof(wchar_t);//获取字符串长度--无法区分双字节字符
	lenth = CStringA(str).GetLength();		//获取字符串长度
	lenth+=GetDlgItemInt(IDC_EDIT_Txcont);	//计算总发送字节数
	SetDlgItemInt(IDC_EDIT_Txcont, lenth);	//更新已发送总字节数

	//*********************************检查是否为HEX发送
	//if (m_CHECKTS.GetCheck())
	if (((CButton*)GetDlgItem(IDC_Hex_Send))->GetCheck())			//((CButton*)GetDlgItem(控件的ID))->GetCheck();	//IDC_Hex_Send
	{
		//char b1 = 0x0A, b2 = 02, b3 = 03;
		//CString sendstring;
		//m_EditSend = b1;
		//m_EditSend += b2;
		//m_EditSend += b3;
		//m_mscom.put_Output(COleVariant(m_EditSend));//把发送编辑框的数据发送出去

		//CString st = _T("");
		//for (int i=0;i<lenth/2;i++)
		//{
		//	char n = wcstol(m_EditSend, NULL, 16);
		//	st += n;
		//}
		//m_EditSend = st;
		//m_mscom.put_Output(COleVariant(m_EditSend));//把发送编辑框的数据发送出去


		CString strText(_T("5A 4C 18 00 00 00 3D 00"));
		strText = _T("0x") + strText;
		CString num;
		strText.Replace(_T(" "), _T(",0x"));
		char* buf = NULL;
#ifdef UNICODE
		int nLen = WideCharToMultiByte(CP_ACP, 0, strText, -1, buf, 0, NULL, NULL);
		buf = new char[nLen];
		memset(buf, 0, sizeof(char) * nLen);
		WideCharToMultiByte(CP_ACP, 0, strText, -1, buf, nLen, NULL, NULL);
		for (int i = 0; i < nLen; i++)
		{
			num += buf[i];
		}
#else
		int nLen = strText.GetLength() + 1;
		buf = new char[nLen];
		memset(buf, 0, sizeof(char*) * nLen);
		sprintf(buf, "%s", strText);
		for (int i = 0; i < nLen; i++)
		{
			num += buf[i];
		}
#endif
		// ...
		delete[] buf;
		buf = NULL;
		m_EditSend = num;
		m_mscom.put_Output(COleVariant(m_EditSend));//把发送编辑框的数据发送出去

		//CString st = _T("20");
		//int n = strtol(st, NULL, 16);

		//CString strText(_T("5A 4C 18 00 00 00 3D 00"));
		//strText = _T("0x") + strText;
		//strText.Replace(_T(" "), _T(",0x"));
		//char* buf = NULL;
		//#ifdef UNICODE
		//	int nLen = WideCharToMultiByte(CP_ACP, 0, strText, -1, buf, 0, NULL, NULL);
		//	buf = new char[nLen];
		//	memset(buf, 0, sizeof(char) * nLen);
		//	WideCharToMultiByte(CP_ACP, 0, strText, -1, buf, nLen, NULL, NULL);
		//#else
		//	int nLen = strText.GetLength() + 1;
		//	buf = new char[nLen];
		//	memset(buf, 0, sizeof(char*) * nLen);
		//	sprintf(buf, "%s", strText);
		//#endif
		//// ...
		//delete[] buf;
		//buf = NULL;

		//m_EditSend = strText;
		//m_mscom.put_Output(COleVariant(strText));//把发送编辑框的数据发送出去
	}
	else
	{
		//*********************************发送数据
		m_mscom.put_Output(COleVariant(m_EditSend));//把发送编辑框的数据发送出去
	}
	
}


void CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonClean()		//清除数据
{
	// TODO: 在此添加控件通知处理程序代码

	SetDlgItemInt(IDC_EDIT_Dcont, 0, 1);			//清除行计数
	SetDlgItemInt(IDC_EDIT_Rxcont, 0, 1);			//清除接收字节计数
	SetDlgItemInt(IDC_EDIT_Txcont, 0, 1);			//清除接发送节计数
	SetDlgItemText(IDC_EDIT_Rev, _T(""));			//清除接收框
	//m_EditReceive = _T(""); //给接收编辑框发送空格符
	//UpdateData(false); //更新数据
}


void CVS2010之MFC串口通信教程Dlg::OnBnClickedButtonClose()		//退出
{
	// TODO: 在此添加控件通知处理程序代码

	if (m_mscom.get_PortOpen())
		m_mscom.put_PortOpen(false);
	CDialogEx::OnCancel();
}
BEGIN_EVENTSINK_MAP(CVS2010之MFC串口通信教程Dlg, CDialogEx)
	ON_EVENT(CVS2010之MFC串口通信教程Dlg, IDC_MSCOMM1, 1, CVS2010之MFC串口通信教程Dlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void CVS2010之MFC串口通信教程Dlg::OnCommMscomm1()			//MSCOMM事件处理程序
{
	
	/*AfxBeginThread(DemoA, NULL);*/
	//接收处理数据
	if (m_mscom.get_CommEvent() == 2)
	{
		////SetDlgItemInt(IDC_EDIT_Txcont, 10, 1);
		//char str[2048] = { 0 };
		//long k;
		//long len;
		//CString m_SD = _T("");
		//
		////打印时间
		//if (m_PRINTTIME.GetCheck())
		//{
		//	SYSTEMTIME time;
		//	::GetLocalTime(&time);
		//	m_SD.Format(_T("%04d年%02d月%02d日%02d:%02d:%02d:%03d->\t"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		//}		

		//VARIANT InputData = m_mscom.get_Input(); //读缓冲区
		//COleSafeArray fs;
		//fs = InputData; //VARIANT型变À量转换为COleSafeArray型变量
		//len= fs.GetOneDimSize();
		//for (k = 0; k<len; k++)
		//	fs.GetElement(&k, str + k); //转换为BYTE型数组

		////自动换行
		//if (m_CHECKRTN.GetCheck())
		//{
		//	*(str + k) = '\t';
		//	*(str + k + 1) = '\n';
		//}

		//m_SD += str; // 接收到编辑框里面
		////SetTimer(1,1,NULL); //延时10ms

		////m_EditReceive.ReleaseBuffer();
		////UpdateData(false);

		//////滚动条处于最下方，如下的代码将实现这一功能1
		////CEdit*pedit = (CEdit*)GetDlgItem(IDC_EDIT_Rev);
		////unsigned long   nline = pedit->GetLimitText();
		////nline += m_SD.GetLength();
		////((CEdit*)GetDlgItem(IDC_EDIT_Rev))->SetLimitText(nline);

		////CEdit* pmyEdit;
		////pmyEdit = (CEdit*)GetDlgItem(IDC_EDIT_Rev);
		////pmyEdit->SetSel(-1, -1);
		////pmyEdit->ReplaceSel(m_SD, true);

		////滚动条处于最下方，如下的代码将实现这一功能2
		//CEdit*pedit = (CEdit*)GetDlgItem(IDC_EDIT_Rev);
		//unsigned long   nline = pedit->GetLimitText();
		//nline += m_SD.GetLength();
		//SetFocus();		//设定光标位置为第一行第一位
		//nline = pedit->GetLineCount();		//获取新行
		//pedit->SetSel(-1,1);				//将光标放置到最后一行起始位，从上往下
		//pedit->ReplaceSel(m_SD, true);		//插入显示数据


		////显示行计数
		//SetDlgItemInt(IDC_EDIT_Dcont, nline);

		////显示已接收字节数计数
		//CEdit* pEDIT_Rxcont = (CEdit*)GetDlgItem(IDC_EDIT_Rxcont);
		////unsigned long  m_Rxcont = pEDIT_Rxcont->GetLimitText();
		//unsigned long  m_Rxcont;

		//GetDlgItemText(IDC_EDIT_Rxcont, m_EDIT_Rxcont);
		////m_Rxcont = atol(m_EDIT_Rxcont.c);
		//m_Rxcont = _ttoi(m_EDIT_Rxcont);
		///*m_Rxcont=_tcstoul(m_EDIT_Rxcont);*/
		////(_ttoi)m_Rxcont.Formate((long)("%d"), m_EDIT_Rxcont);
		////if (nline <=1)
		////	m_Rxcont = 0;
		//m_Rxcont += len;
		//m_EDIT_Rxcont.Format(_T("%d"), m_Rxcont);
		////((CEdit*)GetDlgItem(IDC_EDIT_Rxcont))->SetLimitText(m_Rxcont);
		////SetDlgItemText(IDC_EDIT_Rxcont, m_EDIT_Rxcont);//不使用UpdateData(FALSE);的原因是该函数会刷新整个对话框的数据，而SetDlgItemText()只更新接收编辑框的数据。

		//if (m_SAVEF.GetCheck())
		//{
		//	bSave = true;
		//}
		//else
		//{
		//	bSave = false;
		//}

		//AfxBeginThread(DemoA, this);
		AfxBeginThread(Comm_Read, this);			//串口接收和显示线程
	}
	if (m_mscom.get_CommEvent() == 3)
	{
		
		//char str[2048] = { 0 };
		//long k;
		//long len;
		//CString m_SD = _T("");
		//
		////打印时间
		//if (m_PRINTTIME.GetCheck())
		//{
		//	SYSTEMTIME time;
		//	::GetLocalTime(&time);
		//	m_SD.Format(_T("%04d年%02d月%02d日%02d:%02d:%02d:%03d->\t"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		//}		

		//VARIANT InputData = m_mscom.get_Input(); //读缓冲区
		//COleSafeArray fs;
		//fs = InputData; //VARIANT型变À量转换为COleSafeArray型变量
		//len= fs.GetOneDimSize();
		//for (k = 0; k<len; k++)
		//	fs.GetElement(&k, str + k); //转换为BYTE型数组

		////自动换行
		//if (m_CHECKRTN.GetCheck())
		//{
		//	*(str + k) = '\t';
		//	*(str + k + 1) = '\n';
		//}

		//m_SD += str; // 接收到编辑框里面
		////SetTimer(1,1,NULL); //延时10ms

		////m_EditReceive.ReleaseBuffer();
		////UpdateData(false);

		//////滚动条处于最下方，如下的代码将实现这一功能1
		////CEdit*pedit = (CEdit*)GetDlgItem(IDC_EDIT_Rev);
		////unsigned long   nline = pedit->GetLimitText();
		////nline += m_SD.GetLength();
		////((CEdit*)GetDlgItem(IDC_EDIT_Rev))->SetLimitText(nline);

		////CEdit* pmyEdit;
		////pmyEdit = (CEdit*)GetDlgItem(IDC_EDIT_Rev);
		////pmyEdit->SetSel(-1, -1);
		////pmyEdit->ReplaceSel(m_SD, true);

		////滚动条处于最下方，如下的代码将实现这一功能2
		//CEdit*pedit = (CEdit*)GetDlgItem(IDC_EDIT_Rev);
		//unsigned long   nline = pedit->GetLimitText();
		//nline += m_SD.GetLength();
		//SetFocus();		//设定光标位置为第一行第一位
		//nline = pedit->GetLineCount();		//获取新行
		//pedit->SetSel(-1,1);				//将光标放置到最后一行起始位，从上往下
		//pedit->ReplaceSel(m_SD, true);		//插入显示数据


		////显示行计数
		///*CEdit* p_Cont;*/
		//m_EDIT_Dcont.Format(_T("%d"), nline);
		//SetDlgItemText(IDC_EDIT_Dcont, m_EDIT_Dcont);//不使用UpdateData(FALSE);的原因是该函数会刷新整个对话框的数据，而SetDlgItemText()只更新接收编辑框的数据。

		////显示已接收字节数计数
		//CEdit* pEDIT_Rxcont = (CEdit*)GetDlgItem(IDC_EDIT_Rxcont);
		////unsigned long  m_Rxcont = pEDIT_Rxcont->GetLimitText();
		//unsigned long  m_Rxcont;

		//GetDlgItemText(IDC_EDIT_Rxcont, m_EDIT_Rxcont);
		////m_Rxcont = atol(m_EDIT_Rxcont.c);
		//m_Rxcont = _ttoi(m_EDIT_Rxcont);
		///*m_Rxcont=_tcstoul(m_EDIT_Rxcont);*/
		////(_ttoi)m_Rxcont.Formate((long)("%d"), m_EDIT_Rxcont);
		////if (nline <=1)
		////	m_Rxcont = 0;
		//m_Rxcont += len;
		//m_EDIT_Rxcont.Format(_T("%d"), m_Rxcont);
		////((CEdit*)GetDlgItem(IDC_EDIT_Rxcont))->SetLimitText(m_Rxcont);
		////SetDlgItemText(IDC_EDIT_Rxcont, m_EDIT_Rxcont);//不使用UpdateData(FALSE);的原因是该函数会刷新整个对话框的数据，而SetDlgItemText()只更新接收编辑框的数据。

		//if (m_SAVEF.GetCheck())
		//{
		//	bSave = true;
		//}
		//else
		//{
		//	bSave = false;
		//}
		
		//AfxBeginThread(DemoA, this);
		AfxBeginThread(DemoC, this);			//串口接收和显示线程
	}
}


void CVS2010之MFC串口通信教程Dlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CVS2010之MFC串口通信教程Dlg::OnBnClickedCrn()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CVS2010之MFC串口通信教程Dlg::OnBnClickedPrinttime()
{
	// TODO: 在此添加控件通知处理程序代码
}




void CVS2010之MFC串口通信教程Dlg::OnBnClickedSavef()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_SAVEF.GetCheck()&&( bSave == false))
	{
		bSave = true;
		AfxBeginThread(DemoD, this);
	}
	else if((!m_SAVEF.GetCheck())&& (bSave == true))
	{
		bSave = false;
		AfxBeginThread(DemoD, this);
	}
	//AfxBeginThread(DemoD, this);

	//if (m_SAVEF.GetCheck())
	//{
	//	CString s;
	//	SYSTEMTIME time;
	//	::GetLocalTime(&time);
	//	filename = _T("d:\\串口接收数据\\"); //文件位置
	//	s.Format(_T("%04d-%02d-%02d-%02d.txt"), time.wYear, time.wMonth, time.wDay, time.wHour);
	//	filename += s;  //文件路径+文件名 
	//	if (file.Open(filename, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite))//建立文件 
	//	{
	//		Sleep(10);
	//		bSave = true;
	//	}

	//}
	//else if(bSave == true)
	//{
	//	file.Abort();	//终止文件操作
	//	file.Flush();
	//	file.Close();  //关闭文件
	//	bSave = false;
	//	Sleep(10);
	//	file.Close();  //关闭文件
	//}
	//CString s;
	//SYSTEMTIME time;
	//::GetLocalTime(&time);
	//filename = _T("d:\\串口接收数据\\"); //文件位置
	//s.Format(_T("%04d-%02d-%02d-%02d.txt"), time.wYear, time.wMonth, time.wDay, time.wHour);
	//filename += s;  //文件路径+文件名 
	//file.Open(filename, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);//建立文件 
	//file.Close();  //关闭文件
}





void CVS2010之MFC串口通信教程Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CVS2010之MFC串口通信教程Dlg * pMyClass = (CVS2010之MFC串口通信教程Dlg*)nIDEvent;
	static	UINT	mm = 0;
	static	UINT	ss = 0;
	static	UINT	mss = 0;
	CString	str;
	switch (nIDEvent)
	{
	case	1:
		UpdateData(true); //更新控件数据
		
			if (m_CHECKTS.GetCheck())
			{
				if (m_EditSend != "")
					//m_mscom.put_Output(COleVariant(m_EditSend));//把发送编辑框的数据发送出去
					OnBnClickedButtonSend();
			}
		
		break;

	}

	CDialogEx::OnTimer(nIDEvent);
}


void CVS2010之MFC串口通信教程Dlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT TIMES = 0;
	if (m_CHECKTS.GetCheck())
	{
		TIMES = GetDlgItemInt(IDC_EDIT1);
		//SetDlgItemInt(IDC_EDIT1, TIMES+1,1);
		
		if(TIMES>0)
			SetTimer(1, TIMES, NULL);		//定时器
		else
			KillTimer(1);
	}
	else
	{
		KillTimer(1);
	}
}


void CVS2010之MFC串口通信教程Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UINT TIMES = 0;
	if (m_CHECKTS.GetCheck())
	{
		TIMES = GetDlgItemInt(IDC_EDIT1);
		if (TIMES>0)
			SetTimer(1, TIMES, NULL);		//定时器
		else
			KillTimer(1);
	}
	else
	{
		KillTimer(1);
	}
}


