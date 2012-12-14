
/*=========================================================*
 *                   TSTLOAD.C                             * 
 * this is the testbed program for the diagrammer, it      *
 * creates a tree, starts the graphics environment manager *
 * and calls the parse routine                             *
 *=========================================================*/

#include "alpro.h"

void main()
{
  TREE *tree=create_tree();
  start_gem();
  parse(tree);
  stop_gem();
}


