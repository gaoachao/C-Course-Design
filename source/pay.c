#include <stdio.h>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#include "mouse.h"
#include "hz.h"
#include "database.h"
#include "pay.h"
#include "login.h"

/***********************************
FUNCTION: codepay_main
DESCRIPTION: 扫码支付主函数
INPUT: *name,*number,*price,hold
RETURN: 无
***********************************/
int codepay_main(char *name, char *number, char *price, Hold hold)
{
    int num = 0;
    FILE *fp;
    char file_hold[30] = "\0";

    codepaypage_draw(name, number, price);
    strcpy(file_hold, "database\\");
    strcat(file_hold, name);
    strcat(file_hold, "\\hold.dat");

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //扫码支付键
        if (MouseX > 300 && MouseX < 400 && MouseY > 280 && MouseY < 310)
        {
            if (mouse_press(300, 280, 400, 310) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    num = 1;
                    lightup_codepay_page(300, 280, 400, 310, 1);
                }

                continue;
            }
            else if (mouse_press(300, 280, 400, 310) == 1)
            {
                if ((fp = fopen(file_hold, "rb+")) == NULL)
                {
                    printf("%s open failed\n", file_hold);
                    delay(3000);
                    exit(1);
                }
                //                fseek(fp, 0, SEEK_END);
                //                len = ftell(fp) / sizeof(Hold); //计算已持有机票数
                fseek(fp, 0, SEEK_END);
                fwrite(&hold, sizeof(Hold), 1, fp); //写入机票信息
                if (fclose(fp) != 0)
                {
                    printf("%s close failed\n", file_hold);
                    delay(3000);
                    exit(1);
                }
                code_scan();
                puthz(300, 340, "购票成功！", 24, 30, GREEN);
                delay(2000);
                //*func=4;

                return 1;
            }
        }

        //返回键
        if (MouseX > 450 && MouseX < 550 && MouseY > 280 && MouseY < 310)
        {
            if (mouse_press(450, 280, 550, 310) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    num = 2;
                    lightup_codepay_page(450, 280, 550, 310, 2);
                }
                continue;
            }
            else if (mouse_press(450, 280, 550, 310) == 1)
            {
                num = 0;
                recoverbuttom_codepay_page(450, 280, 550, 310, 2);
                return 2;
            }
        }

        if (num != 0)
        {
            if (num == 1)
            {
                recoverbuttom_codepay_page(300, 280, 400, 310, 1);
            }
            if (num == 2)
            {
                recoverbuttom_codepay_page(450, 280, 550, 310, 2);
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
FUNCTION: code_scan
DESCRIPTION: 扫码动画函数
INPUT: 无
RETURN: 无
***********************************/
void code_scan(void)
{
    int i, j;
    unsigned int size;
    void *pt_addr;

    clrmous(MouseX, MouseY);

    setlinestyle(0, 0, 4);
    setcolor(RED);
    line(60, 120, 270, 120);

    size = imagesize(60, 120, 270, 120);
    if ((pt_addr = malloc(size)) == NULL)
    {
        exit(1);
    }
    getimage(60, 120, 270, 120, pt_addr);

    setcolor(WHITE);
    line(60, 120, 270, 120);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j + 120 < 330; j += 2)
        {
            putimage(60, 120 + j, pt_addr, XOR_PUT);
            delay(25);
            putimage(60, 120 + j, pt_addr, XOR_PUT);
        }
    }
    free(pt_addr);
}

