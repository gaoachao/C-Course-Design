/***********************************
FILE: change2.c
DESCRIPTION: �û����������޸�����
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
#include "login.h"
#include "userpage.h"
#include "change2.h"

/***********************************
FUNCTION: change2_main
DESCRIPTION: ���˽�����������������
INPUT: *func
RETURN: ��
***********************************/
void change2_main(int *func, USER *u)
{
	int num = 0;
	//	char *ttemp;
	int temp = 0;
	int temp2 = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
//	int state4 = 0;
	char new_password[16];
	int state_password = 0; //������¼�����Ƿ��޸ĵ�״̬��

	char password[16]; //�ɵ�����
	char str1[16];	   //�µ�����(ֻ��һ���м���̣�����������Ҫ����new_password)
	char str2[16];	   //�µ�����(�ظ�)
	int flag1;

	memset(password, '\0', sizeof(password));
	memset(str1, '\0', sizeof(str1));
	memset(str2, '\0', sizeof(str2));
	memset(new_password, '\0', sizeof(new_password));

	exit_buttom(); //����˳���ť
				   //	get_time(ttemp); //���ʵʱʱ��
	change2_draw(); //��ø�����Ϣ�޸��������

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		//ʵʱʱ��չʾ
		//		display_time(65, 10, ttemp);

		//��ת����Ʊ��Ϣ����
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
		//��ת��������ؽ���
		//��ת����̬��ѯ����
		//�˳���
		if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
		{
			if (mouse_press(595, 0, 640, 20) == 1)
			{
				*func = 1;
				return;
			}
		}
		//���ص���������
		if (MouseX > 330 && MouseX < 390 && MouseY > 310 && MouseY < 340)
		{
			if (mouse_press(330, 310, 390, 340) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(330, 310, 390, 340) == 1)
			{
				*func = 5;
				return;
			}
		}

		//����ɵ�����
		if (MouseX > 200 && MouseX < 480 && MouseY > 165 && MouseY < 195)
		{
			if (mouse_press(200, 165, 480, 195) == 2)
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)
				{
					lightup_change2(200, 165, 480, 195, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(200, 165, 480, 195) == 1)
			{
				lightup_change2(200, 165, 480, 195, 1);
				memset(password, '\0', sizeof(password)); //ȷ���������
				inputadmin(password, 200, 165, 15, 7);	  //���������
				if (strlen(password) == 0)
				{
					state1 = 0;
				}
				else
					state1 = 1;
			}
		}
		//�����µ�����  	rectangle(200, 210, 480, 240);
		if (MouseX > 200 && MouseX < 480 && MouseY > 210 && MouseY < 240)
		{
			if (mouse_press(200, 210, 480, 240) == 2)
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightup_change2(200, 210, 480, 240, 1);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(200, 210, 480, 240) == 1)
			{
				lightup_change2(200, 210, 480, 240, 1);
				memset(str1, '\0', sizeof(str1));  //ȷ���������
				inputadmin(str1, 200, 210, 15, 7); //����������
				if (strlen(str1) == 0)
				{
					state2 = 0;
				}
				else
					state2 = 1;
			}
		}
		//�����µ�����(�ظ�) 	rectangle(220, 255, 480, 285);
		if (MouseX > 220 && MouseX < 480 && MouseY > 255 && MouseY < 285)
		{
			if (mouse_press(220, 255, 480, 285) == 2)
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightup_change2(220, 255, 480, 285, 1);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(220, 255, 480, 285) == 1)
			{
				lightup_change2(220, 255, 480, 285, 1);
				memset(str2, '\0', sizeof(str2));  //ȷ���������
				inputadmin(str2, 220, 255, 15, 7); //����������
				if (strlen(str2) == 0)
				{
					state3 = 0;
				}
				else
					state3 = 1;
			}
		}
		//�ָ�����
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0 && num == 1)
			{
				recoverbuttom_change2(200, 165, 480, 195, 1);
			}
			if (state2 == 0 && num == 2)
			{
				recoverbuttom_change2(200, 210, 480, 240, 1);
			}
			if (state3 == 0 && num == 3)
			{
				recoverbuttom_change2(220, 255, 480, 285, 1);
			}
			num = 0;
		}
		//ȷ����ť
		if (MouseX > 220 && MouseX < 280 && MouseY > 310 && MouseY < 340)
		{
			if (mouse_press(220, 310, 280, 340) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(220, 310, 280, 340) == 1)
			{
				temp = confirm_password2(str1, str2);
				temp2 = strcmp(password, u->password); //�ɵ����������ݿ�������Ա�
				if (temp2 != 0 && state_password == 0)
				{
					setfillstyle(SOLID_FILL, WHITE);
					bar(490, 165, 640, 195);
					puthz(490, 165, "���������", 16, 18, 6);
				}
				else if (temp2 == 0)
				{
					setfillstyle(SOLID_FILL, WHITE);
					bar(490, 165, 640, 195);
					puthz(490, 165, "��������ȷ", 16, 18, 6);
					if (temp == 1)
					{
						strcpy(new_password, str1);
						input_password(u, new_password);
						clrmous(MouseX, MouseY);
						setfillstyle(SOLID_FILL, WHITE);
						bar(490, 255, 640, 285);
						puthz(490, 315, "�޸�����ɹ�", 16, 18, 6);
						state_password = 1;
					}
					else if (temp != 1)
					{
						clrmous(MouseX, MouseY);
						puthz(490, 255, "���벻һ��", 16, 18, 6);
					}
				}
			}
		}
		//�����������
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/***********************************
FUNCTION: input_password
DESCRIPTION: ���µ�����д�����ݿ�
INPUT:*u
RETURN: ��
***********************************/
void input_password(USER *u, char *new_password)
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
	len = ftell(fp) / sizeof(USER); //�û��ĸ���
	for (i = 0; i < len; i++)
	{
		/*if ((utemp = (USER *)malloc(sizeof(USER))) == NULL)
		{
			printf("malloc runs wrong\n");
			delay(3000);
			exit(1);
		}*/
		memset(&utemp, '\0', sizeof(USER));
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(&utemp, sizeof(USER), 1, fp);
		// fwrite(u,sizeof(USER),1,fp);
		if (strcmp(u->name, utemp.name) == 0)
		{
			strcpy(u->password, new_password);
			fseek(fp, i * sizeof(USER), SEEK_SET);
			fwrite(u, sizeof(USER), 1, fp);
			break;
		}
	}
	/*	if (utemp != NULL)
		{
			free(utemp);
			utemp = NULL;
		}*/
	if (fclose(fp) != 0)
	{
		printf("cannot close database\n");
		delay(2000);
		exit(1);
	}
}

