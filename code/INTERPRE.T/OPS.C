\begin{verbatim}
/*=============================================================*
 *               OPS.C                                         *
 * the functions relating to the operations in the interpreter *
 *=============================================================*/


#include "ops.h"

/*=============================================================*
 * create_op_list allocates enough space for an operation list *
 *=============================================================*/
OP_LIST *create_op_list()
    {
        OP_LIST *op=(OP_LIST *)malloc(sizeof(OP_LIST));

        if(op==NULL)
            fatal_error("NO room for OP_LIST");

        op->next=NULL;

        return(op);
    }


/*=======================================================*
 * create_op_list_list allocates enough space for a list *
 * of op_list's                                          *
 *=======================================================*/
OP_LIST_LIST *create_op_list_list()
    {
        OP_LIST_LIST *opl=(OP_LIST_LIST *)malloc(sizeof(OP_LIST_LIST));

        if(opl==NULL)
            fatal_error("NO room for OP_LIST_LIST");

        opl->op=NULL;
        opl->next=NULL;

        return(opl);
    }

/*===========================================================*
 * the op array is an array of pointers to lists of op_lists *
 * allocate anough space for one fixed size of 999           *
 *===========================================================*/
OP_LIST_LIST **create_op_array()
    {
        int loop;
        OP_LIST_LIST **otp=(OP_LIST_LIST **)malloc(sizeof(OP_LIST_LIST *)
                                                     *OP_ARRAY_SIZE);

        if(otp==NULL)
           fatal_error("no more room for op ARRAY");

        for(loop=0;loop<OP_ARRAY_SIZE;loop++)
           otp[loop]=NULL;

        return(otp);
    }

/*=========================================================*
 * save_ops_array is used because no programs are inverted *
 * loops through array saving ops in the format of         *
 * OP NUM                                                  *
 *   an op                                                 *
 *   any more ops                                          *
 *=========================================================*/
void save_ops_array(char *filename, OP_LIST_LIST **ops_array)
    {
     int loop;
     FILE *outfile=open_output(filename);
     TOKEN token;
     OP_LIST_LIST *opl;
     OP_LIST *op;


     for(loop=0;loop<OP_ARRAY_SIZE;loop++)
        {
         if(ops_array[loop]!=NULL)
           {
             opl=ops_array[loop];

             token.token_type=OP_NUM;
             token.value.keyword_number=loop;
             write_token(outfile,&token);

             while(opl->next!=NULL)
               {
                op=opl->op;
                while(op->next!=NULL)
                  {
                   save_op(outfile,op);
                   op=op->next;
                  }
                save_op(outfile,op);

                /* an operation is expected to end
                   in a fullstop */

                token.token_type=FULLSTOP;
                token.value.keyword_number=FULLSTOP;
                write_token(outfile,&token);

                opl=opl->next;
               }
               op=opl->op;
               while(op->next!=NULL)
                  {
                   save_op(outfile,op);
                   op=op->next;
                  }
               save_op(outfile,op);

               token.token_type=FULLSTOP;
               token.value.keyword_number=FULLSTOP;
               write_token(outfile,&token);
           }
        }
     close_file(outfile);
}

/*=========================================================*
 * save_op writes out the current part of the op_list_list *
 *=========================================================*/
void save_op(FILE *outfile,OP_LIST *op)
    {

     TOKEN token;

     if(op->type==OP_VERB)
         {
           token.token_type=KEYWORD;
           token.value.keyword_number=op->value.keyword_number;
         }

     if(op->type==OP_VAR)
         {
           token.token_type=VARIABLE_NAME;
           token.value.var_values.unique=
                   op->value.var_name->own.unique;
           token.value.var_values.hash=
                   op->value.var_name->own.hash;
         }

     if(op->type==OP_STRING)
         {
           token.token_type=NON_NUMERIC_LITERAL_LENGTH;
           token.value.keyword_number=
                             strlen(op->value.non_numeric_literal);
           write_token(outfile,&token);
           token.token_type=NON_NUMERIC_LITERAL;
           token.value.string=op->value.non_numeric_literal;
         }
 
     if(op->type==OP_NUM_LIT)
         {
           token.token_type=NUMERIC;
           token.value.keyword_number=op->value.numeric_literal;
         }

     write_token(outfile,&token);
   }


