

/*===================================================*
 *               STRUCTS.H                           *
 * all the structures associated with the diagrammer *
 *===================================================*/

#ifndef JSPDIAG
#define JSPDIAG

#include "profile.h"


 struct OPLISTALS{
                  char op_type;
                  int op_num;
                  struct OPLISTALS *next_op;
                 };

 typedef struct OPLISTALS OPLIST;


typedef struct {
                int box_number;
                char box_name[10];
                int box_type;
                int no_children;
                OPLIST *op;
                struct BOX		 	*children;
                struct BOX			*parent;
                struct BOX			*left_sibling;
                struct BOX			*right_sibling;
                BOX_REC probench_box;
               }BOX;

 struct BOXYSTRUCT{
                   BOX *box;
                   struct BOXYSTRUCT *link;
                  };

typedef struct BOXYSTRUCT BOXLIST;

typedef struct {
                int total_boxes;
                BOX *root;
               }TREE;

#endif


