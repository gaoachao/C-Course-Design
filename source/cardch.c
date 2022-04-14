/***********************************
FILE: cardch.c
DESCRIPTION: 银行卡信息修改界面
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
DESCRIPTION: 疫情防控主函数
INPUT: *func
RETURN: 无
***********************************/
void cardchange_main(int *func, USER *u)
{
  int temp2 = 0; //用来记录输入的已绑定密码和数据库中密码是否一致
  int num = 0;
  int state1 = 0; // state1、2、3是用来判断输入框内是否有输入信息
  int state2 = 0;
  int state3 = 0;
  char old_password[10];     //已绑定的银行卡密码
  char new_password[10];     //输入的新的银行卡密码
  char new_card[20];         //输入的新的银行卡号
  int state_password = 0;    //用来记录密码是否修改的状态量
  int state_bankcard = 0;    //用来记录银行卡号是否修改的状态量
  char new_bankcard[20];     //用来将新的银行卡号写入数据库
  char new_cardpassword[10]; //用来将新的银行卡写入数据库
  cardchange_draw();
  exit_buttom();
  cardinfo(u);

  //鼠标操作
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);

    //返回前页
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

    //银行卡账户信息
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

    //银行卡更改绑定信息
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

    //输入当前的密码
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
        memset(old_password, '\0', sizeof(old_password)); //确认密码清除
        inputadmin(old_password, 280, 220, 6, 7);        //输入旧密码
        if (strlen(old_password) == 0)
        {
          state1 = 0;
        }
        else
          state1 = 1;
      }
    }
    //输入银行卡卡号
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
        memset(new_card, '\0', sizeof(new_card)); //确认清除
        inputadmin(new_card, 225, 260, 19, 7);   //输入新的账号
        if (strlen(new_card) == 0)
        {
          state2 = 0;
        }
        else
          state2 = 1;
      }
    }
    //输入新卡密码
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
        memset(new_password, '\0', sizeof(new_password)); //确认密码清除
        inputadmin(new_password, 225, 300, 6, 7);        //输入新密码
        if (strlen(new_password) == 0)
        {
          state3 = 0;
        }
        else
          state3 = 1;
      }
    }

    //恢复点亮
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

    // rectangle(270,350,355,385); 确认更改

    //确定按钮
    if (MouseX > 270 && MouseX < 355 && MouseY > 350 && MouseY < 385)
    {
      if (mouse_press(270, 350, 355, 385) == 2)
      {
        MouseS = 1;
        continue;
      }
      else if (mouse_press(270, 350, 355, 385) == 1)
      {
        temp2 = strcmp(old_password, u->bankpassword); //输入的银行卡密码与数据库中密码对比
        if (temp2 != 0 && state_password == 0)
        {
          setfillstyle(SOLID_FILL, WHITE);
          bar(525, 220, 640, 250);
          puthz(525, 220, "旧密码错误", 16, 18, 6);
        }
        else if (temp2 == 0)
        {
          setfillstyle(SOLID_FILL, WHITE);
          bar(525, 220, 640, 250);
          puthz(525, 220, "旧密码正确", 16, 18, 6);
          strcpy(new_bankcard, new_card);
          strcpy(new_cardpassword, new_password);
          input_newcard(u, new_bankcard);
          input_newcardpassword(u, new_cardpassword);
          clrmous(MouseX, MouseY);
          puthz(400, 360, "更改成功！", 16, 18, 6);
          state_password = 1;
          state_bankcard = 1;
        }
      }
    }

    //退出键
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

    //调整鼠标手势
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}

/*****************************
FUNCTION: cardinfo
DESCRIPTION: 银行卡信息
INPUT: u
RETURN: 无
*****************************/
void cardinfo(USER *u)
{
  settextjustify(LEFT_TEXT, TOP_TEXT); //设置文本对齐方式
  settextstyle(2, 0, 7);
  setcolor(DARKGRAY);
  outtextxy(160, 147, u->name);
  outtextxy(160, 187, u->bank);
}

/***********************************
FUNCTION: input_newcardpassword
DESCRIPTION: 将新的银行卡账户写入数据库
INPUT:*u
RETURN: 无
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
  len = ftell(fp) / sizeof(USER); //用户的个数
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
DESCRIPTION: 将新的银行卡账户写入数据库
INPUT:*u
RETURN: 无
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
  len = ftell(fp) / sizeof(USER); //用户的个数
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
DESCRIPTION: 银行卡信息修改界面
INPUT: 无
RETURN: 无
***********************************/
void cardchange_draw(void)
{
  clrmous(MouseX, MouseY);
  cleardevice();
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, 640, 480);
  puthz(65, 20, "我的银行卡", 32, 35, 4);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(0, 75, 640, 110);
  puthz(80, 85, "账户信息", 16, 18, 1);
  puthz(200, 85, "更换绑定", 16, 18, 1);
  puthz(320, 85, "返回前页", 16, 18, 1);
  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 115, 640, 480);
  puthz(70, 150, "用户姓名：", 16, 18, 5);
  puthz(70, 190, "银行卡号：", 16, 18, 5);
  puthz(70, 230, "请输入当前银行卡密码：", 16, 18, 5);
  puthz(70, 270, "新的银行卡卡号：", 16, 18, 5);
  puthz(70, 310, "新的银行卡密码：", 16, 18, 5);
  setcolor(DARKGRAY);
  rectangle(280, 220, 520, 250); //当前银行卡密码
  rectangle(225, 260, 580, 290); //银行卡卡号
  rectangle(225, 300, 465, 330); //银行卡密码
  // rectangle(270,350,355,385); 确认更改
  puthz(280, 360, "确定更改", 16, 18, 4)
  ;

}