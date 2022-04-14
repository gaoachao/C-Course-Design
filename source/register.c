#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>
#include "hz.h"
#include "register.h"
#include "database.h"
#include "mouse.h"
#include "login.h"

/***********************************
FUNCTION: register_main
DESCRIPTION: 注册控制主函数
INPUT: *func,*u
RETURN: 无
***********************************/
void register_main(int *func, USER *u)
{
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int num = 0;
	int password_flag = 0, password_flag_record = 0;
	static int flag = 0;
	char name[16];
	char password[16];
	char id[20];
	char str[16]; //保存确定密码
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	printf("the sizeof USER is %d\n", sizeof(USER));

	memset(u, '\0', sizeof(USER));
	memset(name, '\0', sizeof(name));
	memset(password, '\0', sizeof(password));
	memset(id, '\0', sizeof(id));
	memset(str, '\0', sizeof(str));

	register_page();
	exit_buttom();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//账号栏
		if (MouseX > 120 && MouseX < 520 && MouseY > 120 && MouseY < 150)
		{
			if (mouse_press(120, 120, 520, 150) == 2) //账号输入框未点击
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)
				{
					lightup_register(120, 120, 520, 150, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(120, 120, 520, 150) == 1) //账号输入栏点击
			{
				lightup_register(120, 120, 520, 150, 1);
				memset(name, '\0', sizeof(name));  //用户名清除
				inputadmin(name, 120, 120, 15, 7); //输入用户名
				if (strlen(name) == 0)
				{
					state1 = 0;
				}
				else
					state1 = 1;
			}
		}

		//设置密码栏
		if (MouseX > 120 && MouseX < 520 && MouseY > 190 && MouseY < 220)
		{
			if (mouse_press(120, 190, 520, 220) == 2) //输入密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightup_register(120, 190, 520, 220, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(120, 190, 520, 220) == 1) //密码输入栏点击
			{
				lightup_register(120, 190, 520, 220, 1);
				memset(password, '\0', sizeof(password)); //密码清除
				inputadmin(password, 120, 190, 16, 7);	  //输入密码
				if (strlen(password) == 0)
				{
					state2 = 0;
				}
				else
					state2 = 1;
			}
		}

		//确定密码栏
		if (MouseX > 120 && MouseX < 520 && MouseY > 260 && MouseY < 290)
		{
			if (mouse_press(120, 260, 520, 290) == 2) //确定密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightup_register(120, 260, 520, 290, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(120, 260, 520, 290) == 1) //确定密码输入栏点击
			{
				lightup_register(120, 260, 520, 290, 1);
				memset(str, '\0', sizeof(str));	  //确定密码清除
				inputadmin(str, 120, 260, 12, 7); //再次输入密码
				if (strlen(str) == 0)
				{
					state3 = 0;
				}
				else
					state3 = 1;
			}
		}

		//身份证号栏
		if (MouseX > 120 && MouseX < 520 && MouseY > 330 && MouseY < 360)
		{
			if (mouse_press(120, 330, 520, 360) == 2) //输入身份证号栏未点击
			{
				MouseS = 2;
				if (num == 0 && state4 == 0)
				{
					lightup_register(120, 330, 520, 360, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(120, 330, 520, 360) == 1) //身份证号输入栏点击
			{
				lightup_register(120, 330, 520, 360, 1);
				memset(id, '\0', sizeof(id));	 //身份证号清除
				inputadmin(id, 120, 330, 18, 7); //输入身份证号
				if (strlen(id) == 0)
				{
					state4 = 0;
				}
				else
					state4 = 1;
			}
		}

		//注册键
		if (MouseX > 120 && MouseX < 400 && MouseY > 250 && MouseY < 430)
		{
			if (mouse_press(120, 400, 250, 430) == 2) //注册键未点击
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_register(120, 400, 250, 430, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(120, 400, 250, 430) == 1) //注册键点击
			{
				lightup_register(120, 400, 250, 430, 2);
				//	printf("%s\n%s\n%s\n%s\n",name,password,str,id);
				if (register_complete_judge(name, password, id, str) == 1)
				{
					*func = 0;
					delay(3000);
					return;
				}
				else
					continue;
			}
		}

		//返回键
		if (MouseX > 390 && MouseX < 520 && MouseY > 250 && MouseY < 430)
		{
			if (mouse_press(390, 400, 520, 430) == 2) //返回键未点击
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_register(390, 400, 520, 430, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(390, 400, 520, 430) == 1) //返回键点击
			{
				lightup_register(390, 400, 520, 430, 3);
				*func = 0;
				return;
			}
		}

		//检查两次输入密码是否相同
		if (state2 == 1 && state3 == 1)
		{
			password_flag = confirm_password(password, str);
			if (flag == 0)
			{
				confilm_password_state(360, 290, password_flag);
				password_flag_record = password_flag;
				flag++;
			}
			else
			{
				if (password_flag != password_flag_record)
				{
					if (password_flag == 1)
					{
						confilm_password_state(360, 290, 1);
					}
					else
					{
						confilm_password_state(360, 290, 0);
					}
					password_flag_record = password_flag;
				}
			}
		}

		//输入框及按键点亮
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbuttom_register(120, 120, 520, 150, 1);
			}
			if (state2 == 0)
			{
				recoverbuttom_register(120, 190, 520, 220, 1);
			}
			if (state3 == 0)
			{
				recoverbuttom_register(120, 260, 520, 290, 1);
			}
			if (state4 == 0)
			{
				recoverbuttom_register(120, 330, 520, 360, 1);
			}
			if (num == 2)
			{
				recoverbuttom_register(120, 400, 250, 430, 2);
			}
			if (num == 3)
			{
				recoverbuttom_register(390, 400, 520, 430, 3);
			}

			num = 0;
		}

		//退出键
		if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
		{
			if (mouse_press(595, 0, 640, 20) == 1)
			{
				*func = 1;
				return;
			}
		}
	}
}

