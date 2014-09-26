/*************************************************************************
	> File Name: title.h
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 10时29分52秒
 ************************************************************************/

#ifndef __TT_H
#define __TT_H
#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
using namespace std;
#define out(x) (std::cerr << std::boolalpha << "Line " << __LINE__ << ": " << #x << ": " << (x) << std::endl)

#define BACKSPACE 127

#ifndef _LEE_H_ //Linux platform
#define _LEE_H_

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

#else           //WIN32 platform
#include <conio.h>
#endif

typedef struct User {
	int type; // vip:1 ,other:2
	int id;
	time_t start, end;
	bool operator < (const User o) const {
		if(type == o.type)
			return id < o.id;
		return type > o.type;
	}
} User;

typedef struct Bar {
	int id;
	User user;
	double score;  // 平均分数
	int cnt;  // 业务处理次数
	bool work;
} Bar;

extern int userID;
extern priority_queue<User> users, tmp;
extern double allVIPtime, allNVIPtime;
extern int allVIPCnt, allNVIPCnt;
extern User user;
extern Bar bar[];

int getch();
void init();
void clrscr();
void tm();
void setBackGroundColor();
void gotoxy(int x, int y);
bool login(FILE *file);
int hasBar();
void userToBar();
int Arrive();
void Leave();
void BusinessSelect();
void showQueue();
void SystemSelect();
void SystemLeave();
void welcome();

#endif // __TT_H
