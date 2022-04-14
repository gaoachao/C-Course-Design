/***********************************
FILE: userpage.c
DESCRIPTION: 用户个人中心，包括修改密码、待出行机票查询、个人信息（包括健康状况）显示等功能
***********************************/
#include <stdio.h>
#include <graphics.h>
#include <bios.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "hz.h"
#include "mouse.h"
#include "database.h"
#include "queue.h"
#include "register.h"
#include "buypage.h"
#include "menu.h"
#include "userpage.h"
#include "prevent.h"
#define city_len 12

/***********************************
FUNCTION: prevent_main
DESCRIPTION: 疫情防控主函数
INPUT: *func
RETURN: 无
***********************************/
void prevent_main(int *func, USER *u)
{
  //  int state1 = 0;
  int i, len;
  City c[city_len];

  //出现疫情防控界面
  prevent_draw();
  //退出按钮
  exit_buttom();
  //获得实时时间
  //  get_time(ttemp);

  //刚进入页面进行一次健康状态的判断
  if (strcmp(u->health_code, "1") == 0)
  {
    clrmous(MouseX, MouseY);
    setfillstyle(SOLID_FILL, GREEN);
    bar(240, 160, 265, 185);
  }
  else if (strcmp(u->health_code, "2") == 0)
  {
    clrmous(MouseX, MouseY);
    setfillstyle(SOLID_FILL, YELLOW);
    bar(240, 160, 265, 185);
  }
  else if (strcmp(u->health_code, "3") == 0)
  {
    clrmous(MouseX, MouseY);
    setfillstyle(SOLID_FILL, RED);
    bar(240, 160, 265, 185);
  }

  //鼠标操作
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //实时时间展示
    //  display_time(65, 10, ttemp);

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
        *func = 5;
        return;
      }
    }

    //跳转至动态查询界面
    if (MouseX > 540 && MouseX < 620 && MouseY > 10 && MouseY < 60)
    {
      if (mouse_press(540, 10, 620, 60) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(540, 10, 620, 60) == 1)
      {
        *func = 15;
        return;
      }
    }

    //退出键
    if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
    {
      if (mouse_press(595, 0, 640, 20) == 1)
      {
        *func = 1;
        return;
      }
    }
    //中高风险地区查询键
    if (MouseX > 230 && MouseX < 270 && MouseY > 230 && MouseY < 260)
    {
      if (mouse_press(230, 230, 270, 260) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(230, 230, 270, 260) == 1)
      {
        city_read(c);
        get_cityinfo(c);
        continue;
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
FUNCTION: city_read
DESCRIPTION: 中高风险地区读入
INPUT: 无
RETURN: 无
***********************************/
void city_read(City *c)
{
  FILE *fp;
  City ctem;
  int i = 0;
  int j = 0;
  //  int city_len = 12;
  //  char ch;
  memset(c, '\0', city_len * sizeof(City));

  if ((fp = fopen("database\\city.dat", "rb+")) == NULL)
  {
    printf("cannot open file city\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_SET);
  while (!feof(fp) || i < city_len)
  {
    memset(&ctem, '\0', sizeof(City));
    fscanf(fp, "%s\t%s\n", ctem.city_name, ctem.level);
    strcpy(c[i].city_name, ctem.city_name);
    strcpy(c[i].level, ctem.level);
    i++;
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close city");
    delay(2000);
    exit(1);
  }
}

/*****************************
FUNCTION: get_cityinfo
DESCRIPTION:疫情防控界面输出当前中高风险地区
INPUT: c
RETURN: 无
*****************************/
void get_cityinfo(City *c)
{
  int i = 0;
  for (i = 0; i < city_len; i++)
  {
    puthz(490, 165 + 25 * i, c[i].city_name, 16, 18, 8);
    puthz(550, 165 + 25 * i, c[i].level, 16, 18, 8);
  }
}

/***********************************
FUNCTION: prevent_draw
DESCRIPTION: 疫情防控界面
INPUT: 无
RETURN: 无
***********************************/
void prevent_draw(void)
{
  clrmous(MouseX, MouseY);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setcolor(DARKGRAY);
  rectangle(60, 0, 640, 60);
  rectangle(0, 0, 60, 60);
  line(0, 150, 640, 150);
  line(460, 150, 460, 640);
  setfillstyle(SOLID_FILL, GREEN);
  bar(0, 0, 60, 60);
  setfillstyle(SOLID_FILL, RED);
  bar(595, 0, 640, 20);
  puthz(65, 20, "航旅纵横", 32, 35, 4);
  puthz(270, 30, "机票信息", 16, 18, 8);
  puthz(360, 30, "个人中心", 16, 18, 8);
  puthz(450, 30, "疫情防控", 16, 18, 2);
  puthz(540, 30, "动态查询", 16, 18, 8);
  puthz(595, 5, "退出", 16, 18, 1);
  puthz(30, 70, "出行防疫提示：", 16, 18, 5);
  puthz(30, 160, "旅客健康状态：", 16, 18, 5);
  puthz(30, 200, "旅客过往地区：", 16, 18, 5);
  puthz(240, 200, "查询", 16, 18, 1);
  puthz(30, 240, "当前中高风险地区：", 16, 18, 5);
  puthz(240, 240, "查询", 16, 18, 1);
}

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