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
#include "time.h"
#define city_len 12
#define tips_len 10

/***********************************
FUNCTION: prevent_main
DESCRIPTION: �������������
INPUT: *func
RETURN: ��
***********************************/
void prevent_main(int *func, USER *u)
{
  StaticLinkList list[tips_len];
  City c[city_len];
  int key;
  int i = 0;
  int num = 0;
  int flag = 0;
  int state_city = 0; //������¼�и߷��յ���չ��״��
  int state = 0;      //����¼���﷭ҳ״̬
  int hour1, min1;
  int second1, second_all_1;
  int second_all_2 = 0;
  char ttemp[40] = "\0";

  //��ʼ���뺯����ʱ��
  get_h_min_second(&hour1, &min1, &second1);
  second_all_1 = (60 * hour1 + min1) * 60 + second1;
  InitList(list);
  getinfo_List(list);
  //����������ؽ���
  prevent_draw();
  //�˳���ť
  exit_buttom();
  //��ӡ���߱���
  printtips(list);
  //���ʱ�� ��displayһ��ĺ���
  get_time(ttemp);

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
    //����ʱ��
    display_time(65, 10, ttemp);
    //����ʱ��Ա�����й�������
    get_h_min_second(&hour1, &min1, &second1);
    second_all_2 = (60 * hour1 + min1) * 60 + second1;
    if (second_all_2 == second_all_1 + 15)
    {
      tips_cover();
      List_next(&flag, list);
      puthz(100, 110, list[flag].data, 16, 18, 6);
      second_all_1 = second_all_2;
    }
    //�������Ʊ��﷭ҳ
    if (kbhit())
    {
      key = bioskey(0);
      if (key == Key_Down)
      {
        tips_cover();
        List_next(&flag, list);
        puthz(100, 110, list[flag].data, 16, 18, 6);
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
    if (MouseX > 540 && MouseX < 620 && MouseY > 25 && MouseY < 60)
    {
      if (mouse_press(540, 25, 620, 60) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(540, 25, 620, 60) == 1)
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
        if (num == 0)
        {
          lightup_prevent(230, 242, 280, 254, 4);
          num = 4;
        }

        continue;
      }
      else if (mouse_press(230, 230, 270, 260) == 1)
      {
        if (state_city == 0) //��ʾδչ��
        {
          city_read(c);
          get_cityinfo(c);
          delay(100);
        }
        if (state_city == 1) //��ʾ��չ��
        {
          setfillstyle(SOLID_FILL, WHITE);
          bar(465, 147, 640, 480);
          delay(100);
        }
        if (state_city == 0)
        {
          state_city = 1;
        }
        else if (state_city == 1)
        {
          state_city = 0;
        }

        continue;
      }
    }

    //�ÿ͹���������ѯ��
    if (MouseX > 230 && MouseX < 270 && MouseY > 190 && MouseY < 220)
    {
      if (mouse_press(230, 190, 270, 220) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_prevent(230, 202, 280, 214, 3);
          num = 3;
        }
        continue;
      }
      else if (mouse_press(230, 190, 270, 220) == 1)
      {
        *func = 27;
        return;
      }
    }

    //�ÿͺ������
    if (MouseX > 230 && MouseX < 270 && MouseY > 270 && MouseY < 300)
    {
      if (mouse_press(230, 270, 270, 300) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_prevent(230, 282, 280, 294, 5);
          num = 5;
        }
        continue;
      }
      else if (mouse_press(230, 270, 270, 300) == 1)
      {
        *func = 26;
        return;
      }
    }

    //��һ��
    if (MouseX > 530 && MouseX < 600 && MouseY > 115 && MouseY < 145)
    {
      if (mouse_press(530, 115, 600, 145) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_prevent(530, 110, 600, 140, 1);
          num = 1;
        }
        if (state != 0)
        {
          if (state == 1)
          {
            state = 0;
          }
        }
        continue;
      }
      else if (mouse_press(530, 115, 600, 145) == 1)
      {
        if (state == 0)
        {
          tips_cover();
          List_next(&flag, list);
          puthz(100, 110, list[flag].data, 16, 18, 6);
          state = 1;
        }
        delay(100);
        continue;
      }
    }

    //����Աģʽ     rectangle(320, 230, 430, 265);
    if (MouseX > 320 && MouseX < 430 && MouseY > 230 && MouseY < 265)
    {
      if (mouse_press(320, 230, 430, 265) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_prevent(320, 230, 430, 265, 2);
          num = 2;
        }
        continue;
      }
      else if (mouse_press(320, 230, 430, 265) == 1)
      {
        *func = 28;
        return;
      }
    }

    //��ť�ָ�����
    if (num != 0)
    {
      if (num == 1)
      {
        recover_prevent(530, 110, 600, 140, 1);
      }
      if (num == 2)
      {
        recover_prevent(320, 230, 430, 265, 2);
      }
      if (num == 3)
      {
        recover_prevent(230, 192, 290, 225, 3);
      }
      if (num == 4)
      {
        recover_prevent(230, 232, 290, 265, 4);
      }
      if (num == 5)
      {
        recover_prevent(230, 272, 290, 305, 5);
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
  memset(c, '\0', city_len * sizeof(City));

  if ((fp = fopen("database\\city.dat", "rb+")) == NULL)
  {
    printf("cannot open file city\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_SET);
  while (!feof(fp) || i < city_len) //������ϵ��ļ�������������ļ��������򷵻ط�0ֵ�����򷵻�0
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
/*
void city_read(City *c)
{
  FILE *fp;
  City ctem;
  int i = 0;
  memset(c, '\0', city_len * sizeof(City));
  if ((fp = fopen("database\\city.dat", "rb+")) == NULL)
  {
    printf("cannot open file city\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_SET);
  for (i = 0; i < city_len; i++) 
  {
    memset(&ctem, '\0', sizeof(City));
    fseek(fp, i * sizeof(City), SEEK_SET);
    fread(&ctem, sizeof(City), 1, fp);
    strcpy(c[i].city_name, ctem.city_name);
    strcpy(c[i].level, ctem.level);
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close city");
    delay(2000);
    exit(1);
  }
}  
*/

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
FUNCTION: lightup_prevent
DESCRIPTION: ������ؽ��水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_prevent(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setfillstyle(1, LIGHTGRAY);
  bar(x1, y1, x2, y2);
  switch (flag)
  {
  case 1:
  {
    setcolor(RED);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    puthz(540, 118, "��һ��", 16, 18, 4);
    break;
  }

  case 2:
  {
    setcolor(RED);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    puthz(330, 240, "����Աģʽ", 16, 18, 4);
    break;
  }
  case 3:
  {
    puthz(240, 200, "��ѯ", 16, 18, 1); //�ÿ͹���������ѯ
    break;
  }
  case 4:
  {
    puthz(240, 240, "��ѯ", 16, 18, 1); //��ǰ�и߷��յ�����ѯ
    break;
  }
  case 5:
  {
    puthz(240, 280, "�", 16, 18, 1); //�ÿͺ�����Ϣ�
    break;
  }
  default:
  {
    printf("something wrong in lightup_prevent\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: recover_prevent
DESCRIPTION: ������ؽ�������ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recover_prevent(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setfillstyle(SOLID_FILL, WHITE);
  bar(x1, y1, x2, y2);
  switch (flag)
  {
  case 1:
  {
    setcolor(BROWN);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    puthz(540, 118, "��һ��", 16, 18, 1);
    break;
  }
  case 2:
  {
    setcolor(BROWN);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    puthz(330, 240, "����Աģʽ", 16, 18, 1);
    break;
  }
  case 3:
  {
    puthz(240, 200, "��ѯ", 16, 18, 1); //�ÿ͹���������ѯ
    break;
  }
  case 4:
  {
    puthz(240, 240, "��ѯ", 16, 18, 1); //��ǰ�и߷��յ�����ѯ
    break;
  }
  case 5:
  {
    puthz(240, 280, "�", 16, 18, 1); //�ÿͺ�����Ϣ�
    break;
  }
  default:
  {
    printf("something wrong in recover_prevent\n");
    closegraph();
    exit(1);
  }
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
  line(0, 145, 640, 145);
  line(460, 145, 460, 640);
  setfillstyle(SOLID_FILL, GREEN);
  bar(0, 0, 60, 60);
  puthz(65, 20, "�����ݺ�", 32, 35, 4);
  puthz(270, 30, "��Ʊ��Ϣ", 16, 18, 8);
  puthz(360, 30, "��������", 16, 18, 8);
  puthz(450, 30, "�������", 16, 18, 2);
  puthz(540, 30, "��̬��ѯ", 16, 18, 8);
  puthz(30, 70, "���з�����ʾ��", 16, 18, 5);
  puthz(30, 160, "�ÿͽ���״̬��", 16, 18, 5);
  puthz(30, 200, "�ÿ͹���������", 16, 18, 5);
  puthz(240, 200, "��ѯ", 16, 18, 1);
  puthz(30, 240, "��ǰ�и߷��յ�����", 16, 18, 5);
  puthz(240, 240, "��ѯ", 16, 18, 1);
  puthz(30, 280, "�ÿͺ�������", 16, 18, 5);
  puthz(240, 280, "�", 16, 18, 1);
  puthz(540, 118, "��һ��", 16, 18, 1);
  setcolor(BROWN);
  rectangle(530, 110, 600, 140);
  puthz(330, 240, "����Աģʽ", 16, 18, 1);
  rectangle(320, 230, 430, 265);
  setcolor(DARKGRAY);
  rectangle(60, 375, 330, 470);
  rectangle(65, 370, 335, 465);
  puthz(85, 410, "�����ڼ䣬��ע�������", 16, 18, 6);
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

//������ʾ ��̬����
/***********************************
FUNCTION: InitList
DESCRIPTION: ��ʼ������,�趨�α�
INPUT: StaticLinkList space
RETURN: ��
***********************************/
void InitList(StaticLinkList *space)
{
  int i = 0;
  while (i < tips_len - 1)
  {
    space[i].cur = i + 1;
    i++;
  }
  space[tips_len - 1].cur = 0;
}

/***********************************
FUNCTION: List_next
DESCRIPTION: ����������α�
INPUT: StaticLinkList space   flag
RETURN: ��
***********************************/
void List_next(int *flag, StaticLinkList *space)
{
  int temp = *flag;
  *flag = space[temp].cur;
}

/***********************************
FUNCTION: getinfo_List
DESCRIPTION: ���л������
INPUT:
RETURN: ��
***********************************/
void getinfo_List(StaticLinkList *space)
{
  FILE *fp;
  char tiptemp[30];
  int i = 0;
  int j = 0;
  for (i = 0; i < tips_len; i++)
  {
    memset(space[i].data, '\0', sizeof(space[i].data));
  }
  if ((fp = fopen("database\\tips.dat", "rb+")) == NULL)
  {
    printf("cannot open file tips.dat\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_SET);
  //������ϵ��ļ�������������ļ��������򷵻ط�0ֵ�����򷵻�0
  while (!feof(fp) || j < tips_len)
  {
    memset(&tiptemp, '\0', sizeof(tiptemp));
    fscanf(fp, "%s\n", tiptemp);
    strcpy(space[j].data, tiptemp);
    j++;
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close tipstemp");
    delay(2000);
    exit(1);
  }
}

/***********************************
FUNCTION: printtips
DESCRIPTION: ��ӡ���߱���
INPUT:StaticLinkList *space
RETURN: ��
***********************************/
void printtips(StaticLinkList *space)
{
  puthz(100, 110, space[0].data, 16, 18, 6);
}

/***********************************
FUNCTION: tips_cover
DESCRIPTION: �ڸǷ��߱���
INPUT: ��
RETURN: ��
***********************************/
void tips_cover(void)
{
  setfillstyle(SOLID_FILL, WHITE);
  bar(70, 90, 350, 140);
}

/***********************************
FUNCTION: get_h_min_second
DESCRIPTION: ��ȡʵʱСʱ�ͷ���
INPUT: *h  *min  *sec
RETURN: ��
***********************************/
void get_h_min_second(int *h, int *min, int *sec)
{
  time_t lt;
  struct tm *ptr;
  char hour[3], minute[3], second[3];
  char first; //,second;

  memset(hour, '\0', sizeof(hour));
  memset(minute, '\0', sizeof(minute));
  memset(second, '\0', sizeof(second));

  lt = time(NULL);
  ptr = localtime(&lt); //��ȡ����ʱ��

  strftime(hour, 3, "%H", ptr);
  strftime(minute, 3, "%M", ptr);
  strftime(second, 3, "%S", ptr);

  if (hour[0] == '0')
  {
    first = hour[1];
    hour[0] = first;
    hour[1] = '\0';
  }
  if (minute[0] == '0')
  {
    first = minute[1];
    minute[0] = first;
    minute[1] = '\0';
  }
  if (second[0] == '0')
  {
    first = second[1];
    second[0] = first;
    second[1] = '\0';
  }

  *h = atoi(hour);
  *min = (atoi(minute));
  *sec = (atoi(second));
}