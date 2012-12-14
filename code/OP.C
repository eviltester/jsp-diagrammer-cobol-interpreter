
/*============================================
 *            OP.C                           *
 *                                           *
 * This file contains the functions          *
 * for the jsp operations on the diagrammer  *
 *===========================================*/
#include "op.h"



/*******
********        FUNCTIONS
********/

/*=====================================*
 * create_op allocates space for an op *
 *=====================================*/
OPLIST *create_op()
{
        OPLIST *opy;

        if((opy=(OPLIST *)malloc(sizeof(OPLIST)))==NULL)
                        fatal_error("no more room for oplist");

        opy->op_num=0;
        opy->next_op=NULL;

        return opy;
}


