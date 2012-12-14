\begin{verbatim}
/*===================================================*
 *               SYMTAB.C                            *
 * functions for the symbol table in the interpreter *
 *===================================================*/
#include "symtab.h"
#include "alfile.h"
#include "alstring.h"
#include "errors.h"

/*=================================================================*
 * create_symtab_entry , allocates enough space for a SYMTAB_ENTRY *
 *=================================================================*/
SYMTAB_ENTRY *create_symtab_entry(NODE_LIST *nlp)
   {
     SYMTAB_ENTRY *sep=(SYMTAB_ENTRY *)malloc(sizeof(SYMTAB_ENTRY));

                if(sep==NULL)
                        fatal_error("NO room for SYMTAB_ENTRY");

                sep->contents=nlp;
                sep->next=NULL;

                return(sep);
   }

/*=================================================================*
 * add node to slot, first of all checks the slot, if null then    *
 * just adds it to the slot, otherwise looks for a list containing *
 * the variable name and adds on to it, if not then it creates a   *
 * new node list                                                   *
 *=================================================================*/  
void add_node_to_sym(NODE *node,int slot,SYMTAB_ENTRY *array[])
   {
     SYMTAB_ENTRY *sep;
     NODE_LIST *nlp;

     if(array[slot]!=NULL)
         {
                                
          if(nlp=extract_link(NAME(node),array[slot]->contents)==NULL)
               {
                 /* couldn't find it*/
                 nlp=array[slot]->contents;

                 while(nlp->link!=NULL)
                    nlp=nlp->link;

                 nlp->link=create_node_list(node);
               }
          else
               {
                 sep=array[slot];
                 while(sep->next!=NULL)
                     sep=sep->next;

                 sep->next=create_symtab_entry(
                                  create_node_list(node));
               }
         }
       else
          array[slot]=create_symtab_entry(create_node_list(node));
 }

/*====================================================*
 * a completely randomly written hash function        *
 * with no thought given to efficient distribution of *
 * variables                                          *
 *====================================================*/
int hash(char *hash_string)
        {

                int len=strlen(hash_string);
                int n=0,loop;

        /* works through string, increasing the value
           of n dependant upon the current value of n
           in relation to loop, and the current character */

                for(loop=0;loop<len;loop++){
                        n+=((n>loop)?n-loop:n+loop)*(hash_string[loop]);
                        }

                if(n<0)n=n*(-1);

                return(n);
        }

/*======================================================*
 *  create_symbol_table_array allocates space for array *
 *======================================================*/
SYMTAB_ENTRY **create_symbol_table_array(int size)
        {
                int loop;
                SYMTAB_ENTRY **stp=(SYMTAB_ENTRY **)
                            malloc(sizeof(SYMTAB_ENTRY *)*size);

                if(stp==NULL)
                        fatal_error("no more room for symbol table ARRAY");

                for(loop=0;loop<size;loop++)
                        stp[loop]=NULL;

                return(stp);
        }

/*===========================================================*
 * a test function used to test the save but left in because *
 * it provides some useful information for debugging         *
 * it works through the array, and every list in the array   *
 * printing off each node                                    *
 *===========================================================*/
void print_nodes(SYMTAB_ENTRY **symtab)
   {
     int slot=0;
     SYMTAB_ENTRY *sep;
     NODE_LIST *nlp;

     for(slot=0;slot<100;slot++)
         {
          sep=symtab[slot];
          if(sep!=NULL)
              {
               while(sep->next!=NULL)
                  {
                   nlp=sep->contents;
                   while(nlp->link!=NULL)
                      {
                        print_node(nlp->node);
                        nlp=nlp->link;
                      }
                   print_node(nlp->node);
                   sep=sep->next;
                  }
              nlp=sep->contents;
              while(nlp->link!=NULL)
                  {
                    print_node(nlp->node);
                    nlp=nlp->link;
                  }
              print_node(nlp->node);
             }
         else printf("printing slot %d is empty --",slot);
         }
     printf("END of NODES\n");
   }

void print_node(NODE *node)
  {
    NODE *np;

    printf("own hash = %d\n",node->own.hash);
    printf("own uniq = %d\n",node->own.unique);
    np=node->parent;
    if(np==NULL)
       {

                printf("\n\nparent hash = 0\n");
                printf("parent uniq = 0\n");
        }
      else{
                printf("\n\nparent hash = %d\n",np->own.hash);
                printf("parent uniq = %d\n",np->own.unique);
        }
      np=node->younger_sibling;
      if(np==NULL)
        {
                printf("sibling hash = 0\n");
                printf("parent uniq = 0\n");
        }
      else{

                printf("sibling hash = %d\n",np->own.hash);
                printf("sibling uniq = %d\n",np->own.unique);
        }
       np=node->eldest_child;
       if(np==NULL)
        {

                printf("child hash = 0\n");
                printf("child uniq = 0\n");
        }
      else{
        
            printf("child hash = %d\n",np->own.hash);
            printf("child uniq = %d\n",np->own.unique);
        }

                printf("level  %d\n",node->level);

                printf("\nDATA INFO\n");
                printf("NAME %s\n",INFO(node)->name);
                printf("TYPE %d\n",INFO(node)->type);
  if(INFO(node)->type==INT)
     printf("integer value is data_n  %d\n",INFO(node)->data_n);
  else{
      if(INFO(node)->type==CHAR)
        {
                  printf("data_c %s\n",INFO(node)->data_c);
                  printf("size data_n %d\n",INFO(node)->data_n);
        }
      }
getchar();
 }

