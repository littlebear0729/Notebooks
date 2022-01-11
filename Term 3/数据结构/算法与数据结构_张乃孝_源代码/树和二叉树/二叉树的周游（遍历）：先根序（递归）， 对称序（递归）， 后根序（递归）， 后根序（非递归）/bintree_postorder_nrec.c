/* ������������εķǵݹ��㷨*/

#include<stdlib.h>
#include<stdio.h>

typedef char DataType;

struct BinTreeNode;                         /* �������н�� */
typedef struct BinTreeNode *PBinTreeNode;   /* ����ָ������ */

struct BinTreeNode {
    DataType  info;                         /* ������ */
    PBinTreeNode  llink;                    /* ָ������Ů */
    PBinTreeNode  rlink;                    /* ָ������Ů */
};

typedef struct BinTreeNode *BinTree;
typedef BinTree *PBinTree;
typedef PBinTreeNode BNode;

PBinTreeNode root_btree(PBinTree t) {
    return *t;
}

PBinTreeNode leftChild_btree (PBinTreeNode p){
    return p->llink;
}

PBinTreeNode rightChild_btree (PBinTreeNode p){
    return p->rlink;
}

/*�����㷨�����Ƚ�����������Ϊ����Ķ�������
Ȼ���ȸ��������ε�˳�����������Ϣ,
����һ��˫���洢�Ķ������Ĺ���*/

PBinTreeNode createRest_BTree() {
    /* �ݹ鴴���Ӹ���ʼ�Ķ����� */
    PBinTreeNode  pbnode;
    char ch;
    scanf("%c",&ch);
    if ( ch == '@') pbnode = NULL;
    else {
        pbnode = (PBinTreeNode )malloc(sizeof(struct BinTreeNode));
        if (pbnode == NULL) {
            printf("Out of space!\n");
            return pbnode;
        }
        pbnode->info = ch;
        pbnode->llink = createRest_BTree();	/* ���������� */
        pbnode->rlink = createRest_BTree();	/* ���������� */
    }
    return pbnode;
}


PBinTree  create_BTree( void ) {
    /* ���������Ķ����� */
    PBinTree pbtree = (PBinTree)malloc(sizeof(BinTree));
    if (pbtree != NULL)
        *pbtree = createRest_BTree( );  /* �ݹ鴴���Ӹ���ʼ�Ķ����� */
    return pbtree; 
}

void visit(BNode p) { printf("%c ",p->info); }

typedef struct { 
    BNode ptr;          /* ��ջ��� */
    int   tag;          /* ��� */
} Elem;

/*ջ˳���ʾ*/
#define MAXNUM 20       /* ջ�����Ԫ�ظ��� */
struct  SeqStack {      /* ˳��ջ���Ͷ��� */
    int  t;             /* ָʾջ��λ�� */
    Elem s[MAXNUM];
};

typedef struct SeqStack *PSeqStack;	/* ˳��ջ���͵�ָ������ */ 

/*����һ����ջ;Ϊջ�ṹ����ռ䣬����ջ��������ֵΪ-1*/
PSeqStack  createEmptyStack_seq( void ) {
    PSeqStack pastack;
    pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if (pastack == NULL)
        printf("Out of space!! \n");
    else
        pastack->t = -1;
    return pastack;
}

/*�ж�pastack��ָ��ջ�Ƿ�Ϊ�գ�Ϊ��ջʱ����1�����򷵻�0*/
int isEmptyStack_seq( PSeqStack pastack ) {
    return pastack->t == -1;
}

/* ��ջ��ѹ��һԪ��x */
void push_seq( PSeqStack pastack, Elem x ) {
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
        pastack->t--;
}

/* �ٶ�pastack��ָ��ջ��Ϊ�գ���ջ��Ԫ�ص�ֵ */
Elem  top_seq( PSeqStack pastack ) {
    return (pastack->s[pastack->t]);
}

void nPostOrder(PBinTree t) {
    PSeqStack st;	/* ջ��Ԫ������Ϊ Elem */
    Elem stnode;
    BNode  p;		/* ����ʱ��ǰҪ����Ľ��*/
    char continueflag; /* �����Ƿ������ջ��������������ʱ�������֮���������ջ */
    
    if (*t == NULL) return;
    st = createEmptyStack_seq( ); 	/* ������ջ */
    
    p = *t;                 /* �Ӹ���㿪ʼ */
    do {					/* ÿִ��һ�δ�ѭ������һ����pָ����������ȥ���� */
        while (p != NULL) { /* �����ذ������Ľ���ջ���������������� */
            stnode.ptr = p;
            stnode.tag = 1;
            push_seq(st, stnode);
            p = leftChild_btree(p);
        }
        continueflag = 't';
        while ( continueflag == 't' && !isEmptyStack_seq(st) ) {
            stnode = top_seq(st);
            pop_seq(st);	/* ��ջ */
            p = stnode.ptr;				
            if (stnode.tag == 1) { 
            /* ����Ǵ���������������ı�־���½�ջ��ֹͣ��ջ������������ */
                stnode.tag = 2;
                push_seq(st, stnode);
                continueflag = 'f';
                p = rightChild_btree(p);
            }
            else visit(p);
        }
    } while (!isEmptyStack_seq (st));	/* ջΪ��ʱ��ȫ�������� */
}

int main(){
    PBinTree  tree = create_BTree();
    nPostOrder(tree);
    putchar('\n');
    return 0;
}

