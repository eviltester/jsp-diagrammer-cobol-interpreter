
/*====================================================*
 *             ALUTIL.H                               *
 *  Any utilities that are needed in the project      *
 *  are not relevant in any other part of the project *
 *  and are not supplied by the compiler              *
 *====================================================*/
#ifndef ALUTIL
#define ALUTIL

/*=====================================================*
 * str_to_int turns the supplied character string into *
 * the returned integer value                          *
 *=====================================================*/
static int str_to_int(char *con)
   {
     int count=0;

     while(*con!='\0')
        {
         count=count*10;
         count+=(*con)-'0';
         con++;
        }
     return(count);
   }

#endif
