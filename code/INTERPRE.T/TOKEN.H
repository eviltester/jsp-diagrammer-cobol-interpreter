\begin{verbatim}
/*==============================================================*
 *                    TOKEN.H                                   *
 * defines the token functions and types, used for intermediate *
 * file access                                                  *
 *==============================================================*/
#ifndef TOKENYH
#define TOKENYH

#include <stdio.h>
#include "node.h"
#include "symtab.h"

typedef enum{NOTHING,OPEN_BRACE,CLOSE_BRACE,FULLSTOP,
             KEYWORD,NON_KEYWORD,NON_KEYWORD_LENGTH,
             NON_NUMERIC_LITERAL,NON_NUMERIC_LITERAL_LENGTH,
             OP_NUM,VARIABLE_NAME,NUMERIC,COND_NUM,RELATIONAL_OP
            }TOKEN_TYPE;

typedef struct{
               TOKEN_TYPE token_type;
               union{
                     int keyword_number;
                     char *string;
                     save_values var_values;
                    }value;
              }TOKEN;

extern void write_token(FILE *,TOKEN *);
extern int get_token(FILE *,TOKEN *);

#endif

\end{verbatim}
