\begin{verbatim}
/*=======================================================*
 *                     TRACE.H                           *
 * define the trace structure and the debugger functions *
 *=======================================================*/

#ifndef TRACEYH
#define TRACEYH

#include <stdio.h>
#include "ops.h"
#include "conds.h"
#include "alpro.h"

/* a run consists of the current box, the last box number visited *
 * the current op, the op number position in the list, the current*
 * tree, current symbol table, current op array, and the finished *
 * indicator                                                      */

struct run_info{
                 BOX *current_box;
                 int last_box_num;
                 OPLIST *current_op;
                 int op_num;
                 TREE *current_tree;
                 SYMTAB_ENTRY **current_symbols;
                 COND **current_conds;
                 OP_LIST_LIST **current_ops;
                 int finished;
               };

typedef struct run_info RUN_INFO;

extern RUN_INFO *create_run(TREE *,SYMTAB_ENTRY **,COND **,OP_LIST_LIST **);
extern void reset_run(RUN_INFO *);
extern int get_next_op(RUN_INFO *);
extern int next_op(RUN_INFO *);
extern int next_box_from(RUN_INFO *);
extern int get_next_op(RUN_INFO *);

#endif

\end{verbatim}                    
  
