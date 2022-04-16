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
#include "history.h"

/***********************************
FUNCTION: history_main
DESCRIPTION: 查询已订购酒店信息
INPUT: 无
RETURN: 无
***********************************/
void history_main(int *func, USER *u)
{
  int num = 0;
  history_draw();
  exit_buttom();

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
          lightup_history(460, 390, 550, 425, 1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(460, 390, 550, 425) == 1)
      {
        *func = 5;
        return;
      }
    }
    //恢复点亮
    if (num != 0)
    {
      if (num == 1)
      {
        recover_history(460, 390, 550, 425, 1);
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
FUNCTION: lightup_history
DESCRIPTION: 历史机票界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_history(int x1, int y1, int x2, int y2, int flag)
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
    puthz(470, 400, "返回前页", 16, 18, 4);
    break;
  }
  default:
  {
    printf("something wrong in recover_history\n");
    break;
  }
  }
}

/***********************************
FUNCTION: recover_history
DESCRIPTION: 历史机票界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recover_history(int x1, int y1, int x2, int y2, int flag)
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
    puthz(470, 400, "返回前页", 16, 18, 5);
    break;
  }
  default:
  {
    printf("something wrong in recover_history\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: histroy_draw
DESCRIPTION: 购票记录界面绘制
INPUT: 无
RETURN: 无
***********************************/
void history_draw(void)
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
  puthz(65, 20, "历史购票", 32, 35, 4);
  puthz(66, 21, "历史购票", 32, 35, 4);
  setcolor(DARKGRAY);
  rectangle(120, 110, 540, 370);
  rectangle(125, 105, 545, 365);
  puthz(470, 400, "返回前页", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(460, 390, 550, 425);
}