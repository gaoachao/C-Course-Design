#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>
#include "mouse.h"
#include <bios.h>
#include <conio.h>
#include "hz.h"
#include "database.h"
#include "dynamic.h"
#include "register.h"
#include "buypage.h"
#include "login.h"

/***********************************
FUNCTION: dynamic_main1
DESCRIPTION: ���ݳ��к����ڲ�ѯ������
INPUT: *func
RETURN: ��
***********************************/
void dynamic_main1(int *func)
{
    //    int f = 1, ftemp = 1;
    int num = 0;
    int i, j, prepage = 0;

    int key;
    //	char *ttemp;
    int len, page_num, page_rest;
    //	int state[MaxSize];
    int state1 = 0;
    int state2 = 0;
    int click_state = 0;
    //	int state3=0;
    int decity = 0, laucity = 0;
    char date[3];
    TNode node;              //��Ʊ�ڵ�
    Ticket t_list[List_len]; //��Ʊ��Ϣ����
    char *city[] = {
        "����", "�Ϻ�", "����", "�ɶ�",
        "����", "����", "����", "����",
        "����", "�Ͼ�", "�人", "���"};
    memset(date, '\0', sizeof(date));
    initQueue(&node);

    dynamic_draw1();

    exit_buttom();

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (kbhit())
        {
            key = bioskey(0);
            if (key == Key_Down)
            {
                if (strlen(t_list[0].number) != 0)
                {
                    ticket_cover_dynamic();

                    queue_down(&prepage, page_num);
                    enqueue(&node, t_list, prepage);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest,1);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest,1);
                        delay(100);
                    }
                }
            }
            if (key == Key_Up)
            {
                if (strlen(t_list[0].number) != 0)
                {
                    ticket_cover_dynamic();

                    queue_up(&prepage, page_num);
                    //	queue_up(&prepage,page_num);
                    enqueue(&node, t_list, prepage);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest,1);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest,1);
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
                    ticket_cover_dynamic();

                    queue_down(&prepage, page_num);
                    //	queue_up(&prepage,page_num);
                    enqueue(&node, t_list, prepage);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest,1);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest,1);
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
                ticket_cover_dynamic();

                queue_up(&prepage, page_num);
                //	queue_up(&prepage,page_num);
                enqueue(&node, t_list, prepage);
                if (prepage + 1 < page_num)
                {
                    ticket_display_dynamic(&node, 1, page_rest,1);
                    delay(100);
                }
                else if (prepage + 1 == page_num)
                {
                    ticket_display_dynamic(&node, 2, page_rest,1);
                    delay(100);
                }
            }
        }

        //������ѡ��
        if (MouseX > 60 && MouseX < 210 && MouseY > 120 && MouseY < 150)
        {
            if (mouse_press(60, 120, 210, 150) == 2)
            {
                MouseS = 1;
                if (state1 == 0 && state2 == 0)
                {
                    city_select_lightup(60, 120, 60 + 150, 120 + 30);
                    state1 = 1;
                }
                continue;
            }
            else if (mouse_press(60, 120, 210, 150) == 1)
            {
                MouseS = 1;
                if (state2 == 0) //���˵�δչ��
                {
                    city_select_page(60, 154);
                    state2 = 1;
                    delay(120);
                }
                else if (state2 == 1) //���˵���չ��
                {
                    ticket_cover_dynamic();
                    state2 = 0;
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                    delay(120);
                }
            }
        }
        //�����س���������
        if (state2 == 1)
        {
            if (MouseX > 60 && MouseX < 60 + 300 && MouseY > 154 && MouseY < 154 + 140)
            {
                //����
                if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 0, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 0, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 1; //����1
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�Ϻ�
                if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 0, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 0, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 2; //����2
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 0, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 0, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 3; //����3
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�ɶ�
                if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 0, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 0, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 4; //����4
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 1, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 1, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 5; //����5
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 1, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 1, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 6; //����6
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 1, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 1, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 7; //����7
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 1, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 1, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 8; //����8
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 2, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;

                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 2, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 9; //����9
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�Ͼ�
                if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 2, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 2, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 10; //����10
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�人
                if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 2, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                    continue;
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 11; //����11
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //���
                if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 2, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                    continue;
                }
                else if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 2, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 12; //����12
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }
            }
        }

        //Ŀ�ĵ�ѡ��
        if (MouseX > 220 && MouseX < 370 && MouseY > 120 && MouseY < 150)
        {
            if (mouse_press(220, 120, 370, 150) == 2)
            {
                MouseS = 1;
                if (state1 == 0 && state2 == 0)
                {
                    city_select_lightup(220, 120, 220 + 150, 120 + 30);
                    state1 = 2;
                }
                continue;
            }
            else if (mouse_press(220, 120, 370, 150) == 1)
            {
                MouseS = 1;
                if (state2 == 0)
                {
                    city_select_page(220, 154);
                    state2 = 2;
                    delay(120);
                }
                else if (state2 == 2)
                {
                    ticket_cover_dynamic();
                    state2 = 0;

                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                    delay(120);
                }
            }
        }

        //Ŀ�ĵس���������
        if (state2 == 2)
        {
            if (MouseX > 220 && MouseX < 220 + 300 && MouseY > 154 && MouseY < 154 + 140)
            {
                //����
                if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 0, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 0, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 1; //����1
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�Ϻ�
                if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 0, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 0, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 2; //����2
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 0, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 0, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 3; //����3
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�ɶ�
                if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 0, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 0, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 4; //����4
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 1, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 1, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 5; //����5
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 1, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 1, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 6; //����6
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 1, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 1, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 7; //����7
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 1, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 1, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 8; //����8
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //����
                if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 2, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 2, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 9; //����9
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�Ͼ�
                if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 2, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 2, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 10; //����10
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //�人
                if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                    continue;
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 11; //����11
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }

                //���
                if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 2, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                }
                else if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 2, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 12; //����12
                    state2 = 0;
                    ticket_cover_dynamic();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                }
            }
        }

        //����
        if (MouseX > 380 && MouseX < 530 && MouseY > 120 && MouseY < 150)
        {
            if (mouse_press(380, 120, 530, 150) == 2)
            {
                MouseS = 1;
                if (state1 == 0 && state2 == 0)
                {
                    city_select_lightup(380, 120, 380 + 150, 120 + 30);
                    state1 = 3;
                }
                continue;
            }
            else if (mouse_press(380, 120, 530, 150) == 1)
            {
                if (state2 == 0)
                {
                    date_select_page(350, 154);
                    state2 = 3;
                    delay(120);
                }
                else if (state2 == 3)
                {
                    ticket_cover_dynamic();
                    state2 = 0;
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(120);
                    }
                    delay(120);
                }
            }
        }
        //����ѡ��������
        if (state2 == 3)
        {
            if (MouseX > 350 && MouseX < 350 + 220 && MouseY > 154 && MouseY < 154 + 300)
            {
                if (mouse_press(350, 154, 350 + 220, 154 + 300) == 2)
                {
                    for (j = 0; j < 7; j++)
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (mouse_press(350 + 20 + 50 * i, 154 + 20 + j * 40, 350 + 20 + 50 * i + 30, 154 + 20 + j * 40 + 20) == 2)
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
                else if (mouse_press(350, 154, 350 + 220, 154 + 300) == 1)
                {
                    for (j = 0; j < 7; j++)
                    {
                        for (i = 0; i < 4; i++)
                        {

                            if (mouse_press(350 + 20 + 50 * i, 154 + 20 + j * 40, 350 + 20 + 50 * i + 30, 154 + 20 + j * 40 + 20) == 1)
                            {
                                MouseS = 1;
                                state2 = 0;
                                itoa(4 * j + i + 1, date, 10);
                                ticket_cover_dynamic();

                                setfillstyle(SOLID_FILL, WHITE);
                                setcolor(BLUE);
                                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
                                settextjustify(LEFT_TEXT, TOP_TEXT);
                                bar(381, 121, 529, 149);
                                outtextxy(395, 122, "2");
                                puthz(410, 126, "��", 16, 18, GREEN);
                                outtextxy(435, 122, date);
                                if (prepage + 1 < page_num)
                                {
                                    ticket_display_dynamic(&node, 1, page_rest, 1);
                                    delay(120);
                                }
                                else if (prepage + 1 == page_num)
                                {
                                    ticket_display_dynamic(&node, 2, page_rest, 1);
                                    delay(120);
                                }
                            }
                        }
                    }
                }
            }
        }

        //����Ų�ѯ����
        if (MouseX > 220 && MouseX < 380 && MouseY > 80 && MouseY < 110)
        {
            if (mouse_press(220, 80, 380, 110) == 2)
            {
                if (num == 0)
                {
                    MouseS = 1;
                    lightup_dynamic(220, 80, 380, 110, 2);
                    num = 2;
                }
                continue;
            }
            else if (mouse_press(220, 80, 380, 110) == 1)
            {
                free(node.ticket_info);
                *func = 16;
                return;
            }
        }
        //ʵʱ������Ϣ��ѯ����
        if (MouseX > 400 && MouseX < 540 && MouseY > 80 && MouseY < 110)
        {
            if (mouse_press(400, 80, 540, 110) == 2)
            {
                if (num == 0)
                {
                    MouseS = 1;
                    lightup_dynamic(400, 80, 540, 110, 3);
                    num = 3;
                }
                continue;
            }
            else if (mouse_press(400, 80, 540, 110) == 1)
            {
                free(node.ticket_info);
                *func = 17;
                return;
            }
        }

        //��ѯ��
        if (MouseX > 550 && MouseX < 595 && MouseY > 127 && MouseY < 149)
        {
            if (mouse_press(550, 127, 595, 149) == 2)
            {
                MouseS = 1;
            }
            else if (mouse_press(550, 127, 595, 149) == 1)
            {
                if (laucity != 0 && decity != 0 && strlen(date) != 0)
                {
                    MouseS = 1;
                    len = ticketinfo_read(t_list, city[laucity - 1], city[decity - 1], date);
                    buypage_count(&page_num, &page_rest, len); // ate);
                    prepage = 0;
                    enqueue(&node, t_list, prepage);
                    ticket_cover_dynamic();
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 1);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 1);
                        delay(100);
                    }
                }
            }
        }

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
                free(node.ticket_info);
                *func = 4;
                return;
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

        if (num != 0)
        {
            /*            if (num == 1)
                        {
                            recoverlightup_dynamic(60, 80, 200, 110, 1);
                        }*/
            if (num == 2)
            {
                recoverlightup_dynamic(220, 80, 380, 110, 2);
            }
            if (num == 3)
            {
                recoverlightup_dynamic(400, 80, 540, 110, 3);
            }
            num = 0;
        }

        if (state1 != 0)
        {
            if (state1 == 1)
            {
                city_select_lightup_recover(60, 120, 60 + 150, 120 + 30);
            }
            if (state1 == 2)
            {
                city_select_lightup_recover(220, 120, 220 + 150, 120 + 30);
            }
            if (state1 == 3)
            {
                city_select_lightup_recover(380, 120, 380 + 150, 120 + 30);
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
FUNCTION: dynamic_main2
DESCRIPTION: ���ݺ���Ų�ѯ������
INPUT: *func
RETURN: ��
***********************************/
void dynamic_main2(int *func)
{
    int num = 0;
    int i, j, prepage = 0;

    int key;
    int len, page_num, page_rest;
    int state1 = 0;
    //    int state2 = 0;
    char number[10];
    TNode node;                      //��Ʊ�ڵ�
    Ticket t_list[List_len_dynamic]; //��Ʊ��Ϣ����

    dynamic_draw2();
    exit_buttom();

    initQueue(&node);
    memset(number, '\0', sizeof(number));

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (kbhit())
        {
            key = bioskey(0);
            if (key == Key_Down)
            {
                if (strlen(t_list[0].number) != 0)
                {
                    ticket_cover_dynamic_number();

                    queue_down(&prepage, page_num);
                    //	queue_up(&prepage,page_num);
                    enqueue(&node, t_list, prepage);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 2);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 2);
                        delay(100);
                    }
                }
            }
            if (key == Key_Up)
            {
                if (strlen(t_list[0].number) != 0)
                {
                    ticket_cover_dynamic_number();

                    queue_up(&prepage, page_num);
                    //	queue_up(&prepage,page_num);
                    enqueue(&node, t_list, prepage);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 2);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 2);
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
                    ticket_cover_dynamic_number();

                    queue_down(&prepage, page_num);
                    //	queue_up(&prepage,page_num);
                    enqueue(&node, t_list, prepage);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 2);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 2);
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
                    ticket_cover_dynamic_number();

                    queue_up(&prepage, page_num);
                    //	queue_up(&prepage,page_num);
                    enqueue(&node, t_list, prepage);
                    if (prepage + 1 < page_num)
                    {
                        ticket_display_dynamic(&node, 1, page_rest, 2);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        ticket_display_dynamic(&node, 2, page_rest, 2);
                        delay(100);
                    }
                }
        }

        //����������
        {
            if (MouseX > 200 && MouseX < 400 && MouseY > 120 && MouseY < 150)
            {
                if (mouse_press(200, 120, 400, 150) == 2)
                {
                    if (num == 0 && state1 == 0)
                    {
                        MouseS = 2;
                        num = 1;
                        lightup_login(200, 120, 400, 150, 1);
                    }
                    continue;
                }
                else if (mouse_press(200, 120, 400, 150) == 1)
                {
                    lightup_login(200, 120, 400, 150, 1);
                    memset(number, '\0', sizeof(number));
                    inputadmin(number, 200, 120, 9, LIGHTGRAY);
                    if (strlen(number) == 0)
                    {
                        state1 = 0;
                    }
                    else
                    {
                        state1 = 1;
                    }
                }
            }
        }

        //�������ڲ�ѯ����
        if (MouseX > 60 && MouseX < 200 && MouseY > 80 && MouseY < 110)
        {
            if (mouse_press(60, 80, 200, 110) == 2)
            {
                if (num == 0)
                {
                    MouseS = 1;
                    lightup_dynamic(60, 80, 200, 110, 1);
                    num = 2;
                }
                continue;
            }
            else if (mouse_press(60, 80, 200, 110) == 1)
            {
                free(node.ticket_info);
                *func = 15;
                return;
            }
        }

        //ʵʱ������Ϣ��ѯ����
        if (MouseX > 400 && MouseX < 540 && MouseY > 80 && MouseY < 110)
        {
            if (mouse_press(400, 80, 540, 110) == 2)
            {
                if (num == 0)
                {
                    MouseS = 1;
                    lightup_dynamic(400, 80, 540, 110, 3);
                    num = 3;
                }
                continue;
            }
            else if (mouse_press(400, 80, 540, 110) == 1)
            {
                free(node.ticket_info);
                *func = 17;
                return;
            }
        }

        //��ѯ��
        if (MouseX > 550 && MouseX < 595 && MouseY > 127 && MouseY < 149)
        {
            if (mouse_press(550, 127, 595, 149) == 2)
            {
                MouseS = 1;
            }
            else if (mouse_press(550, 127, 595, 149) == 1)
            {
                if (strlen(number) != 0)
                {
                    MouseS = 1;
                    len = ticketinfo_read_number(t_list, number);
                    if (strlen(t_list[0].number) == 0)
                    {
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(420, 120, 530, 150);
                        puthz(420, 122, "���಻����", 16, 18, RED);
                    }
                    else
                    {

                        setfillstyle(SOLID_FILL, WHITE);
                        bar(420, 120, 530, 150);
                        buypage_count(&page_num, &page_rest, len);
                        prepage = 0;
                        enqueue(&node, t_list, prepage);
                        ticket_cover_dynamic_number();
                        printf("num=%d\t", page_num);
                        printf("rest=%d\n", page_rest);
                        if (prepage + 1 < page_num)
                        {
                            ticket_display_dynamic(&node, 1, page_rest, 2);
                            delay(100);
                        }
                        else if (prepage + 1 == page_num)
                        {
                            ticket_display_dynamic(&node, 2, page_rest, 2);
                            delay(100);
                        }
                    }
                }
            }
        }

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
                free(node.ticket_info);
                *func = 4;
                return;
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

        if (num != 0)
        {
            if (num == 1 && state1 == 0)
            {
                recoverbuttom_login(200, 120, 400, 150, 1);
            }
            if (num == 2)
            {
                recoverlightup_dynamic(60, 80, 200, 110, 1);
            }
            if (num == 3)
            {
                recoverlightup_dynamic(400, 80, 540, 110, 3);
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
FUNCTION: ticket_cover_dynamic
DESCRIPTION: �ڸ�ԭ�л�Ʊ�б�
INPUT: *node��flag,page_rest
RETURN: ��
***********************************/
void ticket_cover_dynamic(void)
{
    clrmous(MouseX, MouseY);

    setfillstyle(SOLID_FILL, WHITE);
    bar(1, 152, 640, 479);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 160, 640, 200);
    puthz(40, 170, "������", 16, 18, 9);
    puthz(140, 170, "���չ�˾", 16, 18, 9);
    puthz(240, 170, "��ɵ�����", 16, 18, 9);
    puthz(360, 170, "Ŀ�ĵ�����", 16, 18, 9);
    puthz(480, 170, "׼����", 16, 18, 9);
    //    puthz(400, 170, "���ò�Ʊ��", 16, 18, 9);

    setcolor(DARKGRAY);
    line(0, 230, 640, 230);
    line(0, 260, 640, 260);
    line(0, 290, 640, 290);
    line(0, 320, 640, 320);
    line(0, 350, 640, 350);
    line(0, 380, 640, 380);
    line(0, 410, 640, 410);
    line(0, 440, 640, 440);

    setfillstyle(SOLID_FILL, GREEN);
    bar(539, 449, 599, 469);
    bar(39, 449, 99, 469);

    puthz(545, 452, "��һҳ", 16, 18, 1);
    puthz(45, 452, "��һҳ", 16, 18, 1);
}

/***********************************
FUNCTION: ticket_cover_dynamic
DESCRIPTION: �ڸ�ԭ�л�Ʊ�б�
INPUT: *node��flag,page_rest
RETURN: ��
***********************************/
void ticket_cover_dynamic_number(void)
{
    clrmous(MouseX, MouseY);

    setfillstyle(SOLID_FILL, WHITE);
    bar(1, 152, 640, 479);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 160, 640, 200);
    puthz(40, 170, "������", 16, 18, 9);
    puthz(140, 170, "���չ�˾", 16, 18, 9);
    puthz(240, 170, "��ɵ�����", 16, 18, 9);
    puthz(360, 170, "Ŀ�ĵ�����", 16, 18, 9);
    puthz(480, 170, "׼����", 16, 18, 9);
    puthz(580, 170, "����", 16, 18, 9);
    //    puthz(400, 170, "���ò�Ʊ��", 16, 18, 9);

    setcolor(DARKGRAY);
    line(0, 230, 640, 230);
    line(0, 260, 640, 260);
    line(0, 290, 640, 290);
    line(0, 320, 640, 320);
    line(0, 350, 640, 350);
    line(0, 380, 640, 380);
    line(0, 410, 640, 410);
    line(0, 440, 640, 440);

    setfillstyle(SOLID_FILL, GREEN);
    bar(539, 449, 599, 469);
    bar(39, 449, 99, 469);

    puthz(545, 452, "��һҳ", 16, 18, 1);
    puthz(45, 452, "��һҳ", 16, 18, 1);
}

