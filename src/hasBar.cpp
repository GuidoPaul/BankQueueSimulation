/*************************************************************************
	> File Name: hasBar.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时20分29秒
 ************************************************************************/

#include "title.h"

/**
 * 检测柜台是否有顾客
 * 返回值: 0-2表示相应柜台, -1无空柜台
 */
int hasBar() {
	int i;
	for (i = 0; i < 3; ++i) {
		if(bar[i].work == 0) {
			return i;
		}
	}
	return -1;
}
