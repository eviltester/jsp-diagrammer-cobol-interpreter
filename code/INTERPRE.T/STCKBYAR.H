
/*==================================================*
 *             STCKBYAR.H                           *
 * the functions for a stack by array in c based on *
 * formal spec presented by K. Barclay              *
 *==================================================*/
#ifndef STCKBYAR
#define STCKBYAR

#include "node.h"
#include <stdio.h>

typedef struct{
                NODE **array;
                int stack_max_size;
                int stack_curr_size;
              }STACKBYARRAY;

/* POP REMOVES THE TOP OF STACK */

extern STACKBYARRAY *stackpop(STACKBYARRAY *);
extern NODE *stacktop(STACKBYARRAY *);
extern STACKBYARRAY *stackpush(STACKBYARRAY *,NODE *);
extern STACKBYARRAY *create_stack_by_array(int);

#endif

