/* ���Ա��˳���ʾ�����ͺͽ��涨��*/

#define TRUE 1
#define FALSE 0
#define	SPECIAL -1

/* ����˳���Ĵ�С��Ӧ������Ҫ�޸� */
enum { NBASE = 20 };

/* ����˳����Ԫ�����͡�Ӧ������Ҫ�޸� */
typedef int DataType;

struct SeqList {  	
    int n, nmax;			/* ��ǰԪ�ظ��� n���洢����С nmax */
    DataType *elems;	/* ������Ա��е�Ԫ�� */
};

typedef struct SeqList *PSeqList;

/* �����µ�˳��� */
PSeqList createNullList_seq( void );

/* �ж�˳����Ƿ�Ϊ�� */
int isNullList_seq( PSeqList palist );

/*��palist��ָ˳������±�Ϊp��Ԫ��֮ǰ����Ԫ��x*/
int insert_seq(PSeqList palist, int p, DataType x);

/*��palist��ָ˳�����ɾ���±�Ϊ���Ԫ��*/
int  delete_seq( PSeqList palist, int p );

/*��x��palist��ָ˳����е��±�*/
int locate_seq(PSeqList palist, DataType x);

/* ��palist��ָ˳������±�Ϊp��Ԫ��ֵ */
DataType  retrieve_seq( PSeqList palist, int p );
