/*=====================================*
 *        TREEBOX.C                    *
 * contains all tree and box functions *
 *=====================================*/

#include "treebox.h"

#define BOX_DOES_NOT_EXIST(B)		(tree->total_boxes<B || B<0)
/********
*********       FUNCTIONS
*********/

/*======================================================*
 * find_box initiates a call to the recursive find with *
 * the root box as the first box to check               *
 *======================================================*/
BOX *find_box(box_num,tree)
        int box_num;TREE *tree;
{

 		  if(BOX_DOES_NOT_EXIST(box_num))
        	{
             error("box does not exist");
             return NULL;
            }

        return (BOX *)find(box_num,tree->root);
}


BOX *find(box_num,root)
        int box_num;BOX *root;
{

        BOX		*boxpointer=root;
        BOX     *returned=NULL;
		int stopped=0;
		int direction=1;  /*1 down 0 up*/

        if(root->box_number==box_num)
                        return root;
        else
           if(root->no_children==0)
                    return NULL;
           else
             {
                  
             do{
             	if(direction==1  && boxpointer->children)
             		boxpointer=boxpointer->children;
             	else
             		{
                		if(boxpointer->box_number==box_num)
                			{
                				stopped=1;
                				returned = boxpointer;
                			}
                		else
                			{
                				if(boxpointer->box_number==1)
              			  			stopped=1;
          			      		else
            		    			{
                					if(boxpointer->right_sibling!=NULL)
                						{
                							direction=1;
                							boxpointer=boxpointer->right_sibling;
                						}
                					else
            		    				{
               			 					direction=0;
                							boxpointer=boxpointer->parent;
                						}
                					}
							}

                	}
                }while(!stopped);
             }
              
		return returned;
		      	

}

/*=========================================================*
 * renumber_from initiates the recursive renumber function *
 *=========================================================*/
void renumber_from(TREE *tree)
{

        int dummy;
/*printf("renumber from\n");*/
        dummy=renumber(tree->root,0);
}


int renumber(start,number)
			BOX *start; int number;
{
        BOX		*boxpointer=start;
		int stopped=0;
		int direction=1;  /*1 down 0 up*/
		int count=number;

        do{
          	if(direction==1  && boxpointer->children)
          		{
          			count++;
          			boxpointer->box_number=count;
          			boxpointer=boxpointer->children;
          		}
           	else
          		{
          		if(direction==1)
          			{
          	 		count++;
           			boxpointer->box_number=count;
           			}
           			
           			if(boxpointer->box_number==1)
       			  		stopped=1;
   			      	else
       		    		{
           				if(boxpointer->right_sibling!=NULL)
           					{
           						direction=1;
           						boxpointer=boxpointer->right_sibling;
           					}
           				else
       		    			{
       			 				direction=0;
           						boxpointer=boxpointer->parent;
           					}
           				}
					

              	}
          }while(!stopped);
             
		return count;
}




/*==============================================================*
 * this function creates a new box under another, increases the *
 * total number of boxes, and renumbers the tree                *
 *==============================================================*/
int create_under(box_num,tree)
                int box_num;TREE *tree;
{
	if(!BOX_DOES_NOT_EXIST(box_num))
		{
        add_under(find_box(box_num,tree),create_box(),tree);
        tree->total_boxes++;
        renumber_from(tree);
        return 1;
        }
     else
     	{
     	error("box does not exist");
     	return 0;
     	}

}

/*================================================================*
 * add under gives the parent ops to the child, assuming the      *
 * child has none, the parent's children pointer is given to this *
 * child box and the child is added to the parent's children      *
 *================================================================*/
void add_under(BOX *parent,BOX *child,TREE *tree)
        {
                child->box_type=1;
                child->no_children=parent->no_children;

                if(child->op==NULL)
                     child->op=parent->op;

                child->children=parent->children;
                
                parent->op=NULL;

				parent->children=child;
                parent->no_children=1;
                
                child->parent=parent;
                child->left_sibling=NULL;
                child->right_sibling=NULL;
        }



/*================================================================*
 * get_parent returns the parent								  *
 *================================================================*/
