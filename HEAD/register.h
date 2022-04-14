#ifndef _REGISTER_H_
#define _REGISTER_H_
#include "database.h"

void register_main(int *func, USER *u);
void lightup_register(int x1, int y1, int x2, int y2, int flag);
void register_page(void);
void exit_buttom(void);
void inputadmin_database(char *name, char *password, char *id);
void recoverbuttom_register(int x1, int y1, int x2, int y2, int flag);
int confirm_password(char *str1, char *str2);
void confilm_password_state(int x, int y, int flag);
int name_judge(char *name, int x, int y);
int password_judge(char *password, int x, int y);
int password_confirm_judge(char *password, char *str, int x, int y);
int id_judge(char *id, int x, int y);
int duplicate_judge(char *name);
int register_complete_judge(char *name, char *password, char *id, char *str);

#endif