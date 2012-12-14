
/*================================================*
 *                   ALFILE.C                     *
 * Simplified file handling routines to open and  *
 * close files, if a file fails to be opened then *
 * the program is exited with an error message    *
 *================================================*/

#include "alfile.h"

/*===============================================*
 * open_input file opens infile_name as input if *
 * it can't be opened then an error message is   *
 * printed and the program exits                 *
 *===============================================*/
FILE *open_input(char *infile_name)
     {

     FILE *infile;

     if((infile = fopen(infile_name,"r")) == NULL)
         {
          printf(" cannot open input file %s\n",infile_name);
          exit(1);
         }
                
     return(infile);
     }

/*===================================================*
 * Open_output file opens outfile_name as output, if *
 * it can't be opened then an error message is       *
 * printed and the program exits                     *
 *===================================================*/
FILE *open_output(char *outfile_name)
    {
      FILE *outfile;

      if((outfile = fopen(outfile_name,"w")) == NULL)
            {
             printf(" cannot open output file %s\n",outfile_name);
             exit(1);
            }

      return(outfile);
    }

/*=====================================*
 * close_file closes the supplied file *
 * function  supplied to be consistent *
 * with above calls                    *
 *=====================================*/ 
void close_file(FILE *closeme)
    {
      fclose(closeme);
    }


