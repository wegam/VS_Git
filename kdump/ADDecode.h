#pragma once
#include "stdafx.h"
#define DECODE_BUF_MAX_LEN 10240
#define DECODE_CMD_MAX_LEN 64
#include "ChartCtrl/ChartCtrl.h"
#include "ChartCtrl/ChartAxisLabel.h"  
#include "ChartCtrl/ChartLineSerie.h"
#include<vector>
typedef enum
{
	RET_OK,
	RET_LEN_OUT,
	RET_INVALID_PARA,
	RET_FAIL,
}t_ret;
typedef struct
{
	
	UINT Index ;//数据ID

	DWORD TickCount;//时间点
	UINT AdVal;//当前AD值
	int FirstDiffVal;//和第一次值的差值
	int AdjDiffVal;//相邻差值

}t_AD_Info;
typedef enum
{
	X_TIME,
	X_INDEX,

}t_SerieX;
typedef enum
{
	Y_ADJDIFFVAL,
	Y_ADVAL,
	Y_FIRSTDIFFVAL,

}t_SerieY;
typedef enum
{
	FIGURE_HEX,
	FIGURE_DECIMAL,


}t_Figure;
BOOL GbkToUnicode(LPSTR lpcszStr, int csLen, LPWSTR lpwszStr, int wsLen);
int UnicodeToGbk(LPWSTR lpwszStr, int wsLen, LPSTR lpcszStr, int csLen);
class ADDecode :public::CChartCtrl
{
	enum
	{
		Pack_HeadS,
		Pack_HeadE,
		Pack_Tail,

	};
public:
	ADDecode();
	~ADDecode();
	void SetSerieXY(t_SerieX x,t_SerieY y);
	void SetFigure(t_Figure Figure = FIGURE_HEX);

	t_ret CreatecRecordFile(CString FileName);
	void CloseRecordFile(void);
	t_ret SetFlgStr(char *pstr);
	void UnPacket(char *pBuf, DWORD nLength);
	void DecodeData(char *OneLineStr);
	int ChangeNum(char* str);
	void Init(void);
	void Clear(void);
	void ReStart(void);
	void RefreshUi(void);
	int GetAdjMaxDiffVal(void);
	int GetAdjMinDiffVal(void);
	t_AD_Info * GetADInfo(void);
	LPCTSTR GetLastStr(void);
protected:
	t_Figure m_Figure;
	t_SerieX m_SerieX;
	t_SerieY m_SerieY;
	CFile*	m_pFile ;
	char	m_PackBuffer[DECODE_BUF_MAX_LEN];
	char m_FlgStr[DECODE_CMD_MAX_LEN];
	int  m_CmdPos ;
	char	DisBuffer[DECODE_BUF_MAX_LEN];
	CString m_FileName;
	UINT m_FlgStrLen;
	UINT m_StrVal ;
	UINT m_LastVal ;
	t_AD_Info m_Info;
	 UINT m_CmdLength;
	 int m_MinDiffVal;
	 int m_MaxDiffVal;
	 UINT m_nUnPackStatus = Pack_HeadS;
	 std::vector<t_AD_Info>m_AdInfo;
	 DWORD m_StartTick;
	 CString m_DisValStr;
};

