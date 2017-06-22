#include "stdafx.h"
#include "ADDecode.h"


ADDecode::ADDecode()
{
	m_pFile = NULL;
	memset(m_PackBuffer, 0x0, DECODE_BUF_MAX_LEN);
	memset(m_FlgStr, 0x0, DECODE_CMD_MAX_LEN);

	m_FlgStrLen = 0;
	m_CmdPos = 0;
	m_StrVal = 0;
	m_LastVal = 0;
	m_DisValStr.Empty();
	m_Info.Index = 0;
	m_MaxDiffVal = 0;
	m_Info.AdjDiffVal = 0;
	m_MinDiffVal = 0;
	m_SerieX = X_TIME;
	m_SerieY = Y_ADJDIFFVAL;
	m_Figure = FIGURE_HEX;
}
void ADDecode::Init(void)
{
	CChartAxis *pAxis = NULL;

	Clear();
	pAxis = CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
}
LPCTSTR ADDecode::GetLastStr(void)
{
	return m_DisValStr;
}
void ADDecode::Clear(void)
{
	if (m_pFile != NULL)
	{

		if (m_pFile->GetLength()==0){
			CString tmp;
			tmp = m_pFile->GetFilePath() ;
			m_pFile->Close();
			DeleteFile(tmp);
		}
		else
		{
			m_pFile->Close();
		}
		delete m_pFile;
		m_pFile = NULL;
	}
	memset(m_PackBuffer, 0x0, DECODE_BUF_MAX_LEN);
	memset(m_FlgStr, 0x0, DECODE_CMD_MAX_LEN);

	m_FlgStrLen = 0;
	m_CmdPos = 0;
	m_StrVal = 0;
	m_LastVal = 0;
	m_DisValStr.Empty();
	m_Info.Index = 0;
	m_MaxDiffVal = 0;
	m_Info.AdjDiffVal = 0;
	m_MinDiffVal = 0;
	m_AdInfo.clear();
	RemoveAllSeries();
}
void ADDecode::ReStart(void)
{
	
	m_CmdPos = 0;
	m_StrVal = 0;
	m_LastVal = 0;
	m_DisValStr.Empty();
	m_Info.Index = 0;
	m_MaxDiffVal = 0;
	m_Info.AdjDiffVal = 0;
	m_MinDiffVal = 0;
	m_AdInfo.clear();
	RemoveAllSeries();
}

ADDecode::~ADDecode()
{
	
	Clear();
}
void ADDecode::SetSerieXY(t_SerieX x, t_SerieY y)
{
	m_SerieX = x;
	m_SerieY = y;
}
void ADDecode::SetFigure(t_Figure Figure)
{
	m_Figure = Figure;

}

