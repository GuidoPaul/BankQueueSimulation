/*************************************************************************
	> File Name: BusinessSelect.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时25分14秒
 ************************************************************************/

#include "title.h"

/**
 * 业务查询界面
 */
void BusinessSelect() {
	int i;
	clrscr();
	gotoxy(0, 0);
	printf("**********************************业务查询界面**********************************\n\n");
	printf("\n");
	printf("正在办理业务的顾客编号为: 一号柜台 二号柜台 三号柜台\n");
	printf("                        ");
	for (i = 0; i < 3; ++i) {
		if(bar[i].user.id == 0) {
			printf("   无客户");
		} else {
			printf("  %d号客户", bar[i].user.id);
		}	
	}
	printf("\n\n\t\t\t\t\t按任意键返回主菜单\n");
	getch();
	getch();
}
