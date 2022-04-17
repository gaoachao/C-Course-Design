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
#include "history.h"

/***********************************
FUNCTION: history_main
DESCRIPTION: ��ѯ�Ѷ����Ƶ���Ϣ
INPUT: ��
RETURN: ��
***********************************/
void history_main(int *func, USER *u)
{
  int key;
  int num = 0;
  int len, page_num, page_rest;
  int prepage = 0;
  HNode node;            //��Ʊ�ڵ�
  Hold h_list[List_len]; //��Ʊ��Ϣ����
  memset(h_list,'\0',sizeof(Hold)*List_len);
  history_draw();
  exit_buttom();
  InitQueue(&node); // hold���г�ʼ��

  len = holdinfo_read(u, h_list); //�������ʷ�����Ʊ��Ŀ
  page_count(&page_num, &page_rest, len);
  enqueue_history(&node, h_list, prepage);
  hold_display(&node, 1, page_rest,page_num);

  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
    //�������Ʒ�ҳ
    if (kbhit())
    {
      key = bioskey(0);
      if (key == Key_Down)
      {
        if (strlen(h_list[0].number) != 0)
        {
          hold_cover();                   // queue_down/up  ԭ����queue.c��
          queue_down(&prepage, page_num); // prepage = 0 ��һҳ  �� prepage = 1 �ڶ�ҳ
          enqueue_history(&node, h_list, prepage);
          if (prepage + 1 < page_num)
          {
            hold_display(&node, 1, page_rest,page_num);
            delay(100);
          }
          else if (prepage + 1 == page_num)
          {
            hold_display(&node, 2, page_rest,page_num);
            delay(100);
          }
        }
      }
      if (key == Key_Up)
      {
        if (strlen(h_list[0].number) != 0)
        {
          hold_cover();
          queue_up(&prepage, page_num);
          enqueue_history(&node, h_list, prepage);
          if (prepage + 1 < page_num)
          {
            hold_display(&node, 1, page_rest,page_num);
            delay(100);
          }
          else if (prepage + 1 == page_num)
          {
            hold_display(&node, 2, page_rest,page_num);
            delay(100);
          }
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

    //����ǰҳ��
    if (MouseX > 280 && MouseX < 400 && MouseY > 370 && MouseY < 435)
    {
      if (mouse_press(280, 400, 370, 435) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_history(280, 400, 370, 435, 1);
          num = 1;
        }
        continue;
      }
      if (mouse_press(280, 400, 370, 435) == 1)
      {
        *func = 5;
        return;
      }
    }

    //��һҳ��
    if (MouseX > 100 && MouseX < 180 && MouseY > 400 && MouseY < 435)
    {
      if (mouse_press(100, 400, 180, 435) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_history(100, 400, 180, 435, 2);
          num = 2;
        }
        continue;
      }
      if (mouse_press(100, 400, 180, 435) == 1)
      {
        if (strlen(h_list[0].number) != 0)
        {
          hold_cover();
          queue_down(&prepage, page_num);
          enqueue_history(&node, h_list, prepage);
          if (prepage + 1 < page_num)
          {
            hold_display(&node, 1, page_rest,page_num);
            delay(100);
          }
          else if (prepage + 1 == page_num)
          {
            hold_display(&node, 2, page_rest,page_num);
            delay(100);
          }
        }
        continue;
      }
    }

    //��һҳ��
    if (MouseX > 460 && MouseX < 540 && MouseY > 370 && MouseY < 435)
    {
      if (mouse_press(460, 400, 540, 435) == 2)
      {
        MouseS = 1;
        if (num == 0)
        {
          lightup_history(460, 400, 540, 435, 3);
          num = 3;
        }
        continue;
      }
      if (mouse_press(460, 400, 540, 435) == 1)
      {
        if (strlen(h_list[0].number) != 0)
        {
          hold_cover();
          queue_up(&prepage, page_num);
          enqueue_history(&node, h_list, prepage);
          if (prepage + 1 < page_num)
          {
            hold_display(&node, 1, page_rest,page_num);
            delay(100);
          }
          else if (prepage + 1 == page_num)
          {
            hold_display(&node, 2, page_rest,page_num);
            delay(100);
          }
        }
        continue;
      }
    }
    //�ָ�����
    if (num != 0)
    {
      if (num == 1)
      {
        recover_history(280, 400, 370, 435, 1);
      }
      if (num == 2)
      {
        recover_history(100, 400, 180, 435, 2);
      }
      if (num == 3)
      {
        recover_history(460, 400, 540, 435, 3);
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
FUNCTION: lightup_history
DESCRIPTION: ��ʷ��Ʊ���水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_history(int x1, int y1, int x2, int y2, int flag)
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
    puthz(290, 410, "����ǰҳ", 16, 18, 4);
    break;
  }
  case 2:
  {
    puthz(110, 410, "��һҳ", 16, 18, 4);
    break;
  }
  case 3:
  {
    puthz(470, 410, "��һҳ", 16, 18, 4);
    break;
  }
  default:
  {
    printf("something wrong in recover_history\n");
    break;
  }
  }
}

/***********************************
FUNCTION: recover_history
DESCRIPTION: ��ʷ��Ʊ���水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recover_history(int x1, int y1, int x2, int y2, int flag)
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
    puthz(290, 410, "����ǰҳ", 16, 18, 5);
    break;
  }
  case 2:
  {
    puthz(110, 410, "��һҳ", 16, 18, 5);
    break;
  }
  case 3:
  {
    puthz(470, 410, "��һҳ", 16, 18, 5);
    break;
  }
  default:
  {
    printf("something wrong in recover_history\n");
    closegraph();
    exit(1);
  }
  }
}

/***********************************
FUNCTION: histroy_draw
DESCRIPTION: ��Ʊ��¼�������
INPUT: ��
RETURN: ��
***********************************/
void history_draw(void)
{
  clrmous(MouseX, MouseY);
  delay(30);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(0, 90, 640, 130);
  puthz(55, 30, "��ʷ��Ʊ", 32, 35, 4);
  puthz(56, 31, "��ʷ��Ʊ", 32, 35, 4);
  puthz(290, 410, "����ǰҳ", 16, 18, 5);
  puthz(110, 410, "��һҳ", 16, 18, 5);
  puthz(470, 410, "��һҳ", 16, 18, 5);
  setcolor(LIGHTCYAN);
  rectangle(280, 400, 370, 435);
  rectangle(100, 400, 180, 435);
  rectangle(460, 400, 540, 435);
  puthz(30, 100, "����", 16, 18, 9);
  puthz(100, 100, "������", 16, 18, 9);
  puthz(205, 100, "���չ�˾", 16, 18, 9);
  puthz(290, 100, "��ɵ�", 16, 18, 9);
  puthz(350, 100, "�����", 16, 18, 9);
  puthz(415, 100, "��Ʊ��", 16, 18, 9);
  puthz(488, 100, "��Ʊ����", 16, 18, 9);
  puthz(575, 100, "��Ŀ", 16, 18, 9);
  setcolor(DARKGRAY);
  line(0, 173, 640, 173);
  line(0, 203, 640, 203);
  line(0, 233, 640, 233);
  line(0, 263, 640, 263);
  line(0, 293, 640, 293);
  line(0, 323, 640, 323);
  line(0, 353, 640, 353);
  line(0, 383, 640, 383);
}

/***********************************
FUNCTION: page_count
DESCRIPTION: ����һ����ҳ�Լ����һҳ�м�����Ϣ
INPUT: *page_num��*page_rest,len,*state
RETURN: ��
***********************************/
void page_count(int *page_num, int *page_rest, int len)
{
  int i;
  if (len == 0)
  {
    *page_num = 0;
    *page_rest = 0;
    return;
  }
  *page_rest = len % MaxSize;
  *page_num = len / MaxSize;
  if (*page_rest == 0)
  {
    *page_rest = MaxSize;
  }
  else
  {
    (*page_num)++;
  }
}

/***********************************
FUNCTION: InitQueue
DESCRIPTION: ��ʼ������
INPUT: *node
RETURN: ��
***********************************/
void InitQueue(HNode *node)
{
  node->hold_info = (Hold *)malloc((MaxSize + 1) * sizeof(Hold)); // +1�����ϳ�����ȶ���
  if (!node->hold_info)
  {
    printf("malloc runs wrong in InitQueue\n");
    delay(3000);
    exit(1);
  }
  memset(node->hold_info, '\0', (MaxSize + 1) * sizeof(Hold));
  node->front = 0;
  node->rear = 0;
}

/***********************************
FUNCTION: holdinfo_read
DESCRIPTION: ��HOLD��Ʊ��Ϣ��ȡ����Ʊ�б�h_list��
INPUT: USER *u, Hold *h_list
RETURN: len(������ʷ��Ʊ��)
***********************************/
int holdinfo_read(USER *u, Hold *h_list)
{
  int i, len;
  FILE *fp;
  Hold htemp;
  char file_hold[30] = "\0";
  strcpy(file_hold, "database\\");
  strcat(file_hold, u->name);
  strcat(file_hold, "\\hold.dat");

  if ((fp = fopen(file_hold, "rb+")) == NULL)
  {
    printf("cannot open file hold\n");
    delay(3000);
    exit(1);
  }

  fseek(fp, 0, SEEK_END);
  len = ftell(fp) / sizeof(Hold);
  memset(h_list, '\0', len * sizeof(Hold));
  for (i = 0; i < len; i++)
  {
    memset(&htemp, '\0', sizeof(Hold));
    fseek(fp, i * sizeof(Hold), SEEK_SET);
    fread(&htemp, sizeof(Hold), 1, fp);
    strcpy(h_list[i].number, htemp.number);
    strcpy(h_list[i].company, htemp.company);
    strcpy(h_list[i].city1, htemp.city1);
    strcpy(h_list[i].city2, htemp.city2);
    strcpy(h_list[i].price, htemp.price);
    strcpy(h_list[i].sort, htemp.sort);
    strcpy(h_list[i].distance, htemp.distance);
    strcpy(h_list[i].ticket_num, htemp.ticket_num);
    strcpy(h_list[i].date, htemp.date);
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close file hold");
    delay(2000);
    exit(1);
  }
  return len;
}

/***********************************
FUNCTION: enqueue_history
DESCRIPTION: �������
INPUT: *node,*t_list,prepage
RETURN: ��
***********************************/
void enqueue_history(HNode *node, Hold *h_list, int prepage)
{
  int i;
  if ((node->rear + 1) % (MaxSize + 1) == node->front) //�ж϶����Ƿ�����
  {
    return;
  }
  for (i = 0; i < MaxSize; i++)
  {
    strcpy(node->hold_info[node->rear].number, h_list[MaxSize * prepage + i].number);
    strcpy(node->hold_info[node->rear].company, h_list[MaxSize * prepage + i].company);
    strcpy(node->hold_info[node->rear].city1, h_list[MaxSize * prepage + i].city1);
    strcpy(node->hold_info[node->rear].city2, h_list[MaxSize * prepage + i].city2);
    strcpy(node->hold_info[node->rear].price, h_list[MaxSize * prepage + i].price);
    strcpy(node->hold_info[node->rear].sort, h_list[MaxSize * prepage + i].sort);
    strcpy(node->hold_info[node->rear].distance, h_list[MaxSize * prepage + i].distance);
    strcpy(node->hold_info[node->rear].ticket_num, h_list[MaxSize * prepage + i].ticket_num);
    strcpy(node->hold_info[node->rear].date, h_list[MaxSize * prepage + i].date);
    node->rear = (node->rear + 1) % (MaxSize);
  }
}

/***********************************
FUNCTION: hold_display
DESCRIPTION: չʾ�ѹ���Ʊ��¼
INPUT: *node��flag,page_rest
RETURN: ��
***********************************/
void hold_display(HNode *node, int flag, int page_rest ,int page_num)
{
  int i, j;
  setcolor(BROWN);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  settextjustify(LEFT_TEXT, TOP_TEXT);

  if (flag == 1 && strlen(node->hold_info[0].number) != 0) //�������һҳ
  {
    /* for (j = 0; j < page_rest; j++)     
      {
        puthz(10, 150 + 5 + j * 30, "����", 16, 18, 6);
        puthz(65, 150 + 5 + j * 30, "��", 16, 18, 6);
      }  
    */
    if(page_num > 1)
    {
      for (j = 0; j < MaxSize; j++)     //��������ҳʱ����һҳӦ��ȫ����ӡ������������
      {
        puthz(10, 150 + 5 + j * 30, "����", 16, 18, 6);
        puthz(70, 150 + 5 + j * 30, "��", 16, 18, 6);
      }
    }
    else if (page_num == 1)
    {
      for (j = 0; j < page_rest ; j++)
      {
        puthz(10, 150 + 5 + j * 30, "����", 16, 18, 6);
        puthz(70, 150 + 5 + j * 30, "��", 16, 18, 6);
      }
    }
    for (i = 0; i < MaxSize; i++)
    {
      outtextxy(50, 150 + i * 30, node->hold_info[i].date);
      outtextxy(110, 150 + i * 30, node->hold_info[i].number);
      puthz(210, 150 + 5 + i * 30, node->hold_info[i].company, 16, 18, 6);
      puthz(290, 150 + 5 + i * 30, node->hold_info[i].city1, 16, 18, 6);
      puthz(360, 150 + 5 + i * 30, node->hold_info[i].city2, 16, 18, 6);
      outtextxy(425, 150 + i * 30, node->hold_info[i].price);
      puthz(495, 150 + 5 + i * 30, node->hold_info[i].sort, 16, 18, 6);
      outtextxy(580, 150 + i * 30, node->hold_info[i].ticket_num);
    }
  }
  else if (flag == 2 && strlen(node->hold_info[0].number) != 0) //�����һҳ
  {
    for (j = 0; j < page_rest; j++)
    {
      puthz(10, 150 + 5 + j * 30, "����", 16, 18, 6);
      puthz(70, 150 + 5 + j * 30, "��", 16, 18, 6);
    }
    for (i = 0; i < MaxSize; i++)
    {
      outtextxy(50, 150 + i * 30, node->hold_info[i].date);
      outtextxy(110, 150 + i * 30, node->hold_info[i].number);
      puthz(210, 150 + 5 + i * 30, node->hold_info[i].company, 16, 18, 6);
      puthz(290, 150 + 5 + i * 30, node->hold_info[i].city1, 16, 18, 6);
      puthz(360, 150 + 5 + i * 30, node->hold_info[i].city2, 16, 18, 6);
      outtextxy(425, 150 + i * 30, node->hold_info[i].price);
      puthz(495, 150 + 5 + i * 30, node->hold_info[i].sort, 16, 18, 6);
      outtextxy(580, 150 + i * 30, node->hold_info[i].ticket_num);
    }
  }
}

/***********************************
FUNCTION: hold_cover
DESCRIPTION: �ڸ��ѹ���Ʊ��¼���Ա㻻ҳ��
INPUT: ��
RETURN: ��
***********************************/
void hold_cover(void)
{
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 135, 640, 390);
  setcolor(DARKGRAY);
  line(0, 173, 640, 173);
  line(0, 203, 640, 203);
  line(0, 233, 640, 233);
  line(0, 263, 640, 263);
  line(0, 293, 640, 293);
  line(0, 323, 640, 323);
  line(0, 353, 640, 353);
  line(0, 383, 640, 383);
}