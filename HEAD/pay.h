#ifndef _PAY_H_
#define _PAY_H_

void codepaypage_draw(char *name, char *number, char *price); //扫码购票界面绘制

int codepay_main(char *name, char *number, char *price, Hold hold); //扫码购票主函数

void paypage_draw(char *name, char *number, char *price); //银行卡购票界面绘制

int pay_main(USER u, Hold hold, char *price); //银行卡购票主函数

void lightup_codepay_page(int x1, int y1, int x2, int y2, int flag);

void recoverbuttom_codepay_page(int x1, int y1, int x2, int y2, int flag);

void code_scan(void);

#endif