#include"stdafx.h"

CDateTime dt;


/////////////////
//   修改日期中的S和C没做
//   日期备忘录没完

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
		printf("*             万年历             *\n");
		printf("*         [1] 日历显示   ->      *\n");
		printf("*         [2] 日历查询   ->      *\n");
		printf("*         [3] 修改日期   ->      *\n");
		printf("*         [4] 日期备忘录 ->      *\n");
		printf("*         [5] 信息帮助           *\n");
		printf("*         [0] 退出系统           *\n");
		printf("**********************************\n");
		printf("请选择:> ");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			CalShow(&dt);
			break;//日历显示 
		case 2:
			CalSelect(&dt);
			break;//日历查询
		case 3:
			ModifyDate(&dt);
			break;//修改日期
		case 4:
			DateMemo(&dt);
			break;//日期备忘录
		case 5:
			Help();
			break;//信息帮助
		case 0:
			exit(0);
			break;//退出系统
		default:
			printf("输入有误，请重新输入！\n");
			system("pause");
			break;
		}
	}
}
