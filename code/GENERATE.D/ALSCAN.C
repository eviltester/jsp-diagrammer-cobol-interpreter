\begin{verbatim}
#include <stdio.h>
#include "alstring.h"
#include "alfile.h"
#include "staglist.h"
#include "token.h"


    
void main(){

 FILE *infile,*outfile;
 char currch,nextch,*ch,chp[100];
 staggered_list *listpointer,*root=create_list_with_file("B:keywords");
 int dat,length_of;
 TOKEN *token,t;
 


                int g2_001_DATA_A;
                int g3_001_DOUBLE_SUBTREE_A;
                int g4_001_SINGLE_SUBTREE_A;
                int g5_001_KEYWORD_OR_WORD_A;
      /**************************************************************************/
      /**************************************************************************/
      /******************** DRIVING PROCEDURE    B:\ALSCAN *********************/
      /**************************************************************************/
       PROCEDURE_DIVISION:
      /**/
      /** takes the output from allinescan*/
      /** which is one line with all the cobol*/
      /** details on it, rather than cobol details*/
      /** */
      /** being spread across a number of lines*/
      /**/
       C1_001_SCAN:
           goto C1_002_SCAN_START;
       C1_002_SCAN_START_EX:
           goto C1_003_LINES;
       C1_003_LINES_EX:
           goto C1_013_EOF;
       C1_013_EOF_EX:
           goto veryend;
      /**/
       C1_002_SCAN_START:
  /*001*/      infile=open_input("b:\\testout.dat");
  /*003*/      currch=getc(infile);
           if(currch!=EOF) nextch=getc(infile);
  /*033*/      token=&t;
  /*021*/      outfile=open_output("b:\\testout2.dat");
           goto C1_002_SCAN_START_EX;
      /**/
       C1_003_LINES:
       C1_004_LINE_EX:
           if(!(
  /*C01*/         (currch==EOF)
))
                   goto C1_004_LINE;
           goto C1_003_LINES_EX;
      /**/
       C1_004_LINE:
           goto C1_005_LINE_START;
       C1_005_LINE_START_EX:
           goto C1_006_CHUNKS;
       C1_006_CHUNKS_EX:
           goto C1_012_BACKSLASH_N;
       C1_012_BACKSLASH_N_EX:
           goto C1_004_LINE_EX;
      /**/
       C1_005_LINE_START:
  /*016*/      /*printf("START OF LINE\n");*/
           goto C1_005_LINE_START_EX;
      /**/
       C1_006_CHUNKS:
       C1_007_CHUNK_EX:
           if(!(
  /*C02*/         (currch=='\n')
))
                   goto C1_007_CHUNK;
           goto C1_006_CHUNKS_EX;
      /**/
       C1_007_CHUNK:
           goto C1_008_START_CHUNK;
       C1_008_START_CHUNK_EX:
           goto C1_009_BLANKS;
       C1_009_BLANKS_EX:
           goto C1_011_DATA;
       C1_011_DATA_EX:
           goto C1_007_CHUNK_EX;
      /**/
       C1_008_START_CHUNK:
  /*005*/      ch=chp;
           goto C1_008_START_CHUNK_EX;
      /**/
       C1_009_BLANKS:
       C1_010_BLANK_EX:
           if(!(
  /*C03*/         (currch!=' ')
))
                   goto C1_010_BLANK;
           goto C1_009_BLANKS_EX;
      /**/
       C1_010_BLANK:
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C1_010_BLANK_EX;
      /**/
       C1_011_DATA:
                g2_001_DATA_A=0;
           goto C2_001_DATA;
       C2_001_EXIT01:
           goto C1_011_DATA_EX;
      /**/
       C1_012_BACKSLASH_N:
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
  /*015*/      /*printf("END LINE TOKEN\n");*/
           /*getchar();*/
           goto C1_012_BACKSLASH_N_EX;
      /**/
       C1_013_EOF:
  /*002*/      close_file(infile);
  /*022*/      close_file(outfile);
           goto C1_013_EOF_EX;
      /**/
       C2_001_DATA:
           goto C2_002_DATA;
       C2_002_DATA_EX:
       C2_001_DATA_A:
                switch(g2_001_DATA_A){
                case 0 : goto C2_001_EXIT01;break;
                }
      /**/
       C2_002_DATA:
           if((
  /*C06*/         (currch=='"' || currch=='\'')
))
                   goto C2_003_NON_NUMERI_C_LITERAL;
           if((
  /*C07*/         (currch=='(')
))
                   goto C2_008_OPEN_BRACE;
           if((
  /*C08*/         (currch==')')
))
                   goto C2_010_CLOSE_BRACE;
           if((
  /*C15*/         (currch=='.')
))
                   goto C2_012_FULLSTOP;
           if((
  /*C09*/         (currch!='"' &&
               currch!='\'' &&
               currch!='(' &&
               currch!=')' &&
               currch!='.' &&
               currch!='\n')
))
                   goto C2_014_WORD;
       C2_003_NON_NUMERI_C_LITERAL_EX:
       C2_008_OPEN_BRACE_EX:
       C2_010_CLOSE_BRACE_EX:
       C2_012_FULLSTOP_EX:
       C2_014_WORD_EX:
           goto C2_002_DATA_EX;
      /**/
       C2_003_NON_NUMERI_C_LITERAL:
           if((
  /*C04*/         (currch=='"')
))
                   goto C2_004_DOUBLE_QUOTE;
           if((
  /*C05*/         (currch=='\'')
))
                   goto C2_006_SINGLE_QUOTE;
       C2_004_DOUBLE_QUOTE_EX:
       C2_006_SINGLE_QUOTE_EX:
           goto C2_003_NON_NUMERI_C_LITERAL_EX;
      /**/
       C2_004_DOUBLE_QUOTE:
           goto C2_005_DOUBLE_SUBTREE;
       C2_005_DOUBLE_SUBTREE_EX:
           goto C2_004_DOUBLE_QUOTE_EX;
      /**/
       C2_005_DOUBLE_SUBTREE:
                g3_001_DOUBLE_SUBTREE_A=0;
           goto C3_001_DOUBLE_SUBTREE;
       C3_001_EXIT01:
           goto C2_005_DOUBLE_SUBTREE_EX;
      /**/
       C2_006_SINGLE_QUOTE:
           goto C2_007_SINGLE_SUBTREE;
       C2_007_SINGLE_SUBTREE_EX:
           goto C2_006_SINGLE_QUOTE_EX;
      /**/
       C2_007_SINGLE_SUBTREE:
                g4_001_SINGLE_SUBTREE_A=0;
           goto C4_001_SINGLE_SUBTREE;
       C4_001_EXIT01:
           goto C2_007_SINGLE_SUBTREE_EX;
      /**/
       C2_008_OPEN_BRACE:
           goto C2_009_BRACE;
       C2_009_BRACE_EX:
           goto C2_008_OPEN_BRACE_EX;
      /**/
       C2_009_BRACE:
  /*008*/      /*printf("open brace\n");*/
  /*024*/      token->token_type=OPEN_BRACE; 
           token->value.keyword_number=OPEN_BRACE;
  /*023*/      write_token(outfile,token);
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C2_009_BRACE_EX;
      /**/
       C2_010_CLOSE_BRACE:
           goto C2_011_PARENTHESI;
       C2_011_PARENTHESI_EX:
           goto C2_010_CLOSE_BRACE_EX;
      /**/
       C2_011_PARENTHESI:
  /*009*/      /*printf("close brace\n");*/
  /*025*/      token->token_type=CLOSE_BRACE; 
           token->value.keyword_number=CLOSE_BRACE;
  /*023*/      write_token(outfile,token);
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C2_011_PARENTHESI_EX;
      /**/
       C2_012_FULLSTOP:
           goto C2_013_PERIOD;
       C2_013_PERIOD_EX:
           goto C2_012_FULLSTOP_EX;
      /**/
       C2_013_PERIOD:
  /*014*/      /*printf("fullstop\n");*/
  /*026*/      token->token_type=FULLSTOP; 
           token->value.keyword_number=FULLSTOP;
  /*023*/      write_token(outfile,token);
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C2_013_PERIOD_EX;
      /**/
       C2_014_WORD:
           goto C2_015_KEYWORD_OR_WORD;
       C2_015_KEYWORD_OR_WORD_EX:
           goto C2_014_WORD_EX;
      /**/
       C2_015_KEYWORD_OR_WORD:
                g5_001_KEYWORD_OR_WORD_A=0;
           goto C5_001_KEYWORD_OR_WORD;
       C5_001_EXIT01:
           goto C2_015_KEYWORD_OR_WORD_EX;
      /**/
       C3_001_DOUBLE_SUBTREE:
           goto C3_002_START_QUOTE;
       C3_002_START_QUOTE_EX:
           goto C3_003_THE_IN_BETWEEN;
       C3_003_THE_IN_BETWEEN_EX:
           goto C3_007_END_QUOTE;
       C3_007_END_QUOTE_EX:
       C3_001_DOUBLE_SUBTREE_A:
                switch(g3_001_DOUBLE_SUBTREE_A){
                case 0 : goto C3_001_EXIT01;break;
                }
      /**/
       C3_002_START_QUOTE:
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
  /*011*/      length_of=0;
  /*005*/      ch=chp;
  /*006*/      *ch='\0';
           goto C3_002_START_QUOTE_EX;
      /**/
       C3_003_THE_IN_BETWEEN:
       C3_004_CHAR_SEQUENCE_EX:
           if(!(
  /*C11*/         (currch=='"' && nextch!='"')
))
                   goto C3_004_CHAR_SEQUENCE;
           goto C3_003_THE_IN_BETWEEN_EX;
      /**/
       C3_004_CHAR_SEQUENCE:
           if((
  /*C13*/         (currch=='"' && nextch=='"')
))
                   goto C3_005_QUOTE_QUOTE;
           if(!(
  /*C13*/         (currch=='"' && nextch=='"')
))
                   goto C3_006_ANY_OTHER;
       C3_005_QUOTE_QUOTE_EX:
       C3_006_ANY_OTHER_EX:
           goto C3_004_CHAR_SEQUENCE_EX;
      /**/
       C3_005_QUOTE_QUOTE:
  /*012*/      length_of++;
  /*030*/      *ch=currch;
  /*031*/      ch++;
  /*006*/      *ch='\0';
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C3_005_QUOTE_QUOTE_EX;
      /**/
       C3_006_ANY_OTHER:
  /*012*/      length_of++;
  /*030*/      *ch=currch;
  /*031*/      ch++;
  /*006*/      *ch='\0';
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C3_006_ANY_OTHER_EX;
      /**/
       C3_007_END_QUOTE:
  /*013*/      token->token_type=NON_NUMERIC_LITERAL_LENGTH;
           token->value.keyword_number=length_of;
  /*023*/      write_token(outfile,token);
  /*007*/      /*printf("string token for %s\n",chp);*/
  /*029*/      token->token_type=NON_NUMERIC_LITERAL; 
           token->value.string=chp;
  /*023*/      write_token(outfile,token);
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C3_007_END_QUOTE_EX;
      /**/
       C4_001_SINGLE_SUBTREE:
           goto C4_002_START_QUOTE;
       C4_002_START_QUOTE_EX:
           goto C4_003_THE_IN_BETWEEN;
       C4_003_THE_IN_BETWEEN_EX:
           goto C4_007_END_QUOTE;
       C4_007_END_QUOTE_EX:
       C4_001_SINGLE_SUBTREE_A:
                switch(g4_001_SINGLE_SUBTREE_A){
                case 0 : goto C4_001_EXIT01;break;
                }
      /**/
       C4_002_START_QUOTE:
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
  /*011*/      length_of=0;
  /*005*/      ch=chp;
  /*006*/      *ch='\0';
           goto C4_002_START_QUOTE_EX;
      /**/
       C4_003_THE_IN_BETWEEN:
       C4_004_CHAR_SEQUENCE_EX:
           if(!(
  /*C12*/         (currch=='\'' && nextch!='\'')
))
                   goto C4_004_CHAR_SEQUENCE;
           goto C4_003_THE_IN_BETWEEN_EX;
      /**/
       C4_004_CHAR_SEQUENCE:
           if((
  /*C14*/         (currch=='\'' && nextch=='\'')
))
                   goto C4_005_SIN_QUOTE_SIN_QUOTE;
           if(!(
  /*C14*/         (currch=='\'' && nextch=='\'')
))
                   goto C4_006_ANY_OTHER;
       C4_005_SIN_QUOTE_SIN_QUOTE_EX:
       C4_006_ANY_OTHER_EX:
           goto C4_004_CHAR_SEQUENCE_EX;
      /**/
       C4_005_SIN_QUOTE_SIN_QUOTE:
  /*012*/      length_of++;
  /*030*/      *ch=currch;
  /*031*/      ch++;
  /*006*/      *ch='\0';
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C4_005_SIN_QUOTE_SIN_QUOTE_EX;
      /**/
       C4_006_ANY_OTHER:
  /*012*/      length_of++;
  /*030*/      *ch=currch;
  /*031*/      ch++;
  /*006*/      *ch='\0';
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C4_006_ANY_OTHER_EX;
      /**/
       C4_007_END_QUOTE:
  /*013*/      token->token_type=NON_NUMERIC_LITERAL_LENGTH;
           token->value.keyword_number=length_of;
  /*023*/      write_token(outfile,token);
  /*007*/      /*printf("string token for %s\n",chp);*/
  /*029*/      token->token_type=NON_NUMERIC_LITERAL; 
           token->value.string=chp;
  /*023*/      write_token(outfile,token);
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C4_007_END_QUOTE_EX;
      /**/
       C5_001_KEYWORD_OR_WORD:
           goto C5_002_KEYWORD_WORD_BCKTR;
       C5_002_KEYWORD_WORD_BCKTR_EX:
       C5_001_KEYWORD_OR_WORD_A:
                switch(g5_001_KEYWORD_OR_WORD_A){
                case 0 : goto C5_001_EXIT01;break;
                }
      /**/
       C5_002_KEYWORD_WORD_BCKTR:
           goto C5_003_KEYWORD;
       C5_003_KEYWORD_EX:
       C5_008_NON_KEYWORD_EX:
           goto C5_002_KEYWORD_WORD_BCKTR_EX;
      /**/
       C5_003_KEYWORD:
           goto C5_004_KEYWORD_START;
       C5_004_KEYWORD_START_EX:
           goto C5_005_KEYWORD_CHARS;
       C5_005_KEYWORD_CHARS_EX:
           goto C5_007_KEYWORD_END;
       C5_007_KEYWORD_END_EX:
           goto C5_003_KEYWORD_EX;
      /**/
       C5_004_KEYWORD_START:
  /*005*/      ch=chp;
  /*011*/      length_of=0;
  /*017*/      listpointer=root;
  /*030*/      *ch=currch;
  /*031*/      ch++;
  /*006*/      *ch='\0';
  /*018*/      listpointer=check_pointer(listpointer,currch);
  /*012*/      length_of++;
           if((
  /*Q01*/         (!isupper(currch)) && currch!='-'
))
                   goto C5_008_NON_KEYWORD;
           if((
  /*Q02*/         listpointer==NULL
))
                   goto C5_008_NON_KEYWORD;
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C5_004_KEYWORD_START_EX;
      /**/
       C5_005_KEYWORD_CHARS:
       C5_006_KEYWORD_CHAR_EX:
           if(!(
  /*C10*/         (currch==' ' || currch=='\n' || 
               currch=='(' || currch==')' ||
               currch=='.')
))
                   goto C5_006_KEYWORD_CHAR;
           goto C5_005_KEYWORD_CHARS_EX;
      /**/
       C5_006_KEYWORD_CHAR:
  /*030*/      *ch=currch;
  /*031*/      ch++;
  /*006*/      *ch='\0';
  /*012*/      length_of++;
  /*018*/      listpointer=check_pointer(listpointer,currch);
           if((
  /*Q01*/         (!isupper(currch)) && currch!='-'
))
                   goto C5_008_NON_KEYWORD;
           if((
  /*Q02*/         listpointer==NULL
))
                   goto C5_008_NON_KEYWORD;
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C5_006_KEYWORD_CHAR_EX;
      /**/
       C5_007_KEYWORD_END:
  /*019*/      dat=get_data(listpointer);
           if((
  /*Q03*/         dat==NULL
))
                   goto C5_008_NON_KEYWORD;
  /*020*/      /*printf("keyword - %s number %d",chp,dat);*/
  /*027*/      token->token_type=KEYWORD; 
           token->value.keyword_number=dat;
  /*023*/      write_token(outfile,token);
           goto C5_007_KEYWORD_END_EX;
      /**/
       C5_008_NON_KEYWORD:
           goto C5_009_START_NON;
       C5_009_START_NON_EX:
           goto C5_010_CHARS;
       C5_010_CHARS_EX:
           goto C5_012_END_WORD;
       C5_012_END_WORD_EX:
           goto C5_008_NON_KEYWORD_EX;
      /**/
       C5_009_START_NON:
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C5_009_START_NON_EX;
      /**/
       C5_010_CHARS:
       C5_011_CHAR_EX:
           if(!(
  /*C10*/         (currch==' ' || currch=='\n' || 
               currch=='(' || currch==')' ||
               currch=='.')
))
                   goto C5_011_CHAR;
           goto C5_010_CHARS_EX;
      /**/
       C5_011_CHAR:
  /*030*/      *ch=currch;
  /*031*/      ch++;
  /*006*/      *ch='\0';
  /*012*/      length_of++;
  /*004*/      currch=nextch;
           if(nextch!=EOF) nextch=getc(infile);
           goto C5_011_CHAR_EX;
      /**/
       C5_012_END_WORD:
  /*010*/      /*printf("word token for %s\n",chp);*/
  /*032*/      token->token_type=NON_KEYWORD_LENGTH;
           token->value.keyword_number=length_of;
  /*023*/      write_token(outfile,token);
  /*028*/      token->token_type=NON_KEYWORD; 
           token->value.string=chp;
  /*023*/      write_token(outfile,token);
  /*013*/      token->token_type=NON_NUMERIC_LITERAL_LENGTH;
           token->value.keyword_number=length_of;
           goto C5_012_END_WORD_EX;
      /**/
      /*   Data Analysis Map*/
      /**/
      /*                         ------------- Data Analysis By -------------*/
      /**/
      /*                         BOX TYPE               OPERATION  ALLOCATION*/
      /*  Tree name: SCAN*/
      /**/
      /*                         Leaf      :   6          Operations:  11*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   3*/
      /*                         Iterations:   3*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   1   -->    DATA*/
      /**/
      /*  Tree name: DATA*/
      /**/
      /*                         Leaf      :   3          Operations:  12*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   2*/
      /*                         Sequences :   7*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   3   -->    DOUBLE-SUBTREE*/
      /*                                                  SINGLE-SUBTREE*/
      /*                                                  KEYWORD_OR-WORD*/
      /**/
      /*  Tree name: DOUBLE-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:  21*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   1*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: SINGLE-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:  21*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   1*/
      /*                         Iterations:   1*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: KEYWORD_OR-WORD*/
      /**/
      /*                         Leaf      :   6          Operations:  31*/
      /*                                                  Quits     :   5*/
      /*                         Selections:   0*/
      /*                         Sequences :   3*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   1*/
      /*                         Subtrees  :   0*/
      /**/
      /**/
      /**/
veryend: ;
}
\end{verbatim}
