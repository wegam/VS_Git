
// VS2010֮MFC����ͨ�Ž̳�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVS2010֮MFC����ͨ�Ž̳�App: 
// �йش����ʵ�֣������ VS2010֮MFC����ͨ�Ž̳�.cpp
//

class CVS2010֮MFC����ͨ�Ž̳�App : public CWinApp
{
public:
	CVS2010֮MFC����ͨ�Ž̳�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVS2010֮MFC����ͨ�Ž̳�App theApp;