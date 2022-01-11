/* ���Ա��˳���ʾ������ʵ��*/

#define _CRT_SECURE_NO_WARNINGS
/* SeqList.c*/
/*���Ա��˳���ʾ������ʵ��*/

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

PSeqList createNullSeq_String(int m) {
/* �����µ�˳��� */
    PSeqList palist = (PSeqList) malloc(sizeof(struct SeqList));
    if (palist != NULL) {
        palist->element = (DataType *) malloc(sizeof(DataType) * m);
        if (palist->element) {
            palist->MAXNUM = m;
            palist->n = 0;                    /* �ձ���Ϊ0 */
            return (palist);
        } else free(palist);
    }
    printf("Out of space!!\n");        /* �洢����ʧ�� */
    return NULL;
}

int isNullList_seq(PSeqList palist) {
/*�б�palist��ָ˳����Ƿ�Ϊ�ձ�*/
    return (palist->n == 0);
}

int locate_seq(PSeqList palist, DataType x) {
    int q;
    for (q = 0; q < palist->n; q++) if (palist->element[q] == x) return (q);
    return (-1);
}

int insertPre_seq(PSeqList palist, int p, DataType x) {
    int q;
    if (palist->n >= palist->MAXNUM) {            /* ��� */
        printf("Overflow!\n");
        return (0);
    }
    if (isNullList_seq(palist)) {            /*��˳������ */
        palist->element[0] = x;                    /* ����Ԫ��x */
        palist->n = 1;                /* Ԫ�ظ���Ϊ1 */
        return (1);
    }
    if (p < 0 || p > palist->n) {            /* �������±�Ϊp��Ԫ�� */
        printf("Not exist! \n");
        return (0);
    }
    for (q = palist->n - 1; q >= p; q--)  /* ����λ�ü�֮���Ԫ�ؾ�����һ��λ�� */
        palist->element[q + 1] = palist->element[q];
    palist->element[p] = x;                    /* ����Ԫ��x */
    palist->n = palist->n + 1;                /* Ԫ�ظ�����1 */
    return (1);
}

int insertPost_seq(PSeqList palist, int p, DataType x) {
    int q;
    if (palist->n >= palist->MAXNUM) {
        printf("Overflow!\n");
        return 1;
    }
    if (p < 0 || p > palist->n) {
        printf("Not Exist!\n");
        return 1;
    }
    if (isNullList_seq(palist) || p == 0) {
        palist->element[0] = x;
        palist->n = 1;
        return 0;
    }
    for (q = palist->n - 1; q >= p; q--) {
        palist->element[q + 1] = palist->element[q];
    }
    palist->element[p + 1] = x;
    palist->n++;
    return 0;
}

int deleteP_seq(PSeqList palist, int p) {
    int q;
    if (p < 0 || p > palist->n - 1) {
        printf("Not exist!\n ");
        return (0);
    }
    for (q = p; q < palist->n - 1; q++)    /* ��ɾ��Ԫ��֮���Ԫ�ؾ�ǰ��һ��λ�� */
        palist->element[q] = palist->element[q + 1];
    palist->n = palist->n - 1;            /* Ԫ�ظ�����1 */
    return (1);
}

int deleteV_seq(PSeqList palist, int x) {
    // ɾ����һ�����ֵ�x
    int i, pos = locate_seq(palist, x), n = palist->n;
    for (i = pos; i < n; i++) {
        palist->element[i] = palist->element[i + 1];
    }
    palist->n--;
    return 0;
}

int delete_all_x(PSeqList palist, int x) {
    // ɾ�����г��ֵ�x
    /*
    int i, j;
    for (i = 0; i < palist->n; i++) {
        if (palist->element[i] == x) {
            for (j = i; j < palist->n - 1; j++) {
                palist->element[j] = palist->element[j + 1];
            }
            palist->n--;
            i--;
        }
    }
    return 0;
    */
    while (locate_seq(palist, x) != -1) {
        deleteP_seq(palist, locate_seq(palist, x));
    }
    return 0;
}

DataType retrive_seq(PSeqList list, int p) {
    if (p >= 0 && p < list->n)
        return (list->element[p]);
    return (-1);

}

PSeqList reverse_swq(PSeqList list) {
    int i, n = list->n;
    PSeqList ansList = createNullSeq_String(11);
    ansList->MAXNUM = list->MAXNUM;
    ansList->n = list->n;
    for (i = 0; i < n; i++) {
        ansList->element[i] = list->element[n - i - 1];
    }
    return ansList;
}

void print_list(PSeqList llist) {
    int i;
    for (i = 0; i < llist->n; i++)
        printf("%d ", llist->element[i]);
    printf("\n");
}

int find_minV(PSeqList list) {
    int i, n = list->n;
    int min = list->element[0];
    for (i = 1; i < n; i++) {
        if (list->element[i] < min) {
            min = list->element[i];
        }
    }
    return min;
}

int main() {
    PSeqList palist = createNullSeq_String(11);
    DataType x;
    int i, p;
    printf("�������������Ԫ��,��-1 ��β:");
    i = 0;
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        insertPre_seq(palist, i, x);
        i++;
    }
    print_list(palist);
    printf("Input insert position and value:");
    scanf("%d %d", &p, &x);
    insertPost_seq(palist, p, x);
    print_list(palist);
    return 0;
}
