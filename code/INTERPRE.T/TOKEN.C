\begin{verbatim}
/*=============================================================*
 *                          TOKEN.C                            *       
 * the two token functions write and get for intermediate file *
 * access                                                      *
 *=============================================================*/

#include "token.h"

/*==============================================================*
 * write token writes out a token, this is done in several ways *
 * dependant upon the token type                                *
 *==============================================================*/
void write_token(FILE *fp,TOKEN *toke)
{
    fprintf(fp,"%d\n",toke->token_type); /* write out token type */

    if(toke->token_type==OPEN_BRACE ||    /* if (,), or . then  */
       toke->token_type==CLOSE_BRACE ||   /* write out the type */
       toke->token_type==FULLSTOP){       /* again              */ 
         fprintf(fp,"%d\n",toke->token_type);
       }
    else{
         if(toke->token_type==KEYWORD ||
            toke->token_type==OP_NUM ||
            toke->token_type==NUMERIC ||
            toke->token_type==COND_NUM ||
            toke->token_type==RELATIONAL_OP ||
            toke->token_type==NON_KEYWORD_LENGTH ||
            toke->token_type==NON_NUMERIC_LITERAL_LENGTH){
              fprintf(fp,"%d\n",toke->value.keyword_number);
            }
         else{   /* if its a string type then write it out */
              if(toke->token_type==NON_NUMERIC_LITERAL ||
                 toke->token_type==NON_KEYWORD){
                   fprintf(fp,"%s\n",toke->value.string);
                }
              else{  /* if its a variable write out hash then unique */
                   if(toke->token_type==VARIABLE_NAME){
                      fprintf(fp,"%d\n",toke->value.var_values.hash);
                      fprintf(fp,"%d\n",toke->value.var_values.unique);
                     }
                  }
             }
        }
}



/*============================================================*
 * get_token reads a token from the file, first get the token *
 * type, then read the relevant details                       *
 *============================================================*/
int get_token(FILE *fp,TOKEN *toke)
 {

char g,*str;
int size;

fscanf(fp,"%d",&(toke->token_type)); /* read token type */

if(feof(fp)) return(1);

     g=getc(fp);              /* read \n */
     if(g!='\n')
          {
           printf("token number READ ERROR\n");
           exit(0);
          }


if(toke->token_type==OPEN_BRACE ||       /* get type again */
   toke->token_type==CLOSE_BRACE ||      /* then get \n    */
   toke->token_type==FULLSTOP)
     {
     fscanf(fp,"%d",&(toke->value.keyword_number));
     g=getc(fp);
     if(g!='\n')
          {
          printf("open brace etc READ ERROR\n");
          exit(0);
          }
     }
else{
     if(toke->token_type==KEYWORD ||      /* if one of these */
        toke->token_type==OP_NUM ||       /* then read the   */
        toke->token_type==NUMERIC ||      /* integer value   */
        toke->token_type==COND_NUM ||
        toke->token_type==RELATIONAL_OP ){
               fscanf(fp,"%d",&(toke->value.keyword_number));
               g=getc(fp);
               if(g!='\n')       /* get \n */
                {
                 printf("keyword num etc READ ERROR\n");
                 exit(0);
               }
          }
     else{
          if(toke->token_type==VARIABLE_NAME) /* if variable */
            {
               /* get hash value */
               fscanf(fp,"%d",&(toke->value.var_values.hash));
               g=getc(fp);
               if(g!='\n')
                 {
                  printf("hash num etc READ ERROR\n");
                  exit(0);
                 }
               
               /* get unique value */
               fscanf(fp,"%d",&(toke->value.var_values.unique));
               g=getc(fp);
               if(g!='\n')
                 {
                  printf("unique num etc READ ERROR\n");
                  exit(0);
                 }
            }
        else          /* else it must be a string */
         {
          fscanf(fp,"%d",&size);   /* read the size */
               g=getc(fp);
               if(g!='\n')
               {
               printf("size READ ERROR\n");
               exit(0);
               }
            /* allocate the size */
          toke->value.string=(char *)malloc(size+1);
          str=toke->value.string;

              /* read the string , type first*/
              fscanf(fp,"%d",&(toke->token_type)); 
               g=getc(fp);
               if(g!='\n')
                {
                 printf("type READ ERROR\n");
                 exit(0);
                }
         
          /* then read the string */
          g=getc(fp);
          while(g!='\n'){
               *str=g;
                str++;
               *str='\0';
               g=getc(fp);
               }
          }
       }
     }
return(0);
}

\end{verbatim}
