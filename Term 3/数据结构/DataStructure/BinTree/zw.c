/* �����ӱ��ʾ��*/

#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 20

typedef char DataType;

struct EdgeNode {    /* �ӱ��н��Ľṹ */
    int nodeposition;
    struct EdgeNode *link;
};

struct ChiTreeNode {   /* �����н��Ľṹ */
    DataType info;
    struct EdgeNode *children;
};

struct ChiTree {        /* ���ṹ */
    int n;        /* ������ */
    int root;    /* �������±� */
    struct ChiTreeNode nodelist[MAXNUM];
};

typedef struct ChiTree *PChiTree;        /* �����͵�ָ������ */
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
    for (i = 0; i < t->n; i++) {    /* ���������ĸ�����㣬�ǲ��Ǹ���� */
        v = t->nodelist[i].children;/* �����Ľ���ӱ�����p���򷵻�ֵ�Ǹý���λ�� */
        while (v != NULL)
            if (v->nodeposition == p)
                return (i);
            else
                v = v->link;
    }
    return -1;  /* �޸���㣬�򷵻�ֵΪ-1 */
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
        printf("���뺢�ӽڵ��λ��,���û������-1��");
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
        printf("��һ�����");
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

    printf("������һ�����λ�ã����Ҹý����ҽ��");
    scanf("%d", &k);
    k = rightSibling_chitree(p, k);
    printf("�ý����ҽ��λ�ã�%d", k);
    printf("������һ�����λ�ã����Ҹý��ĸ����");
    scanf("%d", &k);
    k = parent_chitree(p, k);
    printf("�ý��ĸ����λ�ã�%d", k);
    return 0;
}