/***********************************
FUNCTION: ticket_display_dynamic
DESCRIPTION: չʾ��Ʊ
INPUT: *node��flag,page_rest
RETURN: ��
***********************************/
void ticket_display_dynamic(TNode *node, int flag, int page_rest, int mode)
{
    int i;

    setcolor(BROWN);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    settextjustify(LEFT_TEXT, TOP_TEXT);

    if (mode == 1) //���ճ��в�ѯ�����������
    {
        if (flag == 1 && strlen(node->ticket_info[0].number) != 0) //�������һҳ
        {
            for (i = 0; i < MaxSize; i++)
            {
                outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
                puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
                puthz(280, 200 + 3 + i * 30, node->ticket_info[i].weather1, 16, 18, 6);
                puthz(400, 200 + 3 + i * 30, node->ticket_info[i].weather2, 16, 18, 6);
                outtextxy(490, 200 + i * 30, node->ticket_info[i].rate);
            }
        }
        else if (flag == 2 && strlen(node->ticket_info[0].number) != 0) //�����һҳ
        {
            for (i = 0; i < page_rest; i++)
            {
                outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
                puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
                puthz(280, 200 + 3 + i * 30, node->ticket_info[i].weather1, 16, 18, 6);
                puthz(400, 200 + 3 + i * 30, node->ticket_info[i].weather2, 16, 18, 6);
                outtextxy(490, 200 + i * 30, node->ticket_info[i].rate);
            }
        }
    }

    if (mode == 2) //���պ���Ų�ѯ���������
    {
        if (flag == 1 && strlen(node->ticket_info[0].number) != 0) //�������һҳ
        {
            for (i = 0; i < MaxSize; i++)
            {
                outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
                puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
                puthz(280, 200 + 3 + i * 30, node->ticket_info[i].weather1, 16, 18, 6);
                puthz(400, 200 + 3 + i * 30, node->ticket_info[i].weather2, 16, 18, 6);
                outtextxy(490, 200 + i * 30, node->ticket_info[i].rate);
                outtextxy(575, 200 + i * 30, node->ticket_info[i].date);
                puthz(611, 200 + i * 30 + 3, "��", 16, 18, 6);
            }
        }
        else if (flag == 2 && strlen(node->ticket_info[0].number) != 0) //�����һҳ
        {
            for (i = 0; i < page_rest; i++)
            {
                outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
                puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
                puthz(280, 200 + 3 + i * 30, node->ticket_info[i].weather1, 16, 18, 6);
                puthz(400, 200 + 3 + i * 30, node->ticket_info[i].weather2, 16, 18, 6);
                outtextxy(490, 200 + i * 30, node->ticket_info[i].rate);
                outtextxy(575, 200 + i * 30, node->ticket_info[i].date);
                puthz(611, 200 + i * 30 + 3, "��", 16, 18, 6);
            }
        }
    }
}

