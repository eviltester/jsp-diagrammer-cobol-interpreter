
/*======================================================*
 *                 ALPRO.H                              *
 * This header file #includes ALL the files necessary   *
 * for the test diagrammer, and externally declares the *
 * functions acting on the .pr0 file from probench      *
 * these functions unfortunately only work on a PC      *
 *======================================================*/

#ifndef ALPROFILEH
#define ALPROFILEH

#include <stdio.h>
#include "errors.h"
#include "structs.h"
#include "op.h"
#include "box.h"
#include "boxlist.h"
#include "tree.h"
#include "treebox.h"
#include "system.h"
#include "profile.h"
#include "alutil.h"
#include "alfile.h"
/*#include "ops.h"
#include "conds.h"
#include "trace.h"
#include "symtab.h"
*/
extern void load_profile(char *,TREE *);
extern int read_box(FILE *,BOX *);
extern int process_header(char *,struct header_rec *,FILE *);

#endif

