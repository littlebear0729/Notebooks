/* �����������㷨Դ����*/

#include<stdio.h>

struct Node;                    /* ������������ */
typedef int KeyType;
typedef int DataType;

typedef struct Node ListNode;

struct Node {
    KeyType key;            /* �������ֶ� */
    /*DataType info;                ��¼�������ֶ� */
    ListNode *next;              /* ��¼��ָ���ֶ� */
};

typedef ListNode * LinkList;

/* ��������������б�������������е�һ�����Ϊ��ͷ��㡣 */
void listSort(LinkList * plist) {
    ListNode *now, *pre, *p, *q, *head; head=*plist;
    if (head->next == NULL || head->next->next == NULL)
        return;  /* Ϊ�������������ֻ��һ����� */

    pre = head->next; now = pre->next;
    while (now != NULL) {
        q = head; p = head->next;
        while(p != now && p->key <= now->key) {
            q = p;  p = p->next;
        } /* ��ѭ������ʱ���Ѿ��ҵ���now�Ĳ���λ�� */

        if (p == now) {                        /* nowӦ����ԭλ�� */
            pre = pre->next; now = pre->next; continue;
        }

        /* ʹnow��¼��������now��¼���������� */
        pre->next = now->next; q->next = now;
        now->next = p; now = pre->next;
    }
}

ListNode element[9]={
    0, &element[1],
    49, &element[2],
    38, &element[3],
    65, &element[4],
    97, &element[5],
    76, &element[6],
    13, &element[7],
    27, &element[8],
    49, NULL
};

int main(){
    LinkList p = element;
    listSort(&p);
    p = p->next;
    while (p != NULL){
        printf("%d ",p->key);
        p = p->next;
    }
    getchar();
    return 0;
}
