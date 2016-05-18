#include"stdafx.h"

//日历显示
void CalShow(CDateTime *dt)
{
	int select=1;
	while(select)
	{
		system("CLS");
		printf("******************************************\n");
		printf("* [1] 显示当前日期      [2] 显示当前时间 *\n");
		printf("* [3] 显示日期时间      [4] 动态时间显示 *\n");
		printf("* [5] 显示本月日历表    [0] 返回主菜单   *\n");
		printf("******************************************\n");
		printf("请选择:> ");
		scanf("%d",&select);
		system("CLS");
		GetNowDateTime(dt);
		switch(select)
		{
			
		case 1:
			ShowDate(dt);
			break;//显示当前日期
		case 2:		
			ShowTime(dt);
			break;//显示当前时间
		case 3:
			GetNowDateTime(dt);
			ShowDateTime(dt);
			break;//显示日期时间
		case 4:
			DShowTime(dt);
			break;//动态时间显示
		case 5:
			ShowNowCal(dt);
			break;//显示本月日历表
		case 0:
			main();
			break;//返回主菜单
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
		system("pause");
	}
}

//显示日期
void ShowDate(CDateTime *dt)
{
	printf("%d年%d月%d日\n",dt->m_year,dt->m_month,dt->m_day);
}

//显示时间
void ShowTime(CDateTime *dt)
{
	printf("%d时%d分%d秒\n",dt->m_hour,dt->m_minute,dt->m_second);
}


//动态显示时间
void DShowTime(CDateTime *dt)
{
	system("CLS");
	while(1)
	{
		if(_kbhit())
			break;
		GetNowDateTime(dt);
		ShowTime(dt);
		Sleep(1000);
		system("CLS");
	}			
}

//给定年月日显示本月日历表
void ShowCal(int year,int month,int day)
{ 
	printf("\t  %d 年 %d 月 %d 日\n",year,month,day);
	printf("=======================================\n");
	char *Title[]={"日","一","二","三","四","五","六"};
	for(int i=0;i<7;i++)
	{
		printf("%-6s",Title[i]);
	}
	printf("\n");
	int week=GetWeekByYMD(year,month,1);
	for(i=0;i<week;i++)
	{
		printf("%-6c",' ');
	}
	int mday=GetDayByYM(year,month);
	for(i=1;i<=mday;i++)
	{
		printf("%-6d",i);
		if((i+week)%7==0)
			printf("\n");
	}
	printf("\n");
	printf("=======================================\n");
}

//显示本月日历表
void ShowNowCal(CDateTime *dt)
{
	ShowCal(dt->m_year,dt->m_month,dt->m_day);
}