/* �ֵ��AVL��ʵ��*/


#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;

typedef int DataType;

struct AVLNode;

typedef struct AVLNode * PAVLNode;
typedef struct AVLNode *AVLTree;
typedef AVLTree * PAVLTree;

struct AVLNode {
    KeyType key;                   /* ���Ĺؼ��� */
    DataType value;                /* ����������Ϣ */
    int bf;                        /* ����ƽ������ */
    PAVLNode llink, rlink;         /* �ֱ�ָ�����������Ů */
};


PAVLNode creatNode (KeyType key) {
    PAVLNode node = (PAVLNode)malloc(sizeof(struct AVLNode));
    if (node != NULL) {
        node->key = key; node->bf = 0;
        node->llink = node->rlink = NULL;
    }
    return node;
}

PAVLNode lL(PAVLNode a, PAVLNode  b) {
    a->bf = 0;
    a->llink = b->rlink;
    b->bf = 0;
    b->rlink = a;                    /* bָ�������������ĸ���� */
    return b;
}

PAVLNode rR(PAVLNode a, PAVLNode b) {
    a->bf = 0;  a->rlink = b->llink;
    b->bf = 0;  b->llink = a;
    return b;
}

PAVLNode  lR(PAVLNode a,  PAVLNode b) {
    PAVLNode c = b->rlink; 
    a->llink = c->rlink; b->rlink = c->llink;
    c->llink = b;  c->rlink = a;

    switch (c->bf) {
    case 0:
        a->bf = 0;  b->bf = 0;  break; /* LR(0)�͵��� */
    case 1:
        a->bf = 1;  b->bf = 0;  break; /* �½�����*c���������У�LR(L)�͵��� */
    case -1:
        a->bf = 0;  b->bf = -1; break;/* �½�����*c���������У�LR(R)�͵��� */
    }

    c->bf = 0; 
    return c;
}

PAVLNode  rL(PAVLNode a, PAVLNode b) {
    PAVLNode c = b->llink;
    a->rlink = c->llink;  b->llink = c->rlink;
    c->llink = a;  c->rlink = b;

    switch (c->bf) {  
    case 0:
        a->bf = 0;  b->bf = 0;  break;/* *c������ǲ����㣬RL(0)�͵��� */
    case 1:
        a->bf = 0;  b->bf = 1;  break;/* ����*c���������У�RL(L)�͵��� */
    case -1:
        a->bf = -1;  b->bf = 0;  break;/* ����*c���������У�RL(R)�͵��� */
    }

    c->bf = 0; 
    return c;
}

void avlSearchInsert(PAVLTree ptree, KeyType key) {    
    PAVLNode node_a, node_b, parent_a, p, q, r, node;
    int d;

    if (*ptree == NULL) {              /* ԭ��AVL��Ϊ�� */
        *ptree = creatNode(key);   return;
    }        

    node_a = *ptree;  parent_a = NULL;  p = node_a;  q = NULL;

    while ( p != NULL ) {              /* Ѱ�Ҳ���λ�ü���С��ƽ������ */
        if (key == p->key) return;     /* AVL�����Ѿ��йؼ���Ϊkey�Ľ�� */    
        r = q;  q = p;
        if (key < p->key) p = p->llink;/* ����*p�������� */ 
        else p = p->rlink;             /* ����*p�������� */ 

        if(q->bf != 0) {               /* Ѱ����С��ƽ������*node_a */
            parent_a = r;  node_a = q; 
        }
    }

    node = creatNode(key);
    if (key < q->key) q->llink = node; /* ʹ�½���Ϊ*p������Ů */        
    else q->rlink = node;              /* ʹ�½���Ϊ*p������Ů */ 

    /* �Ѿ����½������뵽AVL���У�node_aָ����С��ƽ�������� */
    if (key < node_a->key)                   /* �½���ǲ���*node_a���������� */
    {   node_b = p = node_a->llink;  d = -1; }
    else                                     /* �½���ǲ���*node_a���������� */
    {   node_b = p = node_a->rlink;  d = 1; }

    /* �޸�*node_b���½��·���ϵĸ�����ƽ�����ӣ�*node_bΪ*node_a����Ů */
    while ( (p != NULL) && (p != node) )
        if(key < p->key) {  p->bf = -1;  p = p->llink;  }/* *p���������߶ȼ�1 */
        else {  p->bf = 1;  p = p->rlink;  }             /* *p���������߶ȼ�1 */

    /* *node_aԭ����ƽ������Ϊ0���������ֻ����Ϊ1��1��û���ƻ���ƽ�� */
    if (node_a->bf == 0) {  node_a->bf = d;  return;  }

    /* �½�����ԭ���߶Ƚ�С�������� */
    if (node_a->bf == -d) {  node_a->bf = 0;  return;  }

    /* �������½�����ԭ���߶Ƚϴ�������У��ƻ���ƽ���ԣ�Ҫ���������е��� */
    if(d == -1)                              /* �½�����*node_a����������*/
        if(node_b->bf == -1) node_b = lL(node_a,node_b); /* LL�͵���*/
        else  node_b = lR(node_a,node_b);                /* LR�͵���*/
    else                                     /* �½�����*node_a����������*/
        if(node_b->bf == 1) node_b = rR(node_a,node_b);  /* RR�͵��� */
        else  node_b=rL(node_a, node_b);                 /* RL �͵��� */

    if(parent_a == NULL)                       /* node_aԭ��ָ�����ĸ���� */
        *ptree = node_b;
    else
        if(parent_a->llink == node_a)  parent_a->llink = node_b;
        else parent_a->rlink = node_b;
}

#define MAXNUM 100
enum {FALSE, TRUE};

typedef struct {
    KeyType key;                /* �ֵ�Ԫ�صĹؼ����ֶ�     */
    DataType value;             /* �ֵ�Ԫ�ص������ֶ�    */
} DicElement;

typedef struct {
    int n;                      /* n<=MAXNUM��Ϊ�ֵ���Ԫ�صĸ��� */
    DicElement element[MAXNUM];
} SeqDictionary;


void creatTree(PAVLTree ptree, SeqDictionary dic) {      
    int i;
	*ptree = creatNode(dic.element[0].key);
    for(i = 1; i < dic.n; i++)
        avlSearchInsert(ptree, dic.element[i].key); /* ���½��������� */
}

int main() {
    return 0;
}
