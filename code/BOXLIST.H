
/*=====================================================*
 *                  BOXLIST.H                          *  
 * The formal spec for linked list used in boxlist     *
 * and the external declarations of the functions used *
 *=====================================================*/

#ifndef BOXLISTDEFn
#define BOXLISTDEFn
#include <stdio.h>
#include "structs.h"
#include "box.h"

/******************************************************************
*******************************************************************
sort            linked_list
based on        int,type
  (*      type * linked_list -> linked_list  *)


(c)    NEWLIST:                           ->      linked_list
(c)    ADDLIST:       type x linked_list  ->      linked_list
       DELETE_NODE:         linked_list ->
       DELETE_FROM_LIST:   type x linked_list   ->      linked_list
       ADD_AT:      int x type x linked_list    ->      linked_list
       APPEND:      linked_list x linked_list   ->      linked_list
       POSITION_IN: type x linked_list      ->      linked_list
       OVERWRITE_AT:int x type x linked_list  ->      linked_list
       JOIN_LISTS:  linked_list x linked_list x int -> linked_list
(*      currently not implemented *)
       GET_AT:      int x linked_list       ->      type
       UNITLIST:    type                    ->      linked_list
*******************************************************************
******************************************************************/


extern BOXLIST *create_boxlist(void);
extern BOXLIST *delete_from_list(BOX *,BOXLIST *);
extern BOXLIST *join_box_lists(BOXLIST *,BOXLIST *,int);
extern int position_in(BOX *,BOXLIST *);
extern int pos_in(BOX *,BOXLIST *,int);
extern BOXLIST *append(BOXLIST *,BOXLIST *);
extern BOXLIST *add_at(int,BOX *,BOXLIST *);
extern BOXLIST *overwrite_at(int,BOX *,BOXLIST *);
extern void scrub_boxlist(BOXLIST *);

#endif


