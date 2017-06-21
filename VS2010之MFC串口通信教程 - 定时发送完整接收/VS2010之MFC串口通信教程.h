
// VS2010之MFC串口通信教程.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CVS2010之MFC串口通信教程App: 
// 有关此类的实现，请参阅 VS2010之MFC串口通信教程.cpp
//

class CVS2010之MFC串口通信教程App : public CWinApp
{
public:
	CVS2010之MFC串口通信教程App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CVS2010之MFC串口通信教程App theApp;