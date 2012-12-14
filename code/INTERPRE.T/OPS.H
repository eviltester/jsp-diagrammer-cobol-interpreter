\begin{verbatim}
/*==========================================================*
 *             OPS.H                                        *
 * define's and declarations for the operations used in the *
 * interpreter                                              *
 *==========================================================*/

#ifndef OPSYH
#define OPSYH

#include "conds.h"
#include "token.h"
#include <stdio.h>
#include "node.h"
#include "alfile.h"
#include "errors.h"
#include "symtab.h"
#include "keywords.h"

/* fixed size of array */
#define OP_ARRAY_SIZE 1000

/* type of items in an OP_LIST */
typedef enum{OP_VERB,OP_VAR,OP_STRING,OP_NUM_LIT}OP_TYPE;

/* an OP_LIST is a list of OP_TYPE things which make up 
   a COBOL statement */
typedef struct{
               OP_TYPE type;
               union{
                     int keyword_number;
                     NODE *var_name;
                     char *non_numeric_literal;
                     int numeric_literal;
                    }value;
               struct OP_LIST *next;
              }OP_LIST;

/* an OP_LIST_LIST is a list of statements, these statements
   are contained in the OP_LIST */
typedef struct{
               OP_LIST *op;
               struct OP_LIST_LIST *next;
              }OP_LIST_LIST;

/*FUNCTION DEFS*/

extern OP_LIST_LIST **create_op_array(void);
extern OP_LIST *create_op_list(void);
extern OP_LIST_LIST *create_op_list_list(void);
extern void save_ops_array(char *,OP_LIST_LIST **);
extern void save_op(FILE *,OP_LIST *);
extern void load_ops_array(char *,OP_LIST_LIST **,SYMTAB_ENTRY **);
extern OP_LIST *load_op(FILE *,SYMTAB_ENTRY **,TOKEN *);
extern void display_operations(OP_LIST_LIST **);
extern void display_operation(OP_LIST_LIST *);
extern void evaluate_operation(OP_LIST_LIST *);
extern void evaluate_op(OP_LIST *);
extern void do_move(OP_LIST *);
extern void do_display(OP_LIST *);
extern void do_add(OP_LIST *);


#endif

\end{verbatim}
