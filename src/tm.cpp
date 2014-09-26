/*************************************************************************
	> File Name: tm.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时10分12秒
 ************************************************************************/

#include "title.h"

/**
 * 显示当前时间
 */
void tm() {
	time_t timep;
	time(&timep);
	printf("现在时刻：%s", ctime(&timep));
}
