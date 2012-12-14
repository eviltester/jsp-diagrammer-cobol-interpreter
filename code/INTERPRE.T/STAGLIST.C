\begin{verbatim}
/*===============================================*
 *        STAGLIST.C                             *
 * an implementation of a trie for keyword names *
 * memory intensive and does not work on a PC    *
 *===============================================*/

#include "staglist.h"

#define DATA_FIELD              27
#define HYPHEN_FIELD    26

/*===========================*
 * allocates memory for list *
 *===========================*/
staggered_list *create_list()
        {
                int loop;
                staggered_list *stag;
                stag= (staggered_list *)malloc(sizeof(staggered_list));
                if(stag==NULL)
                 fatal_error("not enough memory for staggered list segment");

                for(loop=0;loop<27;loop++)
                        stag->pointer[loop]=NULL;
                stag->data=NULL;

                return stag;
        }

/*========================================*
 * return the data held at this trie node *
 *========================================*/
int get_data(staggered_list *stag)
        {
                return stag->data;
        }

/*======================================*
 * insert data at this trie node        *
 *======================================*/
void put_data(staggered_list *stag,int put)
        {
                stag->data=put;
        }

/*============================================================*
 * work out what the offset in the list for this character    *
 * is and if it is null then create a new list segment for it *
 * then return the address of the segment                     *
 *============================================================*/
staggered_list *add_pointer(staggered_list *stag,char ch)
     {
       int offset=(ch=='-') ? HYPHEN_FIELD : (ch-'A');

       if(stag->pointer[offset]==NULL)
          stag->pointer[offset]=create_list();

       return(stag->pointer[offset]);

     }
/*==============================================================*
 * retrieves the pointer for a stag list segment at a character *
 * offset                                                       *
 *==============================================================*/
staggered_list *check_pointer(staggered_list *stag,char ch)
        {
            return(stag->pointer[(ch=='-') ? HYPHEN_FIELD : (ch-'A')]);
        }

/*============================================================*
 * builds up a trie using data from the file, the unique data *
 * number is only incremented when a field with an * is found *
 * this allows verbs such as ZERO,ZEROES to share the same    *
 * keyword value, since they are effectively the same keyword *
 *============================================================*/
staggered_list *create_list_with_file(char *infile_name)
  {
     FILE *infile=open_input(infile_name);
     char ch;
     staggered_list *list_pointer,*root=create_list();
     int data_count=0;

     ch=getc(infile);

     data_count= (ch=='*') ? 0 : 1;  /* 0 reserved for undefined etc*/

     while(ch!=EOF)
        {
           if(ch=='*'){
                       data_count++;
                       ch=getc(infile);
                       }

           list_pointer=root;

           while(ch!='\n' && ch!=EOF)
                {

                  list_pointer=add_pointer(list_pointer,ch);
                  ch=getc(infile);
                }
           if(ch==EOF)
               fatal_error("unexpected end of file in list setup");

           put_data(list_pointer,data_count);
           ch=getc(infile);
          }
      close_file(infile);
      return root;
   }




\end{verbatim}                        
