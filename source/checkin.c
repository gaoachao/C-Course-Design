/***********************************
FILE: htinfo.c
DESCRIPTION: ��ѯ�Ѷ����ľƵ���Ϣ
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
#include "checkin.h"

/***********************************
FUNCTION: checkin_main
DESCRIPTION: �Ѷ����Ƶ���Ϣ
INPUT: ��
RETURN: ��
***********************************/
void checkin_main(int *func)
{
  int num = 0;
  char day[3];
  checkin_draw();
  exit_buttom();
  date_select(145, 155);
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //�˳���
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

    //����ǰҳ��
    if (MouseX > 460 && MouseX < 550 && MouseY > 390 && MouseY < 425)
    {
      if (mouse_press(460, 390, 550, 425) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(460, 390, 550, 425, 29);
          num = 29;
        }
        continue;
      }
      if (mouse_press(460, 390, 550, 425) == 1)
      {
        *func = 23;
        return;
      }
    }

    //ѡ��2��1��
    if (MouseX > 165 && MouseX < 195 && MouseY > 175 && MouseY < 195)
    {
      if (mouse_press(165, 175, 195, 195) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165, 175, 195, 195, 1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(165, 175, 195, 195) == 1)
      {
        check_in(day, 1);
      }
    }
    //ѡ��2��2��
    if (MouseX > 215 && MouseX < 245 && MouseY > 175 && MouseY < 195)
    {
      if (mouse_press(215, 175, 245, 195) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(215, 175, 245, 195, 2);
          num = 2;
        }
        continue;
      }
      if (mouse_press(215, 175, 245, 195) == 1)
      {
        check_in(day, 2);
        continue;
      }
    }
    //ѡ��2��3��
    if (MouseX > 265 && MouseX < 295 && MouseY > 175 && MouseY < 195)
    {
      if (mouse_press(265, 175, 295, 195) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(265, 175, 295, 195, 3);
          num = 3;
        }
        continue;
      }
      if (mouse_press(265, 175, 295, 195) == 1)
      {
        check_in(day, 3);
        continue;
      }
    }
    //ѡ��2��4��
    if (MouseX > 315 && MouseX < 345 && MouseY > 175 && MouseY < 195)
    {
      if (mouse_press(315, 175, 345, 195) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(315, 175, 345, 195, 4);
          num = 4;
        }
        continue;
      }
      if (mouse_press(315, 175, 345, 195) == 1)
      {
        check_in(day, 4);
        continue;
      }
    }
    //ѡ��2��5��
    if (MouseX > 365 && MouseX < 395 && MouseY > 175 && MouseY < 195)
    {
      if (mouse_press(365, 175, 395, 195) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(365, 175, 395, 195, 5);
          num = 5;
        }
        continue;
      }
      if (mouse_press(365, 175, 395, 195) == 1)
      {
        check_in(day, 5);
        continue;
      }
    }
    //ѡ��2��6��
    if (MouseX > 415 && MouseX < 445 && MouseY > 175 && MouseY < 195)
    {
      if (mouse_press(415, 175, 445, 195) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(415, 175, 445, 195, 6);
          num = 6;
        }
        continue;
      }
      if (mouse_press(415, 175, 445, 195) == 1)
      {
        check_in(day, 6);
        continue;
      }
    }
    //ѡ��2��7��
    if (MouseX > 465 && MouseX < 495 && MouseY > 175 && MouseY < 195)
    {
      if (mouse_press(465, 175, 495, 195) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(465, 175, 495, 195, 7);
          num = 7;
        }
        continue;
      }
      if (mouse_press(465, 175, 495, 195) == 1)
      {
        check_in(day, 7);
        continue;
      }
    }
    //ѡ��2��8��
    if (MouseX > 165 && MouseX < 215 && MouseY > 215 && MouseY < 235)
    {
      if (mouse_press(165, 215, 195, 235) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165, 215, 195, 235, 8);
          num = 8;
        }
        continue;
      }
      if (mouse_press(165, 215, 195, 235) == 1)
      {
        check_in(day, 8);
        continue;
      }
    }
    //ѡ��2��9��
    if (MouseX > 165 + 50 * 1 && MouseX < 195 + 50 * 1 && MouseY > 175 + 40 * 1 && MouseY < 195 + 40 * 1)
    {
      if (mouse_press(165 + 50 * 1, 175 + 40 * 1, 195 + 50 * 1, 195 + 40 * 1) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 1, 175 + 40 * 1, 195 + 50 * 1, 195 + 40 * 1, 9);
          num = 9;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 1, 175 + 40 * 1, 195 + 50 * 1, 195 + 40 * 1) == 1)
      {
        check_in(day, 9);
        continue;
      }
    }
    //ѡ��2��10��
    if (MouseX > 165 + 50 * 2 && MouseX < 195 + 50 * 2 && MouseY > 175 + 40 * 1 && MouseY < 195 + 40 * 1)
    {
      if (mouse_press(165 + 50 * 2, 175 + 40 * 1, 195 + 50 * 2, 195 + 40 * 1) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 2, 175 + 40 * 1, 195 + 50 * 2, 195 + 40 * 1, 10);
          num = 10;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 2, 175 + 40 * 1, 195 + 50 * 2, 195 + 40 * 1) == 1)
      {
        check_in(day, 10);
        continue;
      }
    }
    //ѡ��2��11��
    if (MouseX > 165 + 50 * 3 && MouseX < 195 + 50 * 3 && MouseY > 175 + 40 * 1 && MouseY < 195 + 40 * 1)
    {
      if (mouse_press(165 + 50 * 3, 175 + 40 * 1, 195 + 50 * 3, 195 + 40 * 1) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 3, 175 + 40 * 1, 195 + 50 * 3, 195 + 40 * 1, 11);
          num = 11;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 3, 175 + 40 * 1, 195 + 50 * 3, 195 + 40 * 1) == 1)
      {
        check_in(day, 11);
        continue;
      }
    }
    //ѡ��2��12��
    if (MouseX > 165 + 50 * 4 && MouseX < 195 + 50 * 4 && MouseY > 175 + 40 * 1 && MouseY < 195 + 40 * 1)
    {
      if (mouse_press(165 + 50 * 4, 175 + 40 * 1, 195 + 50 * 4, 195 + 40 * 1) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 4, 175 + 40 * 1, 195 + 50 * 4, 195 + 40 * 1, 12);
          num = 12;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 4, 175 + 40 * 1, 195 + 50 * 4, 195 + 40 * 1) == 1)
      {
        check_in(day, 12);
        continue;
      }
    }
    //ѡ��2��13��
    if (MouseX > 165 + 50 * 5 && MouseX < 195 + 50 * 5 && MouseY > 175 + 40 * 1 && MouseY < 195 + 40 * 1)
    {
      if (mouse_press(165 + 50 * 5, 175 + 40 * 1, 195 + 50 * 5, 195 + 40 * 1) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 5, 175 + 40 * 1, 195 + 50 * 5, 195 + 40 * 1, 13);
          num = 13;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 5, 175 + 40 * 1, 195 + 50 * 5, 195 + 40 * 1) == 1)
      {
        check_in(day, 13);
        continue;
      }
    }
    //ѡ��2��14��
    if (MouseX > 165 + 50 * 6 && MouseX < 195 + 50 * 6 && MouseY > 175 + 40 * 1 && MouseY < 195 + 40 * 1)
    {
      if (mouse_press(165 + 50 * 6, 175 + 40 * 1, 195 + 50 * 6, 195 + 40 * 1) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 6, 175 + 40 * 1, 195 + 50 * 6, 195 + 40 * 1, 14);
          num = 14;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 6, 175 + 40 * 1, 195 + 50 * 6, 195 + 40 * 1) == 1)
      {
        check_in(day, 14);
        continue;
      }
    }
    //ѡ��2��15��
    if (MouseX > 165 + 50 * 0 && MouseX < 195 + 50 * 0 && MouseY > 175 + 40 * 2 && MouseY < 195 + 40 * 2)
    {
      if (mouse_press(165 + 50 * 0, 175 + 40 * 2, 195 + 50 * 0, 195 + 40 * 2) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 0, 175 + 40 * 2, 195 + 50 * 0, 195 + 40 * 2, 15);
          num = 15;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 0, 175 + 40 * 2, 195 + 50 * 0, 195 + 40 * 2) == 1)
      {
        check_in(day, 15);
        continue;
      }
    }
    //ѡ��2��16��
    if (MouseX > 165 + 50 * 1 && MouseX < 195 + 50 * 1 && MouseY > 175 + 40 * 2 && MouseY < 195 + 40 * 2)
    {
      if (mouse_press(165 + 50 * 1, 175 + 40 * 2, 195 + 50 * 1, 195 + 40 * 2) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 1, 175 + 40 * 2, 195 + 50 * 1, 195 + 40 * 2, 16);
          num = 16;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 1, 175 + 40 * 2, 195 + 50 * 1, 195 + 40 * 2) == 1)
      {
        check_in(day, 16);
        continue;
      }
    }
    //ѡ��2��17��
    if (MouseX > 165 + 50 * 2 && MouseX < 195 + 50 * 2 && MouseY > 175 + 40 * 2 && MouseY < 195 + 40 * 2)
    {
      if (mouse_press(165 + 50 * 2, 175 + 40 * 2, 195 + 50 * 2, 195 + 40 * 2) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 2, 175 + 40 * 2, 195 + 50 * 2, 195 + 40 * 2, 17);
          num = 17;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 2, 175 + 40 * 2, 195 + 50 * 2, 195 + 40 * 2) == 1)
      {
        check_in(day, 17);
        continue;
      }
    }
    //ѡ��2��18��
    if (MouseX > 165 + 50 * 3 && MouseX < 195 + 50 * 3 && MouseY > 175 + 40 * 2 && MouseY < 195 + 40 * 2)
    {
      if (mouse_press(165 + 50 * 3, 175 + 40 * 2, 195 + 50 * 3, 195 + 40 * 2) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 3, 175 + 40 * 2, 195 + 50 * 3, 195 + 40 * 2, 18);
          num = 18;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 3, 175 + 40 * 2, 195 + 50 * 3, 195 + 40 * 2) == 1)
      {
        check_in(day, 18);
        continue;
      }
    }
    //ѡ��2��19��
    if (MouseX > 165 + 50 * 4 && MouseX < 195 + 50 * 4 && MouseY > 175 + 40 * 2 && MouseY < 195 + 40 * 2)
    {
      if (mouse_press(165 + 50 * 4, 175 + 40 * 2, 195 + 50 * 4, 195 + 40 * 2) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 4, 175 + 40 * 2, 195 + 50 * 4, 195 + 40 * 2, 19);
          num = 19;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 4, 175 + 40 * 2, 195 + 50 * 4, 195 + 40 * 2) == 1)
      {
        check_in(day, 19);
        continue;
      }
    }
    //ѡ��2��20��
    if (MouseX > 165 + 50 * 5 && MouseX < 195 + 50 * 5 && MouseY > 175 + 40 * 2 && MouseY < 195 + 40 * 2)
    {
      if (mouse_press(165 + 50 * 5, 175 + 40 * 2, 195 + 50 * 5, 195 + 40 * 2) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 5, 175 + 40 * 2, 195 + 50 * 5, 195 + 40 * 2, 20);
          num = 20;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 5, 175 + 40 * 2, 195 + 50 * 5, 195 + 40 * 2) == 1)
      {
        check_in(day, 20);
        continue;
      }
    }
    //ѡ��2��21��
    if (MouseX > 165 + 50 * 6 && MouseX < 195 + 50 * 6 && MouseY > 175 + 40 * 2 && MouseY < 195 + 40 * 2)
    {
      if (mouse_press(165 + 50 * 6, 175 + 40 * 2, 195 + 50 * 6, 195 + 40 * 2) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 6, 175 + 40 * 2, 195 + 50 * 6, 195 + 40 * 2, 21);
          num = 21;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 6, 175 + 40 * 2, 195 + 50 * 6, 195 + 40 * 2) == 1)
      {
        check_in(day, 21);
        continue;
      }
    }
    //ѡ��2��22��
    if (MouseX > 165 + 50 * 0 && MouseX < 195 + 50 * 0 && MouseY > 175 + 40 * 3 && MouseY < 195 + 40 * 3)
    {
      if (mouse_press(165 + 50 * 0, 175 + 40 * 3, 195 + 50 * 0, 195 + 40 * 3) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 0, 175 + 40 * 3, 195 + 50 * 0, 195 + 40 * 3, 22);
          num = 22;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 0, 175 + 40 * 3, 195 + 50 * 0, 195 + 40 * 3) == 1)
      {
        check_in(day, 22);
        continue;
      }
    }
    //ѡ��2��23��
    if (MouseX > 165 + 50 * 1 && MouseX < 195 + 50 * 1 && MouseY > 175 + 40 * 3 && MouseY < 195 + 40 * 3)
    {
      if (mouse_press(165 + 50 * 1, 175 + 40 * 3, 195 + 50 * 1, 195 + 40 * 3) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 1, 175 + 40 * 3, 195 + 50 * 1, 195 + 40 * 3, 23);
          num = 23;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 1, 175 + 40 * 3, 195 + 50 * 1, 195 + 40 * 3) == 1)
      {
        check_in(day, 23);
        continue;
      }
    }
    //ѡ��2��24��
    if (MouseX > 165 + 50 * 2 && MouseX < 195 + 50 * 2 && MouseY > 175 + 40 * 3 && MouseY < 195 + 40 * 3)
    {
      if (mouse_press(165 + 50 * 2, 175 + 40 * 3, 195 + 50 * 2, 195 + 40 * 3) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 2, 175 + 40 * 3, 195 + 50 * 2, 195 + 40 * 3, 24);
          num = 24;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 2, 175 + 40 * 3, 195 + 50 * 2, 195 + 40 * 3) == 1)
      {
        check_in(day, 24);
        continue;
      }
    }
    //ѡ��2��25��
    if (MouseX > 165 + 50 * 3 && MouseX < 195 + 50 * 3 && MouseY > 175 + 40 * 3 && MouseY < 195 + 40 * 3)
    {
      if (mouse_press(165 + 50 * 3, 175 + 40 * 3, 195 + 50 * 3, 195 + 40 * 3) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 3, 175 + 40 * 3, 195 + 50 * 3, 195 + 40 * 3, 25);
          num = 25;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 3, 175 + 40 * 3, 195 + 50 * 3, 195 + 40 * 3) == 1)
      {
        check_in(day, 25);
        continue;
      }
    }
    //ѡ��2��26��
    if (MouseX > 165 + 50 * 4 && MouseX < 195 + 50 * 4 && MouseY > 175 + 40 * 3 && MouseY < 195 + 40 * 3)
    {
      if (mouse_press(165 + 50 * 4, 175 + 40 * 3, 195 + 50 * 4, 195 + 40 * 3) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 4, 175 + 40 * 3, 195 + 50 * 4, 195 + 40 * 3, 26);
          num = 26;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 4, 175 + 40 * 3, 195 + 50 * 4, 195 + 40 * 3) == 1)
      {
        check_in(day, 26);
        continue;
      }
    }
    //ѡ��2��27��
    if (MouseX > 165 + 50 * 5 && MouseX < 195 + 50 * 5 && MouseY > 175 + 40 * 3 && MouseY < 195 + 40 * 3)
    {
      if (mouse_press(165 + 50 * 5, 175 + 40 * 3, 195 + 50 * 5, 195 + 40 * 3) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 5, 175 + 40 * 3, 195 + 50 * 5, 195 + 40 * 3, 27);
          num = 27;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 5, 175 + 40 * 3, 195 + 50 * 5, 195 + 40 * 3) == 1)
      {
        check_in(day, 27);
        continue;
      }
    }
    //ѡ��2��28��
    if (MouseX > 165 + 50 * 6 && MouseX < 195 + 50 * 6 && MouseY > 175 + 40 * 3 && MouseY < 195 + 40 * 3)
    {
      if (mouse_press(165 + 50 * 6, 175 + 40 * 3, 195 + 50 * 6, 195 + 40 * 3) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_checkin(165 + 50 * 6, 175 + 40 * 3, 195 + 50 * 6, 195 + 40 * 3, 28);
          num = 28;
        }
        continue;
      }
      if (mouse_press(165 + 50 * 6, 175 + 40 * 3, 195 + 50 * 6, 195 + 40 * 3) == 1)
      {
        check_in(day, 28);
        continue;
      }
    }

    //�ָ�����
    if (num != 0)
    {
      if (num == 1)
      {
        recover_checkin(165 + 50 * 0, 175 + 40 * 0, 195 + 50 * 0, 195 + 40 * 0, 1);
      }
      if (num == 2)
      {
        recover_checkin(165 + 50 * 1, 175 + 40 * 0, 195 + 50 * 1, 195 + 40 * 0, 2);
      }
      if (num == 3)
      {
        recover_checkin(165 + 50 * 2, 175 + 40 * 0, 195 + 50 * 2, 195 + 40 * 0, 3);
      }
      if (num == 4)
      {
        recover_checkin(165 + 50 * 3, 175 + 40 * 0, 195 + 50 * 3, 195 + 40 * 0, 4);
      }
      if (num == 5)
      {
        recover_checkin(165 + 50 * 4, 175 + 40 * 0, 195 + 50 * 4, 195 + 40 * 0, 5);
      }
      if (num == 6)
      {
        recover_checkin(165 + 50 * 5, 175 + 40 * 0, 195 + 50 * 5, 195 + 40 * 0, 6);
      }
      if (num == 7)
      {
        recover_checkin(165 + 50 * 6, 175 + 40 * 0, 195 + 50 * 6, 195 + 40 * 0, 7);
      }
      if (num == 8)
      {
        recover_checkin(165 + 50 * 0, 175 + 40 * 1, 195 + 50 * 0, 195 + 40 * 1, 8);
      }
      if (num == 9)
      {
        recover_checkin(165 + 50 * 1, 175 + 40 * 1, 195 + 50 * 1, 195 + 40 * 1, 9);
      }
      if (num == 10)
      {
        recover_checkin(165 + 50 * 2, 175 + 40 * 1, 195 + 50 * 2, 195 + 40 * 1, 10);
      }
      if (num == 11)
      {
        recover_checkin(165 + 50 * 3, 175 + 40 * 1, 195 + 50 * 3, 195 + 40 * 1, 11);
      }
      if (num == 12)
      {
        recover_checkin(165 + 50 * 4, 175 + 40 * 1, 195 + 50 * 4, 195 + 40 * 1, 12);
      }
      if (num == 13)
      {
        recover_checkin(165 + 50 * 5, 175 + 40 * 1, 195 + 50 * 5, 195 + 40 * 1, 13);
      }
      if (num == 14)
      {
        recover_checkin(165 + 50 * 6, 175 + 40 * 1, 195 + 50 * 6, 195 + 40 * 1, 14);
      }
      if (num == 15)
      {
        recover_checkin(165 + 50 * 0, 175 + 40 * 2, 195 + 50 * 0, 195 + 40 * 2, 15);
      }
      if (num == 16)
      {
        recover_checkin(165 + 50 * 1, 175 + 40 * 2, 195 + 50 * 1, 195 + 40 * 2, 16);
      }
      if (num == 17)
      {
        recover_checkin(165 + 50 * 2, 175 + 40 * 2, 195 + 50 * 2, 195 + 40 * 2, 17);
      }
      if (num == 18)
      {
        recover_checkin(165 + 50 * 3, 175 + 40 * 2, 195 + 50 * 3, 195 + 40 * 2, 18);
      }
      if (num == 19)
      {
        recover_checkin(165 + 50 * 4, 175 + 40 * 2, 195 + 50 * 4, 195 + 40 * 2, 19);
      }
      if (num == 20)
      {
        recover_checkin(165 + 50 * 5, 175 + 40 * 2, 195 + 50 * 5, 195 + 40 * 2, 20);
      }
      if (num == 21)
      {
        recover_checkin(165 + 50 * 6, 175 + 40 * 2, 195 + 50 * 6, 195 + 40 * 2, 21);
      }
      if (num == 22)
      {
        recover_checkin(165 + 50 * 0, 175 + 40 * 3, 195 + 50 * 0, 195 + 40 * 3, 22);
      }
      if (num == 23)
      {
        recover_checkin(165 + 50 * 1, 175 + 40 * 3, 195 + 50 * 1, 195 + 40 * 3, 23);
      }
      if (num == 24)
      {
        recover_checkin(165 + 50 * 2, 175 + 40 * 3, 195 + 50 * 2, 195 + 40 * 3, 24);
      }
      if (num == 25)
      {
        recover_checkin(165 + 50 * 3, 175 + 40 * 3, 195 + 50 * 3, 195 + 40 * 3, 25);
      }
      if (num == 26)
      {
        recover_checkin(165 + 50 * 4, 175 + 40 * 3, 195 + 50 * 4, 195 + 40 * 3, 26);
      }
      if (num == 27)
      {
        recover_checkin(165 + 50 * 5, 175 + 40 * 3, 195 + 50 * 5, 195 + 40 * 3, 27);
      }
      if (num == 28)
      {
        recover_checkin(165 + 50 * 6, 175 + 40 * 3, 195 + 50 * 6, 195 + 40 * 3, 28);
      }
      if (num == 29)
      {
        recover_checkin(460, 390, 550, 425, 29);
      }
      num = 0;
    }

    //�����������
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}

