#ifndef _CDATETIME_H
#define _CDATETIME_H

#include"stdafx.h"

typedef struct CDateTime
{
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_minute;
	int m_second;
}CDateTime;



/////////////////////////////////////////
void InitDateTime(CDateTime *dt);
void GetNowDateTime(CDateTime *dt);
void ShowDateTime(CDateTime *dt);
bool IsLeapYear(int year);
int GetDayByYM(int year,int month);
int GetWeekByYMD(int year,int month,int day);
CDateTime GetNextDateTime(CDateTime *pt,int n);
CDateTime GetLastDateTime(CDateTime *pt,int n);
int GetDateNum(CDateTime *dt,CDateTime *pt);
int GetDateNumByYMD(int year,int month,int day);
int GetDayByYear(int year);

#endif