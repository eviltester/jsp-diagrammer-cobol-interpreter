
/*================================================*
 *                   NODE.C                       *
 *   the functions as used for variable nodes     *
 *================================================*/ 

#include "node.h"
#include "errors.h"

/*==========================================================*
 * create_data_info allocates enough space for the variable *
 * information                                              *
 *==========================================================*/
DATA_INFO *create_data_info()
        {
                DATA_INFO *dip=(DATA_INFO *)malloc(sizeof(DATA_INFO));

                if(dip==NULL)
                        fatal_error("no more room for DATA_INFO");

                dip->name=NULL;
                dip->format=NULL;
                dip->data_c=NULL;
                dip->data_n=0;
                return(dip);
        }

/*=================================================*
 * create_node allocates enough space for the node *
 *=================================================*/
NODE *create_node()
        {
                NODE *ndp=(NODE *)malloc(sizeof(NODE));

                if(ndp==NULL)
                        fatal_error("no more room for NODE");

                PARENT(ndp)=NULL;
                SIBLING(ndp)=NULL;
                CHILD(ndp)=NULL;
                INFO(ndp)=create_data_info();
                LEVEL(ndp)=0;

                return(ndp);
        }

/*==================================================*
 * create_node_list creates space for the node list *
 *==================================================*/
NODE_LIST *create_node_list(NODE *ndp)
        {
                NODE_LIST *ndlp=(NODE_LIST *)malloc(sizeof(NODE_LIST));

                if(ndlp==NULL)
                        fatal_error("no more room for NODE LIST");

                ndlp->node=ndp;
                ndlp->link=NULL;

                return(ndlp);
        }

/*==================================================*
 * extract_link finds a variable in a list of nodes *
 *==================================================*/
NODE_LIST *extract_link(char *name,NODE_LIST *nlp)
        {
                NODE_LIST *nlpoint=nlp;

                while(nlpoint!=NULL)
                        {
                                if(!strcmp(NAME(nlpoint->node),name))
                                        return nlpoint;
                                else
                                        nlpoint=nlpoint->link;
                        }
                return nlpoint;
        }


