/* 树的子表表示法*/

#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 20

typedef char DataType;

struct EdgeNode {    /* 子表中结点的结构 */
    int nodeposition;
    struct EdgeNode *link;
};

struct ChiTreeNode {   /* 结点表中结点的结构 */
    DataType info;
    struct EdgeNode *children;
};

struct ChiTree {        /* 树结构 */
    int n;        /* 结点个数 */
    int root;    /* 根结点的下标 */
    struct ChiTreeNode nodelist[MAXNUM];
};

typedef struct ChiTree *PChiTree;        /* 树类型的指针类型 */

typedef struct EdgeNode *PEdgeNode;

int rightSibling_chitree(PChiTree t, int p) {
    int i;
    struct EdgeNode *v;
    for (i = 0; i < t->n; i++) {
        v = t->nodelist[i].children;
        while (v != NULL)
            if (v->nodeposition == p)
                if (v->link == NULL)
                    return -1;
                else
                    return (v->link->nodeposition);
            else
                v = v->link;
    }
    return -1;
}

int parent_chitree(PChiTree t, int p) {
    int i;
    struct EdgeNode *v;
    for (i = 0; i < t->n; i++) {    /* 逐个检查树的各个结点，是不是父结点 */
        v = t->nodelist[i].children;/* 若检查的结点子表中有p，则返回值是该结点的位置 */
        while (v != NULL)
            if (v->nodeposition == p)
                return (i);
            else
                v = v->link;
    }
    return -1;  /* 无父结点，则返回值为-1 */
}

PChiTree createEmptyTree() {
    PChiTree pChiTree = (PChiTree) malloc(sizeof(struct ChiTree));
    if (pChiTree == NULL) {
        printf("Out of space!");
        return NULL;
    } else {
        pChiTree->root = -1;
        pChiTree->n = 0;
    }
    return pChiTree;
}

PChiTree input_tree() {
    char t;
    int tmp;
    PChiTree pChiTree = createEmptyTree();
    printf("input tree: (# to end)\n");
    while (scanf(" %c", &t)) {
        if (t == '#')
            break;
        pChiTree->nodelist[pChiTree->n].info = t;
        pChiTree->n++;
    }
    pChiTree->n--;
    for (int i = 0; i <= pChiTree->n; i++) {
        printf("%d %c\n", i, pChiTree->nodelist[i].info);
    }
    printf("input children tree: (-1 to end)\n");
    for (int i = 0; i <= pChiTree->n; i++) {
        printf("input children tree for node %d, %c: ", i, pChiTree->nodelist[i].info);
        PEdgeNode p, q;
        p = (PEdgeNode) malloc(sizeof(struct EdgeNode));
        pChiTree->nodelist[i].children = p;
        while (scanf(" %d", &tmp)) {
            p->nodeposition = tmp;
            q = (PEdgeNode) malloc(sizeof(struct EdgeNode));
            p->link = q;
            p = p->link;
            if (tmp == -1)
                break;
        }
    }
    for (int i = 0; i <= pChiTree->n; i++) {
        printf("nodelist: %d %c", i, pChiTree->nodelist[i].info);
        PEdgeNode v = pChiTree->nodelist[i].children;
        while (v->nodeposition != -1) {
            printf(" %d", v->nodeposition);
            v = v->link;
        }
        printf("\n");
    }
    return pChiTree;
}

int main() {
    PChiTree t = input_tree();
    int p;
    printf("find parent: ");
    scanf("%d", &p);
    printf("parent: %d\n", parent_chitree(t, p));
    printf("find right sibling: ");
    scanf("%d", &p);
    printf("right sibling: %d\n", rightSibling_chitree(t, p));
    return 0;
}
