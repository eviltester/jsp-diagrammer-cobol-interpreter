
/*===================================*
 *        SYSTEM.H                   *
 * the system functions              *
 *===================================*/

#ifndef SYSTEM
#define SYSTEM

#include "structs.h"
#include "drawprim.h"
#include "treebox.h"
#include "alpro.h"
#include <stdio.h>

/*******
********     FUNCTION DEFINITIONS
********/
extern void prntree(BOX *,TREE *);
extern void parse(TREE *);
extern void print_sizes(void);
extern void draw_tree(BOX *,int,int);
extern void draw_from(BOX *,int,int,int *,int *,int,int,int,int);


#endif