/*=========================================================*
 * save_nodes saves the symbol table to the specified file *
 *=========================================================*/
void save_nodes(SYMTAB_ENTRY **symtab,FILE *outfile)
  {
     int slot=0;
     SYMTAB_ENTRY *sep;
     NODE_LIST *nlp;

        
     for(slot=0;slot<100;slot++) /* loop through slots */
         {
           sep=symtab[slot];
           if(sep!=NULL)       /* if there are entries */
                {
                 while(sep->next!=NULL) /* loop through list */
                   {
                     nlp=sep->contents;
                     while(nlp->link!=NULL) /* loop through list */
                        {
                         save_node(nlp->node,outfile);
                         nlp=nlp->link;
                        }
                     save_node(nlp->node,outfile);
                     sep=sep->next;
                   }
                 nlp=sep->contents;      /* do last list */
                 while(nlp->link!=NULL)
                    {
                     save_node(nlp->node,outfile);
                     nlp=nlp->link;
                    }
                 save_node(nlp->node,outfile);
                 }
                }
            fprintf(outfile,"END of NODES\n");
      }

/*=========================================*
 * save_node writes out a node to the file *
 *=========================================*/
void save_node(NODE *node,FILE *outfile)
        {
                NODE *np;

        /* write header with the hash, and unique number */
        fprintf(outfile,"NODE\N");
                fprintf(outfile,"%d\n",node->own.hash);
                fprintf(outfile,"%d\n",node->own.unique);


        /* for each of the parent, child and sibling
           if none exist then write out null values,
           otherwise write out the hash and unique
           number of the relative */

        np=node->parent;
        if(np==NULL)
          {
                fprintf(outfile,"0\n");
                fprintf(outfile,"0\n");
          }
        else{
                    fprintf(outfile,"%d\n",np->own.hash);
                    fprintf(outfile,"%d\n",np->own.unique);
            }

        np=node->younger_sibling;
        if(np==NULL)
           {
                    fprintf(outfile,"0\n");
                    fprintf(outfile,"0\n");
           }
        else{
                fprintf(outfile,"%d\n",np->own.hash);
                    fprintf(outfile,"%d\n",np->own.unique);
            }

        np=node->eldest_child;
        if(np==NULL)
           {
                    fprintf(outfile,"0\n");
                    fprintf(outfile,"0\n");
           }
        else{
                fprintf(outfile,"%d\n",np->own.hash);
                fprintf(outfile,"%d\n",np->own.unique);
           }

        /* write out the level number */
                fprintf(outfile,"%d\n",node->level);


        /* write out the variable name and type */
                fprintf(outfile,"%s\n",INFO(node)->name);
                fprintf(outfile,"%d\n",INFO(node)->type);

  /* if its an int then write out the contents,
     if its a char then write out the string length 
     followed by the string */

  if(INFO(node)->type==INT)
     fprintf(outfile,"%d\n",INFO(node)->data_n);
  else{
      if(INFO(node)->type==CHAR)
        {
                  fprintf(outfile,"%d\n",INFO(node)->data_n);
                  fprintf(outfile,"%s\n",INFO(node)->data_c);
        }
      }
  }       

/*===================================================*
 * load_symtab loads in a symbol table from filename *
 *===================================================*/
