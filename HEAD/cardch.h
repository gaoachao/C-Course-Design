#ifndef _CARDCH_H_
#define _CARDCH_H_
#include"database.h"

void cardchange_main(int *func, USER *u);
void cardchange_draw(void);
void cardinfo(USER *u);
void input_newcard(USER *u, char *new_bank);
void input_newcardpassword(USER *u, char *new_cardpassword);

#endif
