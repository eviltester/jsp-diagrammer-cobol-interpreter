\begin{verbatim}
/*========================================================*
 *               CONDS.H                                  *
 * declare the condition details for the conditions used  *
 * in the interpreter, the different relational operators *
 * used and the limited syntax of the condition           *
 * ie. LEFT_HAND_SIDE RELATION RIGHT_HAND_SIDE            *
 *========================================================*/

#ifndef CONDHY
#define CONDHY
#include "symtab.h"
#include <stdio.h>
#include "node.h"
#include "alfile.h"
#include "errors.h"
#include "token.h"
 
#define COND_ARRAY_SIZE 100    /* size of array */


typedef enum{RELATIONAL_NOTHING,
             GREATER_THAN,           /* types of comparison */
             LESS_THAN,              /* possible            */
             EQUAL_TO}REL_OP;

typedef enum{NO_STATUS,YES_STATUS}NOT_STATUS; /* the negation */

typedef enum{SIDE_VAR,                   /* types of things */
             SIDE_NON_LITERAL,           /* that can be     */
             SIDE_LITERAL}SIDE_TYPE;     /* compared        */

/* each side of the condition is of a certain type 
   and either points to the contants or in the case
   of a numeric holds it here              */

typedef struct{
               SIDE_TYPE type;
               union{
                     NODE *variable;
                     char *non_numeric_literal;
                     int numeric_literal;
                    }contents;
              }CONDITION_SIDE;

/* the relation between the two sides has a negation status
   and the type of comparison to take place                 */

typedef struct{
               NOT_STATUS not;
               REL_OP relation;
              }RELATIONAL;

/* the actual, lhs comparison rhs , condition */
typedef struct{
               CONDITION_SIDE lhs;
               RELATIONAL relation;
               CONDITION_SIDE rhs;
              }COND;

/*FUNCTION DEFS*/

extern COND **create_cond_array(void);
extern COND *create_cond(void);
extern void save_cond_array(char *,COND **);
extern void save_side(CONDITION_SIDE *,FILE *);
extern void load_cond_array(char *,COND **,SYMTAB_ENTRY **);
extern void load_side(CONDITION_SIDE *,TOKEN *,SYMTAB_ENTRY **);
extern void display_condition(COND *);
extern void display_side(CONDITION_SIDE *);
extern int evaluate_condition(COND *);



#endif

\end{verbatim}
