
/*=================================================================*
 *                 DRAWPRIM.C                                      *
 * the system drawing primitives, they are declared                *
 * here so that the drawing can be ported to any system            *
 * by changing the actual contents of the functions and the header *
 * this remains unfinished since there is no clear screen function *
 * and the jsp box is drawn as a square rather than a rectangle,   *
 * but development stopped early on in the project timescale       *
 *=================================================================*/

#include "drawprim.h"


/*=====================================================================*
 * The graphic system is initialised, in this case GEM on the ATARI ST *
 *=====================================================================*/
void start_gem()
{
        short junk;
        appl_init();
        handle=graf_handle(&junk,&junk,&junk,&junk);
        v_opnvwk(workin,&handle,workout);

}

/*===================================*
 * the graphic system is closed down *
 *===================================*/
void stop_gem()
{
        v_clrwk(handle);
        appl_exit();

}

/*==================================================*
 * a non relative line draw from (x1,y1) to (x2,y2) *
 *==================================================*/
void draw_line(int x1,int y1,int x2,int y2)
{
                co_ord[0]=x1;
                co_ord[1]=y1;
                co_ord[2]=x2;
                co_ord[3]=y2;
                v_pline(handle,2,co_ord);
}

/*====================================*
 * draw a box at (x1,y1) of size size *
 *====================================*/
void draw_box(x1,y1,size)
        int x1,y1,size;
{
                   
        co_ord[0]=x1;
        co_ord[1]=y1;
        co_ord[2]=x1+size;
        co_ord[3]=y1;
        co_ord[4]=x1+size;
        co_ord[5]=y1+size;
        co_ord[6]=x1;
        co_ord[7]=y1+size;
        co_ord[8]=x1;
        co_ord[9]=y1;
        v_pline(handle,5,co_ord);
}


