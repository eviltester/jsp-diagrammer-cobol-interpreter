\begin{verbatim}
#include <stdio.h>
#include "alfile.h"
#include "allinesc.h"

#define area2 6
#define infile_name "b:altest.dat"
#define outfile_name "b:\\testout.dat"

void main(){

 int poscount=0;
 char line[100];
 FILE *infile,*outfile;
 char *eof_marker;

                int g2_001_LINE_BODY_A;
                int g3_001_REST_SUBTREE_A;
                int g4_001_NORMAL_SUBTREE_A;
                int g5_001_COMMENT_SUBTREE_A;
                int g6_001_PRINT_SUBTREE_A;
                int g7_001_CONTINUE_SUBTREE_A;
      /**************************************************************************/
      /**************************************************************************/
      /******************* DRIVING PROCEDURE    B:\ALLINESC ********************/
      /**************************************************************************/
       PROCEDURE_DIVISION:
      /**/
      /** line scanner takes an input file*/
      /** reads in the lines from the file and*/
      /** builds up complete cobol statements*/
      /** on a single line*/
      /** it skips comment lines*/
      /** and joins together continuation lines*/
      /** */
      /** NO ERROR HANDLING YET!!!!*/
      /**/
       C1_001_LINE__SCANNER:
           goto C1_002_SCAN_START;
       C1_002_SCAN_START_EX:
           goto C1_003_SCAN_BODY;
       C1_003_SCAN_BODY_EX:
           goto C1_014_SCAN_END;
       C1_014_SCAN_END_EX:
           goto veryend;
      /**/
       C1_002_SCAN_START:
  /*001*/      infile=open_input(infile_name);
           eof_marker=fgets(line,100,infile);
  /*006*/      outfile=open_output(outfile_name);
  /*004*/      poscount=0;
  /*003*/      poscount++;
           goto C1_002_SCAN_START_EX;
      /**/
       C1_003_SCAN_BODY:
       C1_004_LINE_GROUP_EX:
           if(!(
  /*C01*/         (feof(infile) /*eof_marker==NULL*/)
))
                   goto C1_004_LINE_GROUP;
           goto C1_003_SCAN_BODY_EX;
      /**/
      /** a line group has a number of body lines*/
      /** , these are lines without a full-stop*/
      /** at the end.*/
      /** */
      /** this is followed by a line with a */
      /** fullstop at the end ---the END-LINE*/
      /**/
       C1_004_LINE_GROUP:
           goto C1_005_BODY_LINE;
       C1_005_BODY_LINE_EX:
           goto C1_009_END_LINE;
       C1_009_END_LINE_EX:
           goto C1_004_LINE_GROUP_EX;
      /**/
       C1_005_BODY_LINE:
       C1_006_LINE_EX:
           if(!(
  /*C02*/         (feof(infile) || (is_last_full_stop(line) && (line[area2]!='*')))
))
                   goto C1_006_LINE;
           goto C1_005_BODY_LINE_EX;
      /**/
       C1_006_LINE:
           goto C1_007_LINE_BODY;
       C1_007_LINE_BODY_EX:
           goto C1_008_LINE_END;
       C1_008_LINE_END_EX:
           goto C1_006_LINE_EX;
      /**/
       C1_007_LINE_BODY:
                g2_001_LINE_BODY_A=0;
           goto C2_001_LINE_BODY;
       C2_001_EXIT01:
           goto C1_007_LINE_BODY_EX;
      /**/
       C1_008_LINE_END:
  /*004*/      poscount=0;
  /*009*/      eof_marker=fgets(line,100,infile);
           goto C1_008_LINE_END_EX;
      /**/
       C1_009_END_LINE:
           goto C1_010_LINE_BODY;
       C1_010_LINE_BODY_EX:
           goto C1_013_LINE_END;
       C1_013_LINE_END_EX:
           goto C1_009_END_LINE_EX;
      /**/
       C1_010_LINE_BODY:
           goto C1_011_LINE_AREA1;
       C1_011_LINE_AREA1_EX:
           goto C1_012_REST_SUBTREE;
       C1_012_REST_SUBTREE_EX:
           goto C1_010_LINE_BODY_EX;
      /**/
       C1_011_LINE_AREA1:
  /*010*/      poscount=6;
           goto C1_011_LINE_AREA1_EX;
      /**/
       C1_012_REST_SUBTREE:
                g3_001_REST_SUBTREE_A=0;
           goto C3_001_REST_SUBTREE;
       C3_001_EXIT01:
           goto C1_012_REST_SUBTREE_EX;
      /**/
       C1_013_LINE_END:
  /*004*/      poscount=0;
  /*009*/      eof_marker=fgets(line,100,infile);
           goto C1_013_LINE_END_EX;
      /**/
       C1_014_SCAN_END:
  /*002*/      close_file(infile);
  /*007*/      close_file(outfile);
           goto C1_014_SCAN_END_EX;
      /**/
       C4_001_NORMAL_SUBTREE:
           goto C4_002_NORM_AREA2;
       C4_002_NORM_AREA2_EX:
           goto C4_004_REST_OF_NO_RMAL_LINE;
       C4_004_REST_OF_NO_RMAL_LINE_EX:
           goto C4_006_NORNAL_LIN_E_AREA4;
       C4_006_NORNAL_LIN_E_AREA4_EX:
           goto C4_008_END_OF_NOR_MAL_LINE;
       C4_008_END_OF_NOR_MAL_LINE_EX:
       C4_001_NORMAL_SUBTREE_A:
                switch(g4_001_NORMAL_SUBTREE_A){
                case 0 : goto C4_001_EXIT02;break;
                case 1 : goto C4_001_EXIT03;break;
                }
      /**/
       C4_002_NORM_AREA2:
           goto C4_003_P_AREA_2_S_PACE;
       C4_003_P_AREA_2_S_PACE_EX:
           goto C4_002_NORM_AREA2_EX;
      /**/
       C4_003_P_AREA_2_S_PACE:
  /*003*/      poscount++;
           goto C4_003_P_AREA_2_S_PACE_EX;
      /**/
       C4_004_REST_OF_NO_RMAL_LINE:
       C4_005_NORMAL_CHA_R_EX:
           if(!(
  /*C09*/         (line[poscount]=='\n' || poscount>72)
))
                   goto C4_005_NORMAL_CHA_R;
           goto C4_004_REST_OF_NO_RMAL_LINE_EX;
      /**/
       C4_005_NORMAL_CHA_R:
  /*005*/      putc(line[poscount],outfile);
  /*003*/      poscount++;
           goto C4_005_NORMAL_CHA_R_EX;
      /**/
       C4_006_NORNAL_LIN_E_AREA4:
       C4_007_NORM_AREA4__CHAR_EX:
           if(!(
  /*C07*/         (line[poscount]=='\n')
))
                   goto C4_007_NORM_AREA4__CHAR;
           goto C4_006_NORNAL_LIN_E_AREA4_EX;
      /**/
       C4_007_NORM_AREA4__CHAR:
  /*003*/      poscount++;
           goto C4_007_NORM_AREA4__CHAR_EX;
      /**/
       C4_008_END_OF_NOR_MAL_LINE:
  /*003*/      poscount++;
           goto C4_008_END_OF_NOR_MAL_LINE_EX;
      /**/
       C5_001_COMMENT_SUBTREE:
           goto C5_002_COMMENT_AR_EA_2;
       C5_002_COMMENT_AR_EA_2_EX:
           goto C5_004_COMEENT_BO_DY;
       C5_004_COMEENT_BO_DY_EX:
           goto C5_006_COMMENT_LI_NE_AREA4;
       C5_006_COMMENT_LI_NE_AREA4_EX:
           goto C5_008_COMMENT_EN_D;
       C5_008_COMMENT_EN_D_EX:
       C5_001_COMMENT_SUBTREE_A:
                switch(g5_001_COMMENT_SUBTREE_A){
                case 0 : goto C5_001_EXIT02;break;
                case 1 : goto C5_001_EXIT03;break;
                }
      /**/
       C5_002_COMMENT_AR_EA_2:
           goto C5_003_AREA2_ASTE_RISK;
       C5_003_AREA2_ASTE_RISK_EX:
           goto C5_002_COMMENT_AR_EA_2_EX;
      /**/
       C5_003_AREA2_ASTE_RISK:
  /*003*/      poscount++;
           goto C5_003_AREA2_ASTE_RISK_EX;
      /**/
       C5_004_COMEENT_BO_DY:
       C5_005_COMMENT_CH_AR_EX:
           if(!(
  /*C09*/         (line[poscount]=='\n' || poscount>72)
))
                   goto C5_005_COMMENT_CH_AR;
           goto C5_004_COMEENT_BO_DY_EX;
      /**/
       C5_005_COMMENT_CH_AR:
  /*003*/      poscount++;
           goto C5_005_COMMENT_CH_AR_EX;
      /**/
       C5_006_COMMENT_LI_NE_AREA4:
       C5_007_COMMENT_AR_EA4_CHAR_EX:
           if(!(
  /*C07*/         (line[poscount]=='\n')
))
                   goto C5_007_COMMENT_AR_EA4_CHAR;
           goto C5_006_COMMENT_LI_NE_AREA4_EX;
      /**/
       C5_007_COMMENT_AR_EA4_CHAR:
  /*003*/      poscount++;
           goto C5_007_COMMENT_AR_EA4_CHAR_EX;
      /**/
       C5_008_COMMENT_EN_D:
  /*003*/      poscount++;
           goto C5_008_COMMENT_EN_D_EX;
      /**/
       C6_001_PRINT_SUBTREE:
           goto C6_002_PRINT_LINE__AREA2;
       C6_002_PRINT_LINE__AREA2_EX:
           goto C6_004_PRINT_LINE__BODY;
       C6_004_PRINT_LINE__BODY_EX:
           goto C6_006_PRINT_LINE__AREA4;
       C6_006_PRINT_LINE__AREA4_EX:
           goto C6_008_PRINT_LINE__END;
       C6_008_PRINT_LINE__END_EX:
       C6_001_PRINT_SUBTREE_A:
                switch(g6_001_PRINT_SUBTREE_A){
                case 0 : goto C6_001_EXIT02;break;
                case 1 : goto C6_001_EXIT03;break;
                }
      /**/
       C6_002_PRINT_LINE__AREA2:
           goto C6_003_AREA2_SLAS_H;
       C6_003_AREA2_SLAS_H_EX:
           goto C6_002_PRINT_LINE__AREA2_EX;
      /**/
       C6_003_AREA2_SLAS_H:
  /*003*/      poscount++;
           goto C6_003_AREA2_SLAS_H_EX;
      /**/
       C6_004_PRINT_LINE__BODY:
       C6_005_PRINT_LINE__CHAR_EX:
           if(!(
  /*C09*/         (line[poscount]=='\n' || poscount>72)
))
                   goto C6_005_PRINT_LINE__CHAR;
           goto C6_004_PRINT_LINE__BODY_EX;
      /**/
       C6_005_PRINT_LINE__CHAR:
  /*005*/      putc(line[poscount],outfile);
  /*003*/      poscount++;
           goto C6_005_PRINT_LINE__CHAR_EX;
      /**/
       C6_006_PRINT_LINE__AREA4:
       C6_007_PRINT_AREA_4_CHAR_EX:
           if(!(
  /*C07*/         (line[poscount]=='\n')
))
                   goto C6_007_PRINT_AREA_4_CHAR;
           goto C6_006_PRINT_LINE__AREA4_EX;
      /**/
       C6_007_PRINT_AREA_4_CHAR:
  /*003*/      poscount++;
           goto C6_007_PRINT_AREA_4_CHAR_EX;
      /**/
       C6_008_PRINT_LINE__END:
  /*003*/      poscount++;
           goto C6_008_PRINT_LINE__END_EX;
      /**/
       C7_001_CONTINUE_SUBTREE:
           goto C7_002_CONTINUE_L_INE_AREA2;
       C7_002_CONTINUE_L_INE_AREA2_EX:
           goto C7_004_POSSIBLE_B_LANKS;
       C7_004_POSSIBLE_B_LANKS_EX:
           goto C7_006_POSSIBLE_QUOTE;
       C7_006_POSSIBLE_QUOTE_EX:
           goto C7_008_CONTINUE_B_ODY;
       C7_008_CONTINUE_B_ODY_EX:
           goto C7_012_CONTINUE_L_INE_AREA4;
       C7_012_CONTINUE_L_INE_AREA4_EX:
           goto C7_014_CONTINUE_L_INE_END;
       C7_014_CONTINUE_L_INE_END_EX:
       C7_001_CONTINUE_SUBTREE_A:
                switch(g7_001_CONTINUE_SUBTREE_A){
                case 0 : goto C7_001_EXIT02;break;
                case 1 : goto C7_001_EXIT03;break;
                }
      /**/
       C7_002_CONTINUE_L_INE_AREA2:
           goto C7_003_AREA2_HASH;
       C7_003_AREA2_HASH_EX:
           goto C7_002_CONTINUE_L_INE_AREA2_EX;
      /**/
       C7_003_AREA2_HASH:
  /*003*/      poscount++;
           goto C7_003_AREA2_HASH_EX;
      /**/
       C7_004_POSSIBLE_B_LANKS:
       C7_005_POSSIBLE_B_LANK_EX:
           if(!(
  /*C08*/         (line[poscount]!=' ')
))
                   goto C7_005_POSSIBLE_B_LANK;
           goto C7_004_POSSIBLE_B_LANKS_EX;
      /**/
       C7_005_POSSIBLE_B_LANK:
  /*003*/      poscount++;
           goto C7_005_POSSIBLE_B_LANK_EX;
      /**/
       C7_006_POSSIBLE_QUOTE:
           if((
  /*C11*/         (line[area2]=='\'')
))
                   goto C7_007_QUOTE;
       C7_007_QUOTE_EX:
           goto C7_006_POSSIBLE_QUOTE_EX;
      /**/
       C7_007_QUOTE:
  /*003*/      poscount++;
           goto C7_007_QUOTE_EX;
      /**/
       C7_008_CONTINUE_B_ODY:
           goto C7_009_CONTINUE_F_ROM_HERE;
       C7_009_CONTINUE_F_ROM_HERE_EX:
           goto C7_010_CONTINUE_C_HARS;
       C7_010_CONTINUE_C_HARS_EX:
           goto C7_008_CONTINUE_B_ODY_EX;
      /**/
       C7_009_CONTINUE_F_ROM_HERE:
  /*003*/      poscount++;
           goto C7_009_CONTINUE_F_ROM_HERE_EX;
      /**/
       C7_010_CONTINUE_C_HARS:
       C7_011_CONTINUE_C_HAR_EX:
           if(!(
  /*C09*/         (line[poscount]=='\n' || poscount>72)
))
                   goto C7_011_CONTINUE_C_HAR;
           goto C7_010_CONTINUE_C_HARS_EX;
      /**/
       C7_011_CONTINUE_C_HAR:
  /*005*/      putc(line[poscount],outfile);
  /*003*/      poscount++;
           goto C7_011_CONTINUE_C_HAR_EX;
      /**/
       C7_012_CONTINUE_L_INE_AREA4:
       C7_013_CONTINUE_A_REA4_CHAR_EX:
           if(!(
  /*C07*/         (line[poscount]=='\n')
))
                   goto C7_013_CONTINUE_A_REA4_CHAR;
           goto C7_012_CONTINUE_L_INE_AREA4_EX;
      /**/
       C7_013_CONTINUE_A_REA4_CHAR:
  /*003*/      poscount++;
           goto C7_013_CONTINUE_A_REA4_CHAR_EX;
      /**/
       C7_014_CONTINUE_L_INE_END:
  /*003*/      poscount++;
           goto C7_014_CONTINUE_L_INE_END_EX;
      /**/
       C3_001_REST_SUBTREE:
           goto C3_002_REST_OF_LI_NE;
       C3_002_REST_OF_LI_NE_EX:
       C3_001_REST_SUBTREE_A:
                switch(g3_001_REST_SUBTREE_A){
                case 0 : goto C3_001_EXIT01;break;
                }
      /**/
      /** the line is either a normal line*/
      /**                    a comment line*/
      /**                    a print line*/
      /**                 or a continuation line*/
      /**/
       C3_002_REST_OF_LI_NE:
           if((
  /*C10*/         (is_blank_or_end(line))
))
                   goto C3_003_BLANK_OR_END_LINE;
           if((
  /*C03*/         (line[area2]==' ')
))
                   goto C3_004_NORMAL_LIN_E;
           if((
  /*C04*/         (line[area2]=='*')
))
                   goto C3_007_COMMENT_LI_NE;
           if((
  /*C05*/         (line[area2]=='\\')
))
                   goto C3_010_PRINT_LINE;
           if((
  /*C06*/         (line[area2]=='-')
))
                   goto C3_013_CONTINUE_L_INE;
       C3_003_BLANK_OR_END_LINE_EX:
       C3_004_NORMAL_LIN_E_EX:
       C3_007_COMMENT_LI_NE_EX:
       C3_010_PRINT_LINE_EX:
       C3_013_CONTINUE_L_INE_EX:
           goto C3_002_REST_OF_LI_NE_EX;
      /**/
       C3_003_BLANK_OR_END_LINE:
  /*012*/      printf(" ");
           goto C3_003_BLANK_OR_END_LINE_EX;
      /**/
       C3_004_NORMAL_LIN_E:
           goto C3_005_NORMAL_SUBTREE;
       C3_005_NORMAL_SUBTREE_EX:
           goto C3_006_END_NORMAL;
       C3_006_END_NORMAL_EX:
           goto C3_004_NORMAL_LIN_E_EX;
      /**/
       C3_005_NORMAL_SUBTREE:
                g4_001_NORMAL_SUBTREE_A=0;
           goto C4_001_NORMAL_SUBTREE;
       C4_001_EXIT02:
           goto C3_005_NORMAL_SUBTREE_EX;
      /**/
       C3_006_END_NORMAL:
  /*011*/      putc('\n',outfile);
           goto C3_006_END_NORMAL_EX;
      /**/
       C3_007_COMMENT_LI_NE:
           goto C3_008_COMMENT_SUBTREE;
       C3_008_COMMENT_SUBTREE_EX:
           goto C3_009_END_COMMENT;
       C3_009_END_COMMENT_EX:
           goto C3_007_COMMENT_LI_NE_EX;
      /**/
       C3_008_COMMENT_SUBTREE:
                g5_001_COMMENT_SUBTREE_A=0;
           goto C5_001_COMMENT_SUBTREE;
       C5_001_EXIT02:
           goto C3_008_COMMENT_SUBTREE_EX;
      /**/
       C3_009_END_COMMENT:
  /*011*/      putc('\n',outfile);
           goto C3_009_END_COMMENT_EX;
      /**/
       C3_010_PRINT_LINE:
           goto C3_011_PRINT_SUBTREE;
       C3_011_PRINT_SUBTREE_EX:
           goto C3_012_END_PRINT;
       C3_012_END_PRINT_EX:
           goto C3_010_PRINT_LINE_EX;
      /**/
       C3_011_PRINT_SUBTREE:
                g6_001_PRINT_SUBTREE_A=0;
           goto C6_001_PRINT_SUBTREE;
       C6_001_EXIT02:
           goto C3_011_PRINT_SUBTREE_EX;
      /**/
       C3_012_END_PRINT:
  /*011*/      putc('\n',outfile);
           goto C3_012_END_PRINT_EX;
      /**/
       C3_013_CONTINUE_L_INE:
           goto C3_014_CONTINUE_SUBTREE;
       C3_014_CONTINUE_SUBTREE_EX:
           goto C3_015_END_CONTINUE;
       C3_015_END_CONTINUE_EX:
           goto C3_013_CONTINUE_L_INE_EX;
      /**/
       C3_014_CONTINUE_SUBTREE:
                g7_001_CONTINUE_SUBTREE_A=0;
           goto C7_001_CONTINUE_SUBTREE;
       C7_001_EXIT02:
           goto C3_014_CONTINUE_SUBTREE_EX;
      /**/
       C3_015_END_CONTINUE:
  /*011*/      putc('\n',outfile);
           goto C3_015_END_CONTINUE_EX;
      /**/
       C2_001_LINE_BODY:
           goto C2_002_LINE_AREA1;
       C2_002_LINE_AREA1_EX:
           goto C2_003_REST_OF_LI_NE;
       C2_003_REST_OF_LI_NE_EX:
       C2_001_LINE_BODY_A:
                switch(g2_001_LINE_BODY_A){
                case 0 : goto C2_001_EXIT01;break;
                }
      /**/
       C2_002_LINE_AREA1:
  /*010*/      poscount=6;
           goto C2_002_LINE_AREA1_EX;
      /**/
      /** the line is either a normal line*/
      /**                    a comment line*/
      /**                    a print line*/
      /**                 or a continuation line*/
      /**/
       C2_003_REST_OF_LI_NE:
           if((
  /*C10*/         (is_blank_or_end(line))
))
                   goto C2_004_BLANK_OR_LAST;
           if((
  /*C03*/         (line[area2]==' ')
))
                   goto C2_005_NORMAL_LIN_E;
           if((
  /*C04*/         (line[area2]=='*')
))
                   goto C2_007_COMMENT_LI_NE;
           if((
  /*C05*/         (line[area2]=='\\')
))
                   goto C2_009_PRINT_LINE;
           if((
  /*C06*/         (line[area2]=='-')
))
                   goto C2_011_CONTINUE_L_INE;
       C2_004_BLANK_OR_LAST_EX:
       C2_005_NORMAL_LIN_E_EX:
       C2_007_COMMENT_LI_NE_EX:
       C2_009_PRINT_LINE_EX:
       C2_011_CONTINUE_L_INE_EX:
           goto C2_003_REST_OF_LI_NE_EX;
      /**/
       C2_004_BLANK_OR_LAST:
  /*012*/      printf(" ");
           goto C2_004_BLANK_OR_LAST_EX;
      /**/
       C2_005_NORMAL_LIN_E:
           goto C2_006_NORMAL_SUBTREE;
       C2_006_NORMAL_SUBTREE_EX:
           goto C2_005_NORMAL_LIN_E_EX;
      /**/
       C2_006_NORMAL_SUBTREE:
                g4_001_NORMAL_SUBTREE_A=1;
           goto C4_001_NORMAL_SUBTREE;
       C4_001_EXIT03:
           goto C2_006_NORMAL_SUBTREE_EX;
      /**/
       C2_007_COMMENT_LI_NE:
           goto C2_008_COMMENT_SUBTREE;
       C2_008_COMMENT_SUBTREE_EX:
           goto C2_007_COMMENT_LI_NE_EX;
      /**/
       C2_008_COMMENT_SUBTREE:
                g5_001_COMMENT_SUBTREE_A=1;
           goto C5_001_COMMENT_SUBTREE;
       C5_001_EXIT03:
           goto C2_008_COMMENT_SUBTREE_EX;
      /**/
       C2_009_PRINT_LINE:
           goto C2_010_PRINT_SUBTREE;
       C2_010_PRINT_SUBTREE_EX:
           goto C2_009_PRINT_LINE_EX;
      /**/
       C2_010_PRINT_SUBTREE:
                g6_001_PRINT_SUBTREE_A=1;
           goto C6_001_PRINT_SUBTREE;
       C6_001_EXIT03:
           goto C2_010_PRINT_SUBTREE_EX;
      /**/
       C2_011_CONTINUE_L_INE:
           goto C2_012_CONTINUE_SUBTREE;
       C2_012_CONTINUE_SUBTREE_EX:
           goto C2_011_CONTINUE_L_INE_EX;
      /**/
       C2_012_CONTINUE_SUBTREE:
                g7_001_CONTINUE_SUBTREE_A=1;
           goto C7_001_CONTINUE_SUBTREE;
       C7_001_EXIT03:
           goto C2_012_CONTINUE_SUBTREE_EX;
      /**/
      /*   Data Analysis Map*/
      /**/
      /*                         ------------- Data Analysis By -------------*/
      /**/
      /*                         BOX TYPE               OPERATION  ALLOCATION*/
      /*  Tree name: LINE_-SCANNER*/
      /**/
      /*                         Leaf      :   5          Operations:  11*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   5*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   2   -->    LINE_BODY*/
      /*                                                  REST-SUBTREE*/
      /**/
      /*  Tree name: NORMAL-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:   5*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   2*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: COMMENT-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:   4*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   2*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: PRINT-SUBTREE*/
      /**/
      /*                         Leaf      :   4          Operations:   5*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   0*/
      /*                         Sequences :   2*/
      /*                         Iterations:   2*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: CONTINUE-SUBTREE*/
      /**/
      /*                         Leaf      :   7          Operations:   8*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   3*/
      /*                         Iterations:   3*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   0*/
      /**/
      /*  Tree name: REST-SUBTREE*/
      /**/
      /*                         Leaf      :   5          Operations:   5*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   5*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   4   -->    NORMAL-SUBTREE*/
      /*                                                  COMMENT-SUBTREE*/
      /*                                                  PRINT-SUBTREE*/
      /*                                                  CONTINUE-SUBTREE*/
      /**/
      /*  Tree name: LINE_BODY*/
      /**/
      /*                         Leaf      :   2          Operations:   2*/
      /*                                                  Quits     :   0*/
      /*                         Selections:   1*/
      /*                         Sequences :   5*/
      /*                         Iterations:   0*/
      /*                         Backtracks:   0*/
      /*                         Subtrees  :   4   -->    NORMAL-SUBTREE*/
      /*                                                  COMMENT-SUBTREE*/
      /*                                                  PRINT-SUBTREE*/
      /*                                                  CONTINUE-SUBTREE*/
      /**/
      /**/
      /**/
veryend: ;
}
\end{verbatim}