BOX *get_parent(target,tree)
                BOX *target;TREE *tree;
{
		/*	simplified because a parent pointer is held with 
			each box, if the box is not NULL, then simply
			access the parent address, thus... 					*/
			
			if(target)
				{
					if(target->box_number==1)
						return(target);
					else
						return(target->parent);
				}
			else
					return(NULL);
						 
}


/*================================================================*
 * initates a call to add right provided we are not adding to the *
 * right of the root box                                          *
 *================================================================*/
int create_right(box_num,tree)
                int box_num;TREE *tree;
{
                if(box_num==1)
                	{
                        error("cannot add right of root box");
                        return 0;
                    }
                else
                  {
                	if(BOX_DOES_NOT_EXIST(box_num))
                		{
                		error("box does not exist");
                		return 0;
                		}
                	else
                		{
                  
                 		   	 add_right(	find_box(box_num,tree),
                 		   	 			create_box(),
                 		   	 			tree);
                  			 tree->total_boxes++;
               			     renumber_from(tree);
               			     return 1;
						}
                  }
}

/*=======================================================*
 * add right first finds the position in the list of the *
 * box we are trying to add to the right of, we then add *
 * the box to the list at this position + 1              *
 *=======================================================*/
void add_right(lefty,righty,tree)
                BOX *lefty,*righty;TREE *tree;
{



		BOX *parent=get_parent(lefty,tree);
		BOX *temp;
	
        parent->no_children++;
        	
        righty->parent=parent;
        righty->left_sibling=lefty;
        righty->right_sibling=lefty->right_sibling;
        
        temp=lefty->right_sibling;
        if(temp)
        	temp->left_sibling=righty;
        	
        lefty->right_sibling=righty;
}

/*================================================================*
 * initates a call to add left provided we are not adding to the  *
 * left of the root box                                           *
 *================================================================*/
int create_left(box_num,tree)
                int box_num;TREE *tree;
{

                if(box_num==1)
                	{
                        error("cannot add left of root box");
                        return 0;
                    }
                else
                  {
                  	if(BOX_DOES_NOT_EXIST(box_num))
                  		{
                  		error("box does not exist");
                  		return 0;
                  		}
                  	else
                  		{
                        add_left(	create_box(),
                        			find_box(box_num,tree),
                        			tree);
                        tree->total_boxes++;
                        renumber_from(tree);
                        return 1;
						}
                   }
}

/*======================================================*
 * add left first finds the position in the list of the *
 * box we are trying to add to the left of, we then add *
 * the box to the list at this position.                *
 * add_at is not destructive and inserts the box        *
 *======================================================*/
void add_left(lefty,righty,tree)
                BOX *lefty,*righty;TREE *tree;
{
        BOX *parent=get_parent(righty,tree);
		BOX *temp;
		
        parent->no_children++;

        lefty->parent=parent;
        lefty->left_sibling=righty->left_sibling;
        lefty->right_sibling=righty;

		temp=righty->left_sibling;
		if(temp)
			temp->right_sibling=lefty;
		else
			parent->children=lefty;
			        
        righty->left_sibling=lefty;

}

/*===========================================================*
 * initates a call to add above provided we are not adding   *
 * above the root box                                        *
 *===========================================================*/
int create_above(box_num,tree)
                int box_num;TREE *tree;
{
        if(box_num==1)
        	{
             error("cannot add above root box");
             return 0;
            }
        else
          {
          	if(BOX_DOES_NOT_EXIST(box_num))
          		{
          		error("box does not exist");
          		return 0;
          		}
          	else
          		{
           			add_above(create_box(),
           					  find_box(box_num,tree),
           					  tree);
           			tree->total_boxes++;
           			renumber_from(tree);
           			return 1;
           		}
          }
}

/*===============================================================*
 * add_above adds the lower box to the upper box's children list *
 * then the parent box of the lower box has the new box as a     *
 * child.                                                        *
 * effectively a box is added vertically between two boxes       *
 *===============================================================*/
