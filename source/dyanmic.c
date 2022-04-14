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
DESCRIPTION: 根据城市和日期查询主函数
INPUT: *func
RETURN: 无
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
    TNode node;              //机票节点
    Ticket t_list[List_len]; //机票信息队列
    char *city[] = {
        "北京", "上海", "广州", "成都",
        "深圳", "昆明", "西安", "重庆",
        "杭州", "南京", "武汉", "天津"};
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

        //鼠标点击翻页
        //下一页
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

        //上一页
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

        //出发地选择
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
                if (state2 == 0) //若菜单未展开
                {
                    city_select_page(60, 154);
                    state2 = 1;
                    delay(120);
                }
                else if (state2 == 1) //若菜单已展开
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
        //出发地城市鼠标操作
        if (state2 == 1)
        {
            if (MouseX > 60 && MouseX < 60 + 300 && MouseY > 154 && MouseY < 154 + 140)
            {
                //北京
                if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 0, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 0, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 1; //城市1
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

                //上海
                if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 0, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 0, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 2; //城市2
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

                //广州
                if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 0, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 0, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 3; //城市3
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

                //成都
                if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 0, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 0, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    laucity = 4; //城市4
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

                //深圳
                if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 1, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 1, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 5; //城市5
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

                //昆明
                if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 1, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 1, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 6; //城市6
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

                //西安
                if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 1, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 1, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 7; //城市7
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

                //重庆
                if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 1, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 1, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    laucity = 8; //城市8
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

                //杭州
                if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 2, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;

                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 0, 154 + 20 + 40 * 2, 60 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 9; //城市9
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

                //南京
                if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 2, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(60 + 20 + 70 * 1, 154 + 20 + 40 * 2, 60 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 10; //城市10
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

                //武汉
                if (mouse_press(60 + 20 + 70 * 2, 154 + 20 + 40 * 2, 60 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                    continue;
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 11; //城市11
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

                //天津
                if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 2, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                    continue;
                }
                else if (mouse_press(60 + 20 + 70 * 3, 154 + 20 + 40 * 2, 60 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    laucity = 12; //城市12
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

        //目的地选择
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

        //目的地城市鼠标操作
        if (state2 == 2)
        {
            if (MouseX > 220 && MouseX < 220 + 300 && MouseY > 154 && MouseY < 154 + 140)
            {
                //北京
                if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 0, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 0, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 1; //城市1
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

                //上海
                if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 0, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 0, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 2; //城市2
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

                //广州
                if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 0, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 0, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 3; //城市3
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

                //成都
                if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 0, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 0, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 0 + 20) == 1)
                {
                    decity = 4; //城市4
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

                //深圳
                if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 1, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 1, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 5; //城市5
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

                //昆明
                if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 1, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 1, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 6; //城市6
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

                //西安
                if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 1, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 1, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 7; //城市7
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

                //重庆
                if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 1, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*3,154+20+40*0,220+20+70*3+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 1, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 1 + 20) == 1)
                {
                    decity = 8; //城市8
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

                //杭州
                if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 2, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*0,154+20+40*0,220+20+70*0+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 0, 154 + 20 + 40 * 2, 220 + 20 + 70 * 0 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 9; //城市9
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

                //南京
                if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 2, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                    //	city_select_lightup(220+20+70*1,154+20+40*0,220+20+70*1+50,154+20+40*0+20);
                }
                else if (mouse_press(220 + 20 + 70 * 1, 154 + 20 + 40 * 2, 220 + 20 + 70 * 1 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 10; //城市10
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

                //武汉
                if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    //	city_select_lightup(220+20+70*2,154+20+40*0,220+20+70*2+50,154+20+40*0+20);
                    continue;
                }
                else if (mouse_press(220 + 20 + 70 * 2, 154 + 20 + 40 * 2, 220 + 20 + 70 * 2 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 11; //城市11
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

                //天津
                if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 2, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 2)
                {
                    MouseS = 1;
                    continue;
                }
                else if (mouse_press(220 + 20 + 70 * 3, 154 + 20 + 40 * 2, 220 + 20 + 70 * 3 + 50, 154 + 20 + 40 * 2 + 20) == 1)
                {
                    decity = 12; //城市12
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

        //日期
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
        //日期选择鼠标操作
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
                        MouseS = 0; //防止重复点亮
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
                                puthz(410, 126, "月", 16, 18, GREEN);
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

        //航班号查询按键
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
        //实时航班信息查询按键
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

        //查询键
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
                free(node.ticket_info);
                *func = 4;
                return;
            }
        }

        //跳转至个人中心界面
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
                free(node.ticket_info);
                *func = 8;
                return;
            }
        }

        //退出键
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
DESCRIPTION: 根据航班号查询主函数
INPUT: *func
RETURN: 无
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
    TNode node;                      //机票节点
    Ticket t_list[List_len_dynamic]; //机票信息队列

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

        //鼠标点击翻页
        //下一页
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

        //上一页
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

        //航班号输入框
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

        //城市日期查询按键
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

        //实时航班信息查询按键
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

        //查询键
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
                        puthz(420, 122, "航班不存在", 16, 18, RED);
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
                free(node.ticket_info);
                *func = 4;
                return;
            }
        }

        //跳转至个人中心界面
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
                free(node.ticket_info);
                *func = 8;
                return;
            }
        }

        //退出键
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
DESCRIPTION: 遮盖原有机票列表
INPUT: *node，flag,page_rest
RETURN: 无
***********************************/
void ticket_cover_dynamic(void)
{
    clrmous(MouseX, MouseY);

    setfillstyle(SOLID_FILL, WHITE);
    bar(1, 152, 640, 479);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 160, 640, 200);
    puthz(40, 170, "航班编号", 16, 18, 9);
    puthz(140, 170, "航空公司", 16, 18, 9);
    puthz(240, 170, "起飞地天气", 16, 18, 9);
    puthz(360, 170, "目的地天气", 16, 18, 9);
    puthz(480, 170, "准点率", 16, 18, 9);
    //    puthz(400, 170, "经济舱票价", 16, 18, 9);

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

    puthz(545, 452, "下一页", 16, 18, 1);
    puthz(45, 452, "上一页", 16, 18, 1);
}

