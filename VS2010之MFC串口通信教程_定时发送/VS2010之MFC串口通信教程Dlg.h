
// VS2010֮MFC����ͨ�Ž̳�Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"

UINT DemoA(LPVOID pParam);
UINT DemoC(LPVOID pParam);
UINT DemoD(LPVOID pParam);		//�򿪺͹ر��ļ�
UINT DemoE(LPVOID pParam);
char* UnicodeToAnsi(CString wstr);	//Unicode ת Ansi �ַ�������


// CVS2010֮MFC����ͨ�Ž̳�Dlg �Ի���
class CVS2010֮MFC����ͨ�Ž̳�Dlg : public CDialogEx
{
// ����
public:
	CVS2010֮MFC����ͨ�Ž̳�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VS2010MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
//	BOOL �Զ�����;
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
