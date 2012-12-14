\begin{verbatim}
/*============================================*
 *                       TRACE.C              *
 * all the trace functions                    *
 *============================================*/

#include "trace.h"

/*============================================================*
 * create_run allocates space for run details, and initialise *
 * the values                                                 *
 *============================================================*/
RUN_INFO *create_run(TREE *tree,SYMTAB_ENTRY **symtab,
                     COND **cond_array,OP_LIST_LIST **ops_array)
{
    RUN_INFO *run;

        if((run=(RUN_INFO *)malloc(sizeof(RUN_INFO)))==NULL)
                fatal_error("no more room for run info");

    
    run->current_box=tree->root;
    run->last_box_num=0;
    run->current_op=tree->root->op;
    run->op_num=0;
    run->current_tree=tree;
    run->current_symbols=symtab;
    run->current_conds=cond_array;
    run->current_ops=ops_array;
    run->finished=0;

    return(run);
}

/*===========================================================*
 * reset_run returns all the run variables to their original *
 *===========================================================*/
void reset_run(RUN_INFO *run)
{
    run->current_box=run->current_tree->root;
    run->last_box_num=0;
    run->current_op=run->current_tree->root->op;
    run->op_num=0;
    reset_symtab(run->current_symbols,100);
    run->finished=0;
}

/*===============================================================*
 * get_next_op uses the current run details to determine whether *
 * another operation is available, and if so alters the run      *
 * details                                                       *
 *===============================================================*/
int get_next_op(RUN_INFO *info)
{
    BOXLIST *blp;

    /* if the current box has ops then check the box
       to see if there are any ops left to do */
    if(info->current_box->op!=NULL && next_op(info))
       {
        /* make this box the last visited box */
        info->last_box_num=info->current_box->box_number;
        return(1);
       }
    else
       {           /* box has kids*/
       if(info->current_box->children!=NULL)
         {
       
         /* if the current box is a selection then work
            through the children testing the conditions
            and if any pass then make that box the current
            and check it for ops */

         if(info->current_box->probench_box.box_type==SELECTION)
           {
            blp=info->current_box->children;
            while(blp!=NULL)
             {
              if(evaluate_condition(info->current_conds[
                                    blp->box->probench_box.cond_num]))
               {
                info->current_box=blp->box;
                info->last_box_num=blp->box->box_number;
                return(get_next_op(info));
               }
              blp=blp->link;
             }
           /* if none then work back to find the next box and
              check it for ops */
           if(next_box_from(info))
            return(get_next_op(info));
           else
             return(0);
           }

           /* if the box is an iteration then check the child's
              condition, if the negation of it succeeds then
              make the child the current box */
         if(info->current_box->probench_box.box_type==ITERATION)
           {
            blp=info->current_box->children;
              if(!evaluate_condition(info->current_conds[
                                     blp->box->probench_box.cond_num]))
               {
                info->current_box=blp->box;
                info->last_box_num=blp->box->box_number;
                return(get_next_op(info));
               }
           /* if none then work back to find the next box and
              check it for ops */
           if(next_box_from(info))
            return(get_next_op(info)); 
           else
             return(0);
          }
 
         /* if the box is a sequence then make the first child
            the current box, and check it */

        if(info->current_box->probench_box.box_type==SEQUENCE)
           {
            blp=info->current_box->children;
            info->current_box=blp->box;
            info->last_box_num=blp->box->box_number;
            return(get_next_op(info));
           }
         }
       else
           /* if none then work back to find the next box and
              check it for ops */
           if(next_box_from(info))
            return(get_next_op(info));
           else
             return(0);
      }
     return(0);
}

/*========================================================*
 * next_op uses the op_num of the run to find the next op *
 * and if there are none then return 0                    *
 *========================================================*/
int next_op(RUN_INFO *info)
{
    int next=info->op_num+1;
    OPLIST *box_ops;
    int loop;

    box_ops=info->current_box->op;

    for(loop=1;loop<next;loop++)
       {
        box_ops=box_ops->next_op;
        if(box_ops==NULL)
          {
           info->op_num=0;
           return(0);
          }
       }

    info->op_num=loop;
    info->current_op=box_ops;
    return(loop);
}

/*=====================================================*
 * work out which box is the next one when moving back *
 *=====================================================*/
int next_box_from(RUN_INFO *info)
{
    BOX *parent;
    BOXLIST *boxlp;

    /* get the parent */
    parent=get_parent(info->current_box,info->current_tree);

    /* if the current is the root then we are finished */
    if(info->current_box==info->current_tree->root)
        return(NULL);

    /* if the parent is an iteration then set the current
       to be the parent */
    if(parent->probench_box.box_type==ITERATION)
       {
        info->current_box=parent;
        info->last_box_num=info->current_box->box_number;
        return(1);
       }

    /* if the parent is a selection then set the current to be
       the parent and find the next box back from then */
    if(parent->probench_box.box_type==SELECTION)
       {
        info->current_box=parent;
        return(next_box_from(info));
       }

    /* the parent is a sequence then compare the child box
       numbers with the current box number until we either
       run out of boxes or we find a box with a number
       greater than the current.
       if we find a box greater then set it to be current */

    if(parent->probench_box.box_type==SEQUENCE)
       {
        boxlp=parent->children;

        while(boxlp!=NULL)
          {
           if(boxlp->box->box_number > info->current_box->box_number)
            {
             info->current_box=boxlp->box;
             return(1);
            }
           boxlp=boxlp->link;
          }

        /* no good children so set current to be the parent */
        info->current_box=parent;
        return(next_box_from(info));
       }
}

\end{verbatim}
