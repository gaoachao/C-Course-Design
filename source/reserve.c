/***********************************
FILE: reserve.c
DESCRIPTION: 用户个人中心订购酒店功能实现
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
#include "reserve.h"
#define hotle_len 20

/***********************************
FUNCTION: hotlereserve_main
DESCRIPTION: 酒店订购界面主函数
INPUT: *func
RETURN: 无
***********************************/
void hotlereserve_main(int *func, Hotle *booked)
{
  int num = 0; //用来记录"旅客健康码上传"按钮点亮状态
  int city_flag = 0;
  int city_num = 0;
  int line = 1;
  int state1 = 0;
  int state = 0;
  int laucity = 0;
  Hotle h[hotle_len];
  char *city[] = {
      "北京", "上海", "广州", "成都",
      "深圳", "昆明", "西安", "重庆",
      "杭州", "南京", "武汉", "天津"};

  memset(booked, '\0', sizeof(Hotle));
  //出现订购酒店界面
  reserve_draw();
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //城市选择
    if (MouseX > 80 && MouseX < 240 && MouseY > 110 && MouseY < 140)
    {
      if (mouse_press(80, 110, 240, 140) == 2)
      {
        MouseS = 1;
        if (state1 == 0 && state == 0)
        {
          city_lightup(80, 110, 240, 140);
          state1 = 1;
        }
        continue;
      }
      else if (mouse_press(80, 110, 240, 140) == 1)
      {
        MouseS = 1;
        clrmous(MouseX, MouseY);
        setfillstyle(SOLID_FILL, WHITE);
        bar(82, 112, 238, 138);
        if (state == 0) // state用来记录城市列表的展开状态，若城市列表未展开
        {
          city_page(80, 144);
          state = 1;
          delay(100); // delay函数 1000为1s
        }
        else if (state == 1) //若城市列表已展开
        {
          city_cover(80, 144);
          state = 0;
          delay(100);
        }
      }
    }

    if (state == 1) //在城市列表展开的状态下进行选择城市操作
    {
      if (MouseX > 80 && MouseX < 80 + 300 && MouseY > 144 && MouseY < 144 + 140)
      {
        //北京
        if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 0, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 0, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 1; //城市1
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }

        //上海
        if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 0, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 0, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 2; //城市2
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //广州
        if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 0, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 0, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 3; //城市3
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //成都
        if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 0, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 0, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 4; //城市4
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //深圳
        if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 1, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 1, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 5; //城市5
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //昆明
        if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 1, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 1, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 6; //城市6
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //西安
        if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 1, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 1, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 7; //城市7
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //重庆
        if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 1, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 1, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 8; //城市8
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //杭州
        if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 2, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 2, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 9; //城市9
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //南京
        if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 2, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 2, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 10; //城市10
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //武汉
        if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 2, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 2, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 11; //城市11
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //天津
        if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 2, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 2, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 12; //城市12
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
      }
    }

    //查询酒店
    if (MouseX > 330 && MouseX < 380 && MouseY > 110 && MouseY < 140)
    {
      if (mouse_press(330, 110, 380, 140) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(330, 110, 380, 140) == 1)
      {
        hotlecity_read(h);
        switch (laucity)
        {
        case 1: //北京
        {
          hotle_cover();
          hotle_display(h, 1, 1);
          hotle_display(h, 2, 2);
          hotle_display(h, 3, 3);
          hotle_display(h, 4, 4);
          city_flag = 5;
          city_num = 0;
          break;
        }
        case 2: //上海
        {
          hotle_cover();
          hotle_display(h, 5, 1);
          hotle_display(h, 6, 2);
          hotle_display(h, 7, 3);
          hotle_display(h, 8, 4);
          city_flag = 5;
          city_num = 4;
          break;
        }
        case 3: //广州
        {
          hotle_cover();
          hotle_display(h, 9, 1);
          hotle_display(h, 10, 2);
          city_flag = 3;
          city_num = 8;
          break;
        }
        case 4: //成都
        {
          hotle_cover();
          hotle_display(h, 11, 1);
          city_flag = 2;
          city_num = 10;
          break;
        }
        case 5: //深圳
        {
          hotle_cover();
          hotle_display(h, 12, 1);
          city_flag = 2;
          city_num = 11;
          break;
        }
        case 6: //昆明
        {
          hotle_cover();
          hotle_display(h, 13, 1);
          city_flag = 2;
          city_num = 12;
          break;
        }
        case 7: //西安
        {
          hotle_cover();
          hotle_display(h, 14, 1);
          city_flag = 2;
          city_num = 13;
          break;
        }
        case 8: //重庆
        {
          hotle_cover();
          hotle_display(h, 15, 1);
          city_flag = 2;
          city_num = 14;
          break;
        }
        case 9: //杭州
        {
          hotle_cover();
          hotle_display(h, 16, 1);
          city_flag = 2;
          city_num = 15;
          break;
        }
        case 10: //南京
        {
          hotle_cover();
          hotle_display(h, 17, 1);
          city_flag = 2;
          city_num = 16;
          break;
        }
        case 11: //武汉
        {
          hotle_cover();
          hotle_display(h, 18, 1);
          hotle_display(h, 19, 2);
          city_flag = 3;
          city_num = 17;
          break;
        }
        case 12: //天津
        {
          hotle_cover();
          hotle_display(h, 20, 1);
          city_flag = 2;
          city_num = 19;
          break;
        }
        default:
          break;
        }
      }
    }

    for (line = 1; line < city_flag; line++)
    {
      if (mouse_press(500, 185 + 30 * line, 555, 210 + 30 * line) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(500, 185 + 30 * line, 555, 210 + 30 * line) == 1)
      {
        strcpy(booked->hotle_city, h[city_num + line - 1].hotle_city);
        strcpy(booked->hotle_name, h[city_num + line - 1].hotle_name);
        strcpy(booked->hotle_class, h[city_num + line - 1].hotle_class);
        strcpy(booked->price, h[city_num + line - 1].price);
        *func = 12;
        return;
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
        *func = 4;
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
        *func = 8;
        return;
      }
    }

    //跳转至动态查询界面

    //返回个人中心界面
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

    //旅客健康码上传
    if (MouseX > 470 && MouseX < 610 && MouseY > 70 && MouseY < 110)
    {
      if (mouse_press(470,70,610,110) == 2)
      {
        MouseS = 1;
        if(num == 0)
        {
          lightup_reserve(470,70,610,110,1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(470,70,610,110) == 1)
      {
        *func = 20;
        return;
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

    if (state1 != 0)
    {
      if (state1 == 1)
      {
        city_lightup_recover(80, 110, 240, 140);
      }
      state1 = 0;
    }

    //"旅客健康码上传"按钮恢复点亮
    if (num != 0)
    {
      if (num == 1)
      {
        recover_reserve(470,70,610,110,1);
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
FUNCTION: city_page
DESCRIPTION: 城市选择菜单绘制
INPUT: x,y
RETURN: 无
***********************************/
void city_page(int x, int y)
{
  int i, j;
  char *city[] = {
      "北京", "上海", "广州", "成都",
      "深圳", "昆明", "西安", "重庆",
      "杭州", "南京", "武汉", "天津"};

  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x, y, x + 300, y + 140);
  setcolor(BLUE);
  rectangle(x - 1, y - 1, x + 300 + 1, y + 140 + 1);
  rectangle(x - 2, y - 2, x + 300 + 2, y + 140 + 2);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  setcolor(DARKGRAY);
  /*	bar(x+10,y+10,x+20+50,y+30);
    bar(x+20+50+10,y+10,x+20+50+20+50,y+30);*/
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 3; j++)
    {

      bar(x + 20 + 70 * i, y + 20 + j * 40, x + 20 + 70 * i + 50, y + 20 + j * 40 + 20);
      rectangle(x + 20 + 70 * i, y + 20 + j * 40, x + 20 + 70 * i + 50, y + 20 + j * 40 + 20);
      puthz(x + 20 + 70 * i + 7, y + 20 + j * 40 + 2, city[j * 4 + i], 16, 18, RED);
    }
  }
}

/***********************************
FUNCTION: city_cover
DESCRIPTION: 鼠标再次点击后城市列表隐藏
INPUT: x,y
RETURN: 无
***********************************/
void city_cover(int x, int y)
{
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x - 2, y - 2, x + 300 + 2, y + 140 + 2);
  line(0, 160, 640, 160);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(0, 160, 640, 200);
  puthz(60, 170, "城市", 16, 18, 9);
  puthz(150, 170, "酒店名称", 16, 18, 9);
  puthz(270, 170, "房间类型", 16, 18, 9);
  puthz(390, 170, "酒店价格", 16, 18, 9);
}

/***********************************
FUNCTION: hotle_display
DESCRIPTION: 点击查询后酒店列表显示
INPUT: x,y
RETURN: 无
***********************************/
void hotle_display(Hotle *h, int num, int line)
{
  puthz(60, 190 + 30 * line, h[num - 1].hotle_city, 16, 18, 6);
  puthz(150, 190 + 30 * line, h[num - 1].hotle_name, 16, 18, 6);
  puthz(270, 190 + 30 * line, h[num - 1].hotle_class, 16, 18, 6);
  setcolor(BROWN);
  outtextxy(390, 185 + 30 * line, h[num - 1].price);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(500, 185 + 30 * line, 555, 210 + 30 * line);
  puthz(510, 190 + 30 * line, "订购", 16, 18, 1);
}

/***********************************
FUNCTION: hotle_cover
DESCRIPTION: 点击查询后酒店列表影藏
INPUT: 无
RETURN: 无
***********************************/
void hotle_cover(void)
{
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 205, 640, 480);
}

/***********************************
FUNCTION: hotlecity_read
DESCRIPTION: 酒店信息读入
INPUT: 无
RETURN: 无
***********************************/
void hotlecity_read(Hotle *h)
{
  FILE *fp;
  Hotle htemp;
  int i = 0;
  char ch;
  memset(h, '\0', hotle_len * sizeof(Hotle));
  if ((fp = fopen("database\\hotle.dat", "rb+")) == NULL)
  {
    printf("cannot open file hotle\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_SET);
  while (!feof(fp) || i < hotle_len)
  {
    memset(&htemp, '\0', sizeof(Hotle));
    fscanf(fp, "%s\t%s\t%s\t%s\n", htemp.hotle_city, htemp.hotle_name, htemp.hotle_class, htemp.price);
    strcpy(h[i].hotle_city, htemp.hotle_city);
    strcpy(h[i].hotle_name, htemp.hotle_name);
    strcpy(h[i].hotle_class, htemp.hotle_class);
    strcpy(h[i].price, htemp.price);
    i++;
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close file hotle");
    delay(2000);
    exit(1);
  }
}

/***********************************
FUNCTION: lightup_reserve
DESCRIPTION: 酒店订购界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_reserve(int x1, int y1, int x2, int y2, int flag)
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
    puthz(480, 80, "旅客健康码上传", 16, 18, 4);
    break;
  }

  default:
  {
    printf("something wrong in recover_reserve\n");
    break;
  }
  }
}

/***********************************
FUNCTION: recover_scanpay
DESCRIPTION: 酒店订购界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recover_reserve(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setcolor(BROWN);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x1, y1, x2, y2);
  rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
  switch (flag)
  {
  case 1:
  {
    puthz(480, 80, "旅客健康码上传", 16, 18, 1);
    break;
  }

  default:
  {
    printf("something wrong in recover_reserve\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: city_lightup
DESCRIPTION: 城市选择框点亮
INPUT: x1,x2,y1,y2
RETURN: 无
***********************************/
void city_lightup(int x1, int y1, int x2, int y2)
{
  clrmous(MouseX, MouseY);
  setcolor(GREEN);
  rectangle(x1, y1, x2, y2);
}

/***********************************
FUNCTION: city_lightup_recover
DESCRIPTION: 城市选择框点亮恢复
INPUT: x1,x2,y1,y2
RETURN: 无
***********************************/
void city_lightup_recover(int x1, int y1, int x2, int y2)
{
  clrmous(MouseX, MouseY);
  setcolor(DARKGRAY);
  rectangle(x1, y1, x2, y2);
}

/***********************************
FUNCTION: reserve_draw
DESCRIPTION: 订购酒店界面
INPUT: 无
RETURN: 无
***********************************/
void reserve_draw(void)
{
  clrmous(MouseX, MouseY);
  delay(30);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setcolor(DARKGRAY);
  rectangle(60, 0, 640, 60);
  rectangle(0, 0, 60, 60);
  setfillstyle(SOLID_FILL, GREEN);
  bar(0, 0, 60, 60);
  rectangle(80, 110, 240, 140);
  line(0, 160, 640, 160);
  setfillstyle(SOLID_FILL, DARKGRAY);
  bar(595, 0, 640, 20);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(0, 160, 640, 200);
  puthz(600, 2, "退出", 16, 18, RED);
  puthz(65, 20, "航旅纵横", 32, 35, 4);
  puthz(270, 30, "机票信息", 16, 18, 8);
  puthz(360, 30, "个人中心", 16, 18, 2);
  puthz(450, 30, "疫情防控", 16, 18, 8);
  puthz(540, 30, "动态查询", 16, 18, 8);
  puthz(80, 80, "请选择城市：", 16, 18, 5);
  puthz(90, 115, "城市", 16, 18, 7);
  puthz(340, 115, "查询", 16, 18, 1);
  puthz(480, 80, "旅客健康码上传", 16, 18, 1);
  setcolor(BROWN);
  rectangle(470,70,610,110);
  puthz(60, 170, "城市", 16, 18, 9);
  puthz(150, 170, "酒店名称", 16, 18, 9);
  puthz(270, 170, "房间类型", 16, 18, 9);
  puthz(390, 170, "酒店价格", 16, 18, 9);
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