/***********************************
FUNCTION: lightup_checkin
DESCRIPTION: �Ƶ���ס����ѡ����水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_checkin(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setcolor(LIGHTRED);
  setfillstyle(1, LIGHTGRAY);

  bar(x1, y1, x2, y2);                       //����ڲ�
  rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //���߿�
  switch (flag)
  {
  case 1:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 0 + 10, 155 + 20 + 0 * 40 - 2, "1");
    break;
  }
  case 2:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 1 + 10, 155 + 20 + 0 * 40 - 2, "2");
    break;
  }
  case 3:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 2 + 10, 155 + 20 + 0 * 40 - 2, "3");
    break;
  }
  case 4:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 3 + 10, 155 + 20 + 0 * 40 - 2, "4");
    break;
  }
  case 5:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 4 + 10, 155 + 20 + 0 * 40 - 2, "5");
    break;
  }
  case 6:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 5 + 10, 155 + 20 + 0 * 40 - 2, "6");
    break;
  }
  case 7:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 6 + 10, 155 + 20 + 0 * 40 - 2, "7");
    break;
  }
  case 8:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 0 + 10, 155 + 20 + 1 * 40 - 2, "8");
    break;
  }
  case 9:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 1 + 10, 155 + 20 + 1 * 40 - 2, "9");
    break;
  }
  case 10:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 2 + 5, 155 + 20 + 1 * 40 - 2, "10");
    break;
  }
  case 11:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 3 + 5, 155 + 20 + 1 * 40 - 2, "11");
    break;
  }
  case 12:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 4 + 5, 155 + 20 + 1 * 40 - 2, "12");
    break;
  }
  case 13:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 5 + 5, 155 + 20 + 1 * 40 - 2, "13");
    break;
  }
  case 14:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 6 + 5, 155 + 20 + 1 * 40 - 2, "14");
    break;
  }
  case 15:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 0 + 5, 155 + 20 + 2 * 40 - 2, "15");
    break;
  }
  case 16:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 1 + 5, 155 + 20 + 2 * 40 - 2, "16");
    break;
  }
  case 17:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 2 + 5, 155 + 20 + 2 * 40 - 2, "17");
    break;
  }
  case 18:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 3 + 5, 155 + 20 + 2 * 40 - 2, "18");
    break;
  }
  case 19:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 4 + 5, 155 + 20 + 2 * 40 - 2, "19");
    break;
  }
  case 20:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 5 + 5, 155 + 20 + 2 * 40 - 2, "20");
    break;
  }
  case 21:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 6 + 5, 155 + 20 + 2 * 40 - 2, "21");
    break;
  }
  case 22:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 0 + 5, 155 + 20 + 3 * 40 - 2, "22");
    break;
  }
  case 23:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 1 + 5, 155 + 20 + 3 * 40 - 2, "23");
    break;
  }
  case 24:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 2 + 5, 155 + 20 + 3 * 40 - 2, "24");
    break;
  }
  case 25:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 3 + 5, 155 + 20 + 3 * 40 - 2, "25");
    break;
  }
  case 26:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 4 + 5, 155 + 20 + 3 * 40 - 2, "26");
    break;
  }
  case 27:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 5 + 5, 155 + 20 + 3 * 40 - 2, "27");
    break;
  }
  case 28:
  {
    setcolor(RED);
    outtextxy(165 + 50 * 6 + 5, 155 + 20 + 3 * 40 - 2, "28");
    break;
  }
  case 29:
  {
    puthz(470, 400, "����ǰҳ", 16, 18, 4);
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
FUNCTION: recover_checkin
DESCRIPTION: �Ƶ���ס����ѡ����水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recover_checkin(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x1, y1, x2, y2);
  switch (flag)
  {
  case 1:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 0 + 10, 155 + 20 + 0 * 40 - 2, "1");
    break;
  }
  case 2:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 1 + 10, 155 + 20 + 0 * 40 - 2, "2");
    break;
  }
  case 3:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 2 + 10, 155 + 20 + 0 * 40 - 2, "3");
    break;
  }
  case 4:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 3 + 10, 155 + 20 + 0 * 40 - 2, "4");
    break;
  }
  case 5:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 4 + 10, 155 + 20 + 0 * 40 - 2, "5");
    break;
  }
  case 6:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 5 + 10, 155 + 20 + 0 * 40 - 2, "6");
    break;
  }
  case 7:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 6 + 10, 155 + 20 + 0 * 40 - 2, "7");
    break;
  }
  case 8:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 0 + 10, 155 + 20 + 1 * 40 - 2, "8");
    break;
  }
  case 9:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 1 + 10, 155 + 20 + 1 * 40 - 2, "9");
    break;
  }
  case 10:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 2 + 5, 155 + 20 + 1 * 40 - 2, "10");
    break;
  }
  case 11:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 3 + 5, 155 + 20 + 1 * 40 - 2, "11");
    break;
  }
  case 12:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 4 + 5, 155 + 20 + 1 * 40 - 2, "12");
    break;
  }
  case 13:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 5 + 5, 155 + 20 + 1 * 40 - 2, "13");
    break;
  }
  case 14:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 6 + 5, 155 + 20 + 1 * 40 - 2, "14");
    break;
  }
  case 15:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 0 + 5, 155 + 20 + 2 * 40 - 2, "15");
    break;
  }
  case 16:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 1 + 5, 155 + 20 + 2 * 40 - 2, "16");
    break;
  }
  case 17:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 2 + 5, 155 + 20 + 2 * 40 - 2, "17");
    break;
  }
  case 18:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 3 + 5, 155 + 20 + 2 * 40 - 2, "18");
    break;
  }
  case 19:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 4 + 5, 155 + 20 + 2 * 40 - 2, "19");
    break;
  }
  case 20:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 5 + 5, 155 + 20 + 2 * 40 - 2, "20");
    break;
  }
  case 21:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 6 + 5, 155 + 20 + 2 * 40 - 2, "21");
    break;
  }
  case 22:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 0 + 5, 155 + 20 + 3 * 40 - 2, "22");
    break;
  }
  case 23:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 1 + 5, 155 + 20 + 3 * 40 - 2, "23");
    break;
  }
  case 24:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 2 + 5, 155 + 20 + 3 * 40 - 2, "24");
    break;
  }
  case 25:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 3 + 5, 155 + 20 + 3 * 40 - 2, "25");
    break;
  }
  case 26:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 4 + 5, 155 + 20 + 3 * 40 - 2, "26");
    break;
  }
  case 27:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 5 + 5, 155 + 20 + 3 * 40 - 2, "27");
    break;
  }
  case 28:
  {
    setcolor(DARKGRAY);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    outtextxy(165 + 50 * 6 + 5, 155 + 20 + 3 * 40 - 2, "28");
    break;
  }
  case 29:
  {
    setcolor(LIGHTCYAN);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    puthz(470, 400, "����ǰҳ", 16, 18, 5);
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
FUNCTION: date_select
DESCRIPTION: ������ס���ڻ���
INPUT: x,y
RETURN: ��
***********************************/
void date_select(int x, int y)
{
  int i, j;
  int count = 0;
  char date[3] = "\0";

  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x, y, x + 300, y + 200);
  setfillstyle(SOLID_FILL, WHITE);
  setcolor(DARKGRAY);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  settextjustify(LEFT_TEXT, TOP_TEXT);
  for (j = 0; j < 4; j++)
  {
    for (i = 0; i < 7; i++)
    {
      count++;
      itoa(count, date, 10);
      bar(x + 20 + 50 * i, y + 20 + j * 40, x + 20 + 50 * i + 30, y + 20 + j * 40 + 20);
      rectangle(x + 20 + 50 * i, y + 20 + j * 40, x + 20 + 50 * i + 30, y + 20 + j * 40 + 20);
      if (count < 10)
      {
        outtextxy(x + 20 + 50 * i + 10, y + 20 + j * 40 - 2, date);
      }
      else if (count >= 10)
      {
        outtextxy(x + 20 + 50 * i + 5, y + 20 + j * 40 - 2, date);
      }
    }
  }
  puthz(145, 118, "����", 32, 35, 1);
}

