/* ���Ĺ�����������㷨*/

#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 20
#define null -1

/* typedef int DataType; */
struct  ParTreeNode	{
    /*DataType  info;		 ����е�Ԫ�� */
    int parent;	/* ���ĸ����λ�� */
};

struct ParTree { 
    int n;                 	/* ���н��ĸ��� */
    struct ParTreeNode nodelist[MAXNUM];  	/* ������еĽ�� */
};

typedef struct ParTree *PParTree;		/* �����͵�ָ������ */

int rightSibling_partree(PParTree t, int p) {
    int i;
    if (p >= 0 && p < t->n) {
        for (i = p+1; i <= t->n; i++)
            if (t->nodelist[i].parent == t->nodelist[p].parent)
                return(i);
    }
    return null;
}


/* ���ȸ����д洢ʱ,�������ӽ�������ɼ�����*/
int leftChild_partree(PParTree t, int p) { 
    if (t->nodelist[p+1].parent == p)
        return(p+1);
    else
        return null;
}

typedef int Node;

void visit(Node p) { printf("%d ",p); }

/*����˳���ʾ*/
typedef Node DataType;
struct SeqQueue {	/* ˳��������Ͷ��� */
    int f, r;
    DataType q[MAXNUM];
};

typedef struct SeqQueue *PSeqQueue;	/* ˳��������͵�ָ������ */

/*����һ���ն���*/
PSeqQueue  createEmptyQueue_seq( void ) {  
    PSeqQueue paqu;
    paqu = (PSeqQueue)malloc(sizeof(struct SeqQueue));
    if (paqu == NULL)
        printf("Out of space!! \n");
    else
        paqu->f = paqu->r = 0;
	return paqu;
}

/*�ж����Ƿ�Ϊ�ն���*/
int  isEmptyQueue_seq( PSeqQueue paqu ) {
    return (paqu->f == paqu->r);
}

/* �ڶ����в���һԪ��x */
void  enQueue_seq( PSeqQueue paqu, DataType x ) {
    if( (paqu->r + 1) % MAXNUM == paqu->f  )
        printf( "Full queue.\n" );
    else {
        paqu->q[paqu->r] = x;
        paqu->r = (paqu->r + 1) % MAXNUM;
    }
}

/* ɾ������ͷ��Ԫ�� */
void  deQueue_seq( PSeqQueue paqu ) {
    if( paqu->f == paqu->r )
        printf( "Empty Queue.\n" );
    else
        paqu->f = (paqu->f + 1) % MAXNUM;
}

/* �Էǿն���,�����ͷ��Ԫ�� */
DataType  frontQueue_seq( PSeqQueue paqu ) {
    return paqu->q[paqu->f];
}

void levelOrder(PParTree t) {
    Node c;
    PSeqQueue q;	/* ����Ԫ�ص�����Ϊ Node */
    q = createEmptyQueue_seq();
    
    c = 0; /*c = root(t);*/
    if (c == null)  return;
    enQueue_seq(q,c);
    while (!isEmptyQueue_seq(q)) {
        c = frontQueue_seq(q);
        deQueue_seq(q);
        visit(c);
        c = leftChild_partree(t, c);
        while (c!=null) {
            enQueue_seq(q,c);
            c = rightSibling_partree(t, c);
        }
    }
}

struct ParTree tree = {10, -1,0,1,1,3,3,3,0,7,7};

int main(){
    PParTree t = &tree;
    levelOrder(t);
    putchar('\n');
    return 0;
}

