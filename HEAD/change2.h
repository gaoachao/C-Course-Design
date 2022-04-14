#ifndef _CHANGE2_H_
#define _CHANGE2_H_

void change2_main(int *func,USER *u); //ÖØÖÃÃÜÂëÖ÷º¯Êı
void input_password(USER *u, char *new_password);
void lightup_change2(int x1, int y1, int x2, int y2, int flag);
void recoverbuttom_change2(int x1, int y1, int x2, int y2, int flag);
void change2_draw(void);
int confirm_password2(char *str1,char *str2);


#endif