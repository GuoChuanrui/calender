#include"stdafx.h"

//���ڱ���¼
void DateMemo(CDateTime *dt)
{
	FILE *fp;
	if((fp=fopen("Memo.txt","r++"))==NULL) {
       	printf("cannot open file\n");
       	exit(0); 
	}

	int select=1;
	while(select)
	{
		system("CLS");
		printf("*********************************************\n");
		printf("* [1] �鿴����¼          [2] ���ӱ�����Ϣ  *\n");
		printf("* [3] ɾ��������Ϣ        [4] ��������¼    *\n");
		printf("* [0] �������˵�                            *\n");
		printf("*********************************************\n");
		printf("��ѡ��:> ");
		scanf("%d",&select);
		system("CLS");
		switch(select)
		{
		case 1:
			LookMemo(fp);
			break;//�鿴����¼
		case 2:
			AddMemo(fp);
			break;//���ӱ�����Ϣ
		case 3:
			break;//ɾ��������Ϣ
		case 4:
			break;//��������¼  
		case 0:
			main();
			break;//�������˵�
		default:
			printf("�����������������룡\n");
			break;
		}
		system("pause");
	}
	fclose(fp);
}

//�鿴����¼
void LookMemo(FILE *fp)
{
	char ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
        ch=fgetc(fp);
	}
	printf("\n");
}

//���ӱ���¼
void AddMemo(FILE *fp)
{
	
	char ch=getchar();
	while(ch!='\n')
	{
		fputc(ch,fp);
		ch=getchar();
	}
}

  