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
#include "buypage.h"
#include "menu.h"
#include "purchase.h"
#include "pay.h"

/***********************************
FUNCTION: purchace_confirm_main
DESCRIPTION: ��Ʊ��Ϣȷ��������
INPUT: *u,t
RETURN: ��
***********************************/
void purchace_confirm_main(int *func, USER *u, Ticket t)
{
    int num = 0;

    purchace_confirm_draw(u, t);
    delay(30);

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //ȷ�ϰ���
        if (MouseX > 100 && MouseX < 230 && MouseY > 400 && MouseY < 430)
        {
            if (mouse_press(100, 400, 230, 430) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    lightup_purchace_confirm(100, 400, 230, 430, 1);
                    num = 1;
                }
                continue;
            }
            else if (mouse_press(100, 400, 230, 430) == 1)
            {
                if (info_check(u->health_code) == 1) //���Թ�Ʊ
                {
                    *func = 10;
                    clrmous(MouseX, MouseY);
                    delay(1000);
                    return;
                }
            }
        }

        //���ؼ�
        if (MouseX > 410 && MouseX < 540 && MouseY > 400 && MouseY < 430)
        {
            if (mouse_press(410, 400, 540, 430) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    lightup_purchace_confirm(410, 400, 540, 430, 2);
                    num = 2;
                }
                continue;
            }
            else if (mouse_press(410, 400, 540, 430) == 1)
            {
                *func = 4;
                return;
            }
        }

        if (num != 0)
        {
            if (num == 1)
            {
                recoverbuttom_purchace_confirm(100, 400, 230, 430, 1);
            }
            if (num == 2)
            {
                recoverbuttom_purchace_confirm(410, 400, 540, 430, 2);
            }
            num = 0;
        }

        if (MouseS != 0)
        {
            MouseS = 0;
        }
    }
}

