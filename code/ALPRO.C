
/*=====================================================*
 *               ALPRO.C                               *
 * The following functions load in a .pr0 file from    *
 * probench, the data read is then formed into a tree  * 
 * as used by the test diagrammer. Full details are    *
 * contained below                                     *
 *=====================================================*/

#include "alpro.h"

/*======================================================*
 * load_profile takes a filename and tree as arguments  *
 * the file is opened, then the header processed to     *
 * check that it is a valid probench file.              *
 *                                                      *
 * The root box is then read, the boxes that follow     *
 * are added onto the tree in different ways.           *
 *                                                      * 
 * The goback number is used to find the parent box,    *
 * if the current box is the first child then it is     *
 * created under the parent, but if it is not then it   *
 * is amended onto the list of children                 *
 *======================================================*/
void load_profile(char *filename,TREE *tree)
{
    BOX *boxp,*boxp2;
    int current_box_no;
    struct header_rec diag_header;
    BOXLIST *boxlp;
    FILE *infile=open_input(filename);

    if(!process_header(filename,&diag_header,infile)) /* check header */ 
       exit();

    boxp=tree->root;            /* point to the root box */

    if(!read_box(infile,boxp))  /* load in the details of the root box */
       exit();

    current_box_no=2;
    boxp=create_box();          /* create the next box */

    
    while(read_box(infile,boxp)) /* while there is still a box to read */
       {
         boxp->box_number=current_box_no++; /* assign the box a number,
                                            and increment the number */

         /* find parent ie. the box with 
            number, current - goback    */

         boxp2=find_box(boxp->box_number - 
                        boxp->probench_box.goback_num,
                        tree);

         if(boxp2->children==NULL) /* this is the parents first child */
           {                       /* so add directly under */
            add_under(boxp2,boxp,tree);
            tree->total_boxes++;        /* increment total boxes */
           }
         else{                          /* add after last child */
              boxlp=boxp2->children;    /* get first child */

              while(boxlp->link!=NULL)
                 boxlp=boxlp->link;     /* find last child */

              boxp2=boxlp->box;         /* get last child then */
                                        /* add to the right of */
                                        /* this child */
              add_right(boxp2,boxp,tree);
                  tree->total_boxes++;/* increment total boxes */

                 }
         boxp=create_box();   /* create next box */
      }
    free(boxp);         /* delete spuriously created box */
        close_file(infile); /* close the input file */
}

/*===================================================*
 * Read box reads in the box details from the file,  *
 * It skips any comments and converts the ops arrays *
 * into a linked list as used by the diagrammer      *
 *===================================================*/
int read_box(FILE *infile, BOX *boxp)
{
   short loop,loop2,ops_no;
   char g,als_op_num[4];
   BOX_OPS boxes_ops;
   OPLIST *opl,*lastopl;

   /*read the box, return if it failed */
   if(fread((void *)&(boxp->probench_box),sizeof(BOX_REC),1,infile)!=1)
                return(0);

   /* check that i have read a box */
   if(boxp->probench_box.rec_type != BOX_RECORD)
        return(0); /* oops read the trailer */

   /* skip comment */
   for(loop=0;loop<boxp->probench_box.comment_size;loop++)
          g=getc(infile);


  
   if(boxp->probench_box.op_indic) /* if the box has ops */
     {
      /* read the first set */
      if(fread(&boxes_ops,sizeof(BOX_OPS),1,infile)!=1)
                  fatal_error("error on read ops");

      ops_no=boxes_ops.op_count; /* find out how many there are */

      opl=create_op();                   /* create first list */
      opl->op_type=boxes_ops.op_type[0]; /* set type */

      /* the op numbers on file are stored as 3 characters
         we use an integer so prepare to convert it */      

          for(loop2=0;loop2<3;loop2++)
                  als_op_num[loop2]=boxes_ops.op_num[0][loop2];
          als_op_num[3]='\0';

          opl->op_num=str_to_int(als_op_num); /* convert first op num */

          boxp->op=opl;       /* get ready to do the rest */
          lastopl=opl;        /* set the last op to this one */
          opl=opl->next_op;   

      for(loop=1;loop<OP_GRP_SIZE;loop++) /* loop through array */
        {
          if(loop<ops_no) /* if we still have some to process */
             {
               opl=create_op();            /* create op */
               lastopl->next_op=opl;       /* connect this and 
                                             the last together*/

               /* convert op_num as before */
               opl->op_type=boxes_ops.op_type[loop];
               for(loop2=0;loop2<3;loop2++)
                    als_op_num[loop2]=boxes_ops.op_num[loop][loop2];
               als_op_num[3]='\0';
               opl->op_num=str_to_int(als_op_num);

               /* get ready to do the next op */
               lastopl=opl;        
               opl=opl->next_op;
             }
        }

      ops_no -= OP_GRP_SIZE; /* total is less the number read */

      while(boxes_ops.next_ops!=NULL) /* if there are more */
        {
         if(fread(&boxes_ops,sizeof(BOX_OPS),1,infile)!=1)
            fatal_error("error on read ops");

         for(loop=0;loop<OP_GRP_SIZE;loop++)
           {
            if(loop<ops_no)
              {
               opl=create_op();
               lastopl->next_op=opl;
               opl->op_type=boxes_ops.op_type[loop];
               for(loop2=0;loop2<3;loop2++)
                   als_op_num[loop2]=boxes_ops.op_num[loop][loop2];
               als_op_num[3]='\0';
               opl->op_num=str_to_int(als_op_num);
               lastopl->next_op=opl;
               opl=opl->next_op;
              }
           }

         ops_no -= OP_GRP_SIZE;
        }
       getc(infile);getc(infile);
      }

   return(1);
}

/*===============================================*
 * process header checks that there is a header  *
 * and that it is a valid probench one           *
 *===============================================*/
int process_header(char *filename,
                   struct header_rec *diag_header,
                   FILE *infile)
{ 

   if(fread((void *)diag_header,sizeof(struct header_rec),1,infile)!=1)
       {
        printf("file %s is not a valid profile \n",filename);
        return(0);
       }


   if(diag_header->file_check_no!=PRO_CHECK_NO)
       {
        printf("file %s is not a valid profile \n",filename);
        return(0);
       }

   return(1);
}