void lightup_dynamic(int x1, int y1, int x2, int y2, int flag)
{
    clrmous(MouseX, MouseY);
    delay(30);

    switch (flag)
    {
    case 1:
    {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x1, y1, x2, y2);
        setcolor(RED);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "���ݳ��в�ѯ", 16, 18, BLUE);
        break;
    }

    case 2:
    {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x1, y1, x2, y2);
        setcolor(RED);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "���ݺ���Ų�ѯ", 16, 18, BLUE);
        break;
    }

    case 3:
    {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x1, y1, x2, y2);
        setcolor(RED);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "ʵʱ�����ѯ", 16, 18, BLUE);
        break;
    }

    case 4:
    {
        setcolor(GREEN);
        rectangle(x1, y1, x2, y2);
        break;
    }

    default:
        break;
    }
}

void recoverlightup_dynamic(int x1, int y1, int x2, int y2, int flag)
{
    clrmous(MouseX, MouseY);
    delay(30);

    switch (flag)
    {
    case 1:
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(x1, y1, x2, y2);
        setcolor(BROWN);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "���ݳ��в�ѯ", 16, 18, BLUE);
        break;
    }

    case 2:
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(x1, y1, x2, y2);
        setcolor(BROWN);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "���ݺ���Ų�ѯ", 16, 18, BLUE);
        break;
    }

    case 3:
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(x1, y1, x2, y2);
        setcolor(BROWN);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "ʵʱ�����ѯ", 16, 18, BLUE);
        break;
    }

    case 4:
    {
        setcolor(LIGHTGRAY);
        rectangle(x1, y1, x2, y2);
        break;
    }

    default:
        break;
    }
}

