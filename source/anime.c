#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h> #include<dos.h>
#define IMAGE_SIZE 10

void plane(int x, int y)
{
    arc(x, y, 90, 270, 5);
    line(x, y + 5, x + 35, y + 5);
    line(x, y - 5, x + 25, y - 5);
    line(x + 25, y - 5, x + 35, y + 5);

    line(x + 20, y, x + 12, y);
    line(x + 12, y - 15, x + 12, y);
    line(x + 12, y - 15, x + 17, y - 15);
    line(x + 17, y - 15, x + 20, y);

    line(x, y - 5, x - 4, y - 13);
    line(x - 4, y - 13, x - 1, y - 13);
    line(x - 1, y - 13, x + 5, y - 5);
}

int main()
{
    int gd = VGA;
    int gm = VGAHI;
    void *pt_addr;
    //  int x, y, maxx, maxy, midy, midx, i;
    unsigned int size;
    int i, m, n, j;
    initgraph(&gd, &gm, "C:\\code\\BGI");
    setbkcolor(LIGHTBLUE);
    setcolor(WHITE);

    plane(320,200);
    plane(1,1);

/*    arc(x, y, 90, 270, 5);
    line(x, y + 5, x + 35, y + 5);
    line(x, y - 5, x + 25, y - 5);
    line(x + 25, y - 5, x + 35, y + 5);

    line(x + 20, y, x + 12, y);
    line(x + 12, y - 15, x + 12, y);
    line(x + 12, y - 15, x + 17, y - 15);
    line(x + 17, y - 15, x + 20, y);

    line(x, y - 5, x - 4, y - 13);
    line(x - 4, y - 13, x - 1, y - 13);
    line(x - 1, y - 13, x + 5, y - 5);*/

    //    cleardevice();

    getch();
    closegraph();
    return 0;
}
//    clrmous(MouseX, MouseY);
/*    delay(30);

    setcolor(BLUE);
    //    puthz(x, 130, "用户名", 16, 18, DARKGRAY);
    outtextxy(390, 126, "long");
    //    puthz(x, 170, "航班号", 16, 18, DARKGRAY);
    outtextxy(390, 166, "number");
    //    puthz(x, 210, "需支付", 16, 18, DARKGRAY);
    outtextxy(390, 206, "1536");
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(LIGHTCYAN);
    bar(300, 280, 400, 310);
    rectangle(300, 280, 400, 310);
    bar(450, 280, 550, 310);
    rectangle(450, 280, 550, 310);
    //    puthz(312, 283, "扫码", 24, 46, DARKGRAY);
    //    puthz(462, 283, "返回", 24, 46, DARKGRAY);
    setcolor(RED);
    line(60, 120, 270, 120);
    size = imagesize(60, 120, 270, 120);
    pt_addr = malloc(size);
    getimage(60, 120, 270, 120, pt_addr);
    setcolor(WHITE);
    line(60, 120, 270, 120);
    srand(time(NULL));
    for (m = 0; m < 38; m++)
    {
        for (n = 0; n < 38; n++)
        {
            i = rand() % 20;
            if (i < 10)
            {

                setcolor(DARKGRAY);
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
                bar(70, 270, 120, x);
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

    delay(y0);
    setcolor(BROWN);
    line(50, 110, 100, 110);
    line(50, 110, 50, 160);
    line(230, 110, 280, 110);
    line(280, 110, 280, 160);
    line(230, x+20, 280, x+20);
    line(280, x+20, 280, 270);
    line(50, x+20, 100, x+20);
    line(50, x+20, 50, 270);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j + 120 < 330; j += 2)
        {
            putimage(60, 120 + j, pt_addr, XOR_PUT);
            delay(25);
            putimage(60, 120 + j, pt_addr, XOR_PUT);
        }
    }
    //    line()
    free(pt_addr);
    getch();
    closegraph();
    return 0;
}

/*void draw_image(int x, int y);
void Putstar(void);


int main()
{
    int gd = VGA;
    int gm = VGAHI;
    void *pt_addr;
    int x, y, maxx, maxy, midy, midx, i;
    unsigned int size;
    initgraph(&gd, &gm, "C:\\code\\BGI");
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    x = 0;
    midy = y = maxy / 2;
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(midx, 400, "AROUND THE WORLD");
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    ellipse(midx, midy, 130, 50, 160, 30);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    draw_image(x, y);
    size = imagesize(x, y - IMAGE_SIZE, x + 4 * IMAGE_SIZE, y + IMAGE_SIZE);
    pt_addr = malloc(size);
    getimage(x, y - IMAGE_SIZE, x + 4 * IMAGE_SIZE, y + IMAGE_SIZE,pt_addr);
    Putstar();
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, maxx, maxy);
    delay(1000);
    while (!kbhit())
    {
        Putstar();
        setcolor(RED);
        setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
        ellipse(midx, midy, 130, 50, 160, 30);
        setcolor(DARKGRAY);
        ellipse(midx, midy, 130, 50, 160, 30);
        for (i = 0; i <= 13; i++)
        {
            setcolor(i % 2 == 0 ? LIGHTBLUE : DARKGRAY);
            ellipse(midx, midy, 0, 360, 100, 100 - 8 * i);
            setcolor(LIGHTBLUE);
            ellipse(midx, midy, 0, 360, 100 - 8 * i, 100);
        }
        putimage(x, y - IMAGE_SIZE, pt_addr, XOR_PUT);
        x = x > +maxx ? 0 : x + 6;
        putimage(x, y - IMAGE_SIZE, pt_addr, XOR_PUT);
    }
    delay(1000);
    getch();
    free(pt_addr);
    closegraph();
    return 0;
}

void draw_image(int x, int y)
{
    int arw[11];
    arw[0] = x + 10;
    arw[1] = y - 10;
    arw[2] = x + 34;
    arw[3] = y - 6;
    arw[4] = x + 34;
    arw[5] = y + 6;
    arw[6] = x + 10;
    arw[7] = y + 10;
    arw[9] = x + 10;
    arw[10] = y - 10;
    moveto(x + 10, y - 4);
    setcolor(14);
    setfillstyle(1, 4);
    linerel(-3 * 10, -2 * 8);
    moveto(x + 10, y + 4);
    linerel(-3 * 10, +2 * 8);
    moveto(x + 10, y);
    linerel(-3 * 10, 0);
    setcolor(3);
    setfillstyle(1, LIGHTBLUE);
    fillpoly(4, arw);
}

void Putstar(void)
{
    int seed=y-158;
    int i,dotx,doty,h,w,color,maxcolor;
    maxcolor=getmaxcolor();
    w=getmaxx();
    h=getmaxy();
    srand(seed);
    for(i=0;i<250;i++)
    {
        dotx=i+rand()%w;
        doty=i+rand()%h;
        color=rand()%maxcolor;
        setcolor(color);
        putpixel(dotx,doty,color);
        circle(dotx+1,doty+1,1);
    }
    srand(seed);
}*/