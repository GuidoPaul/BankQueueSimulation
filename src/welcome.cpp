/*************************************************************************
	> File Name: welcome.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时37分15秒
 ************************************************************************/

#include "title.h"

/**
 * 欢迎界面
 */
void welcome() {
	int option;

	clrscr();
	gotoxy(0, 0);
	printf("****************************顾欢迎使用银行业务管理器****************************\n\n");
	printf("\t\t\t\t请选择服务项:\n\n");
	printf("\t\t\t\t1.顾客到来\n\n");
	printf("\t\t\t\t2.顾客离开\n\n");
	printf("\t\t\t\t3.查看业务办理情况\n\n");
	printf("\t\t\t\t4.查看排队情况\n\n");
	printf("\t\t\t\t5.系统查询\n\n");
	printf("\t\t\t\t6.退出系统\n\n");
	printf("请输入: ");
	scanf("%d", &option);
	switch (option) {
		case 1: Arrive();
				break;
		case 2: Leave();
				break;
		case 3: BusinessSelect();
				break;
		case 4: showQueue();
				break;
		case 5: SystemSelect();
				break;
		case 6: SystemLeave();
				break;
		default: printf("混蛋！\n");
	}
}