/***********************************
FUNCTION: check_in
DESCRIPTION: �ϴ�������������
INPUT: ��
RETURN: ��
***********************************/
void check_in(char *day, int data)
{
  // rectangle(120, 110, 540, 370);
  // rectangle(125, 105, 545, 365);
  setfillstyle(SOLID_FILL, WHITE);
  bar(280, 115, 530, 160);
  itoa(data, day, 10);
  puthz(380, 130, "����", 16, 18, 6);
  setcolor(BROWN);
  outtextxy(420, 125, day);
  if (data < 10)
  {
    puthz(435, 130, "����ס", 16, 18, 6);
  }
  else if (data >= 10)
  {
    puthz(445, 130, "����ס", 16, 18, 6);
  }
}

/***********************************
FUNCTION: htinfo_draw
DESCRIPTION: �ϴ�������������
INPUT: ��
RETURN: ��
***********************************/
void checkin_draw(void)
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
  puthz(65, 20, "�Ѷ����Ƶ���Ϣ", 32, 35, 4);
  puthz(66, 21, "�Ѷ����Ƶ���Ϣ", 32, 35, 4);
  setcolor(DARKGRAY);
  rectangle(120, 110, 540, 370);
  rectangle(125, 105, 545, 365);
  puthz(470, 400, "����ǰҳ", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(460, 390, 550, 425);
  puthz(380, 130, "��δ������ס", 16, 18, 6);
}