/***********************************
FUNCTION: purchace_main
DESCRIPTION: ��Ʊ������
INPUT: *func,*name,*id,t
RETURN: ��
***********************************/
void purchace_main(int *func, USER u, Ticket t)
{
    int num = 0, flag = 1;
    Hold hold;
    FILE *fp;
    char u_name[30];
    int tnum = 1;
    char ticket_num[3] = "\0";
    int price1 = 0, price2 = 0, price = 0;
    int flag1 = 0;

    char sum[4];

    memset(&hold, '\0', sizeof(Hold));
    delay(100);
    purchace_draw(u.name, u.id, t);
    delay(30);
    strcpy(u_name, "database\\");
    strcat(u_name, u.name);
    strcpy(hold.number, t.number);
    strcpy(hold.company, t.company);
    strcpy(hold.city1, t.city1);
    strcpy(hold.city2, t.city2);
    strcpy(hold.distance, t.distance);
    price1 = atoi(t.economy_price);
    itoa(tnum, ticket_num, 10);
    //�ļ��в���
    if (access(u_name, 0) == -1) //�ļ��в�����
    {
        if (mkdir(u_name) != 0)
        {
            printf("The file news failed\n");
        }
    }
    strcat(u_name, "\\hold.dat");
    if (access(u_name, 0) == -1) // hold�ļ�������
    {
        if ((fp = fopen(u_name, "wb+")) == NULL)
        {
            printf("%s new failed\n", u_name);
            delay(3000);
            exit(1);
        }
        if (fclose(fp) != 0)
        {
            printf("%s close failed\n", u_name);
            delay(3000);
            exit(1);
        }
    }

    /*   if ((fp = fopen(u_name, "wb+")) == NULL)
       {
           printf("%s new failed\n", u_name);
           delay(3000);
           exit(1);
       }
       if (fclose(fp) != 0)
       {
           printf("%s close failed\n", u_name);
           delay(3000);
           exit(1);
       }*/
    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);

        //����
        if (MouseX > 98 && MouseX < 114 && MouseY > 220 && MouseY < 236)
        {
            if (mouse_press(98, 220, 114, 236) == 2)
            {
                MouseS = 1;
                continue;
            }
            else if (mouse_press(98, 220, 114, 236) == 1)
            {
                if (tnum > 1)
                {
                    tnum--;
                    itoa(tnum, ticket_num, 10);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(118, 220, 134, 236);
                    setcolor(BLUE);
                    outtextxy(120, 216, ticket_num);
                    delay(200);
                }
            }
        }

        //�Ӻ�
        if (MouseX > 138 && MouseX < 154 && MouseY > 220 && MouseY < 236)
        {
            if (mouse_press(138, 220, 154, 236) == 2)
            {
                MouseS = 1;
                continue;
            }
            else if (mouse_press(138, 220, 154, 236) == 1)
            {
                if (tnum < 3) //��๺������Ʊ
                {
                    tnum++;
                    itoa(tnum, ticket_num, 10);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(118, 220, 134, 236);
                    setcolor(BLUE);
                    outtextxy(120, 216, ticket_num);
                    delay(200);
                }
            }
        }

        //���ò�
        if (MouseX > 170 && MouseX < 186 && MouseY > 270 && MouseY < 286)
        {
            if (mouse_press(170, 270, 186, 286) == 2)
            {
                MouseS = 1;
                continue;
            }
            else if (mouse_press(170, 270, 186, 286) == 1)
            {
                if (flag == 2)
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(420, 270, 436, 286);
                    setcolor(BLUE);
                    rectangle(420, 270, 436, 286);
                }
                if (flag != 1)
                {
                    setfillstyle(SOLID_FILL, BLUE);
                    clrmous(MouseX, MouseY);
                    delay(30);
                    bar(170, 270, 186, 286);
                    flag = 1;
                    //                  strcpy(hold.sort, "���ò�");
                    //                    strcpy(hold.price, t.economy_price);
                    price1 = atoi(t.economy_price);
                    delay(100);
                }
            }
        }

        //�����
        if (MouseX > 420 && MouseX < 436 && MouseY > 270 && MouseY < 286)
        {
            if (mouse_press(420, 270, 436, 286) == 2)
            {
                MouseS = 1;
                continue;
            }
            else if (mouse_press(420, 270, 436, 286) == 1)
            {
                if (flag == 1)
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(170, 270, 186, 286);
                    setcolor(BLUE);
                    rectangle(170, 270, 186, 286);
                }
                if (flag != 2)
                {
                    setfillstyle(SOLID_FILL, BLUE);
                    clrmous(MouseX, MouseY);
                    delay(30);
                    bar(420, 270, 436, 286);
                    //                  strcpy(hold.sort, "�����");
                    //                   strcpy(hold.price, t.business_price);
                    price1 = atoi(t.business_price);
                    flag = 2;
                    delay(100);
                }
            }
        }

        //���ؼ�
        if (MouseX > 70 && MouseX < 200 && MouseY > 410 && MouseY < 440)
        {
            if (mouse_press(70, 410, 200, 440) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    lightup_purchace_confirm(70, 410, 200, 440, 3);
                    num = 1;
                }
                continue;
            }
            else if (mouse_press(70, 410, 200, 440) == 1)
            {
                *func = 9;
                return;
            }
        }

        //֧����
        if (MouseX > 440 && MouseX < 570 && MouseY > 410 && MouseY < 440)
        {
            if (mouse_press(440, 410, 570, 440) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    lightup_purchace_confirm(440, 410, 570, 440, 4);
                    num = 2;
                }
                continue;
            }
            else if (mouse_press(440, 410, 570, 440) == 1)
            {
                MouseS = 1;
                price = price1 * tnum + price2;
                itoa(price, sum, 10);

                strcpy(hold.ticket_num, ticket_num);
                strcpy(hold.price, sum);
                if (flag == 1)
                {
                    strcpy(hold.sort, "���ò�");
                }
                else if (flag == 2)
                {
                    strcpy(hold.sort, "�����");
                }
                flag1 = pay_main(u, hold, sum);
                if (flag1 == 1)
                {
                    *func = 4;
                    return;
                }
                else if (flag1 == 2)
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(255, 410, 385, 440);
                    num = 0;
                    purchace_draw(u.name, u.id, t);
                    tnum = 1;
                    flag = 1;
                    flag1 = 0;
                }
            }
        }

        //ɨ��֧����
        if (MouseX > 255 && MouseX < 385 && MouseY > 410 && MouseY < 440)
        {
            if (mouse_press(255, 410, 385, 440) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    lightup_purchace_confirm(255, 410, 385, 440, 5);
                    num = 3;
                }
                continue;
            }
            else if (mouse_press(255, 410, 385, 440) == 1)
            {
                MouseS = 1;

                price = price1 * tnum + price2;
                itoa(price, sum, 10);

                strcpy(hold.ticket_num, ticket_num);
                strcpy(hold.price, sum);
                if (flag == 1)
                {
                    strcpy(hold.sort, "���ò�");
                }
                else if (flag == 2)
                {
                    strcpy(hold.sort, "�����");
                }
                flag1 = codepay_main(u.name, t.number, sum, hold);
                if (flag1 == 1)
                {
                    *func = 4;
                    return;
                }
                else if (flag1 == 2)
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(255, 410, 385, 440);
                    num = 0;
                    purchace_draw(u.name, u.id, t);
                    tnum = 1;
                    flag = 1;
                    flag1 = 0;
                }
            }
        }

        if (num != 0)
        {
            if (num == 1)
            {
                recoverbuttom_purchace_confirm(70, 410, 200, 440, 3);
            }
            if (num == 2)
            {
                recoverbuttom_purchace_confirm(440, 410, 570, 440, 4);
            }
            if (num == 3)
            {
                recoverbuttom_purchace_confirm(255, 410, 385, 440, 5);
            }
            num = 0;
        }

        if (MouseS != 0)
        {
            MouseS = 0;
        }
    }
}

