/***********************************
FILE: upload.c
DESCRIPTION: �������ϴ�����
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
#include "payment.h"
#include "upload.h"

/***********************************
FUNCTION: upload_main
DESCRIPTION: �ϴ�������������
INPUT: ��
RETURN: ��
***********************************/
void upload_main(int *func, USER *u)
{
  upload_draw();
  exit_buttom();
  get_healthstate(u);
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //���ؼ�
    if (MouseX > 370 && MouseX < 420 && MouseY > 280 && MouseY < 310)
    {
      if (mouse_press(370, 280, 420, 310) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(370, 280, 420, 310) == 1)
      {
        *func = 11;
        return;
      }
    }

    //�ϴ���
    if (MouseX > 230 && MouseX < 280 && MouseY > 280 && MouseY < 310)
    {
      if (mouse_press(230, 280, 280, 310) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(230, 280, 280, 310) == 1)
      {
        *func = 21;
        return;
      }
    }
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

    //�����������
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}

/*****************************
FUNCTION: get_healthstate
DESCRIPTION: �������ϴ������ȡ������Ϣ
INPUT: u
RETURN: ��
*****************************/
void get_healthstate(USER *u)
{
  settextjustify(LEFT_TEXT, TOP_TEXT); //�����ı����뷽ʽ
  settextstyle(2, 0, 7);
  setcolor(DARKGRAY);
  outtextxy(320, 145, u->name);
  if (strcmp(u->health_code, "1") == 0)
  {
    puthz(360, 190, "����", 16, 18, 2);
  }
  else if (strcmp(u->health_code, "2") == 0)
  {
    puthz(360, 190, "����", 16, 18, 6);
  }
  else if (strcmp(u->health_code, "3") == 0)
  {
    puthz(360, 190, "����", 16, 18, 4);
  }
  else if (strcmp(u->health_code, "0") == 0)
  {
    puthz(360, 190, "δ�", 16, 18, 8);
  }
}

/***********************************
FUNCTION: upload_draw
DESCRIPTION: �ϴ�������������
INPUT: ��
RETURN: ��
***********************************/
void upload_draw(void)
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
  puthz(65, 20, "�������ϴ�", 32, 35, 4);
  puthz(66, 21, "�������ϴ�", 32, 35, 4);
  puthz(210, 150, "�û�������", 16, 18, 5);
  puthz(210, 190, "��Ľ���״̬��", 16, 18, 5);
  setcolor(DARKGRAY);
  rectangle(180, 125, 470, 240);
  rectangle(181, 126, 471, 241);
  puthz(240, 290, "�ϴ�", 16, 28, 1);
  puthz(380, 290, "����", 16, 28, 1);
}

//�����״Shape 1Ϊ���ƣ�2Ϊ��꣬3Ϊʮ��

/* 1 ��ɫ
   2 ��ɫ
   3 ��ɫ
   4 ��ɫ
   5 ÷��ɫ
   6 �ػ�ɫ��ƫ��
   7 ����ɫ
   8 ���ɫ
   9 ����ɫ
*/