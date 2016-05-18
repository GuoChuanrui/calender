#include"stdafx.h"

//日期备忘录
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
		printf("* [1] 查看备忘录          [2] 增加备忘信息  *\n");
		printf("* [3] 删除备忘信息        [4] 导出备忘录    *\n");
		printf("* [0] 返回主菜单                            *\n");
		printf("*********************************************\n");
		printf("请选择:> ");
		scanf("%d",&select);
		system("CLS");
		switch(select)
		{
		case 1:
			LookMemo(fp);
			break;//查看备忘录
		case 2:
			AddMemo(fp);
			break;//增加备忘信息
		case 3:
			break;//删除备忘信息
		case 4:
			break;//导出备忘录  
		case 0:
			main();
			break;//返回主菜单
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
		system("pause");
	}
	fclose(fp);
}

//查看备忘录
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

//增加备忘录
void AddMemo(FILE *fp)
{
	
	char ch=getchar();
	while(ch!='\n')
	{
		fputc(ch,fp);
		ch=getchar();
	}
}

  