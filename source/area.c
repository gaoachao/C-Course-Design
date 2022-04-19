/***********************************
FILE：area.h
DESCRIPTION: 旅客过往地区查询
***********************************/
#include <stdio.h>
#include <direct.h>
#include <graphics.h>
#include <bios.h>
#include <dos.h>
#include <string.h>
#include <time.h>
#include <io.h>
#include <stdlib.h>
#include <conio.h>
#include "hz.h"
#include "mouse.h"
#include "database.h"
#include "queue.h"
#include "register.h"
#include "reserve.h"
#include "buypage.h"
#include "menu.h"
#include "purchase.h"
#include "pay.h"
#include "booked.h"
#include "payment.h"
#include "upload.h"
#include "up.h"
#include "htinfo.h"
#include "history.h"
#include "hesuan.h"
#include "area.h"
#define city_len 12

/***********************************
FUNCTION: area_main
DESCRIPTION: 核酸结果上报
INPUT: 无
RETURN: 无
***********************************/
void area_main(int *func, USER *u)
{
  City c[city_len];
  Hold h_list[List_len];
  int num = 0;
  int len = 0;
  memset(h_list, '\0', sizeof(Hold) * List_len);
  holdinfo_read(u, h_list);
  len = holdinfo_read(u, h_list); //读入的历史购买机票数目

  city_read(c);
  area_draw();
  get_username(u);
  get_city_dangerlevel(h_list, c , len);
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //退出键
    if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
    {
      if (mouse_press(595, 0, 640, 20) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(595, 0, 640, 20) == 1)
      {
        *func = 1;
        return;
      }
    }
    //返回前页键
    if (MouseX > 460 && MouseX < 550 && MouseY > 390 && MouseY < 425)
    {
      if (mouse_press(460, 390, 550, 425) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_hesuan(460, 390, 550, 425, 1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(460, 390, 550, 425) == 1)
      {
        *func = 8;
        return;
      }
    }
    //恢复点亮
    if (num != 0)
    {
      if (num == 1)
      {
        recover_hesuan(460, 390, 550, 425, 1);
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
/***********************************
FUNCTION: get_username
DESCRIPTION: 获得用户姓名
INPUT: 无
RETURN: 无
***********************************/
void get_username(USER *u)
{
  setcolor(DARKGRAY);
  outtextxy(295, 115, u->name);
}


/***********************************
FUNCTION: get_city_dangerlevel
DESCRIPTION: 得到过往地区
INPUT: Hold *h_list, int len
RETURN: 无
***********************************/
void get_city_dangerlevel(Hold *h_list, City *c, int len)
{
  int i, j;
  int m,n;
  int k = 1;
  int flag = 0;
  puthz(175, 180, h_list[0].city2, 16, 18, 6);
  for (n = 0; n < city_len; n++)
  {
    if (strcmp(h_list[0].city2, c[n].city_name) == 0)
    {
      puthz(315, 180, c[n].level, 16, 18, 6);
    }
  }
  for (i = 1; i < len; i++)
  {
    for (j = 0; j < i; j++)
    {
      if (strcmp(h_list[j].city2, h_list[i].city2) == 0)
      {
        flag = 1;
      }
    }
    if (flag == 0)
    {
      puthz(175, 180 + k * 30, h_list[i].city2, 16, 18, 6);
      for (m = 0; m < city_len; m++)
      {
        if (strcmp(h_list[i].city2, c[m].city_name) == 0)
        {
          puthz(315, 180+k * 30, c[m].level, 16, 18, 6);
        }
      }
      k++;
    }
    flag = 0;
  }
}

/***********************************
FUNCTION: area_draw
DESCRIPTION: 购票记录界面绘制
INPUT: 无
RETURN: 无
***********************************/
void area_draw(void)
{
  clrmous(MouseX, MouseY);
  delay(30);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setcolor(YELLOW);
  arc(0, 320, 0, 360, 100);
  setfillstyle(SOLID_FILL, YELLOW);
  fillellipse(0, 320, 100, 100);
  setcolor(GREEN);
  arc(0, 480, 0, 75, 160);
  setfillstyle(SOLID_FILL, GREEN);
  fillellipse(0, 480, 160, 160);
  puthz(85, 20, "旅客过往地区", 32, 35, 4);
  puthz(86, 21, "旅客过往地区", 32, 35, 4);
  puthz(165, 120, "用户姓名：", 16, 18, 1);
  puthz(165, 150, "过往地区", 16, 18, 1);
  puthz(305, 150, "风险等级", 16, 18, 1);
  puthz(470, 400, "返回前页", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(460, 390, 550, 425);
  setcolor(DARKGRAY);
  rectangle(120, 90, 530, 360);
  rectangle(125, 85, 535, 355);
}