/***********************************
FUNCTION: register_complete_judge
DESCRIPTION: 判断注册信息是否就绪
INPUT: *name,*password,*id,str
RETURN: 1,就绪；0，未就绪
***********************************/
int register_complete_judge(char *name, char *password, char *id, char *str)
{
	// int state=0;//输入框是否输入内容
	int state1; //用户名信息检测
	int state2; //密码信息检测
	int state3; //确认密码信息检测
	int state4; //身份证号信息检测
	int flag = 0;

	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(522, 120, 620, 150);
	bar(522, 190, 620, 220);
	bar(522, 260, 620, 290);
	bar(522, 330, 620, 360);

	//返回值为1表示符合要求
	state1 = name_judge(name, 524, 122);
	state2 = password_judge(password, 524, 192);
	state3 = password_confirm_judge(password, str, 524, 262);
	state4 = id_judge(id, 524, 332);

	if (state1 == 1 && state2 == 1 && state3 == 1 && state4 == 1)
	{
		flag = duplicate_judge(name);
		// printf("flag=%d\n",flag);
		if (flag == 1)
		{
			// printf("duplicate_judge=1\n");
			return 0;
		}
		else if (flag == 0)
		{
			inputadmin_database(name, password, id);
			return 1; //就绪
		}
	}
	else
	{
		return 0;
	}
}

/***********************************
FUNCTION: duplicate_judge
DESCRIPTION: 判断用户名是否已经被注册
INPUT: *name
RETURN: 1,已被注册；0，未注册
***********************************/
int duplicate_judge(char *name)
{
	int len;
	int i;
	USER *u = NULL;
	FILE *fp;

	if ((fp = fopen("database\\userdata.dat", "rb+")) == NULL)
	{
		printf("cannot open file userdata\n");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER *)malloc(sizeof(USER))) == NULL)
		{
			printf("malloc runs wrong in register.c\n");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		//	printf("%s\t%s\t",u.name,name);
		//	printf("%d\n",strcmp(u.name,name));
		if (strcmp(u->name, name) == 0)
		{
			clrmous(MouseX, MouseY);
			delay(10);
			setfillstyle(SOLID_FILL, LIGHTCYAN);
			bar(522, 120, 620, 150);

			puthz(522, 120, "用户名存在", 16, 18, RED);
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("database can't be closed\n");
				delay(3000);
				exit(1);
			}
			return 1;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("database can't be closed\n");
		delay(3000);
		exit(1);
	}
	return 0;
}

/***********************************
FUNCTION: confirm_password
DESCRIPTION: 判断两次输入的密码是否相同
INPUT: *str1,*str2,x,y
RETURN: 1,密码一致；0，密码不一致
***********************************/
int confirm_password(char *str1, char *str2)
{

	if (strcmp(str1, str2) == 0)
	{
		//	puthz(x,y+2,"密码一致",16,18,GREEN);
		return 1;
	}
	else
	{
		//	puthz(x,y+2,"两次输入密码不一致",16,18,RED);
		return 0;
	}
}