t_ret ADDecode::CreatecRecordFile(CString FileName)
{
	
	CloseRecordFile();

	m_pFile = new CFile(FileName, CFile::modeWrite | CFile::modeCreate);
	if (m_pFile != NULL)
	{
		//m_pFile->archive
		return RET_OK;
	}
	return RET_FAIL;
		
}
 t_ret ADDecode::SetFlgStr(char *pstr)
{
	 m_FlgStrLen = strlen(pstr);
	 if (m_FlgStrLen< DECODE_CMD_MAX_LEN)
	 {
		 memset(m_FlgStr, 0x0, DECODE_CMD_MAX_LEN);
		 strcpy_s(m_FlgStr, DECODE_CMD_MAX_LEN, pstr);
		 return RET_OK;
	 }
	 m_FlgStrLen = 0;
	 return RET_OK;
}
void ADDecode::CloseRecordFile(void)
{
	if (m_pFile != NULL)
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
		m_pFile = NULL;
	}
	//m_AdInfo.clear();
}
int ADDecode::ChangeNum(char* str)
{
#define MAX_NO_STR_LEN  16
	char  revstr[MAX_NO_STR_LEN + 1] = { 0 };  //根据十六进制字符串的长度，这里注意数组不要越界
	int   num[MAX_NO_STR_LEN + 1] = { 0 };
	int   count = 1;
	int   result = 0;
	int length = strlen(str);
	if (MAX_NO_STR_LEN <= length)
	{
		str[MAX_NO_STR_LEN - 1] = 0;
		length = MAX_NO_STR_LEN ;
	}
		strcpy_s(revstr, MAX_NO_STR_LEN, str);
		if (m_Figure == FIGURE_DECIMAL)
		{
			result = atoi(revstr);

		}
		else{
			for (int i = length - 1; i >= 0; i--)
			{
				if (count < 0)
				{
					count = 1;
				}
				if ((revstr[i] >= '0') && (revstr[i] <= '9'))
					num[i] = revstr[i] - 48;//字符0的ASCII值为48
				else if ((revstr[i] >= 'a') && (revstr[i] <= 'f'))
					num[i] = revstr[i] - 'a' + 10;
				else if ((revstr[i] >= 'A') && (revstr[i] <= 'F'))
					num[i] = revstr[i] - 'A' + 10;
				else{
					num[i] = 0;
					count = -1;
					result = 0;
				}

				result = result + num[i] * count;
				count = count * 16;//十六进制    
			}
		}
	return result;
}
t_AD_Info * ADDecode::GetADInfo(void)
{
	return (&m_Info);
}
int ADDecode::GetAdjMaxDiffVal(void)
{
	return (m_MaxDiffVal);
}
int ADDecode::GetAdjMinDiffVal(void)
{
	return (m_MinDiffVal);
}
BOOL GbkToUnicode(LPSTR lpcszStr, int csLen, LPWSTR lpwszStr, int wsLen)
{
	int nSize = ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpcszStr, -1, NULL, 0);
	if (wsLen < nSize)
	{
		nSize = wsLen - 1;
	}
	::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpcszStr, csLen, lpwszStr, nSize);
	return TRUE;
}
int UnicodeToGbk(LPWSTR lpwszStr, int wsLen, LPSTR lpcszStr, int csLen)
{
	int nSzie;
	nSzie = WideCharToMultiByte(CP_OEMCP, NULL, lpwszStr, wsLen, NULL, 0, NULL, FALSE);
	if (csLen < nSzie)
	{
		return 0;
	}
	return WideCharToMultiByte(CP_OEMCP, NULL, lpwszStr, wsLen, lpcszStr, csLen, NULL, FALSE);

}

