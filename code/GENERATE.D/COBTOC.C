\begin{verbatim}
#include<stdio.h>
#define NO_SUB_TREES 20
#define SUBTREE_OCCURANCES 30
#define NAME_LENGTH 50
#define EXIT_LENGTH 30

typedef struct {
                    char exit[EXIT_LENGTH];
                  }EXIT_LIST;

typedef struct {
                    char sub_name[NAME_LENGTH];
                    EXIT_LIST exits[SUBTREE_OCCURANCES];
                    int main_number;
                  }MAIN_ALTER_LIST;
int total_subs=0;

FILE *infile,*outfile;
MAIN_ALTER_LIST root[NO_SUB_TREES];


static int is_it(char *inrec,char *check){

     char *chk;
     chk=check;

     while(*inrec==' ')
          inrec++;

     while(*chk!='\0' && *chk==*inrec){
          chk++;inrec++;
          }

     if(*chk=='\0')
          return(1);
     else
          return(0);
     }

static int is_it_blank(char *inrec){

     while(*inrec==' ')
          inrec++;

     if(*inrec=='\n')
          return(1);
     else
          return(0);
     }


static int is_it_if(char *inrec){

     char check[]="IF ";
     char *chk;
     chk=check;

     while(*inrec==' ')
          inrec++;

     while(*chk!='\0' && *chk==*inrec){
          chk++;inrec++;
          }

     if(*chk=='\0' || (*inrec=='\n' && *chk==' '))
          return(1);
     else
          return(0);
     }

static int find_exit(char *name,int sub){
     int loop=0,found=0;

     for(loop=0;loop<root[sub].main_number;loop++)
          {
          if(!strcmp(name,root[sub].exits[loop].exit)){
               found=loop+1;
               loop=root[sub].main_number;
               }
          }
     return found;
     }

static int find_sub(char *name){
     int loop=0,found=0;

     for(loop=0;loop<total_subs;loop++)
          {
          if(!strcmp(name,root[loop].sub_name)){
               found=loop+1;
               loop=total_subs;
               }
          }
     return found;
     }


