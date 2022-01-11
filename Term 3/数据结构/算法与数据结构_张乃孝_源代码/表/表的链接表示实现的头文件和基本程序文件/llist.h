/* ���Ա�ĵ������ʾ�����ͺͽ��溯������*/

/* �������ӱ�Ԫ�����͡�Ӧ������Ҫ���� */
typedef int DataType;

struct Node;					  /* ������������ */
typedef  struct Node  *PNode;	  /* ���ָ������ */
typedef  struct Node  *LinkList;  /* ���������� */

struct  Node { 					  /* ��������ṹ */
    DataType  info;
    PNode     link;
};

/* ����һ����ͷ���Ŀ����� */
LinkList createNullList_link( void );

/* ��llist��ͷ���ĵ��������±�Ϊi��(��i+1��)���ǰ����Ԫ��x */
int insert_link(LinkList llist, int i, DataType x);

/* ��llist����ͷ���ĵ�������ɾ����һ��ֵΪx�Ľ�� */
int  delete_link( LinkList llist, DataType x );

/* ��llist����ͷ���ĵ��������ҵ�һ��ֵΪx�Ľ��洢λ�� */
PNode  locate_link(LinkList llist, DataType x );

/* �ڴ���ͷ���ĵ�����llist�����±�Ϊi��(��i+1��)���Ĵ洢λ�� */
/* ���������±�Ϊi��(��i+1��)Ԫ��ʱ������ֵΪNULL */
PNode  find_link( LinkList llist, int i );

/* �ж�llist����ͷ���ĵ������Ƿ��ǿ����� */
int  isNullList_link( LinkList llist);
