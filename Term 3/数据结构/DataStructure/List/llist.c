/* ���Ա�ĵ������ʾ*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include "llist.h"
#include "slist.h"

int main() {
    LinkList list;
    int i;
    DataType x;
    list = createNullList_link();
    PNode p = list;
    printf("�������Ա�,�������������Ԫ��,��-1 ��β:");
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        insertPost_link(list, p, x);
        p = p->link;
    }
    printflist(list);

    /*
    printf("Insert (value) before (position): ");
    int pos, val;
    scanf("%d %d", &val, &pos);
    p = list->link;
    i = 0;
    while (p != NULL) {
        //printf("val:%d i:%d\n", p->info, i);
        if (i == pos) {
            insertPre_link(list, p, val);
        }
        p = p->link;
        i++;
    }
    printflist(list);
    */

    /*
    printf("Delete (position): ");
    int pos;
    scanf("%d", &pos);
    p = list->link;
    i = 0;
    while (p != NULL) {
        if (i == pos) {
            deleteP_link(list, p);
        }
        p = p->link;
        i++;
    }
    printflist(list);
    */

    /*
    printf("Delete (position): ");
    int pos;
    scanf("%d", &pos);
    p = list;
    i = 0;
    if (pos == 0) {
        list->link = p->link->link;
    } else {
        p = list->link;
        while (p != NULL) {
            if (i == pos) {
                deleteP_link(list, p);
            }
            p = p->link;
            i++;
        }
    }
    printflist(list);
     */

    /*
    //˳���
    int pos;
    PSeqList palist = createNullSeq_String(11);
    printf("�������������Ԫ��,��-1 ��β:");
    i = 0;
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        insertPre_seq(palist, i, x);
        i++;
    }
    print_list(palist);
    //ɾǰ��
    printf("Input delete (position) before it: ");
    scanf("%d", &pos);
    deleteP_seq(palist, pos - 1);
    print_list(palist);
    //ɾ���
    printf("Input delete (position) after it: ");
    scanf("%d", &pos);
    deleteP_seq(palist, pos + 1);
    print_list(palist);

    //������
    //ɾǰ��
    printf("Delete (position) before it: ");
    scanf("%d", &pos);
    p = list->link;
    i = 0;
    while (p != NULL) {
        if (i == pos) {
            deleteP_link(list, locatePre_link(list, p));
        }
        p = p->link;
        i++;
    }
    printflist(list);
    //ɾ���
    printf("Delete (position) after it: ");
    scanf("%d", &pos);
    p = list->link;
    i = 0;
    while (p != NULL) {
        if (i == pos) {
            deleteP_link(list, p->link);
        }
        p = p->link;
        i++;
    }
    printflist(list);
    */

    //�ⷨһ
    int appeared[10000] = {};
    p = list->link;
    while (p != NULL) {
        if (appeared[p->info] == 0) {
            appeared[p->info]++;
        } else {
            PNode pre_pos = locatePre_link(list, p);
            pre_pos->link = p->link;
        }
        p = p->link;
    }
    printflist(list);

    //�ⷨ��
    printf("\n");
    PNode p1 = list->link, p2 = list->link->link;
    while (p1->link != NULL) {
        while (p2 != NULL) {
            if (p1->info == p2->info) {
                PNode pre_pos = locatePre_link(list, p2);
                pre_pos->link = p2->link;
            }
            p2 = p2->link;
        }
        p1 = p1->link;
        p2 = p1->link;
    }
    printflist(list);
    return 0;
}