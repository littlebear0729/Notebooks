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

PChiTree Create_NullTree_chitree(void) {
    PChiTree p;
    p = (PChiTree) malloc(sizeof(struct ChiTree));
    if (p == NULL)
        printf("Out of space \n");
    else {
        p->n = 0;
        p->root = -1;
    }
    return p;
}

int isNull_chitree(PChiTree p) {
    return p->n == 0;
}

PChiTree insert_chitree(PChiTree p, char a) {
    PEdgeNode v;

    int k = 0;
    p->nodelist[p->n].info = a;
    p->nodelist[p->n].children = (PEdgeNode) malloc(sizeof (struct EdgeNode));
    v = p->nodelist[p->n].children;
    do {
        printf("输入孩子节点的位置,如果没有输入-1：");
        scanf("%d", &k);
        if (k == -1)
            break;
        v->nodeposition = k;
        v->link = (PEdgeNode) malloc(sizeof(struct EdgeNode));;
        v = v->link;
    } while (k != -1);
    p->n++;
    return p;
}

PChiTree create_chitree(PChiTree p) {
    char a;
    scanf("%c", &a);
    p->root = a;
    while (a <= 'z' && a >= 'a') {
        insert_chitree(p, a);
        printf("下一个结点");
        scanf(" %c", &a);
    }
    return p;
}

int main() {
    int k;
    PChiTree p;
    p = Create_NullTree_chitree();
//    isNull_chitree(p);
    p = create_chitree(p);

/*
    printf("%c %d\n", p->root, p->root);

    for (int i = 0; i < p->n; i++) {
        printf("%d %c", i, p->nodelist[i].info);
        PEdgeNode v;
        v = p->nodelist[i].children;
        while (v->link != NULL) {
            printf(" %d", v->nodeposition);
            v = v->link;
        }
        printf("\n");
    }
*/

    printf("请输入一个结点位置，来找该结点的右结点");
    scanf("%d", &k);
    k = rightSibling_chitree(p, k);
    printf("该结点的右结点位置：%d", k);
    printf("请输入一个结点位置，来找该结点的父结点");
    scanf("%d", &k);
    k = parent_chitree(p, k);
    printf("该结点的父结点位置：%d", k);
    return 0;
}