
/* ALSTRING.h a collection of functions to manipulate dynamic strings */
#ifndef ALSTRING
#define ALSTRING

#include <stdio.h>
#include "errors.h"



/* The following define is the increment for string resizing */
#define INCR 10

/* the new structure for dynamic strings */
typedef struct {
                int max_size;           /*size allocated for string*/
                int curr_size;          /*current size */
                char *string_part;      /*pointer to string*/ 
               }DYNAMIC_STRING;        /*new type allows resizing etc*/

/* Function definitions*/
extern DYNAMIC_STRING *create_dynamic_string(void);
extern void append_to_string(char,DYNAMIC_STRING *);
extern void resize_by(DYNAMIC_STRING *,int);
extern void reset_string(DYNAMIC_STRING *);
extern void force_upper(char *);
extern void destroy_dynamic(DYNAMIC_STRING *);
extern char *extract_then(DYNAMIC_STRING *);
#endif

