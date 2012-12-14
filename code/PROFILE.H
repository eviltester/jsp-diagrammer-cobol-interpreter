
/* PROFILE.H - Probench file structure information
** (c) SCM ltd 1992
*/
#ifndef DFERT
#define DFERT
/* box_type values */
#define SEQUENCE    0
#define SELECTION   1
#define ITERATION   2
#define BACK_TRACK  3
#define SUB_TYPE    4
#define LEAF        5

/**/

#define HEADER       1
#define BOX_RECORD   2
#define TRAILER      3
#define OPS_OVERFLOW 4

#define OP_GRP_SIZE   16

#define OPS_LIST    0
#define COND_LIST   1
#define QUIT_LIST   2

/* box comment handling information */
#define COMMENT_LEN(comment)  (*((int *)(comment)))
#define COMM_INFO   sizeof(int)

struct header_rec {
 char rec_type;
 char diag_type;
 char data_flow[26];
 int  invert_count;
 int  box_tot;
 int  file_check_no;
 char const_checked;  /* flag indicating consistency checked */
 char spare[3];
};

struct box_rec{
 char rec_type;
 int  goback_num;
 char box_type;
 char box_name[2][10];
 char cond_type;
 int  cond_num;
 char data_item;
 char struct_indic;
 char page_indic;
 int  ops_depth;
 char op_indic;
 char subtree_no;
 int  comment_size;  /* size in bytes of comment text for box */
 char spare[3];
};

typedef struct box_rec BOX_REC;

struct trailer_rec{
 char rec_type;
 int goback_total;
};

typedef struct trailer_rec TRAILER_REC;

#define PRO_CHECK_NO  20860

struct box_ops{
 char op_type[OP_GRP_SIZE];
 char op_num[OP_GRP_SIZE][3];
 char q_level[OP_GRP_SIZE]; /* quit level 'Q','R'...'Z' */
 int op_count;
 struct box_ops *next_ops;
};

typedef struct box_ops BOX_OPS;

/* end PROFILE.H */

#endif


