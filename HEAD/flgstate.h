#ifndef _FLGSTATE_H_
#define _FLGSTATE_H_
#include "database.h"

void state_consult_draw(void);

void state_consult_main(int *func, Ticket *t, int *flag);

void state_display(TNode *node, int flag, int page_rest);

void get_date(char *date);

void get_h_min(int *h, int *min);

void read_time(int *h, int *min, char *time);

int delay_judge(char *landtime, char *rate);

void delay_list_make(int *delay_list, Ticket *ticket_list, int len);

void ticket_cover_state(void);

void draw_plane(int x, int y);

void detail_consult_draw(Ticket t, int delay_state, int hour1, int min1);

void time_remain(int hour1, int min1, int hour2, int min2, char *remain);

void fly_pos(int hour1, int min1, int hour2, int min2, int hour3, int min3, float *percent);

void distance_remain(char *distance, float percent);

void detail_consult_main(int *func, Ticket t, int delay_state);

#endif