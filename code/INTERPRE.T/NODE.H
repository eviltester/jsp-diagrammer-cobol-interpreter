
/*===================================================*
 *                       NODE.H                      *
 * the structures used to represent variables in the *
 * interpreter                                       *
 *===================================================*/

#ifndef NODEY
#define NODEY
#include <stdio.h>

/* type of variables */
typedef enum{
             VARIABLE,
             QUALIFIER,  /* a variable name with no pic */
             STRING,
             INT,        /* numeric variable */
             CHAR        /* character variable */
            }TYPE;

/* the next structure is only for non inverted use */
/* used when saving variables to files, hash is the
   array position, unique is the value allocated to that
   variable */

typedef struct{  int hash;
                 int unique;
              }save_values;


/* the information relating to the variable 
   the name
       type - char , int etc
       format - not implemented properly yet
       data_c - for char variables pointer to the string
       data_n - for ints the value, for char the length
*/

typedef struct{ 
                char *name;
                TYPE type;
                char *format;
                char *data_c;
                int data_n;
              }DATA_INFO;

/* parent is the working storage level above the current
   younger_sibling, is the next variable at the same level
   eldest_child the first child variable
   info is the data for the variable
   level is the WS level ie 01, 02 etc.
*/

typedef struct{ 
               struct NODE *parent;
               save_values parent_stuff;
               struct NODE *younger_sibling;
               save_values sibling;
               struct NODE *eldest_child;
               save_values child;
               DATA_INFO *info;
               save_values own;
               int level;
              }NODE;

/* linked list definition for nodes */

typedef struct{
                NODE *node;
                struct NODE_LIST *link;
              }NODE_LIST;

/********************
** Macro's
********************/
#define LEVEL(N)        ((N)->level)
#define INFO(N)         ((N)->info)
#define PARENT(N)       ((N)->parent)
#define SIBLING(N)      ((N)->younger_sibling)
#define CHILD(N)        ((N)->eldest_child)

/* DATA INFO MACRO'S */
#define NAME(N)         ((N)->info->name)

/* DEFINE NODE FUNCTIONS */
extern NODE_LIST *create_node_list(NODE *);
extern NODE *create_node(void);

extern NODE_LIST *extract_link(char *,NODE_LIST *);

extern DATA_INFO *create_data_info(void);

/*macro function's*/

#define GET_NODE(NL)    ((NL)->node)
#define NEXT_LIST(NL)   ((NL)->link)
#define CREATE_BLANK_NODE_LIST()        (create_node_list(NULL))

#endif


