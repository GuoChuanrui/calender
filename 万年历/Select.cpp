#include"stdafx.h"

//日历查询
void CalSelect(CDateTime *dt)
{
	int select=1;
	while(select)
	{
		system("CLS");
		printf("************************************************\n");
		printf("* [1] 查询当前日期          [2] 查询当前时间   *\n");
		printf("* [3] 查询日期时间          [4] 查 询 星 期    *\n");
		printf("* [5] 查询N天后日期         [6] 查询N天前日期  *\n");
		printf("* [7] 查询距离某日期的天数  [0] 返回主菜单     *\n");
		printf("************************************************\n");
		printf("请选择:> ");
		scanf("%d",&select);
		system("CLS");
		GetNowDateTime(dt);
		switch(select)
		{
		case 1:
			ShowDate(dt);
			break;//查询当前日期
		case 2:		
			ShowTime(dt);
			break;//查询当前时间
		case 3:
			ShowDateTime(dt);
			break;//查询日期时间
		case 4:
			SelectWeek(dt);
			break;//查 询 星 期  
		case 5:
			SelectAfterNDate();
			break;//查询N天后日期
		case 6:
			SelectBeforeNDate();
			break;//查询N天前日期
		case 7:
			SelectDateNum();
			break;//查询距离某日期的天数
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

//查询星期
void SelectWeek(CDateTime *dt)
{
	int week=GetWeekByYMD(dt->m_year,dt->m_month,dt->m_day);
	if(week==0)
		printf("今天是星期日\n");
	else
		printf("今天星期 %d\n",week);
}


//查询N天后的日期
void SelectAfterNDate()
{
	CDateTime dt;
	GetNowDateTime(&dt);
	int n;
	printf("请输入N:>");
	scanf("%d",&n);
	CDateTime p=GetNextDateTime(&dt,n);
	ShowDate(&p);
}


//查询N天前的日期
void SelectBeforeNDate()
{
	CDateTime dt;
	GetNowDateTime(&dt);
	int n;
	printf("请输入N:>");
	scanf("%d",&n);
	CDateTime p=GetLastDateTime(&dt,n);
	ShowDate(&p);
}


//查询距离某日期的天数
void SelectDateNum()
{
	CDateTime dt,pt;
	GetNowDateTime(&dt);
	InitDateTime(&pt);
	int num=0;
	printf("  今  天  是  :> ");
	ShowDate(&dt);
	printf("\n");
	printf("请输入一个日期:> ");
	scanf("%d年%d月%d日",&pt.m_year,&pt.m_month,&pt.m_day);
	if((pt.m_year>0)&&(pt.m_month<=12)&&(pt.m_month>=1)&&(pt.m_day>=1)&&(pt.m_day<=31))
	{
		printf("\n");
		num=GetDateNum(&dt,&pt);
		printf("  相  距  %d  天  \n",num);
	}
	else
	{
		printf("输入有误,请重新输入!");
		system("pause");
		system("CLS");
		SelectDateNum();
	}	
}