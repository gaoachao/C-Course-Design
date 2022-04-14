/***********************************
FILE: mycard.c
DESCRIPTION: ���п���Ϣ����
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
#include "mycard.h"

/***********************************
FUNCTION: mycard_main
DESCRIPTION: �������������
INPUT: *func
RETURN: ��
***********************************/
void mycard_main(int *func, USER *u)
{
  mycard_draw();
  exit_buttom();
  get_cardinfo(u);

  //������
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //����ǰҳ
    if (MouseX > 315 && MouseX < 380 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(315, 80, 380, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(315, 80, 380, 110) == 1)
      {
        *func = 5;
        return;
      }
    }

    //���п��˻���Ϣ�ָ�
    if (MouseX > 75 && MouseX < 150 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(75, 80, 150, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(75, 80, 150, 110) == 1)
      {
        recover_cardinfo(u);
      }
    }

    //���п����İ���Ϣ
    if (MouseX > 195 && MouseX < 270 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(195, 80, 270, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(195, 80, 270, 110) == 1)
      {
        *func = 14;
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
FUNCTION: get_cardinfo
DESCRIPTION: ���п���Ϣ
INPUT: u
RETURN: ��
*****************************/
void get_cardinfo(USER *u)
{
  settextjustify(LEFT_TEXT, TOP_TEXT); //�����ı����뷽ʽ
  settextstyle(2, 0, 7);
  setcolor(DARKGRAY);
  outtextxy(170, 147, u->name);
  outtextxy(170, 187, u->bank);
}



/*****************************
FUNCTION: recover_cardinfo
DESCRIPTION: �ָ����п���Ϣ
INPUT: u
RETURN: ��
*****************************/
void recover_cardinfo(USER *u)
{
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 115, 640, 480);
  settextjustify(LEFT_TEXT, TOP_TEXT); //�����ı����뷽ʽ
  settextstyle(2, 0, 7);
  setcolor(DARKGRAY);
  outtextxy(170, 147, u->name);
  outtextxy(170, 187, u->bank);
  puthz(80, 150, "�û�������", 16, 18, 5);
  puthz(80, 190, "���п��ţ�", 16, 18, 5);
  puthz(450, 410, "ע�Ᵽ���Ʋ���ϢŶ��", 16, 18, 6);
}

/***********************************
FUNCTION: mycard_draw
DESCRIPTION: ������ؽ���
INPUT: ��
RETURN: ��
***********************************/
void mycard_draw(void)
{
  clrmous(MouseX, MouseY);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  puthz(65, 20, "�ҵ����п�", 32, 35, 4);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(0, 75, 640, 110);
  puthz(80, 85, "�˻���Ϣ", 16, 18, 1);
  puthz(200, 85, "������", 16, 18, 1);
  puthz(320, 85, "����ǰҳ", 16, 18, 1);
  puthz(80, 150, "�û�������", 16, 18, 5);
  puthz(80, 190, "���п��ţ�", 16, 18, 5);
  puthz(450, 450, "ע�Ᵽ���Ʋ���ϢŶ��", 16, 18, 6);
}