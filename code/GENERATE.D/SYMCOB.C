\begin{verbatim}
#include <stdio.h>
#include "alutil.h"
#include "alstring.h"
#include "alfile.h"
#include "node.h"
#include "stckbyar.h"
#include "symtab.h"
#include "keywords.h"
#include "token.h"

    
void main(){

 FILE *infile,*outfile;
 NODE *current,*first_01;
 TOKEN *token,t;
 STACKBYARRAY *stack=create_stack_by_array(50);
 SYMTAB_ENTRY **symtab=create_symbol_table_array(SYMTAB_ARRAY_SIZE);
 int unique_no=1;
 int hashval=0;
 int number_of;
 char *pointer,*pointer2,count_string[20];
 int alfeof=0;


                int g2_001_FORMAT_OR_STOP_A;
                int g3_001_LEVEL_NUMBER_A;
                int g5_001_NINE_SUBTREE_A;
                int g6_001_X_SUBTREE_A;
                int g4_001_FORMAT_SUBTREE_A;
      /**************************************************************************/
      /**************************************************************************/
      /******************** DRIVING PROCEDURE    B:\SYMCOB *********************/
      /**************************************************************************/
       PROCEDURE_DIVISION:
      /**/
       C1_001_GENERATE_SYMBOL:
           goto C1_002_SYMBOL_START;
       C1_002_SYMBOL_START_EX:
           goto C1_003_BEFORE_WORKING;
       C1_003_BEFORE_WORKING_EX:
           goto C1_005_SECTION;
       C1_005_SECTION_EX:
           goto C1_006_WORKING_STORAGE;
       C1_006_WORKING_STORAGE_EX:
           goto C1_021_END;
       C1_021_END_EX:
           goto veryend;
      /**/
       C1_002_SYMBOL_START:
  /*001*/      infile=open_input("b:testout2.dat");
           outfile=open_output("b:symtable.out"); 
           token=&t;
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C1_002_SYMBOL_START_EX;
      /**/
       C1_003_BEFORE_WORKING:
       C1_004_JUST_DATA_EX:
           if(!(
  /*C01*/         (token->value.keyword_number==WORKING_STORAGE)
))
                   goto C1_004_JUST_DATA;
           goto C1_003_BEFORE_WORKING_EX;
      /**/
       C1_004_JUST_DATA:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C1_004_JUST_DATA_EX;
      /**/
       C1_005_SECTION:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C1_005_SECTION_EX;
      /**/
       C1_006_WORKING_STORAGE:
           goto C1_007_FIRST_01;
       C1_007_FIRST_01_EX:
           goto C1_012_REST;
       C1_012_REST_EX:
           goto C1_006_WORKING_STORAGE_EX;
      /**/
       C1_007_FIRST_01:
           goto C1_008_NUM;
       C1_008_NUM_EX:
           goto C1_009_VARIABLE_NAME;
       C1_009_VARIABLE_NAME_EX:
           goto C1_010_FORMAT_OR_STOP;
       C1_010_FORMAT_OR_STOP_EX:
           goto C1_011_END_LEVEL;
       C1_011_END_LEVEL_EX:
           goto C1_007_FIRST_01_EX;
      /**/
       C1_008_NUM:
  /*003*/      current=create_node();
           current->level=str_to_int(token->value.string);
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C1_008_NUM_EX;
      /**/
       C1_009_VARIABLE_NAME:
  /*007*/      NAME(current)=token->value.string;
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
  /*012*/      hashval=hash(NAME(current))%SYMTAB_ARRAY_SIZE;
           current->own.hash=hashval;
           add_node_to_sym(current,hashval,symtab);
           goto C1_009_VARIABLE_NAME_EX;
      /**/
       C1_010_FORMAT_OR_STOP:
                g2_001_FORMAT_OR_STOP_A=0;
           goto C2_001_FORMAT_OR_STOP;
       C2_001_EXIT01:
           goto C1_010_FORMAT_OR_STOP_EX;
      /**/
       C1_011_END_LEVEL:
  /*011*/      PARENT(current)=NULL;
           first_01=current;
  /*010*/      stackpush(stack,current);
  /*013*/      current->own.unique=unique_no;
           unique_no++;
           goto C1_011_END_LEVEL_EX;
      /**/
       C1_012_REST:
       C1_013_LEVEL_EX:
           if(!(
  /*C02*/         (alfeof==1)
))
                   goto C1_013_LEVEL;
           goto C1_012_REST_EX;
      /**/
       C1_013_LEVEL:
           goto C1_014_LEVEL_NUMBER;
       C1_014_LEVEL_NUMBER_EX:
           goto C1_015_VARIABLE_NAME;
       C1_015_VARIABLE_NAME_EX:
           goto C1_016_FORMAT_OR_STOP;
       C1_016_FORMAT_OR_STOP_EX:
           goto C1_017_END_LEVEL;
       C1_017_END_LEVEL_EX:
           goto C1_013_LEVEL_EX;
      /**/
       C1_014_LEVEL_NUMBER:
                g3_001_LEVEL_NUMBER_A=0;
           goto C3_001_LEVEL_NUMBER;
       C3_001_EXIT01:
           goto C1_014_LEVEL_NUMBER_EX;
      /**/
       C1_015_VARIABLE_NAME:
  /*007*/      NAME(current)=token->value.string;
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
  /*012*/      hashval=hash(NAME(current))%SYMTAB_ARRAY_SIZE;
           current->own.hash=hashval;
           add_node_to_sym(current,hashval,symtab);
           goto C1_015_VARIABLE_NAME_EX;
      /**/
       C1_016_FORMAT_OR_STOP:
                g2_001_FORMAT_OR_STOP_A=1;
           goto C2_001_FORMAT_OR_STOP;
       C2_001_EXIT02:
           goto C1_016_FORMAT_OR_STOP_EX;
      /**/
       C1_017_END_LEVEL:
           goto C1_018_POSS_OVERWRITE;
       C1_018_POSS_OVERWRITE_EX:
           goto C1_020_END;
       C1_020_END_EX:
           goto C1_017_END_LEVEL_EX;
      /**/
       C1_018_POSS_OVERWRITE:
           if((
  /*C04*/         (current->level==stacktop(stack)->level)
))
                   goto C1_019_OVERWRITE;
       C1_019_OVERWRITE_EX:
           goto C1_018_POSS_OVERWRITE_EX;
      /**/
       C1_019_OVERWRITE:
  /*005*/      stackpop(stack);
           goto C1_019_OVERWRITE_EX;
      /**/
       C1_020_END:
  /*010*/      stackpush(stack,current);
  /*013*/      current->own.unique=unique_no;
           unique_no++;
           goto C1_020_END_EX;
      /**/
       C1_021_END:
  /*014*/      close_file(infile);
           save_nodes(symtab,outfile);
           close_file(outfile);
           goto C1_021_END_EX;
      /**/
       C4_001_FORMAT_SUBTREE:
           goto C4_002_PICTURE;
       C4_002_PICTURE_EX:
           goto C4_003_LIMITED;
       C4_003_LIMITED_EX:
           goto C4_010_FULLSTOP;
       C4_010_FULLSTOP_EX:
       C4_001_FORMAT_SUBTREE_A:
                switch(g4_001_FORMAT_SUBTREE_A){
                case 0 : goto C4_001_EXIT02;break;
                }
      /**/
       C4_002_PICTURE:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
  /*016*/      pointer=token->value.string;
  /*008*/      current->info->type=VARIABLE;
           goto C4_002_PICTURE_EX;
      /**/
       C4_003_LIMITED:
           if((
  /*C08*/         (*pointer=='9')
))
                   goto C4_004_NINE;
           if(!(
  /*C08*/         (*pointer=='9')
))
                   goto C4_007_X;
       C4_004_NINE_EX:
       C4_007_X_EX:
           goto C4_003_LIMITED_EX;
      /**/
       C4_004_NINE:
           goto C4_005_NINE_START;
       C4_005_NINE_START_EX:
           goto C4_006_NINE_SUBTREE;
       C4_006_NINE_SUBTREE_EX:
           goto C4_004_NINE_EX;
      /**/
       C4_005_NINE_START:
  /*022*/      current->info->type=INT;
  /*015*/      number_of=0;
  /*017*/      pointer++;
           goto C4_005_NINE_START_EX;
      /**/
       C4_006_NINE_SUBTREE:
                g5_001_NINE_SUBTREE_A=0;
           goto C5_001_NINE_SUBTREE;
       C5_001_EXIT01:
           goto C4_006_NINE_SUBTREE_EX;
      /**/
       C4_007_X:
           goto C4_008_X_START;
       C4_008_X_START_EX:
           goto C4_009_X_SUBTREE;
       C4_009_X_SUBTREE_EX:
           goto C4_007_X_EX;
      /**/
       C4_008_X_START:
  /*023*/      current->info->type=CHAR;
  /*015*/      number_of=0;
  /*017*/      pointer++;
           goto C4_008_X_START_EX;
      /**/
       C4_009_X_SUBTREE:
                g6_001_X_SUBTREE_A=0;
           goto C6_001_X_SUBTREE;
       C6_001_EXIT01:
           goto C4_009_X_SUBTREE_EX;
      /**/
       C4_010_FULLSTOP:
           goto C4_010_FULLSTOP_EX;
      /**/
       C3_001_LEVEL_NUMBER:
           goto C3_002_NUMBER_START;
       C3_002_NUMBER_START_EX:
           goto C3_003_NUMBER_BODY;
       C3_003_NUMBER_BODY_EX:
           goto C3_011_NUMBER_END;
       C3_011_NUMBER_END_EX:
       C3_001_LEVEL_NUMBER_A:
                switch(g3_001_LEVEL_NUMBER_A){
                case 0 : goto C3_001_EXIT01;break;
                }
      /**/
       C3_002_NUMBER_START:
  /*003*/      current=create_node();
           current->level=str_to_int(token->value.string);
           goto C3_002_NUMBER_START_EX;
      /**/
       C3_003_NUMBER_BODY:
           if((
  /*C03*/         (current->level > stacktop(stack)->level)
))
                   goto C3_004_FURTHER_DOWN;
           if((
  /*C05*/         (current->level < stacktop(stack)->level)
))
                   goto C3_005_BACK_UP;
           if((
  /*C04*/         (current->level==stacktop(stack)->level)
))
                   goto C3_010_SAME;
       C3_004_FURTHER_DOWN_EX:
       C3_005_BACK_UP_EX:
       C3_010_SAME_EX:
           goto C3_003_NUMBER_BODY_EX;
      /**/
       C3_004_FURTHER_DOWN:
  /*004*/      PARENT(current)=stacktop(stack);
           CHILD(stacktop(stack))=current;
           goto C3_004_FURTHER_DOWN_EX;
      /**/
       C3_005_BACK_UP:
           goto C3_006_BUS;
       C3_006_BUS_EX:
           goto C3_007_BUB;
       C3_007_BUB_EX:
           goto C3_009_BUE;
       C3_009_BUE_EX:
           goto C3_005_BACK_UP_EX;
      /**/
       C3_006_BUS:
           goto C3_006_BUS_EX;
      /**/
       C3_007_BUB:
       C3_008_LEVEL_EX:
           if(!(
  /*C04*/         (current->level==stacktop(stack)->level)
))
                   goto C3_008_LEVEL;
           goto C3_007_BUB_EX;
      /**/
       C3_008_LEVEL:
  /*005*/      stackpop(stack);
           goto C3_008_LEVEL_EX;
      /**/
       C3_009_BUE:
  /*006*/      SIBLING(stacktop(stack))=current;
           PARENT(current)=PARENT(stacktop(stack));
           goto C3_009_BUE_EX;
      /**/
       C3_010_SAME:
  /*006*/      SIBLING(stacktop(stack))=current;
           PARENT(current)=PARENT(stacktop(stack));
           goto C3_010_SAME_EX;
      /**/
       C3_011_NUMBER_END:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C3_011_NUMBER_END_EX;
      /**/
       C2_001_FORMAT_OR_STOP:
           goto C2_002_POSS_FORMAT;
       C2_002_POSS_FORMAT_EX:
           goto C2_006_NEXT;
       C2_006_NEXT_EX:
       C2_001_FORMAT_OR_STOP_A:
                switch(g2_001_FORMAT_OR_STOP_A){
                case 0 : goto C2_001_EXIT01;break;
                case 1 : goto C2_001_EXIT02;break;
                }
      /**/
       C2_002_POSS_FORMAT:
           if(!(
  /*C06*/         (token->token_type==FULLSTOP)
))
                   goto C2_003_FORMAT;
           if((
  /*C06*/         (token->token_type==FULLSTOP)
))
                   goto C2_005_FULLSTOP;
       C2_003_FORMAT_EX:
       C2_005_FULLSTOP_EX:
           goto C2_002_POSS_FORMAT_EX;
      /**/
       C2_003_FORMAT:
           goto C2_004_FORMAT_SUBTREE;
       C2_004_FORMAT_SUBTREE_EX:
           goto C2_003_FORMAT_EX;
      /**/
       C2_004_FORMAT_SUBTREE:
                g4_001_FORMAT_SUBTREE_A=0;
           goto C4_001_FORMAT_SUBTREE;
       C4_001_EXIT02:
           goto C2_004_FORMAT_SUBTREE_EX;
      /**/
       C2_005_FULLSTOP:
  /*009*/      current->info->type=QUALIFIER;
           goto C2_005_FULLSTOP_EX;
      /**/
       C2_006_NEXT:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C2_006_NEXT_EX;
      /**/
       C5_001_NINE_SUBTREE:
           goto C5_002_NINE_BODY;
       C5_002_NINE_BODY_EX:
       C5_001_NINE_SUBTREE_A:
                switch(g5_001_NINE_SUBTREE_A){
                case 0 : goto C5_001_EXIT01;break;
                }
      /**/
       C5_002_NINE_BODY:
       C5_003_NINE_CHAR_EX:
           if(!(
  /*C06*/         (token->token_type==FULLSTOP)
))
                   goto C5_003_NINE_CHAR;
           goto C5_002_NINE_BODY_EX;
      /**/
       C5_003_NINE_CHAR:
           goto C5_004_PIECES;
       C5_004_PIECES_EX:
           goto C5_017_END;
       C5_017_END_EX:
           goto C5_003_NINE_CHAR_EX;
      /**/
       C5_004_PIECES:
           if((
  /*C10*/         (token->token_type==OPEN_BRACE)
))
                   goto C5_005_BRACE_N9;
           if((
  /*C08*/         (*pointer=='9')
))
                   goto C5_012_ONLY_9;
       C5_005_BRACE_N9_EX:
       C5_012_ONLY_9_EX:
           goto C5_004_PIECES_EX;
      /**/
       C5_005_BRACE_N9:
           goto C5_006_OPEN_BRACE;
       C5_006_OPEN_BRACE_EX:
           goto C5_007_N9;
       C5_007_N9_EX:
           goto C5_011_CLOSE_BRAC_E;
       C5_011_CLOSE_BRAC_E_EX:
           goto C5_005_BRACE_N9_EX;
      /**/
       C5_006_OPEN_BRACE:
  /*020*/      pointer2=count_string;
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
  /*016*/      pointer=token->value.string;
           goto C5_006_OPEN_BRACE_EX;
      /**/
       C5_007_N9:
           goto C5_008_NUM_CHARS;
       C5_008_NUM_CHARS_EX:
           goto C5_010_NUM_END;
       C5_010_NUM_END_EX:
           goto C5_007_N9_EX;
      /**/
       C5_008_NUM_CHARS:
       C5_009_NUM_CHAR_EX:
           if(!(
  /*C07*/         (*pointer=='\0')
))
                   goto C5_009_NUM_CHAR;
           goto C5_008_NUM_CHARS_EX;
      /**/
       C5_009_NUM_CHAR:
  /*019*/      *pointer2=*pointer;
           pointer++;
           pointer2++;
           goto C5_009_NUM_CHAR_EX;
      /**/
       C5_010_NUM_END:
  /*021*/      *pointer2='\0';
           number_of+=str_to_int(count_string);
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C5_010_NUM_END_EX;
      /**/
       C5_011_CLOSE_BRAC_E:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C5_011_CLOSE_BRAC_E_EX;
      /**/
       C5_012_ONLY_9:
           goto C5_013_ONLY9START;
       C5_013_ONLY9START_EX:
           goto C5_014_ONLY9BODY;
       C5_014_ONLY9BODY_EX:
           goto C5_016_ONLY_NINE_END;
       C5_016_ONLY_NINE_END_EX:
           goto C5_012_ONLY_9_EX;
      /**/
       C5_013_ONLY9START:
  /*018*/      number_of++;
           goto C5_013_ONLY9START_EX;
      /**/
       C5_014_ONLY9BODY:
       C5_015_NINE_EX:
           if(!(
  /*C07*/         (*pointer=='\0')
))
                   goto C5_015_NINE;
           goto C5_014_ONLY9BODY_EX;
      /**/
       C5_015_NINE:
  /*018*/      number_of++;
  /*017*/      pointer++;
  /*026*/      current->info->data_c=NULL;
           current->info->data_n=0;
           goto C5_015_NINE_EX;
      /**/
       C5_016_ONLY_NINE_END:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C5_016_ONLY_NINE_END_EX;
      /**/
       C5_017_END:
  /*016*/      pointer=token->value.string;
           goto C5_017_END_EX;
      /**/
       C6_001_X_SUBTREE:
           goto C6_002_X_BODY;
       C6_002_X_BODY_EX:
       C6_001_X_SUBTREE_A:
                switch(g6_001_X_SUBTREE_A){
                case 0 : goto C6_001_EXIT01;break;
                }
      /**/
       C6_002_X_BODY:
       C6_003_X_CHAR_EX:
           if(!(
  /*C06*/         (token->token_type==FULLSTOP)
))
                   goto C6_003_X_CHAR;
           goto C6_002_X_BODY_EX;
      /**/
       C6_003_X_CHAR:
           goto C6_004_PIECES;
       C6_004_PIECES_EX:
           goto C6_016_END;
       C6_016_END_EX:
           goto C6_003_X_CHAR_EX;
      /**/
       C6_004_PIECES:
           if((
  /*C10*/         (token->token_type==OPEN_BRACE)
))
                   goto C6_005_BRACE_NX;
           if((
  /*C09*/         (*pointer=='X')
))
                   goto C6_012_ONLY_X;
       C6_005_BRACE_NX_EX:
       C6_012_ONLY_X_EX:
           goto C6_004_PIECES_EX;
      /**/
       C6_005_BRACE_NX:
           goto C6_006_OPEN_BRACE;
       C6_006_OPEN_BRACE_EX:
           goto C6_007_NX;
       C6_007_NX_EX:
           goto C6_011_CLOSE_BRAC_E;
       C6_011_CLOSE_BRAC_E_EX:
           goto C6_005_BRACE_NX_EX;
      /**/
       C6_006_OPEN_BRACE:
  /*020*/      pointer2=count_string;
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
  /*016*/      pointer=token->value.string;
           goto C6_006_OPEN_BRACE_EX;
      /**/
       C6_007_NX:
           goto C6_008_NUM_CHARS;
       C6_008_NUM_CHARS_EX:
           goto C6_010_NUM_END;
       C6_010_NUM_END_EX:
           goto C6_007_NX_EX;
      /**/
       C6_008_NUM_CHARS:
       C6_009_NUM_CHAR_EX:
           if(!(
  /*C07*/         (*pointer=='\0')
))
                   goto C6_009_NUM_CHAR;
           goto C6_008_NUM_CHARS_EX;
      /**/
       C6_009_NUM_CHAR:
  /*019*/      *pointer2=*pointer;
           pointer++;
           pointer2++;
           goto C6_009_NUM_CHAR_EX;
      /**/
       C6_010_NUM_END:
  /*021*/      *pointer2='\0';
           number_of+=str_to_int(count_string);
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C6_010_NUM_END_EX;
      /**/
       C6_011_CLOSE_BRAC_E:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C6_011_CLOSE_BRAC_E_EX;
      /**/
       C6_012_ONLY_X:
           goto C6_013_ONLYXBODY;
       C6_013_ONLYXBODY_EX:
           goto C6_015_ONLYXEND;
       C6_015_ONLYXEND_EX:
           goto C6_012_ONLY_X_EX;
      /**/
       C6_013_ONLYXBODY:
       C6_014_X_EX:
           if(!(
  /*C07*/         (*pointer=='\0')
))
                   goto C6_014_X;
           goto C6_013_ONLYXBODY_EX;
      /**/
       C6_014_X:
  /*018*/      number_of++;
  /*017*/      pointer++;
  /*024*/      current->info->data_c=(char *)malloc(number_of+1);
           current->info->data_c[0]='\0';
  /*025*/      current->info->data_n=number_of;
           goto C6_014_X_EX;
      /**/
       C6_015_ONLYXEND:
  /*002*/      if(!feof(infile)) alfeof=get_token(infile,token);
           goto C6_015_ONLYXEND_EX;
      /**/
       C6_016_END:
  /*016*/      pointer=token->value.string;
           goto C6_016_END_EX;
      /**/
      /*   Data Analysis Map*/
      /**/
      /*                         ------------- Data Analysis By -------------*/
      /**/
      /*                         BOX TYPE               OPERATION  ALLOCATION*/
      /*  Tree name: GENERATE-SYMBOL*/
      /**/
      /*                         Leaf      :  10          Operations:  21*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   5*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   3   -->    FORMAT_OR-STOP*/
      /*                                                  LEVEL-NUMBER*/
      /*                                                  FORMAT_OR-STOP*/
      /**/
      /*  Tree name: FORMAT-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:   9*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   3*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   2   -->    NINE-SUBTREE*/
      /*                                                  X_SUBTREE*/
      /**/
      /*  Tree name: LEVEL-NUMBER*/
      /**/
      /*                         Leaf      :   7          Operations:   6*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   2*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: FORMAT_OR-STOP*/
      /**/
      /*                         Leaf      :   2          Operations:   2*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   2*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   1   -->    FORMAT-SUBTREE*/
      /**/
      /*  Tree name: NINE-SUBTREE*/
      /**/
      /*                         Leaf      :   8          Operations:  13*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   5*/
      /*                         Iterations:   3*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: X_SUBTREE*/
      /**/
      /*                         Leaf      :   7          Operations:  13*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   5*/
      /*                         Iterations:   3*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /**/
      /**/
veryend: ;
}
\end{verbatim}
