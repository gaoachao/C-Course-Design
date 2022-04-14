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
FUNCTION: htinfo_draw
DESCRIPTION: 上传健康码界面绘制
INPUT: 无
RETURN: 无
***********************************/
void up_draw(void)
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
  puthz(65, 20, "健康码上传", 32, 35, 4);
  puthz(66, 21, "健康码上传", 32, 35, 4);
  puthz(410, 380, "返回", 16, 30, 1);
  setcolor(LIGHTCYAN);
  rectangle(400, 370, 470, 405);
  puthz(290, 380, "上传", 16, 30, 1);
  setcolor(LIGHTCYAN);
  rectangle(280, 370, 350, 405);
}
