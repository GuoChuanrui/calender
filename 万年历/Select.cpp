#include"stdafx.h"

//������ѯ
void CalSelect(CDateTime *dt)
{
	int select=1;
	while(select)
	{
		system("CLS");
		printf("************************************************\n");
		printf("* [1] ��ѯ��ǰ����          [2] ��ѯ��ǰʱ��   *\n");
		printf("* [3] ��ѯ����ʱ��          [4] �� ѯ �� ��    *\n");
		printf("* [5] ��ѯN�������         [6] ��ѯN��ǰ����  *\n");
		printf("* [7] ��ѯ����ĳ���ڵ�����  [0] �������˵�     *\n");
		printf("************************************************\n");
		printf("��ѡ��:> ");
		scanf("%d",&select);
		system("CLS");
		GetNowDateTime(dt);
		switch(select)
		{
		case 1:
			ShowDate(dt);
			break;//��ѯ��ǰ����
		case 2:		
			ShowTime(dt);
			break;//��ѯ��ǰʱ��
		case 3:
			ShowDateTime(dt);
			break;//��ѯ����ʱ��
		case 4:
			SelectWeek(dt);
			break;//�� ѯ �� ��  
		case 5:
			SelectAfterNDate();
			break;//��ѯN�������
		case 6:
			SelectBeforeNDate();
			break;//��ѯN��ǰ����
		case 7:
			SelectDateNum();
			break;//��ѯ����ĳ���ڵ�����
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

//��ѯ����
void SelectWeek(CDateTime *dt)
{
	int week=GetWeekByYMD(dt->m_year,dt->m_month,dt->m_day);
	if(week==0)
		printf("������������\n");
	else
		printf("�������� %d\n",week);
}


//��ѯN��������
void SelectAfterNDate()
{
	CDateTime dt;
	GetNowDateTime(&dt);
	int n;
	printf("������N:>");
	scanf("%d",&n);
	CDateTime p=GetNextDateTime(&dt,n);
	ShowDate(&p);
}


//��ѯN��ǰ������
void SelectBeforeNDate()
{
	CDateTime dt;
	GetNowDateTime(&dt);
	int n;
	printf("������N:>");
	scanf("%d",&n);
	CDateTime p=GetLastDateTime(&dt,n);
	ShowDate(&p);
}


//��ѯ����ĳ���ڵ�����
void SelectDateNum()
{
	CDateTime dt,pt;
	GetNowDateTime(&dt);
	InitDateTime(&pt);
	int num=0;
	printf("  ��  ��  ��  :> ");
	ShowDate(&dt);
	printf("\n");
	printf("������һ������:> ");
	scanf("%d��%d��%d��",&pt.m_year,&pt.m_month,&pt.m_day);
	if((pt.m_year>0)&&(pt.m_month<=12)&&(pt.m_month>=1)&&(pt.m_day>=1)&&(pt.m_day<=31))
	{
		printf("\n");
		num=GetDateNum(&dt,&pt);
		printf("  ��  ��  %d  ��  \n",num);
	}
	else
	{
		printf("��������,����������!");
		system("pause");
		system("CLS");
		SelectDateNum();
	}	
}