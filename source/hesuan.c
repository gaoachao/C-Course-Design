/***********************************
FILE: hesuan.c
DESCRIPTION: 上报核酸结果
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

/***********************************
FUNCTION: hesuan_main
DESCRIPTION: 核酸结果上报
INPUT: 无
RETURN: 无
***********************************/
void hesuan_main(int *func, USER *u)
{
  int num = 0;
  char hesuan_temp[2];
  hesuan_draw();
  exit_buttom();
  setcolor(DARKGRAY);
  outtextxy(295, 155, u->name);
  //刚进入页面进行一次核酸结果的判断
  if (strcmp(u->hesuan, "1") == 0)
  {
    setfillstyle(SOLID_FILL, WHITE);
    bar(340, 195, 365, 220);
    bar(440, 195, 465, 220);
    setcolor(DARKGRAY);
    line(342, 207, 350, 218);
    line(350, 218, 362, 199);
    setcolor(DARKGRAY);
    rectangle(340, 195, 365, 220);
    rectangle(440, 195, 465, 220);
  }
  else if (strcmp(u->hesuan, "2") == 0)
  {
    clrmous(MouseX, MouseY);
    setfillstyle(SOLID_FILL, WHITE);
    bar(340, 195, 365, 220);
    bar(440, 195, 465, 220);
    setcolor(DARKGRAY);
    line(442, 207, 450, 218);
    line(450, 218, 462, 199);
    setcolor(DARKGRAY);
    rectangle(340, 195, 365, 220);
    rectangle(440, 195, 465, 220);
  }

  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
    //选中阴性
    if (MouseX > 340 && MouseX < 365 && MouseY > 195 && MouseY < 220)
    {
      if (mouse_press(340, 195, 365, 220) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(340, 195, 365, 220) == 1)
      {
        strcpy(hesuan_temp, "1");
        input_hesuan(u, hesuan_temp);
        clrmous(MouseX, MouseY);
        setfillstyle(SOLID_FILL, WHITE);
        bar(340, 195, 365, 220);
        bar(440, 195, 465, 220);
        setcolor(DARKGRAY);
        line(342, 207, 350, 218);
        line(350, 218, 362, 199);
        setcolor(DARKGRAY);
        rectangle(340, 195, 365, 220);
        rectangle(440, 195, 465, 220);
      }
    }
    //选中阳性
    if (MouseX > 440 && MouseX < 465 && MouseY > 195 && MouseY < 220)
    {
      if (mouse_press(440, 195, 465, 220) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(440, 195, 465, 220) == 1)
      {
        strcpy(hesuan_temp, "2");
        input_hesuan(u, hesuan_temp);
        clrmous(MouseX, MouseY);
        setfillstyle(SOLID_FILL, WHITE);
        bar(340, 195, 365, 220);
        bar(440, 195, 465, 220);
        setcolor(DARKGRAY);
        line(442, 207, 450, 218);
        line(450, 218, 462, 199);
        setcolor(DARKGRAY);
        rectangle(340, 195, 365, 220);
        rectangle(440, 195, 465, 220);
      }
    }

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
FUNCTION: lightup_hesuan
DESCRIPTION: 核酸上报界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_hesuan(int x1, int y1, int x2, int y2, int flag)
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
    printf("something wrong in recover_hesuan\n");
    break;
  }
  }
}

/***********************************
FUNCTION: recover_hesuan
DESCRIPTION: 核酸上报界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recover_hesuan(int x1, int y1, int x2, int y2, int flag)
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
    printf("something wrong in recover_hesuan\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: input_hesuan
DESCRIPTION: 将核酸结果写入数据库
INPUT:*u
RETURN: 无
***********************************/
void input_hesuan(USER *u, char *hesuan)
{
  USER utemp;
  FILE *fp;
  int i, len;

  if ((fp = fopen("database\\userdata.dat", "rb+")) == NULL)
  {
    printf("cannot open file userdata\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp) / sizeof(USER); //用户的个数
  for (i = 0; i < len; i++)
  {
    memset(&utemp, '\0', sizeof(USER));
    fseek(fp, i * sizeof(USER), SEEK_SET);
    fread(&utemp, sizeof(USER), 1, fp);
    if (strcmp(u->name, utemp.name) == 0 && strcmp(u->password, utemp.password) == 0)
    {
      strcpy(u->hesuan, hesuan);
      fseek(fp, i * sizeof(USER), SEEK_SET);
      fwrite(u, sizeof(USER), 1, fp); // fwrite函数在写入的时候是覆盖光标当前位置后“偏移量”个单位
      break;
    }
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close database\n");
    delay(2000);
    exit(1);
  }
}

/***********************************
FUNCTION: hesuan_draw
DESCRIPTION: 购票记录界面绘制
INPUT: 无
RETURN: 无
***********************************/
void hesuan_draw(void)
{
  clrmous(MouseX, MouseY);
  delay(30);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setcolor(DARKGRAY);
  rectangle(340, 195, 365, 220);
  rectangle(440, 195, 465, 220);
  setcolor(YELLOW);
  arc(0, 320, 0, 360, 100);
  setfillstyle(SOLID_FILL, YELLOW);
  fillellipse(0, 320, 100, 100);
  setcolor(GREEN);
  arc(0, 480, 0, 75, 160);
  setfillstyle(SOLID_FILL, GREEN);
  fillellipse(0, 480, 160, 160);
  puthz(85, 20, "核酸结果填报", 32, 35, 4);
  puthz(86, 21, "核酸结果填报", 32, 35, 4);
  puthz(175, 160, "用户姓名：", 16, 18, 1);
  puthz(175, 200, "核酸结果：", 16, 18, 1);
  puthz(295, 200, "阴性", 16, 18, 2);
  puthz(395, 200, "阳性", 16, 18, 4);
  setcolor(DARKGRAY);
  rectangle(140, 110, 520, 310);
  rectangle(145, 105, 525, 305);
  puthz(470, 400, "返回前页", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(460, 390, 550, 425);
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