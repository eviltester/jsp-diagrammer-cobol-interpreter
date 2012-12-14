
/*===================================*
 *                  BOX.C            *
 * The functions that act on the box *
 * structure of the diagrammer       *
 *===================================*/
#include <stdio.h>
#include "structs.h"
#include "treebox.h"
#include "box.h"


/*=================================================*
*  Print a box, mainly prints the non Probench     *
*  Features, but prints out the probench box name  *
*==================================================*/
void box_print(box)
        BOX *box;
{
/*    int loop;
    BOXLIST *listpointer;
    BOX *boxpointer;
    OPLIST *oppointer;

    printf("BOX number %d ",box->box_number);

    printf("type:- %d \n n.o children:- %d\n",box->box_type,
                                              box->no_children);

    printf("name:- \n");
    for(loop=0;loop<10;loop++)
         printf("%c",box->probench_box.box_name[0][loop]);
    for(loop=0;loop<10;loop++)
         printf("%c",box->probench_box.box_name[1][loop]);


    if((box->no_children==0)&&((box->op)==NULL))
        printf(" box has not been allocated anything\n");
    else
        if(box->no_children==0)
           {
            printf("ops:- ");
            oppointer=box->op;
            while(oppointer->next_op!=NULL)
               {
                printf("%d ",oppointer->op_num);
                oppointer=oppointer->next_op;
               }
            printf("%d.",oppointer->op_num);
            printf("\n");
           }

    if((box->no_children)!=0)
      {
        listpointer=box->children;
        boxpointer=listpointer->box;
        printf("children list:- %d",boxpointer->box_number);
        while(listpointer->link!=NULL)
           {
             listpointer=listpointer->link;
             boxpointer=listpointer->box;
             printf(",%d",boxpointer->box_number);
           }
        printf("\n");
      }
     */
}


/*====================================*
 * Make the supplied box the root box *
 *====================================*/
void make_root(BOX *box)
{
   box->box_number=1;
   name_box(box,"root box  ");
   box->box_type=1;
   box->no_children=0;
   box->op=NULL;
   box->children=NULL;
   
   box->parent=NULL;
   box->left_sibling=NULL;
   box->right_sibling=NULL;
}


/*=====================================*
 * make the supplied name the box name *
 * the name is placed in the probench  *
 * information side                    *
 *=====================================*/
void name_box(box,name)
        BOX *box;char *name;
{

	if(box!=NULL)
        strcpy(box->probench_box.box_name,name);
}

/*=====================================*
 * Delete the supplied box and the     *
 * corresponding operations            *
 *=====================================*/
void scrub_box(BOX *box)
{
        OPLIST *oplisty,*oplisty2;



        oplisty=box->op;        /* point to first op */
        while(oplisty!=NULL)    /* do until no more ops */ 
                {
                 oplisty2=oplisty->next_op;  /* get next op */
                 free(oplisty);              /* delete current op */
                 oplisty=oplisty2;           /* point to next op */
                }

		free(box);
}

/*============================================*
 * Create a box and return the box address    *
 * the default value allocations are mainly   *
 * for the diagrammer details because the     *
 * probench values are intended to be loaded  *
 * from file, the default box_type was added  *
 * because no probench .pr0 file is read in   *
 *============================================*/
BOX *create_box(void)
{
        BOX *allocated;

        if((allocated=(BOX *)malloc(sizeof(BOX)))==NULL)
                fatal_error("no more room for box");

        allocated->box_number=0;
        allocated->box_type=1;
        allocated->no_children=0;
        allocated->op=NULL;
        allocated->children=NULL;
        
        allocated->parent=NULL;
        allocated->right_sibling=NULL;
        allocated->left_sibling=NULL;

        allocated->probench_box.box_type=SEQUENCE;

        return allocated;
}


/*==============================================*
 * A simple box editing function for the test   *
 * diagrammer, allows the setting of a box type *
 * the addition of operations, and conditions   *
 * , operations are appended to the operations  *
 * list                                         *
 *                                              *
 * NO CHECKS made on the existance of operations*
 * or conditions.                               *
 *==============================================*/
void edit_box(BOX *box,TREE *tree)
   {
      int num=0;
      OPLIST *opl;
      BOX *parent;

      parent=get_parent(box,tree); /* get the parent */

   /* show the type menu and get response */

      printf("box is type %d\n",box->probench_box.box_type);
      printf("new type is :\n");
      printf("%d. sequence\n%d. selection\n%d. iteration\n => ",
              SEQUENCE,SELECTION,ITERATION);
      scanf("%d",&num);
      box->probench_box.box_type=num;

    /* if parent was selection or iteration then the box
       needs a condition, assuming it is not the root of 
       course */

    if((parent->probench_box.box_type==SELECTION ||
        parent->probench_box.box_type==ITERATION) &&
        parent != box)
       {
        printf("\nbox has cond number %d\n",box->probench_box.cond_num);
        printf("new cond is => ");
        scanf("%d",&(box->probench_box.cond_num));
       }

    /* if box does not have children then operations may be added */
    if(box->no_children==0)
       {
        printf("\nadd ops ... 0 to stop => ");
      
        scanf("%d",&num);
        opl=box->op;

        while(num!=0)
          {
           if(opl==NULL)    /* if it is the first op */
             {              /* then create and add   */
              box->op=(OPLIST *)create_op();
              opl=box->op;
              opl->op_num=num;
             }
           else             /* otherwise loop through ops */
             {              /* and place it on the end    */
              while(opl->next_op!=NULL)
                 opl=opl->next_op;

              opl->next_op=(OPLIST *)create_op();
              opl=opl->next_op;
              opl->op_num=num;
             }
           printf("=> ");
           scanf("%d",&num);  /* get next */
          }
      }
}

