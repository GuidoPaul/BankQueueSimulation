/*************************************************************************
	> File Name: init.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 10时38分32秒
 ************************************************************************/

#include "title.h"

/**
 * 初始化, 固化卡号
 */
void init() {
	int i;
	userID = 0;
	allVIPCnt = allNVIPCnt = 0;
	allVIPtime = allNVIPtime = 0;
	while (!users.empty()) {
		users.pop();
	}
	for (i = 0; i < 3; ++i) {
		bar[i].user.id = 0;
		bar[i].score = 0;
		bar[i].cnt = 0;
		bar[i].work = 0;
	}
}
