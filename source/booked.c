/***********************************
FILE: booked.c
DESCRIPTION: 酒店订购支付界面
***********************************/
#include <stdio.h>
#include <direct.h>
#include <graphics.h>
#include <bios.h>
#include <dos.h>
#include <string.h>
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

/***********************************
FUNCTION: booked_main
DESCRIPTION: 购票主函数
INPUT: *func,*name,*id,t
RETURN: 无
***********************************/
void booked_main(int *func, USER *u, Hotle *h, Live *L)
{
  int num = 0;
  char filename[30];
  int live_day = 1; // int类型居住天数
  char liveday[3];  // char类型的居住天数
  FILE *fp;
  strcpy(liveday, "1");

  hotle_booked_draw(u->name, h->hotle_city, h->hotle_name, h->hotle_class, h->price);

  memset(L, '\0', sizeof(Live));
  delay(100);
  strcpy(filename, "database\\");
  strcat(filename, u->name);
  strcpy(L->city, h->hotle_city);
  strcpy(L->name, h->hotle_name);
  strcpy(L->price, h->price);
  strcpy(L->class, h->hotle_class);
  strcpy(L->day, liveday);
  
  //文件夹操作
  if (access(filename, 0) == -1) //文件夹不存在
  {
    if (mkdir(filename) != 0)
    {
      printf("The file news failed\n");
    }
  }
  strcat(filename, "\\live.dat");
  if (access(filename, 0) == -1) // live.dat文件不存在(已订购就信息)
  {
    if ((fp = fopen(filename, "wb+")) == NULL) //读写打开或建立一个二进制文件,若不存在会新建
    {
      printf("%s new failed\n", filename);
      delay(3000);
      exit(1);
    }
    if (fclose(fp) != 0)
    {
      printf("%s close failed\n", filename);
      delay(3000);
      exit(1);
    }
  }

  //刚进入页面进行一次健康状态的判断
  if (strcmp(u->health_code, "1") == 0)
  {
    puthz(255, 150, "绿码", 16, 18, 2);
  }
  else if (strcmp(u->health_code, "2") == 0)
  {
    puthz(255, 150, "黄码", 16, 18, 6);
  }
  else if (strcmp(u->health_code, "3") == 0)
  {
    puthz(255, 150, "红码", 16, 18, 4);
  }
  //鼠标操作
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
    //返回键
    if (MouseX > 435 && MouseX < 500 && MouseY > 390 && MouseY < 425)
    {
      if (mouse_press(435, 390, 500, 425) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_booked(435, 390, 500, 425, 2);
          num = 2;
        }
        continue;
      }
      else if (mouse_press(435, 390, 500, 425) == 1)
      {
        *func = 11;
        return;
      }
    }
    //确定支付界面
    if (MouseX > 250 && MouseX < 340 && MouseY > 390 && MouseY < 425)
    {
      if (mouse_press(250, 390, 340, 425) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_booked(250, 390, 340, 425, 1);
          num = 1;
        }
        continue;
      }
      else if (mouse_press(250, 390, 340, 425) == 1)
      {
        if (strcmp(u->health_code, "1") == 0)
        {
          puthz(300, 435, "绿码，可以入住", 16, 18, 8);
          *func = 18;
          delay(1000);
          return;
        }
        else if (strcmp(u->health_code, "2") == 0)
        {
          puthz(300, 435, "黄码，无法入住", 16, 18, 8);
        }
        else if (strcmp(u->health_code, "3") == 0)
        {
          puthz(300, 435, "红码，无法入住", 16, 18, 8);
        }
        else if (strcmp(u->health_code, "0") == 0)
        {
          puthz(300, 435, "健康状态尚未填报", 16, 18, 8);
        }
      }
    }

    //增加居住天数
    if (MouseX > 290 && MouseX < 310 && MouseY > 350 && MouseY < 365)
    {
      if (mouse_press(290, 350, 310, 365) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(290, 350, 310, 365) == 1)
      {
        live_day++;
        itoa(live_day, liveday, 10);
        strcpy(L->day, liveday);
        setfillstyle(SOLID_FILL, WHITE);
        bar(270, 340, 290, 375);
        setcolor(BLUE);
        outtextxy(275, 345, liveday);
        delay(200);
      }
    }

    //减少居住天数
    if (MouseX > 245 && MouseX < 265 && MouseY > 350 && MouseY < 365)
    {
      if (mouse_press(245, 350, 265, 365) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(245, 350, 265, 365) == 1)
      {
        live_day--;
        itoa(live_day, liveday, 10);
        strcpy(L->day, liveday);
        setfillstyle(SOLID_FILL, WHITE);
        bar(270, 340, 290, 375);
        setcolor(BLUE);
        outtextxy(275, 345, liveday);
        delay(200);
      }
    }

    //恢复点亮
    if (num != 0)
    {
      if (num == 1)
      {
        recover_booked(250, 390, 340, 425, 1);
      }
      if (num == 2)
      {
        recover_booked(435, 390, 500, 425, 2);
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
FUNCTION: lightup_booked
DESCRIPTION: 酒店信息确认界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_booked(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setcolor(LIGHTRED);
  setfillstyle(1, LIGHTGRAY);

  bar(x1, y1, x2, y2);                       //填充内部
  rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //画边框
  switch (flag)
  {
  case 1:
  {
    puthz(260, 400, "确认支付", 16, 18, 4);
    break;
  }

  case 2:
  {
    puthz(450, 400, "返回", 16, 18, 4);
    break;
  }
  case 3: //为payment.c服务
  {
    puthz(200, 350, "确定付款", 16, 18, 4);
    break;
  }

  default:
    printf("something wrong in loghtup_purchace_confirm\n");
    break;
  }
}

/***********************************
FUNCTION: recover_booked
DESCRIPTION: 酒店信息确认界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recover_booked(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setcolor(LIGHTCYAN);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x1, y1, x2, y2);
  rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
  switch (flag)
  {
  case 1:
  {
    puthz(260, 400, "确认支付", 16, 18, 5);
    break;
  }

  case 2:
  {
    puthz(450, 400, "返回", 16, 18, 5);
    break;
  }

  case 3: //为payment.c服务
  {
    puthz(200, 350, "确定付款", 16, 18, 1);
    break;
  }

  default:
  {
    printf("something wrong in recoverbuttom_purchace_confirmr\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: hotle_booked_draw
DESCRIPTION: 信息确认界面绘制
INPUT: *u,t
RETURN: 无
***********************************/
void hotle_booked_draw(char *name, char *hotle_city, char *hotle_name, char *hotle_class, char *price)
{
  cleardevice();
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setcolor(GREEN);
  arc(0, 480, 0, 75, 160);
  setfillstyle(SOLID_FILL, GREEN);
  fillellipse(0, 480, 160, 160);
  puthz(65, 20, "欢迎入住！", 32, 35, 4);
  puthz(160, 110, "旅客姓名：", 16, 18, 6);
  setcolor(BLUE);
  outtextxy(255, 107, name);
  puthz(160, 150, "健康状态：", 16, 18, 6);
  puthz(160, 190, "所在城市：", 16, 18, 6);
  puthz(255, 190, hotle_city, 16, 18, 1);
  puthz(160, 230, "酒店名称：", 16, 18, 6);
  puthz(255, 230, hotle_name, 16, 18, 1);
  puthz(160, 270, "房间类型：", 16, 18, 6);
  puthz(255, 270, hotle_class, 16, 18, 1);
  puthz(160, 310, "房间单价：", 16, 18, 6);
  outtextxy(255, 307, price);
  puthz(160, 350, "居住天数：", 16, 18, 6);
  setcolor(DARKGRAY);
  outtextxy(255, 345, "-");
  setcolor(BLUE);
  outtextxy(275, 345, "1");
  setcolor(DARKGRAY);
  outtextxy(295, 345, "+");
  puthz(480, 20, "勤洗手，多通风！", 16, 18, 8);
  puthz(480, 50, "戴口罩，少聚集！", 16, 18, 8);
  puthz(480, 80, "疫情面前无小事！", 16, 18, 8);
  puthz(260, 400, "确认支付", 16, 18, 5);
  puthz(450, 400, "返回", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(250, 390, 340, 425);
  rectangle(435, 390, 500, 425);
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
