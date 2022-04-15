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
  htinfo_draw();
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
    //调整鼠标手势
    if (MouseS != 0)
    {
      MouseS = 0;
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
  rectangle(120,110,540,370);
  rectangle(125,105,545,365);
  puthz(160,135,"酒店名字：",16,18,1);
  puthz(160,165,"所在城市：",16,18,1);
  puthz(160,195,"房间类型：",16,18,1);
  puthz(160,225,"单日价格：",16,18,1);
  puthz(160,255,"订购天数：",16,18,1);
  puthz(160,285,"请选择办理入住的日期：",16,18,1);
  puthz(410,325,"祝您旅途愉快！",16,18,6);
  puthz(470,400,"返回前页",16,18,6);
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