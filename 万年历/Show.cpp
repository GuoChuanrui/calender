#include"stdafx.h"

//������ʾ
void CalShow(CDateTime *dt)
{
	int select=1;
	while(select)
	{
		system("CLS");
		printf("******************************************\n");
		printf("* [1] ��ʾ��ǰ����      [2] ��ʾ��ǰʱ�� *\n");
		printf("* [3] ��ʾ����ʱ��      [4] ��̬ʱ����ʾ *\n");
		printf("* [5] ��ʾ����������    [0] �������˵�   *\n");
		printf("******************************************\n");
		printf("��ѡ��:> ");
		scanf("%d",&select);
		system("CLS");
		GetNowDateTime(dt);
		switch(select)
		{
			
		case 1:
			ShowDate(dt);
			break;//��ʾ��ǰ����
		case 2:		
			ShowTime(dt);
			break;//��ʾ��ǰʱ��
		case 3:
			GetNowDateTime(dt);
			ShowDateTime(dt);
			break;//��ʾ����ʱ��
		case 4:
			DShowTime(dt);
			break;//��̬ʱ����ʾ
		case 5:
			ShowNowCal(dt);
			break;//��ʾ����������
		case 0:
			main();
			break;//�������˵�
		default:
			printf("�����������������룡\n");
			break;
		}
		system("pause");
	}
}

//��ʾ����
void ShowDate(CDateTime *dt)
{
	printf("%d��%d��%d��\n",dt->m_year,dt->m_month,dt->m_day);
}

//��ʾʱ��
void ShowTime(CDateTime *dt)
{
	printf("%dʱ%d��%d��\n",dt->m_hour,dt->m_minute,dt->m_second);
}


//��̬��ʾʱ��
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

//������������ʾ����������
void ShowCal(int year,int month,int day)
{ 
	printf("\t  %d �� %d �� %d ��\n",year,month,day);
	printf("=======================================\n");
	char *Title[]={"��","һ","��","��","��","��","��"};
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

//��ʾ����������
void ShowNowCal(CDateTime *dt)
{
	ShowCal(dt->m_year,dt->m_month,dt->m_day);
}