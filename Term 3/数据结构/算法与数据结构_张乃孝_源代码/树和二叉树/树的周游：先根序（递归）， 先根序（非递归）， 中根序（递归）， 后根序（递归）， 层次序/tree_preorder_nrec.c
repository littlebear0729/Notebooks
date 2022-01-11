/* �����ȸ����εķǵݹ��㷨*/

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
#define MAXNUM 20       /* ջ�����Ԫ�ظ��� */
struct  SeqStack {      /* ˳��ջ���Ͷ��� */
    DataType  s[MAXNUM];
    int  t; 			/* ָʾջ��λ�� */
};
typedef  struct SeqStack  *PSeqStack;	/* ˳��ջ���͵�ָ������ */ 

/*����һ����ջ;Ϊջ�ṹ����ռ䣬����ջ��������ֵΪ-1*/
PSeqStack  createEmptyStack_seq( void ) {
    PSeqStack pastack;
    pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if (pastack==NULL)
        printf("Out of space!! \n");
    else
        pastack->t = -1;
    return  pastack;
}

/*�ж�pastack��ָ��ջ�Ƿ�Ϊ��ջ��Ϊ��ջʱ����1�����򷵻�0*/
int  isEmptyStack_seq( PSeqStack pastack ) {
    return pastack->t == -1;
}

/* ��ջ��ѹ��һԪ��x */
void  push_seq( PSeqStack pastack, DataType x ) {
    if( pastack->t >= MAXNUM - 1  )
        printf( "Overflow! \n" );
    else {
        pastack->t++;
        pastack->s[pastack->t] = x;
    }
}

/* ɾ��ջ��Ԫ�� */
void  pop_seq( PSeqStack pastack ) {
    if (pastack->t == -1 )
        printf( "Underflow!\n" );
    else
        pastack->t = pastack->t - 1;
}

/* ��pastack��ָ��ջ��Ϊ��ջʱ����ջ��Ԫ�ص�ֵ */
DataType  top_seq( PSeqStack pastack ) {
    return (pastack->s[pastack->t]);
}

struct  ParTreeNode	{
    /*DataType  info;		 ����е�Ԫ�� */
    int parent;	/* ���ĸ����λ�� */
};

#define  MAXNUM   20
#define null -1

struct  ParTree{ 
    int   n;                 	/* ���н��ĸ��� */
    struct ParTreeNode  nodelist[MAXNUM];  	/* ������еĽ�� */
};

typedef struct ParTree  *PParTree;		/* �����͵�ָ������ */

int rightSibling_partree(PParTree t, int p) {
    int i;
    if (p >= 0 && p < t->n) {
        for (i = p+1; i <= t->n; i++)
            if (t->nodelist[i].parent == t->nodelist[p].parent) return i;
    }
    return null;
}

/* ���ȸ����д洢ʱ,�������ӽ�������ɼ�����*/
int leftChild_partree(PParTree t, int p) {
    if (t->nodelist[p+1].parent == p)
        return p + 1;
    else
        return null;
}

typedef int Node;

void visit(Node p) { printf("%d ",p); }

void npreOrder ( PParTree t, Node p ) {
    Node c;
    PSeqStack s;	/* ջԪ�ص������� Node */
    s = createEmptyStack_seq ( );
    
    c = 0; /*c = root ( p );*/
    do {
        while ( c!=null ) {
            visit ( c );
            push_seq( s, c );
            c = leftChild_partree ( t, c );
        }
        while ( c == null && !isEmptyStack_seq(s)) {
            c = rightSibling_partree(t, top_seq(s));
            pop_seq(s);
        }
    } while(c != null);
}

struct  ParTree tree = {10, -1,0,1,1,3,3,3,0,7,7};

int main(){
    npreOrder(&tree, 0);
    putchar('\n');
    return 0;
}


