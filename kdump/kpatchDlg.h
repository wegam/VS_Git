// kpatchDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "SerialMFC.h"
typedef unsigned int u32;
typedef unsigned char u8;
/************************************************************************/
/*                                                                      */
/************************************************************************/

#include "ADDecode.h"
//e:\code\kdump\ChartCtrl\ChartLineSerie.h
//#include "ChartCtrl/ChartString.h"
enum
{
	E_BAUD_RATE_COUNT = 3,
	E_BAUD_RATE_DATA_SIZE = 3,

	E_DEFAULT_BAUD_RATE_IDX = 2,//460800
	E_MSG_BUFFER_SIZE = 512,
	E_SHOW_DATA_LEN = 16,
	E_SHOW_DATA_BUFFER = E_SHOW_DATA_LEN << 2,
	E_TEMP_RECV_BUF_SIZE = 16384,
	E_BUFFER_SIZE =E_TEMP_RECV_BUF_SIZE,
	E_TIMER_ID=1,
};

const BYTE a_SpeedParameters[E_BAUD_RATE_COUNT][E_BAUD_RATE_DATA_SIZE] =
{
	/* speed configuration for Uart0 */
	{ 0x00, 0xFF, 0xF9 },	/*  0*/
	{ 0x60, 0xFF, 0xFD },	/*  1*/
	{ 0xB0, 0xFF, 0xFF },	/*  2*/
};

const DWORD a_PCSpeedValue[E_BAUD_RATE_COUNT]= 
{
	115200,	/*  0 */
	230400,	/*  1 */
	460800,	/*  2 */
};
#define TABLE_UPDATE_TIMER 2
#define TABLE_UPDATE_TIMEOUT 573
// CkpatchDlg dialog
class CkpatchDlg : public CDialog
{
// Construction
public:
	CkpatchDlg(CWnd* pParent = NULL);	// standard constructor
	~CkpatchDlg()
	{
		if( m_pFile!=NULL)
		{

			if (m_pFile->GetLength()==0){
				CString tmp;
				tmp = m_pFile->GetFilePath();
				m_pFile->Close();
				DeleteFile(tmp);
			}
			else
			{
				m_pFile->Close();
			}
			delete m_pFile;
		}
	}
// Dialog Data
	enum { IDD = IDD_KPATCH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

public:
	void  UpdateFilterPara(void);
	void SetFlgstr(void);
	ADDecode m_ChartCtrl1;
	ADDecode m_ChartCtrl2;
	CComboBox m_cmbCom;
	CComboBox m_cmbBaud;
	CSerialMFC m_serial;
	CString m_strFn;
	CFile*	m_pFile;
	u32		m_ReceivedCount;
	UINT	m_nTimerID;
	void InitTable(void);
	void Init();
	BOOL IsInputValid();
	afx_msg LRESULT OnSerialMsg (WPARAM wParam, LPARAM lParam);
protected:
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void OnOK();
	void EnableUI(BOOL bOp=TRUE);
public:
	afx_msg void OnCbnDropdownComboCom();
public:
	afx_msg void OnBnClickedButtonBrw();
public:
	afx_msg void OnBnClickedButtonStart();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedUpdateXy();
	afx_msg void OnBnClickedLogDecode();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedResetDis();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedFilter();
};
