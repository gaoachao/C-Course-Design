/***********************************
FILE: userpage.c
DESCRIPTION: 用户个人中心，包括修改密码、待出行机票查询、个人信息（包括健康状况）显示等功能
***********************************/
#include <stdio.h>
#include <graphics.h>
#include <bios.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "hz.h"
#include "mouse.h"
#include "database.h"
#include "queue.h"
#include "register.h"
#include "buypage.h"
#include "menu.h"
#include "userpage.h"
#include "login.h"

/***********************************
FUNCTION: userpage_main
DESCRIPTION: 机票界面主函数
INPUT: *func
RETURN: 无
***********************************/
void userpage_main(int *func, USER *u)
{
	int num = 0;
	char health_code[2];
	memset(health_code, '\0', sizeof(health_code));

	userinfo_read(u);
	//出现用户个人中心界面
	userpage_draw();
	//退出按钮
	exit_buttom();
	//获得实时时间
	//	get_time(ttemp);
	//获取基本信息
	get_userinfo(u);

	//刚进入页面进行一次健康状态的判断
	if (strcmp(u->health_code, "1") == 0)
	{
		clrmous(MouseX, MouseY);
		setcolor(DARKGRAY);
		line(182, 167, 190, 178);
		line(190, 178, 202, 159);
	}
	else if (strcmp(u->health_code, "2") == 0)
	{
		clrmous(MouseX, MouseY);
		setcolor(DARKGRAY);
		line(282, 167, 290, 178);
		line(290, 178, 302, 159);
	}
	else if (strcmp(u->health_code, "3") == 0)
	{
		clrmous(MouseX, MouseY);
		setcolor(DARKGRAY);
		line(382, 167, 390, 178);
		line(390, 178, 402, 159);
	}

	//刚进入页面进行一次核酸结果的判断
	if (strcmp(u->hesuan, "1") == 0)
	{
		puthz(180, 190, "阴性", 16, 18, 8);
	}
	else if (strcmp(u->hesuan, "2") == 0)
	{
		puthz(180, 190, "阳性", 16, 18, 8);
	}
	else
	{
		puthz(180, 190, "未上报", 16, 18, 8);
	}

	//鼠标操作
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//实时时间展示
		//		display_time(65, 10, ttemp);
		//选中绿码
		if (MouseX > 140 && MouseX < 205 && MouseY > 155 && MouseY < 180)
		{
			if (mouse_press(140, 155, 205, 180) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(140, 155, 205, 180) == 1)
			{
				strcpy(health_code, "1");
				input_healthcode(u, health_code);
				clrmous(MouseX, MouseY);
				setfillstyle(SOLID_FILL, WHITE);
				bar(280, 155, 305, 180);
				bar(380, 155, 405, 180);
				setcolor(DARKGRAY);
				line(182, 167, 190, 178);
				line(190, 178, 202, 159);
				setcolor(DARKGRAY);
				rectangle(280, 155, 305, 180);
				rectangle(380, 155, 405, 180);
				//	outtextxy(1,1,u->health_code);
			}
		}
		//选中黄码
		if (MouseX > 240 && MouseX < 305 && MouseY > 155 && MouseY < 180)
		{
			if (mouse_press(240, 155, 405, 180) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(240, 155, 405, 180) == 1)
			{
				strcpy(health_code, "2");
				input_healthcode(u, health_code);
				clrmous(MouseX, MouseY);
				setfillstyle(SOLID_FILL, WHITE);
				bar(180, 155, 205, 180);
				bar(380, 155, 405, 180);
				setcolor(DARKGRAY);
				line(282, 167, 290, 178);
				line(290, 178, 302, 159);
				setcolor(DARKGRAY);
				rectangle(180, 155, 205, 180);
				rectangle(380, 155, 405, 180);
			}
		}
		//选中红码
		if (MouseX > 340 && MouseX < 405 && MouseY > 155 && MouseY < 180)
		{
			if (mouse_press(340, 155, 405, 180) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(340, 155, 405, 180) == 1)
			{
				strcpy(health_code, "3");
				input_healthcode(u, health_code);
				clrmous(MouseX, MouseY);
				setfillstyle(SOLID_FILL, WHITE);
				bar(280, 155, 305, 180);
				bar(180, 155, 205, 180);
				setcolor(DARKGRAY);
				line(382, 167, 390, 178);
				line(390, 178, 402, 159);
				setcolor(DARKGRAY);
				rectangle(280, 155, 305, 180);
				rectangle(180, 155, 205, 180);
			}
		}
		//跳转至机票信息界面
		if (MouseX > 270 && MouseX < 350 && MouseY > 10 && MouseY < 60)
		{
			if (mouse_press(270, 10, 350, 60) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(270, 10, 350, 60) == 1)
			{
				*func = 4;
				return;
			}
		}
		//跳转至疫情防控界面
		if (MouseX > 450 && MouseX < 530 && MouseY > 10 && MouseY < 60)
		{
			if (mouse_press(450, 10, 530, 60) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(450, 10, 530, 60) == 1)
			{
				*func = 8;
				return;
			}
		}

		//跳转至动态查询界面

		//跳转至修改密码界面
		if (MouseX > 520 && MouseX < 640 && MouseY > 70 && MouseY < 100)
		{
			if (mouse_press(520, 70, 640, 100) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_userpage(510, 82, 600, 94, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(520, 70, 640, 100) == 1)
			{
				*func = 6;
				return;
			}
		}
		//跳转历史机票查询界面

		//跳转酒店订购界面
		if (MouseX > 520 && MouseX < 640 && MouseY > 130 && MouseY < 160)
		{
			if (mouse_press(520, 130, 640, 160) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_userpage(510, 142, 600, 154, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(520, 130, 640, 160) == 1)
			{
				*func = 11;
				return;
			}
		}

		//酒店查询
		if (MouseX > 520 && MouseX < 640 && MouseY > 160 && MouseY < 190)
		{
			if (mouse_press(520, 160, 640, 190) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_userpage(510, 172, 600, 184, 4);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(520, 160, 640, 190) == 1)
			{
				*func = 23;
				return;
			}
		}

		//跳转至我的卡包界面
		if (MouseX > 520 && MouseX < 640 && MouseY > 190 && MouseY < 218)
		{
			if (mouse_press(520, 190, 640, 218) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_userpage(510, 202, 600, 214, 5);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(520, 190, 640, 218) == 1)
			{
				*func = 13;
				return;
			}
		}
		//退出登录功能切换账号的实现
		if (MouseX > 520 && MouseX < 640 && MouseY > 225 && MouseY < 260)
		{
			if (mouse_press(520, 225, 640, 260) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_userpage(510, 232, 600, 244, 6);
					num = 6;
				}
				continue;
			}
			else if (mouse_press(520, 225, 640, 260) == 1)
			{
				memset(u, '\0', sizeof(USER));
				*func = 0;
				return;
			}
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

		if (num != 0)
		{
			if (num == 1)
			{
				recover_usepage(510, 70, 640, 100, 1);
			}
			if (num == 2)
			{
				recover_usepage(510, 100, 640, 130, 2);
			}
			if (num == 3)
			{
				recover_usepage(510, 130, 640, 160, 3);
			}
			if (num == 4)
			{
				recover_usepage(510, 160, 640, 190, 4);
			}
			if (num == 5)
			{
				recover_usepage(510, 190, 640, 220, 5);
			}
			if (num == 6)
			{
				recover_usepage(510, 220, 640, 250, 6);
			}
			num = 0;
		}

		//调整鼠标手势
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*****************************
FUNCTION: get_userinfo
DESCRIPTION: 个人页面获取基本信息
INPUT: u
RETURN: 无
*****************************/
void get_userinfo(USER *u)
{
	settextjustify(LEFT_TEXT, TOP_TEXT); //设置文本对齐方式
	settextstyle(2, 0, 7);
	setcolor(DARKGRAY);
	outtextxy(145, 95, u->name);
	outtextxy(145, 125, u->id);
	outtextxy(145, 215, u->mileage);
}

/***********************************
FUNCTION: input_healthcode
DESCRIPTION: 将健康码状态写入数据库
INPUT:*u
RETURN: 无
***********************************/
void input_healthcode(USER *u, char *health_code)
{
	USER utemp;
	FILE *fp;
	int i, len;

	if ((fp = fopen("database\\userdata.dat", "rb+")) == NULL)
	{
		printf("cannot open file userdata\n");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER); //用户的个数
	for (i = 0; i < len; i++)
	{
		memset(&utemp, '\0', sizeof(USER));
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(&utemp, sizeof(USER), 1, fp);
		if (strcmp(u->name, utemp.name) == 0 && strcmp(u->password, utemp.password) == 0)
		{
			strcpy(u->health_code, health_code);
			fseek(fp, i * sizeof(USER), SEEK_SET);
			fwrite(u, sizeof(USER), 1, fp);
			break;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("cannot close database\n");
		delay(2000);
		exit(1);
	}
}
/***********************************
FUNCTION: lightup_userpage
DESCRIPTION: 个人中心按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_userpage(int x1, int y1, int x2, int y2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, LIGHTGRAY);
	bar(x1, y1, x2, y2);
	switch (flag)
	{
	case 1:
	{
		puthz(520, 80, "密码修改", 16, 18, 5);
		break;
	}
	case 2:
	{
		puthz(520, 110, "购票记录", 16, 18, 5);
		break;
	}
	case 3:
	{
		puthz(520, 140, "酒店订购", 16, 18, 5);
		break;
	}
	case 4:
	{
		puthz(520, 170, "酒店查询", 16, 18, 5);
		break;
	}
	case 5:
	{
		puthz(520, 200, "我的卡包", 16, 18, 5);
		break;
	}
	case 6:
	{
		puthz(520, 230, "退出登录", 16, 18, 5);
		break;
	}

	default:
	{
		printf("something wrong in lightup_userpage\n");
		closegraph();
		exit(1);
	}
	}
}

/***********************************
FUNCTION: recover_userpage
DESCRIPTION: 个人中心点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recover_usepage(int x1, int y1, int x2, int y2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(SOLID_FILL, WHITE);
	bar(x1, y1, x2, y2);
	switch (flag)
	{
	case 1:
	{
		puthz(520, 80, "密码修改", 16, 18, 5);
		break;
	}
	case 2:
	{
		puthz(520, 110, "购票记录", 16, 18, 5);
		break;
	}
	case 3:
	{
		puthz(520, 140, "酒店订购", 16, 18, 5);
		break;
	}
	case 4:
	{
		puthz(520, 170, "酒店查询", 16, 18, 5);
		break;
	}
	case 5:
	{
		puthz(520, 200, "我的卡包", 16, 18, 5);
		break;
	}
	case 6:
	{
		puthz(520, 230, "退出登录", 16, 18, 5);
		break;
	}

	default:
	{
		printf("something wrong in recover_userpage\n");
		closegraph();
		exit(1);
	}
	}
}

/***********************************
FUNCTION: userpage_draw
DESCRIPTION: 购票界面
INPUT: 无
RETURN: 无
***********************************/
void userpage_draw(void)
{
	clrmous(MouseX, MouseY);
	cleardevice();
	setfillstyle(SOLID_FILL, WHITE);
	bar(0, 0, 640, 480);
	setcolor(DARKGRAY);
	rectangle(60, 0, 640, 60);
	rectangle(0, 0, 60, 60);
	line(0, 260, 640, 260);
	line(500, 60, 500, 260);
	setfillstyle(SOLID_FILL, GREEN);
	bar(0, 0, 60, 60);
	//健康码选择，增强交互性
	setcolor(DARKGRAY);
	rectangle(180, 155, 205, 180);
	rectangle(280, 155, 305, 180);
	rectangle(380, 155, 405, 180);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(595, 0, 640, 20);
	puthz(600, 2, "退出", 16, 18, RED);
	puthz(65, 20, "航旅纵横", 32, 35, 4);
	puthz(270, 30, "机票信息", 16, 18, 8);
	puthz(360, 30, "个人中心", 16, 18, 2);
	puthz(450, 30, "疫情防控", 16, 18, 8);
	puthz(540, 30, "动态查询", 16, 18, 8);
	puthz(40, 190, "核酸检测结果：", 16, 18, 9);
	puthz(40, 220, "总里程数：", 16, 18, 9);
	puthz(20, 270, "待出行机票信息：", 16, 18, 6);
	puthz(20, 70, "个人信息：", 16, 18, 6);
	puthz(40, 100, "用户姓名：", 16, 18, 9);
	puthz(40, 130, "身份证号：", 16, 18, 9);
	puthz(40, 160, "健康状态：", 16, 18, 9);
	puthz(140, 160, "绿码", 16, 18, 2);
	puthz(240, 160, "黄码", 16, 18, 6);
	puthz(340, 160, "红码", 16, 18, 4);
	puthz(520, 80, "密码修改", 16, 18, 5);
	puthz(520, 110, "购票记录", 16, 18, 5);
	puthz(520, 140, "酒店订购", 16, 18, 5);
	puthz(520, 170, "酒店查询", 16, 18, 5);
	puthz(520, 200, "我的卡包", 16, 18, 5);
	puthz(520, 230, "退出登录", 16, 18, 5);
}

//鼠标形状Shape 1为手势，2为光标，3为十字

/* 1 蓝色
	 2 绿色
	 3 青色
	 4 红色
	 5 梅红色
	 6 棕黄色（偏金）
	 7 淡灰色
	 8 深灰色
	 9 深蓝色
*/