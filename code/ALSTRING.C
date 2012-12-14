
#include "alstring.h"

#include <stdio.h>
#include "errors.h"



/**********
***********             FUNCTIONS
***********/
/*      function allocates memory for a dynamic string, handles out
        out of memory errors, initialises the string and returns its 
        address*/

DYNAMIC_STRING *create_dynamic_string()
  {
    DYNAMIC_STRING *dst;
    char *st;

    if((dst=(DYNAMIC_STRING *)malloc(sizeof(DYNAMIC_STRING)))==NULL)
            fatal_error("no more room for dynamic string");

     /* allocates room for 1 char !! */
    if((st=(char *)malloc(sizeof(char)))==NULL)
            fatal_error("no more room for string part");


     /* make the string end legally */
     st[0]='\0';

     dst->max_size=sizeof(char);
     dst->curr_size=0;
     dst->string_part=st;

     return dst;
  }

/*      append a character to a dynamic string, resize if necessary */
void append_to_string(char ch,DYNAMIC_STRING *dynamic_string)
   {
     /* if the next slot is the last slot then resize */
     if((dynamic_string->curr_size+1)==dynamic_string->max_size)
            resize_by(dynamic_string,INCR);

     /* curr_size acts as a subscript to the last character */
     dynamic_string->string_part[dynamic_string->curr_size]=ch;

     dynamic_string->curr_size++;
     dynamic_string->max_size++;
     dynamic_string->string_part[dynamic_string->curr_size]='\0';
   }

/*      resize a dynamic string by allocating memory, copying from
        the old memory locations to the new one, and freeing the
        old locations */
void resize_by(DYNAMIC_STRING *dynamic_string, int incr)
    {
      char *increased;

      if((increased=(char *)realloc((char *)dynamic_string->string_part,
                                  dynamic_string->max_size+incr))==NULL)
              fatal_error("no room to resize a dynamic string");


      strcpy(increased,dynamic_string->string_part);
      free(dynamic_string->string_part);

      dynamic_string->string_part=increased;
      dynamic_string->max_size+=incr;
    }

/* resets a dynamic string to 1 char length */
void reset_string(DYNAMIC_STRING *dst)
   {
     char *st;

     free(dst->string_part);

     /* allocates room for 1 char !! */
     if((st=(char *)malloc(sizeof(char)))==NULL)
          fatal_error("no more room for string part");


     /* make the string end legally */
     st[0]='\0';

     dst->max_size=sizeof(char);
     dst->curr_size=0;
     dst->string_part=st;

  }

/* force uppercase */
void force_upper(char *string)
   {
     while(*string!='\0')
       {
        *string=toupper(*string);
        string++;
       }
   }

/* totally destroy a dynamic string */
void destroy_dynamic(DYNAMIC_STRING *dst)
   {
     free(dst->string_part);
     free(dst);
   }

/* return the string but destroy the shell */
char *extract_then(DYNAMIC_STRING *dst)
   {
     free(dst);
     return(dst->string_part);
   }


        


