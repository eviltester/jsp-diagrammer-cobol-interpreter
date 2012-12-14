\begin{verbatim}
#include <stdio.h>
#include "alfile.h"
#include "staglist.h"
#include "node.h"
#include "alutil.h"
#include "symtab.h"
#include "token.h"

void main(){

FILE *infile,*outfile;
char currch,nextch,ch[100],*chp;
staggered_list *listpointer,*root=create_list_with_file("B:keywords");
SYMTAB_ENTRY **symtab=create_symbol_table_array(100);
int dat,length_of;
TOKEN *token,t;
NODE *node;


                int g2_001_DATA_STUFFSUB_A;
                int g3_001_SINGLE_SUBTREE_A;
                int g4_001_DOUBLE_SUBTREE_A;
                int g5_001_RELATIONAL_SUBTREE_A;
                int g6_001_WORD_SUBTREE_A;
      /**************************************************************************/
      /**************************************************************************/
      /******************* DRIVING PROCEDURE    B:\CONDSANY ********************/
      /**************************************************************************/
       PROCEDURE_DIVISION:
      /**/
      /** conds-analyser takes the probench .cnd*/
      /** file and tokenises it, ready for the*/
      /** next stage of conds analysis.*/
      /**/
       C1_001_CONDS_ANALYSER:
           goto C1_002_CONDS_START;
       C1_002_CONDS_START_EX:
           goto C1_003_CONDS;
       C1_003_CONDS_EX:
           goto C1_021_CONDS_END;
       C1_021_CONDS_END_EX:
           goto veryend;
      /**/
       C1_002_CONDS_START:
  /*028*/      token=&t;
  /*029*/      dat=GREATER_THAN;
  /*001*/      infile=open_input("b:altest.cnd");
  /*003*/      outfile=open_output("b:cndout.dat");
  /*008*/      load_symtab(symtab,"b:symtable.out");
           cross_reference(symtab,100);
  /*005*/      currch=getc(infile);
           if(currch!=EOF) nextch=getc(infile);
           goto C1_002_CONDS_START_EX;
      /**/
       C1_003_CONDS:
       C1_004_COND_GROUP_EX:
           if(!(
  /*C01*/         (currch==EOF)
))
                   goto C1_004_COND_GROUP;
           goto C1_003_CONDS_EX;
      /**/
      /** a condition group consists of a line*/
      /** with a condition number on it, followed*/
      /** by perhaps more lines*/
      /**/
       C1_004_COND_GROUP:
           goto C1_005_COND_NUM_LINE;
       C1_005_COND_NUM_LINE_EX:
           goto C1_015_REST_OF_GROUP;
       C1_015_REST_OF_GROUP_EX:
           goto C1_004_COND_GROUP_EX;
      /**/
       C1_005_COND_NUM_LINE:
           goto C1_006_COND_NUM;
       C1_006_COND_NUM_EX:
           goto C1_011_DATA;
       C1_011_DATA_EX:
           goto C1_005_COND_NUM_LINE_EX;
      /**/
      /** read the condition number, extract the*/
      /** numeric characters and turn them into an*/
      /** integer*/
      /**/
       C1_006_COND_NUM:
           goto C1_007_COND_NUM_START;
       C1_007_COND_NUM_START_EX:
           goto C1_008_COND_NUM_BODY;
       C1_008_COND_NUM_BODY_EX:
           goto C1_010_COND_NUM_END;
       C1_010_COND_NUM_END_EX:
           goto C1_006_COND_NUM_EX;
      /**/
       C1_007_COND_NUM_START:
  /*007*/      chp=ch;
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C1_007_COND_NUM_START_EX;
      /**/
       C1_008_COND_NUM_BODY:
       C1_009_COND_NUM_NUMBER_EX:
           if(!(
  /*C02*/         (currch==' ')
))
                   goto C1_009_COND_NUM_NUMBER;
           goto C1_008_COND_NUM_BODY_EX;
      /**/
       C1_009_COND_NUM_NUMBER:
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C1_009_COND_NUM_NUMBER_EX;
      /**/
       C1_010_COND_NUM_END:
  /*018*/      dat=str_to_int(ch);
  /*022*/      token->token_type=COND_NUM;token->value.keyword_number=dat;
  /*012*/      write_token(outfile,token);
           goto C1_010_COND_NUM_END_EX;
      /**/
       C1_011_DATA:
       C1_012_DATA_GROUP_EX:
           if(!(
  /*C03*/         (currch==EOF || currch=='\n')
))
                   goto C1_012_DATA_GROUP;
           goto C1_011_DATA_EX;
      /**/
       C1_012_DATA_GROUP:
           goto C1_013_DATA;
       C1_013_DATA_EX:
           goto C1_012_DATA_GROUP_EX;
      /**/
       C1_013_DATA:
           goto C1_014_DATA_STUFFSUB;
       C1_014_DATA_STUFFSUB_EX:
           goto C1_013_DATA_EX;
      /**/
       C1_014_DATA_STUFFSUB:
                g2_001_DATA_STUFFSUB_A=0;
           goto C2_001_DATA_STUFFSUB;
       C2_001_EXIT01:
           goto C1_014_DATA_STUFFSUB_EX;
      /**/
       C1_015_REST_OF_GROUP:
       C1_016_DATA_GROUP_EX:
           if(!(
  /*C12*/         (currch==EOF || currch=='C')
))
                   goto C1_016_DATA_GROUP;
           goto C1_015_REST_OF_GROUP_EX;
      /**/
       C1_016_DATA_GROUP:
           goto C1_017_DATA;
       C1_017_DATA_EX:
           goto C1_020_DATA_END;
       C1_020_DATA_END_EX:
           goto C1_016_DATA_GROUP_EX;
      /**/
       C1_017_DATA:
       C1_018_LINE_EX:
           if(!(
  /*C13*/         (currch=='\n' || currch==EOF)
))
                   goto C1_018_LINE;
           goto C1_017_DATA_EX;
      /**/
       C1_018_LINE:
           goto C1_019_DATA_STUFFSUB;
       C1_019_DATA_STUFFSUB_EX:
           goto C1_018_LINE_EX;
      /**/
       C1_019_DATA_STUFFSUB:
                g2_001_DATA_STUFFSUB_A=1;
           goto C2_001_DATA_STUFFSUB;
       C2_001_EXIT02:
           goto C1_019_DATA_STUFFSUB_EX;
      /**/
       C1_020_DATA_END:
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C1_020_DATA_END_EX;
      /**/
       C1_021_CONDS_END:
  /*002*/      close_file(infile);
  /*004*/      close_file(outfile);
           goto C1_021_CONDS_END_EX;
      /**/
      /** a data segment consists of blanks */
      /** followed by a token of some sort*/
      /**/
       C2_001_DATA_STUFFSUB:
           goto C2_002_BLANKS;
       C2_002_BLANKS_EX:
           goto C2_004_DATA;
       C2_004_DATA_EX:
       C2_001_DATA_STUFFSUB_A:
                switch(g2_001_DATA_STUFFSUB_A){
                case 0 : goto C2_001_EXIT01;break;
                case 1 : goto C2_001_EXIT02;break;
                }
      /**/
       C2_002_BLANKS:
       C2_003_BLANK_EX:
           if(!(
  /*C04*/         (currch!=' ')
))
                   goto C2_003_BLANK;
           goto C2_002_BLANKS_EX;
      /**/
       C2_003_BLANK:
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C2_003_BLANK_EX;
      /**/
      /** the token can be a string, integer,*/
      /** fullstop, releational operator*/
      /**/
       C2_004_DATA:
           if((
  /*C05*/         (currch=='"' || currch=='\'')
))
                   goto C2_005_NON_NUM_LITERAL;
           if((
  /*C06*/         (currch=='.')
))
                   goto C2_010_FULLSTOP;
           if((
  /*C18*/         (currch=='<' || currch=='>' || currch=='=')
))
                   goto C2_012_RELATIONAL_SYMBOL;
           if((
  /*C07*/         (currch!='"' &&
               currch!='\'' &&
               currch!='.' &&
               currch!='\n')
))
                   goto C2_014_WORD;
       C2_005_NON_NUM_LITERAL_EX:
       C2_010_FULLSTOP_EX:
       C2_012_RELATIONAL_SYMBOL_EX:
       C2_014_WORD_EX:
           goto C2_004_DATA_EX;
      /**/
       C2_005_NON_NUM_LITERAL:
           if((
  /*C08*/         (currch=='\'')
))
                   goto C2_006_SINGLE;
           if((
  /*C09*/         (currch=='"')
))
                   goto C2_008_DOUBLE;
       C2_006_SINGLE_EX:
       C2_008_DOUBLE_EX:
           goto C2_005_NON_NUM_LITERAL_EX;
      /**/
       C2_006_SINGLE:
           goto C2_007_SINGLE_SUBTREE;
       C2_007_SINGLE_SUBTREE_EX:
           goto C2_006_SINGLE_EX;
      /**/
       C2_007_SINGLE_SUBTREE:
                g3_001_SINGLE_SUBTREE_A=0;
           goto C3_001_SINGLE_SUBTREE;
       C3_001_EXIT01:
           goto C2_007_SINGLE_SUBTREE_EX;
      /**/
       C2_008_DOUBLE:
           goto C2_009_DOUBLE_SUBTREE;
       C2_009_DOUBLE_SUBTREE_EX:
           goto C2_008_DOUBLE_EX;
      /**/
       C2_009_DOUBLE_SUBTREE:
                g4_001_DOUBLE_SUBTREE_A=0;
           goto C4_001_DOUBLE_SUBTREE;
       C4_001_EXIT01:
           goto C2_009_DOUBLE_SUBTREE_EX;
      /**/
       C2_010_FULLSTOP:
           goto C2_011_PERIOD;
       C2_011_PERIOD_EX:
           goto C2_010_FULLSTOP_EX;
      /**/
       C2_011_PERIOD:
  /*013*/      token->token_type=FULLSTOP;
           token->value.keyword_number=FULLSTOP;
  /*012*/      write_token(outfile,token);
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C2_011_PERIOD_EX;
      /**/
       C2_012_RELATIONAL_SYMBOL:
           goto C2_013_RELATIONAL_SUBTREE;
       C2_013_RELATIONAL_SUBTREE_EX:
           goto C2_012_RELATIONAL_SYMBOL_EX;
      /**/
       C2_013_RELATIONAL_SUBTREE:
                g5_001_RELATIONAL_SUBTREE_A=0;
           goto C5_001_RELATIONAL_SUBTREE;
       C5_001_EXIT01:
           goto C2_013_RELATIONAL_SUBTREE_EX;
      /**/
       C2_014_WORD:
           goto C2_015_WORD_SUBTREE;
       C2_015_WORD_SUBTREE_EX:
           goto C2_014_WORD_EX;
      /**/
       C2_015_WORD_SUBTREE:
                g6_001_WORD_SUBTREE_A=0;
           goto C6_001_WORD_SUBTREE;
       C6_001_EXIT01:
           goto C2_015_WORD_SUBTREE_EX;
      /**/
       C5_001_RELATIONAL_SUBTREE:
           goto C5_002_RELATIONAL_START;
       C5_002_RELATIONAL_START_EX:
           goto C5_009_RELATIONAL_END;
       C5_009_RELATIONAL_END_EX:
       C5_001_RELATIONAL_SUBTREE_A:
                switch(g5_001_RELATIONAL_SUBTREE_A){
                case 0 : goto C5_001_EXIT01;break;
                }
      /**/
       C5_002_RELATIONAL_START:
           if((
  /*C20*/         (currch=='>')
))
                   goto C5_003_GREATER_THAN;
           if((
  /*C19*/         (currch=='<')
))
                   goto C5_005_LESS_THAN;
           if((
  /*C21*/         (currch=='=')
))
                   goto C5_007_EQUALS;
       C5_003_GREATER_THAN_EX:
       C5_005_LESS_THAN_EX:
       C5_007_EQUALS_EX:
           goto C5_002_RELATIONAL_START_EX;
      /**/
       C5_003_GREATER_THAN:
           goto C5_004_GREATER_SYMBOL;
       C5_004_GREATER_SYMBOL_EX:
           goto C5_003_GREATER_THAN_EX;
      /**/
       C5_004_GREATER_SYMBOL:
  /*029*/      dat=GREATER_THAN;
           goto C5_004_GREATER_SYMBOL_EX;
      /**/
       C5_005_LESS_THAN:
           goto C5_006_LESS;
       C5_006_LESS_EX:
           goto C5_005_LESS_THAN_EX;
      /**/
       C5_006_LESS:
  /*030*/      dat=LESS_THAN;
           goto C5_006_LESS_EX;
      /**/
       C5_007_EQUALS:
           goto C5_008_EQUAL;
       C5_008_EQUAL_EX:
           goto C5_007_EQUALS_EX;
      /**/
       C5_008_EQUAL:
  /*031*/      dat=EQUAL_TO;
           goto C5_008_EQUAL_EX;
      /**/
       C5_009_RELATIONAL_END:
  /*032*/      token->token_type=RELATIONAL_OP;token->value.keyword_number=dat;
  /*012*/      write_token(outfile,token);
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C5_009_RELATIONAL_END_EX;
      /**/
       C6_001_WORD_SUBTREE:
           goto C6_002_WORD_START;
       C6_002_WORD_START_EX:
           goto C6_003_WORD_BODY;
       C6_003_WORD_BODY_EX:
       C6_001_WORD_SUBTREE_A:
                switch(g6_001_WORD_SUBTREE_A){
                case 0 : goto C6_001_EXIT01;break;
                }
      /**/
       C6_002_WORD_START:
  /*007*/      chp=ch;
  /*019*/      *chp='\0';
           goto C6_002_WORD_START_EX;
      /**/
       C6_003_WORD_BODY:
           goto C6_004_KEYWORD;
       C6_004_KEYWORD_EX:
       C6_009_NON_KEYWOR_D_EX:
           goto C6_003_WORD_BODY_EX;
      /**/
       C6_004_KEYWORD:
           goto C6_005_KEYWORD_START;
       C6_005_KEYWORD_START_EX:
           goto C6_006_KEYWORD_BODY;
       C6_006_KEYWORD_BODY_EX:
           goto C6_008_KEYWORD_END;
       C6_008_KEYWORD_END_EX:
           goto C6_004_KEYWORD_EX;
      /**/
       C6_005_KEYWORD_START:
  /*009*/      listpointer=root;
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*010*/      listpointer=check_pointer(listpointer,currch);
           if((
  /*Q01*/         (!isupper(currch)) && currch!='-'
))
                   goto C6_009_NON_KEYWOR_D;
           if((
  /*Q02*/         listpointer==NULL
))
                   goto C6_009_NON_KEYWOR_D;
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C6_005_KEYWORD_START_EX;
      /**/
       C6_006_KEYWORD_BODY:
       C6_007_KEYWORD_CHAR_EX:
           if(!(
  /*C10*/         (currch==' ' || currch=='\n' ||
               currch=='.' || currch==EOF)
))
                   goto C6_007_KEYWORD_CHAR;
           goto C6_006_KEYWORD_BODY_EX;
      /**/
       C6_007_KEYWORD_CHAR:
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*010*/      listpointer=check_pointer(listpointer,currch);
           if((
  /*Q01*/         (!isupper(currch)) && currch!='-'
))
                   goto C6_009_NON_KEYWOR_D;
           if((
  /*Q02*/         listpointer==NULL
))
                   goto C6_009_NON_KEYWOR_D;
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C6_007_KEYWORD_CHAR_EX;
      /**/
       C6_008_KEYWORD_END:
  /*011*/      dat=get_data(listpointer);
           if((
  /*Q03*/         dat==NULL
))
                   goto C6_009_NON_KEYWOR_D;
  /*014*/      token->token_type=KEYWORD;
           token->value.keyword_number=dat;
  /*012*/      write_token(outfile,token);
           goto C6_008_KEYWORD_END_EX;
      /**/
       C6_009_NON_KEYWOR_D:
           goto C6_010_CHARS;
       C6_010_CHARS_EX:
           goto C6_015_CHOICE;
       C6_015_CHOICE_EX:
           goto C6_009_NON_KEYWOR_D_EX;
      /**/
       C6_010_CHARS:
           goto C6_011_CHARS_START;
       C6_011_CHARS_START_EX:
           goto C6_012_CHARS_BODY;
       C6_012_CHARS_BODY_EX:
           goto C6_014_CHARS_END;
       C6_014_CHARS_END_EX:
           goto C6_010_CHARS_EX;
      /**/
       C6_011_CHARS_START:
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C6_011_CHARS_START_EX;
      /**/
       C6_012_CHARS_BODY:
       C6_013_CHAR_EX:
           if(!(
  /*C10*/         (currch==' ' || currch=='\n' ||
               currch=='.' || currch==EOF)
))
                   goto C6_013_CHAR;
           goto C6_012_CHARS_BODY_EX;
      /**/
       C6_013_CHAR:
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C6_013_CHAR_EX;
      /**/
       C6_014_CHARS_END:
  /*027*/      node=look_for_by_name(ch,symtab);
           goto C6_014_CHARS_END_EX;
      /**/
       C6_015_CHOICE:
           if((
  /*C11*/         (node==NULL && isdigit(ch[0]))
))
                   goto C6_016_POSSIBLE_NUMBER;
           if((
  /*C22*/         (node!=NULL)
))
                   goto C6_018_VARIABLE;
       C6_016_POSSIBLE_NUMBER_EX:
       C6_018_VARIABLE_EX:
           goto C6_015_CHOICE_EX;
      /**/
       C6_016_POSSIBLE_NUMBER:
           goto C6_017_NUMBER;
       C6_017_NUMBER_EX:
           goto C6_016_POSSIBLE_NUMBER_EX;
      /**/
       C6_017_NUMBER:
  /*018*/      dat=str_to_int(ch);
  /*024*/      token->token_type=NUMERIC;token->value.keyword_number=dat;
  /*012*/      write_token(outfile,token);
           goto C6_017_NUMBER_EX;
      /**/
       C6_018_VARIABLE:
           goto C6_019_VAR_START;
       C6_019_VAR_START_EX:
           goto C6_018_VARIABLE_EX;
      /**/
       C6_019_VAR_START:
  /*023*/      token->token_type=VARIABLE_NAME;token->value.var_values.hash=node->own.hash;
           token->value.var_values.unique=node->own.unique;
  /*012*/      write_token(outfile,token);
           goto C6_019_VAR_START_EX;
      /**/
       C3_001_SINGLE_SUBTREE:
           goto C3_002__START;
       C3_002__START_EX:
           goto C3_003__BODY;
       C3_003__BODY_EX:
           goto C3_007__END;
       C3_007__END_EX:
       C3_001_SINGLE_SUBTREE_A:
                switch(g3_001_SINGLE_SUBTREE_A){
                case 0 : goto C3_001_EXIT01;break;
                }
      /**/
       C3_002__START:
  /*007*/      chp=ch;
  /*019*/      *chp='\0';
  /*025*/      length_of=0;
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C3_002__START_EX;
      /**/
       C3_003__BODY:
       C3_004_CHAR_EX:
           if(!(
  /*C16*/         (currch=='\'' && nextch!='\'')
))
                   goto C3_004_CHAR;
           goto C3_003__BODY_EX;
      /**/
       C3_004_CHAR:
           if((
  /*C14*/         (currch=='\'' && nextch=='\'')
))
                   goto C3_005_QUOTE_QUOTE;
           if(!(
  /*C14*/         (currch=='\'' && nextch=='\'')
))
                   goto C3_006_ANY;
       C3_005_QUOTE_QUOTE_EX:
       C3_006_ANY_EX:
           goto C3_004_CHAR_EX;
      /**/
       C3_005_QUOTE_QUOTE:
  /*026*/      length_of++;
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C3_005_QUOTE_QUOTE_EX;
      /**/
       C3_006_ANY:
  /*026*/      length_of++;
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C3_006_ANY_EX;
      /**/
       C3_007__END:
  /*017*/      token->token_type=NON_NUMERIC_LITERAL_LENGTH;
           token->value.keyword_number=length_of;
  /*012*/      write_token(outfile,token);
  /*016*/      token->token_type=NON_NUMERIC_LITERAL;
           token->value.string=ch;
  /*012*/      write_token(outfile,token);
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C3_007__END_EX;
      /**/
       C4_001_DOUBLE_SUBTREE:
           goto C4_002__START;
       C4_002__START_EX:
           goto C4_003__BODY;
       C4_003__BODY_EX:
           goto C4_007__END;
       C4_007__END_EX:
       C4_001_DOUBLE_SUBTREE_A:
                switch(g4_001_DOUBLE_SUBTREE_A){
                case 0 : goto C4_001_EXIT01;break;
                }
      /**/
       C4_002__START:
  /*007*/      chp=ch;
  /*019*/      *chp='\0';
  /*025*/      length_of=0;
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C4_002__START_EX;
      /**/
       C4_003__BODY:
       C4_004_CHAR_EX:
           if(!(
  /*C17*/         (currch=='"' && nextch!='"')
))
                   goto C4_004_CHAR;
           goto C4_003__BODY_EX;
      /**/
       C4_004_CHAR:
           if((
  /*C15*/         (currch=='"' && nextch=='"')
))
                   goto C4_005_QUOTE_QUOTE;
           if(!(
  /*C15*/         (currch=='"' && nextch=='"')
))
                   goto C4_006_ANY;
       C4_005_QUOTE_QUOTE_EX:
       C4_006_ANY_EX:
           goto C4_004_CHAR_EX;
      /**/
       C4_005_QUOTE_QUOTE:
  /*026*/      length_of++;
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C4_005_QUOTE_QUOTE_EX;
      /**/
       C4_006_ANY:
  /*026*/      length_of++;
  /*021*/      *chp=currch;
  /*020*/      chp++;
  /*019*/      *chp='\0';
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C4_006_ANY_EX;
      /**/
       C4_007__END:
  /*017*/      token->token_type=NON_NUMERIC_LITERAL_LENGTH;
           token->value.keyword_number=length_of;
  /*012*/      write_token(outfile,token);
  /*016*/      token->token_type=NON_NUMERIC_LITERAL;
           token->value.string=ch;
  /*012*/      write_token(outfile,token);
  /*006*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C4_007__END_EX;
      /**/
      /*   Data Analysis Map*/
      /**/
      /*                         ------------- Data Analysis By -------------*/
      /**/
      /*                         BOX TYPE               OPERATION  ALLOCATION*/
      /*  Tree name: CONDS-ANALYSER*/
      /**/
      /*                         Leaf      :   6          Operations:  18*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   8*/
      /*                         Iterations:   5*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   2   -->    DATA-STUFFSUB*/
      /*                                                  DATA-STUFFSUB*/
      /**/
      /*  Tree name: DATA-STUFFSUB*/
      /**/
      /*                         Leaf      :   2          Operations:   4*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   2*/
      /*                         Sequences :   6*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   4   -->    SINGLE-SUBTREE*/
      /*                                                  DOUBLE-SUBTREE*/
      /*                                                  RELATIONAL-SUBTREE*/
      /*                                                  WORD-SUBTREE*/
      /**/
      /*  Tree name: RELATIONAL-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:   6*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   4*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: WORD-SUBTREE*/
      /**/
      /*                         Leaf      :   9          Operations:  27*/
      /*                                                  Quits     :   5*/
      /*                         Selections:   1*/
      /*                         Sequences :   6*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   1*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: SINGLE-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:  20*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   1*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: DOUBLE-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:  20*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   1*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /**/
      /**/
veryend: ;
}
\end{verbatim}
