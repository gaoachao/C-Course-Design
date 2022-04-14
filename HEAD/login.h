#ifndef _LOGIN_H_
#define _LOGIN_H_
#include "database.h"

void inputadmin(char *id, int x1, int y1, int charnum, int color);
void login_page(void);
void login_main(int *func, USER *u);
void lightup_login(int x1, int y1, int x2, int y2, int flag);
void recoverbuttom_login(int x1, int y1, int x2, int y2, int flag);
void inputpassword(char *id, int x1, int y1, int charnum, int color);
void vertification_code(int x1, int y1, int x2, int y2, int color, char *str);
int input_judge(char *str, int x, int y);
int name_password_login(char *name, char *password);
int vcode_judge(char *str, char *vcode);
int login_judge(USER *u, char *str, char *vcode);
void userinfo_read(USER *u);

#endif