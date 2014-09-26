/*************************************************************************
	> File Name: showQueue.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时25分54秒
 ************************************************************************/

#include "title.h"

/**
 * 顾客排队界面
 */
void showQueue() {
	int size, i;
	clrscr();
	gotoxy(0, 0);
	printf("**********************************顾客排队界面**********************************\n\n");
	printf("\n");
	while(!tmp.empty()) {
		tmp.pop();
	}
	size = users.size();
	for (i = 0; i < size; ++i) {
		user = users.top();
		users.pop();
		printf("第%d位: %d号客户\n", i + 1, user.id);
		tmp.push(user);
	}
	users = tmp;
	printf("\n\n\t\t\t\t\t按任意键返回主菜单\n");
	getch();
	getch();
}