/***********************************
FUNCTION: confirm_password_state
DESCRIPTION: 输出确认密码状态
INPUT: x,y,flag(1,密码一致；0，密码不一致)
RETURN: 无
***********************************/
void confilm_password_state(int x, int y, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);

	setfillstyle(SOLID_FILL, LIGHTCYAN);
	// bar(360,292,520,310);
	bar(x, y + 2, x + 160, y + 20);
	if (flag == 1)
	{
		puthz(x, y + 2, "密码一致", 16, 18, GREEN);
	}
	else
	{
		puthz(x, y + 2, "两次输入密码不一致", 16, 18, RED);
	}
}

/***********************************
FUNCTION: name_judge
DESCRIPTION: 判断用户名输入框内是否就绪
INPUT: *name,x,y
RETURN: 0(未输入)/1(已输入)
***********************************/
int name_judge(char *name, int x, int y)
{
	if (strlen(name) == 0)
	{
		puthz(x, y, "未输入", 16, 18, RED);
		return 0;
	}
	else
	{
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		// line(550, 158, 560, 168);
		// line(560, 168, 570, 148);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 1;
	}
}

/***********************************
FUNCTION: password_judge
DESCRIPTION: 判断密码输入框内是否就绪
INPUT: *password,x,y
RETURN: 0(密码不符合要求)/1(密码符合要求)
***********************************/
int password_judge(char *password, int x, int y)
{
	if (strlen(password) >= 6)
	{
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 1;
	}
	else if (strlen(password) < 6 && strlen(password) > 0)
	{
		puthz(x, y, "密码过短", 16, 18, RED);
		return 0;
	}
	else
	{
		puthz(x, y, "未输入", 16, 18, RED);
		return 0;
	}
}

/***********************************
FUNCTION: password_confirm_judge
DESCRIPTION: 判断确认密码输入框内是否就绪
INPUT: *password,*str,x,y
RETURN: 0(不符合要求)/1(符合要求)
***********************************/
int password_confirm_judge(char *password, char *str, int x, int y)
{
	if (strlen(str) == 0)
	{
		puthz(x, y, "未输入", 16, 18, RED);
		return 0;
	}
	else
	{
		if (confirm_password(str, password) == 1)
		{
			setcolor(GREEN);
			setlinestyle(SOLID_LINE, 0, 3);
			line(x + 3, y + 8, x + 13, y + 18);
			line(x + 13, y + 18, x + 23, y - 2);
			return 1;
		}
		else
			return 0;
	}
}

/***********************************
FUNCTION: id_judge
DESCRIPTION: 判断身份证号输入框内是否就绪
INPUT: *id,x,y
RETURN: 0(不符合要求)/1(符合要求)
***********************************/
int id_judge(char *id, int x, int y)
{
	if (strlen(id) == 0)
	{
		puthz(x, y, "未输入", 16, 18, RED);
		return 0;
	}
	else if (strlen(id) == 18)
	{
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 1;
	}
	else
	{
		puthz(x, y, "输入过短", 16, 18, RED);
		return 0;
	}
}

/***********************************
FUNCTION: inputadmin_database
DESCRIPTION: 将注册信息写入数据库
INPUT: *id 需要输入的字符串，x，y，charnum 最多输入的字符数
RETURN: 无
***********************************/
void inputadmin_database(char *name, char *password, char *id)
{
	USER u;
	FILE *fp;
	memset(&u, '\0', sizeof(USER));

	if ((fp = fopen("database\\userdata.dat", "rb+")) == 0)
	{
		printf("cannot open Userdata.dat\n");
		delay(3000);
		exit(1);
	}
	/*	if(u=(USER*)malloc(sizeof(USER))==NULL)
		{
			printf("malloc runs wrong in login.c");
			delay(2000);
			exit(1);
		}*/
	memset(&u, '\0', sizeof(USER));
	strcpy(u.name, name);
	strcpy(u.password, password);
	strcpy(u.id, id);
	strcpy(u.bank, "1111111111111111112");
	strcpy(u.bankpassword, "111112");
	strcpy(u.health_code, "0");
	strcpy(u.hesuan,"0");
	strcpy(u.mileage,"0");
	//	u.health_code=0;
	/*
	   strcpy(u.mileage,"0");*/
	fseek(fp, 0, SEEK_END);
	fwrite(&u, sizeof(USER), 1, fp);
	/*   if(u!=NULL)
	   {
		   free(u);
		   u=NULL;
	   }*/
	if (fclose(fp) != 0)
	{
		printf("cannot close database\n");
		delay(2000);
		exit(1);
	}
}