/***********************************
FUNCTION: ticket_cover_dynamic
DESCRIPTION: 遮盖原有机票列表
INPUT: *node，flag,page_rest
RETURN: 无
***********************************/
void ticket_cover_dynamic_number(void)
{
    clrmous(MouseX, MouseY);

    setfillstyle(SOLID_FILL, WHITE);
    bar(1, 152, 640, 479);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 160, 640, 200);
    puthz(40, 170, "航班编号", 16, 18, 9);
    puthz(140, 170, "航空公司", 16, 18, 9);
    puthz(240, 170, "起飞地天气", 16, 18, 9);
    puthz(360, 170, "目的地天气", 16, 18, 9);
    puthz(480, 170, "准点率", 16, 18, 9);
    puthz(580, 170, "日期", 16, 18, 9);
    //    puthz(400, 170, "经济舱票价", 16, 18, 9);

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

    puthz(545, 452, "下一页", 16, 18, 1);
    puthz(45, 452, "上一页", 16, 18, 1);
}

/***********************************
FUNCTION: ticket_display_dynamic
DESCRIPTION: 展示机票
INPUT: *node，flag,page_rest
RETURN: 无
***********************************/
void ticket_display_dynamic(TNode *node, int flag, int page_rest, int mode)
{
    int i;

    setcolor(BROWN);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    settextjustify(LEFT_TEXT, TOP_TEXT);

    if (mode == 1) //按照城市查询，不输出日期
    {
        if (flag == 1 && strlen(node->ticket_info[0].number) != 0) //不是最后一页
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
        else if (flag == 2 && strlen(node->ticket_info[0].number) != 0) //是最后一页
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

    if (mode == 2) //按照航班号查询，输出日期
    {
        if (flag == 1 && strlen(node->ticket_info[0].number) != 0) //不是最后一页
        {
            for (i = 0; i < MaxSize; i++)
            {
                outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
                puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
                puthz(280, 200 + 3 + i * 30, node->ticket_info[i].weather1, 16, 18, 6);
                puthz(400, 200 + 3 + i * 30, node->ticket_info[i].weather2, 16, 18, 6);
                outtextxy(490, 200 + i * 30, node->ticket_info[i].rate);
                outtextxy(575, 200 + i * 30, node->ticket_info[i].date);
                puthz(611, 200 + i * 30 + 3, "号", 16, 18, 6);
            }
        }
        else if (flag == 2 && strlen(node->ticket_info[0].number) != 0) //是最后一页
        {
            for (i = 0; i < page_rest; i++)
            {
                outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
                puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
                puthz(280, 200 + 3 + i * 30, node->ticket_info[i].weather1, 16, 18, 6);
                puthz(400, 200 + 3 + i * 30, node->ticket_info[i].weather2, 16, 18, 6);
                outtextxy(490, 200 + i * 30, node->ticket_info[i].rate);
                outtextxy(575, 200 + i * 30, node->ticket_info[i].date);
                puthz(611, 200 + i * 30 + 3, "号", 16, 18, 6);
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
        puthz(x1 + 15, y1 + 8, "根据城市查询", 16, 18, BLUE);
        break;
    }

    case 2:
    {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x1, y1, x2, y2);
        setcolor(RED);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "根据航班号查询", 16, 18, BLUE);
        break;
    }

    case 3:
    {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x1, y1, x2, y2);
        setcolor(RED);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "实时航班查询", 16, 18, BLUE);
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
        puthz(x1 + 15, y1 + 8, "根据城市查询", 16, 18, BLUE);
        break;
    }

    case 2:
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(x1, y1, x2, y2);
        setcolor(BROWN);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "根据航班号查询", 16, 18, BLUE);
        break;
    }

    case 3:
    {
        setfillstyle(SOLID_FILL, WHITE);
        bar(x1, y1, x2, y2);
        setcolor(BROWN);
        rectangle(x1, y1, x2, y2);
        puthz(x1 + 15, y1 + 8, "实时航班查询", 16, 18, BLUE);
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
DESCRIPTION: 动态查询界面绘制
INPUT: 无
RETURN: 无
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
    puthz(65, 20, "航旅纵横", 32, 35, 4);
    puthz(270, 30, "机票信息", 16, 18, 8);
    puthz(360, 30, "个人中心", 16, 18, 8);
    puthz(450, 30, "疫情防控", 16, 18, 8);
    puthz(540, 30, "动态查询", 16, 18, 2);

    puthz(40, 170, "航班编号", 16, 18, 9);
    puthz(140, 170, "航空公司", 16, 18, 9);
    puthz(240, 170, "起飞地天气", 16, 18, 9);
    puthz(360, 170, "目的地天气", 16, 18, 9);
    puthz(480, 170, "准点率", 16, 18, 9);
    puthz(580, 170, "日期", 16, 18, 9);
    puthz(75, 128, "输入航班号", 16, 18, 7);
    puthz(555, 128, "查询", 16, 18, 6);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(220, 80, 380, 110);
    setcolor(RED);
    rectangle(60, 80, 200, 110);
    setcolor(BROWN);
    rectangle(220, 80, 380, 110);
    rectangle(400, 80, 540, 110);
    puthz(75, 88, "根据城市查询", 16, 18, BLUE);
    puthz(235, 88, "根据航班号查询", 16, 18, BLUE);
    puthz(415, 88, "实时航班查询", 16, 18, BLUE);
    puthz(545, 452, "下一页", 16, 18, 1);
    puthz(45, 452, "上一页", 16, 18, 1);
}

