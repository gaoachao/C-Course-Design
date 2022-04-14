#include "hz.h"
#include <stdio.h>
#include <dos.h>
#include <bios.h>
#include <stdlib.h>
#include <graphics.h>
#include "database.h"
#include <string.h>
#include <time.h>
#include "mouse.h"
#include "login.h"
#include "database.h"
#include "register.h"

/***********************************
FUNCTION: login_main
DESCRIPTION: ��¼������
INPUT: *func,*u
RETURN: ��
***********************************/
void login_main(int *func, USER *u)
{
	int num = 0;
	char str[5];   //��֤��
	char vcode[5]; //��֤������������
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();

	memset(str, '\0', sizeof(str));
	memset(u, '\0', sizeof(USER));

	login_page();
	exit_buttom();
	vertification_code(450, 340, 520, 370, DARKGRAY, str); //������֤��

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//�˺���
		if (MouseX > 120 && MouseX < 520 && MouseY > 160 && MouseY < 190)
		{
			if (mouse_press(120, 160, 520, 190) == 2) //�˺������δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)
				{

					lightup_login(120, 160, 520, 190, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(120, 160, 520, 190) == 1)
			{
				MouseS = 1;
				lightup_login(120, 160, 520, 190, 1);
				memset(u->name, '\0', sizeof(u->name));
				inputadmin(u->name, 120, 160, 15, 7);
				if (strlen(u->name) == 0)
				{
					state1 = 0;
				}
				else
					state1 = 1;
			}
		}

		//������
		if (MouseX > 120 && MouseX < 520 && MouseY > 250 && MouseY < 280)
		{
			if (mouse_press(120, 250, 520, 280) == 2) //���������δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightup_login(120, 250, 520, 280, 1);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(120, 250, 520, 280) == 1)
			{
				MouseS = 1;
				lightup_login(120, 250, 520, 280, 1);
				memset(u->password, '\0', sizeof(u->password));
				inputpassword(u->password, 120, 250, 15, LIGHTGRAY);
				if (strlen(u->password) == 0)
				{
					state2 = 0;
				}
				else
					state2 = 1;
			}
		}

		//��֤����
		if (MouseX > 120 && MouseX < 470 && MouseY > 340 && MouseY < 370)
		{
			if (mouse_press(120, 340, 450, 370) == 2) //��֤�������δ���
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightup_login(120, 340, 450, 370, 1);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(120, 340, 450, 370) == 1)
			{
				MouseS = 1;
				lightup_login(120, 340, 450, 370, 1);
				memset(vcode, '\0', sizeof(vcode));
				inputadmin(vcode, 120, 340, 4, LIGHTGRAY);
				if (strlen(vcode) == 0)
				{
					state3 = 0;
				}
				else
					state3 = 1;
			}
		}

		if (MouseX > 450 && MouseX < 520 && MouseY > 340 && MouseY < 370)
		{
			if (mouse_press(450, 340, 520, 370) == 1)
			{
				MouseS = 1;
				vertification_code(450, 340, 520, 370, DARKGRAY, str);
				continue;
			}
		}

		//��¼��ť
		if (MouseX > 70 && MouseX < 200 && MouseY > 410 && MouseY < 440)
		{
			if (mouse_press(70, 410, 200, 440) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_login(70, 410, 200, 440, 2);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(70, 410, 200, 440) == 1)
			{
				MouseS = 1;
				if (login_judge(u, str, vcode) == 1)
				{

					puthz(260, 380, "��½�ɹ�", 24, 30, GREEN);
					userinfo_read(u);
					*func = 4;
					/*	printf("%s\n", u->name);
						printf("%s\n", u->id);
						printf("%s\n", u->health_code);
						printf("%s\n", u->bank);*/
					delay(3000);
					return;
				}
				else
				{
					//	printf("login_judge=0\n");
					continue;
				}
			}
		}

		//ע�ᰴť
		if (MouseX > 440 && MouseX < 570 && MouseY > 410 && MouseY < 440)
		{
			if (mouse_press(440, 410, 570, 440) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_login(440, 410, 570, 440, 3);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(440, 410, 570, 440) == 1)
			{
				*func = 2;
				return;
			}
		}

		//���������
		if (MouseX > 255 && MouseX < 3850 && MouseY > 410 && MouseY < 440)
		{
			if (mouse_press(255, 410, 385, 440) == 2)
			{
				MouseS = 1;
				if (num == 0)
				{
					lightup_login(255, 410, 385, 440, 4);
					num = 6;
				}
				continue;
			}
			else if (mouse_press(255, 410, 385, 440) == 1)
			{
				*func = 3;
				return;
			}
		}

		//�˳���
		if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
		{
			if (mouse_press(595, 0, 640, 20) == 1)
			{
				*func = 1;
				return;
			}
		}

		//�ָ�����
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0 && num == 1)
			{
				recoverbuttom_login(120, 160, 520, 190, 1);
			}
			if (state2 == 0 && num == 2)
			{
				recoverbuttom_login(120, 250, 520, 280, 1);
			}
			if (state3 == 0 && num == 3)
			{
				recoverbuttom_login(120, 340, 450, 370, 1);
			}
			if (num == 4)
			{
				recoverbuttom_login(70, 410, 200, 440, 2);
			}
			if (num == 5)
			{
				recoverbuttom_login(440, 410, 570, 440, 3);
			}
			if (num == 6)
			{
				recoverbuttom_login(255, 410, 385, 440, 4);
			}
			num = 0;
		}

		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/***********************************
FUNCTION: login_judge
DESCRIPTION: �ж��Ƿ���Ե�¼
INPUT: *str,x,y
RETURN: 1(���Ե�¼)/0(���ܵ�¼)
***********************************/
int login_judge(USER *u, char *str, char *vcode)
{
	int state = 0;
	int state1;
	int state2;
	//	int state3;

	state += input_judge(u->name, 522, 160);
	state += input_judge(u->password, 522, 250);
	state += input_judge(vcode, 522, 340);

	if (state == 3)
	{
		state1 = name_password_login(u->name, u->password);
		state2 = vcode_judge(str, vcode);
		//	printf("state1=%d,state2=%d",state1,state2);
		if (state1 == 1 && state2 == 1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

/***********************************
FUNCTION: userinfo_read
DESCRIPTION: �����ݿ��ȡ�û���Ϣ
INPUT: *u
RETURN: ��
***********************************/
void userinfo_read(USER *u)
{
	FILE *fp;
	USER utemp;
	int i, len;

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
		memset(&utemp,'\0',sizeof(USER));
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(&utemp, sizeof(USER), 1, fp);
		if (strcmp(u->name, utemp.name) == 0 && strcmp(u->password, utemp.password) == 0)
		{
			strcpy(u->id, utemp.id);
			strcpy(u->health_code, utemp.health_code);
			strcpy(u->bank, utemp.bank);
			strcpy(u->bankpassword, utemp.bankpassword);
			strcpy(u->hesuan,utemp.hesuan);
			strcpy(u->mileage,utemp.mileage);

			if (fclose(fp) != 0)
			{
				printf("database cannot be closed\n");
				delay(3000);
				exit(1);
			}
			return;
		}
	}
	if (len == i)
	{
		printf("user informain read failed\n");
	}

	if (fclose(fp) != 0)
	{
		printf("database cannot be closed\n");
		delay(3000);
		exit(1);
	}
}

/***********************************
FUNCTION: input_judge
DESCRIPTION: �ж���������Ƿ�����������
INPUT: *str,x,y
RETURN: 1/0
***********************************/
int input_judge(char *str, int x, int y)
{
	if (strlen(str) == 0)
	{
		clrmous(MouseX, MouseY);
		delay(10);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(x, y, x + 100, y + 30);
		puthz(x, y + 2, "δ����", 16, 18, RED);
		return 0;
	}
	else
	{
		clrmous(MouseX, MouseY);
		delay(10);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(x, y, x + 100, y + 30);
		return 1;
	}
}

/***********************************
FUNCTION: vcodelogin
DESCRIPTION: �ж���֤���Ƿ���ȷ
INPUT: *str,*vcode
RETURN: 1(���Ե�¼)/0(�����Ե�¼)
***********************************/
int vcode_judge(char *str, char *vcode)
{
	if (strcmp(str, vcode) == 0) //��֤����ȷ
	{
		//�ڵ���������
		clrmous(MouseX, MouseY);
		delay(10);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(522, 340, 522 + 100, 370);

		//���Թ�
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3);
		line(522 + 3, 340 + 10, 522 + 13, 340 + 20);
		line(522 + 13, 340 + 20, 522 + 23, 340);
		return 1;
	}
	else //��֤�����
	{
		//�ڵ���������
		clrmous(MouseX, MouseY);
		delay(10);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(522, 340, 522 + 100, 370);

		puthz(522, 343, "��֤�����", 16, 18, RED);
		return 0;
	}
}

/***********************************
FUNCTION: name_password_login
DESCRIPTION: �ж��û����Ƿ���ڼ������Ƿ���ȷ
INPUT: *name,*password
RETURN: 1(���Ե�¼)/0(�����Ե�¼)
***********************************/
int name_password_login(char *name, char *password)
{
	USER u;
	FILE *fp;
	int i, len;

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
		/*if ((u = (USER *)malloc(sizeof(USER))) == NULL)
		{
			printf("malloc runs wrong\n");
			delay(3000);
			exit(1);
		}*/
		memset(&u,'\0',sizeof(USER));
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(&u, sizeof(USER), 1, fp);
		if (strcmp(name, u.name) == 0) //�ҵ���Ӧ���û���
		{
			//�ڵ���������
			clrmous(MouseX, MouseY);
			delay(10);
			setfillstyle(SOLID_FILL, LIGHTCYAN);
			bar(522, 160, 522 + 100, 190);

			//���Թ�
			setcolor(GREEN);
			setlinestyle(SOLID_LINE, 0, 3);
			line(522 + 3, 160 + 10, 522 + 13, 160 + 20);
			line(522 + 13, 160 + 20, 522 + 23, 160);

			//���벻��ȷ
			if (strcmp(password, u.password) != 0)
			{
				//�ڵ���������
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(SOLID_FILL, LIGHTCYAN);
				bar(522, 250, 522 + 100, 280);

				puthz(522, 250, "�������", 16, 18, RED);
				/*if (u != NULL)
				{
					free(u);
					u = NULL;
				}*/
				if (fclose(fp) != 0)
				{
					printf("database cannot be closed\n");
					delay(3000);
					exit(1);
				}
				return 0;
			}
			else
			//������ȷ
			{
				//�ڵ���������
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(SOLID_FILL, LIGHTCYAN);
				bar(522, 250, 522 + 100, 250);

				//���Թ�
				setcolor(GREEN);
				setlinestyle(SOLID_LINE, 0, 3);
				line(522 + 3, 250 + 10, 522 + 13, 250 + 20);
				line(522 + 13, 250 + 20, 522 + 23, 250);

				// puthz(260,400,"��½�ɹ�",24,30,RED);
			/*	if (u != NULL)
				{
					free(u);
					u = NULL;
				}*/
				if (fclose(fp) != 0)
				{
					printf("database cannot be closed\n");
					delay(3000);
					exit(1);
				}
				return 1;
			}
		}
	}

	//δע��
	if (i == len)
	{
		//�ڵ���������
		clrmous(MouseX, MouseY);
		delay(10);
		setfillstyle(SOLID_FILL, LIGHTCYAN);
		bar(522, 250, 522 + 100, 250);
		puthz(522, 162, "�û�δע��", 16, 18, RED);
	}
/*	if (u != NULL)
	{
		free(u);
		u = NULL;
	}*/
	if (fclose(fp) != 0)
	{
		printf("database cannot be closed\n");
		delay(3000);
		exit(1);
	}
	return 0;
}

