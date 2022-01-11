/* 线性表的单链表表示*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include "llist.h"
#include "slist.h"

LinkList addB2A_link (LinkList palist, LinkList pblist) {
    PNode pa_end = palist, pb;
    while (pa_end->link != NULL) pa_end = pa_end->link;
    for (pb = pblist->link; pb != NULL; pb = pb->link) {
        if (locate_link(palist, pb->info) == NULL) {
            insertPost_link(palist, pa_end, pb->info);
            pa_end = pa_end->link;
        }
    }
    return palist;
}

LinkList merge_link (LinkList palist, LinkList pblist, LinkList pclist) {
    PNode pa = palist->link, pb = pblist->link, pc = pclist;
    while (pa != NULL || pb != NULL) {
        if (pa == NULL) {
            insertPost_link(pclist, pc, pb->info);
            pc = pc -> link;
            pb = pb -> link;
            continue;
        }
        if (pb == NULL) {
            insertPost_link(pclist, pc, pa->info);
            pc = pc -> link;
            pa = pa -> link;
            continue;
        }
        if (pa->info > pb->info) {
            insertPost_link(pclist, pc, pb->info);
            pc = pc -> link;
            pb = pb -> link;
        }
        if (pa->info < pb->info) {
            insertPost_link(pclist, pc, pa->info);
            pc = pc -> link;
            pa = pa -> link;
        }
        if (pa->info == pb->info) {
            insertPost_link(pclist, pc, pa->info);
            pc = pc -> link;
            pa = pa -> link;
            pb = pb -> link;
        }
    }
    return pclist;
}

int main() {
    LinkList palist, pblist;
    int i;
    DataType x;
    palist = createNullList_link();
    pblist = createNullList_link();
    PNode pa = palist, pb = pblist;
    printf("建立pa线性表,请输入表中数据元素,以-1 结尾:");
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        insertPost_link(palist, pa, x);
        pa = pa->link;
    }
    printflist(palist);

    printf("建立pb线性表,请输入表中数据元素,以-1 结尾:");
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        insertPost_link(pblist, pb, x);
        pb = pb->link;
    }
    printflist(pblist);
/*
    addB2A_link(palist, pblist);

    printflist(palist);*/

    LinkList pclist = createNullList_link();
    merge_link(palist, pblist, pclist);
    printflist(pclist);
    return 0;
}