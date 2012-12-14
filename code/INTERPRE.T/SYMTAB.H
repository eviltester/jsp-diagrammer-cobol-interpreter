\begin{verbatim}
/*=========================================================*
 *              SYMTAB.H                                   *
 * the symbol table structure and the function definitions *
 *=========================================================*/ 
#ifndef SYMTABY
#define SYMTABY

#include "node.h"

/* arbitrary size of symbol table */

#define SYMTAB_ARRAY_SIZE 100

/* the symbol table entry structure consists of a list
   of node_lists, meaning that a number of variables 
   can share the same hash value, but also that variables
   can share the same name */

typedef struct{
                 NODE_LIST *contents;
                 struct SYMTAB_ENTRY *next;
              }SYMTAB_ENTRY;

/********** functions ************/
extern SYMTAB_ENTRY **create_symbol_table_array(int);
extern void add_node_to_sym(NODE *,int,SYMTAB_ENTRY **);
extern SYMTAB_ENTRY *create_symtab_entry(NODE_LIST *);
extern int hash(char *);
extern void print_nodes(SYMTAB_ENTRY **);
extern void print_node(NODE *);
extern void save_nodes(SYMTAB_ENTRY **,FILE *);
extern void save_node(NODE *,FILE *);
extern int load_symtab(SYMTAB_ENTRY **,char *);
extern NODE *look_for(int,int,SYMTAB_ENTRY **);
extern NODE *look_for_by_name(char *,SYMTAB_ENTRY **);
extern void cross_reference(SYMTAB_ENTRY **,int);
extern void quick_display_symtab(SYMTAB_ENTRY **,int);
extern void quick_display_node(NODE *);
extern void reset_symtab(SYMTAB_ENTRY **,int);
extern void reset_node(NODE *);


#endif

\end{verbatim}
