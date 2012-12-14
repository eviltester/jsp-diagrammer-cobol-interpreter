\begin{verbatim}
#include <stdio.h>
#include "alfile.h"
#include "staglist.h"
#include "node.h"
#include "alutil.h"
#include "symtab.h"
#include "keywords.h"
#include "token.h"
#include "conds.h"

void main(){

FILE *infile;
SYMTAB_ENTRY **symtab=create_symbol_table_array(100);
int eof;
TOKEN *token,t;
NODE *node;
COND *cond;
COND **cond_array=create_cond_array();


                int g2_001_LHS_A;
                int g3_001_KEYWORDS_A;
                int g4_001_RHS_A;
                int g5_001_GROUP_SUBTREE_A;
      /**************************************************************************/
      /**************************************************************************/
      /******************* DRIVING PROCEDURE    B:\CONDSBLD ********************/
      /**************************************************************************/
       PROCEDURE_DIVISION:
      /**/
      /** take the output from the condition*/
      /** tokeniser, it consists of an iteration*/
      /** of condition number, left hand side,*/
      /** a relational operator ie NOT >, or >*/
      /** then the right hand side*/
      /**/
       C1_001_CONDS_BUILD:
           goto C1_002_CONDS_START;
       C1_002_CONDS_START_EX:
           goto C1_003_CONDS_BODY;
       C1_003_CONDS_BODY_EX:
           goto C1_009_CONDS_END;
       C1_009_CONDS_END_EX:
           goto veryend;
      /**/
       C1_002_CONDS_START:
  /*001*/      infile=open_input("b:cndout.dat");
  /*007*/      load_symtab(symtab,"b:symtable.out");
           cross_reference(symtab,100);
  /*005*/      token=&t;
  /*006*/      eof=get_token(infile,token);
           goto C1_002_CONDS_START_EX;
      /**/
       C1_003_CONDS_BODY:
       C1_004_COND_EX:
           if(!(
  /*C01*/         (eof==1)
))
                   goto C1_004_COND;
           goto C1_003_CONDS_BODY_EX;
      /**/
       C1_004_COND:
           goto C1_005_COND_NUM;
       C1_005_COND_NUM_EX:
           goto C1_006_LHS;
       C1_006_LHS_EX:
           goto C1_007_KEYWORDS;
       C1_007_KEYWORDS_EX:
           goto C1_008_RHS;
       C1_008_RHS_EX:
           goto C1_004_COND_EX;
      /**/
       C1_005_COND_NUM:
  /*010*/      cond=create_cond();
  /*011*/      cond_array[token->value.keyword_number]=cond;
  /*006*/      eof=get_token(infile,token);
           goto C1_005_COND_NUM_EX;
      /**/
       C1_006_LHS:
                g2_001_LHS_A=0;
           goto C2_001_LHS;
       C2_001_EXIT01:
           goto C1_006_LHS_EX;
      /**/
       C1_007_KEYWORDS:
                g3_001_KEYWORDS_A=0;
           goto C3_001_KEYWORDS;
       C3_001_EXIT01:
           goto C1_007_KEYWORDS_EX;
      /**/
       C1_008_RHS:
                g4_001_RHS_A=0;
           goto C4_001_RHS;
       C4_001_EXIT01:
           goto C1_008_RHS_EX;
      /**/
       C1_009_CONDS_END:
  /*002*/      close_file(infile);
  /*004*/      save_cond_array("b:cndout2.dat",cond_array);
           goto C1_009_CONDS_END_EX;
      /**/
       C5_001_GROUP_SUBTREE:
           if((
  /*C08*/         (token->token_type==RELATIONAL_OP)
))
                   goto C5_002_RELATIONAL;
           if((
  /*C09*/         (token->token_type==KEYWORD)
))
                   goto C5_008_VERB;
       C5_002_RELATIONAL_EX:
       C5_008_VERB_EX:
       C5_001_GROUP_SUBTREE_A:
                switch(g5_001_GROUP_SUBTREE_A){
                case 0 : goto C5_001_EXIT02;break;
                case 1 : goto C5_001_EXIT03;break;
                }
      /**/
       C5_002_RELATIONAL:
           goto C5_003_RELATIONAL_BODY;
       C5_003_RELATIONAL_BODY_EX:
           goto C5_007_RELATIONAL_END;
       C5_007_RELATIONAL_END_EX:
           goto C5_002_RELATIONAL_EX;
      /**/
       C5_003_RELATIONAL_BODY:
           if((
  /*C10*/         (token->value.keyword_number==GREATER_THAN)
))
                   goto C5_004_GREATER_SYMBOL;
           if((
  /*C11*/         (token->value.keyword_number==LESS_THAN)
))
                   goto C5_005_LESS_SYMBOL;
           if((
  /*C12*/         (token->value.keyword_number==EQUAL_TO)
))
                   goto C5_006_EQUAL_SYMBOL;
       C5_004_GREATER_SYMBOL_EX:
       C5_005_LESS_SYMBOL_EX:
       C5_006_EQUAL_SYMBOL_EX:
           goto C5_003_RELATIONAL_BODY_EX;
      /**/
       C5_004_GREATER_SYMBOL:
  /*014*/      cond->relation.relation=GREATER_THAN;
           goto C5_004_GREATER_SYMBOL_EX;
      /**/
       C5_005_LESS_SYMBOL:
  /*015*/      cond->relation.relation=LESS_THAN;
           goto C5_005_LESS_SYMBOL_EX;
      /**/
       C5_006_EQUAL_SYMBOL:
  /*016*/      cond->relation.relation=EQUAL_TO;
           goto C5_006_EQUAL_SYMBOL_EX;
      /**/
       C5_007_RELATIONAL_END:
  /*006*/      eof=get_token(infile,token);
           goto C5_007_RELATIONAL_END_EX;
      /**/
       C5_008_VERB:
           goto C5_009_VERB_BODY;
       C5_009_VERB_BODY_EX:
           goto C5_019_VERB_END;
       C5_019_VERB_END_EX:
           goto C5_008_VERB_EX;
      /**/
       C5_009_VERB_BODY:
           if((
  /*C13*/         (token->value.keyword_number==GREATER)
))
                   goto C5_010_GREATER;
           if((
  /*C14*/         (token->value.keyword_number==LESS)
))
                   goto C5_013_LESS;
           if((
  /*C15*/         (token->value.keyword_number==EQUAL)
))
                   goto C5_016_EQUAL;
       C5_010_GREATER_EX:
       C5_013_LESS_EX:
       C5_016_EQUAL_EX:
           goto C5_009_VERB_BODY_EX;
      /**/
       C5_010_GREATER:
           goto C5_011_GREATER;
       C5_011_GREATER_EX:
           goto C5_012_THAN;
       C5_012_THAN_EX:
           goto C5_010_GREATER_EX;
      /**/
       C5_011_GREATER:
  /*006*/      eof=get_token(infile,token);
           goto C5_011_GREATER_EX;
      /**/
       C5_012_THAN:
  /*014*/      cond->relation.relation=GREATER_THAN;
           goto C5_012_THAN_EX;
      /**/
       C5_013_LESS:
           goto C5_014_LESS;
       C5_014_LESS_EX:
           goto C5_015_THAN;
       C5_015_THAN_EX:
           goto C5_013_LESS_EX;
      /**/
       C5_014_LESS:
  /*006*/      eof=get_token(infile,token);
           goto C5_014_LESS_EX;
      /**/
       C5_015_THAN:
  /*015*/      cond->relation.relation=LESS_THAN;
           goto C5_015_THAN_EX;
      /**/
       C5_016_EQUAL:
           goto C5_017_EQUAL;
       C5_017_EQUAL_EX:
           goto C5_018_TO;
       C5_018_TO_EX:
           goto C5_016_EQUAL_EX;
      /**/
       C5_017_EQUAL:
  /*006*/      eof=get_token(infile,token);
           goto C5_017_EQUAL_EX;
      /**/
       C5_018_TO:
  /*016*/      cond->relation.relation=EQUAL_TO;
           goto C5_018_TO_EX;
      /**/
       C5_019_VERB_END:
  /*006*/      eof=get_token(infile,token);
           goto C5_019_VERB_END_EX;
      /**/
      /** skip the IS, take the NOT and the*/
      /** relational and build a relational part o*/
      /** f the condition*/
      /**/
       C3_001_KEYWORDS:
           goto C3_002_KSTART;
       C3_002_KSTART_EX:
           goto C3_003_POSS_IS;
       C3_003_POSS_IS_EX:
           goto C3_005_KEYWORD_GROUP;
       C3_005_KEYWORD_GROUP_EX:
       C3_001_KEYWORDS_A:
                switch(g3_001_KEYWORDS_A){
                case 0 : goto C3_001_EXIT01;break;
                }
      /**/
       C3_002_KSTART:
  /*023*/      printf("relation bit\n");
           goto C3_002_KSTART_EX;
      /**/
       C3_003_POSS_IS:
           if((
  /*C05*/         (token->token_type==KEYWORD &&
               token->value.keyword_number==IS)
))
                   goto C3_004_IS;
       C3_004_IS_EX:
           goto C3_003_POSS_IS_EX;
      /**/
       C3_004_IS:
  /*006*/      eof=get_token(infile,token);
           goto C3_004_IS_EX;
      /**/
       C3_005_KEYWORD_GROUP:
           if((
  /*C06*/         (token->token_type==KEYWORD &&
               token->value.keyword_number==NOT)
))
                   goto C3_006_NOT_GROUP;
           if((
  /*C07*/         (token->token_type==KEYWORD ||
               token->token_type==RELATIONAL_OP)
))
                   goto C3_010_NOT_NOT_GROUP;
       C3_006_NOT_GROUP_EX:
       C3_010_NOT_NOT_GROUP_EX:
           goto C3_005_KEYWORD_GROUP_EX;
      /**/
       C3_006_NOT_GROUP:
           goto C3_007_NOT;
       C3_007_NOT_EX:
           goto C3_008_GROUP;
       C3_008_GROUP_EX:
           goto C3_006_NOT_GROUP_EX;
      /**/
       C3_007_NOT:
  /*006*/      eof=get_token(infile,token);
  /*017*/      cond->relation.not=YES_STATUS;
           goto C3_007_NOT_EX;
      /**/
       C3_008_GROUP:
           goto C3_009_GROUP_SUBTREE;
       C3_009_GROUP_SUBTREE_EX:
           goto C3_008_GROUP_EX;
      /**/
       C3_009_GROUP_SUBTREE:
                g5_001_GROUP_SUBTREE_A=0;
           goto C5_001_GROUP_SUBTREE;
       C5_001_EXIT02:
           goto C3_009_GROUP_SUBTREE_EX;
      /**/
       C3_010_NOT_NOT_GROUP:
           goto C3_011_GROUP;
       C3_011_GROUP_EX:
           goto C3_010_NOT_NOT_GROUP_EX;
      /**/
       C3_011_GROUP:
           goto C3_012_GROUP_SUBTREE;
       C3_012_GROUP_SUBTREE_EX:
           goto C3_011_GROUP_EX;
      /**/
       C3_012_GROUP_SUBTREE:
                g5_001_GROUP_SUBTREE_A=1;
           goto C5_001_GROUP_SUBTREE;
       C5_001_EXIT03:
           goto C3_012_GROUP_SUBTREE_EX;
      /**/
       C4_001_RHS:
           goto C4_002_RHS_START;
       C4_002_RHS_START_EX:
           goto C4_003_RHS_BODY;
       C4_003_RHS_BODY_EX:
           goto C4_007_RHS_END;
       C4_007_RHS_END_EX:
       C4_001_RHS_A:
                switch(g4_001_RHS_A){
                case 0 : goto C4_001_EXIT01;break;
                }
      /**/
       C4_002_RHS_START:
  /*022*/      printf("right hand side\n");getchar();
  /*021*/      cond->relation.not=NO_STATUS;
           goto C4_002_RHS_START_EX;
      /**/
       C4_003_RHS_BODY:
           if((
  /*C02*/         (token->token_type==NUMERIC)
))
                   goto C4_004_INTEGER;
           if((
  /*C03*/         (token->token_type==VARIABLE_NAME)
))
                   goto C4_005_VARIABLE;
           if((
  /*C04*/         (token->token_type==NON_NUMERIC_LITERAL)
))
                   goto C4_006_STRING;
       C4_004_INTEGER_EX:
       C4_005_VARIABLE_EX:
       C4_006_STRING_EX:
           goto C4_003_RHS_BODY_EX;
      /**/
       C4_004_INTEGER:
  /*018*/      cond->rhs.type=SIDE_LITERAL;
           cond->rhs.contents.numeric_literal=token->value.keyword_number;
  /*025*/      printf("numeric value \n");
           goto C4_004_INTEGER_EX;
      /**/
       C4_005_VARIABLE:
  /*009*/      node=look_for(token->value.var_values.unique,
                         token->value.var_values.hash,
                         symtab);
  /*020*/      cond->rhs.type=SIDE_VAR;
           cond->rhs.contents.variable=node;
  /*026*/      printf("variable\n");
           goto C4_005_VARIABLE_EX;
      /**/
       C4_006_STRING:
  /*019*/      cond->rhs.type=SIDE_NON_LITERAL;
           cond->rhs.contents.non_numeric_literal=token->value.string;
  /*028*/      printf("string2\n");
           goto C4_006_STRING_EX;
      /**/
       C4_007_RHS_END:
  /*006*/      eof=get_token(infile,token);
           goto C4_007_RHS_END_EX;
      /**/
       C2_001_LHS:
           goto C2_002_LHS_START;
       C2_002_LHS_START_EX:
           goto C2_003_LHS_BODY;
       C2_003_LHS_BODY_EX:
           goto C2_007_LHS_END;
       C2_007_LHS_END_EX:
       C2_001_LHS_A:
                switch(g2_001_LHS_A){
                case 0 : goto C2_001_EXIT01;break;
                }
      /**/
       C2_002_LHS_START:
  /*024*/      printf("lefthand side\n");
           goto C2_002_LHS_START_EX;
      /**/
       C2_003_LHS_BODY:
           if((
  /*C02*/         (token->token_type==NUMERIC)
))
                   goto C2_004_INTEGER;
           if((
  /*C03*/         (token->token_type==VARIABLE_NAME)
))
                   goto C2_005_VARIABLE;
           if((
  /*C04*/         (token->token_type==NON_NUMERIC_LITERAL)
))
                   goto C2_006_STRING;
       C2_004_INTEGER_EX:
       C2_005_VARIABLE_EX:
       C2_006_STRING_EX:
           goto C2_003_LHS_BODY_EX;
      /**/
       C2_004_INTEGER:
  /*003*/      cond->lhs.type=SIDE_LITERAL;
  /*008*/      cond->lhs.contents.numeric_literal=token->value.keyword_number;
  /*025*/      printf("numeric value \n");
           goto C2_004_INTEGER_EX;
      /**/
       C2_005_VARIABLE:
  /*009*/      node=look_for(token->value.var_values.unique,
                         token->value.var_values.hash,
                         symtab);
  /*013*/      cond->lhs.contents.variable=node;
           cond->lhs.type=SIDE_VAR;  
  /*026*/      printf("variable\n");
           goto C2_005_VARIABLE_EX;
      /**/
       C2_006_STRING:
  /*012*/      cond->lhs.type=SIDE_NON_LITERAL;
           cond->lhs.contents.non_numeric_literal=token->value.string;
  /*027*/      printf("string\n");
           goto C2_006_STRING_EX;
      /**/
       C2_007_LHS_END:
  /*006*/      eof=get_token(infile,token);
           goto C2_007_LHS_END_EX;
      /**/
      /*   Data Analysis Map*/
      /**/
      /*                         ------------- Data Analysis By -------------*/
      /**/
      /*                         BOX TYPE               OPERATION  ALLOCATION*/
      /*  Tree name: CONDS-BUILD*/
      /**/
      /*                         Leaf      :   3          Operations:   9*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   2*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   3   -->    LHS*/
      /*                                                  KEYWORDS*/
      /*                                                  RHS*/
      /**/
      /*  Tree name: GROUP-SUBTREE*/
      /**/
      /*                         Leaf      :  11          Operations:  11*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   3*/
      /*                         Sequences :   5*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: KEYWORDS*/
      /**/
      /*                         Leaf      :   3          Operations:   4*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   2*/
      /*                         Sequences :   5*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   2   -->    GROUP-SUBTREE*/
      /*                                                  GROUP-SUBTREE*/
      /**/
      /*  Tree name: RHS*/
      /**/
      /*                         Leaf      :   5          Operations:  10*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   1*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: LHS*/
      /**/
      /*                         Leaf      :   5          Operations:  10*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   1*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /**/
      /**/
veryend: ;
}
\end{verbatim}
