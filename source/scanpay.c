/***********************************
FILE: scanpay.c
DESCRIPTION: �Ƶ�ɨ��֧������
***********************************/
#include <stdio.h>
#include <direct.h>
#include <graphics.h>
#include <bios.h>           #include<time.h>
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
#include "scanpay.h"

/***********************************
FUNCTION: scanpay_main
DESCRIPTION: �Ƶ�ɨ��֧��������
INPUT: *func,
RETURN: ��
***********************************/
void scanpay_main(int *func, USER *u, Live *L)
{
  int num = 0;
  int single_price = 0;
  int livingday = 0;
  int total_price = 0;
  char totalpay[2];
  scanpay_draw();
  exit_buttom();
  memset(totalpay, '\0', sizeof(totalpay));
  single_price = atoi(L->price);
  livingday = atoi(L->day); //�ַ���ת��Ϊ����
  total_price = single_price * livingday;
  itoa(total_price, totalpay, 10); //����ת��Ϊ�ַ���
  setcolor(DARKGRAY);
  outtextxy(425, 215, totalpay);
  outtextxy(425, 175, u->name);

  //������
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //����ǰҳ
    if (MouseX > 335 && MouseX < 400 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(335, 80, 400, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(335, 80, 400, 110) == 1)
      {
        *func = 12;
        return;
      }
    }

    //ɨ��֧������
    if (MouseX > 215 && MouseX < 280 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(215, 80, 280, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(215, 80, 280, 110) == 1)
      {
        *func = 18;
        return;
      }
    }

    //���п�֧��
    if (MouseX > 75 && MouseX < 170 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(75, 80, 170, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(75, 80, 170, 110) == 1)
      {
        *func = 18;
        return;
      }
    }

    //ȷ�����ť
    if (MouseX > 355 && MouseX < 440 && MouseY > 270 && MouseY < 310)
    {
      if (mouse_press(355, 270, 440, 310) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_scanpay(355, 270, 440, 310, 1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(355, 270, 440, 310) == 1)
      {
        inputlive_database(u, L); //��payment�У����Ѷ����Ƶ���Ϣд��LIVE.dat
        scanpay_scan();
        delay(2000);
        puthz(345, 330, "����ɹ�", 16, 18, 8);
        continue;
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

    //�ָ�����
    if (num != 0)
    {
      if (num == 1)
      {
        recover_scanpay(355, 270, 440, 310, 1);
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
FUNCTION: scanpay_scan
DESCRIPTION: ɨ�붯������
INPUT: ��
RETURN: ��
***********************************/
void scanpay_scan(void)
{
  int i, j;
  unsigned int size;
  void *pt_addr;

  clrmous(MouseX, MouseY);

  setlinestyle(0, 0, 4);
  setcolor(RED);
  line(60, 120, 270, 120);

  size = imagesize(60, 120, 270, 120);
  if ((pt_addr = malloc(size)) == NULL)
  {
    exit(1);
  }
  getimage(60, 120, 270, 120, pt_addr);

  setcolor(WHITE);
  line(60, 120, 270, 120);

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j + 120 < 330; j += 2)
    {
      putimage(60, 120 + j, pt_addr, XOR_PUT);
      delay(25);
      putimage(60, 120 + j, pt_addr, XOR_PUT);
    }
  }
  free(pt_addr);
}

/***********************************
FUNCTION: lightup_scanpay
DESCRIPTION: �Ƶ�ɨ�븶����水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_scanpay(int x1, int y1, int x2, int y2, int flag)
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
    puthz(360, 280, "ȷ������", 16, 20, 4);
    break;
  }

  default:
  {
    printf("something wrong in recover_scanpay\n");
    break;
  }
  }
}

/***********************************
FUNCTION: recover_scanpay
DESCRIPTION: �Ƶ�ɨ�븶����水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recover_scanpay(int x1, int y1, int x2, int y2, int flag)
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
    puthz(360, 280, "ȷ������", 16, 20, 5);
    break;
  }

  default:
  {
    printf("something wrong in recover_scanpay\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: scanpay_draw
DESCRIPTION: �Ƶ�֧����ͼ
INPUT: ��
RETURN: ��
***********************************/
void scanpay_draw(void)
{
  int m, n, i;
  clrmous(MouseX, MouseY);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setcolor(GREEN);
  arc(0, 480, 0, 75, 160);
  setfillstyle(SOLID_FILL, GREEN);
  fillellipse(0, 480, 160, 160);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(0, 75, 640, 110);
  puthz(65, 20, "֧��", 32, 35, 4);
  puthz(80, 83, "���п�֧��", 16, 18, 1);
  puthz(220, 83, "ɨ��֧��", 16, 18, 1);
  puthz(340, 83, "����ǰҳ", 16, 18, 1);
  puthz(330, 180, "�û�������", 16, 18, 6);
  puthz(330, 220, "������", 16, 18, 6);
  puthz(360, 280, "ȷ������", 16, 20, 5);
  setcolor(LIGHTCYAN);
  rectangle(355, 270, 440, 310);
  //������ά��
  srand(time(NULL));
  for (m = 0; m < 38; m++)
  {
    for (n = 0; n < 38; n++)
    {
      i = rand() % 20;
      if (i < 10)
      {
        setcolor(DARKGRAY);
        setfillstyle(SOLID_FILL, DARKGRAY);
        bar(70 + m * 5, 130 + n * 5, 70 + (m + 1) * 5, 130 + (n + 1) * 5);
        setcolor(DARKGRAY);
        setfillstyle(SOLID_FILL, WHITE);
        bar(69, 129, 121, 181);
        bar(69, 269, 121, 321);
        bar(209, 129, 261, 181);
        setcolor(DARKGRAY);
        setfillstyle(SOLID_FILL, DARKGRAY);
        bar(70, 130, 120, 180);
        bar(70, 270, 120, 320);
        bar(210, 130, 260, 180);
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, DARKGRAY);
        bar(80, 140, 110, 170);
        bar(80, 280, 110, 310);
        bar(220, 140, 250, 170);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, DARKGRAY);
        bar(90, 150, 100, 160);
        bar(90, 290, 100, 300);
        bar(230, 150, 240, 160);
      }
    }
  }
  setcolor(BROWN);
  line(50, 110, 100, 110);
  line(50, 110, 50, 160);
  line(230, 110, 280, 110);
  line(280, 110, 280, 160);
  line(230, 340, 280, 340);
  line(280, 340, 280, 270);
  line(50, 340, 100, 340);
  line(50, 340, 50, 270);
}