/***********************************
FUNCTION: info_check
DESCRIPTION: ����״̬��Ϣ���
INPUT: *health_code
RETURN: 1(���Թ�Ʊ)/0(���ܹ�Ʊ)
***********************************/
int info_check(char *health_code)
{
    setfillstyle(SOLID_FILL, WHITE);
    if (strcmp(health_code, "0") == 0)
    {
        bar(100, 374, 540, 394);
        puthz(100, 374, "����״̬δ�����ǰ���������Ļ�������ؽ����", 16, 18, LIGHTGREEN);
        return 0;
    }
    else if (strcmp(health_code, "1") == 0 || strcmp(health_code, "2") == 0)
    {
        bar(100, 374, 540, 394);
        puthz(100, 374, "���Թ�Ʊ", 16, 18, LIGHTGREEN);
        return 1;
    }
    else if (strcmp(health_code, "3") == 0)
    {
        bar(100, 374, 540, 394);
        puthz(100, 374, "Ϊ�߷�����Ⱥ���޷���Ʊ", 16, 18, LIGHTGREEN);
        return 0;
    }
}

/***********************************
FUNCTION: lightup__purchace_confirm
DESCRIPTION: ��Ʊ��Ϣȷ�Ͻ��水ť����
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void lightup_purchace_confirm(int x1, int y1, int x2, int y2, int flag)
{
    clrmous(MouseX, MouseY);
    delay(10);
    setcolor(LIGHTRED);
    //    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setfillstyle(1, LIGHTGRAY);

    bar(x1, y1, x2, y2);                       //����ڲ�
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //���߿�
    switch (flag)
    {
    case 1:
    {
        puthz(130, 404, "ȷ��", 24, 46, RED);
        break;
    }

    case 2:
    {
        puthz(440, 404, "����", 24, 46, RED);
        break;
    }

    case 3:
    {
        puthz(100, 414, "����", 24, 46, RED);
        break;
    }

    case 4:
    {
        puthz(470, 414, "֧��", 24, 46, RED);
        break;
    }

    case 5:
    {
        puthz(266, 414, "ɨ��֧��", 24, 28, RED);
        break;
    }

    default:
        printf("something wrong in loghtup_purchace_confirm\n");
        break;
    }
}

/***********************************
FUNCTION: recoverbuttom_purchace_confirm
DESCRIPTION: ��Ʊ��Ϣȷ�Ͻ��水ť�����ָ�
INPUT: x1,y1,x2,y2.flag
RETURN: ��
***********************************/
void recoverbuttom_purchace_confirm(int x1, int y1, int x2, int y2, int flag)
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
        puthz(130, 404, "ȷ��", 24, 46, DARKGRAY);
        break;
    }

    case 2:
    {
        puthz(440, 404, "����", 24, 46, DARKGRAY);
        break;
    }

    case 3:
    {
        puthz(100, 414, "����", 24, 46, DARKGRAY);
        break;
    }

    case 4:
    {
        puthz(470, 414, "֧��", 24, 46, DARKGRAY);
        break;
    }

    case 5:
    {
        puthz(266, 414, "ɨ��֧��", 24, 28, DARKGRAY);
        break;
    }

    default:
    {
        printf("something wrong in recoverbuttom_purchace_confirmr\n");
        closegraph();
        exit(1);
    }
    }
}

