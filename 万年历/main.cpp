#include"stdafx.h"

CDateTime dt;


/////////////////
//   �޸������е�S��Cû��
//   ���ڱ���¼û��

///////////////
void main()
{	
	InitDateTime(&dt);
	GetNowDateTime(&dt);
	ShowDateTime(&dt);						
	int select=1;
	while(select)
	{
		system("CLS");
		printf("**********************************\n");
		printf("*             ������             *\n");
		printf("*         [1] ������ʾ   ->      *\n");
		printf("*         [2] ������ѯ   ->      *\n");
		printf("*         [3] �޸�����   ->      *\n");
		printf("*         [4] ���ڱ���¼ ->      *\n");
		printf("*         [5] ��Ϣ����           *\n");
		printf("*         [0] �˳�ϵͳ           *\n");
		printf("**********************************\n");
		printf("��ѡ��:> ");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			CalShow(&dt);
			break;//������ʾ 
		case 2:
			CalSelect(&dt);
			break;//������ѯ
		case 3:
			ModifyDate(&dt);
			break;//�޸�����
		case 4:
			DateMemo(&dt);
			break;//���ڱ���¼
		case 5:
			Help();
			break;//��Ϣ����
		case 0:
			exit(0);
			break;//�˳�ϵͳ
		default:
			printf("�����������������룡\n");
			system("pause");
			break;
		}
	}
}
