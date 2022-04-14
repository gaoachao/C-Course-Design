/***********************************
FILE: up.c
DESCRIPTION: ������
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

/***********************************
FUNCTION: up_main
DESCRIPTION: ������������
INPUT: ��
RETURN: ��
***********************************/
void up_main(int *func, USER *u)
{
  int m, n, i;
  int num = 0;    //��ť����״̬��¼
  int state = 0;  //�������Ƿ��ϴ�
  int state2 = 0; //��¼�Ƿ����ɨ��

  up_draw();
  exit_buttom();
  srand(time(NULL));
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
    if (state == 0)
    {
      if (strcmp(u->health_code, "1") == 0)
      {
        for (m = 0; m < 38; m++)
        {
          for (n = 0; n < 38; n++)
          {
            i = rand() % 20;
            if (i < 10)
            {
              setcolor(GREEN);
              setfillstyle(SOLID_FILL, GREEN);
              bar(270 + m * 5, 130 + n * 5, 270 + (m + 1) * 5, 130 + (n + 1) * 5);
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, WHITE);
              bar(269, 129, 321, 181);
              bar(269, 269, 321, 321);
              bar(409, 129, 461, 181);
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, GREEN);
              bar(270, 130, 320, 180);
              bar(270, 270, 320, 320);
              bar(410, 130, 460, 180);
              setcolor(WHITE);
              setfillstyle(SOLID_FILL, GREEN);
              bar(280, 140, 310, 170);
              bar(280, 280, 310, 310);
              bar(420, 140, 450, 170);
              setcolor(BLACK);
              setfillstyle(SOLID_FILL, GREEN);
              bar(290, 150, 300, 160);
              bar(290, 290, 300, 300);
              bar(430, 150, 440, 160);
            }
          }
        }
        setcolor(BROWN);
        line(250, 110, 300, 110);
        line(250, 110, 250, 160);
        line(430, 110, 480, 110);
        line(480, 110, 480, 160);
        line(430, 340, 480, 340);
        line(480, 340, 480, 270);
        line(250, 340, 300, 340);
        line(250, 340, 250, 270);
        state = 1;
        state2 = 1;
        continue;
      }
      else if (strcmp(u->health_code, "2") == 0)
      {
        for (m = 0; m < 38; m++)
        {
          for (n = 0; n < 38; n++)
          {
            i = rand() % 20;
            if (i < 10)
            {
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(270 + m * 5, 130 + n * 5, 270 + (m + 1) * 5, 130 + (n + 1) * 5);
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, WHITE);
              bar(269, 129, 321, 181);
              bar(269, 269, 321, 321);
              bar(409, 129, 461, 181);
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(270, 130, 320, 180);
              bar(270, 270, 320, 320);
              bar(410, 130, 460, 180);
              setcolor(WHITE);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(280, 140, 310, 170);
              bar(280, 280, 310, 310);
              bar(420, 140, 450, 170);
              setcolor(BLACK);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(290, 150, 300, 160);
              bar(290, 290, 300, 300);
              bar(430, 150, 440, 160);
            }
          }
        }
        setcolor(BROWN);
        line(250, 110, 300, 110);
        line(250, 110, 250, 160);
        line(430, 110, 480, 110);
        line(480, 110, 480, 160);
        line(430, 340, 480, 340);
        line(480, 340, 480, 270);
        line(250, 340, 300, 340);
        line(250, 340, 250, 270);
        state = 1;
        state2 = 1;
        continue;
      }
      else if (strcmp(u->health_code, "3") == 0)
      {
        for (m = 0; m < 38; m++)
        {
          for (n = 0; n < 38; n++)
          {
            i = rand() % 20;
            if (i < 10)
            {
              setcolor(RED);
              setfillstyle(SOLID_FILL, RED);
              bar(270 + m * 5, 130 + n * 5, 270 + (m + 1) * 5, 130 + (n + 1) * 5);
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, WHITE);
              bar(269, 129, 321, 181);
              bar(269, 269, 321, 321);
              bar(409, 129, 461, 181);
              setcolor(RED);
              setfillstyle(SOLID_FILL, RED);
              bar(270, 130, 320, 180);
              bar(270, 270, 320, 320);
              bar(410, 130, 460, 180);
              setcolor(WHITE);
              setfillstyle(SOLID_FILL, RED);
              bar(280, 140, 310, 170);
              bar(280, 280, 310, 310);
              bar(420, 140, 450, 170);
              setcolor(BLACK);
              setfillstyle(SOLID_FILL, RED);
              bar(290, 150, 300, 160);
              bar(290, 290, 300, 300);
              bar(430, 150, 440, 160);
            }
          }
        }
        setcolor(BROWN);
        line(250, 110, 300, 110);
        line(250, 110, 250, 160);
        line(430, 110, 480, 110);
        line(480, 110, 480, 160);
        line(430, 340, 480, 340);
        line(480, 340, 480, 270);
        line(250, 340, 300, 340);
        line(250, 340, 250, 270);
        up_scan();
        state = 1;
        state2 = 1;
        continue;
      }
      else if (strcmp(u->health_code, "2") == 0)
      {
        for (m = 0; m < 38; m++)
        {
          for (n = 0; n < 38; n++)
          {
            i = rand() % 20;
            if (i < 10)
            {
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(270 + m * 5, 130 + n * 5, 270 + (m + 1) * 5, 130 + (n + 1) * 5);
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, WHITE);
              bar(269, 129, 321, 181);
              bar(269, 269, 321, 321);
              bar(409, 129, 461, 181);
              setcolor(YELLOW);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(270, 130, 320, 180);
              bar(270, 270, 320, 320);
              bar(410, 130, 460, 180);
              setcolor(WHITE);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(280, 140, 310, 170);
              bar(280, 280, 310, 310);
              bar(420, 140, 450, 170);
              setcolor(BLACK);
              setfillstyle(SOLID_FILL, YELLOW);
              bar(290, 150, 300, 160);
              bar(290, 290, 300, 300);
              bar(430, 150, 440, 160);
            }
          }
        }
        setcolor(BROWN);
        line(250, 110, 300, 110);
        line(250, 110, 250, 160);
        line(430, 110, 480, 110);
        line(480, 110, 480, 160);
        line(430, 340, 480, 340);
        line(480, 340, 480, 270);
        line(250, 340, 300, 340);
        line(250, 340, 250, 270);
        up_scan();
        state = 1;
        continue;
      }
      else if (strcmp(u->health_code, "0") == 0)
      {
        puthz(360, 190, "δ�", 32, 18, 8);
        state = 1;
      }
    }

    //���ؼ�
    if (MouseX > 400 && MouseX < 470 && MouseY > 370 && MouseY < 405)
    {
      if (mouse_press(400, 370, 470, 405) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_up(400, 370, 470, 405, 1);
          num = 1;
        }
        continue;
      }
      else if (mouse_press(400, 370, 470, 405) == 1)
      {
        *func = 11;
        return;
      }
    }
    //�ϴ���
    if (MouseX > 280 && MouseX < 370 && MouseY > 370 && MouseY < 405)
    {
      if (mouse_press(280, 370, 350, 405) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_up(280, 370, 350, 405, 2);
          num = 2;
        }
        continue;
      }
      else if (mouse_press(280, 370, 350, 405) == 1)
      {
        if (state2 == 1)
        {
          up_scan();
        }
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
        recover_up(400, 370, 470, 405, 1);
      }
      if (num == 2)
      {
        recover_up(280, 370, 350, 405, 2);
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
FUNCTION: up_scan
DESCRIPTION: ɨ�붯������
INPUT: ��
RETURN: ��
***********************************/
void up_scan(void)
{
  unsigned int size;
  int i, j;
  void *pt_addr;

  clrmous(MouseX, MouseY);

  setlinestyle(0, 0, 4);
  setcolor(RED);
  line(260, 120, 470, 120);

  size = imagesize(260, 120, 470, 120); //����ɨ����ߵ�ͼ��
  //���ر���λͼ��������ֽ���,�ɹ��򷵻�һ������,ʧ���򷵻� FALSE ������һ�� E_WARNING ���Ĵ�����Ϣ��
  if ((pt_addr = malloc(size)) == NULL)
  {
    exit(1);
  }
  getimage(260, 120, 470, 120, pt_addr); //��getimage()����ԭͼ��

  setcolor(WHITE); //����ԭͼ��ʹɨ����̸�������
  line(260, 120, 470, 120);

  for (i = 0; i < 2; i++) //ɨ������
  {
    for (j = 0; j + 120 < 330; j += 2)
    {
      putimage(260, 120 + j, pt_addr, XOR_PUT);
      /*
      int op������:COPY_PUT��OR_PUT��AND_PUT��XOR_PUT��NOT_PUT�ȣ�
      �ֱ���и��ơ����롢��򡢷ǵ����㡣XOR_PUTԭ����Ļÿ����������Ӧ��
      ͼ���ֽ�����������㣬����������Ļ�ϡ���ĳһͼ�����Ļ��ԭ��
      ͼ�������������ʱ����Ļ��ʾ��������ͼ��ĺϳɡ�����ͬ��ͼ����������㣬
      ����Ч�ز�����ͼ������ԭʼ��Ļ�����������ʽ���Զ��������Ƿǳ����õġ�
      */
      delay(25);
      putimage(260, 120 + j, pt_addr, XOR_PUT);
      //��һ��putimage�Ƿ�ӳ���ڶ�����������ͼ������ԭʼ��Ļ��
    }
  }
  free(pt_addr);
}

/***********************************
FUNCTION: lightup_up
DESCRIPTION: �������ϴ���ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_up(int x1, int y1, int x2, int y2, int flag)
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
    puthz(410, 380, "����", 16, 30, 4);
    break;
  }
  case 2:
  {
    puthz(290, 380, "�ϴ�", 16, 30, 4);
    break;
  }

  default:
  {
    printf("something wrong in recover_up\n");
    break;
  }
  }
}

/***********************************
FUNCTION: recover_up
DESCRIPTION: �������ϴ������ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recover_up(int x1, int y1, int x2, int y2, int flag)
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
    puthz(410, 380, "����", 16, 30, 1);
    break;
  }
  case 2:
  {
    puthz(290, 380, "�ϴ�", 16, 30, 1);
    break;
  }

  default:
  {
    printf("something wrong in recover_up\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: up_draw
DESCRIPTION: �ϴ�������������
INPUT: ��
RETURN: ��
***********************************/
void up_draw(void)
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
  puthz(410, 380, "����", 16, 30, 1);
  setcolor(LIGHTCYAN);
  rectangle(400, 370, 470, 405);
  puthz(290, 380, "�ϴ�", 16, 30, 1);
  setcolor(LIGHTCYAN);
  rectangle(280, 370, 350, 405);
}