/*===========================================================*
 * load_ops_array loads in the operations from filename into *
 * op_array using symtab to find any variables               *
 *===========================================================*/
void load_ops_array(char *filename, OP_LIST_LIST **op_array,
                    SYMTAB_ENTRY **symtab)
    {
     FILE *infile=open_input(filename);
     TOKEN token;
     OP_LIST_LIST *opl;
     OP_LIST *op;
     int eof;
   

     eof=get_token(infile,&token);  /* get first op_num */

        while(!eof)
            {
             /*create space for op_list_list, stick op in place
               in the array */

             opl=create_op_list_list();
             op_array[token.value.keyword_number]=opl;

             /* get the first part of the first op */
             eof=get_token(infile,&token);
            
             op=load_op(infile,symtab,&token);
             opl->op=op;

             /* get rest */
             eof=get_token(infile,&token);

             while(token.token_type!=OP_NUM && !eof)
               {
                opl->next=create_op_list_list();
                op=load_op(infile,symtab,&token);
                opl=opl->next;
                opl->op=op;
                eof=get_token(infile,&token);
               }
             opl->next=NULL; /* do next */

            }
       close_file(infile);
}

/*================================================================*
 * load_op loads in a full op, and returns it to the op_list_list *
 *================================================================*/
OP_LIST *load_op(FILE *infile,SYMTAB_ENTRY **symtab,TOKEN *token)
    {

     int eof=0;
     NODE *node;
     OP_LIST *firstop=NULL,*op,*lastop;

     
            /* load in a full op, which end in a fullstop */
            while(token->token_type!=FULLSTOP && !eof)
               {
                op=create_op_list();

                if(firstop==NULL) 
                     firstop=op;
                else
                     lastop->next=op;

                if(token->token_type==KEYWORD)
                   {
                    op->value.keyword_number=token->value.keyword_number;
                    op->type=OP_VERB;
                   }

                if(token->token_type==VARIABLE_NAME)
                   {
                      op->type=OP_VAR;
                      node=look_for(token->value.var_values.unique,
                                    token->value.var_values.hash,
                                    symtab);
                      op->value.var_name=node;
                   }

                if(token->token_type==NON_NUMERIC_LITERAL)
                   {
                     op->type=OP_STRING;
                     op->value.non_numeric_literal=token->value.string;
                   }

                if(token->token_type==NUMERIC)
                   {
                    op->type=OP_NUM_LIT;
                    op->value.numeric_literal=token->value.keyword_number;
                   }
               lastop=op;
               eof=get_token(infile,token);
              }
      lastop->next=NULL;
      return(firstop);
    }
 
/*================================================*
 * display_operations loops through the ops_array *
 * for each op it displays the OP_NUM             *
 * followed by the statements                     *
 *================================================*/
void display_operations(OP_LIST_LIST **ops_array)
{
   int loop;

   for(loop=0;loop<OP_ARRAY_SIZE;loop++)
       {
        if(ops_array[loop]!=NULL)
            {
             printf("OP NUM %d\n",loop);
             display_operation(ops_array[loop]);
             printf("\n");
            }
       }
}

/*==================================================*
 * display_operation works through the op_list_list *
 * displaying each op_list on a new line            *
 *==================================================*/
