/* ջ���ӱ�ʾ�����ͺͽ��溯������ */

typedef int DataType;
struct  Node;					/* �������� */
typedef  struct Node  *PNode;	/* ָ�����ָ������ */

struct  Node {                   /* ��������ṹ */
    DataType info;
    PNode    link;
};

struct LinkStack {               /* ����ջ���Ͷ��� */
    PNode top;		            /* ָ��ջ����� */
};

typedef  struct LinkStack  *PLinkStack;	 /* ����ջ���͵�ָ������ */

/*������ջ�ṹ�ռ䣬����һ������ջ������ָ�������ջ��ָ��*/
PLinkStack  createEmptyStack_link(void);

/*�е�����ʽջ�Ƿ�Ϊ��ջ*/
int  isEmptyStack_link( PLinkStack plstack );

/* ��ջ��ѹ��һԪ��x */
void push_link( PLinkStack plstack, DataType x );

/*��ջ*/
void  pop_link( PLinkStack plstack );

/* �Էǿ�ջ��ջ��Ԫ�� */
DataType  top_link( PLinkStack plstack );

