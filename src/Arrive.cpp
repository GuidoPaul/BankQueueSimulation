/*************************************************************************
	> File Name: Arrive.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时22分08秒
 ************************************************************************/

#include "title.h"

/**
 * 顾客到达界面
 * 返回值: 1 顾客进入成功, 0 顾客进入失败
 */
int Arrive() {
	int times, barNum;
	bool success;
	clrscr();
	gotoxy(0, 0);
	printf("**********************************顾客到达界面**********************************\n\n");
	printf("\t\t\t\t请选择你的用户类型:\n\n");
	printf("\t\t\t\t1.VIP用户\n\n");
	printf("\t\t\t\t2.普通卡用户\n\n");
	printf("请输入: ");
	scanf("%d", &user.type);
	times = 2;
	// 校验输入数字是否合法, ///////// 仅数字
	while (times > 0) {
		if (user.type != 1 && user.type != 2) {
			printf("\t\t\t您的输入有错, 您还有%d次机会重新输入\n", times);
			printf("请输入: ");
			scanf("%d", &user.type);
		} else {
			break;
		}
		times--;
	}
	if (times > 0) {
		if (user.type == 1) { // VIP
			success = login(fopen("vip", "r"));
			if(success) {
				user.id = ++ userID;
				user.type = 1;
				users.push(user);
			}
		} else { // 非VIP
			success = login(fopen("nvip", "r"));
			if(success) {
				user.id = ++ userID;
				user.type = 2;
				users.push(user);
			}
		}
		if(success) {
			clrscr();
			gotoxy(0, 0);
			printf("\n\n\t\t\t请收好你的编号单子, 您的编号为%d号!", userID);
			printf("\n\n\t\t\t\t确认后请按任意键返回主菜单\n");
			getch();
			userToBar();
		}
	} else { // 输入数字不合法3次
		printf("\n\n\t\t\t\t登录失败, 请按任意键返回！\n");
		printf("\n\n\t\t\t\t\t\t按任意键返回主菜单\n");
		getch();
		getch();
		return 0;
	}
}
