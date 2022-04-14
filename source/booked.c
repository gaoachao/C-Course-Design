/***********************************
FILE: booked.c
DESCRIPTION: �Ƶ궩��֧������
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

/***********************************
FUNCTION: booked_main
DESCRIPTION: ��Ʊ������
INPUT: *func,*name,*id,t
RETURN: ��
***********************************/
void booked_main(int *func, USER *u, Hotle *h, Live *L)
{
  int num = 0;
  char filename[30];
  int live_day = 1; // int���;�ס����
  char liveday[3];  // char���͵ľ�ס����
  FILE *fp;
  strcpy(liveday, "1");

  hotle_booked_draw(u->name, h->hotle_city, h->hotle_name, h->hotle_class, h->price);

  memset(L, '\0', sizeof(Live));
  delay(100);
  strcpy(filename, "database\\");
  strcat(filename, u->name);
  strcpy(L->city, h->hotle_city);
  strcpy(L->name, h->hotle_name);
  strcpy(L->price, h->price);
  strcpy(L->class, h->hotle_class);
  strcpy(L->day, liveday);
  
  //�ļ��в���
  if (access(filename, 0) == -1) //�ļ��в�����
  {
    if (mkdir(filename) != 0)
    {
      printf("The file news failed\n");
    }
  }
  strcat(filename, "\\live.dat");
  if (access(filename, 0) == -1) // live.dat�ļ�������(�Ѷ�������Ϣ)
  {
    if ((fp = fopen(filename, "wb+")) == NULL) //��д�򿪻���һ���������ļ�,�������ڻ��½�
    {
      printf("%s new failed\n", filename);
      delay(3000);
      exit(1);
    }
    if (fclose(fp) != 0)
    {
      printf("%s close failed\n", filename);
      delay(3000);
      exit(1);
    }
  }

  //�ս���ҳ�����һ�ν���״̬���ж�
  if (strcmp(u->health_code, "1") == 0)
  {
    puthz(255, 150, "����", 16, 18, 2);
  }
  else if (strcmp(u->health_code, "2") == 0)
  {
    puthz(255, 150, "����", 16, 18, 6);
  }
  else if (strcmp(u->health_code, "3") == 0)
  {
    puthz(255, 150, "����", 16, 18, 4);
  }
  //������
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
    //���ؼ�
    if (MouseX > 435 && MouseX < 500 && MouseY > 390 && MouseY < 425)
    {
      if (mouse_press(435, 390, 500, 425) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_booked(435, 390, 500, 425, 2);
          num = 2;
        }
        continue;
      }
      else if (mouse_press(435, 390, 500, 425) == 1)
      {
        *func = 11;
        return;
      }
    }
    //ȷ��֧������
    if (MouseX > 250 && MouseX < 340 && MouseY > 390 && MouseY < 425)
    {
      if (mouse_press(250, 390, 340, 425) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_booked(250, 390, 340, 425, 1);
          num = 1;
        }
        continue;
      }
      else if (mouse_press(250, 390, 340, 425) == 1)
      {
        if (strcmp(u->health_code, "1") == 0)
        {
          puthz(300, 435, "���룬������ס", 16, 18, 8);
          *func = 18;
          delay(1000);
          return;
        }
        else if (strcmp(u->health_code, "2") == 0)
        {
          puthz(300, 435, "���룬�޷���ס", 16, 18, 8);
        }
        else if (strcmp(u->health_code, "3") == 0)
        {
          puthz(300, 435, "���룬�޷���ס", 16, 18, 8);
        }
        else if (strcmp(u->health_code, "0") == 0)
        {
          puthz(300, 435, "����״̬��δ�", 16, 18, 8);
        }
      }
    }

    //���Ӿ�ס����
    if (MouseX > 290 && MouseX < 310 && MouseY > 350 && MouseY < 365)
    {
      if (mouse_press(290, 350, 310, 365) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(290, 350, 310, 365) == 1)
      {
        live_day++;
        itoa(live_day, liveday, 10);
        strcpy(L->day, liveday);
        setfillstyle(SOLID_FILL, WHITE);
        bar(270, 340, 290, 375);
        setcolor(BLUE);
        outtextxy(275, 345, liveday);
        delay(200);
      }
    }

    //���پ�ס����
    if (MouseX > 245 && MouseX < 265 && MouseY > 350 && MouseY < 365)
    {
      if (mouse_press(245, 350, 265, 365) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(245, 350, 265, 365) == 1)
      {
        live_day--;
        itoa(live_day, liveday, 10);
        strcpy(L->day, liveday);
        setfillstyle(SOLID_FILL, WHITE);
        bar(270, 340, 290, 375);
        setcolor(BLUE);
        outtextxy(275, 345, liveday);
        delay(200);
      }
    }

    //�ָ�����
    if (num != 0)
    {
      if (num == 1)
      {
        recover_booked(250, 390, 340, 425, 1);
      }
      if (num == 2)
      {
        recover_booked(435, 390, 500, 425, 2);
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
FUNCTION: lightup_booked
DESCRIPTION: �Ƶ���Ϣȷ�Ͻ��水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_booked(int x1, int y1, int x2, int y2, int flag)
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
    puthz(260, 400, "ȷ��֧��", 16, 18, 4);
    break;
  }

  case 2:
  {
    puthz(450, 400, "����", 16, 18, 4);
    break;
  }
  case 3: //Ϊpayment.c����
  {
    puthz(200, 350, "ȷ������", 16, 18, 4);
    break;
  }

  default:
    printf("something wrong in loghtup_purchace_confirm\n");
    break;
  }
}

