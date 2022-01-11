/* ���ĺ�����εĵݹ��㷨*/

#include<stdio.h>

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

void postOrder( PParTree t, Node p ) {
    Node c;
    c = leftChild_partree (t, p);
    while (c != null) {
        postOrder (t, c);
        c = rightSibling_partree (t, c);
    }
    visit( p );
}

struct  ParTree tree={10, -1,0,1,1,3,3,3,0,7,7};

int main(){
    PParTree t = &tree;
    postOrder(t, 0);
    putchar('\n');
    return 0;
}

