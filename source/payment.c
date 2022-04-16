/***********************************
FILE: payment.c
DESCRIPTION: 酒店支付界面
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
DESCRIPTION: 酒店支付主函数
INPUT: *func,
RETURN: 无
***********************************/
void payment_main(int *func, USER *u, Live *L)
{
  int state1 = 0;
  int num = 0;         //密码框
  int num2 = 0;        //按钮
  int flag = 1;        //用来判断银行卡密码是否正确
  int flag_finish = 0; //用来判断是否已经完成付款  1表示已经完成
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
  livingday = atoi(L->day); //字符串转换为整数
  total_price = single_price * livingday;
  itoa(total_price, totalpay, 10); //整数转换为字符串
  setcolor(DARKGRAY);
  outtextxy(230, 225, totalpay);

  //鼠标操作
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
    //返回前页
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
    //扫码支付
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

    //银行卡支付
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

    //输入银行卡密码
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
        memset(bankpassword, '\0', sizeof(bankpassword)); //确认密码清除
        inputbankpassword(bankpassword, 200, 265, 7, LIGHTGRAY); //输入银行卡密码
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

    //确定付款
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
          puthz(430, 270, "密码错误或未输入", 16, 18, 6);
        }
        else if (flag == 0)
        {
          if (flag_finish == 0)
          {
            inputlive_database(u, L);
            setfillstyle(SOLID_FILL, WHITE);
            bar(320, 340, 640, 380);
            bar(390, 260, 640, 300);
            puthz(430, 270, "密码正确", 16, 18, 6);
            puthz(430, 350, "支付完成", 16, 18, 6);
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
            puthz(430, 350, "请勿重复付款", 16, 18, 6);
          }
        }
        continue;
      }
    }

    //密码框恢复点亮
    if (num != 0)
    {
      MouseS = 0;
      if (state1 == 0 && num == 1)
      {
        recover_payment(200, 265, 380, 295, 1);
      }
      num = 0;
    }

    //按钮恢复点亮
    if (num2 != 0)
    {
      if (num2 == 1)
      {
        recover_booked(190, 340, 280, 375, 3);
      }
      num2 = 0;
    }

    //调整鼠标手势
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}

/***********************************
FUNCTION: inputadmin_database
DESCRIPTION: 将已订购酒店信息写入数据库
INPUT:
RETURN: 无
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
  fwrite(L, sizeof(Live), 1, fp); //写入机票信息
  if (fclose(fp) != 0)
  {
    printf("%s close failed\n", file_live);
    delay(3000);
    exit(1);
  }
}

/***********************************
FUNCTION: payment_info
DESCRIPTION: 酒店支付界面支付信息
INPUT: 无
RETURN: 无
***********************************/
void payment_info(USER *u, Live *L)
{
  settextjustify(LEFT_TEXT, TOP_TEXT); //设置文本对齐方式
  settextstyle(2, 0, 7);
  setcolor(DARKGRAY);
  outtextxy(165, 147, u->name);
  outtextxy(165, 187, u->bank);
}

/***********************************
FUNCTION: lightup_payment
DESCRIPTION: 酒店支付界面密码框点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_payment(int x1, int y1, int x2, int y2, int flag)
{
  clrmous(MouseX, MouseY);
  delay(10);
  setcolor(RED);
  setfillstyle(1, LIGHTGRAY);
  bar(x1, y1, x2, y2);                       //填充内部
  rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //画边框
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
DESCRIPTION: 酒店支付界面按钮点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
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
DESCRIPTION: 不显示银行卡密码的输入功能
INPUT: *id 需要输入的字符串，x，y，charnum 最多输入的字符数
RETURN: 无
***********************************/
void inputbankpassword(char *id, int x1, int y1, int charnum, int color)
{
  int k = 0;
  int i = 0;
  char t;
  clrmous(MouseX, MouseY);
  setfillstyle(SOLID_FILL, color);
  setlinestyle(SOLID_LINE, 0, NORM_WIDTH); //NOR_WIDTH 和 THICK_WIDTH
  setcolor(WHITE);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
  settextjustify(LEFT_TEXT, TOP_TEXT);
  line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
  while (bioskey(1)) //直接使用BIOS服务的键盘接口
  {
    k = bioskey(0);
    // bioskey(1)检测是否有键按下,没有键按下时返回0,有键按下时返回按键码(任何按键码都不为0),但此时并不将检测到的按键码从键盘缓冲队列中清除.
    // bioskey(0)返回键盘缓冲队列中的按键码，并将此按键码从键盘缓冲队列中清除.
  }
  while (1)
  {
    t = bioskey(0);
    if (i < charnum)
    {
      if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
      {
        if (t != '\b') //  \b表示退格
        {
          *(id + i) = t; //读入字符串id
          *(id + i + 1) = '\0';
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
          outtextxy(x1 + 8 + i * 18, y1 + 2, "*");                 //输出*字符(16)
          i++;
          line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
        }
        else if (t == '\b' && i > 0) //退格键
        {
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //遮盖光标
          bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //遮盖文字
          i--;                                                       //减少一个字数
          line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //绘制光标
          *(id + i) = '\0';
          *(id + i + 1) = '\0';
        }
        else
        {
          setfillstyle(SOLID_FILL, color);
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
          break;
        }
      }
      else
      {
        setfillstyle(SOLID_FILL, color);
        bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
        break;
      }
    }
    else if (i >= charnum)
    {
      if (t != '\n' && t != '\r' && t != ' ' && t != 033) // Esc
      {
        if (t == '\b' && i > 0) //退格键
        {
          bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);   //遮盖光标
          bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);   //遮盖文字
          i--;                                                       //减少一个字数
          line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20); //绘制光标
          *(id + i) = '\0';
        }
      }
      else
      {
        setfillstyle(SOLID_FILL, color);
        bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
        break;
      }
    }
  }
}

/***********************************
FUNCTION: payment_draw
DESCRIPTION: 酒店支付绘图
INPUT: 无
RETURN: 无
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
  puthz(65, 20, "支付", 32, 35, 4);
  puthz(80, 83, "银行卡支付", 16, 18, 1);
  puthz(220, 83, "扫码支付", 16, 18, 1);
  puthz(340, 83, "返回前页", 16, 18, 1);
  puthz(80, 150, "用户姓名：", 16, 18, 5);
  puthz(80, 190, "银行卡号：", 16, 18, 5);
  puthz(80, 230, "需要支付的金额：", 16, 18, 5);
  puthz(80, 270, "请输入密码：", 16, 18, 5);
  puthz(200, 350, "确定付款", 16, 18, 1);
  setcolor(LIGHTCYAN);
  rectangle(190, 340, 280, 375);
  setcolor(DARKGRAY);
  rectangle(200, 265, 380, 295);
}
