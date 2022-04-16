/***********************************
FILE: payment.c
DESCRIPTION: �Ƶ�֧������
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

/***********************************
FUNCTION: payment_main
DESCRIPTION: �Ƶ�֧��������
INPUT: *func,
RETURN: ��
***********************************/
void payment_main(int *func, USER *u, Live *L)
{
  int state1 = 0;
  int num = 0;         //�����
  int num2 = 0;        //��ť
  int flag = 1;        //�����ж����п������Ƿ���ȷ
  int flag_finish = 0; //�����ж��Ƿ��Ѿ���ɸ���  1��ʾ�Ѿ����
  char bankpassword[10];
  int single_price = 0;
  int livingday = 0;
  int total_price = 0;
  char totalpay[2];
  payment_draw();
  exit_buttom();
  payment_info(u, L);
  memset(totalpay, '\0', sizeof(totalpay));

  single_price = atoi(L->price);
  livingday = atoi(L->day); //�ַ���ת��Ϊ����
  total_price = single_price * livingday;
  itoa(total_price, totalpay, 10); //����ת��Ϊ�ַ���
  setcolor(DARKGRAY);
  outtextxy(230, 225, totalpay);

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
    //ɨ��֧��
    if (MouseX > 215 && MouseX < 280 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(215, 80, 280, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(215, 80, 280, 110) == 1)
      {
        *func = 19;
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

    //�������п�����
    if (MouseX > 200 && MouseX < 380 && MouseY > 265 && MouseY < 295)
    {
      if (mouse_press(200, 265, 380, 295) == 2)
      {
        MouseS = 1;
        if (num == 0 && state1 == 0)
        {
          lightup_payment(200, 265, 380, 295, 1);
          num = 1;
        }
        continue;
      }
      else if (mouse_press(200, 265, 380, 295) == 1)
      {
        lightup_payment(200, 265, 380, 295, 1);
        memset(bankpassword, '\0', sizeof(bankpassword)); //ȷ���������
        inputbankpassword(bankpassword, 200, 265, 7, LIGHTGRAY); //�������п�����
        flag = strcmp(bankpassword, u->bankpassword);
        if (strlen(bankpassword) == 0)
        {
          state1 = 0;
        }
        else
        {
          state1 = 1;
        }
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

    //ȷ������
    if (MouseX > 190 && MouseX < 280 && MouseY > 340 && MouseY < 375)
    {
      if (mouse_press(190, 340, 280, 375) == 2)
      {
        MouseS = 1;
        if (num2 == 0)
        {
          lightup_booked(190, 340, 280, 375, 3);
          num2 = 1;
        }
        continue;
      }
      if (mouse_press(190, 340, 280, 375) == 1)
      {
        
        delay(800);
        if (flag != 0)
        {
          setfillstyle(SOLID_FILL, WHITE);
          bar(320, 340, 640, 380);
          bar(390, 260, 640, 300);
          puthz(430, 270, "��������δ����", 16, 18, 6);
        }
        else if (flag == 0)
        {
          if (flag_finish == 0)
          {
            inputlive_database(u, L);
            setfillstyle(SOLID_FILL, WHITE);
            bar(320, 340, 640, 380);
            bar(390, 260, 640, 300);
            puthz(430, 270, "������ȷ", 16, 18, 6);
            puthz(430, 350, "֧�����", 16, 18, 6);
            flag_finish = 1;
            delay(2000);
            *func = 11;
            return;
          }
          else if (flag_finish == 1)
          {
            setfillstyle(SOLID_FILL, WHITE);
            bar(320, 340, 640, 380);
            bar(390, 260, 640, 300);
            puthz(430, 350, "�����ظ�����", 16, 18, 6);
          }
        }
        continue;
      }
    }

    //�����ָ�����
    if (num != 0)
    {
      MouseS = 0;
      if (state1 == 0 && num == 1)
      {
        recover_payment(200, 265, 380, 295, 1);
      }
      num = 0;
    }

    //��ť�ָ�����
    if (num2 != 0)
    {
      if (num2 == 1)
      {
        recover_booked(190, 340, 280, 375, 3);
      }
      num2 = 0;
    }

    //�����������
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}

/***********************************
FUNCTION: inputadmin_database
DESCRIPTION: ���Ѷ����Ƶ���Ϣд�����ݿ�
INPUT:
RETURN: ��
***********************************/
void inputlive_database(USER *u, Live *L)
{
  FILE *fp;
  char file_live[30] = "\0";
  strcpy(file_live, "database\\");
  strcat(file_live, u->name);
  strcat(file_live, "\\live.dat");
  if ((fp = fopen(file_live, "rb+")) == NULL)
  {
    printf("%s open failed\n", file_live);
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  fwrite(L, sizeof(Live), 1, fp); //д���Ʊ��Ϣ
  if (fclose(fp) != 0)
  {
    printf("%s close failed\n", file_live);
    delay(3000);
    exit(1);
  }
}

/***********************************
FUNCTION: payment_info
DESCRIPTION: �Ƶ�֧������֧����Ϣ
INPUT: ��
RETURN: ��
***********************************/
void payment_info(USER *u, Live *L)
{
  settextjustify(LEFT_TEXT, TOP_TEXT); //�����ı����뷽ʽ
  settextstyle(2, 0, 7);
  setcolor(DARKGRAY);
  outtextxy(165, 147, u->name);
  outtextxy(165, 187, u->bank);
}

/***********************************
FUNCTION: lightup_payment
DESCRIPTION: �Ƶ�֧��������������
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_payment(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setcolor(RED);
  setfillstyle(1, LIGHTGRAY);
  bar(x1, y1, x2, y2);                       //����ڲ�
  rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //���߿�
  switch (flag)
  {
  case 1:
  {
    break;
  }
  default:
  {
    printf("something wrong in recover_payment\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: recover_payment
DESCRIPTION: �Ƶ�֧�����水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recover_payment(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setcolor(DARKGRAY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x1, y1, x2, y2);
  rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
  switch (flag)
  {
  case 1:
  {
    break;
  }
  default:
  {
    printf("something wrong in recover_payment\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: inputbankpassword
DESCRIPTION: ����ʾ���п���������빦��
INPUT: *id ��Ҫ������ַ�����x��y��charnum ���������ַ���
RETURN: ��
***********************************/
void inputbankpassword(char *id, int x1, int y1, int charnum, int color)
{
  int k = 0;
  int i = 0;
  char t;
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, color);
  setlinestyle(SOLID_LINE, 0, NORM_WIDTH); //NOR_WIDTH �� THICK_WIDTH
  setcolor(WHITE);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
  settextjustify(LEFT_TEXT, TOP_TEXT);
  line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
  while (bioskey(1)) //ֱ��ʹ��BIOS����ļ��̽ӿ�
  {
    k = bioskey(0);
    // bioskey(1)����Ƿ��м�����,û�м�����ʱ����0,�м�����ʱ���ذ�����(�κΰ����붼��Ϊ0),����ʱ��������⵽�İ�����Ӽ��̻�����������.
    // bioskey(0)���ؼ��̻�������еİ����룬�����˰�����Ӽ��̻�����������.
  }
  while (1)
  {
    t = bioskey(0);
    if (i < charnum)
    {
      if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
      {
        if (t != '\b') //  \b��ʾ�˸�
        {
          *(id + i) = t; //�����ַ���id
          *(id + i + 1) = '\0';
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
          outtextxy(x1 + 8 + i * 18, y1 + 2, "*");                 //���*�ַ�(16)
          i++;
          line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
        }
        else if (t == '\b' && i > 0) //�˸��
        {
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //�ڸǹ��
          bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //�ڸ�����
          i--;                                                       //����һ������
          line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //���ƹ��
          *(id + i) = '\0';
          *(id + i + 1) = '\0';
        }
        else
        {
          setfillstyle(SOLID_FILL, color);
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
          break;
        }
      }
      else
      {
        setfillstyle(SOLID_FILL, color);
        bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
        break;
      }
    }
    else if (i >= charnum)
    {
      if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
      {
        if (t == '\b' && i > 0) //�˸��
        {
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //�ڸǹ��
          bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //�ڸ�����
          i--;                                                       //����һ������
          line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //���ƹ��
          *(id + i) = '\0';
        }
      }
      else
      {
        setfillstyle(SOLID_FILL, color);
        bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
        break;
      }
    }
  }
}

/***********************************
FUNCTION: payment_draw
DESCRIPTION: �Ƶ�֧����ͼ
INPUT: ��
RETURN: ��
***********************************/
void payment_draw(void)
{
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
  puthz(80, 150, "�û�������", 16, 18, 5);
  puthz(80, 190, "���п��ţ�", 16, 18, 5);
  puthz(80, 230, "��Ҫ֧���Ľ�", 16, 18, 5);
  puthz(80, 270, "���������룺", 16, 18, 5);
  puthz(200, 350, "ȷ������", 16, 18, 1);
  setcolor(LIGHTCYAN);
  rectangle(190, 340, 280, 375);
  setcolor(DARKGRAY);
  rectangle(200, 265, 380, 295);
}
