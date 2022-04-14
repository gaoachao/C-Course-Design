#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>
#include <time.h>
#include <bios.h>
#include <conio.h>
#include "mouse.h"
#include "hz.h"
#include "database.h"
#include "dynamic.h"
#include "register.h"
#include "buypage.h"
#include "login.h"
#include "flgstate.h"
#include "menu.h"

/***********************************
FUNCTION: state_consult_main
DESCRIPTION: 航班状态查询列表界面
INPUT: *func
RETURN: node.delay_state
***********************************/
void state_consult_main(int *func, Ticket *t, int *flag)
{
    int num = 0;
    int i, j, prepage = 0;

    int key;
    int len = 0, page_num = 0, page_rest = 0;
    int state1 = 0;
    int state2 = 0;
    //  int click_state = 0;
    int decity = 0, laucity = 0;
    int delay_list[List_len];

    char date[3] = "\0";
    TNode node;              //机票节点
    Ticket t_list[List_len]; //机票信息队列
    char *city[] = {
        "北京", "上海", "广州", "成都",
        "深圳", "昆明", "西安", "重庆",
        "杭州", "南京", "武汉", "天津"};

    initQueue(&node);

    state_consult_draw();

    exit_buttom();

    memset(t, '\0', sizeof(Ticket));

    memset(t_list, '\0', List_len * sizeof(Ticket));

    for (i = 0; i < List_len; i++)
    {
        delay_list[i] = 2;
    }

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
                    ticket_cover_state();
                    queue_down(&prepage, page_num);
                    enqueue_delay(&node, t_list, prepage, delay_list);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
                        delay(120);
                    }
                }
            }
            if (key == Key_Up)
            {
                if (strlen(t_list[0].number) != 0)
                {
                    ticket_cover_state();
                    queue_up(&prepage, page_num);
                    enqueue_delay(&node, t_list, prepage, delay_list);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
                        delay(120);
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
                    ticket_cover_state();
                    queue_down(&prepage, page_num);
                    enqueue_delay(&node, t_list, prepage, delay_list);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
                        delay(120);
                    }
                }
            }
        }

        //上一页
        if (mouse_press(40, 450, 100, 470) == 1)
        {
            if (strlen(t_list[0].number) != 0)
            {
                ticket_cover_state();
                queue_up(&prepage, page_num);
                enqueue_delay(&node, t_list, prepage, delay_list);
                if (prepage + 1 < page_num)
                {
                    state_display(&node, 1, page_rest);
                    delay(120);
                }
                else if (prepage + 1 == page_num)
                {
                    state_display(&node, 2, page_rest);
                    delay(120);
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
                    ticket_cover_state();
                    state2 = 0;
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(61, 121, 209, 149);
                    puthz(75, 129, city[laucity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();
                    state2 = 0;

                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
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
                    ticket_cover_state();

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(221, 121, 369, 149);
                    puthz(235, 129, city[decity - 1], 16, 18, BLUE);
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(120);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
                        delay(120);
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
                    num = 1;
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

        //查询键
        if (MouseX > 550 && MouseX < 595 && MouseY > 127 && MouseY < 149)
        {
            if (mouse_press(550, 127, 595, 149) == 2)
            {
                MouseS = 1;
            }
            else if (mouse_press(550, 127, 595, 149) == 1)
            {
                get_date(date);
                if (laucity != 0 && decity != 0)
                {
                    MouseS = 1;
                    get_date(date);
                    len = ticketinfo_read(t_list, city[laucity - 1], city[decity - 1], date);
                    buypage_count(&page_num, &page_rest, len);
                    delay_list_make(delay_list, t_list, len);
                    prepage = 0;
                    enqueue_delay(&node, t_list, prepage, delay_list);
                    ticket_cover_state();
                    if (prepage + 1 < page_num)
                    {
                        state_display(&node, 1, page_rest);
                        delay(100);
                    }
                    else if (prepage + 1 == page_num)
                    {
                        state_display(&node, 2, page_rest);
                        delay(100);
                    }
                }
            }
        }

        //查看键
        if (prepage + 1 < page_num)
        {
            if (mouse_press(590, 203, 635, 227 + 30 * 7) == 2) // MouseX>590&&MouseX<635&&MouseY>203&&MouseY<227+30*8)
            {
                for (i = 0; i < MaxSize; i++)
                {
                    if (mouse_press(590, 203 + 30 * i, 635, 227 + 30 * i) == 2)
                    {
                        MouseS = 1;
                    }
                    continue;
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
                        *flag = node.t_delay[i];
                        free(node.ticket_info);
                        *func = 22;

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
                    }
                    continue;
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
                        *flag = node.t_delay[i];
                        free(node.ticket_info);
                        *func = 22;

                        return;
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
            if (num == 1)
            {
                recoverlightup_dynamic(60, 80, 200, 110, 1);
            }
            if (num == 2)
            {
                recoverlightup_dynamic(220, 80, 380, 110, 2);
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
            state1 = 0;
        }

        if (MouseS != 0)
        {
            MouseS = 0;
        }
    }
}

void detail_consult_main(int *func, Ticket t, int delay_state) //, int *func)
{
    char ttmep[40];
    int hour1, hour2;
    int min1, min2, min1temp;
    int num = 0;

    memset(ttmep, '\0', sizeof(ttmep));
    get_time(ttmep);
    get_h_min(&hour1, &min1);
    min1temp = min1;

    detail_consult_draw(t, delay_state, hour1, min1);
    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        display_time(20, 400, ttmep);

        get_h_min(&hour1, &min1);
        if (min1temp + 2 == min1)
        {
            detail_consult_draw(t, delay_state, hour1, min1);
            min1temp = min1;
        }

        if (MouseX > 390 && MouseX < 520 && MouseY > 400 && MouseY < 430)
        {
            if (mouse_press(390, 400, 520, 430) == 2)
            {
                if (num == 0)
                {
                    lightup_register(390, 400, 520, 430, 3);
                    num = 1;
                }
                continue;
            }
            else if (mouse_press(390, 400, 520, 430) == 1)
            {
                *func = 17;
                return;
            }
        }

        if (num != 0)
        {
            recoverbuttom_register(390, 400, 520, 430, 3);
            num = 0;
        }

        if (MouseS != 0)
        {
            MouseS = 0;
        }
    }
}

/***********************************
FUNCTION: delay_judge
DESCRIPTION: 判断是否晚点
INPUT: *landtine,*rate
RETURN: 1(晚点)/0(准点)
***********************************/
int delay_judge(char *landtime, char *rate)
{
    int i, ran = 0;
    char ch;
    char rate_num[3] = "\0";
    int h = 0, min = 0;
    char hour[3] = "\0", minute[3] = "\0";
    char timestr[6];
    memset(timestr, '\0', sizeof(timestr));

    for (i = 0; rate[i] != '%'; i++)
    {
        rate_num[i] = rate[i];
    }

    i = atoi(rate_num);

    ran = rand() % 100;
    if (ran >= i) //视为晚点,着陆时间延迟两个小时
    {
        read_time(&h, &min, landtime);
        h += 2;
        itoa(h, hour, 10);
        itoa(min, minute, 10);
        strcpy(timestr, hour);
        strcat(timestr, ":");
        strcat(timestr, minute);
        strcpy(landtime, timestr);
        return 1;
    }
    else
        return 0;
}

/***********************************
FUNCTION: state_display
DESCRIPTION: 展示机票
INPUT: *node，flag,page_rest
RETURN: 无
***********************************/
void state_display(TNode *node, int flag, int page_rest)
{
    int i, f = 0;
    int hour1 = 0, hour2 = 0, hour3 = 0;
    int minute1 = 0, minute2 = 0, minute3 = 0;

    setcolor(BROWN);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    settextjustify(LEFT_TEXT, TOP_TEXT);

    get_h_min(&hour1, &minute1);

    srand(time(NULL));

    if (flag == 1 && strlen(node->ticket_info[0].number) != 0) //不是最后一页
    {
        for (i = 0; i < MaxSize; i++)
        {
            if (node->t_delay[i] == 1)
            {
                puthz(360, 200 + 3 + i * 30, "晚点", 16, 18, 6);
            }
            else if (node->t_delay[i] == 0)
            {
                puthz(360, 200 + 3 + i * 30, "准点", 16, 18, 6);
            }
            hour2 = 0;
            minute2 = 0;
            f = 0;
            read_time(&hour2, &minute2, node->ticket_info[i].land_time);
            read_time(&hour3, &minute3, node->ticket_info[i].launch_time);
            outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
            puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
            if (hour1 <= hour3 && minute1 <= minute3)
            {
                puthz(240, 200 + 3 + i * 30, "未起飞", 16, 18, 6);
                f = 1;
            }
            if (hour1 >= hour2 && minute1 >= minute2 && f != 1)
            {
                puthz(240, 200 + 3 + i * 30, "已着陆", 16, 18, 6);
                f = 2;
            }
            if (f == 0)
            {
                outtextxy(240, 200 + i * 30, node->ticket_info[i].land_time);
            }

            outtextxy(440, 200 + i * 30, node->ticket_info[i].tower);
            setfillstyle(10, LIGHTGRAY);
            bar(590, 203 + 30 * i, 635, 227 + 30 * i);
            rectangle(590, 203 + 30 * i, 635, 227 + 30 * i);
            puthz(596, 206 + 30 * i, "查看", 16, 18, BLUE);
        }
    }
    else if (flag == 2 && strlen(node->ticket_info[0].number) != 0) //是最后一页
    {
        for (i = 0; i < page_rest; i++)
        {
            if (node->t_delay[i] == 1)
            {
                puthz(360, 200 + 3 + i * 30, "晚点", 16, 18, 6);
            }
            else if (node->t_delay[i] == 0)
            {
                puthz(360, 200 + 3 + i * 30, "准点", 16, 18, 6);
            }
            hour2 = 0;
            minute2 = 0;
            f = 0;
            read_time(&hour2, &minute2, node->ticket_info[i].land_time);
            read_time(&hour3, &minute3, node->ticket_info[i].launch_time);
            outtextxy(50, 200 + i * 30, node->ticket_info[i].number);
            puthz(160, 200 + 3 + i * 30, node->ticket_info[i].company, 16, 18, 6);
            if (hour1 <= hour3 && minute1 <= minute3)
            {
                puthz(240, 200 + 3 + i * 30, "未起飞", 16, 18, 6);
                f = 1;
            }
            if (hour1 >= hour2 && minute1 >= minute2 && f != 1)
            {
                puthz(240, 200 + 3 + i * 30, "已着陆", 16, 18, 6);
                f = 2;
            }
            if (f == 0)
            {
                outtextxy(240, 200 + i * 30, node->ticket_info[i].land_time);
            }
            outtextxy(440, 200 + i * 30, node->ticket_info[i].tower);
            setfillstyle(10, LIGHTGRAY);
            bar(590, 203 + 30 * i, 635, 227 + 30 * i);
            rectangle(590, 203 + 30 * i, 635, 227 + 30 * i);
            puthz(596, 206 + 30 * i, "查看", 16, 18, BLUE);
        }
    }
}

/***********************************
FUNCTION: delay_list_make
DESCRIPTION: 构造晚点航班列表
INPUT: *delay_list,*ticket_list,len
RETURN: 无
***********************************/
void delay_list_make(int *delay_list, Ticket *ticket_list, int len)
{
    int i;
    for (i = 0; i < List_len; i++)
    {
        delay_list[i] = 2;
    }
    for (i = 0; i < len; i++)
    {
        delay_list[i] = delay_judge(ticket_list[i].land_time, ticket_list[i].rate);
    }
}

/***********************************
FUNCTION: get_date
DESCRIPTION: 获取当天日期
INPUT: *date
RETURN: 无
***********************************/
void get_date(char *date)
{
    time_t lt;
    struct tm *ptr;
    char day[3];
    char first; //,second;

    memset(date, '\0', sizeof(date));

    lt = time(NULL);
    ptr = localtime(&lt); //获取本地时间

    strftime(day, 5, "%d", ptr);

    if (day[0] == '0')
    {
        first = day[1];
        day[0] = first;
        day[1] = '\0';
    }
    strcpy(date, day);
}

/***********************************
FUNCTION: read_time
DESCRIPTION: 获取机票时间
INPUT: *date
RETURN: 无
***********************************/
void read_time(int *h, int *min, char *time)
{
    char hour[3] = "\0", minute[3] = "\0";
    char ch;

    if (time[1] == ':') //小时是一位数
    {
        //读小时
        ch = time[0];
        hour[0] = ch;

        //读分钟
        ch = time[2];
        minute[0] = ch;
        ch = time[3];
        minute[1] = ch;
    }
    else if (time[2] == ':') //小时是两位数
    {
        //读小时
        ch = time[0];
        hour[0] = ch;
        ch = time[1];
        hour[1] = ch;

        //读分钟
        ch = time[3];
        minute[0] = ch;
        ch = time[4];
        minute[1] = ch;
    }

    *h = atoi(hour);
    *min = atoi(hour);
}

/***********************************
FUNCTION: get_h_min
DESCRIPTION: 获取实时小时和分钟
INPUT: *date
RETURN: 无
***********************************/
void get_h_min(int *h, int *min)
{
    time_t lt;
    struct tm *ptr;
    char hour[3], minute[3];
    char first; //,second;

    memset(hour, '\0', sizeof(hour));
    memset(minute, '\0', sizeof(minute));

    lt = time(NULL);
    ptr = localtime(&lt); //获取本地时间

    strftime(hour, 3, "%H", ptr);
    strftime(minute, 3, "%M", ptr);

    if (hour[0] == '0')
    {
        first = hour[1];
        hour[0] = first;
        hour[1] = '\0';
    }
    if (minute[0] == '0')
    {
        first = minute[1];
        minute[0] = first;
        minute[1] = '\0';
    }

    *h = atoi(hour);
    *min = (atoi(minute));
}

/***********************************
FUNCTION: ticket_cover_state
DESCRIPTION: 遮盖原有机票列表
INPUT: *node，flag,page_rest
RETURN: 无
***********************************/
void ticket_cover_state(void)
{
    clrmous(MouseX, MouseY);

    setfillstyle(SOLID_FILL, WHITE);
    bar(1, 152, 640, 479);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 160, 640, 200);
    puthz(40, 170, "航班编号", 16, 18, 9);
    puthz(140, 170, "航空公司", 16, 18, 9);
    puthz(240, 170, "预计到达", 16, 18, 9);
    puthz(340, 170, "是否准时", 16, 18, 9);
    puthz(440, 170, "航站楼", 16, 18, 9);

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
FUNCTION: detail_consult_draw
DESCRIPTION: 绘制飞机详细位置
INPUT: t,delay_state,hour1,min1
RETURN: 无
***********************************/
void detail_consult_draw(Ticket t, int delay_state, int hour1, int min1)
{
    int hour2, min2; //起飞时间
    int hour3, min3; //着陆时间
    float percent = 0;
    char remain[9];

    memset(remain, '\0', sizeof(remain));
    read_time(&hour2, &min2, t.launch_time);
    read_time(&hour3, &min3, t.land_time);

    clrmous(MouseX, MouseY);
    delay(30);
    cleardevice();
    setbkcolor(WHITE);
/*    setbkcolor(RED);
    printf("h2=%d\t,m2=%d\n", hour2, min2);
    printf("h3=%d\t,m3=%d\n", hour3, min3);*

    if (hour1 <= 18 && hour1 >= 6)
    {
        //绘制太阳
        setcolor(RED);
        circle(70, 70, 50);
        circle(70, 70, 51);
        circle(70, 70, 49);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(70, 70, RED);
    }
    else
    {
        //绘制月亮
        setcolor(BROWN);
        arc(500, 70, 269, 91, 50);
        arc(500, 70 + 1, 270, 90, 50);
        arc(500, 70 - 1, 270, 90, 50);
        arc(450, 70, 314, 46, 71);
        arc(450, 70 + 1, 315, 45, 71);
        arc(450, 70 - 1, 315, 45, 71);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(548, 70, BROWN);
    }

    //绘制飞机
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(100, 150, 540, 250);
    rectangle(100, 150, 540, 250);
    rectangle(99, 149, 541, 251);
    setcolor(YELLOW);
    line(120, 200, 520, 200);
    line(120, 200 + 1, 520, 200 + 1);
    line(120, 200 - 1, 520, 200 - 1);
    line(520, 200, 500, 210);
    line(520 - 1, 200, 500 - 1, 210);
    line(520 + 1, 200, 500 + 1, 210);
    fly_pos(hour1, min1, hour2, min2, hour3, min3, &percent);
    /*    draw_plane(490, 190);
        draw_plane(120, 190);*/

    //航班信息
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setcolor(LIGHTGRAY);
    puthz(120, 210, "总里程", 16, 18, RED);
    outtextxy(185, 204, t.distance);

    if (delay_state == 1) //晚点
    {
        puthz(100, 270, "晚点", 16, 18, GREEN);
    }
    if (delay_state == 0) //准点
    {
        puthz(100, 270, "准点", 16, 18, GREEN);
    }
    if (hour1 <= hour2 && min1 < min2)
    {
        puthz(170, 270, "起飞时间", 16, 18, BLUE);
        outtextxy(255, 264, t.launch_time);
        puthz(370, 270, "未起飞", 16, 18, BLUE);
    }
    else if (hour1 >= hour3 && min1 >= min3)
    {
        puthz(170, 270, "着陆时间", 16, 18, BLUE);
        outtextxy(255, 264, t.land_time);
        puthz(370, 270, "已着陆", 16, 18, BLUE);
    }
    else
    {
        time_remain(hour1, min1, hour3, min3, remain);
        puthz(170, 270, "未到达", 16, 18, BLUE);
        puthz(370, 270, "剩余时间", 16, 18, BLUE);
        outtextxy(455, 264, remain);
        puthz(320, 210, "已飞行", 16, 18, RED);
        distance_remain(t.distance, percent);
    }

    puthz(110, 130, "航班号", 16, 18, BLUE);
    outtextxy(175, 124, t.number);
    puthz(290, 130, "出发地", 16, 18, BLUE);
    puthz(350, 130, t.city1, 16, 18, LIGHTGRAY);
    puthz(410, 130, "目的地", 16, 18, BLUE);
    puthz(470, 130, t.city2, 16, 18, LIGHTGRAY);

    setlinestyle(0, 0, 1);
    setfillstyle(SOLID_FILL, WHITE);
    bar(390, 400, 520, 430);
    puthz(420, 404, "返回", 24, 46, 8);
    setcolor(LIGHTCYAN);
    rectangle(390, 400, 520, 430);
}

/***********************************
FUNCTION: distance_remain
DESCRIPTION: 画飞机实时位置
INPUT: *distance,percent
RETURN: 无
***********************************/
void distance_remain(char *distance, float percent)
{
    char remain[8] = "\0";
    char distan[5] = "\0";
    int dis = 0, distemp;
    int i;

    for (i = 0; distance[i] != 'k'; i++)
    {
        distan[i] = distance[i];
    }

    distemp = atoi(distan);
    dis = percent * (float)distemp;
    //   printf("per=%f\t,dis=%d\t,distemp=%d\n",percent,dis,distemp);
    itoa(dis, remain, 10);
    strcat(remain, "km");
    outtextxy(385, 204, remain);
}

/***********************************
FUNCTION: fly_pos
DESCRIPTION: 画飞机实时位置
INPUT: hour1,min1,hour2,min2, hour3,min3
RETURN: 无
***********************************/
void fly_pos(int hour1, int min1, int hour2, int min2, int hour3, int min3, float *percent)
{

    int time1;
    int time2;
    int time3;
    int pos = 0;
    if (hour1 <= hour2 && min1 < min2) //未起飞
    {
        draw_plane(120, 190);
    }
    else if (hour1 >= hour3 && min1 > min3) //未起飞
    {
        draw_plane(490, 190);
    }
    else
    {
        time1 = 60 * hour1 + min1; //当前时间
        time2 = 60 * hour2 + min2; //起飞时间
        time3 = 60 * hour3 + min3; //降落时间
        *percent = (float)(time1 - time2) / (time3 - time2);
        pos = (490 - 120) * (*percent);
        draw_plane(120 + pos, 190);
    }
}

/***********************************
FUNCTION: time_remain
DESCRIPTION: 计算剩余飞行时间
INPUT: hour1,min1,hour2,min2, *remain
RETURN: 无
***********************************/
void time_remain(int hour1, int min1, int hour2, int min2, char *remain)
{
    int time1, time2;
    int hour, minute;
    char h[3] = "\0", min[3] = "\0";

    memset(remain, '\0', sizeof(remain));
    //    setbkcolor(RED);

    time1 = 60 * hour1 + min1; //当前时间
    time2 = 60 * hour2 + min2; //着陆时间
    printf("1=%d\t2=%d\n", time1, time2);

    hour = (time2 - time1) / 60;
    minute = (time2 - time1) - 60 * hour;
    //    printf("h=%d\tmin=%d\n",hour,minute);

    itoa(hour, h, 10);
    itoa(minute, min, 10);
    strcpy(remain, h);
    strcat(remain, "h");
    strcat(remain, min);
    strcat(remain, "min");
}

/***********************************
FUNCTION: draw_plane
DESCRIPTION: 绘制小飞机
INPUT: x,y
RETURN: 无
***********************************/
void draw_plane(int x, int y)
{

    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    arc(x, y, 90, 270, 5);
    line(x, y + 5, x + 35, y + 5);
    line(x, y - 5, x + 25, y - 5);
    line(x + 25, y - 5, x + 35, y + 5);

    line(x + 20, y, x + 12, y);
    line(x + 12, y - 15, x + 12, y);
    line(x + 12, y - 15, x + 17, y - 15);
    line(x + 17, y - 15, x + 20, y);

    line(x, y - 5, x - 4, y - 13);
    line(x - 4, y - 13, x - 1, y - 13);
    line(x - 1, y - 13, x + 5, y - 5);
}

/***********************************
FUNCTION: state_consult_draw
DESCRIPTION: 实时位置查询列表绘制
INPUT: 无
RETURN: 无
***********************************/
void state_consult_draw(void)
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
    puthz(240, 170, "预计到达", 16, 18, 9);
    puthz(340, 170, "是否准时", 16, 18, 9);
    puthz(440, 170, "航站楼", 16, 18, 9);

    puthz(75, 128, "出发", 16, 18, 7);
    puthz(235, 128, "到达", 16, 18, 7);
    //    puthz(385, 128, "日期", 16, 18, 7);
    puthz(555, 128, "查询", 16, 18, 6);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(400, 80, 540, 110);
    setcolor(RED);
    rectangle(400, 80, 540, 110);
    setcolor(BROWN);
    rectangle(220, 80, 380, 110);
    rectangle(60, 80, 200, 110);
    puthz(75, 88, "根据城市查询", 16, 18, BLUE);
    puthz(235, 88, "根据航班号查询", 16, 18, BLUE);
    puthz(415, 88, "实时航班查询", 16, 18, BLUE);
    puthz(545, 452, "下一页", 16, 18, 1);
    puthz(45, 452, "上一页", 16, 18, 1);
}