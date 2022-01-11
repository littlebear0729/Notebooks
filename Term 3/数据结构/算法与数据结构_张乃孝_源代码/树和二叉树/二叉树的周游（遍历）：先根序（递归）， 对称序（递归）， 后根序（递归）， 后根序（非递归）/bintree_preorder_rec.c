/* ������ǰ�����εĵݹ��㷨*/

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
    scanf(" %c",&ch);
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

void visit(PBinTreeNode p) { printf("%c ",p->info); }

void preOrder(PBinTreeNode p) {
    if (p == NULL) return;
    visit(p);
    preOrder(leftChild_btree(p));
    preOrder(rightChild_btree(p));
}
void postOrder(PBinTreeNode p) {
    if (p == NULL) return;
    
    postOrder(leftChild_btree(p));
    postOrder(rightChild_btree(p));
	visit(p);
}
int num_of_Btree(PBinTreeNode p)
{

  if(p==0) return 0;
  return (1+num_of_Btree(p->llink)+num_of_Btree( p->rlink));



}
int main(){
	PBinTree tree;
	printf("��������������ڵ����ݣ��ȹ��������������Ȼ�����ȸ��������룬��@��ʾ����Ľڵ�\n");
    tree = create_BTree();
    //PBinTreeNode p=*tree;
	printf("�������ȸ��������Ϊ��\t");
    postOrder(*tree);
	printf("�������ڵ����Ϊ Num=%d ");
    putchar('\n');
    return 0;
}

