/* �������ԳƸ����εĵݹ��㷨*/

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

void inOrder(BNode p) {
    if (p == NULL) return;
    inOrder(leftChild_btree(p));
    visit(p);
    inOrder(rightChild_btree(p));
}


int main(){
    PBinTree tree = create_BTree();
    inOrder(*tree);
    putchar('\n');
    return 0;
}

