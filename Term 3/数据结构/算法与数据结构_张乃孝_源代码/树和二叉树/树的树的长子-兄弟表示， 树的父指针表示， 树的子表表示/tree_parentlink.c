/* ���ĸ�ָ���ʾ��*/
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20

typedef int DataType;

struct ParTreeNode {
    DataType info;		/* ����е�Ԫ�� */
    int     parent;	/* ���ĸ����λ�� */
};

struct  ParTree { 
    int n;                 	/* ���н��ĸ��� */
    struct ParTreeNode *nodelist;  	/* ������еĽ�� */
};

typedef struct ParTree *PParTree;		/* �����͵�ָ������ */
PParTree create_Null_PParTree(int m)
{
         PParTree ptree=(PParTree)malloc(sizeof(struct ParTree)); 
         ptree->nodelist=(struct ParTreeNode*)malloc(m*sizeof(struct ParTreeNode));
         return ptree;
}

PParTree create_Partree()
{
         struct ParTreeNode parnode;
         int par; int n; int i;
         PParTree ptree= create_Null_PParTree(100);
         printf("����ָ���ʾ���������Ľڵ�ֵ,���ȸ���������,�� @ ��β");
         printf("���ڵ���� n = %d",&n);
         ptree->n=10;
         ptree->nodelist= { 0,-1,1,0,2,1,3,1,4,3,5,3,6,3,7,0,8,7,9,7 };
}
         
                          
         
          
         
int rightSibling_partree(PParTree t, int p) {
    int i;
    if (p >= 0 && p < t->n) {
        for (i = p+1; i <= t->n; i++)
            if (t->nodelist[i].parent == t->nodelist[p].parent)
                return i;
    }
    return -1;
}



/* ���ȸ����д洢ʱ,�������ӽ�������ɼ�����*/
int leftChild_partree(PParTree t, int p) {     
    if (t->nodelist[p+1].parent == p)
        return p+1;
    else
        return -1;
}

int main(){
    PParTree create_Partree();
    return 0;
}
