// kpatch.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "kpatch.h"
#include "kpatchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkpatchApp

BEGIN_MESSAGE_MAP(CkpatchApp, CWinApp)
	ON_COMMAND(ID_HELP, Dummy)
END_MESSAGE_MAP()


// CkpatchApp construction

CkpatchApp::CkpatchApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CkpatchApp object

CkpatchApp theApp;

typedef unsigned char u8;
typedef unsigned short u16;
//359569 00 000014 2
// hee2_18ComputeCheckDigit((u8*)&s_hee_ImeiParam.v_hee_CheckDigit,
// 						 (u8*)&s_hee_ImeiParam.v_hee_CryptedIMEI);
// 
// s_hee_ImeiParam.v_hee_CheckDigit = (s_hee_ImeiParam.v_hee_CheckDigit << 4) | 0x0F;
// s_hee_ImeiParam.v_hee_CryptedIMEI[7] = s_hee_ImeiParam.v_hee_CheckDigit ; 
////359569 00 000014 2
// u8 al_IMEI[8] ={0x35,0x95,0x69,0x00,0x00,0x00,0x14,0x00};
// u8 vl_Chk;
// hee2_18ComputeCheckDigit(&vl_Chk,al_IMEI); // vl_Chk = 0x02

void hee2_18ComputeCheckDigit( u8 *vp_CheckDigit, u8 *a_IMEI)
{
	u8   al_Value[21];
	u8   al_IMEI[8];
	u8   al_IMEIDoubleDigit[14];
	u16  vl_SumDigit = 0;
	u8   i,j;

	/*  IMEI                                                  */
	/*  |    TAC        |     FAC    |       SNR            | */
	/*  | D14 .....  D9 | D8 .....D7 | D6 ...............D1 | */

	al_IMEI[0] = 0;

	/* what happens when i becomes equal to 1 ? .... */

	for (i = 8, j = 1 ; i > 0 ; i-- , j++)
	{
		al_IMEI[j] = a_IMEI[i-2];
	}

	for (i=1,j=0;i<8;i++,j++)
	{
		/*Double the value of the odd labelled digits D1,D3,...D13*/

		al_IMEIDoubleDigit[i-1] = (al_IMEI[i] & 0x0F)<<1;

		al_IMEIDoubleDigit[i-1] = ((al_IMEIDoubleDigit[i-1] / 10)<<4) + (al_IMEIDoubleDigit[i-1] % 10); 

		/* make into al_value all the digit (D1,D2,D3....D14)     */
		/* al_value[0] = D1                                       */
		/* al_value[1] = D2                                       */
		/* ................                                       */
		/* al_value[13] = D14                                     */

		al_Value[j++] = al_IMEIDoubleDigit[i-1] & 0x0F;
		al_Value[j++] = al_IMEIDoubleDigit[i-1] >> 4;
		al_Value[j]   = (al_IMEI[i] & 0xF0)>>4;
	}

	/*add the all digit D1+D1+D3....+D14           */

	for (i=0;i<21;i++)
	{
		vl_SumDigit += al_Value[i];
	}

	/*Turns vl_SumDigit number into a a BCD number */

	if (vl_SumDigit/100)
	{
		vl_SumDigit = ((vl_SumDigit/100)<<8) + 
			(( (vl_SumDigit & 0x9B) / 10)<<4) + 
			((vl_SumDigit & 0x9B) % 10);
	}
	else
	{
		vl_SumDigit = ((vl_SumDigit / 10)<<4) + (vl_SumDigit % 10);
	}

	/* computes the check digit  CD                  */
	/* CD = 10 - odd digit of the vl_SumDigit number */

	if((vl_SumDigit & 0x000F) == 0)
	{
		*vp_CheckDigit = 0x00;
	}
	else
	{
		*vp_CheckDigit = 0x0a - (vl_SumDigit & 0x000F);
	}
}

// CkpatchApp initialization

BOOL CkpatchApp::InitInstance()
{
	////359569 00 000014 2
	//u8 al_IMEI[8] ={0x35,0x95,0x69,0x00,0x00,0x00,0x14,0x00};
//	u8 vl_Chk;
//	hee2_18ComputeCheckDigit(&vl_Chk,al_IMEI);

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("CellonKPatch"));

	CkpatchDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

