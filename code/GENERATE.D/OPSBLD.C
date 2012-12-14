\begin{verbatim}
#include <stdio.h>
#include "alfile.h"
#include "node.h"
#include "alutil.h"
#include "symtab.h"
#include "keywords.h"
#include "token.h"
#include "ops.h"

void main(){

FILE *infile;
SYMTAB_ENTRY **symtab=create_symbol_table_array(100);
int eof;
TOKEN *token,t;
NODE *node;
OP_LIST_LIST **op_array=create_op_array();
OP_LIST_LIST *op_list_list;
OP_LIST *op_list;


                int g2_001_COMMAND_SUBTREE_A;
      /**************************************************************************/
      /**************************************************************************/
      /******************** DRIVING PROCEDURE    B:\OPSBLD *********************/
      /**************************************************************************/
       PROCEDURE_DIVISION:
      /**/
       C1_001_OPS_BUILDER:
           goto C1_002_OPS_BUILD_START;
       C1_002_OPS_BUILD_START_EX:
           goto C1_003_OPS_BUILD_BODY;
       C1_003_OPS_BUILD_BODY_EX:
           goto C1_013_OPS_BUILD_END;
       C1_013_OPS_BUILD_END_EX:
           goto veryend;
      /**/
       C1_002_OPS_BUILD_START:
  /*001*/      infile=open_input("b:opsout.dat");
  /*003*/      token=&t;
  /*005*/      load_symtab(symtab,"b:symtable.out");
           cross_reference(symtab,100);
  /*004*/      eof=get_token(infile,token);
           goto C1_002_OPS_BUILD_START_EX;
      /**/
       C1_003_OPS_BUILD_BODY:
       C1_004_OP_EX:
           if(!(
  /*C01*/         (eof==1)
))
                   goto C1_004_OP;
           goto C1_003_OPS_BUILD_BODY_EX;
      /**/
       C1_004_OP:
           goto C1_005_OPSTART;
       C1_005_OPSTART_EX:
           goto C1_006_FIRST_COMMAND;
       C1_006_FIRST_COMMAND_EX:
           goto C1_008_REST;
       C1_008_REST_EX:
           goto C1_004_OP_EX;
      /**/
       C1_005_OPSTART:
  /*007*/      op_list_list=create_op_list_list();
  /*009*/      op_array[token->value.keyword_number]=op_list_list;
  /*008*/      op_list=create_op_list();
  /*010*/      op_list_list->op=op_list;
  /*004*/      eof=get_token(infile,token);
           goto C1_005_OPSTART_EX;
      /**/
       C1_006_FIRST_COMMAND:
           goto C1_007_COMMAND_SUBTREE;
       C1_007_COMMAND_SUBTREE_EX:
           goto C1_006_FIRST_COMMAND_EX;
      /**/
       C1_007_COMMAND_SUBTREE:
                g2_001_COMMAND_SUBTREE_A=0;
           goto C2_001_COMMAND_SUBTREE;
       C2_001_EXIT01:
           goto C1_007_COMMAND_SUBTREE_EX;
      /**/
       C1_008_REST:
       C1_009_COMMAND_EX:
           if(!(
  /*C02*/         (eof==1 || token->token_type==OP_NUM)
))
                   goto C1_009_COMMAND;
           goto C1_008_REST_EX;
      /**/
       C1_009_COMMAND:
           goto C1_010_COMMAND_START;
       C1_010_COMMAND_START_EX:
           goto C1_011_COMMAND_BODY;
       C1_011_COMMAND_BODY_EX:
           goto C1_009_COMMAND_EX;
      /**/
       C1_010_COMMAND_START:
  /*017*/      op_list_list->next=create_op_list_list();
           op_list_list=op_list_list->next;
  /*008*/      op_list=create_op_list();
  /*010*/      op_list_list->op=op_list;
           goto C1_010_COMMAND_START_EX;
      /**/
       C1_011_COMMAND_BODY:
           goto C1_012_COMMAND_SUBTREE;
       C1_012_COMMAND_SUBTREE_EX:
           goto C1_011_COMMAND_BODY_EX;
      /**/
       C1_012_COMMAND_SUBTREE:
                g2_001_COMMAND_SUBTREE_A=1;
           goto C2_001_COMMAND_SUBTREE;
       C2_001_EXIT02:
           goto C1_012_COMMAND_SUBTREE_EX;
      /**/
       C1_013_OPS_BUILD_END:
  /*002*/      close_file(infile);
  /*011*/      save_ops_array("b:opsarray.out",op_array);
           goto C1_013_OPS_BUILD_END_EX;
      /**/
       C2_001_COMMAND_SUBTREE:
           goto C2_002_FIRST_PART;
       C2_002_FIRST_PART_EX:
           goto C2_009_BODY;
       C2_009_BODY_EX:
           goto C2_018_FULLSTOP;
       C2_018_FULLSTOP_EX:
       C2_001_COMMAND_SUBTREE_A:
                switch(g2_001_COMMAND_SUBTREE_A){
                case 0 : goto C2_001_EXIT01;break;
                case 1 : goto C2_001_EXIT02;break;
                }
      /**/
       C2_002_FIRST_PART:
           goto C2_003_FIRST_BODY;
       C2_003_FIRST_BODY_EX:
           goto C2_008_FIRST_END;
       C2_008_FIRST_END_EX:
           goto C2_002_FIRST_PART_EX;
      /**/
       C2_003_FIRST_BODY:
           if((
  /*C06*/         (token->token_type==KEYWORD)
))
                   goto C2_004_VERB;
           if((
  /*C04*/         (token->token_type==NUMERIC)
))
                   goto C2_005_NUMBER;
           if((
  /*C05*/         (token->token_type==NON_NUMERIC_LITERAL)
))
                   goto C2_006_STRING;
           if((
  /*C03*/         (token->token_type==VARIABLE_NAME)
))
                   goto C2_007_VARIABLE;
       C2_004_VERB_EX:
       C2_005_NUMBER_EX:
       C2_006_STRING_EX:
       C2_007_VARIABLE_EX:
           goto C2_003_FIRST_BODY_EX;
      /**/
       C2_004_VERB:
  /*013*/      op_list->type=OP_VERB;
           op_list->value.keyword_number=token->value.keyword_number;
           goto C2_004_VERB_EX;
      /**/
       C2_005_NUMBER:
  /*015*/      op_list->type=OP_NUM_LIT;
           op_list->value.numeric_literal=token->value.keyword_number;
           goto C2_005_NUMBER_EX;
      /**/
       C2_006_STRING:
  /*014*/      op_list->type=OP_STRING;
           op_list->value.non_numeric_literal=token->value.string;
           goto C2_006_STRING_EX;
      /**/
       C2_007_VARIABLE:
  /*006*/      node=look_for(token->value.var_values.unique,
                         token->value.var_values.hash,
                         symtab);
  /*012*/      op_list->type=OP_VAR;
           op_list->value.var_name=node;
           goto C2_007_VARIABLE_EX;
      /**/
       C2_008_FIRST_END:
  /*004*/      eof=get_token(infile,token);
           goto C2_008_FIRST_END_EX;
      /**/
       C2_009_BODY:
       C2_010_PART_EX:
           if(!(
  /*C07*/         (token->token_type==FULLSTOP)
))
                   goto C2_010_PART;
           goto C2_009_BODY_EX;
      /**/
       C2_010_PART:
           goto C2_011_PART_START;
       C2_011_PART_START_EX:
           goto C2_012_PART_BODY;
       C2_012_PART_BODY_EX:
           goto C2_017_PART_END;
       C2_017_PART_END_EX:
           goto C2_010_PART_EX;
      /**/
       C2_011_PART_START:
  /*016*/      op_list->next=create_op_list();
           op_list=op_list->next;
           goto C2_011_PART_START_EX;
      /**/
       C2_012_PART_BODY:
           if((
  /*C06*/         (token->token_type==KEYWORD)
))
                   goto C2_013_VERB;
           if((
  /*C04*/         (token->token_type==NUMERIC)
))
                   goto C2_014_NUMBER;
           if((
  /*C05*/         (token->token_type==NON_NUMERIC_LITERAL)
))
                   goto C2_015_STRING;
           if((
  /*C03*/         (token->token_type==VARIABLE_NAME)
))
                   goto C2_016_VARIABLE;
       C2_013_VERB_EX:
       C2_014_NUMBER_EX:
       C2_015_STRING_EX:
       C2_016_VARIABLE_EX:
           goto C2_012_PART_BODY_EX;
      /**/
       C2_013_VERB:
  /*013*/      op_list->type=OP_VERB;
           op_list->value.keyword_number=token->value.keyword_number;
           goto C2_013_VERB_EX;
      /**/
       C2_014_NUMBER:
  /*015*/      op_list->type=OP_NUM_LIT;
           op_list->value.numeric_literal=token->value.keyword_number;
           goto C2_014_NUMBER_EX;
      /**/
       C2_015_STRING:
  /*014*/      op_list->type=OP_STRING;
           op_list->value.non_numeric_literal=token->value.string;
           goto C2_015_STRING_EX;
      /**/
       C2_016_VARIABLE:
  /*006*/      node=look_for(token->value.var_values.unique,
                         token->value.var_values.hash,
                         symtab);
  /*012*/      op_list->type=OP_VAR;
           op_list->value.var_name=node;
           goto C2_016_VARIABLE_EX;
      /**/
       C2_017_PART_END:
  /*004*/      eof=get_token(infile,token);
           goto C2_017_PART_END_EX;
      /**/
       C2_018_FULLSTOP:
  /*004*/      eof=get_token(infile,token);
           goto C2_018_FULLSTOP_EX;
      /**/
      /*   Data Analysis Map*/
      /**/
      /*                         ------------- Data Analysis By -------------*/
      /**/
      /*                         BOX TYPE               OPERATION  ALLOCATION*/
      /*  Tree name: OPS-BUILDER*/
      /**/
      /*                         Leaf      :   4          Operations:  14*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   5*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   2   -->    COMMAND-SUBTREE*/
      /*                                                  COMMAND-SUBTREE*/
      /**/
      /*  Tree name: COMMAND-SUBTREE*/
      /**/
      /*                         Leaf      :  12          Operations:  14*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   2*/
      /*                         Sequences :   3*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /**/
      /**/
veryend: ;
}
\end{verbatim}
