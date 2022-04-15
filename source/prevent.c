/***********************************
FILE: userpage.c
DESCRIPTION: 用户个人中心，包括修改密码、待出行机票查询、个人信息（包括健康状况）显示等功能
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
#define tips_len 10

/***********************************
FUNCTION: prevent_main
DESCRIPTION: 疫情防控主函数
INPUT: *func
RETURN: 无
***********************************/
void prevent_main(int *func, USER *u)
{
  StaticLinkList list[tips_len];
  int i = 0;
  int num = 0;
  int flag = 0;
  City c[city_len];
  InitList(list);
  getinfo_List(list);
  //出现疫情防控界面
  prevent_draw();
  //退出按钮
  exit_buttom();
  //打印防疫标语
  printtips(list);
  
  //刚进入页面进行一次健康状态的判断
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

  //鼠标操作
  while (1)
  {
    newmouse(&MouseX, &MouseY, &press);
    //跳转至机票信息界面
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

    //跳转至个人中心界面
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

    //跳转至动态查询界面
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

    //退出键
    if (MouseX > 595 && MouseX < 640 && MouseY > 0 && MouseY < 20)
    {
      if (mouse_press(595, 0, 640, 20) == 1)
      {
        *func = 1;
        return;
      }
    }
    //中高风险地区查询键
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
        city_read(c);
        get_cityinfo(c);
        continue;
      }
    }

    //旅客过往地区查询键
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
        continue;
      }
    }

    //旅客核酸结果填报
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
        continue;
      }
    }

    //下一条
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
        if (flag != list[flag].cur)
        {
          flag = list[flag].cur;
        }
        continue;
      }
      else if (mouse_press(530, 115, 600, 145) == 1)
      {
        tips_cover();

        puthz(100, 110, list[flag].data, 16, 18, 6);
        continue;
      }
    }

    //管理员模式     rectangle(320, 230, 430, 265);
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
        continue;
      }
    }

    //按钮恢复点亮
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

    //调整鼠标手势
    if (MouseS != 0)
    {
      MouseS = 0;
    }
  }
}
/***********************************
FUNCTION: city_read
DESCRIPTION: 中高风险地区读入
INPUT: 无
RETURN: 无
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
  while (!feof(fp) || i < city_len) //检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0
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
DESCRIPTION:疫情防控界面输出当前中高风险地区
INPUT: c
RETURN: 无
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
DESCRIPTION: 疫情防控界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
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
    puthz(540, 118, "下一条", 16, 18, 4);
    break;
  }

  case 2:
  {
    setcolor(RED);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    puthz(330, 240, "管理员模式", 16, 18, 1);
    break;
  }
  case 3:
  {
    puthz(240, 200, "查询", 16, 18, 1); //旅客过往地区查询
    break;
  }
  case 4:
  {
    puthz(240, 240, "查询", 16, 18, 1); //当前中高风险地区查询
    break;
  }
  case 5:
  {
    puthz(240, 280, "填报", 16, 18, 1); //旅客核酸信息填报
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
DESCRIPTION: 疫情防控界面点亮恢复
INPUT: x1,y1,x2,y2.flag
RETURN: 无
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
    puthz(540, 118, "下一条", 16, 18, 1);
    break;
  }
  case 2:
  {
    setcolor(BROWN);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    puthz(330, 240, "管理员模式", 16, 18, 1);
    break;
  }
  case 3:
  {
    puthz(240, 200, "查询", 16, 18, 1); //旅客过往地区查询
    break;
  }
  case 4:
  {
    puthz(240, 240, "查询", 16, 18, 1); //当前中高风险地区查询
    break;
  }
  case 5:
  {
    puthz(240, 280, "填报", 16, 18, 1); //旅客核酸信息填报
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
DESCRIPTION: 疫情防控界面
INPUT: 无
RETURN: 无
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
  puthz(65, 20, "航旅纵横", 32, 35, 4);
  puthz(270, 30, "机票信息", 16, 18, 8);
  puthz(360, 30, "个人中心", 16, 18, 8);
  puthz(450, 30, "疫情防控", 16, 18, 2);
  puthz(540, 30, "动态查询", 16, 18, 8);
  puthz(30, 70, "出行防疫提示：", 16, 18, 5);
  puthz(30, 160, "旅客健康状态：", 16, 18, 5);
  puthz(30, 200, "旅客过往地区：", 16, 18, 5);
  puthz(240, 200, "查询", 16, 18, 1);
  puthz(30, 240, "当前中高风险地区：", 16, 18, 5);
  puthz(240, 240, "查询", 16, 18, 1);
  puthz(30, 280, "旅客核酸结果：", 16, 18, 5);
  puthz(240, 280, "填报", 16, 18, 1);
  puthz(540, 118, "下一条", 16, 18, 1);
  setcolor(BROWN);
  rectangle(530, 110, 600, 140);
  puthz(330, 240, "管理员模式", 16, 18, 1);
  rectangle(320, 230, 430, 265);
}

/* 1 蓝色
   2 绿色
   3 青色
   4 红色
   5 梅红色
   6 棕黄色（偏金）
   7 淡灰色
   8 深灰色
   9 深蓝色
*/

//防疫提示 静态链表
/***********************************
FUNCTION: InitList
DESCRIPTION: 初始化链表,设定游标
INPUT: StaticLinkList space
RETURN: 无
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
FUNCTION: getinfo_List
DESCRIPTION: 队列获得数据
INPUT:
RETURN: 无
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
  //检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0
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
DESCRIPTION: 打印防疫标语
INPUT:StaticLinkList *space
RETURN: 无
***********************************/
void printtips(StaticLinkList *space)
{
  puthz(100, 110, space[0].data, 16, 18, 6);
}

/***********************************
FUNCTION: tips_cover
DESCRIPTION: 遮盖防疫标语
INPUT: 无
RETURN: 无
***********************************/
void tips_cover(void)
{
  setfillstyle(SOLID_FILL, WHITE);
  bar(70, 90, 350, 140);
}