/***********************************
FUNCTION: dynamic_draw1
DESCRIPTION: 动态查询界面绘制
INPUT: 无
RETURN: 无
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
    puthz(65, 20, "航旅纵横", 32, 35, 4);
    puthz(270, 30, "机票信息", 16, 18, 8);
    puthz(360, 30, "个人中心", 16, 18, 8);
    puthz(450, 30, "疫情防控", 16, 18, 8);
    puthz(540, 30, "动态查询", 16, 18, 2);

    puthz(40, 170, "航班编号", 16, 18, 9);
    puthz(140, 170, "航空公司", 16, 18, 9);
    puthz(240, 170, "起飞地天气", 16, 18, 9);
    puthz(360, 170, "目的地天气", 16, 18, 9);
    puthz(480, 170, "准点率", 16, 18, 9);
    //    puthz(400, 170, "经济舱票价", 16, 18, 9);

    //	puthz(595,5,"退出",16,18,1);
    puthz(75, 128, "出发", 16, 18, 7);
    puthz(235, 128, "到达", 16, 18, 7);
    puthz(385, 128, "日期", 16, 18, 7);
    puthz(555, 128, "查询", 16, 18, 6);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(60, 80, 200, 110);
    setcolor(RED);
    rectangle(60, 80, 200, 110);
    setcolor(BROWN);
    rectangle(220, 80, 380, 110);
    rectangle(400, 80, 540, 110);
    puthz(75, 88, "根据城市查询", 16, 18, BLUE);
    puthz(235, 88, "根据航班号查询", 16, 18, BLUE);
    puthz(415, 88, "实时航班查询", 16, 18, BLUE);
    //	rectangle(550,107,595,149);
    puthz(545, 452, "下一页", 16, 18, 1);
    puthz(45, 452, "上一页", 16, 18, 1);
}