#define TRUE 1
#define FALSE 0
#define SPECIAL -1
typedef int DataType;
struct SeqList {
    int MAXNUM;
    int n;
    DataType *element;
};

typedef struct SeqList SeqList, *PSeqList;

PSeqList createNullList_seq(int m);

int isNullList_seq(PSeqList palist);

int insert_seq(PSeqList palist, int p, DataType x);

int delete_seq(PSeqList palist, int p);

int locate_seq(PSeqList palist, DataType x);

DataType retrieve_seq(PSeqList palist, int p);

PSeqList createNullSeq_String(int m) {
/* 创建新的顺序表 */
    PSeqList palist = (PSeqList) malloc(sizeof(struct SeqList));
    if (palist != NULL) {
        palist->element = (DataType *) malloc(sizeof(DataType) * m);
        if (palist->element) {
            palist->MAXNUM = m;
            palist->n = 0;                    /* 空表长度为0 */
            return (palist);
        } else free(palist);
    }
    printf("Out of space!!\n");        /* 存储分配失败 */
    return NULL;
}

int isNullList_seq(PSeqList palist) {
/*判别palist所指顺序表是否为空表。*/
    return (palist->n == 0);
}

int locate_seq(PSeqList palist, DataType x) {
    int q;
    for (q = 0; q < palist->n; q++) if (palist->element[q] == x) return (q);
    return (-1);
}

int insertPre_seq(PSeqList palist, int p, DataType x) {
    int q;
    if (palist->n >= palist->MAXNUM) {            /* 溢出 */
        printf("Overflow!\n");
        return (0);
    }
    if (isNullList_seq(palist)) {            /*空顺序表插入 */
        palist->element[0] = x;                    /* 插入元素x */
        palist->n = 1;                /* 元素个数为1 */
        return (1);
    }
    if (p < 0 || p > palist->n) {            /* 不存在下标为p的元素 */
        printf("Not exist! \n");
        return (0);
    }
    for (q = palist->n - 1; q >= p; q--)  /* 插入位置及之后的元素均后移一个位置 */
        palist->element[q + 1] = palist->element[q];
    palist->element[p] = x;                    /* 插入元素x */
    palist->n = palist->n + 1;                /* 元素个数加1 */
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
    for (q = p; q < palist->n - 1; q++)    /* 被删除元素之后的元素均前移一个位置 */
        palist->element[q] = palist->element[q + 1];
    palist->n = palist->n - 1;            /* 元素个数减1 */
    return (1);
}

int deleteV_seq(PSeqList palist, int x) {
    // 删除第一个出现的x
    int i, pos = locate_seq(palist, x), n = palist->n;
    for (i = pos; i < n; i++) {
        palist->element[i] = palist->element[i + 1];
    }
    palist->n--;
    return 0;
}

int delete_all_x(PSeqList palist, int x) {
    // 删除所有出现的x
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