/***********************************
FUNCTION: pay_main
DESCRIPTION: 扫码支付主函数
INPUT: u,hold,*price
RETURN: 无
***********************************/
int pay_main(USER u, Hold hold, char *price)
{
    int num = 0;
    int state1 = 0;
    int error = 0;
    char password[13];
    FILE *fp;
    char file_hold[30] = "\0";

    paypage_draw(u.name, hold.number, price);
    memset(password, '\0', sizeof(password));
    strcpy(file_hold, "database\\");
    strcat(file_hold, u.name);
    strcat(file_hold, "\\hold.dat");

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //支付键
        if (MouseX > 300 && MouseX < 400 && MouseY > 280 && MouseY < 310)
        {
            if (mouse_press(300, 280, 400, 310) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    num = 1;
                    lightup_codepay_page(300, 280, 400, 310, 3);
                }
                continue;
            }
            else if (mouse_press(300, 280, 400, 310) == 1)
            {
                setcolor(RED);
                //                outtextxy(1, 1, password);
                //                outtextxy(1, 30, u.bankpassword);
                if (strcmp(password, u.bankpassword) == 0)
                {
                    if ((fp = fopen(file_hold, "rb+")) == NULL)
                    {
                        printf("%s open failed\n", file_hold);
                        delay(3000);
                        exit(1);
                    }
                    fseek(fp, 0, SEEK_END);
                    fwrite(&hold, sizeof(Hold), 1, fp); //写入机票信息
                    if (fclose(fp) != 0)
                    {
                        printf("%s close failed\n", file_hold);
                        delay(3000);
                        exit(1);
                    }

                    setfillstyle(SOLID_FILL, WHITE);
                    bar(320, 212, 400, 240);
                    puthz(300, 340, "购票成功！", 24, 30, GREEN);
                    delay(2000);

                    return 1;
                }
                else
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(320, 211, 400, 240);
                    puthz(320, 212, "密码错误", 16, 18, RED);
                    error++;
                }
            }
        }

        //返回键
        if (MouseX > 450 && MouseX < 550 && MouseY > 280 && MouseY < 310)
        {
            if (mouse_press(450, 280, 550, 310) == 2)
            {
                MouseS = 1;
                if (num == 0)
                {
                    num = 2;
                    lightup_codepay_page(450, 280, 550, 310, 2);
                }
                continue;
            }
            else if (mouse_press(450, 280, 550, 310) == 1)
            {
                num = 0;
                recoverbuttom_codepay_page(450, 280, 550, 310, 2);
                return 2;
            }
        }

        //输入框
        if (MouseX > 320 && MouseX < 540 && MouseY > 180 && MouseY < 210)
        {
            if (mouse_press(320, 180, 540, 210) == 2)
            {
                MouseS = 1;
                if (num == 0 && state1 == 0)
                {
                    lightup_codepay_page(320, 180, 540, 210, 0);
                    num = 3;
                }
                continue;
            }
            else if (mouse_press(320, 180, 540, 210) == 1)
            {
                MouseS = 1;
                lightup_codepay_page(320, 180, 540, 210, 0);
                memset(password, '\0', sizeof(password));
                inputpassword(password, 320, 180, 12, LIGHTGRAY);
                if (strlen(password) == 0)
                {
                    state1 = 0;
                }
                else
                {
                    state1 = 1;
                }
            }
        }

        if (num != 0)
        {
            if (num == 1)
            {
                recoverbuttom_codepay_page(300, 280, 400, 310, 3);
            }
            if (num == 2)
            {
                recoverbuttom_codepay_page(450, 280, 550, 310, 2);
            }
            if (num == 3 && state1 == 0)
            {
                recoverbuttom_codepay_page(320, 180, 540, 210, 0);
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
FUNCTION: lightup_codepay_page
DESCRIPTION: 扫码支付界面按钮点亮
INPUT: x1,y1,x2,y2.flag
RETURN: 无
***********************************/
void lightup_codepay_page(int x1, int y1, int x2, int y2, int flag)
{
    clrmous(MouseX, MouseY);
    delay(10);
    setcolor(LIGHTRED);
    //    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setfillstyle(1, LIGHTGRAY);

    bar(x1, y1, x2, y2);                       //填充内部
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1); //画边框
    if (flag != 0)
    {
        switch (flag)
        {
        case 1:
        {
            puthz(312, 283, "扫码", 24, 46, RED);
            break;
        }

        case 2:
        {
            puthz(462, 283, "返回", 24, 46, RED);
            break;
        }

        case 3:
        {
            puthz(312, 283, "支付", 24, 46, RED);
            break;
        }

        default:
            printf("something wrong in loghtup_purchace_confirm\n");
            break;
        }
    }
}

void recoverbuttom_codepay_page(int x1, int y1, int x2, int y2, int flag)
{
    clrmous(MouseX, MouseY);
    delay(30);

    setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x1, y1, x2, y2);
    rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1);

    if (flag != 0)
    {
        switch (flag)
        {
        case 1:
        {
            puthz(312, 283, "扫码", 24, 46, DARKGRAY);
            break;
        }

        case 2:
        {
            puthz(462, 283, "返回", 24, 46, DARKGRAY);
            break;
        }

        case 3:
        {
            puthz(312, 283, "支付", 24, 46, DARKGRAY);
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
}

/***********************************
FUNCTION: paypage_draw
DESCRIPTION: 银行支付界面绘制
INPUT: *name,*number,*price
RETURN: 无
***********************************/
void paypage_draw(char *name, char *number, char *price)
{
    cleardevice();
    clrmous(MouseX, MouseY);
    delay(30);
    setbkcolor(WHITE);

    setcolor(BLUE);
    puthz(40, 100, "用户名", 16, 18, DARKGRAY);
    outtextxy(110, 96, name);
    puthz(40, 140, "航班号", 16, 18, DARKGRAY);
    outtextxy(110, 136, number);
    puthz(40, 180, "需支付", 16, 18, DARKGRAY);
    outtextxy(110, 176, price);

    puthz(320, 130, "输入银行卡密码", 16, 18, BLUE);
    setcolor(LIGHTGRAY);
    rectangle(320, 180, 540, 210);

    setfillstyle(SOLID_FILL, WHITE);
    setcolor(LIGHTCYAN);
    bar(300, 280, 400, 310);
    rectangle(300, 280, 400, 310);
    bar(450, 280, 550, 310);
    rectangle(450, 280, 550, 310);
    puthz(312, 283, "支付", 24, 46, DARKGRAY);
    puthz(462, 283, "返回", 24, 46, DARKGRAY);
}

/***********************************
FUNCTION: codepaypage_draw
DESCRIPTION: 扫码支付界面绘制
INPUT: *name,*number,*price,hold
RETURN: 无
***********************************/
void codepaypage_draw(char *name, char *number, char *price)
{
    int i, m, n;
    cleardevice();
    setbkcolor(WHITE);
    clrmous(MouseX, MouseY);
    delay(30);

    setcolor(BLUE);
    puthz(320, 130, "用户名", 16, 18, DARKGRAY);
    outtextxy(390, 126, name);
    puthz(320, 170, "航班号", 16, 18, DARKGRAY);
    outtextxy(390, 166, number);
    puthz(320, 210, "需支付", 16, 18, DARKGRAY);
    outtextxy(390, 206, price);
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(LIGHTCYAN);
    bar(300, 280, 400, 310);
    rectangle(300, 280, 400, 310);
    bar(450, 280, 550, 310);
    rectangle(450, 280, 550, 310);
    puthz(312, 283, "扫码", 24, 46, DARKGRAY);
    puthz(462, 283, "返回", 24, 46, DARKGRAY);
    srand(time(NULL));
    for (m = 0; m < 38; m++)
    {
        for (n = 0; n < 38; n++)
        {
            i = rand() % 20;
            if (i < 10)
            {

                setcolor(GREEN);
                setfillstyle(SOLID_FILL, GREEN);
                bar(70 + m * 5, 130 + n * 5, 70 + (m + 1) * 5, 130 + (n + 1) * 5);
                setcolor(WHITE);
                setfillstyle(SOLID_FILL, WHITE);
                bar(69, 129, 121, 181);
                bar(69, 269, 121, 321);
                bar(209, 129, 261, 181);
                setcolor(GREEN);
                setfillstyle(SOLID_FILL, GREEN);
                bar(70, 130, 120, 180);
                bar(70, 270, 120, 320);
                bar(210, 130, 260, 180);
                setcolor(WHITE);
                setfillstyle(SOLID_FILL, WHITE);
                bar(80, 140, 110, 170);
                bar(80, 280, 110, 310);
                bar(220, 140, 250, 170);
                setcolor(GREEN);
                setfillstyle(SOLID_FILL, GREEN);
                bar(90, 150, 100, 160);
                bar(90, 290, 100, 300);
                bar(230, 150, 240, 160);
            }
        }
    }
    setcolor(BROWN);
    line(50, 110, 100, 110);
    line(50, 110, 50, 160);
    line(230, 110, 280, 110);
    line(280, 110, 280, 160);
    line(230, 340, 280, 340);
    line(280, 340, 280, 270);
    line(50, 340, 100, 340);
    line(50, 340, 50, 270);
}