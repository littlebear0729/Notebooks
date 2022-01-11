/*�������ӱ�ʾ�����ͺͽ��溯������*/

typedef int DataType;
struct  Node;
typedef  struct Node *PNode;

struct  Node { 		/* ���ṹ */
    DataType    info;
    PNode       link;
};

struct  LinkQueue {	/* ���Ӷ������Ͷ��� */	
    PNode  f;  		/* ͷָ�� */
    PNode  r;  		/* βָ�� */
};

typedef struct LinkQueue *PLinkQueue;

/*����һ���ն���*/
PLinkQueue  createEmptyQueue_link( );

/*�ж����ӱ�ʾ�����Ƿ�Ϊ�ն���*/ 
int  isEmptyQueue_link( PLinkQueue plqu );

/*������*/
void  enQueue_link( PLinkQueue plqu, DataType x);

/*������*/
void  deQueue_link( PLinkQueue plqu );

/* �ڷǿն��������ͷԪ�� */
DataType  frontQueue_link( PLinkQueue plqu );

