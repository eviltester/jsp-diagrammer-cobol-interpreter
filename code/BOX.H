
/*===================================================*
 *             BOX.H                                 *
 * external definitions of the functions that act on *
 * the box structure of the diagrammer               *
 *===================================================*/ 

#ifndef BOXF
#define BOXF
#include <stdio.h>
#include "structs.h"

/********
*********       FUNCTION DEFINITIONS
*********/
extern void box_print(BOX *);
extern void name_box(BOX *,char *);
extern void make_root(BOX *);
extern BOX *create_box(void);
extern void scrub_box(BOX *);
extern void edit_box(BOX *,TREE *);


#endif

