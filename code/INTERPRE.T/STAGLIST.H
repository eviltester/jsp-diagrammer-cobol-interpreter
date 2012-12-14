\begin{verbatim}
/*====================================================*
 *           STAGLIST.H                               *
 * defines the functions necessary to maintain a trie *
 *====================================================*/
 
#ifndef STAGGERED_LIST
#define STAGGERED_LIST

#include <stdio.h>
#include "errors.h"
#include "alfile.h"


#define VALID_CHARS     27


struct stag_list_struct{
                        struct stag_list_struct *pointer[VALID_CHARS];
                        int data;
                  };

typedef struct stag_list_struct staggered_list;

extern staggered_list *create_list();
extern int get_data(staggered_list *);
extern void put_data(staggered_list *,int);
extern staggered_list *add_pointer(staggered_list *,char);
extern staggered_list *check_pointer(staggered_list *,char);
extern staggered_list *create_list_with_file(char *);
#endif

\end{verbatim}
