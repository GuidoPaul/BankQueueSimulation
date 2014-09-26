/*************************************************************************
	> File Name: login.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年09月13日 星期六 20时17分09秒
 ************************************************************************/

#include "title.h"

/**
 * 登录, vip和管理员登录都会调用本函数, 登录时将密码变成星号*****
 */
bool login(FILE *file) {
	char str1[6] = " ", str2[7] = " ", id[5], pwd[6], a, b, c;
	int i = 0, j = 0;

	clrscr();
	gotoxy(0, 0);
	printf("********************************登录验证界面********************************\n");
	printf("\n\t\t请输入5位帐号:");
	printf("\n\t\t请输入6位密码:");
	printf("\n\n\n\n\n");
	printf("\n****************************************************************************\n");
	printf("      1-9、a-z按键输入\t\t  按ESC返回\t\t按回车确认");
	gotoxy(32, 3);
	getchar();
	for (i = 0; i < 5; i++) {
		b = getch();
		while (!((b >= '0' && b <= '9') || (b >= 'a' && b <= 'z') || (b > 'Z' && b < 'A') || b == '\n' || b == BACKSPACE || b == 27)) {
			b = getch();
		}
		if (b == 27) return 0; // Esc
		if (i == 0) {//判断第一位帐号输入的内容
			if (b == BACKSPACE) {//判断第一个字符输入的是退格
				printf("\b");
				gotoxy(32, 3);
				printf("");
				i--;
			} else if (b == '\n') {//判断输入回车的情况
				gotoxy(60, 6);
				printf("账号不能为空");
				gotoxy(32, 3);
				i--;
			} else {
				str1[i] = b;
				printf("%c", b);
			}
		} else {//判断第一位之后的帐号输入的字符
			if (b == BACKSPACE) {//判断第一个字符输入的是退格 
				printf("\b");
				printf(" ");
				printf("\b");
				i = i - 2;
			} else if (b == '\n') {//判断输入回车的情况
				gotoxy(60, 6);
				printf("账号必须五位");
				gotoxy(32, 3);
				printf("    ");
				gotoxy(32, 3);
				i = -1;
			} else {
				str1[i] = b;
				printf("%c", b);
			}
			if (i == 4) {//账号满5位
				a = getch();
				while (a != BACKSPACE && a != '\n') {
					a = getch();
				}
				if (a == BACKSPACE) {
					i--;
					printf("\b");
					printf(" ");
					printf("\b");
				} else {
					if (a == '\n') {
						gotoxy(32, 4);
						break;
					}
				}
			}
		}
	}
	for (j = 0; j < 6; j++) {
		c = getch();
		while (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c > 'Z' && c < 'A') || c == '\n' || c == BACKSPACE || c == 27)) {
			c = getch();
		}
		if (c == 27) return 0;
		if (j == 0) {
			if (c == BACKSPACE) {//判断第一个字符输入的是退格
				printf("\b");
				//                gotoxy(hOut, 30, 4);
				gotoxy(32, 4);
				printf("");
				j--;
			} else if(c == '\n') {//判断第一个字符输入的是回车
				//                gotoxy(hOut, 60, 6);
				gotoxy(60, 6);
				printf("密码不能为空");
				gotoxy(32, 4);
				//                gotoxy(hOut, 30, 4);
				j--;
			} else {
				str2[j] = c;
				printf("*");
			}
		} else {//判断第一位之后的密码输入的字符
			if (c == BACKSPACE) {//当输入的是删除键，删除前面的密码
				printf("\b");
				printf(" ");
				printf("\b");
				j = j - 2;
			} else if (c == '\n') {//判断输入回车的情况
				//                gotoxy(hOut, 60, 6);
				gotoxy(60, 6);
				printf("密码必须五位");
				//                gotoxy(hOut, 30, 4);
				gotoxy(32, 4);
				printf("      ");
				//                        gotoxy(hOut, 30, 4);
				gotoxy(32, 4);
				j = -1;
			} else {
				str2[j] = c;
				printf("*");
			}
			if (j == 5) {
				a = getch();
				while (a != '\n' && a != BACKSPACE)
					a = getch();
				if (a == BACKSPACE) {
					j--;
					printf("\b");
					printf(" ");
					printf("\b");
				} else {
					if (a == '\n') {
						break;
					}
				}
			}
		}
	}
	while (1) {
		/* getc(file); */
		/* getc(file); //获取文件数据流的前两个字符 */
		fscanf(file, "%5[^\n]\n", id); //取文件数据流接下来的除换行标志的五位字符
		if (strcmp(str1, id) == 0) {  // 账号匹配
			/* getc(file); */
			/* getc(file); */
			/* getc(file); */
			fscanf(file, "%6[^\n]\n", pwd); //取文件数据流接下来的除换行标志的六位字符
			if (strcmp(str2, pwd) == 0) { // 密码匹配
				clrscr();
				gotoxy(0, 0);
				printf("\n\n\t\t\t\t登陆成功! \n");
				printf("\n\n\t\t\t\t\t\t请按任意键继续\n");
				getchar();
				return 1;
			} else { // 密码不匹配
				clrscr();
				gotoxy(0, 0);
				printf("\n\n\t\t\t\t对不起，您所输入的密码有误!\n");
				printf("\n\n\t\t\t\t\t\t按任意键返回主菜单\n");
				getchar();
				return 0;
			}
		} else { //取下一行判断 
			c = getc(file);
			while (c != '\n' && c != EOF) {
				c = getc(file);
			}
			if (c == EOF) {
				clrscr();
				gotoxy(0, 0);
				printf("\n\n\t\t\t\t对不起，您所输入的账号有误!\n");
				printf("\n\n\t\t\t\t\t\t按任意键返回主菜单\n");
				getchar();
				return 0;
			}
		}
	}
}
