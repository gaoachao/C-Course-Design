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
#include "prevent.h"
#include "pay.h"
#include "booked.h"
#include "payment.h"
#include "upload.h"
#include "up.h"
#include "htinfo.h"
#include "history.h"
#include "hesuan.h"
#include "area.h"
#include "manage.h"
#define city_len 12

/***********************************
FUNCTION: manage_main
DESCRIPTION: 修改城市风险等级
INPUT: 无
RETURN: 无
***********************************/
void manage_main(int *func)
{
  City c[city_len];
  int num = 0;
  int i, j;
  int k;
  int city_number = 0;
  char danger_high[8];
  char danger_middle[8];
  char danger_low[8];
  memset(danger_high, '\0', sizeof(danger_high));
  memset(danger_middle, '\0', sizeof(danger_middle));
  memset(danger_low, '\0', sizeof(danger_low));
  strcpy(danger_high, "高风险");
  strcpy(danger_middle, "中风险");
  strcpy(danger_low, "低风险");
  manage_draw();
  exit_buttom();
  city_read(c);
  get_cityname(c);
  //刚进页面进行判断风险等级
  for(k=0;k<city_len;k++)
  {
    if(strcmp(c[k].level,danger_high)==0)
    {
      tick_high_draw(k);
    }
    if(strcmp(c[k].level,danger_middle)==0)
    {
      tick_middle_draw(k);
    }
    if(strcmp(c[k].level,danger_low)==0)
    {
      tick_low_draw(k);
    }
  }


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
    if (MouseX > 550 && MouseX < 639 && MouseY > 445 && MouseY < 479)
    {
      if (mouse_press(550, 445, 639, 479) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_manage(550, 445, 639, 479, 1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(550, 445, 639, 479) == 1)
      {
        *func = 8;
        return;
      }
    }
    //北京  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 0 && MouseY < 98 + 30 * 0)
    {
      if (mouse_press(230, 78 + 30 * 0, 250, 98 + 30 * 0) == 2)
      {
        MouseS = 1;
        city_number = 0;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 0, 250, 98 + 30 * 0) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 0 && MouseY < 98 + 30 * 0)
    {
      if (mouse_press(370, 78 + 30 * 0, 390, 98 + 30 * 0) == 2)
      {
        MouseS = 1;
        city_number = 0;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 0, 390, 98 + 30 * 0) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 0 && MouseY < 98 + 30 * 0)
    {
      if (mouse_press(510, 78 + 30 * 0, 530, 98 + 30 * 0) == 2)
      {
        MouseS = 1;
        city_number = 0;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 0, 530, 98 + 30 * 0) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //上海  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 1 && MouseY < 98 + 30 * 1)
    {
      if (mouse_press(230, 78 + 30 * 1, 250, 98 + 30 * 1) == 2)
      {
        MouseS = 1;
        city_number = 1;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 1, 250, 98 + 30 * 1) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 1 && MouseY < 98 + 30 * 1)
    {
      if (mouse_press(370, 78 + 30 * 1, 390, 98 + 30 * 1) == 2)
      {
        MouseS = 1;
        city_number = 1;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 1, 390, 98 + 30 * 1) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 1 && MouseY < 98 + 30 * 1)
    {
      if (mouse_press(510, 78 + 30 * 1, 530, 98 + 30 * 1) == 2)
      {
        MouseS = 1;
        city_number = 1;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 1, 530, 98 + 30 * 1) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //广州  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 2 && MouseY < 98 + 30 * 2)
    {
      if (mouse_press(230, 78 + 30 * 2, 250, 98 + 30 * 2) == 2)
      {
        MouseS = 1;
        city_number = 2;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 2, 250, 98 + 30 * 2) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 2 && MouseY < 98 + 30 * 2)
    {
      if (mouse_press(370, 78 + 30 * 2, 390, 98 + 30 * 2) == 2)
      {
        MouseS = 1;
        city_number = 2;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 2, 390, 98 + 30 * 2) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 2 && MouseY < 98 + 30 * 2)
    {
      if (mouse_press(510, 78 + 30 * 2, 530, 98 + 30 * 2) == 2)
      {
        MouseS = 1;
        city_number = 2;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 2, 530, 98 + 30 * 2) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //成都  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 3 && MouseY < 98 + 30 * 3)
    {
      if (mouse_press(230, 78 + 30 * 3, 250, 98 + 30 * 3) == 2)
      {
        MouseS = 1;
        city_number = 3;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 3, 250, 98 + 30 * 3) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 3 && MouseY < 98 + 30 * 3)
    {
      if (mouse_press(370, 78 + 30 * 3, 390, 98 + 30 * 3) == 2)
      {
        MouseS = 1;
        city_number = 3;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 3, 390, 98 + 30 * 3) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 3 && MouseY < 98 + 30 * 3)
    {
      if (mouse_press(510, 78 + 30 * 3, 530, 98 + 30 * 3) == 2)
      {
        MouseS = 1;
        city_number = 3;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 3, 530, 98 + 30 * 3) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //深圳  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 4 && MouseY < 98 + 30 * 4)
    {
      if (mouse_press(230, 78 + 30 * 4, 250, 98 + 30 * 4) == 2)
      {
        MouseS = 1;
        city_number = 4;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 4, 250, 98 + 30 * 4) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 4 && MouseY < 98 + 30 * 4)
    {
      if (mouse_press(370, 78 + 30 * 4, 390, 98 + 30 * 4) == 2)
      {
        MouseS = 1;
        city_number = 4;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 4, 390, 98 + 30 * 4) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 4 && MouseY < 98 + 30 * 4)
    {
      if (mouse_press(510, 78 + 30 * 4, 530, 98 + 30 * 4) == 2)
      {
        MouseS = 1;
        city_number = 4;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 4, 530, 98 + 30 * 4) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //昆明  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 5 && MouseY < 98 + 30 * 5)
    {
      if (mouse_press(230, 78 + 30 * 5, 250, 98 + 30 * 5) == 2)
      {
        MouseS = 1;
        city_number = 5;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 5, 250, 98 + 30 * 5) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 5 && MouseY < 98 + 30 * 5)
    {
      if (mouse_press(370, 78 + 30 * 5, 390, 98 + 30 * 5) == 2)
      {
        MouseS = 1;
        city_number = 5;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 5, 390, 98 + 30 * 5) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 5 && MouseY < 98 + 30 * 5)
    {
      if (mouse_press(510, 78 + 30 * 5, 530, 98 + 30 * 5) == 2)
      {
        MouseS = 1;
        city_number = 5;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 5, 530, 98 + 30 * 5) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //西安  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 6 && MouseY < 98 + 30 * 6)
    {
      if (mouse_press(230, 78 + 30 * 6, 250, 98 + 30 * 6) == 2)
      {
        MouseS = 1;
        city_number = 6;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 6, 250, 98 + 30 * 6) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 6 && MouseY < 98 + 30 * 6)
    {
      if (mouse_press(370, 78 + 30 * 6, 390, 98 + 30 * 6) == 2)
      {
        MouseS = 1;
        city_number = 6;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 6, 390, 98 + 30 * 6) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 6 && MouseY < 98 + 30 * 6)
    {
      if (mouse_press(510, 78 + 30 * 6, 530, 98 + 30 * 6) == 2)
      {
        MouseS = 1;
        city_number = 6;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 6, 530, 98 + 30 * 6) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //重庆  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 7 && MouseY < 98 + 30 * 7)
    {
      if (mouse_press(230, 78 + 30 * 7, 250, 98 + 30 * 7) == 2)
      {
        MouseS = 1;
        city_number = 7;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 7, 250, 98 + 30 * 7) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 7 && MouseY < 98 + 30 * 7)
    {
      if (mouse_press(370, 78 + 30 * 7, 390, 98 + 30 * 7) == 2)
      {
        MouseS = 1;
        city_number = 7;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 7, 390, 98 + 30 * 7) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 7 && MouseY < 98 + 30 * 7)
    {
      if (mouse_press(510, 78 + 30 * 7, 530, 98 + 30 * 7) == 2)
      {
        MouseS = 1;
        city_number = 7;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 7, 530, 98 + 30 * 7) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //杭州  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 8 && MouseY < 98 + 30 * 8)
    {
      if (mouse_press(230, 78 + 30 * 8, 250, 98 + 30 * 8) == 2)
      {
        MouseS = 1;
        city_number = 8;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 8, 250, 98 + 30 * 8) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 8 && MouseY < 98 + 30 * 8)
    {
      if (mouse_press(370, 78 + 30 * 8, 390, 98 + 30 * 8) == 2)
      {
        MouseS = 1;
        city_number = 8;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 8, 390, 98 + 30 * 8) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 8 && MouseY < 98 + 30 * 8)
    {
      if (mouse_press(510, 78 + 30 * 8, 530, 98 + 30 * 8) == 2)
      {
        MouseS = 1;
        city_number = 8;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 8, 530, 98 + 30 * 8) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //南京  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 9 && MouseY < 98 + 30 * 9)
    {
      if (mouse_press(230, 78 + 30 * 9, 250, 98 + 30 * 9) == 2)
      {
        MouseS = 1;
        city_number = 9;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 9, 250, 98 + 30 * 9) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 9 && MouseY < 98 + 30 * 9)
    {
      if (mouse_press(370, 78 + 30 * 9, 390, 98 + 30 * 9) == 2)
      {
        MouseS = 1;
        city_number = 9;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 9, 390, 98 + 30 * 9) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 9 && MouseY < 98 + 30 * 9)
    {
      if (mouse_press(510, 78 + 30 * 9, 530, 98 + 30 * 9) == 2)
      {
        MouseS = 1;
        city_number = 9;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 9, 530, 98 + 30 * 9) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    //武汉  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 10 && MouseY < 98 + 30 * 10)
    {
      if (mouse_press(230, 78 + 30 * 10, 250, 98 + 30 * 10) == 2)
      {
        MouseS = 1;
        city_number = 10;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 10, 250, 98 + 30 * 10) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 4 && MouseY < 98 + 30 * 4)
    {
      if (mouse_press(370, 78 + 30 * 10, 390, 98 + 30 * 10) == 2)
      {
        MouseS = 1;
        city_number = 10;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 10, 390, 98 + 30 * 10) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 10 && MouseY < 98 + 30 * 10)
    {
      if (mouse_press(510, 78 + 30 * 10, 530, 98 + 30 * 10) == 2)
      {
        MouseS = 1;
        city_number = 10;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 10, 530, 98 + 30 * 10) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }  
    //天津  高风险
    if (MouseX > 230 && MouseX < 250 && MouseY > 78 + 30 * 11 && MouseY < 98 + 30 * 11)
    {
      if (mouse_press(230, 78 + 30 * 11, 250, 98 + 30 * 11) == 2)
      {
        MouseS = 1;
        city_number = 11;
        continue;
      }
      if (mouse_press(230, 78 + 30 * 11, 250, 98 + 30 * 11) == 1)
      {
        tick_high_draw(city_number);
        change_level(c, city_number, danger_high);
        continue;
      }
    } //中风险
    if (MouseX > 370 && MouseX < 390 && MouseY > 78 + 30 * 11 && MouseY < 98 + 30 * 11)
    {
      if (mouse_press(370, 78 + 30 * 11, 390, 98 + 30 * 11) == 2)
      {
        MouseS = 1;
        city_number = 11;
        continue;
      }
      if (mouse_press(370, 78 + 30 * 11, 390, 98 + 30 * 11) == 1)
      {
        tick_middle_draw(city_number);
        change_level(c, city_number, danger_middle);
        continue;
      }
    } //低风险
    if (MouseX > 510 && MouseX < 530 && MouseY > 78 + 30 * 11 && MouseY < 98 + 30 * 11)
    {
      if (mouse_press(510, 78 + 30 * 11, 530, 98 + 30 * 11) == 2)
      {
        MouseS = 1;
        city_number = 11;
        continue;
      }
      if (mouse_press(510, 78 + 30 * 11, 530, 98 + 30 * 11) == 1)
      {
        tick_low_draw(city_number);
        change_level(c, city_number, danger_low);
        continue;
      }
    }
    
    
    
    
    
    //恢复点亮
    if (num != 0)
    {
      if (num == 1)
      {
        recover_manage(550, 445, 639, 479, 1);
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
FUNCTION: lightup_manage
DESCRIPTION: 管理者模式
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_manage(int x1, int y1, int x2, int y2, int flag)
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
    puthz(560, 455, "返回前页", 16, 18, 4);
    break;
  }
  default:
  {
    printf("something wrong in recover_manage\n");
    break;
  }
  }
}

/***********************************
FUNCTION: tick_high
DESCRIPTION: 打钩
INPUT: x
RETURN: 无
***********************************/
void tick_high_draw(int x)
{
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(232, 80 + 30 * x, 248, 96 + 30 * x);
  bar(372, 80 + 30 * x, 388, 96 + 30 * x);
  bar(512, 80 + 30 * x, 528, 96 + 30 * x);
  setcolor(DARKGRAY);
  line(232, 88 + 30 * x, 240, 96 + 30 * x);
  line(240, 96 + 30 * x, 248, 80 + 30 * x);
}

/***********************************
FUNCTION: tick_middle_draw
DESCRIPTION: 打钩
INPUT: x
RETURN: 无
***********************************/
void tick_middle_draw(int x)
{
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(232, 80 + 30 * x, 248, 96 + 30 * x);
  bar(372, 80 + 30 * x, 388, 96 + 30 * x);
  bar(512, 80 + 30 * x, 528, 96 + 30 * x);
  setcolor(DARKGRAY);
  line(372, 88 + 30 * x, 380, 96 + 30 * x);
  line(380, 96 + 30 * x, 388, 80 + 30 * x);
}

/***********************************
FUNCTION: tick_low)_draw
DESCRIPTION: 打钩
INPUT: x
RETURN: 无
***********************************/
void tick_low_draw(int x)
{
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(232, 80 + 30 * x, 248, 96 + 30 * x);
  bar(372, 80 + 30 * x, 388, 96 + 30 * x);
  bar(512, 80 + 30 * x, 528, 96 + 30 * x);
  setcolor(DARKGRAY);
  line(512, 88 + 30 * x, 520, 96 + 30 * x);
  line(520, 96 + 30 * x, 528, 80 + 30 * x);
}

/***********************************
FUNCTION: recover_manage
DESCRIPTION: 核酸上报界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void recover_manage(int x1, int y1, int x2, int y2, int flag)
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
    puthz(560, 455, "返回前页", 16, 18, 5);
    break;
  }
  default:
  {
    printf("something wrong in recover_manage\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: get_cityname
DESCRIPTION: 得到城市列表
INPUT: City *c
RETURN: 无
***********************************/
void get_cityname(City *c)
{
  int i = 0;
  for (i = 0; i < city_len; i++)
  {
    puthz(85, 80 + 30 * i, c[i].city_name, 16, 18, 1);
    puthz(165, 80 + 30 * i, "高风险", 16, 18, 4);
    puthz(305, 80 + 30 * i, "中风险", 16, 18, 6);
    puthz(445, 80 + 30 * i, "低风险", 16, 18, 2);
    setcolor(DARKGRAY);
    rectangle(230, 78 + 30 * i, 250, 98 + 30 * i);
    rectangle(370, 78 + 30 * i, 390, 98 + 30 * i);
    rectangle(510, 78 + 30 * i, 530, 98 + 30 * i);
  }
}

/***********************************
FUNCTION: change_level
DESCRIPTION: 得到城市列表
INPUT: City *c
RETURN: 无
***********************************/
void change_level(City *c, int x, char *level)
{
  FILE *fp;
  City city_temp;
  int i;
  memset(&city_temp, '\0', sizeof(City));
  strcpy(city_temp.level, level);
  strcpy(city_temp.city_name, c[x].city_name);
  if ((fp = fopen("database\\city.dat", "rb+")) == NULL)
  {
    printf("cannot open file city\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, x * 12, SEEK_SET);
  fprintf(fp, "%s\t%s", city_temp.city_name, city_temp.level);
  if (fclose(fp) != 0)
  {
    printf("cannot close database\n");
    delay(2000);
    exit(1);
  }
}

/***********************************
FUNCTION: manage_draw
DESCRIPTION: 购票记录界面绘制
INPUT: 无
RETURN: 无
***********************************/
void manage_draw(void)
{
  clrmous(MouseX, MouseY);
  delay(30);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  puthz(85, 20, "管理员模式（修改风险等级）", 32, 35, 4);
  puthz(86, 21, "管理员模式（修改风险等级）", 32, 35, 4);
  puthz(560, 455, "返回前页", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(550, 445, 639, 479);
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