int load_symtab(SYMTAB_ENTRY **sym,char *filename)
{
     FILE *infile=open_input(filename);
     char header[20],g,*cp,name[100];
     NODE *current;
     int loop=0;

 
     fgets(header,20,infile);

     while(header[0]=='N')
       {
        current=create_node();
        fscanf(infile,"%d",&(current->own.hash));
        g=getc(infile);
        fscanf(infile,"%d",&(current->own.unique));
        g=getc(infile);
        fscanf(infile,"%d",&(current->parent_stuff.hash));
        g=getc(infile);
        fscanf(infile,"%d",&(current->parent_stuff.unique));
        g=getc(infile);
        fscanf(infile,"%d",&(current->sibling.hash));
        g=getc(infile);
        fscanf(infile,"%d",&(current->sibling.unique));
        g=getc(infile);
        fscanf(infile,"%d",&(current->child.hash));
        g=getc(infile);
        fscanf(infile,"%d",&(current->child.unique));
        g=getc(infile);
        fscanf(infile,"%d",&(current->level));
        g=getc(infile);
/*data info*/
        /* get name */
        loop=0;
        g=getc(infile);
        while(g!='\n'){
           name[loop]=g;
           g=getc(infile);
           loop++;
          }
        name[loop]='\0';
       current->info->name=(char *)malloc(loop);
        strcpy(current->info->name,name);

       
        fscanf(infile,"%d",&(current->info->type));
        g=getc(infile);

       if(current->info->type==INT)
        {
        fscanf(infile,"%d",&(current->info->data_n));
        g=getc(infile);
        current->info->data_c=NULL;
        }
       else
          {
          if(current->info->type==CHAR)
            {
             fscanf(infile,"%d",&(current->info->data_n));
             g=getc(infile);
             current->info->data_c=(char *)malloc(current->info->data_n + 1);
             if(current->info->data_c==NULL)
               {
                printf("couldn't allocate enough memory for data string\n");
                return(0);
               }
             g=getc(infile);
             cp=current->info->data_c;
             while(g!='\n'){
                *cp=g;
                cp++;
                g=getc(infile);
               }
             *cp='\0';
           }
         }

         add_node_to_sym(current,current->own.hash,sym);
         fgets(header,20,infile);
        }

     close_file(infile);
  return(1);
}

/*====================================================*
 * cross_reference a symbol table loops through       *
 * the table trying to match up parents with children *
 * brothers with sisters and children with parents    *
 *====================================================*/
void cross_reference(SYMTAB_ENTRY **symtab,int size)
{
  NODE *current,*seek;
  NODE_LIST *nlp;
  SYMTAB_ENTRY *sep;
  int slot;
  
  for(slot=0;slot<100;slot++)
          {
           sep=symtab[slot];
           if(sep!=NULL)
              {
               while(sep->next!=NULL)
                  {
                   nlp=sep->contents;
                   while(nlp->link!=NULL)
                      {
                       current=nlp->node;
                       seek=look_for(current->parent_stuff.unique,
                                     current->parent_stuff.hash,
                                     symtab);
                       current->parent=seek;
                       seek=look_for(current->sibling.unique,
                                     current->sibling.hash,
                                     symtab);
                       current->younger_sibling=seek;
                       seek=look_for(current->child.unique,
                                     current->child.hash,
                                     symtab);
                       current->eldest_child=seek;                             
                       nlp=nlp->link;
                      }
                  current=nlp->node;
                  seek=look_for(current->parent_stuff.unique,
                                current->parent_stuff.hash,
                                symtab);
                  current->parent=seek;
                  seek=look_for(current->sibling.unique,
                                current->sibling.hash,
                                symtab);
                  current->younger_sibling=seek;
                  seek=look_for(current->child.unique,
                                current->child.hash,
                                symtab);
                  current->eldest_child=seek;                             
                  nlp=nlp->link;
                  sep=sep->next;
                }
               nlp=sep->contents;
               while(nlp->link!=NULL)
                 {
                  current=nlp->node;
                  seek=look_for(current->parent_stuff.unique,
                                current->parent_stuff.hash,
                                symtab);
                  current->parent=seek;
                  seek=look_for(current->sibling.unique,
                                current->sibling.hash,
                                symtab);
                  current->younger_sibling=seek;
                  seek=look_for(current->child.unique,
                                current->child.hash,
                                symtab);
                  current->eldest_child=seek;                             
                  nlp=nlp->link;
                 }

                 current=nlp->node;
                 seek=look_for(current->parent_stuff.unique,
                               current->parent_stuff.hash,
                               symtab);
                 current->parent=seek;
                 seek=look_for(current->sibling.unique,
                               current->sibling.hash,
                               symtab);
                 current->younger_sibling=seek;
                 seek=look_for(current->child.unique,
                               current->child.hash,
                               symtab);
                 current->eldest_child=seek;                             
               }
         }
}

/*===================================================*
 * look_for seeks through the hash slot for the node *
 * with the unique id number unique                  *
 *===================================================*/
NODE *look_for(int unique,int hash,SYMTAB_ENTRY **symtab)
{
   NODE *np;
   NODE_LIST *nlp;
   SYMTAB_ENTRY *sep; /*contents nodelist pointer, next sep*/

        if(symtab[hash]==NULL) /* the relative may not exist */
       {
        return NULL;
       }

    sep=symtab[hash];

    while(sep->next!=NULL) /* run through the list */
      {
       nlp=sep->contents;
       while(nlp->link!=NULL) /* run through the list */
          {
           np=nlp->node;
           if(np->own.unique==unique) /* have we found it?*/
               return(np);
           nlp=nlp->link;
          }
           np=nlp->node;
           if(np->own.unique==unique) /* found ? */
               return(np);
           sep=sep->next;
      }
       nlp=sep->contents;       /* do the last list */
       while(nlp->link!=NULL)
          {
           np=nlp->node;
           if(np->own.unique==unique)
               return(np);
           nlp=nlp->link;
          }
           np=nlp->node;
           if(np->own.unique==unique)
               return(np);

printf("ERROR 2 in RECROSS\n");
return NULL;
}           

