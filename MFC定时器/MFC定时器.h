
// MFC��ʱ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC��ʱ��App: 
// �йش����ʵ�֣������ MFC��ʱ��.cpp
//

class CMFC��ʱ��App : public CWinApp
{
public:
	CMFC��ʱ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC��ʱ��App theApp;