/***********************************
FUNCTION: inputadmin
DESCRIPTION: ��ʾ�������ݵ����빦��
INPUT: *id ��Ҫ������ַ�����x��y��charnum ���������ַ���
RETURN: ��
***********************************/
void inputadmin(char *id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);
	}
	while (1)
	{
		t = bioskey(0);
		if (i < charnum)
		{
			if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 - 1, id + i);				 //���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0) //�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //�ڸ�����
					i--;													   //����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
				else
				{
					setfillstyle(SOLID_FILL, color);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					break;
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
			{
				if (t == '\b' && i > 0) //�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //�ڸ�����
					i--;													   //����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
				break;
			}
		}
	}
}

/***********************************
FUNCTION: inputpassword
DESCRIPTION: ����ʾ�������ݵ����빦��
INPUT: *id ��Ҫ������ַ�����x��y��charnum ���������ַ���
RETURN: ��
***********************************/
void inputpassword(char *id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);
	}
	while (1)
	{
		t = bioskey(0);
		if (i < charnum)
		{
			if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 + 2, "*");				 //���*�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0) //�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //�ڸ�����
					i--;													   //����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
				else
				{
					setfillstyle(SOLID_FILL, color);
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					break;
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
			{
				if (t == '\b' && i > 0) //�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //�ڸ�����
					i--;													   //����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
				break;
			}
		}
	}
}

