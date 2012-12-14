
/*========================================================*
 *              TREEBOX.H                                 *
 * contains all the functions relating to trees and boxes *
 * that were too general to fit into tree.h or box.h      *
 *========================================================*/

#ifndef BOXFns
#define BOXFns

#include <stdio.h>
#include "tree.h"

/********
*********       FUNCTION DEFINITIONS
*********/

extern void renumber_from(TREE *);
extern int renumber(BOX *,int);

extern BOX *find_box(int,TREE *);
extern BOX *find(int,BOX *);

extern BOX *create_box(void);

extern int create_under(int,TREE *);
extern void add_under(BOX *,BOX *,TREE *);

extern int create_right(int,TREE *);
extern void add_right(BOX *,BOX *,TREE *);

extern int create_left(int,TREE *);
extern void add_left(BOX *,BOX *,TREE *);

extern int create_above(int,TREE *);
extern void add_above(BOX *,BOX *,TREE *);

extern BOX *get_parent(BOX *,TREE *);
extern BOX *getparent(BOX *,BOX *,TREE *);

extern BOXLIST *get_boxlist(BOX *,TREE *);

extern void delete(int,TREE *);
extern void delbox(BOX *,TREE *);
extern void delbox2(BOX *,TREE *);
extern void delete_range(int,int,TREE *);
#endif


