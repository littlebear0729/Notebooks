/* �����������ļ����㷨*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXNUM 100

typedef int KeyType;

typedef struct {
    KeyType key;                  /* �ֵ�Ԫ�صĹؼ����ֶ�     */
    /*DataType value;             /* �ֵ�Ԫ�ص������ֶ�    */
} DicElement;

typedef struct {
    int n;                          /* n<=MAXNUM��Ϊ�ֵ���Ԫ�صĸ��� */
    DicElement element[MAXNUM];
} SeqDictionary;

struct BinTreeNode;

typedef struct BinTreeNode BinTreeNode, *PBinTreeNode;

struct BinTreeNode {
    KeyType key;                       /* ���Ĺؼ����ֶ� */
    /*DataType value;                         ���������ֶ� */
    PBinTreeNode llink, rlink;        /* ������������ָ�� */
};

typedef struct BinTreeNode * BinTree;
typedef BinTree * PBinTree;

int searchNode(PBinTree ptree, KeyType key, PBinTreeNode *position) {
    PBinTreeNode p = *ptree, q = NULL;

    while (p != NULL) {
        q = p;
        if(p->key == key) { /* �����ɹ��������positionʹָ֮���ҵ��Ľ�� */
            *position = p; return TRUE;
        }
        else if (p->key > key)      /* ������������������ */
            p = p->llink;
        else p = p->rlink;          /* ������������������ */
    }
    
    *position = q;    /* ����ʧ��ʱ��positionָ��ý��Ӧ����λ�õĸ���� */
    return FALSE; 
}

/* �����½�㣬�޿ռ�ʱ����NULL */
PBinTreeNode newNode(KeyType key) {
    PBinTreeNode p = (PBinTreeNode)malloc(sizeof(BinTreeNode));
    if (p == NULL) {
        printf("Error!\n"); 
        return NULL;
    }     /* ����ռ���� */

    p->key = key;                             /* ���Զ�p->value�ĸ�ֵ */
    p->llink = p->rlink = NULL;
    return p;
}

void insertNode(PBinTree ptree, KeyType key) {
    PBinTreeNode p, position;
    
    if (*ptree == NULL) {
        *ptree = newNode(key);     /* ԭ��Ϊ���� */
        return;
    }

    if (searchNode(ptree, key, &position) == TRUE)
        return;/* �Ѵ��ڹؼ���Ϊkey�Ľ�� */

    p = newNode(key);
    if (key < position->key)
        position->llink = p;                  /* ����position�������� */
    else position->rlink = p;                 /* ����position�������� */
}

void deleteNode(PBinTree ptree, KeyType key) {
    PBinTreeNode parentp = NULL, p = *ptree, r;
    while (p!=NULL) {
        if (p->key == key) break;      /* �ҵ��˹ؼ���Ϊkey�Ľ�� */
        parentp = p;
        if(p->key>key) 
            p = p->llink;              /* ���������� */
        else  p=p->rlink;              /* ���������� */
    }

    if (p == NULL) return;             /* �������������޹ؼ���Ϊkey�Ľ�� */

    if (p->llink == NULL) {            /* ���*p�������� */
        if (parentp == NULL)  
            *ptree = p->rlink;         /* ��ɾ���Ľ����ԭ�����������ĸ����*/
        else if(parentp->llink == p)   /* *p���丸��������Ů */
            parentp->llink = p->rlink; /* ��*p�������������丸���������� */
        else parentp->rlink = p->rlink;/* ��*p�������������丸���������� */
    }
    else {  /* ���*p�������� */
        r = p->llink;
        while(r->rlink != NULL)        /* ��*p�����������������½��*r */ 
            r = r->rlink;
        r->rlink = p->rlink;                   /* ��*r����ָ��ָ��*p������Ů */
        if (parentp == NULL) *ptree = p->llink;
        else if(parentp->llink == p)           /* ��*p������Ů����*p */
            parentp->llink = p->llink;
        else parentp->rlink = p->llink;

    }
    free(p);                                   /* �ͷű�ɾ����� */
}

void creatBinTree (PBinTree ptree, SeqDictionary dic) {
    int i;
    *ptree = NULL; /* ����ٶ���ԭ�������޽�� */
    for(i = 0; i < dic.n; i++)
        insertNode(ptree, dic.element[i].key); /* ���½��������� */
}

/* �ͷ��������������ٶ�treeָ��Ϸ��Ķ����� */ 
void destroyBinTree (BinTree tree) {
    BinTree l, r;
    if (tree == NULL) return;
    l = tree->llink;
    r = tree->rlink;
    free(tree);
    destroyBinTree(l);
    destroyBinTree(r);
}

void printBinTree (BinTree tree) {
    if (tree == NULL) return;
    printBinTree(tree->llink);
    printf("%d ", tree->key);
    printBinTree(tree->rlink);
}

SeqDictionary dic = {11, 
    {18, 10, 73, 5, 68, 99, 27, 25, 41, 32, 51}
};

int main() {
    BinTree tree = NULL;
    creatBinTree(&tree, dic);
	
    while(1){
        int i, key;
        PBinTreeNode position;
        
        printf("Input 1 to insert element\n"
                "2 to search element\n"
                "3 to delete element\n"
                "4 to print (inorder) all element in the tree \n"
                "5 to destroy all element in the tree \n"
                "else to exit\nWhat do you want to do? ");
        scanf("%d", &i);
		
        if (i == 1) {
            printf("Input the key you want to insert: ");
            scanf("%d", &key);
            insertNode(&tree, key);
        }
        else if (i == 2) {
            printf("Input the key you want to search: ");
            scanf("%d", &key);
            if(searchNode(&tree, key, &position) == TRUE)
                printf("It is in the dictionary.\n");
            else printf("It is not in the dictionary!\n");
        }
        else if (i == 3) {
            printf("Input the key you want to delete: ");
            scanf("%d", &key);
            deleteNode(&tree, key);
        }
        else if (i == 4) {
            printBinTree(tree);
            putchar('\n');
        }
        else if (i == 5) {
            destroyBinTree(tree);
            tree = NULL;
            putchar('\n');
        }
        else break;
    }
	
    return 0;
}

