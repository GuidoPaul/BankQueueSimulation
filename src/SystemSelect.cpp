/*************************************************************************
	> File Name: SystemSelect.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时26分34秒
 ************************************************************************/

#include "title.h"

/**
 * 系统查询界面
 */
void SystemSelect() {
	clrscr();
	gotoxy(0, 0);
	printf("**********************************系统查询界面**********************************\n\n");
	printf("\n");
	/* printf("请输入你的卡号: "); */
	/* scanf("%d", &userId); */
	/* printf("请您输入五位密码: "); */
	/* scanf("%d", &psw); */
	printf("\n\t至今已有 %d 位普通用户, %d 位vip用户成功办理业务！\n", allNVIPCnt, allVIPCnt);
	printf("\n\tVIP用户业务办理总共用时 %.2lf 秒, 平均用时 %.2lf 秒\n", allVIPtime, allVIPtime / allVIPCnt);
	printf("\n\t普通用户业务办理总共用时 %.2lf 秒, 平均用时 %.2lf 秒\n", allNVIPtime, allNVIPtime / allNVIPCnt);
	printf("\n\n\t\t\t\t\t按任意键返回主菜单\n");
	getch();
	getch();
}
