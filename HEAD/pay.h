#ifndef _PAY_H_
#define _PAY_H_

void codepaypage_draw(char *name, char *number, char *price); //ɨ�빺Ʊ�������

int codepay_main(char *name, char *number, char *price, Hold hold); //ɨ�빺Ʊ������

void paypage_draw(char *name, char *number, char *price); //���п���Ʊ�������

int pay_main(USER u, Hold hold, char *price); //���п���Ʊ������

void lightup_codepay_page(int x1, int y1, int x2, int y2, int flag);

void recoverbuttom_codepay_page(int x1, int y1, int x2, int y2, int flag);

void code_scan(void);

#endif