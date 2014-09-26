/*************************************************************************
	> File Name: userToBar.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时21分09秒
 ************************************************************************/

#include "title.h"

/**
 * 队列中最优用户去柜台
 */
void userToBar() {
	int barNum;
	barNum = hasBar();
	if(barNum != -1 && !users.empty()) {
		user = users.top();
		users.pop();  // 进入柜台, 从队列中删除
		bar[barNum].work = 1;
		bar[barNum].user = user;
		bar[barNum].user.start = time(NULL);
		clrscr();
		gotoxy(0, 0);
		printf("\n\n\t\t\t\t温馨提示: %d 号柜台为空, %d号客户可前去办理业务\n", barNum + 1, user.id);
		printf("\n\n\t\t\t\t\t\t按任意键返回主菜单\n");
		getch();
	}
}
