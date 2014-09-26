/*************************************************************************
	> File Name: Leave.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时24分02秒
 ************************************************************************/

#include "title.h"

/**
 * 顾客离开界面
 */
void Leave() {
	int userId, barNum, score, times;
	clrscr();
	gotoxy(0, 0);
	printf("**********************************顾客离开界面**********************************\n\n");
	printf("\n");
	printf("请输入离开顾客的编号: ");
	scanf("%d", &userId);
	printf("尊敬的 %d 号您好！", userId);
	printf("为了改善服务质量, 请你对我们的服务进行评价。谢谢！\n");
	printf("请你输入你所办理业务的柜台号(1-3):\n");
	scanf("%d", &barNum);
	barNum = barNum - 1;
	times = 2;
	// 检测输入柜台与用户编号是否匹配
	while (times > 0) {
		if(bar[barNum].user.id != userId) {
			printf("\t\t\t您的输入有错, 您还有%d次机会重新输入\n", times);
			printf("请输入离开顾客的编号:\n");
			scanf("%d", &userId);
			printf("尊敬的 %d 号您好！", userId);
			printf("为了改善服务质量, 请你对我们的服务进行评价。谢谢！\n");
			printf("请你输入你所办理业务的柜台号(1-3):\n");
			scanf("%d", &barNum);
		} else {
			break;
		}
		times--;
	}
	if(times > 0) {
		printf("你所办理业务的柜台为 %d .\n", barNum + 1);
		printf("请输入您的评分(1-5):\n");
		printf("                    1分.......非常不满意;\n");
		printf("                    2分.......比较不满意;\n");
		printf("                    3分.......一般满意;\n");
		printf("                    4分.......比较满意;\n");
		printf("                    5分.......非常满意.\n");
		printf("请输入: ");
		scanf("%d", &score);
		printf("您的评分为%d.\n", score);
		bar[barNum].cnt ++;
		bar[barNum].score = bar[barNum].score + score;
		printf("%d柜台的平均满意度为%.2lf。感谢你的评分, 谢谢！！！\n", barNum + 1, bar[barNum].score / bar[barNum].cnt);
		bar[barNum].user.end = time(NULL);
		// 记录总时间和总顾客数
		double userTime = difftime(bar[barNum].user.end, bar[barNum].user.start);
		if(bar[barNum].user.type == 1) {
			allVIPCnt ++;
			allVIPtime += userTime;
		} else {
			allNVIPCnt ++;
			allNVIPtime += userTime;
		}
		printf("\n\n\t\t\t\t您办理业务所用的时间为 %.2lf 秒.\n", userTime);
		printf("\n\n\t\t\t\t\t按任意键返回主菜单\n");
		bar[barNum].work = 0; // 该柜台为空
		userToBar();  // 最优用户去柜台
		getch();
		getch();
	} else { // 输入数字不合法3次
		printf("\n\n\t\t\t\t离开失败, 请按任意键返回！\n");
		printf("\n\n\t\t\t\t\t\t按任意键返回主菜单\n");
		getch();
		getch();
	}
}