/***********************************
FUNCTION: lightup_register
DESCRIPTION: 注册界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_register(int x1, int y1, int x2, int y2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(LIGHTRED);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, LIGHTGRAY);

	bar(x1, y1, x2, y2);					   //填充内部
	rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //画边框
	switch (flag)
	{
	case 1:
		break;

	case 2:
	{
		puthz(150, 404, "注册", 24, 46, RED);
		break;
	}

	case 3:
	{
		puthz(420, 404, "返回", 24, 46, RED);
		break;
	}

	default:
		printf("something wrong in loghtup_register\n");
		break;
	}
}

/***********************************
FUNCTION: recoverbuttom_register
DESCRIPTION: 注册界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recoverbuttom_register(int x1, int y1, int x2, int y2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);

	setcolor(LIGHTCYAN);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
	bar(x1, y1, x2, y2);

	switch (flag)
	{
	case 1:
		break;

	case 2:
	{
		puthz(150, 404, "注册", 24, 46, DARKGRAY);
		break;
	}

	case 3:
	{
		puthz(420, 404, "返回", 24, 46, DARKGRAY);
		break;
	}

	default:
	{
		printf("something wrong in recoverbuttom_register\n");
		closegraph();
		exit(1);
	}
	}
}

/***********************************
FUNCTION: register_page
DESCRIPTION: 绘制注册界面
INPUT: 无
RETURN: 无
***********************************/
void register_page(void)
{
	clrmous(MouseX, MouseY);
	delay(10);

	setbkcolor(LIGHTCYAN);

	setcolor(YELLOW);
	ellipse(320, 360, 180, 360, 22, 50);
	arc(320, 360, 180, 360, 90);

	line(230, 360, 230, 210);
	line(298, 360, 298, 210);
	line(298, 210, 230, 210);

	line(410, 360, 410, 210);
	line(342, 360, 342, 210);
	line(342, 210, 410, 210);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(231, 221, YELLOW);

	ellipse(230, 240, 270, 7, 250, 120);
	ellipse(370, 230, 280, 5, 100, 50);
	line(470, 225, 479, 225);

	ellipse(230, 310, 125, 280, 100, 50);
	ellipse(230, 290, 135, 280, 60, 30);
	line(170, 270, 185, 270);

	arc(230, 0, 270, 300, 320);

	floodfill(229, 331, YELLOW);

	floodfill(299, 331, YELLOW);

	floodfill(411, 320, YELLOW);

	setcolor(LIGHTCYAN);
	setlinestyle(0, 0, 1);
	line(0, 100, 100, 0);
	line(0, 150, 150, 0);
	line(0, 150, 0, 100);
	line(100, 0, 150, 0);

	line(0, 180, 180, 0);
	line(0, 230, 230, 0);
	line(0, 180, 0, 230);
	line(180, 0, 230, 0);

	setfillstyle(9, BROWN);
	floodfill(1, 100, LIGHTCYAN);
	floodfill(1, 180, LIGHTCYAN);

	setfillstyle(SOLID_FILL, WHITE);
	puthz(120, 90, "账号", 24, 34, LIGHTBLUE);
	bar(120, 120, 520, 150);

	puthz(120, 160, "密码", 24, 34, LIGHTBLUE);
	bar(120, 190, 520, 220);
	puthz(320, 222, "密码包含的字符至少为", 16, 18, LIGHTRED);
	setcolor(LIGHTRED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(502, 218, "6");

	puthz(120, 230, "确认密码", 24, 34, LIGHTBLUE);
	bar(120, 260, 520, 290);
	// puthz(360,292,"两次输入密码不一致",16,18,LIGHTRED);

	puthz(120, 300, "身份证号", 24, 34, LIGHTBLUE);
	bar(120, 330, 520, 360);

	bar(120, 400, 250, 430);
	puthz(150, 404, "注册", 24, 46, 8);

	bar(390, 400, 520, 430);
	puthz(420, 404, "返回", 24, 46, 8);
}

/***********************************
FUNCTION: exit_buttom
DESCRIPTION: 绘制退出按键
INPUT: 无
RETURN: 无
***********************************/
void exit_buttom(void)
{
	clrmous(MouseX, MouseY);
	delay(10);

	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(595, 0, 640, 20);
	puthz(600, 2, "退出", 16, 18, RED);
}