\begin{verbatim}
/*======================================================*
 *                    CONDS.C                           *
 * The functions used to manipulate the condition       * 
 * representations used by the interpreter.             *
 * The save and load functions were written out of      *   
 * necessity because no inversion was used to link the  *
 * main interpreter modules                             *
 *======================================================*/

#include "conds.h"

/*==========================================================*
 * create_cond allocates memory for a condition and returns *
 * the address                                              *
 *==========================================================*/
COND *create_cond()
    {
        COND *cond=(COND *)malloc(sizeof(COND));

        if(cond==NULL)
            fatal_error("NO room for COND");

        return(cond);
    }


/*==========================================================*
 * create_cond_array creates anough memory for an array of  *
 * pointers to conditions, the array is of fixed size       *
 * 99 because this is the number of conditions available    *
 * in probench                                              *
 *==========================================================*/
COND **create_cond_array()
    {
        int loop;
        COND **ctp=(COND **)malloc(sizeof(COND *)*COND_ARRAY_SIZE);

        if(ctp==NULL)
           fatal_error("no more room for cond ARRAY");

        for(loop=0;loop<COND_ARRAY_SIZE;loop++) /*initialise array */
           ctp[loop]=NULL;

        return(ctp);
    }

/*============================================================*
 * save_cond_array opens filename and loops through the array *
 * writing out the condition number ( the loop position )     *
 * writing out the left hand side details,                    *
 * then the relational operator                               *
 * and then the right hand side                               *
 *============================================================*/
void save_cond_array(char *filename, COND **cond_array)
    {
     int loop;
     FILE *outfile=open_output(filename);
     TOKEN token;


     for(loop=0;loop<COND_ARRAY_SIZE;loop++)
        {
         if(cond_array[loop]!=NULL)
           {
             token.token_type=COND_NUM;        /* save cond num */
             token.value.keyword_number=loop;
             write_token(outfile,&token);

             /* save left hand side */
             save_side(&(cond_array[loop]->lhs),outfile);

             /* the relational op consists of two parts
                the not status followed by the relation */

             token.token_type=RELATIONAL_OP;
             token.value.keyword_number=cond_array[loop]->
                                             relation.not;
             write_token(outfile,&token);
             token.token_type=RELATIONAL_OP;
             token.value.keyword_number=cond_array[loop]->
                                             relation.relation;
             write_token(outfile,&token);

             /* save right hand side */
             save_side(&(cond_array[loop]->rhs),outfile);
           }
        }
     close_file(outfile);
    }

/*=============================================================*
 * save_side determines which type of token to write out       *
 * dependant upon what is stored at that side of the condition *
 *=============================================================*/
void save_side(CONDITION_SIDE *cond_side,FILE *outfile)
    {
     TOKEN token;
     if(cond_side->type==SIDE_VAR)
        {
         token.token_type=VARIABLE_NAME;
         token.value.var_values.unique=
                 cond_side->contents.variable->own.unique;
         token.value.var_values.hash=
                 cond_side->contents.variable->own.hash;
        }
     if(cond_side->type==SIDE_LITERAL)
        {
         token.token_type=NUMERIC;
         token.value.keyword_number=cond_side->contents.
                                    numeric_literal;
        }
     if(cond_side->type==SIDE_NON_LITERAL)
        {
         
         token.token_type=NON_NUMERIC_LITERAL_LENGTH;
         token.value.keyword_number=strlen(cond_side->contents.
                                           non_numeric_literal);
         write_token(outfile,&token);
         token.token_type=NON_NUMERIC_LITERAL;
         token.value.string=cond_side->contents.non_numeric_literal;
        }
         write_token(outfile,&token);
    }

/*============================================================*
 * load_cond_array uses the file created by the above code to *
 * build up a condition array, the symbol table is used to    *
 * find the addresses of the variables in the conditions      *
 *============================================================*/                     
void load_cond_array(char *filename, COND **cond_array,
                     SYMTAB_ENTRY **symtab)
    {
     int eof;
     FILE *infile=open_input(filename);
     TOKEN token;
     COND *condition;

     eof=get_token(infile,&token); /* get the first condition number */

     while(!eof)
      {
      condition=create_cond();                          /* put the new  */
      cond_array[token.value.keyword_number]=condition; /* condition in */
                                                        /*the slot      */

      eof=get_token(infile,&token);                     /* get side         */
      load_side(&(condition->lhs),&token,symtab);       /* place it on cond */

      eof=get_token(infile,&token);                      /* get relation */
      condition->relation.not=token.value.keyword_number;/* not status   */

      eof=get_token(infile,&token);                      /* get the relation */                 
      condition->relation.relation=token.value.keyword_number;

      eof=get_token(infile,&token);                 /* get the side */
      load_side(&(condition->rhs),&token,symtab);   /* place it on cond */

      eof=get_token(infile,&token); /* get any more */
      }

}      

/*==============================================================*
 * load_side takes a previously loaded token and puts it in the *
 * condition correctly                                          *
 *==============================================================*/
