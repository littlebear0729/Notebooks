/* ���ĳ���-�ֵܱ�ʾ��*/

#include<stdio.h>

typedef int DataType ;
struct  CSNode;   					/* ���н��ṹ */
typedef  struct  CSNode   *PCSNode;	/* ����ָ������ */
struct  CSNode {   					/* ���ṹ���� */
    DataType info;					/* ����е�Ԫ�� */
    PCSNode  lchild;				/* ����������Ů��ָ�� */
    PCSNode  rsibling;				/* �������ֵܵ�ָ�� */
};

typedef  struct CSNode  *CSTree;	/* �����Ͷ��� */
typedef  CSTree   *PCSTree;

PCSNode leftChild_cstree(PCSNode p ) {
    return p->lchild;
}

PCSNode rightSibling_cstree(PCSNode p ) {
    return p->rsibling;
}

PCSNode root_cstree(PCSTree t ) {
    return *t;
}

int isNull_cstree(PCSTree t ) {
    return *t==NULL;
}

int main(){
    return 0;
}
