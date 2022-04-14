/***********************************
FILE: reserve.c
DESCRIPTION: �û��������Ķ����Ƶ깦��ʵ��
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
DESCRIPTION: �Ƶ궩������������
INPUT: *func
RETURN: ��
***********************************/
void hotlereserve_main(int *func, Hotle *booked)
{
  int num = 0; //������¼"�ÿͽ������ϴ�"��ť����״̬
  int city_flag = 0;
  int city_num = 0;
  int line = 1;
  int state1 = 0;
  int state = 0;
  int laucity = 0;
  Hotle h[hotle_len];
  char *city[] = {
      "����", "�Ϻ�", "����", "�ɶ�",
      "����", "����", "����", "����",
      "����", "�Ͼ�", "�人", "���"};

  memset(booked, '\0', sizeof(Hotle));
  //���ֶ����Ƶ����
  reserve_draw();
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //����ѡ��
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
        if (state == 0) // state������¼�����б��չ��״̬���������б�δչ��
        {
          city_page(80, 144);
          state = 1;
          delay(100); // delay���� 1000Ϊ1s
        }
        else if (state == 1) //�������б���չ��
        {
          city_cover(80, 144);
          state = 0;
          delay(100);
        }
      }
    }

    if (state == 1) //�ڳ����б�չ����״̬�½���ѡ����в���
    {
      if (MouseX > 80 && MouseX < 80 + 300 && MouseY > 144 && MouseY < 144 + 140)
      {
        //����
        if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 0, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 0, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 1; //����1
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }

        //�Ϻ�
        if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 0, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 0, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 2; //����2
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //����
        if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 0, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 0, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 3; //����3
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //�ɶ�
        if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 0, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 0 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 0, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 0 + 20) == 1)
        {
          laucity = 4; //����4
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //����
        if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 1, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 1, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 5; //����5
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //����
        if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 1, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 1, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 6; //����6
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //����
        if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 1, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 1, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 7; //����7
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //����
        if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 1, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 1 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 1, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 1 + 20) == 1)
        {
          laucity = 8; //����8
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //����
        if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 2, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 0, 144 + 20 + 40 * 2, 80 + 20 + 70 * 0 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 9; //����9
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //�Ͼ�
        if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 2, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 1, 144 + 20 + 40 * 2, 80 + 20 + 70 * 1 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 10; //����10
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //�人
        if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 2, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 2, 144 + 20 + 40 * 2, 80 + 20 + 70 * 2 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 11; //����11
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
        //���
        if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 2, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 2 + 20) == 2)
        {
          MouseS = 1;
          continue;
        }
        else if (mouse_press(80 + 20 + 70 * 3, 144 + 20 + 40 * 2, 80 + 20 + 70 * 3 + 50, 144 + 20 + 40 * 2 + 20) == 1)
        {
          laucity = 12; //����12
          state = 0;
          city_cover(80, 144);
          puthz(90, 115, city[laucity - 1], 16, 18, 8);
          hotle_cover();
        }
      }
    }

    //��ѯ�Ƶ�
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
        case 1: //����
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
        case 2: //�Ϻ�
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
        case 3: //����
        {
          hotle_cover();
          hotle_display(h, 9, 1);
          hotle_display(h, 10, 2);
          city_flag = 3;
          city_num = 8;
          break;
        }
        case 4: //�ɶ�
        {
          hotle_cover();
          hotle_display(h, 11, 1);
          city_flag = 2;
          city_num = 10;
          break;
        }
        case 5: //����
        {
          hotle_cover();
          hotle_display(h, 12, 1);
          city_flag = 2;
          city_num = 11;
          break;
        }
        case 6: //����
        {
          hotle_cover();
          hotle_display(h, 13, 1);
          city_flag = 2;
          city_num = 12;
          break;
        }
        case 7: //����
        {
          hotle_cover();
          hotle_display(h, 14, 1);
          city_flag = 2;
          city_num = 13;
          break;
        }
        case 8: //����
        {
          hotle_cover();
          hotle_display(h, 15, 1);
          city_flag = 2;
          city_num = 14;
          break;
        }
        case 9: //����
        {
          hotle_cover();
          hotle_display(h, 16, 1);
          city_flag = 2;
          city_num = 15;
          break;
        }
        case 10: //�Ͼ�
        {
          hotle_cover();
          hotle_display(h, 17, 1);
          city_flag = 2;
          city_num = 16;
          break;
        }
        case 11: //�人
        {
          hotle_cover();
          hotle_display(h, 18, 1);
          hotle_display(h, 19, 2);
          city_flag = 3;
          city_num = 17;
          break;
        }
        case 12: //���
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
    //��ת��������ؽ���
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

    //��ת����̬��ѯ����

    //���ظ������Ľ���
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

    //�ÿͽ������ϴ�
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

    if (state1 != 0)
    {
      if (state1 == 1)
      {
        city_lightup_recover(80, 110, 240, 140);
      }
      state1 = 0;
    }

    //"�ÿͽ������ϴ�"��ť�ָ�����
    if (num != 0)
    {
      if (num == 1)
      {
        recover_reserve(470,70,610,110,1);
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
FUNCTION: city_page
DESCRIPTION: ����ѡ��˵�����
INPUT: x,y
RETURN: ��
***********************************/
void city_page(int x, int y)
{
  int i, j;
  char *city[] = {
      "����", "�Ϻ�", "����", "�ɶ�",
      "����", "����", "����", "����",
      "����", "�Ͼ�", "�人", "���"};

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
DESCRIPTION: ����ٴε��������б�����
INPUT: x,y
RETURN: ��
***********************************/
void city_cover(int x, int y)
{
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x - 2, y - 2, x + 300 + 2, y + 140 + 2);
  line(0, 160, 640, 160);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(0, 160, 640, 200);
  puthz(60, 170, "����", 16, 18, 9);
  puthz(150, 170, "�Ƶ�����", 16, 18, 9);
  puthz(270, 170, "��������", 16, 18, 9);
  puthz(390, 170, "�Ƶ�۸�", 16, 18, 9);
}

/***********************************
FUNCTION: hotle_display
DESCRIPTION: �����ѯ��Ƶ��б���ʾ
INPUT: x,y
RETURN: ��
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
  puthz(510, 190 + 30 * line, "����", 16, 18, 1);
}

/***********************************
FUNCTION: hotle_cover
DESCRIPTION: �����ѯ��Ƶ��б�Ӱ��
INPUT: ��
RETURN: ��
***********************************/
void hotle_cover(void)
{
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 205, 640, 480);
}

/***********************************
FUNCTION: hotlecity_read
DESCRIPTION: �Ƶ���Ϣ����
INPUT: ��
RETURN: ��
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
DESCRIPTION: �Ƶ궩�����水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_reserve(int x1, int y1, int x2, int y2, int flag)
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
    puthz(480, 80, "�ÿͽ������ϴ�", 16, 18, 4);
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
DESCRIPTION: �Ƶ궩�����水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
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
    puthz(480, 80, "�ÿͽ������ϴ�", 16, 18, 1);
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
DESCRIPTION: ����ѡ������
INPUT: x1,x2,y1,y2
RETURN: ��
***********************************/
void city_lightup(int x1, int y1, int x2, int y2)
{
  clrmous(MouseX, MouseY);
  setcolor(GREEN);
  rectangle(x1, y1, x2, y2);
}

/***********************************
FUNCTION: city_lightup_recover
DESCRIPTION: ����ѡ�������ָ�
INPUT: x1,x2,y1,y2
RETURN: ��
***********************************/
void city_lightup_recover(int x1, int y1, int x2, int y2)
{
  clrmous(MouseX, MouseY);
  setcolor(DARKGRAY);
  rectangle(x1, y1, x2, y2);
}

/***********************************
FUNCTION: reserve_draw
DESCRIPTION: �����Ƶ����
INPUT: ��
RETURN: ��
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
  puthz(600, 2, "�˳�", 16, 18, RED);
  puthz(65, 20, "�����ݺ�", 32, 35, 4);
  puthz(270, 30, "��Ʊ��Ϣ", 16, 18, 8);
  puthz(360, 30, "��������", 16, 18, 2);
  puthz(450, 30, "�������", 16, 18, 8);
  puthz(540, 30, "��̬��ѯ", 16, 18, 8);
  puthz(80, 80, "��ѡ����У�", 16, 18, 5);
  puthz(90, 115, "����", 16, 18, 7);
  puthz(340, 115, "��ѯ", 16, 18, 1);
  puthz(480, 80, "�ÿͽ������ϴ�", 16, 18, 1);
  setcolor(BROWN);
  rectangle(470,70,610,110);
  puthz(60, 170, "����", 16, 18, 9);
  puthz(150, 170, "�Ƶ�����", 16, 18, 9);
  puthz(270, 170, "��������", 16, 18, 9);
  puthz(390, 170, "�Ƶ�۸�", 16, 18, 9);
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