/*=====================================================*
 * look_for_by_name uses the variable name rather than *
 * hash and unique, the name is hashed to find the slot*
 * that must be checked                                *
 *=====================================================*/
NODE *look_for_by_name(char *name,SYMTAB_ENTRY **symtab)
{
   NODE *np;
   NODE_LIST *nlp;/* node , link */
   SYMTAB_ENTRY *sep; /*contents nodelist pointer, next sep*/
   int hash_val;

   hash_val=hash(name)%100;
 
   if(symtab[hash_val]==NULL)
       {
        return NULL;
       }

    sep=symtab[hash_val];

    while(sep->next!=NULL)
      {
       nlp=sep->contents;
       while(nlp->link!=NULL)
          {
           np=nlp->node;
           if(!strcmp(name,np->info->name))
               return(np);
           nlp=nlp->link;
          }
           np=nlp->node;
           if(!strcmp(name,np->info->name))
               return(np);
       sep=sep->next;
      }
       nlp=sep->contents;
       while(nlp->link!=NULL)
          {
           np=nlp->node;
           if(!strcmp(name,np->info->name))
               return(np);
           nlp=nlp->link;
          }
           np=nlp->node;
           if(!strcmp(name,np->info->name))
               return(np);
printf("ERROR 2 in RECROSS\n");
return NULL;
}           
             
/*=======================================================*
 * run through the symbol table, no ordering is achieved *
 * because the very first 01 level has not been saved    *
 * although it is recorded by the symbol table generator *
 *=======================================================*/
void quick_display_symtab(SYMTAB_ENTRY **symtab,int size)
   {
      int slot=0;
      SYMTAB_ENTRY *sep;
      NODE_LIST *nlp;

      for(slot=0;slot<size;slot++)
         {
           sep=symtab[slot];
           if(sep!=NULL)
                {
                 while(sep->next!=NULL)
                    {
                     nlp=sep->contents;
                     while(nlp->link!=NULL)
                        {
                         quick_display_node(nlp->node);
                         nlp=nlp->link;
                        }
                     quick_display_node(nlp->node);
                     sep=sep->next;
                    }
                  nlp=sep->contents;
                  while(nlp->link!=NULL)
                     {
                       quick_display_node(nlp->node);
                       nlp=nlp->link;
                     }
                  quick_display_node(nlp->node);
                 }
              }
         printf("END of SYMBOLTABLE\n");
      }

/*==================================================*
 * display the node level number, name and contents *
 *==================================================*/
void quick_display_node(NODE *node)
        {

                printf("%d   ",node->level);

                printf("- %s ",INFO(node)->name);

        if(INFO(node)->type==INT)
            printf(" =  %d\n",INFO(node)->data_n);
        else{
             if(INFO(node)->type==CHAR)
               {
                printf("data_c %s\n",INFO(node)->data_c);
               }
             else
                printf("\n");
            }
        }


             
/*==========================================================*
 * this is a primitive reset function to allow a trace      *
 * to begin again from the start, it makes all numerics     *
 * 0 and chars '\0', a more sophisticated mechanism would   *
 * be needed for VALUE implementations, so that the current *
 * value and the default value could be stored, then the    *
 * current could be replaced with the default               *
 *==========================================================*/
void reset_symtab(SYMTAB_ENTRY **symtab,int size)
  {
     int slot=0;
     SYMTAB_ENTRY *sep;
     NODE_LIST *nlp;

     for(slot=0;slot<size;slot++)
           {
             sep=symtab[slot];
             if(sep!=NULL)
                {
                 while(sep->next!=NULL)
                   {
                    nlp=sep->contents;
                    while(nlp->link!=NULL)
                        {
                          reset_node(nlp->node);
                          nlp=nlp->link;
                        }
                    reset_node(nlp->node);
                    sep=sep->next;
                   }
                 nlp=sep->contents;
                 while(nlp->link!=NULL)
                    {
                     reset_node(nlp->node);
                     nlp=nlp->link;
                    }
                 reset_node(nlp->node);
                }
            }
       printf("RESET SYMBOLTABLE\n");
    }

void reset_node(NODE *node)
{

  if(INFO(node)->type==INT)
       INFO(node)->data_n=0;
  else{
      if(INFO(node)->type==CHAR)
                  *(INFO(node)->data_c)='\0';
      }
}

\end{verbatim}
