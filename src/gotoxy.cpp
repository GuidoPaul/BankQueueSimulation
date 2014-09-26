/*************************************************************************
	> File Name: gotoxy.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时12分23秒
 ************************************************************************/

#include "title.h"

/**
 * 光标跳转到指定位置
 */
void gotoxy(int x, int y) {
	char essq[100], xstr[100], ystr[100];

	sprintf(xstr, "%d", x);
	sprintf(ystr, "%d", y);

	essq[0] = '\0';

	strcat(essq, "\033[");
	strcat(essq, ystr);
	strcat(essq, "d");

	strcat(essq, "\033[");
	strcat(essq, xstr);
	strcat(essq, "G");

	printf("%s", essq);
}
