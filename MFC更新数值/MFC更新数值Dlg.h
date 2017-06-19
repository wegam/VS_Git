
// MFC更新数值Dlg.h : 头文件
//

#pragma once


// CMFC更新数值Dlg 对话框
class CMFC更新数值Dlg : public CDialogEx
{
// 构造
public:
	CMFC更新数值Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DIALOG };
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
public:
	long m_Num;
	afx_msg void OnBnClickedButton1();
};