/***********************************
FUNCTION: recover_booked
DESCRIPTION: �Ƶ���Ϣȷ�Ͻ��水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recover_booked(int x1, int y1, int x2, int y2, int flag)
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
    puthz(260, 400, "ȷ��֧��", 16, 18, 5);
    break;
  }

  case 2:
  {
    puthz(450, 400, "����", 16, 18, 5);
    break;
  }

  case 3: //Ϊpayment.c����
  {
    puthz(200, 350, "ȷ������", 16, 18, 1);
    break;
  }

  default:
  {
    printf("something wrong in recoverbuttom_purchace_confirmr\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: hotle_booked_draw
DESCRIPTION: ��Ϣȷ�Ͻ������
INPUT: *u,t
RETURN: ��
***********************************/
void hotle_booked_draw(char *name, char *hotle_city, char *hotle_name, char *hotle_class, char *price)
{
  cleardevice();
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setcolor(GREEN);
  arc(0, 480, 0, 75, 160);
  setfillstyle(SOLID_FILL, GREEN);
  fillellipse(0, 480, 160, 160);
  puthz(65, 20, "��ӭ��ס��", 32, 35, 4);
  puthz(160, 110, "�ÿ�������", 16, 18, 6);
  setcolor(BLUE);
  outtextxy(255, 107, name);
  puthz(160, 150, "����״̬��", 16, 18, 6);
  puthz(160, 190, "���ڳ��У�", 16, 18, 6);
  puthz(255, 190, hotle_city, 16, 18, 1);
  puthz(160, 230, "�Ƶ����ƣ�", 16, 18, 6);
  puthz(255, 230, hotle_name, 16, 18, 1);
  puthz(160, 270, "�������ͣ�", 16, 18, 6);
  puthz(255, 270, hotle_class, 16, 18, 1);
  puthz(160, 310, "���䵥�ۣ�", 16, 18, 6);
  outtextxy(255, 307, price);
  puthz(160, 350, "��ס������", 16, 18, 6);
  setcolor(DARKGRAY);
  outtextxy(255, 345, "-");
  setcolor(BLUE);
  outtextxy(275, 345, "1");
  setcolor(DARKGRAY);
  outtextxy(295, 345, "+");
  puthz(480, 20, "��ϴ�֣���ͨ�磡", 16, 18, 8);
  puthz(480, 50, "�����֣��پۼ���", 16, 18, 8);
  puthz(480, 80, "������ǰ��С�£�", 16, 18, 8);
  puthz(260, 400, "ȷ��֧��", 16, 18, 5);
  puthz(450, 400, "����", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(250, 390, 340, 425);
  rectangle(435, 390, 500, 425);
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
