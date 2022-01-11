/* ��ѭ����������josephus������㷨*/

#include<stdio.h>
#include<stdlib.h>
#iclude <>string.h
#define  FALSE   0
#define  TRUE    1

typedef char DataType[10];
typedef struct Node *PNode;   /* ���ָ������ */

struct  Node {                           /* ��������ṹ */
    DataType info;
    PNode link; 
};

typedef struct Node *LinkList;

/*Ϊ���ݲ������㣬��������PlinkList���ͣ������������͵�ָ������*/
typedef  LinkList *PLinkList;

/* ��1��������nΪ*pclist��ʾ��ѭ�����ʼ�� */
int initlist(PLinkList pclist, int n) {
    int i;
    PNode p, q;
    char name[10];
    q = (PNode)malloc( sizeof( struct Node ) );
    if ( q == NULL ) return FALSE;
    *pclist = q;
    printf("/n�����һ���˵�����");
    scanf("%s",name);
    strcpy(q->info,name); 
    q->link = q;
    printf("/n�������������˵�����");
    for(i = 2; i <= n; i++) {
        scanf("%s",name);
        p = (PNode)malloc(sizeof(struct Node));
        if (p == NULL) return FALSE; /* �˳�ǰӦ���ͷ������ѷ����� */
        strcpy(p->info,name)i;
        p->link = q->link;
        q->link = p;
        q = p;
    }
    return TRUE;
}

void josephus_clink( int n, int s, int m ) {
    LinkList list; 
    PNode p, pre;
    int i;
    
    if (initlist(&list, n) == FALSE) {
        printf("Out of space!\n");
        return;
    }
    
    /* �ҵ�s��Ԫ�أ����ú� pre �� p */
    p = list;
    if (s == 1)
        for (pre = p; pre->link != p; pre = pre->link)
            ;
    else for (i = 1; i < s; i++) {
        pre = p;   p = p->link; 
    }

    while (p != p->link) {              /* �������н���������1ʱ */
        for (i = 1; i < m; i++) {            /* �ҵ�m����� */
            pre = p;  
            p = p->link;
        }
        printf("out element: %s \n", p->info); /* ����ý�� */
        pre->link = p->link;             /* ɾ���ý�� */
        free(p);
        p = pre->link;     
    }

    printf("out element: %d \n", p->info);       /* ������һ����� */
    free(p);
}

void inputnsm(int* np, int* sp, int* mp){
    printf("please input the values of n = ");
    scanf("%d", np);
    printf("please input the values of s = ");
    scanf("%d", sp);
    printf("please input the values of m = ");     
    scanf("%d", mp);
}

int main( ){
    int n, s, m; /* ���������������ֵ */
    
    inputnsm(&n, &s, &m);
    josephus_clink(n, s, m);
    
    getchar(); getchar();
      
    return 0;
}


