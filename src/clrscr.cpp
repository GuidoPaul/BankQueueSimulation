/*************************************************************************
	> File Name: clrscr.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时08分57秒
 ************************************************************************/


#include "title.h"

/**
 * 清屏
 */
void clrscr() {
	int i;
	for (i = 0; i < 100; i++) {
		putchar('\n');
	}
}
