/***********************************
FILE: cardch.c
DESCRIPTION: ���п���Ϣ�޸Ľ���
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
#include "cardch.h"
#include "change2.h"
#include"login.h"
/***********************************
FUNCTION: mycard_main
DESCRIPTION: �������������
INPUT: *func
RETURN: ��
***********************************/
void cardchange_main(int *func, USER *u)
{
  int temp2 = 0; //������¼������Ѱ���������ݿ��������Ƿ�һ��
  int num = 0;
  int state1 = 0; // state1��2��3�������ж���������Ƿ���������Ϣ
  int state2 = 0;
  int state3 = 0;
  char old_password[10];     //�Ѱ󶨵����п�����
  char new_password[10];     //������µ����п�����
  char new_card[20];         //������µ����п���
  int state_password = 0;    //������¼�����Ƿ��޸ĵ�״̬��
  int state_bankcard = 0;    //������¼���п����Ƿ��޸ĵ�״̬��
  char new_bankcard[20];     //�������µ����п���д�����ݿ�
  char new_cardpassword[10]; //�������µ����п�д�����ݿ�
  cardchange_draw();
  exit_buttom();
  cardinfo(u);

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

    //���п��˻���Ϣ
    if (MouseX > 75 && MouseX < 150 && MouseY > 80 && MouseY < 110)
    {
      if (mouse_press(75, 80, 150, 110) == 2)
      {
        MouseS = 1;
        continue;
      }
      if (mouse_press(75, 80, 150, 110) == 1)
      {
        *func = 13;
        return;
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

    //���뵱ǰ������
    if (MouseX > 280 && MouseX < 520 && MouseY > 220 && MouseY < 250)
    {
      if (mouse_press(280, 220, 520, 250) == 2)
      {
        MouseS = 2;
        if (num == 0 && state1 == 0)
        {
          lightup_change2(280, 220, 520, 250, 1);
          num = 1;
        }
        continue;
      }
      else if (mouse_press(280, 220, 520, 250) == 1)
      {
        lightup_change2(280, 220, 520, 250, 1);
        memset(old_password, '\0', sizeof(old_password)); //ȷ���������
        inputadmin(old_password, 280, 220, 6, 7);        //���������
        if (strlen(old_password) == 0)
        {
          state1 = 0;
        }
        else
          state1 = 1;
      }
    }
    //�������п�����
    if (MouseX > 225 && MouseX < 580 && MouseY >260  && MouseY < 290)
    {
      if (mouse_press(225, 260, 575, 290) == 2)
      {
        MouseS = 2;
        if (num == 0 && state2 == 0)
        {
          lightup_change2(225, 260, 580, 290, 1);
          num = 2;
        }
        continue;
      }
      else if (mouse_press(225, 260, 580, 290) == 1)
      {
        lightup_change2(225, 260, 580, 290, 1);
        memset(new_card, '\0', sizeof(new_card)); //ȷ�����
        inputadmin(new_card, 225, 260, 19, 7);   //�����µ��˺�
        if (strlen(new_card) == 0)
        {
          state2 = 0;
        }
        else
          state2 = 1;
      }
    }
    //�����¿�����
    if (MouseX > 225 && MouseX < 465 && MouseY > 300 && MouseY < 330)
    {
      if (mouse_press(225, 300, 465, 330) == 2)
      {
        MouseS = 2;
        if (num == 0 && state3 == 0)
        {
          lightup_change2(225, 300, 465, 330, 1);
          num = 3;
        }
        continue;
      }
      else if (mouse_press(225, 300, 465, 330) == 1)
      {
        lightup_change2(225, 300, 465, 330, 1);
        memset(new_password, '\0', sizeof(new_password)); //ȷ���������
        inputadmin(new_password, 225, 300, 6, 7);        //����������
        if (strlen(new_password) == 0)
        {
          state3 = 0;
        }
        else
          state3 = 1;
      }
    }

    //�ָ�����
    if (num != 0)
    {
      MouseS = 0;
      if (state1 == 0 && num == 1)
      {
        recoverbuttom_change2(280, 220, 520, 250, 1);
      }
      if (state2 == 0 && num == 2)
      {
        recoverbuttom_change2(225, 260, 580, 290, 1);
      }
      if (state3 == 0 && num == 3)
      {
        recoverbuttom_change2(225, 300, 465, 330, 1);
      }
      num = 0;
    }

    // rectangle(270,350,355,385); ȷ�ϸ���

    //ȷ����ť
    if (MouseX > 270 && MouseX < 355 && MouseY > 350 && MouseY < 385)
    {
      if (mouse_press(270, 350, 355, 385) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(270, 350, 355, 385) == 1)
      {
        temp2 = strcmp(old_password, u->bankpassword); //��������п����������ݿ�������Ա�
        if (temp2 != 0 && state_password == 0)
        {
          setfillstyle(SOLID_FILL, WHITE);
          bar(525, 220, 640, 250);
          puthz(525, 220, "���������", 16, 18, 6);
        }
        else if (temp2 == 0)
        {
          setfillstyle(SOLID_FILL, WHITE);
          bar(525, 220, 640, 250);
          puthz(525, 220, "��������ȷ", 16, 18, 6);
          strcpy(new_bankcard, new_card);
          strcpy(new_cardpassword, new_password);
          input_newcard(u, new_bankcard);
          input_newcardpassword(u, new_cardpassword);
          clrmous(MouseX, MouseY);
          puthz(400, 360, "���ĳɹ���", 16, 18, 6);
          state_password = 1;
          state_bankcard = 1;
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

    //�����������
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}

/*****************************
FUNCTION: cardinfo
DESCRIPTION: ���п���Ϣ
INPUT: u
RETURN: ��
*****************************/
void cardinfo(USER *u)
{
  settextjustify(LEFT_TEXT, TOP_TEXT); //�����ı����뷽ʽ
  settextstyle(2, 0, 7);
  setcolor(DARKGRAY);
  outtextxy(160, 147, u->name);
  outtextxy(160, 187, u->bank);
}

/***********************************
FUNCTION: input_newcardpassword
DESCRIPTION: ���µ����п��˻�д�����ݿ�
INPUT:*u
RETURN: ��
***********************************/
void input_newcardpassword(USER *u, char *new_cardpassword)
{
  USER utemp;
  FILE *fp;
  int i, len;

  if ((fp = fopen("database\\userdata.dat", "rb+")) == NULL)
  {
    printf("cannot open file userdata\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp) / sizeof(USER); //�û��ĸ���
  for (i = 0; i < len; i++)
  {
    memset(&utemp, '\0', sizeof(USER));
    fseek(fp, i * sizeof(USER), SEEK_SET);
    fread(&utemp, sizeof(USER), 1, fp);
    if (strcmp(u->name, utemp.name) == 0)
    {
      strcpy(u->bankpassword, new_cardpassword);
      fseek(fp, i * sizeof(USER), SEEK_SET);
      fwrite(u, sizeof(USER), 1, fp);
      break;
    }
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close database\n");
    delay(2000);
    exit(1);
  }
}
/***********************************
FUNCTION: input_newcard
DESCRIPTION: ���µ����п��˻�д�����ݿ�
INPUT:*u
RETURN: ��
***********************************/
void input_newcard(USER *u, char *new_bank)
{
  USER utemp;
  FILE *fp;
  int i, len;

  if ((fp = fopen("database\\userdata.dat", "rb+")) == NULL)
  {
    printf("cannot open file userdata\n");
    delay(3000);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp) / sizeof(USER); //�û��ĸ���
  for (i = 0; i < len; i++)
  {
    memset(&utemp, '\0', sizeof(USER));
    fseek(fp, i * sizeof(USER), SEEK_SET);
    fread(&utemp, sizeof(USER), 1, fp);
    if (strcmp(u->name, utemp.name) == 0)
    {
      strcpy(u->bank, new_bank);
      fseek(fp, i * sizeof(USER), SEEK_SET);
      fwrite(u, sizeof(USER), 1, fp);
      break;
    }
  }
  if (fclose(fp) != 0)
  {
    printf("cannot close database\n");
    delay(2000);
    exit(1);
  }
}

/***********************************
FUNCTION: cardchange_draw
DESCRIPTION: ���п���Ϣ�޸Ľ���
INPUT: ��
RETURN: ��
***********************************/
void cardchange_draw(void)
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
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 115, 640, 480);
  puthz(70, 150, "�û�������", 16, 18, 5);
  puthz(70, 190, "���п��ţ�", 16, 18, 5);
  puthz(70, 230, "�����뵱ǰ���п����룺", 16, 18, 5);
  puthz(70, 270, "�µ����п����ţ�", 16, 18, 5);
  puthz(70, 310, "�µ����п����룺", 16, 18, 5);
  setcolor(DARKGRAY);
  rectangle(280, 220, 520, 250); //��ǰ���п�����
  rectangle(225, 260, 580, 290); //���п�����
  rectangle(225, 300, 465, 330); //���п�����
  // rectangle(270,350,355,385); ȷ�ϸ���
  puthz(280, 360, "ȷ������", 16, 18, 4)
  ;

}