void ADDecode::DecodeData(char *OneLineStr)
{
	//CChartLineSerie *pLineSerie;
#define  VAL_STR_MAX_LEN 1024
	char m_ValStr[VAL_STR_MAX_LEN + 1];
	
	UINT val = ChangeNum((char*)&OneLineStr[m_FlgStrLen]);

	if (val == 0)
	{
		return;
	}
	//EnableRefresh(false);
	
 
	//pLineSerie = CreateLineSerie();
	//pLineSerie->SetSeriesOrdering(poNoOrdering);//设置为无序  
	//pLineSerie->AddPoint(m_Info.Index, m_Info.AdjDiffVal
	m_Info.AdVal = val;
	m_Info.Index++;
	if (m_Info.Index == 1)
	{
		m_StrVal = val;
		m_LastVal = val;
		m_StartTick=GetTickCount();
	}
	m_Info.TickCount = GetTickCount() - m_StartTick;
	memset(m_ValStr, 0x0, VAL_STR_MAX_LEN + 1);
	m_Info.FirstDiffVal = (val - m_StrVal);

	if (m_MaxDiffVal < m_Info.FirstDiffVal)
	{
		m_MaxDiffVal = m_Info.FirstDiffVal;
	}
	if (m_MinDiffVal > m_Info.FirstDiffVal)
	{
		m_MinDiffVal = m_Info.FirstDiffVal;
	}
	m_Info.AdjDiffVal = val - m_LastVal;
	m_LastVal = val;
	int len = sprintf_s(m_ValStr, VAL_STR_MAX_LEN, "%s,%05d,%08d,%d,%d,%d\r\n", OneLineStr, m_Info.Index, m_Info.TickCount, m_Info.AdVal, m_Info.FirstDiffVal, m_Info.AdjDiffVal);
	len = len + 1;
	GbkToUnicode(m_ValStr, len, m_DisValStr.GetBuffer(len), len);
	m_DisValStr.GetBuffer(len)[len] = 0;
	m_DisValStr.ReleaseBuffer();


	

	//pLineSerie->AddPoint(m_Info.Index, m_Info.AdjDiffVal);
	
	//EnableRefresh(true);
	m_AdInfo.push_back(m_Info);
	if (NULL != m_pFile)
	{
		m_pFile->Write(m_ValStr, strlen(m_ValStr));
	}
	



}
void ADDecode::RefreshUi(void)
{
	//if (GetSeriesCount() > 2)
	{

		CChartLineSerie *pLineSerie;
		EnableRefresh(false);
		
	    RemoveAllSeries();
		
#if 1
		pLineSerie = CreateLineSerie();
		pLineSerie->SetSeriesOrdering(poNoOrdering);//设置为无序  

		std::vector<t_AD_Info>::iterator it = m_AdInfo.begin();
		double X,  Y;
		for (it; it != m_AdInfo.end(); it++)
		{
			if (m_SerieX == X_TIME)
			{
				X = it->TickCount;
			}
			else
			{
				X = it->Index;
			}

			if (m_SerieY == Y_ADJDIFFVAL)
			{
				Y = it->AdjDiffVal;
			}
			else if (m_SerieY == Y_ADVAL)
			{
				Y = it->AdVal;
			}
			else if (m_SerieY == Y_FIRSTDIFFVAL)
			{
				Y = it->FirstDiffVal;
			}
			pLineSerie->AddPoint(X, Y);
			//pLineSerie->AddPoint(it->Index, it->AdjDiffVal);
			
		}
#else
		pLineSerie = CreateLineSerie();
		pLineSerie->SetSeriesOrdering(poNoOrdering);//设置为无序  

		std::vector<t_AD_Info>::iterator it = m_AdInfo.begin();
		double X, Y;
		for (it; it != m_AdInfo.end(); it++)
		{
			if (m_SerieX == X_TIME)
			{
				X = it->TickCount;
			}
			else
			{
				X = it->Index;
			}

		
				Y = it->AdjDiffVal;
			
			pLineSerie->AddPoint(X, Y);
			//pLineSerie->AddPoint(it->Index, it->AdjDiffVal);

		}
		pLineSerie = CreateLineSerie();
		pLineSerie->SetSeriesOrdering(poNoOrdering);//设置为无序  

		it = m_AdInfo.begin();
		
		for (it; it != m_AdInfo.end(); it++)
		{
			if (m_SerieX == X_TIME)
			{
				X = it->TickCount;
			}
			else
			{
				X = it->Index;
			}

		
				Y = it->FirstDiffVal;
			pLineSerie->AddPoint(X, Y);

		}
#endif

		EnableRefresh(true);
	}
}
void ADDecode::UnPacket(char *pBuf, DWORD nLength)
{
#define CARRIAGE_RETURN 0x0D
#define LINE_FEED       0x0A



	UINT i = 0;


	for (i = 0; i<nLength; i++)
	{
		switch (m_nUnPackStatus)
		{
		case Pack_HeadS:
			m_CmdLength = 0;
			m_CmdPos = 0;
			if (m_FlgStr[m_CmdPos++] == pBuf[i])
			{
				m_PackBuffer[m_CmdLength++] = pBuf[i];
				m_nUnPackStatus = Pack_HeadE;
			}

			break;
		case Pack_HeadE:
			if (m_FlgStr[m_CmdPos++] == pBuf[i])
			{
				m_PackBuffer[m_CmdLength++] = pBuf[i];
				if (m_CmdPos == m_FlgStrLen)
				{
					m_nUnPackStatus = Pack_Tail;
				}
			}
			else
			{
				m_nUnPackStatus = Pack_HeadS;
			}


			break;
		case Pack_Tail:
		{
						  if (m_CmdLength > DECODE_BUF_MAX_LEN)
						  {
							  m_nUnPackStatus = Pack_HeadS;
							  break;
						  }
						  m_PackBuffer[m_CmdLength] = pBuf[i];


						  if ((m_PackBuffer[m_CmdLength] == LINE_FEED)
							  && (m_PackBuffer[m_CmdLength - 1] == CARRIAGE_RETURN)

							  )
						  {
							  m_PackBuffer[m_CmdLength - 1] = 0;
							  DecodeData(m_PackBuffer);
							  m_nUnPackStatus = Pack_HeadS;


						  }

						  m_CmdLength++;
		}
			break;
		}

	}

}