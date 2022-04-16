/***********************************
FILE: htinfo.c
DESCRIPTION: 查询已订购的酒店信息
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

/***********************************
FUNCTION: htinfo_main
DESCRIPTION: 查询已订购酒店信息
INPUT: 无
RETURN: 无
***********************************/
void htinfo_main(int *func, USER *u, Live *L)
{
  int num = 0;
  htinfo_draw();
  exit_buttom();
  get_htinfo(u);
  //会打印出最新的酒店信息，新订购会刷新
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
          lightup_htinfo(460, 390, 550, 425, 2);
          num = 2;
        }
        continue;
      }
      if (mouse_press(460, 390, 550, 425) == 1)
      {
        *func = 5;
        return;
      }
    }

    //选择键
    if (MouseX > 360 && MouseX < 415 && MouseY > 280 && MouseY < 305)
    {
      if (mouse_press(360, 280, 415, 305) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_htinfo(360, 280, 415, 305, 1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(360, 280, 415, 305) == 1)
      {
        *func = 24;
        return;
      }
    }

    //恢复点亮
    if (num != 0)
    {
      if (num == 1)
      {
        recover_htinfo(360, 280, 415, 305, 1);
      }
      if (num == 2)
      {
        recover_htinfo(460, 390, 550, 425, 2);
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
FUNCTION: get_htinfo
DESCRIPTION: 获取已订购酒店信息
INPUT: 无
RETURN: 无
***********************************/
void get_htinfo(USER *u)
{
  FILE *fp;
  Live ltemp;
  int i, len;
  char file_live[30] = "\0";
  strcpy(file_live, "database\\");
  strcat(file_live, u->name);
  strcat(file_live, "\\live.dat");
  if ((fp = fopen(file_live, "rb+")) == NULL)
  {
    printf("cannot open file LIVE\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp) / sizeof(Live); //酒店信息的个数
  fseek(fp, (len - 1) * sizeof(Live), SEEK_SET);
  fread(&ltemp, sizeof(Live), 1, fp);
  puthz(260, 135, ltemp.name, 16, 18, 8);
  puthz(260, 165, ltemp.city, 16, 18, 8);
  puthz(260, 195, ltemp.class, 16, 18, 8);
  setcolor(DARKGRAY);
  outtextxy(260, 220, ltemp.price);
  outtextxy(260, 250, ltemp.day);
  if (fclose(fp) != 0)
  {
    printf("%s close failed\n", file_live);
    delay(3000);
    exit(1);
  }
}
/***********************************
FUNCTION: lightup_htinfo
DESCRIPTION: 已订购酒店信息界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_htinfo(int x1, int y1, int x2, int y2, int flag)
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
    puthz(370, 285, "选择", 16, 18, 4);
    break;
  }
  case 2:
  {
    puthz(470, 400, "返回前页", 16, 18, 4);
    break;
  }
  default:
  {
    printf("something wrong in recover_htinfo\n");
    break;
  }
  }
}

/***********************************
FUNCTION: recover_htinfo
DESCRIPTION: 已订购酒店信息界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recover_htinfo(int x1, int y1, int x2, int y2, int flag)
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
    puthz(370, 285, "选择", 16, 18, 5);
    break;
  }
  case 2:
  {
    puthz(470, 400, "返回前页", 16, 18, 5);
    break;
  }
  default:
  {
    printf("something wrong in recover_htinfo\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: htinfo_draw
DESCRIPTION: 上传健康码界面绘制
INPUT: 无
RETURN: 无
***********************************/
void htinfo_draw(void)
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
  puthz(65, 20, "已订购酒店信息", 32, 35, 4);
  puthz(66, 21, "已订购酒店信息", 32, 35, 4);
  setcolor(DARKGRAY);
  rectangle(120, 110, 540, 370);
  rectangle(125, 105, 545, 365);
  puthz(160, 135, "酒店名字：", 16, 18, 1);
  puthz(160, 165, "所在城市：", 16, 18, 1);
  puthz(160, 195, "房间类型：", 16, 18, 1);
  puthz(160, 225, "单日价格：", 16, 18, 1);
  puthz(160, 255, "订购天数：", 16, 18, 1);
  puthz(160, 285, "请选择办理入住的日期：", 16, 18, 1);
  puthz(410, 325, "祝您居住愉快！", 16, 18, 6);
  puthz(470, 400, "返回前页", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(460, 390, 550, 425);
  puthz(370, 285, "选择", 16, 18, 5);
  rectangle(360, 280, 415, 305);
}
/*    酒店所在城市
  char name[10];		//酒店名字
  char price[5];		//房价
  char class[10];		//房间类型
  char day[2];			//居住的天数
  char checkin[5];	//办理入住的日期
  char checkout[5]; //办理离开的日期
*/

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