/***********************************
FUNCTION: vertification_code
DESCRIPTION: ������֤��
INPUT: x1,y1,x2,y2,color
RETURN: ��
***********************************/
void vertification_code(int x1, int y1, int x2, int y2, int color, char *str)
{
	int i, j;
	char a;

	srand(time(NULL));
	for (i = 0; i < 4; i++)
	{

		j = rand() % 3;
		if (j == 0)
		{
			a = rand() % 26 + 65;
			str[i] = a;
		}
		else if (j == 1)
		{
			a = rand() % 26 + 97;
			str[i] = a;
		}
		else
		{
			a = rand() % 10 + 48;
			str[i] = a;
		}
	}

	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(SOLID_FILL, color);
	// bar(450,340,520,370);
	bar(x1 + 1, y1, x2, y2);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	setcolor(BLUE);
	outtextxy(x1 + 10, y1 + 2, str);
}

/***********************************
FUNCTION: login_page
DESCRIPTION: ���Ƶ�¼��������
INPUT: ��
RETURN: ��
***********************************/
void login_page(void)
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

	puthz(180 + 2, 70 + 2, "�����ݺṺƱϵͳ", 32, 36, RED);
	puthz(180, 70, "�����ݺṺƱϵͳ", 32, 36, LIGHTRED);

	puthz(120, 130, "�˺�", 24, 34, LIGHTBLUE);
	bar(120, 160, 520, 190);

	puthz(120, 220, "����", 24, 34, LIGHTBLUE);
	bar(120, 250, 520, 280);

	bar(70, 410, 200, 440);
	puthz(100, 414, "��¼", 24, 46, 8);
	bar(440, 410, 570, 440);
	puthz(470, 414, "ע��", 24, 46, 8);
	bar(255, 410, 385, 440);
	puthz(266, 414, "��������", 24, 28, 8);

	puthz(120, 310, "��֤��", 24, 34, LIGHTBLUE);
	bar(120, 340, 450, 370);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(450, 340, 520, 370);
	setcolor(RED);
	rectangle(450, 339, 521, 371);
}

/***********************************
FUNCTION: lightup_login
DESCRIPTION: ��¼���水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_login(int x1, int y1, int x2, int y2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(LIGHTRED);
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
		puthz(100, 414, "��¼", 24, 46, RED);
		break;
	}

	case 3:
	{
		puthz(470, 414, "ע��", 24, 46, RED);
		break;
	}

	case 4:
	{
		puthz(266, 414, "��������", 24, 28, RED);
		break;
	}

	default:
	{
		printf("something wrong in loghtup_login\n");
		closegraph();
		exit(1);
	}
	}
}

/***********************************
FUNCTION: recoverbuttom_login
DESCRIPTION: ��¼���水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recoverbuttom_login(int x1, int y1, int x2, int y2, int flag)
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
		printf("something wrong in recoverbuttom_login\n");
		closegraph();
		exit(1);
	}
	}
}
