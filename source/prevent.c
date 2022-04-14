/***********************************
FILE: userpage.c
DESCRIPTION: �û��������ģ������޸����롢�����л�Ʊ��ѯ��������Ϣ����������״������ʾ�ȹ���
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
DESCRIPTION: �������������
INPUT: *func
RETURN: ��
***********************************/
void prevent_main(int *func, USER *u)
{
  //  int state1 = 0;
  int i, len;
  City c[city_len];

  //����������ؽ���
  prevent_draw();
  //�˳���ť
  exit_buttom();
  //���ʵʱʱ��
  //  get_time(ttemp);

  //�ս���ҳ�����һ�ν���״̬���ж�
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

  //������
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //ʵʱʱ��չʾ
    //  display_time(65, 10, ttemp);

    //��ת����Ʊ��Ϣ����
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

    //��ת���������Ľ���
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

    //��ת����̬��ѯ����
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

    //�˳���
    if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
    {
      if (mouse_press(595, 0, 640, 20) == 1)
      {
        *func = 1;
        return;
      }
    }
    //�и߷��յ�����ѯ��
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

    //�����������
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}
/***********************************
FUNCTION: city_read
DESCRIPTION: �и߷��յ�������
INPUT: ��
RETURN: ��
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
DESCRIPTION:������ؽ��������ǰ�и߷��յ���
INPUT: c
RETURN: ��
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
DESCRIPTION: ������ؽ���
INPUT: ��
RETURN: ��
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
  puthz(65, 20, "�����ݺ�", 32, 35, 4);
  puthz(270, 30, "��Ʊ��Ϣ", 16, 18, 8);
  puthz(360, 30, "��������", 16, 18, 8);
  puthz(450, 30, "�������", 16, 18, 2);
  puthz(540, 30, "��̬��ѯ", 16, 18, 8);
  puthz(595, 5, "�˳�", 16, 18, 1);
  puthz(30, 70, "���з�����ʾ��", 16, 18, 5);
  puthz(30, 160, "�ÿͽ���״̬��", 16, 18, 5);
  puthz(30, 200, "�ÿ͹���������", 16, 18, 5);
  puthz(240, 200, "��ѯ", 16, 18, 1);
  puthz(30, 240, "��ǰ�и߷��յ�����", 16, 18, 5);
  puthz(240, 240, "��ѯ", 16, 18, 1);
}

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