void display_operation(OP_LIST_LIST *op_list_list)
{
    OP_LIST_LIST *opllp;
    OP_LIST *oplp;

    opllp=op_list_list;

    while(opllp!=NULL) /*work through op_list_list */
      {
       oplp=opllp->op;
       while(oplp!=NULL) /* work through op_list */
         {
          if(oplp->type==OP_NUM_LIT) /* display number */
             printf(" %d",oplp->value.numeric_literal);
          else{
              if(oplp->type==OP_STRING) /* display string */
                  printf(" %s",oplp->value.non_numeric_literal);
              else{
                   if(oplp->type==OP_VAR) /* display variable name */
                      printf(" %s",oplp->value.var_name->info->name);
                   else
                      if(oplp->type==OP_VERB) /* display verb number name */
                         printf(" %s",keyword_names[oplp->
                                            value.keyword_number]);
                  }
              }
          oplp=oplp->next;
         }
       opllp=opllp->next;
       printf("\n");
      }
}

/*=======================================================*
 * evaluate_operation works through a list of statements *
 * and carries each out in turn                          *
 *=======================================================*/
void evaluate_operation(OP_LIST_LIST *op_list_list)
{
    OP_LIST_LIST *opllp;
    OP_LIST *oplp;
    opllp=op_list_list;

    while(opllp!=NULL) /* work through list */
      {
       oplp=opllp->op;
       evaluate_op(oplp); /* evaluate statement */
       opllp=opllp->next;
      }
}

/*======================================================*
 * evaluate_op determines which type of operation to do *
 *======================================================*/
void evaluate_op(OP_LIST *op_list)
{
    OP_LIST *oplp;

    oplp=op_list;

    if(oplp->type!=OP_VERB)
       {
        printf("NOT VERB\n");
        exit();
       }
    else
       {
         switch(oplp->value.keyword_number)
           {
             case MOVE : do_move(oplp); break;
             case ADD  : do_add(oplp); break;
             case DISPLAY : do_display(oplp); break;
             default : printf("verb not implemented\n"); break;
           }
       }
}

void do_move(OP_LIST *op_list)
{

/* valid syntax
**
**   MOVE thing TO variable
**
**   only numeric moves so far 
**   between numeric literal and variable
**   and numeric variable and variable    */


    OP_LIST *oplp;
    int value;

    oplp=op_list;        /* skip verb MOVE */
    oplp=oplp->next;

    /* if the `thing' is a number then use the number
       otherwise use the variables contents */
    
    if(oplp->type==OP_NUM_LIT)               
       value=oplp->value.numeric_literal;
    else
       value=oplp->value.var_name->info->data_n;

    oplp=oplp->next;     /* skip keyword TO */

    oplp=oplp->next;
    oplp->value.var_name->info->data_n=value; /* allocate value */
                                              /* to variable */
}

void do_display(OP_LIST *op_list)
{
/* valid syntax
**
** DISPLAY thing
** (automatic newline)
** will display the contents of a string or numeric variable
** a string, or a numeric literal
*/
    OP_LIST *oplp;

    oplp=op_list;             /* skip DISPLAY */
    oplp=oplp->next;

    if(oplp->type==OP_STRING)
        printf(" %s\n",oplp->value.non_numeric_literal);
    else
       {
        if(oplp->type==OP_NUM_LIT)
            printf(" %d\n",oplp->value.numeric_literal);
        else
           {
            if(oplp->type==OP_VAR && 
               oplp->value.var_name->info->type==INT)
              printf(" %d\n",oplp->value.var_name->info->data_n);
            else
              printf(" %s\n",oplp->value.var_name->info->data_c);
           }
       }
}

void do_add(OP_LIST *op_list)
{
/* valid syntax
**
** ADD variable         TO variable
**  or numeric_literal
*/
    int value;
    OP_LIST *oplp=op_list;

    oplp=oplp->next;            /* skip ADD */

    if(oplp->type==OP_NUM_LIT)
       value=oplp->value.numeric_literal;
    else
       value=oplp->value.var_name->info->data_n;

    oplp=oplp->next;       /* skip TO */

    oplp=oplp->next;
    oplp->value.var_name->info->data_n+=value;
}

\end{verbatim}
