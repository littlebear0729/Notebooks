/* �ֵ�Ķ���������ʵ��,������ʵ���˶����������Ļ����������㷨*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXNUM 100


typedef int KeyType;
typedef int DataType;

typedef struct {
    KeyType key;                    /* �ֵ�Ԫ�صĹؼ����ֶ�     */
    DataType value;                 /* �ֵ�Ԫ�ص������ֶ�    */
} DicElement;

typedef struct {
    int n;                          /* n<=MAXNUM��Ϊ�ֵ���Ԫ�صĸ��� */
    DicElement element[MAXNUM];
} SeqDictionary;

struct BinTreeNode;
typedef struct BinTreeNode * PBinTreeNode;

struct BinTreeNode {
    KeyType key;                    /* ���Ĺؼ����ֶ� */
    DataType value;                 /*    ���������ֶ� */
    PBinTreeNode llink, rlink;      /* ������������ָ�� */
};

typedef struct BinTreeNode * BinTree;
typedef BinTree * PBinTree;

int searchNode(PBinTree ptree, KeyType key, PBinTreeNode *position) {
    PBinTreeNode p = *ptree, q = NULL;
    while (p != NULL) {
        q = p;
        if (p->key == key) {        /* �����ɹ�ʱ���ɲ���positionָ����ҵ��Ľ�� */
            *position=p; return(TRUE);
        }
        else if (p->key > key)      /* ������������������ */
            p = p->llink;
        else p = p->rlink;          /* ������������������ */
    }

    *position=q;
    return FALSE;     /* ����ʧ��ʱ��positionָ��ý��Ӧ����ĸ���� */
}

void insertNode(PBinTree ptree, KeyType key) {
    PBinTreeNode p, position;
    if (searchNode(ptree,key,&position) == TRUE) return; /* �Ѵ��ڹؼ���Ϊkey�Ľ�� */
    
    p = (PBinTreeNode)malloc(sizeof(struct BinTreeNode));/* �����½�� */
    if (p == NULL) {    /* ����ռ���� */
        printf("Out of Space!\n"); 
        return;
    } 
    p->key = key;                        /* ���Զ�p->value�ĸ�ֵ */
    p->llink = p->rlink = NULL;
    if (position == NULL)                 /* ԭ��Ϊ���� */
        *ptree = p;
    else if (key < position->key)
        position->llink = p;             /* ����position�������� */
    else position->rlink = p;            /* ����position�������� */
}

void creatTree(PBinTree ptree, SeqDictionary dic) {
    int i;
    *ptree = (BinTree)malloc(sizeof(struct BinTreeNode));
    if (*ptree == NULL) {
        printf("Out of Space!\n.");
        return;
    }
    (*ptree)->llink = (*ptree)->rlink = NULL;
    (*ptree)->key = dic.element[0].key;
    for(i = 1; i < dic.n; i++)
        insertNode(ptree, dic.element[i].key);      /* ���½��������� */
}

void deleteNode(PBinTree ptree, KeyType key) {
    PBinTreeNode parentp = NULL, p = *ptree, r;
    while (p != NULL) {
        if (p->key == key) break;             /* �ҵ��˹ؼ���Ϊkey�Ľ�� */
        parentp = p;
        if (p->key > key) p = p->llink;        /* ���������� */
        else p = p->rlink;                    /* ���������� */
    }

    if (p == NULL)  return;                   /* �������������޹ؼ���Ϊkey�Ľ�� */

    if (p->llink == NULL) {                   /* ���*p�������� */
        if (parentp == NULL)  
            *ptree = p->rlink;                /* ��ɾ���Ľ����ԭ�����������ĸ����*/
        else if (parentp->llink == p)         /* *p���丸��������Ů */
            parentp->llink = p->rlink;        /* ��*p�������������丸���������� */
        else  parentp->rlink = p->rlink;      /* ��*p�������������丸���������� */
    }
    else {  /* ���*p�������� */
        r = p->llink;
        while (r->rlink != NULL) r = r->rlink;   /* ��*p�����������������½��*r */
        r->rlink = p->rlink;                     /* ��*r����ָ��ָ��*p������Ů */
        if (parentp == NULL) *ptree = p->llink;
        else if (parentp->llink == p)            /* ��*p������Ů����*p */
            parentp->llink = p->llink;
        else parentp->rlink = p->llink;
    }
    free p;                                     /* �ͷű�ɾ����� */
}

int main(){
    return 0;
}