void load_side(CONDITION_SIDE *side,TOKEN *token,
               SYMTAB_ENTRY **symtab)
    {
       if(token->token_type==VARIABLE_NAME)
           {
             /* find the variable using the hash value
                and the unique number stored on file */
             side->type=SIDE_VAR;
             side->contents.variable=look_for(
                                     token->value.var_values.unique,
                                     token->value.var_values.hash,
                                     symtab);
           }

       if(token->token_type==NON_NUMERIC_LITERAL)
          {
             /* use the string loaded in by the token code */
             side->type=SIDE_NON_LITERAL;
             side->contents.non_numeric_literal=token->value.string;
          }

      if(token->token_type==NUMERIC)
          {
           /* allocate the numeric value */
           side->type=SIDE_LITERAL;
           side->contents.numeric_literal=token->value.keyword_number;
          }

}

/*============================================================*
 * display_conditions loops through the array                 *
 * displaying the condition number, followed by the condition *
 * itself                                                     *
 *============================================================*/
void display_conditions(COND **cond_array)
{
    int loop;

    for(loop=0;loop<COND_ARRAY_SIZE;loop++)
        {
         if(cond_array[loop]!=NULL)
           {
            printf("COND %d\n",loop);
            display_condition(cond_array[loop]);
            printf("\n");
           }
        }
}

/*=============================================*
 * display_condition takes a condition,        *
 * displays the left hand side,                *
 * if the not status is set then displays NOT  *
 * then the relational operator                *
 * followed by the right hand side             *
 *=============================================*/
void display_condition(COND *cond)
{
    display_side(&(cond->lhs));

    if(cond->relation.not)
         printf(" NOT ");

    if(cond->relation.relation==GREATER_THAN)
         printf(" >");
    else{
         if(cond->relation.relation==LESS_THAN)
               printf(" <");
         else
             if(cond->relation.relation==EQUAL_TO)
                 printf(" =");
        }

    display_side(&(cond->rhs));
}

/*===================================================*
 * display_side displays the relevant details of the *
 * conditional side,                                 *
 * for variables it displays the name                *
 * strings display their contents                    *
 * and numbers get the number displayed              *
 *===================================================*/
void display_side(CONDITION_SIDE *side)
{
    if(side->type==SIDE_VAR)
        printf(" %s",side->contents.variable->info->name);
    else{
         if(side->type==SIDE_NON_LITERAL)
              printf(" %s",side->contents.non_numeric_literal);
         else
             if(side->type==SIDE_LITERAL)
                 printf(" %d",side->contents.numeric_literal);
        } 
} 

/*================================================================*
 * evaluate condition takes a condition, and returns the          *
 * boolean value that it evaluates to.                            *
 *                                                                *
 * Currently equality comparisons are allowed between             *
 * strings and string variables, strings and strings, and         *
 * string variables and string variables                          *
 *                                                                *
 * Numeric comparisons can take place between numeric literals    *
 * and numeric variables in any combination as above.             *
 * The comparisons available are >, <, =, NOT <, NOT >, and NOT = *
 *                                                                *
 * The type of condition is determined by the left hand side so   *
 * the conditions must be semantically correct with no mixed      *
 * conditions i.e numeric < string etc.                           *
 *================================================================*/
int evaluate_condition(COND *cond)
{
    int lhs_num,rhs_num;
    char *lhs,*rhs;
    int truth=0;           /* ever the optomist */

    /*if string or string variable on left hand side*/
    if(cond->lhs.type==SIDE_NON_LITERAL ||
       (cond->lhs.type == SIDE_VAR &&
        cond->lhs.contents.variable->info->type==CHAR))
      {
       if(cond->relation.relation==EQUAL_TO) /* must be == */
         {

          /* if the side is a string then point to the
             string, if it is a variabel the point to
             the variables contents                    */

          if(cond->lhs.type==SIDE_NON_LITERAL)
             lhs=cond->lhs.contents.non_numeric_literal;
          else
             lhs=cond->lhs.contents.variable->info->data_c;

          if(cond->rhs.type==SIDE_NON_LITERAL)
             rhs=cond->rhs.contents.non_numeric_literal;
          else
             rhs=cond->rhs.contents.variable->info->data_c;

          truth=!strcmp(lhs,rhs); /* compare them */
         }
       }
     else
         {
          /* if the side is a number then get the number
             if it is a variable then get the variable contents */

          if(cond->rhs.type==SIDE_LITERAL)
              rhs_num=cond->rhs.contents.numeric_literal;
          else
              rhs_num=cond->rhs.contents.variable->info->data_n;

          if(cond->lhs.type==SIDE_LITERAL)
              lhs_num=cond->lhs.contents.numeric_literal;
          else
              lhs_num=cond->lhs.contents.variable->info->data_n;

          /* carry out the comparison and determine the truth value */

          if(cond->relation.relation==EQUAL_TO) 
                truth=(lhs_num==rhs_num) ? 1:0;
          else{
               if(cond->relation.relation==GREATER_THAN)
                    truth=(lhs_num>rhs_num) ? 1:0;
               else 
                  if(cond->relation.relation==LESS_THAN)
                     truth=(lhs_num<rhs_num) ? 1:0;
                   
              }
         }
     /* if the NOT status is set then negate the truth value
        otherwise return the truth value as is */

     return((cond->relation.not) ? !truth:truth);
}    

\end{verbatim}
