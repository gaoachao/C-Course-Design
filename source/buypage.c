/***********************************
FILE: buypage.c
DESCRIPTION: ѡƱ����Դ�ļ���������Ʊ��������Ʊչʾ�ͻ�Ʊѡ����
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
#include "purchase.h"

/***********************************
FUNCTION: buypage_main
DESCRIPTION: ��Ʊ����������
INPUT: *func
RETURN: ��
***********************************/
void buypage_main(int *func, Ticket *t)
{
	int i, j, prepage = 0;

	int key;
	char ttemp[40] = "\0";
	int len, page_num, page_rest;
	//	int state[MaxSize];
	int state1 = 0;
	int state2 = 0;
	int click_state = 0;
	//	int state3=0;
	int decity = 0, laucity = 0;
	char date[3];
	TNode node;				 //��Ʊ�ڵ�
	Ticket t_list[List_len]; //��Ʊ��Ϣ����
	char *city[] = {
		"����", "�Ϻ�", "����", "�ɶ�",
		"����", "����", "����", "����",
		"����", "�Ͼ�", "�人", "���"};
	memset(date, '\0', sizeof(date));

	memset(t, '\0', sizeof(Ticket));

	memset(t_list,'\0',sizeof(Ticket)*List_len);

	buypage_draw();
	exit_buttom();
	get_time(ttemp);

	initQueue(&node); //��Ʊ���г�ʼ��

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		display_time(65, 10, ttemp);

		//�������Ʒ�ҳ
		if (kbhit())
		{
			key = bioskey(0);
			if (key == Key_Down)
			{
				if (strlen(t_list[0].number) != 0)
				{
					ticket_cover();

					queue_down(&prepage, page_num);
					//	queue_up(&prepage,page_num);
					enqueue(&node, t_list, prepage);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}
			}
			if (key == Key_Up)
			{
				if (strlen(t_list[0].number) != 0)
				{
					ticket_cover();

					queue_up(&prepage, page_num);
					//	queue_up(&prepage,page_num);
					enqueue(&node, t_list, prepage);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}
			}
		}

		//�������ҳ
		//��һҳ
		if (MouseX > 540 && MouseX < 600 && MouseY > 450 && MouseY < 470)
		{
			if (mouse_press(540, 450, 600, 470) == 2)
			{
				MouseS = 1;
			}

			if (mouse_press(540, 450, 600, 470) == 1)
			{
				if (strlen(t_list[0].number) != 0)
				{
					ticket_cover();

					queue_down(&prepage, page_num);
					//	queue_up(&prepage,page_num);
					enqueue(&node, t_list, prepage);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}
			}
		}

		//��һҳ
		if (mouse_press(40, 450, 100, 470) == 1)
		{
			if (strlen(t_list[0].number) != 0)
			{
				ticket_cover();

				queue_up(&prepage, page_num);
				//	queue_up(&prepage,page_num);
				enqueue(&node, t_list, prepage);
				if (prepage + 1 < page_num)
				{
					ticket_display(&node, 1, page_rest);
					delay(100);
				}
				else if (prepage + 1 == page_num)
				{
					ticket_display(&node, 2, page_rest);
					delay(100);
				}
			}
		}

		//������ѡ��
		if (MouseX > 60 && MouseX < 210 && MouseY > 100 && MouseY < 130)
		{
			if (mouse_press(60, 100, 210, 130) == 2)
			{
				MouseS = 1;
				if (state1 == 0 && state2 == 0)
				{
					city_select_lightup(60, 100, 60 + 150, 100 + 30);
					state1 = 1;
				}
				continue;
			}
			else if (mouse_press(60, 100, 210, 130) == 1)
			{
				MouseS = 1;
				if (state2 == 0) //���˵�δչ��
				{
					city_select_page(60, 134);
					state2 = 1;
					delay(100);
				}
				else if (state2 == 1) //���˵���չ��
				{
					ticket_cover();
					state2 = 0;
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
					delay(100);
				}
			}
		}
		//�����س���������
		if (state2 == 1)
		{
			if (MouseX > 60 && MouseX < 60 + 300 && MouseY > 134 && MouseY < 134 + 140)
			{
				//����
				if (mouse_press(60 + 20 + 70 * 0, 134 + 20 + 40 * 0, 60 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*0,134+20+40*0,220+20+70*0+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 0, 134 + 20 + 40 * 0, 60 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					laucity = 1; //����1
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�Ϻ�
				if (mouse_press(60 + 20 + 70 * 1, 134 + 20 + 40 * 0, 60 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*1,134+20+40*0,220+20+70*1+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 1, 134 + 20 + 40 * 0, 60 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					laucity = 2; //����2
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(60 + 20 + 70 * 2, 134 + 20 + 40 * 0, 60 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*2,134+20+40*0,220+20+70*2+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 2, 134 + 20 + 40 * 0, 60 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					laucity = 3; //����3
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�ɶ�
				if (mouse_press(60 + 20 + 70 * 3, 134 + 20 + 40 * 0, 60 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*3,134+20+40*0,220+20+70*3+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 3, 134 + 20 + 40 * 0, 60 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					laucity = 4; //����4
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(60 + 20 + 70 * 0, 134 + 20 + 40 * 1, 60 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*0,134+20+40*0,220+20+70*0+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 0, 134 + 20 + 40 * 1, 60 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					laucity = 5; //����5
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(60 + 20 + 70 * 1, 134 + 20 + 40 * 1, 60 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*1,134+20+40*0,220+20+70*1+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 1, 134 + 20 + 40 * 1, 60 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					laucity = 6; //����6
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(60 + 20 + 70 * 2, 134 + 20 + 40 * 1, 60 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*2,134+20+40*0,220+20+70*2+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 2, 134 + 20 + 40 * 1, 60 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					laucity = 7; //����7
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(60 + 20 + 70 * 3, 134 + 20 + 40 * 1, 60 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*3,134+20+40*0,220+20+70*3+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 3, 134 + 20 + 40 * 1, 60 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					laucity = 8; //����8
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(60 + 20 + 70 * 0, 134 + 20 + 40 * 2, 60 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;

					continue;
					//	city_select_lightup(220+20+70*0,134+20+40*0,220+20+70*0+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 0, 134 + 20 + 40 * 2, 60 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					laucity = 9; //����9
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�Ͼ�
				if (mouse_press(60 + 20 + 70 * 1, 134 + 20 + 40 * 2, 60 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*1,134+20+40*0,220+20+70*1+50,134+20+40*0+20);
				}
				else if (mouse_press(60 + 20 + 70 * 1, 134 + 20 + 40 * 2, 60 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					laucity = 10; //����10
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�人
				if (mouse_press(60 + 20 + 70 * 2, 134 + 20 + 40 * 2, 60 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;
					//	city_select_lightup(220+20+70*2,134+20+40*0,220+20+70*2+50,134+20+40*0+20);
					continue;
				}
				else if (mouse_press(220 + 20 + 70 * 2, 134 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					laucity = 11; //����11
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//���
				if (mouse_press(60 + 20 + 70 * 3, 134 + 20 + 40 * 2, 60 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;
					//	city_select_lightup(220+20+70*3,134+20+40*0,220+20+70*3+50,134+20+40*0+20);
					continue;
				}
				else if (mouse_press(60 + 20 + 70 * 3, 134 + 20 + 40 * 2, 60 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					laucity = 12; //����12
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(61, 101, 209, 129);
					puthz(75, 109, city[laucity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}
			}
		}

		//Ŀ�ĵ�ѡ��
		if (MouseX > 220 && MouseX < 370 && MouseY > 100 && MouseY < 130)
		{
			if (mouse_press(220, 100, 370, 130) == 2)
			{
				MouseS = 1;
				if (state1 == 0 && state2 == 0)
				{
					city_select_lightup(220, 100, 220 + 150, 100 + 30);
					state1 = 2;
				}
				continue;
			}
			else if (mouse_press(220, 100, 370, 130) == 1)
			{
				MouseS = 1;
				if (state2 == 0)
				{
					city_select_page(220, 134);
					state2 = 2;
					delay(100);
				}
				else if (state2 == 2)
				{
					ticket_cover();
					state2 = 0;

					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
					delay(100);
				}
			}
		}

		//Ŀ�ĵس���������
		if (state2 == 2)
		{
			if (MouseX > 220 && MouseX < 220 + 300 && MouseY > 134 && MouseY < 134 + 140)
			{
				//����
				if (mouse_press(220 + 20 + 70 * 0, 134 + 20 + 40 * 0, 220 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*0,134+20+40*0,220+20+70*0+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 0, 134 + 20 + 40 * 0, 220 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					decity = 1; //����1
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�Ϻ�
				if (mouse_press(220 + 20 + 70 * 1, 134 + 20 + 40 * 0, 220 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*1,134+20+40*0,220+20+70*1+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 1, 134 + 20 + 40 * 0, 220 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					decity = 2; //����2
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(220 + 20 + 70 * 2, 134 + 20 + 40 * 0, 220 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*2,134+20+40*0,220+20+70*2+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 2, 134 + 20 + 40 * 0, 220 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					decity = 3; //����3
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�ɶ�
				if (mouse_press(220 + 20 + 70 * 3, 134 + 20 + 40 * 0, 220 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 0 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*3,134+20+40*0,220+20+70*3+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 3, 134 + 20 + 40 * 0, 220 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 0 + 20) == 1)
				{
					decity = 4; //����4
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(220 + 20 + 70 * 0, 134 + 20 + 40 * 1, 220 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*0,134+20+40*0,220+20+70*0+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 0, 134 + 20 + 40 * 1, 220 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					decity = 5; //����5
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(220 + 20 + 70 * 1, 134 + 20 + 40 * 1, 220 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*1,134+20+40*0,220+20+70*1+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 1, 134 + 20 + 40 * 1, 220 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					decity = 6; //����6
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(220 + 20 + 70 * 2, 134 + 20 + 40 * 1, 220 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*2,134+20+40*0,220+20+70*2+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 2, 134 + 20 + 40 * 1, 220 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					decity = 7; //����7
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(220 + 20 + 70 * 3, 134 + 20 + 40 * 1, 220 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 1 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*3,134+20+40*0,220+20+70*3+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 3, 134 + 20 + 40 * 1, 220 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 1 + 20) == 1)
				{
					decity = 8; //����8
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//����
				if (mouse_press(220 + 20 + 70 * 0, 134 + 20 + 40 * 2, 220 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*0,134+20+40*0,220+20+70*0+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 0, 134 + 20 + 40 * 2, 220 + 20 + 70 * 0 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					decity = 9; //����9
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�Ͼ�
				if (mouse_press(220 + 20 + 70 * 1, 134 + 20 + 40 * 2, 220 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;
					continue;
					//	city_select_lightup(220+20+70*1,134+20+40*0,220+20+70*1+50,134+20+40*0+20);
				}
				else if (mouse_press(220 + 20 + 70 * 1, 134 + 20 + 40 * 2, 220 + 20 + 70 * 1 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					decity = 10; //����10
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//�人
				if (mouse_press(220 + 20 + 70 * 2, 134 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;
					//	city_select_lightup(220+20+70*2,134+20+40*0,220+20+70*2+50,134+20+40*0+20);
					continue;
				}
				else if (mouse_press(220 + 20 + 70 * 2, 134 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					decity = 11; //����11
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}

				//���
				if (mouse_press(220 + 20 + 70 * 3, 134 + 20 + 40 * 2, 220 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 2 + 20) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(220 + 20 + 70 * 3, 134 + 20 + 40 * 2, 220 + 20 + 70 * 3 + 50, 134 + 20 + 40 * 2 + 20) == 1)
				{
					decity = 12; //����12
					state2 = 0;
					ticket_cover();

					setfillstyle(SOLID_FILL, WHITE);
					bar(221, 101, 369, 129);
					puthz(235, 109, city[decity - 1], 16, 18, BLUE);
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}
			}
		}

		//����
		if (MouseX > 380 && MouseX < 530 && MouseY > 100 && MouseY < 130)
		{
			if (mouse_press(380, 100, 530, 130) == 2)
			{
				MouseS = 1;
				if (state1 == 0 && state2 == 0)
				{
					city_select_lightup(380, 100, 380 + 150, 100 + 30);
					state1 = 3;
				}
				continue;
			}
			else if (mouse_press(380, 100, 530, 130) == 1)
			{
				if (state2 == 0)
				{
					date_select_page(350, 134);
					state2 = 3;
					delay(100);
				}
				else if (state2 == 3)
				{
					ticket_cover();
					state2 = 0;
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
					delay(100);
				}
			}
		}
		//����ѡ��������
		if (state2 == 3)
		{
			if (MouseX > 350 && MouseX < 350 + 220 && MouseY > 134 && MouseY < 134 + 300)
			{
				if (mouse_press(350, 134, 350 + 220, 134 + 300) == 2)
				{
					for (j = 0; j < 7; j++)
					{
						for (i = 0; i < 4; i++)
						{
							if (mouse_press(350 + 20 + 50 * i, 134 + 20 + j * 40, 350 + 20 + 50 * i + 30, 134 + 20 + j * 40 + 20) == 2)
							{
								MouseS = 1;
								click_state = 1;
							}
						}
					}
					if (click_state == 1)
					{
						click_state = 0;
						continue;
					}
					else
						MouseS = 0; //��ֹ�ظ�����
				}
				else if (mouse_press(350, 134, 350 + 220, 134 + 300) == 1)
				{
					for (j = 0; j < 7; j++)
					{
						for (i = 0; i < 4; i++)
						{

							if (mouse_press(350 + 20 + 50 * i, 134 + 20 + j * 40, 350 + 20 + 50 * i + 30, 134 + 20 + j * 40 + 20) == 1)
							{
								MouseS = 1;
								state2 = 0;
								itoa(4 * j + i + 1, date, 10);
								ticket_cover();

								setfillstyle(SOLID_FILL, WHITE);
								setcolor(BLUE);
								settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
								settextjustify(LEFT_TEXT, TOP_TEXT);
								bar(381, 101, 529, 129);
								outtextxy(395, 102, "2");
								puthz(410, 106, "��", 16, 18, GREEN);
								outtextxy(435, 102, date);
								if (prepage + 1 < page_num)
								{
									ticket_display(&node, 1, page_rest);
									delay(100);
								}
								else if (prepage + 1 == page_num)
								{
									ticket_display(&node, 2, page_rest);
									delay(100);
								}
							}
						}
					}
				}
			}
		}

		//�����
		if (prepage + 1 < page_num)
		{
			if (mouse_press(590, 203, 635, 227 + 30 * 7) == 2) // MouseX>590&&MouseX<635&&MouseY>203&&MouseY<227+30*8)
			{
				for (i = 0; i < MaxSize; i++)
				{
					if (mouse_press(590, 203 + 30 * i, 635, 227 + 30 * i) == 2)
					{
						MouseS = 1;
						click_state = 2;
					}
					if (click_state == 2)
					{
						click_state = 0;
						continue;
					}
					else
						MouseS = 0;
				}
			}
			else if (mouse_press(590, 203, 635, 227 + 30 * 7) == 1 && strlen(node.ticket_info[0].number) != 0)
			{
				for (i = 0; i < MaxSize; i++)
				{
					if (mouse_press(590, 203 + 30 * i, 635, 227 + 30 * i) == 1)
					{
						MouseS = 1;

						strcpy(t->number, node.ticket_info[i].number);
						strcpy(t->company, node.ticket_info[i].company);
						strcpy(t->city1, node.ticket_info[i].city1);
						strcpy(t->city2, node.ticket_info[i].city2);
						strcpy(t->weather1, node.ticket_info[i].weather1);
						strcpy(t->weather2, node.ticket_info[i].weather2);
						strcpy(t->launch_time, node.ticket_info[i].launch_time);
						strcpy(t->land_time, node.ticket_info[i].land_time);
						strcpy(t->tower, node.ticket_info[i].tower);
						strcpy(t->economy_price, node.ticket_info[i].economy_price);
						strcpy(t->business_price, node.ticket_info[i].business_price);
						strcpy(t->distance, node.ticket_info[i].distance);
						strcpy(t->rate, node.ticket_info[i].rate);
						strcpy(t->date, node.ticket_info[i].date);
						free(node.ticket_info);
						*func = 9;
						return;
					}
				}
			}
		}
		else if (prepage + 1 == page_num)
		{
			if (mouse_press(590, 203, 635, 227 + 30 * (page_rest - 1)) == 2) // MouseX>590&&MouseX<635&&MouseY>203&&MouseY<227+30*8)
			{
				for (i = 0; i < page_rest; i++)
				{
					if (mouse_press(590, 203 + 30 * i, 635, 227 + 30 * i) == 2)
					{
						MouseS = 1;
						click_state = 2;
					}
					if (click_state == 2)
					{
						click_state = 0;
						continue;
					}
					else
						MouseS = 0;
				}
			}
			else if (mouse_press(590, 203, 635, 227 + 30 * (page_rest - 1)) == 1 && strlen(node.ticket_info[0].number) != 0)
			{
				for (i = 0; i < page_rest; i++)
				{
					if (mouse_press(590, 203 + 30 * i, 635, 227 + 30 * i) == 1)
					{
						MouseS = 1;

						strcpy(t->number, node.ticket_info[i].number);
						strcpy(t->company, node.ticket_info[i].company);
						strcpy(t->city1, node.ticket_info[i].city1);
						strcpy(t->city2, node.ticket_info[i].city2);
						strcpy(t->weather1, node.ticket_info[i].weather1);
						strcpy(t->weather2, node.ticket_info[i].weather2);
						strcpy(t->launch_time, node.ticket_info[i].launch_time);
						strcpy(t->land_time, node.ticket_info[i].land_time);
						strcpy(t->tower, node.ticket_info[i].tower);
						strcpy(t->economy_price, node.ticket_info[i].economy_price);
						strcpy(t->business_price, node.ticket_info[i].business_price);
						strcpy(t->distance, node.ticket_info[i].distance);
						strcpy(t->rate, node.ticket_info[i].rate);
						strcpy(t->date, node.ticket_info[i].date);
						free(node.ticket_info);
						*func = 9;
						return;
					}
				}
			}
		}

		//��ѯ��
		if (MouseX > 550 && MouseX < 595 && MouseY > 107 && MouseY < 129)
		{
			if (mouse_press(550, 107, 595, 129) == 2)
			{
				MouseS = 1;
			}
			else if (mouse_press(550, 107, 595, 129) == 1)
			{
				if (laucity != 0 && decity != 0 && strlen(date) != 0)
				{
					MouseS = 1;
					len = ticketinfo_read(t_list, city[laucity - 1], city[decity - 1], date);
					buypage_count(&page_num, &page_rest, len);

					prepage = 0;
					enqueue(&node, t_list, prepage);
					ticket_cover();
					if (prepage + 1 < page_num)
					{
						ticket_display(&node, 1, page_rest);
						delay(100);
					}
					else if (prepage + 1 == page_num)
					{
						ticket_display(&node, 2, page_rest);
						delay(100);
					}
				}
			}
		}

		//��ת���������Ľ���
		if (MouseX > 360 && MouseX < 440 && MouseY > 10 && MouseY < 60)
		{
			if (mouse_press(360, 10, 440, 60) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(369, 10, 440, 60) == 1)
			{
				free(node.ticket_info);
				*func = 5;
				return;
			}
		}

		//��ת��������ؽ���
		if (MouseX > 450 && MouseX < 530 && MouseY > 10 && MouseY < 60)
		{
			if (mouse_press(450, 10, 530, 60) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(450, 10, 530, 60) == 1)
			{
				free(node.ticket_info);
				*func = 8;
				return;
			}
		}

		//��ת����̬��ѯ����
		if (MouseX > 540 && MouseX < 620 && MouseY > 10 && MouseY < 60)
		{
			if (mouse_press(540, 10, 620, 60) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(540, 10, 620, 60) == 1)
			{
				free(node.ticket_info);
				*func = 15;
				return;
			}
		}

		//�˳���
		if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
		{
			if (mouse_press(595, 0, 640, 20) == 1)
			{
				free(node.ticket_info);
				*func = 1;
				return;
			}
		}

		if (state1 != 0)
		{
			if (state1 == 1)
			{
				city_select_lightup_recover(60, 100, 60 + 150, 100 + 30);
			}
			if (state1 == 2)
			{
				city_select_lightup_recover(220, 100, 220 + 150, 100 + 30);
			}
			if (state1 == 3)
			{
				city_select_lightup_recover(380, 100, 380 + 150, 100 + 30);
			}
			state1 = 0;
		}

		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/***********************************
FUNCTION: ticket_display
DESCRIPTION: չʾ��Ʊ
INPUT: *node��flag,page_rest
RETURN: ��
***********************************/
void ticket_display(TNode *node, int flag, int page_rest)
{
	int i;

	setcolor(BROWN);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);

	if (flag == 1 && strlen(node->ticket_info[0].number) != 0) //�������һҳ
	{
		for (i = 0; i < MaxSize; i++)
		{
			outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
			puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
			outtextxy(240, 200 + i * 30, node->ticket_info[i].launch_time);
			outtextxy(340, 200 + i * 30, node->ticket_info[i].land_time);
			outtextxy(440, 200 + i * 30, node->ticket_info[i].tower);
			outtextxy(540, 200 + i * 30, node->ticket_info[i].economy_price);
			setfillstyle(10, LIGHTGRAY);
			bar(590, 203 + 30 * i, 635, 227 + 30 * i);
			rectangle(590, 203 + 30 * i, 635, 227 + 30 * i);
			puthz(596, 206 + 30 * i, "����", 16, 18, BLUE);
		}
	}
	else if (flag == 2 && strlen(node->ticket_info[0].number) != 0) //�����һҳ
	{
		for (i = 0; i < page_rest; i++)
		{
			outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
			puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
			outtextxy(240, 200 + i * 30, node->ticket_info[i].launch_time);
			outtextxy(340, 200 + i * 30, node->ticket_info[i].land_time);
			outtextxy(440, 200 + i * 30, node->ticket_info[i].tower);
			outtextxy(540, 200 + i * 30, node->ticket_info[i].economy_price);
			setfillstyle(10, LIGHTGRAY);
			bar(590, 203 + 30 * i, 635, 227 + 30 * i);
			rectangle(590, 203 + 30 * i, 635, 227 + 30 * i);
			puthz(596, 206 + 30 * i, "����", 16, 18, BLUE);
		}
	}
}

/***********************************
FUNCTION: buypage_count
DESCRIPTION: ����һ����ҳ�Լ����һҳ�м�����Ϣ
INPUT: *page_num��*page_rest,len,*state
RETURN: ��
***********************************/
void buypage_count(int *page_num, int *page_rest, int len) //, int *state) //
{
	int i;
	if (len == 0)
	{
		*page_num = 0;
		*page_rest = 0;
		return;
	}
	*page_rest = len % MaxSize;
	*page_num = len / MaxSize;
	if (*page_rest == 0)
	{
		*page_rest = MaxSize;
	}
	else
		(*page_num)++; //������һҳ����8����page_num+1
}

/***********************************
FUNCTION: ticket_cover
DESCRIPTION: �ڸ�ԭ�л�Ʊ�б�
INPUT: *node��flag,page_rest
RETURN: ��
***********************************/
void ticket_cover(void)
{
	clrmous(MouseX, MouseY);

	setfillstyle(SOLID_FILL, WHITE);
	bar(1, 131, 640, 440);

	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 160, 640, 200);
	puthz(40, 170, "������", 16, 18, 9);
	puthz(140, 170, "���չ�˾", 16, 18, 9);
	puthz(240, 170, "�ƻ����", 16, 18, 9);
	puthz(340, 170, "�ƻ�����", 16, 18, 9);
	puthz(440, 170, "��վ¥", 16, 18, 9);
	puthz(500, 170, "���ò�Ʊ��", 16, 18, 9);

	setcolor(DARKGRAY);
	line(0, 230, 640, 230);
	line(0, 260, 640, 260);
	line(0, 290, 640, 290);
	line(0, 320, 640, 320);
	line(0, 350, 640, 350);
	line(0, 380, 640, 380);
	line(0, 410, 640, 410);
	line(0, 440, 640, 440);
}

/***********************************
FUNCTION: city_select_page
DESCRIPTION: ����ѡ��˵�����
INPUT: x,y
RETURN: ��
***********************************/
void city_select_page(int x, int y)
{
	int i, j;
	char *city[] = {
		"����", "�Ϻ�", "����", "�ɶ�",
		"����", "����", "����", "����",
		"����", "�Ͼ�", "�人", "���"};

	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(x, y, x + 300, y + 140);
	setcolor(BLUE);
	rectangle(x - 1, y - 1, x + 300 + 1, y + 140 + 1);
	rectangle(x - 2, y - 2, x + 300 + 2, y + 140 + 2);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setcolor(DARKGRAY);
	/*	bar(x+10,y+10,x+20+50,y+30);
		bar(x+20+50+10,y+10,x+20+50+20+50,y+30);*/
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{

			bar(x + 20 + 70 * i, y + 20 + j * 40, x + 20 + 70 * i + 50, y + 20 + j * 40 + 20);
			rectangle(x + 20 + 70 * i, y + 20 + j * 40, x + 20 + 70 * i + 50, y + 20 + j * 40 + 20);
			puthz(x + 20 + 70 * i + 7, y + 20 + j * 40 + 2, city[j * 4 + i], 16, 18, RED);
		}
	}
}

/***********************************
FUNCTION: date_select_page
DESCRIPTION: ������˵�����
INPUT: x,y
RETURN: ��
***********************************/
void date_select_page(int x, int y)
{
	int i, j;
	int count = 0;
	char date[3] = "\0";

	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(x, y, x + 220, y + 300);
	setcolor(BLUE);
	rectangle(x - 1, y - 1, x + 220 + 1, y + 300 + 1);
	rectangle(x - 2, y - 2, x + 220 + 2, y + 300 + 2);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setcolor(DARKGRAY);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	for (j = 0; j < 7; j++)
	{
		for (i = 0; i < 4; i++)
		{
			count++;
			itoa(count, date, 10);
			bar(x + 20 + 50 * i, y + 20 + j * 40, x + 20 + 50 * i + 30, y + 20 + j * 40 + 20);
			rectangle(x + 20 + 50 * i, y + 20 + j * 40, x + 20 + 50 * i + 30, y + 20 + j * 40 + 20);
			if (count < 10)
			{
				outtextxy(x + 20 + 50 * i + 10, y + 20 + j * 40 - 2, date);
			}
			else if (count >= 10)
			{
				outtextxy(x + 20 + 50 * i + 5, y + 20 + j * 40 - 2, date);
			}

			//	puthz(x+20+70*i+7,y+20+j*40+2,city[j*4+i],16,18,RED);
		}
	}
}

void city_select_lightup(int x1, int y1, int x2, int y2)
{
	clrmous(MouseX, MouseY);
	setcolor(GREEN);
	rectangle(x1, y1, x2, y2);
}

void city_select_lightup_recover(int x1, int y1, int x2, int y2)
{
	clrmous(MouseX, MouseY);
	setcolor(DARKGRAY);
	rectangle(x1, y1, x2, y2);
}

/***********************************
FUNCTION: buypage
DESCRIPTION: ��Ʊ����
INPUT: ��
RETURN: ��
***********************************/
void buypage_draw(void)
{
	cleardevice();
	clrmous(MouseX, MouseY);
	delay(30);

	setlinestyle(0, 0, 1);
	setfillstyle(SOLID_FILL, WHITE);
	bar(0, 0, 640, 480);
	setcolor(DARKGRAY);
	rectangle(60, 0, 640, 60);
	rectangle(0, 0, 60, 60);
	rectangle(0, 60, 640, 160);
	// rectangle(0, 150, 640, 175);
	rectangle(0, 160, 640, 200);
	rectangle(540, 450, 600, 470);
	rectangle(40, 450, 100, 470);
	// rectangle(580,0, 640, 20);
	rectangle(60, 100, 210, 130);
	rectangle(220, 100, 370, 130);
	rectangle(380, 100, 530, 130);
	line(0, 230, 640, 230);

	line(0, 260, 640, 260);
	line(0, 290, 640, 290);
	line(0, 320, 640, 320);
	line(0, 350, 640, 350);
	line(0, 380, 640, 380);
	line(0, 410, 640, 410);
	line(0, 440, 640, 440);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 160, 640, 200);
	setfillstyle(SOLID_FILL, GREEN);
	bar(0, 0, 60, 60);
	setfillstyle(SOLID_FILL, GREEN);
	bar(539, 449, 599, 469);
	bar(39, 449, 99, 469);
	//	setfillstyle(SOLID_FILL, RED);
	//	bar(580,0,640,20);
	puthz(65, 20, "�����ݺ�", 32, 35, 4);
	puthz(270, 30, "��Ʊ��Ϣ", 16, 18, 2);
	puthz(360, 30, "��������", 16, 18, 8);
	puthz(450, 30, "�������", 16, 18, 8);
	puthz(540, 30, "��̬��ѯ", 16, 18, 8);

	puthz(40, 170, "������", 16, 18, 9);
	puthz(140, 170, "���չ�˾", 16, 18, 9);
	puthz(240, 170, "�ƻ����", 16, 18, 9);
	puthz(340, 170, "�ƻ�����", 16, 18, 9);
	puthz(440, 170, "��վ¥", 16, 18, 9);
	puthz(500, 170, "���ò�Ʊ��", 16, 18, 9);

	//	puthz(595,5,"�˳�",16,18,1);
	puthz(75, 110, "����", 16, 18, 7);
	puthz(235, 110, "����", 16, 18, 7);
	puthz(385, 110, "����", 16, 18, 7);
	puthz(555, 110, "��ѯ", 16, 18, 6);
	//	rectangle(550,107,595,129);
	puthz(545, 452, "��һҳ", 16, 18, 1);
	puthz(45, 452, "��һҳ", 16, 18, 1);
	//	getchar();
}