/***********************************
FUNCTION: purchace_confirm_draw
DESCRIPTION: ��Ϣȷ�Ͻ������
INPUT: *u,t
RETURN: ��
***********************************/
void purchace_draw(char *name, char *id, Ticket t)
{
    cleardevice();
    clrmous(MouseX, MouseY);
    delay(30);
    setbkcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setlinestyle(0, 0, 1);

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(1, 0, 639, 65);
    setcolor(DARKGRAY);
    line(1, 65, 639, 65);
    line(1, 64, 639, 64);

    puthz(240, 22, "��Ʊ����", 32, 40, 4);
    puthz(240 + 2, 22 + 2, "��Ʊ����", 32, 40, 5);

    setcolor(BROWN);
    line(1, 190, 639, 190);
    line(1, 360, 639, 360);
    // line(360,66,360,190);
    setcolor(BLUE);
    puthz(40, 80, "�����", 16, 18, DARKGRAY);
    outtextxy(100, 76, t.number);

    puthz(40, 120, "�û���", 16, 18, DARKGRAY);
    outtextxy(100, 116, name);
    puthz(40, 160, "���֤��", 16, 18, DARKGRAY);
    outtextxy(122, 156, id);

    puthz(40, 220, "��Ʊ��", 16, 18, DARKGRAY);
    outtextxy(100, 216, "-");
    rectangle(98, 220, 114, 236);
    outtextxy(120, 216, "1");
    outtextxy(140, 216, "+");
    puthz(160, 220, "�޹�����", 16, 18, RED);
    puthz(40, 270, "���ò�", 16, 18, DARKGRAY);
    outtextxy(110, 266, t.economy_price);
    setfillstyle(SOLID_FILL, BLUE);
    bar(170, 270, 186, 286);
    puthz(300, 270, "�����", 16, 18, DARKGRAY);
    outtextxy(370, 266, t.business_price);
    rectangle(420, 270, 436, 286);
    puthz(40, 320, "Ԥ���Ƶ�", 16, 18, BLUE);

    setcolor(LIGHTCYAN);
    rectangle(70, 410, 200, 440);
    puthz(100, 414, "����", 24, 46, 8);
    rectangle(440, 410, 570, 440);
    puthz(470, 414, "֧��", 24, 46, 8);
    rectangle(255, 410, 385, 440);
    puthz(266, 414, "ɨ��֧��", 24, 28, 8);
}

/***********************************
FUNCTION: purchace_confirm_draw
DESCRIPTION: ��Ϣȷ�Ͻ������
INPUT: *u,t
RETURN: ��
***********************************/
void purchace_confirm_draw(USER *u, Ticket t)
{
    cleardevice();
    clrmous(MouseX, MouseX);
    delay(30);
    setbkcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    settextjustify(LEFT_TEXT, TOP_TEXT);

    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(1, 0, 639, 65);

    puthz(240, 22, "��Ϣȷ��", 32, 40, 4);
    puthz(240 + 2, 22 + 2, "��Ϣȷ��", 32, 40, 5);

    //��Ʊ��Ϣ��
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(100, 90, 540, 190);
    setcolor(BLUE);
    outtextxy(110, 100, t.number);
    puthz(190, 104, t.company, 16, 18, BLUE);
    setfillstyle(SOLID_FILL, RED);
    bar(180, 144, 420, 158);
    setcolor(RED);
    line(420, 141, 420, 161);
    line(420, 141, 450, 151);
    line(420, 161, 450, 151);
    delay(30);
    //    floodfill(421, 151, RED);
    setcolor(BROWN);
    rectangle(100, 90, 540, 190);
    rectangle(100 - 1, 90 - 1, 540 + 1, 190 + 1);
    puthz(110, 140, t.city1, 24, 28, DARKGRAY);
    setcolor(GREEN);
    outtextxy(114, 168, t.launch_time);
    puthz(470, 140, t.city2, 24, 28, DARKGRAY);
    outtextxy(474, 168, t.land_time);
    outtextxy(280, 158, t.distance);
    //  printf("%s\n",t.distance);

    puthz(100, 194, "��������Ϣ������ǰ�����������޸�", 16, 18, LIGHTGREEN);

    //������Ϣ��
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(100, 220, 540, 370);
    setcolor(BROWN);
    rectangle(100, 220, 540, 370);
    rectangle(100 - 1, 220 - 1, 540 + 1, 370 + 1);
    setcolor(BLUE);
    puthz(104, 233, "�û���", 24, 28, DARKGRAY);
    outtextxy(200, 231, u->name);
    puthz(104, 283, "���֤��", 24, 28, DARKGRAY);
    //   printf("%s\n",u->id);
    outtextxy(220, 281, u->id);
    puthz(104, 333, "����״̬", 24, 28, DARKGRAY);
    //    printf("%s\n",u->health_code);
    if (strcmp(u->health_code, "0") == 0)
    {
        puthz(220, 337, "δ�", 16, 18, BLUE);
    }
    else if (strcmp(u->health_code, "1") == 0)
    {
        puthz(220, 337, "����", 16, 18, BLUE);
    }
    else if (strcmp(u->health_code, "2") == 0)
    {
        puthz(220, 337, "����", 16, 18, BLUE);
    }
    else if (strcmp(u->health_code, "3") == 0)
    {
        puthz(220, 337, "����", 16, 18, BLUE);
    }

    setcolor(LIGHTCYAN);
    rectangle(100, 400, 230, 430);
    puthz(130, 404, "ȷ��", 24, 46, 8);

    rectangle(410, 400, 540, 430);
    puthz(440, 404, "����", 24, 46, 8);
}