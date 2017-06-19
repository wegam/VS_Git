
// VS2010之MFC串口通信教程Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"

UINT DemoA(LPVOID pParam);
UINT DemoC(LPVOID pParam);
UINT DemoD(LPVOID pParam);		//打开和关闭文件
UINT DemoE(LPVOID pParam);
char* UnicodeToAnsi(CString wstr);	//Unicode 转 Ansi 字符串函数


// CVS2010之MFC串口通信教程Dlg 对话框
class CVS2010之MFC串口通信教程Dlg : public CDialogEx
{
// 构造
public:
	CVS2010之MFC串口通信教程Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VS2010MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_EditReceive;
	CString m_EditSend;
	CComboBox m_comb1;
	CComboBox m_comb2;
public:
	CMscomm1 m_mscom;
	CButton m_CHECKRTN;
	CButton m_Hex;
	CButton m_PRINTTIME;
	CString m_EDIT_Dcont;
	CString m_EDIT_Rxcont;
	CButton m_SAVEF;

	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonClean();
	afx_msg void OnBnClickedButtonClose();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	UINT DemoB(LPVOID pParam);
	//afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck1();
//	BOOL 自动换行;
//	int m_Check;
//public:

	afx_msg void OnBnClickedCrn();
	afx_msg void OnBnClickedPrinttime();
	
	
	afx_msg void OnBnClickedSavef();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCheck2();
	CButton m_CHECKTS;
	CString m_times;
	afx_msg void OnEnChangeEdit1();
};