/***********************************
FUNCTION: dynamic_draw2
DESCRIPTION: ��̬��ѯ�������
INPUT: ��
RETURN: ��
***********************************/
void dynamic_draw2(void)
{
    clrmous(MouseX, MouseY);
    delay(30);
    cleardevice();

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
    rectangle(200, 120, 400, 150);
    //    rectangle(220, 120, 370, 150);
    //    rectangle(380, 120, 530, 150);

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
    puthz(65, 20, "�����ݺ�", 32, 35, 4);
    puthz(270, 30, "��Ʊ��Ϣ", 16, 18, 8);
    puthz(360, 30, "��������", 16, 18, 8);
    puthz(450, 30, "�������", 16, 18, 8);
    puthz(540, 30, "��̬��ѯ", 16, 18, 2);

    puthz(40, 170, "������", 16, 18, 9);
    puthz(140, 170, "���չ�˾", 16, 18, 9);
    puthz(240, 170, "��ɵ�����", 16, 18, 9);
    puthz(360, 170, "Ŀ�ĵ�����", 16, 18, 9);
    puthz(480, 170, "׼����", 16, 18, 9);
    puthz(580, 170, "����", 16, 18, 9);
    puthz(75, 128, "���뺽���", 16, 18, 7);
    puthz(555, 128, "��ѯ", 16, 18, 6);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(220, 80, 380, 110);
    setcolor(RED);
    rectangle(60, 80, 200, 110);
    setcolor(BROWN);
    rectangle(220, 80, 380, 110);
    rectangle(400, 80, 540, 110);
    puthz(75, 88, "���ݳ��в�ѯ", 16, 18, BLUE);
    puthz(235, 88, "���ݺ���Ų�ѯ", 16, 18, BLUE);
    puthz(415, 88, "ʵʱ�����ѯ", 16, 18, BLUE);
    puthz(545, 452, "��һҳ", 16, 18, 1);
    puthz(45, 452, "��һҳ", 16, 18, 1);
}

