
/*==============================================================*
 *                DRAWPRIM.H                                    * 
 * declares the global variables used by the drawing primitives *
 * and externally declares the primitives themselves            *
 *==============================================================*/

#ifndef DRAW
#define DRAW

#include <vdi.h>  /* the gem/ST drawing routines */

extern void start_gem(void);
extern void stop_gem(void);
extern void draw_line(int,int,int,int);
extern void draw_box(int,int,int);


/* atari st gem stuff */

int contrl[12];
int intin[128];
int ptsin[128];
int intout[128];
int ptsout[128];

short handle;
short workin[11]={1,1,1,1,1,1,1,1,1,1,2},workout[57];
short co_ord[10];

#endif


