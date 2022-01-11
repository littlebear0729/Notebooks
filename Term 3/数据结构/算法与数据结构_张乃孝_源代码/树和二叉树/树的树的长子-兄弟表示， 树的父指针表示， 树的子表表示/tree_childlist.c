/* �����ӱ��ʾ��*/

#include<stdio.h>
#define MAXNUM 20

typedef int DataType ;

struct EdgeNode {   	/* �ӱ��н��Ľṹ */
    int             nodeposition;
    struct EdgeNode *link;
};

struct ChiTreeNode {   /* �����н��Ľṹ */
    DataType        info;
    struct EdgeNode *children;
};

struct ChiTree {   		/* ���ṹ */
    int                n; 		/* ������ */
    int                root;	/* �������±� */
    struct ChiTreeNode nodelist[MAXNUM];
};

typedef struct ChiTree *PChiTree;		/* �����͵�ָ������ */

int rightSibling_chitree(PChiTree t, int p) {
    int i;
    struct EdgeNode  *v;
    for (i = 0; i < t->n; i++) {
        v = t->nodelist[i].children;
        while (v != NULL)
            if (v->nodeposition == p)
                if (v->link == NULL)
                    return -1;
                else
                    return(v->link->nodeposition);
            else
                v = v->link;
    }
    return -1;
}

int parent_chitree(PChiTree t, int p) {
    int i;
    struct EdgeNode *v;
    for (i = 0; i < t->n; i++) {    /* ���������ĸ�����㣬�ǲ��Ǹ���� */
        v = t->nodelist[i].children;/* �����Ľ���ӱ�����p���򷵻�ֵ�Ǹý���λ�� */
        while (v!=NULL)
            if (v->nodeposition == p)
                return(i);
            else
                v = v->link;
    }
    return -1;  /* �޸���㣬�򷵻�ֵΪ-1 */
}

int main() {
    return 0;
}
