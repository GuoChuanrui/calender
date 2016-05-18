#include"stdafx.h"

//��ʼ������ʱ��
void InitDateTime(CDateTime *dt)
{
	dt->m_year = 1;
	dt->m_month = 1;
	dt->m_day = 1;
	dt->m_hour = 0;
	dt->m_minute = 0;
	dt->m_second = 0;
}


//��ȡ��ǰ����ʱ��
void GetNowDateTime(CDateTime *dt)
{
	time_t te;
	time(&te);
	tm *ptm = localtime(&te);
	dt->m_year = ptm->tm_year+1900;
	dt->m_month = ptm->tm_mon+1;
	dt->m_day = ptm->tm_mday;
	dt->m_hour = ptm->tm_hour;
	dt->m_minute = ptm->tm_min;
	dt->m_second = ptm->tm_sec;
}


//��ʾ����ʱ��
void ShowDateTime(CDateTime *dt)
{
	printf("%d��%d��%d��\n",dt->m_year,dt->m_month,dt->m_day);
	printf("%dʱ%d��%d��\n",dt->m_hour,dt->m_minute,dt->m_second);
}


//�ж��Ƿ�����
bool IsLeapYear(int year)
{
	if(((year%4==0)&&(year%100!=0))||year%400==0)
		return true;
	return false;
}

//������ݷ���һ�������
int GetDayByYear(int year)
{
	if(IsLeapYear(year))
		return 366;
	else 
		return 365;
}
//�������·��ص�������
int GetDayByYM(int year,int month)
{
	int mday[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
	if(month==2)
	{
		if(IsLeapYear(year))
			month=0;
	}
	return mday[month];
}

//���������շ�������һ��ĵڼ���
int GetDateNumByYMD(int year,int month,int day)
{
	int D=0;//��һ������һ���еĵڼ���
	for(int i=1;i<month;i++)
	{
		D+=GetDayByYM(year,i);
	}
	D+=day;
	return D;
}

//���������շ�������
int GetWeekByYMD(int year,int month,int day)
{
	int D=GetDateNumByYMD(year,month,day);//��һ������һ���еĵڼ���
	int week=(year-1)+(year-1)/4-(year-1)/100+(year-1)/400+D;
	return week%7;
}


//�õ�n��������
CDateTime GetNextDateTime(CDateTime *pt,int n)
{
	CDateTime dt;
	InitDateTime(&dt);
	dt=*pt;
	int mday=GetDayByYM(dt.m_year,dt.m_month);
	while((dt.m_day+n)>mday)
	{
		dt.m_month++;
		if(dt.m_month>12)
		{
			dt.m_year++;
			dt.m_month=1;
		}
		n-=mday;
		mday=GetDayByYM(dt.m_year,dt.m_month);
	}
	dt.m_day+=n;  
	return dt;
}


//�õ�n��ǰ������
CDateTime GetLastDateTime(CDateTime *pt,int n)
{
	CDateTime dt;
	InitDateTime(&dt);
	dt=*pt;
	int mday=GetDayByYM(dt.m_year,dt.m_month-1);
	while((dt.m_day-n)<0)
	{
		dt.m_month--;
		if(dt.m_month<1)
		{
			dt.m_year--;
			dt.m_month=12;
		}
		n-=mday;
		mday=GetDayByYM(dt.m_year,dt.m_month-1);
	}
	dt.m_day-=n;  
	return dt;
}

//�õ�ĳ�վ��뵱ǰ���ڵ�����
int GetDateNum(CDateTime *dt,CDateTime *pt)
{
	int num=0;
	if(dt->m_year==pt->m_year)    //�����ͬ�꣬�������Ǳ���ĵڼ����������ȡ����ֵ
	{
		num=abs(GetDateNumByYMD(dt->m_year,dt->m_month,dt->m_day)-GetDateNumByYMD(pt->m_year,pt->m_month,pt->m_day));   
	}
	else if(dt->m_year>pt->m_year) //�����ǰ���ڴ�  
	{  
		num=GetDateNumByYMD(dt->m_year,dt->m_month,dt->m_day)+GetDayByYear(pt->m_year)-GetDateNumByYMD(pt->m_year,pt->m_month,pt->m_day);
		while(++pt->m_year<dt->m_year)
		{
			num+=GetDayByYear(pt->m_year);
		}
	}
	else if(dt->m_year<pt->m_year)  //�����ǰ����С
	{
		num=GetDayByYear(dt->m_year)-GetDateNumByYMD(dt->m_year,dt->m_month,dt->m_day)+GetDateNumByYMD(pt->m_year,pt->m_month,pt->m_day);
		while(++dt->m_year<pt->m_year)
		{
			num+=GetDayByYear(dt->m_year);  
		}
	}
	else
	{
		return 0;
	}
	return num;	
}