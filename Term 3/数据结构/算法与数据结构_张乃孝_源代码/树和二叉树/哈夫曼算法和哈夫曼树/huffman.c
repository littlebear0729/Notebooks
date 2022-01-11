/* huffman���Ĺ��췽��*/

#include<stdlib.h>
#include<stdio.h>
#define  MAXINT    2147483647
#define  MAXNUM   50	/* ����w��������ɵ�Ԫ�ظ�����ע�� m<=MAXNUM */
#define  MAXNODE  100	/* ���������е����������ע�� 2*m-1<MAXNODE */

struct HtNode {        /* �����������Ľṹ */
    int ww;
    int parent,llink,rlink;
};

struct HtTree {
    int    root;/* �����������������е��±�*/
    struct HtNode  ht[MAXNODE];
};

typedef struct HtTree  *PHtTree; /* �����������͵�ָ������ */

/* �������m��Ҷ���Ĺ�������*/
PHtTree huffman(int m, int *w) { 
    PHtTree  pht;
    int i, j, x1, x2, m1, m2;
    pht = (PHtTree)malloc(sizeof(struct HtTree));  /* �����չ������� */
    if (pht == NULL) {
        printf("Out of space!! \n");
        return pht;
    }
    for (i = 0; i < 2*m-1; i++) {/* �ó�̬ */
        pht->ht[i].llink = -1;
        pht->ht[i].rlink = -1;
        pht->ht[i].parent = -1;
        if (i < m)
            pht->ht[i].ww = w[i];
        else
            pht->ht[i].ww = -1;
    }
    for ( i = 0; i < m-1; i++)	{/* ÿѭ��һ�ι���һ���ڲ���� */
        m1 = MAXINT;
        m2 = MAXINT;/* ��ر�������ֵ */
        x1 = -1;
        x2 = -1;
        for (j = 0; j < m+i; j++)		/* ��������СȨ���޸����Ľ�� */
            if (pht->ht[j].ww < m1 && pht->ht[j].parent == -1) {
                m2 = m1;
                x2 = x1;
                m1 = pht->ht[j].ww;
                x1 = j;
            }
            else if (pht->ht[j].ww < m2 && pht->ht[j].parent == -1) {
                m2 = pht->ht[j].ww;
                x2 = j;
            }

        pht->ht[x1].parent = m+i;	/* ����һ���ڲ���� */
        pht->ht[x2].parent = m+i;
        pht->ht[m+i].ww = m1+m2; 
        pht->ht[m+i].llink = x1; 
        pht->ht[m+i].rlink = x2;
        pht->root = m+i;
    } 
    return pht;
}

int main() {
    int m = 0, j = 0, i = 0, parent = 0;
    int* w;
    PHtTree pht;
    printf("please input m = ");/*�����ⲿ������*/
    scanf("%d", &m);
    if (m < 1) {
        printf("m is not reasonable!\n");
        return 1;
    }
    w = (int *)malloc(sizeof(int)*m);
    if (w == NULL) {
        printf("overflow!\n");
        return 1;
    }
    printf("please input the %d numbers��\n",m);/*����Ȩֵ*/
    for (j = 0; j < m; j++)
        scanf("%d", w+j);
    pht = huffman(m, w);
    for (j = 0; j < m; j++) {
        printf("the Reverse code of the %d node is:", j+1);/*�õ��ı���Ӧ������*/
        i = j;
        while (pht->ht[i].parent != -1) {
            parent = pht->ht[i].parent;
            if (pht->ht[parent].llink == i)
                printf("0");
            else
                printf("1");
            i = parent;
        }
        printf("\n");
    }
    return 0;
}


