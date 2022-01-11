/* ���ĺ�����εĵݹ��㷨*/

#include<stdio.h>
#include<stdlib.h>

#define  MAXNUM 20
#define null -1

typedef int DataType; 
struct  ParTreeNode	{
    DataType  info;	//	 ����е�Ԫ�� */
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

///typedef int Node;

void visit(PParTree tree,int p) { printf("%d ",tree->nodelist[p]); }

void preOrder( PParTree t,  int p ) {
    int  c;
    visit( t,p );
    c = leftChild_partree ( t, p );
    while ((c>=0)&&(c<t->n)) {
        preOrder ( t, c );
        c = rightSibling_partree (t, c );
    }
}
void postOrder( PParTree t, int p ) {
    int c;
    c = leftChild_partree (t , p);
    while ((c>=0)&&(c<t->n)) {
        postOrder (t, c);
        c = rightSibling_partree (t, c);
    }
    visit( t,p );
}
struct  ParTree tree = {10, 0,-1,1,0,2,1,3,1,4,3,5,3,6,3,7,0,8,7,9,7 };

int main(){
    PParTree t = &tree;
    preOrder(t, 0);
    putchar('\n'); 
    postOrder(t,0);
    putchar('\n');
	return 0;
}