/***********************************
FUNCTION: dynamic_draw1
DESCRIPTION: ��̬��ѯ�������
INPUT: ��
RETURN: ��
***********************************/
void dynamic_draw1(void)
{
    clrmous(MouseX, MouseY);
    delay(30);
    cleardevice();

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
    rectangle(60, 120, 210, 150);
    rectangle(220, 120, 370, 150);
    rectangle(380, 120, 530, 150);

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
    puthz(270, 30, "��Ʊ��Ϣ", 16, 18, 8);
    puthz(360, 30, "��������", 16, 18, 8);
    puthz(450, 30, "�������", 16, 18, 8);
    puthz(540, 30, "��̬��ѯ", 16, 18, 2);

    puthz(40, 170, "������", 16, 18, 9);
    puthz(140, 170, "���չ�˾", 16, 18, 9);
    puthz(240, 170, "��ɵ�����", 16, 18, 9);
    puthz(360, 170, "Ŀ�ĵ�����", 16, 18, 9);
    puthz(480, 170, "׼����", 16, 18, 9);
    //    puthz(400, 170, "���ò�Ʊ��", 16, 18, 9);

    //	puthz(595,5,"�˳�",16,18,1);
    puthz(75, 128, "����", 16, 18, 7);
    puthz(235, 128, "����", 16, 18, 7);
    puthz(385, 128, "����", 16, 18, 7);
    puthz(555, 128, "��ѯ", 16, 18, 6);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(60, 80, 200, 110);
    setcolor(RED);
    rectangle(60, 80, 200, 110);
    setcolor(BROWN);
    rectangle(220, 80, 380, 110);
    rectangle(400, 80, 540, 110);
    puthz(75, 88, "���ݳ��в�ѯ", 16, 18, BLUE);
    puthz(235, 88, "���ݺ���Ų�ѯ", 16, 18, BLUE);
    puthz(415, 88, "ʵʱ�����ѯ", 16, 18, BLUE);
    //	rectangle(550,107,595,149);
    puthz(545, 452, "��һҳ", 16, 18, 1);
    puthz(45, 452, "��һҳ", 16, 18, 1);
}