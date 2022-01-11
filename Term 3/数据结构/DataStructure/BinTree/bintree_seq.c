/* 二叉树的顺序表示*/
#include <stdlib.h>
#include <stdio.h>

#define  MAXNODE    20
typedef char DataType;
struct SeqBTree {            /* 顺序树类型定义 */
    int n;            /* 改造成完全二叉树后，结点的个数 */
    DataType nodelist[MAXNODE];
};

typedef struct SeqBTree *PSeqBTree;

PSeqBTree createEmptyBTree() {
    PSeqBTree pSeqBTree = (PSeqBTree) malloc(sizeof(struct SeqBTree));
    if (pSeqBTree == NULL) {
        printf("Out of space!\n");
    } else {
        pSeqBTree->n = 0;
    }
    return pSeqBTree;
}

int root_seq(PSeqBTree t) {
    return t->nodelist[0];
}

int parent_seq(PSeqBTree t, int p) {
    return t->nodelist[(p - 1) / 2];
}

int leftChild_seq(PSeqBTree t, int p) {
    return t->nodelist[2 * p + 1];
}

int rightChild_seq(PSeqBTree t, int p) {
    return t->nodelist[2 * (p + 1)];
}

void print_BTree(PSeqBTree pSeqBTree) {
    int i;
    printf("顺序表示的二叉树：");
    for (i = 0; i < pSeqBTree->n; i++) {
        printf("%c ", pSeqBTree->nodelist[i]);
    }
    printf("\n");
}

int main() {
    PSeqBTree pSeqBTree = createEmptyBTree();
    int n, i;
    char t;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        scanf("%c", &t);
        pSeqBTree->nodelist[pSeqBTree->n] = t;
        pSeqBTree->n++;
    }
    print_BTree(pSeqBTree);
    return 0;
}
