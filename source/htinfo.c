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

/***********************************
FUNCTION: htinfo_main
DESCRIPTION: ��ѯ�Ѷ����Ƶ���Ϣ
INPUT: ��
RETURN: ��
***********************************/
void htinfo_main(int *func, USER *u, Live *L)
{
  htinfo_draw();
  exit_buttom();  
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
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

/***********************************
FUNCTION: htinfo_draw
DESCRIPTION: �ϴ�������������
INPUT: ��
RETURN: ��
***********************************/
void htinfo_draw(void)
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
  puthz(65, 20, "�Ѷ����Ƶ���Ϣ", 32, 35, 4);
  puthz(66, 21, "�Ѷ����Ƶ���Ϣ", 32, 35, 4);
  setcolor(DARKGRAY);
  rectangle(120,110,540,370);
  rectangle(125,105,545,365);
  puthz(160,135,"�Ƶ����֣�",16,18,1);
  puthz(160,165,"���ڳ��У�",16,18,1);
  puthz(160,195,"�������ͣ�",16,18,1);
  puthz(160,225,"���ռ۸�",16,18,1);
  puthz(160,255,"����������",16,18,1);
  puthz(160,285,"��ѡ�������ס�����ڣ�",16,18,1);
  puthz(410,325,"ף����;��죡",16,18,6);
  puthz(470,400,"����ǰҳ",16,18,6);
}
/*    �Ƶ����ڳ���
	char name[10];		//�Ƶ�����
	char price[5];		//����
	char class[10];		//��������
	char day[2];			//��ס������
	char checkin[5];	//������ס������
	char checkout[5]; //�����뿪������
*/

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