void add_above(BOX *upy,BOX *downy,TREE *tree)
        {
                BOX *parent=get_parent(downy,tree);
				BOX *temp;         
                

  				upy->children=downy;
  				upy->no_children=1;
  				
  				upy->left_sibling=downy->left_sibling;
  				upy->right_sibling=downy->right_sibling;
  				          
  				temp=downy->left_sibling;
  				if(temp)
  					temp->right_sibling=upy;
  					
  				temp=downy->right_sibling;
  				if(temp)
  					temp->left_sibling=upy;      
  				                                     
                downy->parent=upy;
                downy->left_sibling=NULL;
                downy->right_sibling=NULL;
                
                upy->parent=parent;
                
                if(parent->children==downy)
                	parent->children=upy;
        }


/*==========================================================*
 * delete calls the delete box function provided we are not *
 * trying to delete the root box                            *
 *==========================================================*/
void delete(box_num,tree)
                int box_num;TREE *tree;
{
        if(box_num==1)
                error("cannot delete root box");
        else
        	{
        	if(BOX_DOES_NOT_EXIST(box_num))
        		error("the box does not exist");
        	else
        		{
                delbox(find_box(box_num,tree),tree);
                renumber_from(tree);
				}
			}
}

/*===========================================================*
 * delbox uses the boxlist's delete function to remove a box *
 * from the list of children, if the box to be deleted has   *
 * children then these are inserted to the parents children  *
 * list at the same position of the deleted box              *
 *===========================================================*/
void delbox(BOX *box,TREE *tree)
        {
                BOX *parent=get_parent(box,tree);
                BOX *temp,*temp2;

 
 				if(box->children==NULL)
 					{
 		
 					temp=box->left_sibling;
 					if(temp)
 						temp->right_sibling=box->right_sibling;
 					temp=box->right_sibling;
 					if(temp)
 						temp->left_sibling=box->left_sibling;
 					
 					temp=box->parent;
 					if(temp->children==box)
 						temp->children=(box->left_sibling) ? box->left_sibling : box->right_sibling;
 		
 					parent->no_children--;
 					tree->total_boxes--;
					}
				else
					{
		
					temp=box->left_sibling;
					if(temp)
						temp->right_sibling=box->children;
					else
						parent->children=box->children;

						
					temp=box->children;
					
					if(temp)
						{
							while(temp->right_sibling!=NULL)
								{
									temp->parent=parent;
									temp=temp->right_sibling;
									parent->no_children++;
								}
							temp->parent=parent;
						
					
							temp2=box->right_sibling;
							if(temp2)
								temp2->left_sibling=temp;
								
							temp->right_sibling=box->right_sibling;
							tree->total_boxes--;
						}
					}
					
		
				scrub_box(box);
		
        }


void delete_range(int start, int finish, TREE *tree)
	{
		int loop;
		
		if(start>finish)
			{
				loop=start;
				start=finish;
				finish=loop;
			}
			
		for(loop=start;loop<=finish;loop++)
  			{
        	if(BOX_DOES_NOT_EXIST(loop))
        		error("the box does not exist");
        	else
				delbox2(find_box(loop,tree),tree);
			}
				
		tree->total_boxes-=((finish-start)+1);		
		renumber_from(tree);
	}
                                         

void delbox2(BOX *box,TREE *tree)
        {
                BOX *parent=get_parent(box,tree);
                BOX *temp,*temp2;

 
 				if(box->children==NULL)
 					{
 		
 					temp=box->left_sibling;
 					if(temp)
 						temp->right_sibling=box->right_sibling;
 					temp=box->right_sibling;
 					if(temp)
 						temp->left_sibling=box->left_sibling;
 					
 					temp=box->parent;
 					if(temp->children==box)
 						temp->children=(box->left_sibling) ? box->left_sibling : box->right_sibling;
 		
 					parent->no_children--;
 					/*tree->total_boxes--;*/
					}
				else
					{
		
					temp=box->left_sibling;
					if(temp)
						temp->right_sibling=box->children;
					else
						parent->children=box->children;

						
					temp=box->children;
					
					if(temp)
						{
							while(temp->right_sibling!=NULL)
								{
									temp->parent=parent;
									temp=temp->right_sibling;
									parent->no_children++;
								}
							temp->parent=parent;
						
					
							temp2=box->right_sibling;
							if(temp2)
								temp2->left_sibling=temp;
								
							temp->right_sibling=box->right_sibling;
							/*tree->total_boxes--;*/
						}
					}
					
		
				scrub_box(box);
		
        }
