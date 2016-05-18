#include"stdafx.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define PAGEUP 73
#define PAGEDOWN 81
#define S 83
#define C 67

//修改日期
void ModifyDate(CDateTime *dt)
{
	int key;
	while(1)
	{
		system("CLS");
		ShowNowCal(dt);
		printf("\n\n");
		printf("  ↑   : 上一年      ↓    : 下一年\n");
		printf("  ←   : 上个月      →    : 下个月\n");
		printf("PageUp : 昨 天    PageDown : 明 天\n");
		printf("  S    : 保 存       C     : 取 消\n");
		_getch();
		key=_getch();
		switch(key)
		{
		case UP:
			if(dt->m_year>1)
				dt->m_year--;
			break;
		case DOWN:
			dt->m_year++;
			break;
		case LEFT:
			if(dt->m_month>1)
				dt->m_month--;
			break;
		case RIGHT:
			if(dt->m_month<12)
				dt->m_month++;
			break;
		case PAGEUP:
			if(dt->m_day>1)
				dt->m_day--;
			break;
		case PAGEDOWN:
			if(dt->m_day<GetDayByYM(dt->m_year,dt->m_month))
				dt->m_day++;
			break;
		case S:
			ShowDate(dt);
			system("pause");
			break;
		case C:
			printf("C");
			system("pause");
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
	}
}