/***********************************
FUNCTION: confirm_password2
DESCRIPTION: �ж���������������Ƿ���ͬ
INPUT: *str1,*str2,x,y
RETURN: 1,����һ�£�0�����벻һ��
***********************************/
int confirm_password2(char *str1, char *str2)
{

	if (strcmp(str1, str2) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/***********************************
FUNCTION: lightup_change2
DESCRIPTION: ����������水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_change2(int x1, int y1, int x2, int y2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, LIGHTGRAY);

	bar(x1, y1, x2, y2);					   //����ڲ�
	rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //���߿�
	switch (flag)
	{
	case 1:
		break;

	case 2:
	{
		puthz(270, 315, "ȷ��", 16, 20, 1);
		break;
	}

	default:
	{
		printf("something wrong in loghtup_change2\n");
		closegraph();
		exit(1);
	}
	}
}

/***********************************
FUNCTION: recoverbuttom_change2
DESCRIPTION: ������Ϣ�޸�������水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recoverbuttom_change2(int x1, int y1, int x2, int y2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);

	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
	bar(x1, y1, x2, y2);

	switch (flag)
	{
	case 1:
		break;

	case 2:
	{
		puthz(100, 414, "��¼", 24, 46, DARKGRAY);
		break;
	}

	case 3:
	{
		puthz(470, 414, "ע��", 24, 46, DARKGRAY);
		break;
	}

	case 4:
	{
		puthz(266, 414, "��������", 24, 28, DARKGRAY);
		break;
	}

	default:
	{
		printf("something wrong in recoverbuttom_change2\n");
		closegraph();
		exit(1);
	}
	}
}

/***********************************
FUNCTION: change2_draw
DESCRIPTION: ������Ϣ�޸��������
INPUT: ��
RETURN: ��
***********************************/
void change2_draw(void)
{
	clrmous(MouseX, MouseY);
	delay(30);
	cleardevice();
	setfillstyle(SOLID_FILL, WHITE);
	bar(0, 0, 640, 480);
	setcolor(DARKGRAY);
	rectangle(60, 0, 640, 60);
	rectangle(0, 0, 60, 60);
	rectangle(200, 165, 480, 195); //�ɵ������
	rectangle(200, 210, 480, 240); //�µ������
	rectangle(220, 255, 480, 285); //ȷ�������
	setfillstyle(SOLID_FILL, GREEN);
	bar(0, 0, 60, 60);
	setfillstyle(SOLID_FILL, RED);
	bar(580, 0, 640, 20);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(220, 310, 280, 340);
	bar(330, 310, 390, 340);
	puthz(65, 20, "�����ݺ�", 32, 35, 4);
	puthz(270, 30, "��Ʊ��Ϣ", 16, 18, 8);
	puthz(360, 30, "��������", 16, 18, 2);
	puthz(450, 30, "�������", 16, 18, 8);
	puthz(540, 30, "��̬��ѯ", 16, 18, 8);
	puthz(110, 220, "�µ����룺", 16, 18, 5);
	puthz(110, 265, "��ȷ�����룺", 16, 18, 5);
	puthz(595, 5, "�˳�", 16, 18, 1);
	puthz(110, 170, "�ɵ����룺", 16, 18, 5);
	puthz(230, 315, "ȷ��", 16, 20, 1);
	puthz(340, 315, "����", 16, 20, 1);
}