void main(int argc, char *argv[]){

     int loop,loop2,sub_num,exit_num;
     char inrec[100],*char_pointer;
     char check_name[NAME_LENGTH],check_exit_name[EXIT_LENGTH];


      /**************************************************************************/
      /**************************************************************************/
      /******************** DRIVING PROCEDURE    B:\COBTOC *********************/
      /**************************************************************************/
       PROCEDURE_DIVISION:
      /**/
      /** takes as input a probench generated*/
      /** program. This is written with all*/
      /** operations and conditions, quits etc*/
      /** in C syntax.*/
      /** The .dat is the definition of the C */
      /** program and should be ended with an*/
      /** EOD!*/
      /**/
       C1_001_COBOL_TO_C:
           goto C1_002_ASSUME_GOOD;
       C1_002_ASSUME_GOOD_EX:
       C1_259_OOPS_EX:
           goto veryend;
      /**/
       C1_002_ASSUME_GOOD:
           goto C1_003_START;
       C1_003_START_EX:
           goto C1_004_FIRSTPASS;
       C1_004_FIRSTPASS_EX:
           goto C1_049_BODY;
       C1_049_BODY_EX:
           goto C1_258_END;
       C1_258_END_EX:
           goto C1_002_ASSUME_GOOD_EX;
      /**/
       C1_003_START:
           if((
  /*Q01*/         (argc!=3)
               /*!Q!printf("USAGE- COBOLTOC Inputfilename Outputfilename\n");*/
))
                   goto C1_259_OOPS;
  /*001*/      infile=fopen(*++argv,"r");
           if((
  /*Q02*/         (infile==NULL)
               /*!Q!printf("cannot open %s as input\n",*argv);*/
))
                   goto C1_259_OOPS;
  /*002*/      outfile=fopen(*++argv,"w");
           if((
  /*Q03*/         (outfile==NULL)
               /*!Q!printf("cannot open %s as output\n",*argv);*/
))
                   goto C1_259_OOPS;
  /*004*/      fgets(inrec,100,infile);
           goto C1_003_START_EX;
      /**/
       C1_004_FIRSTPASS:
           goto C1_005_BEFORE_EOD;
       C1_005_BEFORE_EOD_EX:
           goto C1_009_AFTER_EOD;
       C1_009_AFTER_EOD_EX:
           goto C1_048_END_PASS1;
       C1_048_END_PASS1_EX:
           goto C1_004_FIRSTPASS_EX;
      /**/
       C1_005_BEFORE_EOD:
           goto C1_006_LINES;
       C1_006_LINES_EX:
           goto C1_008_EOD_LINE;
       C1_008_EOD_LINE_EX:
           goto C1_005_BEFORE_EOD_EX;
      /**/
       C1_006_LINES:
       C1_007_LINE_EX:
           if(!(
  /*C01*/         (is_it(inrec,"EOD!"))
))
                   goto C1_007_LINE;
           goto C1_006_LINES_EX;
      /**/
       C1_007_LINE:
  /*004*/      fgets(inrec,100,infile);
           goto C1_007_LINE_EX;
      /**/
       C1_008_EOD_LINE:
  /*004*/      fgets(inrec,100,infile);
           goto C1_008_EOD_LINE_EX;
      /**/
       C1_009_AFTER_EOD:
       C1_010_LINES_EX:
           if(!(
  /*C02*/         (feof(infile))
))
                   goto C1_010_LINES;
           goto C1_009_AFTER_EOD_EX;
      /**/
       C1_010_LINES:
           goto C1_011_LINE_START;
       C1_011_LINE_START_EX:
           goto C1_012_LINE_BODY;
       C1_012_LINE_BODY_EX:
           goto C1_047_LINE_END;
       C1_047_LINE_END_EX:
           goto C1_010_LINES_EX;
      /**/
       C1_011_LINE_START:
  /*007*/      char_pointer=inrec;
           goto C1_011_LINE_START_EX;
      /**/
       C1_012_LINE_BODY:
           if((
  /*C19*/         (is_it(inrec,"ALTER "))
))
                   goto C1_013_ALTER_LINE;
       C1_013_ALTER_LINE_EX:
           goto C1_012_LINE_BODY_EX;
      /**/
       C1_013_ALTER_LINE:
           goto C1_014_BLANK_SPACES;
       C1_014_BLANK_SPACES_EX:
           goto C1_016_SKIP_ALTER;
       C1_016_SKIP_ALTER_EX:
           goto C1_018_READ_SUB_NAME;
       C1_018_READ_SUB_NAME_EX:
           goto C1_023_PROCESS_NAME;
       C1_023_PROCESS_NAME_EX:
           goto C1_034_READ_EXIT_NAME;
       C1_034_READ_EXIT_NAME_EX:
           goto C1_042_PROCESS_EXIT_NAME;
       C1_042_PROCESS_EXIT_NAME_EX:
           goto C1_013_ALTER_LINE_EX;
      /**/
       C1_014_BLANK_SPACES:
       C1_015_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_015_BLANK;
           goto C1_014_BLANK_SPACES_EX;
      /**/
       C1_015_BLANK:
  /*009*/      char_pointer++;
           goto C1_015_BLANK_EX;
      /**/
       C1_016_SKIP_ALTER:
       C1_017_ALTER_CHAR_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_017_ALTER_CHAR;
           goto C1_016_SKIP_ALTER_EX;
      /**/
       C1_017_ALTER_CHAR:
  /*009*/      char_pointer++;
           goto C1_017_ALTER_CHAR_EX;
      /**/
       C1_018_READ_SUB_NAME:
           goto C1_019_START;
       C1_019_START_EX:
           goto C1_020_BODY;
       C1_020_BODY_EX:
           goto C1_022_END;
       C1_022_END_EX:
           goto C1_018_READ_SUB_NAME_EX;
      /**/
       C1_019_START:
  /*009*/      char_pointer++;
  /*021*/      loop=0;
           goto C1_019_START_EX;
      /**/
       C1_020_BODY:
       C1_021_NAME_CHAR_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_021_NAME_CHAR;
           goto C1_020_BODY_EX;
      /**/
       C1_021_NAME_CHAR:
  /*032*/      check_name[loop]=*char_pointer;
  /*028*/      loop++;
  /*009*/      char_pointer++;
           goto C1_021_NAME_CHAR_EX;
      /**/
       C1_022_END:
  /*033*/      check_name[loop]='\0';
           goto C1_022_END_EX;
      /**/
       C1_023_PROCESS_NAME:
           goto C1_024_START;
       C1_024_START_EX:
           goto C1_025_POSSIBLY_NEW_NAME;
       C1_025_POSSIBLY_NEW_NAME_EX:
           goto C1_033_NAME_END;
       C1_033_NAME_END_EX:
           goto C1_023_PROCESS_NAME_EX;
      /**/
       C1_024_START:
  /*034*/      sub_num=find_sub(check_name);
           goto C1_024_START_EX;
      /**/
       C1_025_POSSIBLY_NEW_NAME:
           if((
  /*C20*/         (sub_num==0)
))
                   goto C1_026_NEW_NAME;
 /*ELSE*/      goto C1_031_OLD_NAME;
       C1_026_NEW_NAME_EX:
       C1_031_OLD_NAME_EX:
           goto C1_025_POSSIBLY_NEW_NAME_EX;
      /**/
       C1_026_NEW_NAME:
           goto C1_027_START;
       C1_027_START_EX:
           goto C1_028_BODY;
       C1_028_BODY_EX:
           goto C1_030_END;
       C1_030_END_EX:
           goto C1_026_NEW_NAME_EX;
      /**/
       C1_027_START:
  /*021*/      loop=0;
           goto C1_027_START_EX;
      /**/
       C1_028_BODY:
       C1_029_NAME_CHAR_EX:
           if(!(
  /*C21*/         (check_name[loop]=='\0')
))
                   goto C1_029_NAME_CHAR;
           goto C1_028_BODY_EX;
      /**/
       C1_029_NAME_CHAR:
  /*035*/      root[total_subs].sub_name[loop]=check_name[loop];
  /*028*/      loop++;
  /*009*/      char_pointer++;
           goto C1_029_NAME_CHAR_EX;
      /**/
       C1_030_END:
  /*036*/      root[total_subs].sub_name[loop]='\0';
  /*037*/      sub_num=total_subs;
  /*038*/      total_subs++;
           goto C1_030_END_EX;
      /**/
       C1_031_OLD_NAME:
           goto C1_032_PSUEDO_RETRIEVE;
       C1_032_PSUEDO_RETRIEVE_EX:
           goto C1_031_OLD_NAME_EX;
      /**/
       C1_032_PSUEDO_RETRIEVE:
  /*039*/      sub_num--;
           goto C1_032_PSUEDO_RETRIEVE_EX;
      /**/
       C1_033_NAME_END:
  /*004*/      fgets(inrec,100,infile);
  /*007*/      char_pointer=inrec;
           goto C1_033_NAME_END_EX;
      /**/
       C1_034_READ_EXIT_NAME:
           goto C1_035_BLANK;
       C1_035_BLANK_EX:
           goto C1_037_EXIT_NAME;
       C1_037_EXIT_NAME_EX:
           goto C1_034_READ_EXIT_NAME_EX;
      /**/
       C1_035_BLANK:
       C1_036_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_036_BLANK;
           goto C1_035_BLANK_EX;
      /**/
       C1_036_BLANK:
  /*009*/      char_pointer++;
           goto C1_036_BLANK_EX;
      /**/
       C1_037_EXIT_NAME:
           goto C1_038_START;
       C1_038_START_EX:
           goto C1_039_BODY;
       C1_039_BODY_EX:
           goto C1_041_END;
       C1_041_END_EX:
           goto C1_037_EXIT_NAME_EX;
      /**/
       C1_038_START:
  /*021*/      loop=0;
           goto C1_038_START_EX;
      /**/
       C1_039_BODY:
       C1_040_EXIT_NAME_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_040_EXIT_NAME_CHAR;
           goto C1_039_BODY_EX;
      /**/
       C1_040_EXIT_NAME_CHAR:
  /*040*/      check_exit_name[loop]=*char_pointer;
  /*028*/      loop++;
  /*009*/      char_pointer++;
           goto C1_040_EXIT_NAME_CHAR_EX;
      /**/
       C1_041_END:
  /*041*/      check_exit_name[loop]='\0';
           goto C1_041_END_EX;
      /**/
       C1_042_PROCESS_EXIT_NAME:
           goto C1_043_START;
       C1_043_START_EX:
           goto C1_044_BODY;
       C1_044_BODY_EX:
           goto C1_046_END;
       C1_046_END_EX:
           goto C1_042_PROCESS_EXIT_NAME_EX;
      /**/
       C1_043_START:
  /*021*/      loop=0;
           goto C1_043_START_EX;
      /**/
       C1_044_BODY:
       C1_045_NAME_CHAR_EX:
           if(!(
  /*C22*/         (check_exit_name[loop]=='\0')
))
                   goto C1_045_NAME_CHAR;
           goto C1_044_BODY_EX;
      /**/
       C1_045_NAME_CHAR:
  /*042*/      root[sub_num].exits[root[sub_num].main_number].exit[loop]=
                                                   check_exit_name[loop];
  /*028*/      loop++;
           goto C1_045_NAME_CHAR_EX;
      /**/
       C1_046_END:
  /*043*/      root[sub_num].exits[root[sub_num].main_number].exit[loop]='\0';
  /*044*/      root[sub_num].main_number++;
           goto C1_046_END_EX;
      /**/
       C1_047_LINE_END:
  /*004*/      fgets(inrec,100,infile);
           goto C1_047_LINE_END_EX;
      /**/
       C1_048_END_PASS1:
  /*027*/      fclose(infile);
  /*031*/      infile=fopen(*--argv,"r");
           if((
  /*Q02*/         (infile==NULL)
               /*!Q!printf("cannot open %s as input\n",*argv);*/
))
                   goto C1_259_OOPS;
  /*004*/      fgets(inrec,100,infile);
           goto C1_048_END_PASS1_EX;
      /**/
       C1_049_BODY:
           goto C1_050_BEFORE_EOD;
       C1_050_BEFORE_EOD_EX:
           goto C1_066_LINES;
       C1_066_LINES_EX:
           goto C1_049_BODY_EX;
      /**/
       C1_050_BEFORE_EOD:
           goto C1_051_LINES;
       C1_051_LINES_EX:
           goto C1_053_EOD_LINE;
       C1_053_EOD_LINE_EX:
           goto C1_054_ALTER_VARIABLES;
       C1_054_ALTER_VARIABLES_EX:
           goto C1_050_BEFORE_EOD_EX;
      /**/
       C1_051_LINES:
       C1_052_LINE_EX:
           if(!(
  /*C01*/         (is_it(inrec,"EOD!"))
))
                   goto C1_052_LINE;
           goto C1_051_LINES_EX;
      /**/
       C1_052_LINE:
  /*005*/      fputs(inrec,outfile);
  /*004*/      fgets(inrec,100,infile);
           goto C1_052_LINE_EX;
      /**/
       C1_053_EOD_LINE:
  /*004*/      fgets(inrec,100,infile);
           goto C1_053_EOD_LINE_EX;
      /**/
       C1_054_ALTER_VARIABLES:
           goto C1_055_START;
       C1_055_START_EX:
           goto C1_056_INTEGER_NAMES;
       C1_056_INTEGER_NAMES_EX:
           goto C1_054_ALTER_VARIABLES_EX;
      /**/
       C1_055_START:
  /*021*/      loop=0;
           goto C1_055_START_EX;
      /**/
       C1_056_INTEGER_NAMES:
       C1_057_NAME_EX:
           if(!(
  /*C23*/         (loop == total_subs)
))
                   goto C1_057_NAME;
           goto C1_056_INTEGER_NAMES_EX;
      /**/
       C1_057_NAME:
           goto C1_058_HEADER;
       C1_058_HEADER_EX:
           goto C1_059_MAIN_BODY;
       C1_059_MAIN_BODY_EX:
           goto C1_065_TRAILER;
       C1_065_TRAILER_EX:
           goto C1_057_NAME_EX;
      /**/
       C1_058_HEADER:
  /*045*/      loop2=0;
  /*048*/      fprintf(outfile,"                int g");
           goto C1_058_HEADER_EX;
      /**/
       C1_059_MAIN_BODY:
       C1_060_NAME_CHAR_EX:
           if(!(
  /*C24*/         (root[loop].sub_name[loop2]=='\0')
))
                   goto C1_060_NAME_CHAR;
           goto C1_059_MAIN_BODY_EX;
      /**/
       C1_060_NAME_CHAR:
           goto C1_061_POSSIBLE_HYPHEN;
       C1_061_POSSIBLE_HYPHEN_EX:
           goto C1_064_END;
       C1_064_END_EX:
           goto C1_060_NAME_CHAR_EX;
      /**/
       C1_061_POSSIBLE_HYPHEN:
           if((
  /*C25*/         (root[loop].sub_name[loop2]=='-')
))
                   goto C1_062_HYPHEN;
 /*ELSE*/      goto C1_063_NOT_HYPHEN;
       C1_062_HYPHEN_EX:
       C1_063_NOT_HYPHEN_EX:
           goto C1_061_POSSIBLE_HYPHEN_EX;
      /**/
       C1_062_HYPHEN:
  /*012*/      putc('_',outfile);
           goto C1_062_HYPHEN_EX;
      /**/
       C1_063_NOT_HYPHEN:
  /*047*/      putc(root[loop].sub_name[loop2],outfile);
           goto C1_063_NOT_HYPHEN_EX;
      /**/
       C1_064_END:
  /*046*/      loop2++;
           goto C1_064_END_EX;
      /**/
       C1_065_TRAILER:
  /*049*/      fprintf(outfile,";\n");
  /*028*/      loop++;
           goto C1_065_TRAILER_EX;
      /**/
       C1_066_LINES:
       C1_067_LINE_EX:
           if(!(
  /*C02*/         (feof(infile))
))
                   goto C1_067_LINE;
           goto C1_066_LINES_EX;
      /**/
       C1_067_LINE:
           goto C1_068_LINE_START;
       C1_068_LINE_START_EX:
           goto C1_069_LINEBODY;
       C1_069_LINEBODY_EX:
           goto C1_257_LINE_END;
       C1_257_LINE_END_EX:
           goto C1_067_LINE_EX;
      /**/
       C1_068_LINE_START:
  /*007*/      char_pointer=inrec;
           goto C1_068_LINE_START_EX;
      /**/
       C1_069_LINEBODY:
           if((
  /*C03*/         (is_it_blank(inrec))
))
                   goto C1_070_BLANK_LINE;
           if((
  /*C19*/         (is_it(inrec,"ALTER "))
))
                   goto C1_071_ALTER_BLOCK;
           if((
  /*C04*/         (is_it(inrec,"PROCEDURE "))
))
                   goto C1_096_PROCEDURE_DIVISION;
           if((
  /*C05*/         (inrec[6]=='*')
))
                   goto C1_105_COMMENT_LINE;
           if((
  /*C06*/         (is_it(inrec,"STOP RUN"))
))
                   goto C1_112_STOP_RUN_LINE;
           if((
  /*C07*/         (is_it(inrec,"GO TO"))
))
                   goto C1_116_GOTOLINE;
           if((
  /*C08*/         (inrec[7]!=' ')
))
                   goto C1_125_LABEL_LINE;
           if((
  /*C27*/         (is_it(inrec,"ELSE "))
))
                   goto C1_155_ELSE_LINE;
           if((
  /*C10*/         (is_it_if(inrec))
))
                   goto C1_174_IF_OR_IF_NOT_LINE;
           if(!(
  /*C03*/         (is_it_blank(inrec))
))
                   goto C1_243_NORMAL_LINE;
       C1_070_BLANK_LINE_EX:
       C1_071_ALTER_BLOCK_EX:
       C1_096_PROCEDURE_DIVISION_EX:
       C1_105_COMMENT_LINE_EX:
       C1_112_STOP_RUN_LINE_EX:
       C1_116_GOTOLINE_EX:
       C1_125_LABEL_LINE_EX:
       C1_155_ELSE_LINE_EX:
       C1_174_IF_OR_IF_NOT_LINE_EX:
       C1_243_NORMAL_LINE_EX:
           goto C1_069_LINEBODY_EX;
      /**/
       C1_070_BLANK_LINE:
  /*011*/      /* skip it */;
           goto C1_070_BLANK_LINE_EX;
      /**/
       C1_071_ALTER_BLOCK:
           goto C1_072_BLANK;
       C1_072_BLANK_EX:
           goto C1_074_SKIP_ALTER;
       C1_074_SKIP_ALTER_EX:
           goto C1_076_READ_SUB_NAME;
       C1_076_READ_SUB_NAME_EX:
           goto C1_081_READ_EXIT_NAME;
       C1_081_READ_EXIT_NAME_EX:
           goto C1_089_PROCESS_EXIT_NAME;
       C1_089_PROCESS_EXIT_NAME_EX:
           goto C1_071_ALTER_BLOCK_EX;
      /**/
       C1_072_BLANK:
       C1_073_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_073_BLANK;
           goto C1_072_BLANK_EX;
      /**/
       C1_073_BLANK:
  /*009*/      char_pointer++;
           goto C1_073_BLANK_EX;
      /**/
       C1_074_SKIP_ALTER:
       C1_075_ALTER_CHAR_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_075_ALTER_CHAR;
           goto C1_074_SKIP_ALTER_EX;
      /**/
       C1_075_ALTER_CHAR:
  /*009*/      char_pointer++;
           goto C1_075_ALTER_CHAR_EX;
      /**/
       C1_076_READ_SUB_NAME:
           goto C1_077_START;
       C1_077_START_EX:
           goto C1_078_BODY;
       C1_078_BODY_EX:
           goto C1_080_END;
       C1_080_END_EX:
           goto C1_076_READ_SUB_NAME_EX;
      /**/
       C1_077_START:
  /*009*/      char_pointer++;
  /*021*/      loop=0;
           goto C1_077_START_EX;
      /**/
       C1_078_BODY:
       C1_079_NAME_CHAR_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_079_NAME_CHAR;
           goto C1_078_BODY_EX;
      /**/
       C1_079_NAME_CHAR:
  /*032*/      check_name[loop]=*char_pointer;
  /*028*/      loop++;
  /*009*/      char_pointer++;
           goto C1_079_NAME_CHAR_EX;
      /**/
       C1_080_END:
  /*033*/      check_name[loop]='\0';
  /*034*/      sub_num=find_sub(check_name);
  /*004*/      fgets(inrec,100,infile);
  /*007*/      char_pointer=inrec;
           goto C1_080_END_EX;
      /**/
       C1_081_READ_EXIT_NAME:
           goto C1_082_BLANK;
       C1_082_BLANK_EX:
           goto C1_084_EXIT_NAME;
       C1_084_EXIT_NAME_EX:
           goto C1_081_READ_EXIT_NAME_EX;
      /**/
       C1_082_BLANK:
       C1_083_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_083_BLANK;
           goto C1_082_BLANK_EX;
      /**/
       C1_083_BLANK:
  /*009*/      char_pointer++;
           goto C1_083_BLANK_EX;
      /**/
       C1_084_EXIT_NAME:
           goto C1_085_START;
       C1_085_START_EX:
           goto C1_086_BODY;
       C1_086_BODY_EX:
           goto C1_088_END;
       C1_088_END_EX:
           goto C1_084_EXIT_NAME_EX;
      /**/
       C1_085_START:
  /*021*/      loop=0;
           goto C1_085_START_EX;
      /**/
       C1_086_BODY:
       C1_087_EXIT_NAME_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_087_EXIT_NAME_CHAR;
           goto C1_086_BODY_EX;
      /**/
       C1_087_EXIT_NAME_CHAR:
  /*040*/      check_exit_name[loop]=*char_pointer;
  /*028*/      loop++;
  /*009*/      char_pointer++;
           goto C1_087_EXIT_NAME_CHAR_EX;
      /**/
       C1_088_END:
  /*041*/      check_exit_name[loop]='\0';
           goto C1_088_END_EX;
      /**/
       C1_089_PROCESS_EXIT_NAME:
           goto C1_090_START;
       C1_090_START_EX:
           goto C1_091_BODY;
       C1_091_BODY_EX:
           goto C1_095_END;
       C1_095_END_EX:
           goto C1_089_PROCESS_EXIT_NAME_EX;
      /**/
       C1_090_START:
  /*062*/      fprintf(outfile,"                g");
  /*050*/      char_pointer=check_name;
           goto C1_090_START_EX;
      /**/
       C1_091_BODY:
       C1_092_CHAR_EX:
           if(!(
  /*C26*/         (*char_pointer=='\0')
))
                   goto C1_092_CHAR;
           goto C1_091_BODY_EX;
      /**/
       C1_092_CHAR:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_093_HYPHEN;
           if(!(
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_094_NOT_HYPHEN;
       C1_093_HYPHEN_EX:
       C1_094_NOT_HYPHEN_EX:
           goto C1_092_CHAR_EX;
      /**/
       C1_093_HYPHEN:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_093_HYPHEN_EX;
      /**/
       C1_094_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_094_NOT_HYPHEN_EX;
      /**/
       C1_095_END:
  /*051*/      putc('=',outfile);
  /*052*/      exit_num=find_exit(check_exit_name,sub_num-1);
  /*053*/      fprintf(outfile,"%d;\n",exit_num-1);
           goto C1_095_END_EX;
      /**/
       C1_096_PROCEDURE_DIVISION:
           goto C1_097_BLANK;
       C1_097_BLANK_EX:
           goto C1_099_PROCEDURE;
       C1_099_PROCEDURE_EX:
           goto C1_101_SPACE;
       C1_101_SPACE_EX:
           goto C1_102_DIVISION;
       C1_102_DIVISION_EX:
           goto C1_104_FULLSTOP;
       C1_104_FULLSTOP_EX:
           goto C1_096_PROCEDURE_DIVISION_EX;
      /**/
       C1_097_BLANK:
       C1_098_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_098_BLANK;
           goto C1_097_BLANK_EX;
      /**/
       C1_098_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_098_BLANK_EX;
      /**/
       C1_099_PROCEDURE:
       C1_100_PROCEDURE_CHAR_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_100_PROCEDURE_CHAR;
           goto C1_099_PROCEDURE_EX;
      /**/
       C1_100_PROCEDURE_CHAR:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_100_PROCEDURE_CHAR_EX;
      /**/
       C1_101_SPACE:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_101_SPACE_EX;
      /**/
       C1_102_DIVISION:
       C1_103_DIVISION_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_103_DIVISION_CHAR;
           goto C1_102_DIVISION_EX;
      /**/
       C1_103_DIVISION_CHAR:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_103_DIVISION_CHAR_EX;
      /**/
       C1_104_FULLSTOP:
  /*013*/      putc(':',outfile);
  /*014*/      putc('\n',outfile);
           goto C1_104_FULLSTOP_EX;
      /**/
       C1_105_COMMENT_LINE:
           goto C1_106_BLANK;
       C1_106_BLANK_EX:
           goto C1_108_START_COMMENT;
       C1_108_START_COMMENT_EX:
           goto C1_109_COMMENT_TEXT;
       C1_109_COMMENT_TEXT_EX:
           goto C1_111_END_COMMENT;
       C1_111_END_COMMENT_EX:
           goto C1_105_COMMENT_LINE_EX;
      /**/
       C1_106_BLANK:
       C1_107_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_107_BLANK;
           goto C1_106_BLANK_EX;
      /**/
       C1_107_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_107_BLANK_EX;
      /**/
       C1_108_START_COMMENT:
  /*010*/      putc('/',outfile);
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_108_START_COMMENT_EX;
      /**/
       C1_109_COMMENT_TEXT:
       C1_110_COMMENT_CHAR_EX:
           if(!(
  /*C14*/         (*char_pointer=='\n')
))
                   goto C1_110_COMMENT_CHAR;
           goto C1_109_COMMENT_TEXT_EX;
      /**/
       C1_110_COMMENT_CHAR:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_110_COMMENT_CHAR_EX;
      /**/
       C1_111_END_COMMENT:
  /*015*/      putc('*',outfile); putc('/',outfile);
  /*008*/      putc(*char_pointer,outfile);
           goto C1_111_END_COMMENT_EX;
      /**/
       C1_112_STOP_RUN_LINE:
           goto C1_113_BLANK;
       C1_113_BLANK_EX:
           goto C1_115_STOP_RUN;
       C1_115_STOP_RUN_EX:
           goto C1_112_STOP_RUN_LINE_EX;
      /**/
       C1_113_BLANK:
       C1_114_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_114_BLANK;
           goto C1_113_BLANK_EX;
      /**/
       C1_114_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_114_BLANK_EX;
      /**/
       C1_115_STOP_RUN:
  /*016*/      fprintf(outfile,"goto veryend;\n");
           goto C1_115_STOP_RUN_EX;
      /**/
       C1_116_GOTOLINE:
           goto C1_117_BLANK;
       C1_117_BLANK_EX:
           goto C1_119_GO_TO;
       C1_119_GO_TO_EX:
           goto C1_120_GOTO_LABEL;
       C1_120_GOTO_LABEL_EX:
           goto C1_124_FULLSTOP;
       C1_124_FULLSTOP_EX:
           goto C1_116_GOTOLINE_EX;
      /**/
       C1_117_BLANK:
       C1_118_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_118_BLANK;
           goto C1_117_BLANK_EX;
      /**/
       C1_118_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_118_BLANK_EX;
      /**/
       C1_119_GO_TO:
  /*017*/      fprintf(outfile,"goto C");
           char_pointer+=6;
           goto C1_119_GO_TO_EX;
      /**/
       C1_120_GOTO_LABEL:
       C1_121_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_121_CHAR;
           goto C1_120_GOTO_LABEL_EX;
      /**/
       C1_121_CHAR:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_122_HYPHEN;
 /*ELSE*/      goto C1_123_NOT_HYPHEN;
       C1_122_HYPHEN_EX:
       C1_123_NOT_HYPHEN_EX:
           goto C1_121_CHAR_EX;
      /**/
       C1_122_HYPHEN:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_122_HYPHEN_EX;
      /**/
       C1_123_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_123_NOT_HYPHEN_EX;
      /**/
       C1_124_FULLSTOP:
  /*018*/      putc(';',outfile);
  /*014*/      putc('\n',outfile);
           goto C1_124_FULLSTOP_EX;
      /**/
       C1_125_LABEL_LINE:
           goto C1_126_LABEL_SUBTREE;
       C1_126_LABEL_SUBTREE_EX:
           goto C1_125_LABEL_LINE_EX;
      /**/
       C1_126_LABEL_SUBTREE:
           goto C1_127_BLANK;
       C1_127_BLANK_EX:
           goto C1_129_START_LABEL_NAME;
       C1_129_START_LABEL_NAME_EX:
           goto C1_130_LABEL_NAME;
       C1_130_LABEL_NAME_EX:
           goto C1_134_FULLSTOP;
       C1_134_FULLSTOP_EX:
           goto C1_135_POSSIBLE_SUBTREE;
       C1_135_POSSIBLE_SUBTREE_EX:
           goto C1_126_LABEL_SUBTREE_EX;
      /**/
       C1_127_BLANK:
       C1_128_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_128_BLANK;
           goto C1_127_BLANK_EX;
      /**/
       C1_128_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_128_BLANK_EX;
      /**/
       C1_129_START_LABEL_NAME:
  /*021*/      loop=0;
  /*019*/      putc('C',outfile);
           goto C1_129_START_LABEL_NAME_EX;
      /**/
       C1_130_LABEL_NAME:
       C1_131_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_131_CHAR;
           goto C1_130_LABEL_NAME_EX;
      /**/
       C1_131_CHAR:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_132_HYPHEN;
           if(!(
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_133_NOT_HYPHEN;
       C1_132_HYPHEN_EX:
       C1_133_NOT_HYPHEN_EX:
           goto C1_131_CHAR_EX;
      /**/
       C1_132_HYPHEN:
  /*012*/      putc('_',outfile);
  /*032*/      check_name[loop]=*char_pointer;
  /*028*/      loop++;
  /*009*/      char_pointer++;
           goto C1_132_HYPHEN_EX;
      /**/
       C1_133_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*032*/      check_name[loop]=*char_pointer;
  /*028*/      loop++;
  /*009*/      char_pointer++;
           goto C1_133_NOT_HYPHEN_EX;
      /**/
       C1_134_FULLSTOP:
  /*033*/      check_name[loop]='\0';
  /*013*/      putc(':',outfile);
  /*014*/      putc('\n',outfile);
  /*034*/      sub_num=find_sub(check_name);
           goto C1_134_FULLSTOP_EX;
      /**/
       C1_135_POSSIBLE_SUBTREE:
           if(!(
  /*C20*/         (sub_num==0)
))
                   goto C1_136_SWITCH;
       C1_136_SWITCH_EX:
           goto C1_135_POSSIBLE_SUBTREE_EX;
      /**/
       C1_136_SWITCH:
           goto C1_137_HEADER;
       C1_137_HEADER_EX:
           goto C1_144_BODY;
       C1_144_BODY_EX:
           goto C1_136_SWITCH_EX;
      /**/
       C1_137_HEADER:
           goto C1_138_START;
       C1_138_START_EX:
           goto C1_139_BODY;
       C1_139_BODY_EX:
           goto C1_143_END;
       C1_143_END_EX:
           goto C1_137_HEADER_EX;
      /**/
       C1_138_START:
  /*004*/      fgets(inrec,100,infile);
  /*054*/      fprintf(outfile,"                switch(g");
  /*055*/      char_pointer=root[sub_num-1].sub_name;
           goto C1_138_START_EX;
      /**/
       C1_139_BODY:
       C1_140_SUB_NAME_EX:
           if(!(
  /*C26*/         (*char_pointer=='\0')
))
                   goto C1_140_SUB_NAME;
           goto C1_139_BODY_EX;
      /**/
       C1_140_SUB_NAME:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_141_;
 /*ELSE*/      goto C1_142_NOT_HYPHEN;
       C1_141__EX:
       C1_142_NOT_HYPHEN_EX:
           goto C1_140_SUB_NAME_EX;
      /**/
       C1_141_:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_141__EX;
      /**/
       C1_142_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_142_NOT_HYPHEN_EX;
      /**/
       C1_143_END:
  /*056*/      fprintf(outfile,"){\n");
           goto C1_143_END_EX;
      /**/
       C1_144_BODY:
           goto C1_145_BODY_START;
       C1_145_BODY_START_EX:
           goto C1_146_BODY_MAIN;
       C1_146_BODY_MAIN_EX:
           goto C1_154_BODY_END;
       C1_154_BODY_END_EX:
           goto C1_144_BODY_EX;
      /**/
       C1_145_BODY_START:
  /*021*/      loop=0;
           goto C1_145_BODY_START_EX;
      /**/
       C1_146_BODY_MAIN:
       C1_147_CASE_EX:
           if(!(
  /*C28*/         (loop==root[sub_num-1].main_number)
))
                   goto C1_147_CASE;
           goto C1_146_BODY_MAIN_EX;
      /**/
       C1_147_CASE:
           goto C1_148_CASE_START;
       C1_148_CASE_START_EX:
           goto C1_149_CASE_BODY;
       C1_149_CASE_BODY_EX:
           goto C1_153_CASE_END;
       C1_153_CASE_END_EX:
           goto C1_147_CASE_EX;
      /**/
       C1_148_CASE_START:
  /*058*/      fprintf(outfile,"                case %d : goto C",loop);
  /*059*/      char_pointer=root[sub_num-1].exits[loop].exit;
           goto C1_148_CASE_START_EX;
      /**/
       C1_149_CASE_BODY:
       C1_150_CASE_NAME_EX:
           if(!(
  /*C26*/         (*char_pointer=='\0')
))
                   goto C1_150_CASE_NAME;
           goto C1_149_CASE_BODY_EX;
      /**/
       C1_150_CASE_NAME:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_151_HYPHEN;
 /*ELSE*/      goto C1_152_NOT_HYPHEN;
       C1_151_HYPHEN_EX:
       C1_152_NOT_HYPHEN_EX:
           goto C1_150_CASE_NAME_EX;
      /**/
       C1_151_HYPHEN:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_151_HYPHEN_EX;
      /**/
       C1_152_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_152_NOT_HYPHEN_EX;
      /**/
       C1_153_CASE_END:
  /*060*/      fprintf(outfile,";break;\n");
  /*028*/      loop++;
           goto C1_153_CASE_END_EX;
      /**/
       C1_154_BODY_END:
  /*057*/      fprintf(outfile,"                }\n");
           goto C1_154_BODY_END_EX;
      /**/
       C1_155_ELSE_LINE:
           goto C1_156_ELSE_SUBTREE;
       C1_156_ELSE_SUBTREE_EX:
           goto C1_155_ELSE_LINE_EX;
      /**/
       C1_156_ELSE_SUBTREE:
           goto C1_157_BLANK;
       C1_157_BLANK_EX:
           goto C1_159_POSS_COMMENT;
       C1_159_POSS_COMMENT_EX:
           goto C1_165_GOTO_LINE;
       C1_165_GOTO_LINE_EX:
           goto C1_156_ELSE_SUBTREE_EX;
      /**/
       C1_157_BLANK:
       C1_158_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_158_BLANK;
           goto C1_157_BLANK_EX;
      /**/
       C1_158_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
  /*028*/      loop++;
           goto C1_158_BLANK_EX;
      /**/
       C1_159_POSS_COMMENT:
           if((
  /*C18*/         (loop<5)
))
                   goto C1_160_ELSE_BLOCK;
       C1_160_ELSE_BLOCK_EX:
           goto C1_159_POSS_COMMENT_EX;
      /**/
       C1_160_ELSE_BLOCK:
           goto C1_161_START_COMMENT;
       C1_161_START_COMMENT_EX:
           goto C1_162_ELSE_FIELD;
       C1_162_ELSE_FIELD_EX:
           goto C1_164_END_COMMENT;
       C1_164_END_COMMENT_EX:
           goto C1_160_ELSE_BLOCK_EX;
      /**/
       C1_161_START_COMMENT:
  /*029*/      putc('/',outfile); putc('*',outfile);
           goto C1_161_START_COMMENT_EX;
      /**/
       C1_162_ELSE_FIELD:
       C1_163__EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_163_;
           goto C1_162_ELSE_FIELD_EX;
      /**/
       C1_163_:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_163__EX;
      /**/
       C1_164_END_COMMENT:
  /*015*/      putc('*',outfile); putc('/',outfile);
           goto C1_164_END_COMMENT_EX;
      /**/
       C1_165_GOTO_LINE:
           goto C1_166_BLANK;
       C1_166_BLANK_EX:
           goto C1_168_GO_TO;
       C1_168_GO_TO_EX:
           goto C1_169_GOTO_LABEL;
       C1_169_GOTO_LABEL_EX:
           goto C1_173_FULLSTOP;
       C1_173_FULLSTOP_EX:
           goto C1_165_GOTO_LINE_EX;
      /**/
       C1_166_BLANK:
       C1_167_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_167_BLANK;
           goto C1_166_BLANK_EX;
      /**/
       C1_167_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_167_BLANK_EX;
      /**/
       C1_168_GO_TO:
  /*017*/      fprintf(outfile,"goto C");
           char_pointer+=6;
           goto C1_168_GO_TO_EX;
      /**/
       C1_169_GOTO_LABEL:
       C1_170_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_170_CHAR;
           goto C1_169_GOTO_LABEL_EX;
      /**/
       C1_170_CHAR:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_171_HYPHEN;
 /*ELSE*/      goto C1_172_NOT_HYPHEN;
       C1_171_HYPHEN_EX:
       C1_172_NOT_HYPHEN_EX:
           goto C1_170_CHAR_EX;
      /**/
       C1_171_HYPHEN:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_171_HYPHEN_EX;
      /**/
       C1_172_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_172_NOT_HYPHEN_EX;
      /**/
       C1_173_FULLSTOP:
  /*018*/      putc(';',outfile);
  /*014*/      putc('\n',outfile);
           goto C1_173_FULLSTOP_EX;
      /**/
       C1_174_IF_OR_IF_NOT_LINE:
           goto C1_175_IF_IFNOT_SUBTREE;
       C1_175_IF_IFNOT_SUBTREE_EX:
           goto C1_174_IF_OR_IF_NOT_LINE_EX;
      /**/
       C1_175_IF_IFNOT_SUBTREE:
           goto C1_176_BLANK;
       C1_176_BLANK_EX:
           goto C1_178_IF_HEADER;
       C1_178_IF_HEADER_EX:
           goto C1_181_CONDITION_LINES;
       C1_181_CONDITION_LINES_EX:
           goto C1_197_END_IF;
       C1_197_END_IF_EX:
           goto C1_198_POSSIBLY_OPERATIONS;
       C1_198_POSSIBLY_OPERATIONS_EX:
           goto C1_175_IF_IFNOT_SUBTREE_EX;
      /**/
       C1_176_BLANK:
       C1_177_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_177_BLANK;
           goto C1_176_BLANK_EX;
      /**/
       C1_177_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_177_BLANK_EX;
      /**/
       C1_178_IF_HEADER:
           if((
  /*C09*/         (is_it(inrec,"IF NOT") && (!is_it(inrec,"IF NOT NOT")))
))
                   goto C1_179_IF_NOT;
           if(!(
  /*C09*/         (is_it(inrec,"IF NOT") && (!is_it(inrec,"IF NOT NOT")))
))
                   goto C1_180_IF;
       C1_179_IF_NOT_EX:
       C1_180_IF_EX:
           goto C1_178_IF_HEADER_EX;
      /**/
       C1_179_IF_NOT:
  /*020*/      fprintf(outfile,"if(!(\n");
  /*004*/      fgets(inrec,100,infile);
  /*007*/      char_pointer=inrec;
           goto C1_179_IF_NOT_EX;
      /**/
       C1_180_IF:
  /*023*/      fprintf(outfile,"if((\n");
  /*004*/      fgets(inrec,100,infile);
  /*007*/      char_pointer=inrec;
           goto C1_180_IF_EX;
      /**/
       C1_181_CONDITION_LINES:
       C1_182_CONDITION_LINE_EX:
           if(!(
  /*C16*/         (is_it(inrec,"GO TO") || is_it(inrec,"!Q!"))
))
                   goto C1_182_CONDITION_LINE;
           goto C1_181_CONDITION_LINES_EX;
      /**/
       C1_182_CONDITION_LINE:
           goto C1_183_NORM;
       C1_183_NORM_EX:
           goto C1_196_GET_NEXT;
       C1_196_GET_NEXT_EX:
           goto C1_182_CONDITION_LINE_EX;
      /**/
       C1_183_NORM:
           goto C1_184_START;
       C1_184_START_EX:
           goto C1_185_BLANK;
       C1_185_BLANK_EX:
           goto C1_187_POSSIBLE_OP_ETC;
       C1_187_POSSIBLE_OP_ETC_EX:
           goto C1_193_REST_OF_LINE;
       C1_193_REST_OF_LINE_EX:
           goto C1_195_TERMINATE;
       C1_195_TERMINATE_EX:
           goto C1_183_NORM_EX;
      /**/
       C1_184_START:
  /*021*/      loop=0;
           goto C1_184_START_EX;
      /**/
       C1_185_BLANK:
       C1_186_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_186_BLANK;
           goto C1_185_BLANK_EX;
      /**/
       C1_186_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
  /*028*/      loop++;
           goto C1_186_BLANK_EX;
      /**/
       C1_187_POSSIBLE_OP_ETC:
           if((
  /*C18*/         (loop<5)
))
                   goto C1_188_NEED_TO_COMMENT;
       C1_188_NEED_TO_COMMENT_EX:
           goto C1_187_POSSIBLE_OP_ETC_EX;
      /**/
       C1_188_NEED_TO_COMMENT:
           goto C1_189_START_COMMENT;
       C1_189_START_COMMENT_EX:
           goto C1_190_COMMENT_THESE;
       C1_190_COMMENT_THESE_EX:
           goto C1_192_END_COMMENT;
       C1_192_END_COMMENT_EX:
           goto C1_188_NEED_TO_COMMENT_EX;
      /**/
       C1_189_START_COMMENT:
  /*029*/      putc('/',outfile); putc('*',outfile);
           goto C1_189_START_COMMENT_EX;
      /**/
       C1_190_COMMENT_THESE:
       C1_191_BLANK_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_191_BLANK;
           goto C1_190_COMMENT_THESE_EX;
      /**/
       C1_191_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_191_BLANK_EX;
      /**/
       C1_192_END_COMMENT:
  /*015*/      putc('*',outfile); putc('/',outfile);
           goto C1_192_END_COMMENT_EX;
      /**/
       C1_193_REST_OF_LINE:
       C1_194_CHAR_EX:
           if(!(
  /*C14*/         (*char_pointer=='\n')
))
                   goto C1_194_CHAR;
           goto C1_193_REST_OF_LINE_EX;
      /**/
       C1_194_CHAR:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_194_CHAR_EX;
      /**/
       C1_195_TERMINATE:
  /*014*/      putc('\n',outfile);
           goto C1_195_TERMINATE_EX;
      /**/
       C1_196_GET_NEXT:
  /*004*/      fgets(inrec,100,infile);
  /*007*/      char_pointer=inrec;
           goto C1_196_GET_NEXT_EX;
      /**/
       C1_197_END_IF:
  /*022*/      fprintf(outfile,"))\n");
           goto C1_197_END_IF_EX;
      /**/
      /** The if may be derived from a quit*/
      /** in which case it is possible that there */
      /** may be operations associated with the*/
      /** if statement as well as conditional */
      /** statements.*/
      /** these are represented in probench*/
      /** for the purpose of this program as*/
      /** starting with !Q! on the first op*/
      /**/
       C1_198_POSSIBLY_OPERATIONS:
           if((
  /*C17*/         (is_it(inrec,"!Q!") )
))
                   goto C1_199_QUIT_OPS;
           if(!(
  /*C17*/         (is_it(inrec,"!Q!") )
))
                   goto C1_233_JUST_GOTO;
       C1_199_QUIT_OPS_EX:
       C1_233_JUST_GOTO_EX:
           goto C1_198_POSSIBLY_OPERATIONS_EX;
      /**/
       C1_199_QUIT_OPS:
           goto C1_200_FIRST_OP_LINE;
       C1_200_FIRST_OP_LINE_EX:
           goto C1_207_OP_LINES;
       C1_207_OP_LINES_EX:
           goto C1_223_GOTO_LINE;
       C1_223_GOTO_LINE_EX:
           goto C1_232_END_OF__QUIT_OPS;
       C1_232_END_OF__QUIT_OPS_EX:
           goto C1_199_QUIT_OPS_EX;
      /**/
       C1_200_FIRST_OP_LINE:
           goto C1_201_BLANK;
       C1_201_BLANK_EX:
           goto C1_203_SHRIEK_Q_SHRIEK;
       C1_203_SHRIEK_Q_SHRIEK_EX:
           goto C1_204_REST_OF_LINE;
       C1_204_REST_OF_LINE_EX:
           goto C1_206_END_OF_LINE;
       C1_206_END_OF_LINE_EX:
           goto C1_200_FIRST_OP_LINE_EX;
      /**/
       C1_201_BLANK:
       C1_202_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_202_BLANK;
           goto C1_201_BLANK_EX;
      /**/
       C1_202_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_202_BLANK_EX;
      /**/
       C1_203_SHRIEK_Q_SHRIEK:
  /*025*/      char_pointer+=3;
  /*024*/      putc('{',outfile);
           goto C1_203_SHRIEK_Q_SHRIEK_EX;
      /**/
       C1_204_REST_OF_LINE:
       C1_205_CHAR_EX:
           if(!(
  /*C14*/         (*char_pointer=='\n')
))
                   goto C1_205_CHAR;
           goto C1_204_REST_OF_LINE_EX;
      /**/
       C1_205_CHAR:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_205_CHAR_EX;
      /**/
       C1_206_END_OF_LINE:
  /*014*/      putc('\n',outfile);
  /*004*/      fgets(inrec,100,infile);
  /*007*/      char_pointer=inrec;
           goto C1_206_END_OF_LINE_EX;
      /**/
       C1_207_OP_LINES:
       C1_208_OP_LINE_EX:
           if(!(
  /*C07*/         (is_it(inrec,"GO TO"))
))
                   goto C1_208_OP_LINE;
           goto C1_207_OP_LINES_EX;
      /**/
       C1_208_OP_LINE:
           goto C1_209_NORM;
       C1_209_NORM_EX:
           goto C1_222_NEXT;
       C1_222_NEXT_EX:
           goto C1_208_OP_LINE_EX;
      /**/
       C1_209_NORM:
           goto C1_210_START;
       C1_210_START_EX:
           goto C1_211_BLANK;
       C1_211_BLANK_EX:
           goto C1_213_POSSIBLE_OP_ETC;
       C1_213_POSSIBLE_OP_ETC_EX:
           goto C1_219_REST_OF_LINE;
       C1_219_REST_OF_LINE_EX:
           goto C1_221_TERMINATE;
       C1_221_TERMINATE_EX:
           goto C1_209_NORM_EX;
      /**/
       C1_210_START:
  /*021*/      loop=0;
           goto C1_210_START_EX;
      /**/
       C1_211_BLANK:
       C1_212_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_212_BLANK;
           goto C1_211_BLANK_EX;
      /**/
       C1_212_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
  /*028*/      loop++;
           goto C1_212_BLANK_EX;
      /**/
       C1_213_POSSIBLE_OP_ETC:
           if((
  /*C18*/         (loop<5)
))
                   goto C1_214_NEED_TO_COMMENT;
       C1_214_NEED_TO_COMMENT_EX:
           goto C1_213_POSSIBLE_OP_ETC_EX;
      /**/
       C1_214_NEED_TO_COMMENT:
           goto C1_215_START_COMMENT;
       C1_215_START_COMMENT_EX:
           goto C1_216_COMMENT_THESE;
       C1_216_COMMENT_THESE_EX:
           goto C1_218_END_COMMENT;
       C1_218_END_COMMENT_EX:
           goto C1_214_NEED_TO_COMMENT_EX;
      /**/
       C1_215_START_COMMENT:
  /*029*/      putc('/',outfile); putc('*',outfile);
           goto C1_215_START_COMMENT_EX;
      /**/
       C1_216_COMMENT_THESE:
       C1_217_BLANK_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_217_BLANK;
           goto C1_216_COMMENT_THESE_EX;
      /**/
       C1_217_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_217_BLANK_EX;
      /**/
       C1_218_END_COMMENT:
  /*015*/      putc('*',outfile); putc('/',outfile);
           goto C1_218_END_COMMENT_EX;
      /**/
       C1_219_REST_OF_LINE:
       C1_220_CHAR_EX:
           if(!(
  /*C14*/         (*char_pointer=='\n')
))
                   goto C1_220_CHAR;
           goto C1_219_REST_OF_LINE_EX;
      /**/
       C1_220_CHAR:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_220_CHAR_EX;
      /**/
       C1_221_TERMINATE:
  /*014*/      putc('\n',outfile);
           goto C1_221_TERMINATE_EX;
      /**/
       C1_222_NEXT:
  /*004*/      fgets(inrec,100,infile);
  /*007*/      char_pointer=inrec;
           goto C1_222_NEXT_EX;
      /**/
       C1_223_GOTO_LINE:
           goto C1_224_BLANK;
       C1_224_BLANK_EX:
           goto C1_226_GO_TO;
       C1_226_GO_TO_EX:
           goto C1_227_GOTO_LABEL;
       C1_227_GOTO_LABEL_EX:
           goto C1_231_FULLSTOP;
       C1_231_FULLSTOP_EX:
           goto C1_223_GOTO_LINE_EX;
      /**/
       C1_224_BLANK:
       C1_225_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_225_BLANK;
           goto C1_224_BLANK_EX;
      /**/
       C1_225_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_225_BLANK_EX;
      /**/
       C1_226_GO_TO:
  /*017*/      fprintf(outfile,"goto C");
           char_pointer+=6;
           goto C1_226_GO_TO_EX;
      /**/
       C1_227_GOTO_LABEL:
       C1_228_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_228_CHAR;
           goto C1_227_GOTO_LABEL_EX;
      /**/
       C1_228_CHAR:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_229_HYPHEN;
 /*ELSE*/      goto C1_230_NOT_HYPHEN;
       C1_229_HYPHEN_EX:
       C1_230_NOT_HYPHEN_EX:
           goto C1_228_CHAR_EX;
      /**/
       C1_229_HYPHEN:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_229_HYPHEN_EX;
      /**/
       C1_230_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_230_NOT_HYPHEN_EX;
      /**/
       C1_231_FULLSTOP:
  /*018*/      putc(';',outfile);
  /*014*/      putc('\n',outfile);
           goto C1_231_FULLSTOP_EX;
      /**/
       C1_232_END_OF__QUIT_OPS:
  /*026*/      fprintf(outfile,"                   }\n");
           goto C1_232_END_OF__QUIT_OPS_EX;
      /**/
       C1_233_JUST_GOTO:
           goto C1_234_GOTO_LINE;
       C1_234_GOTO_LINE_EX:
           goto C1_233_JUST_GOTO_EX;
      /**/
       C1_234_GOTO_LINE:
           goto C1_235_BLANK;
       C1_235_BLANK_EX:
           goto C1_237_GO_TO;
       C1_237_GO_TO_EX:
           goto C1_238_GOTO_LABEL;
       C1_238_GOTO_LABEL_EX:
           goto C1_242_FULLSTOP;
       C1_242_FULLSTOP_EX:
           goto C1_234_GOTO_LINE_EX;
      /**/
       C1_235_BLANK:
       C1_236_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_236_BLANK;
           goto C1_235_BLANK_EX;
      /**/
       C1_236_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_236_BLANK_EX;
      /**/
       C1_237_GO_TO:
  /*017*/      fprintf(outfile,"goto C");
           char_pointer+=6;
           goto C1_237_GO_TO_EX;
      /**/
       C1_238_GOTO_LABEL:
       C1_239_CHAR_EX:
           if(!(
  /*C12*/         (*char_pointer=='.')
))
                   goto C1_239_CHAR;
           goto C1_238_GOTO_LABEL_EX;
      /**/
       C1_239_CHAR:
           if((
  /*C15*/         (*char_pointer=='-')
))
                   goto C1_240_HYPHEN;
 /*ELSE*/      goto C1_241_NOT_HYPHEN;
       C1_240_HYPHEN_EX:
       C1_241_NOT_HYPHEN_EX:
           goto C1_239_CHAR_EX;
      /**/
       C1_240_HYPHEN:
  /*012*/      putc('_',outfile);
  /*009*/      char_pointer++;
           goto C1_240_HYPHEN_EX;
      /**/
       C1_241_NOT_HYPHEN:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_241_NOT_HYPHEN_EX;
      /**/
       C1_242_FULLSTOP:
  /*018*/      putc(';',outfile);
  /*014*/      putc('\n',outfile);
           goto C1_242_FULLSTOP_EX;
      /**/
       C1_243_NORMAL_LINE:
           goto C1_244_NORM;
       C1_244_NORM_EX:
           goto C1_243_NORMAL_LINE_EX;
      /**/
       C1_244_NORM:
           goto C1_245_START;
       C1_245_START_EX:
           goto C1_246_BLANK;
       C1_246_BLANK_EX:
           goto C1_248_POSSIBLE_OP_ETC;
       C1_248_POSSIBLE_OP_ETC_EX:
           goto C1_254_REST_OF_LINE;
       C1_254_REST_OF_LINE_EX:
           goto C1_256_TERMINATE;
       C1_256_TERMINATE_EX:
           goto C1_244_NORM_EX;
      /**/
       C1_245_START:
  /*021*/      loop=0;
           goto C1_245_START_EX;
      /**/
       C1_246_BLANK:
       C1_247_BLANK_EX:
           if(!(
  /*C29*/         (*char_pointer!=' ')
))
                   goto C1_247_BLANK;
           goto C1_246_BLANK_EX;
      /**/
       C1_247_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
  /*028*/      loop++;
           goto C1_247_BLANK_EX;
      /**/
       C1_248_POSSIBLE_OP_ETC:
           if((
  /*C18*/         (loop<5)
))
                   goto C1_249_NEED_TO_COMMENT;
       C1_249_NEED_TO_COMMENT_EX:
           goto C1_248_POSSIBLE_OP_ETC_EX;
      /**/
       C1_249_NEED_TO_COMMENT:
           goto C1_250_START_COMMENT;
       C1_250_START_COMMENT_EX:
           goto C1_251_COMMENT_THESE;
       C1_251_COMMENT_THESE_EX:
           goto C1_253_END_COMMENT;
       C1_253_END_COMMENT_EX:
           goto C1_249_NEED_TO_COMMENT_EX;
      /**/
       C1_250_START_COMMENT:
  /*029*/      putc('/',outfile); putc('*',outfile);
           goto C1_250_START_COMMENT_EX;
      /**/
       C1_251_COMMENT_THESE:
       C1_252_BLANK_EX:
           if(!(
  /*C11*/         (*char_pointer==' ')
))
                   goto C1_252_BLANK;
           goto C1_251_COMMENT_THESE_EX;
      /**/
       C1_252_BLANK:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_252_BLANK_EX;
      /**/
       C1_253_END_COMMENT:
  /*015*/      putc('*',outfile); putc('/',outfile);
           goto C1_253_END_COMMENT_EX;
      /**/
       C1_254_REST_OF_LINE:
       C1_255_CHAR_EX:
           if(!(
  /*C14*/         (*char_pointer=='\n')
))
                   goto C1_255_CHAR;
           goto C1_254_REST_OF_LINE_EX;
      /**/
       C1_255_CHAR:
  /*008*/      putc(*char_pointer,outfile);
  /*009*/      char_pointer++;
           goto C1_255_CHAR_EX;
      /**/
       C1_256_TERMINATE:
  /*014*/      putc('\n',outfile);
           goto C1_256_TERMINATE_EX;
      /**/
       C1_257_LINE_END:
  /*004*/      fgets(inrec,100,infile);
           goto C1_257_LINE_END_EX;
      /**/
       C1_258_END:
  /*006*/      fprintf(outfile,"veryend: ;\n}");
  /*027*/      fclose(infile);
  /*030*/      fclose(outfile);
           goto C1_258_END_EX;
      /**/
       C1_259_OOPS:
  /*003*/      exit(1);
           goto C1_259_OOPS_EX;
      /**/
      /*   Data Analysis Map*/
      /**/
      /*                         ------------- Data Analysis By -------------*/
      /**/
      /*                         BOX TYPE               OPERATION  ALLOCATION*/
      /*  Tree name: COBOL_TO-C*/
      /**/
      /*                         Leaf      : 132          Operations: 239*/
      /*                                                  Quits     :   4*/
      /*                         Selections:  19*/
      /*                         Sequences :  53*/
      /*                         Iterations:  54*/
      /*                         Backtracks:   1*/
      /*                         Subtrees  :   0*/
      /**/
      /**/
      /**/
veryend: ;
}
\end{verbatim}
