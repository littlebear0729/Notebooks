/* ���ڽӱ��ʾͼ�����������㷨*/


#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
#define TRUE 1
#define FALSE 0

typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode * PEdgeNode;
typedef struct EdgeNode * EdgeList;

struct EdgeNode {
    int endvex;			/* ���ڶ����ֶ� */
    PEdgeNode nextedge;	/* ���ֶ� */
};					/* �߱��еĽ�� */

typedef struct {
    /*VexType vertex;*/		/* ������Ϣ */
    EdgeList edgelist;		/* �߱�ͷָ�� */
} VexNode;				/* ������еĽ�� */

typedef struct{
    int n;				/* ͼ�Ķ������ */
    VexNode vexs[MAXVEX];
} GraphList;

typedef struct {
    int vexsno[MAXVEX];		/* �����ڶ�����е��±�ֵ */
    /*VexType vexs[MAXVEX];*/	/* ������Ϣ */	
} Topo;

/* ���ͼ�����ж������� */
/* ���������������ڽӱ� */
void findInDegree(GraphList* g, int *inDegree){
    int i; PEdgeNode p;        
    for (i = 0; i < g->n; i++)
        inDegree[i] = 0;
    for (i = 0; i < g->n; i++){
        p = g->vexs[i].edgelist;
        while (p) {
            ++inDegree[p->endvex];
            p = p->nextedge;
        }
    }
}

void makeNewAOV(EdgeList p, int* indegree, int* top) {
    int k;
    while (p) {                        /* ɾ���Ըö���Ϊ���ı� */
        k = p->endvex; 
        indegree[k]--;
        if (indegree[k] == 0) {        /* ���µ����Ϊ��ı���ջ */
            indegree[k] = *top;
            *top = k; 
        }
        p = p->nextedge;
    }
}

int topoSort(GraphList * paov, Topo * ptopo) {
    EdgeList p;
    int i, j, nodeno = 0, top = -1;
    int indegree[MAXVEX];
    findInDegree(paov, indegree); /* ���ͼ�����ж������� */
    for (i = 0; i < paov->n; i++)
        if (indegree[i] == 0) {         /* �����Ϊ��Ķ�����ջ */ 
            indegree[i] = top; top = i; 
        }
        while (top != -1) {                           /* ջ��Ϊ�� */
            j = top;
            top = indegree[top];               /* ȡ����ǰջ��Ԫ�� */
            /*ptopo->vexs[nodeno]=paov->vexs[j].vertex;*/ /* ����Ԫ����������������� */
            ptopo->vexsno[nodeno++] = j;
            p = paov->vexs[j].edgelist;    /* ȡ��Ԫ�ر߱��еĵ�һ���߽�� */
            /*ɾ���ý��,�����µ�AOV��*/
            /*��indegree��������޸�*/
            makeNewAOV(p, indegree, &top);
        }
        if (nodeno < paov->n) {      /* AOV���д��ڻ�· */
            printf("The aov network has a cycle\n");
            return FALSE;
        }
    return TRUE;
}

/* �ߵĲ����㷨*/
void insert(GraphList* p,int a,int b){
    EdgeList pp;
    PEdgeNode temp;
    temp = (PEdgeNode)malloc(sizeof(EdgeNode));
    temp->endvex = b;
    temp->nextedge = NULL;
    pp = p->vexs[a].edgelist;
    if (pp == NULL) p->vexs[a].edgelist = temp;
    else {
        while (pp->nextedge != NULL)
            pp = pp->nextedge;
        pp->nextedge = temp;
    }
}
	
/* ʵ���ڽӱ�Ĺ��� */
GraphList* makeList(){
    GraphList* p;
    int i;
    p = (GraphList*)malloc(sizeof(GraphList));
    p->n = 9;
    for (i = 0; i < p->n; i++)
        p->vexs[i].edgelist = NULL;
    insert(p, 0, 2);
    insert(p, 0, 7);
    insert(p, 1, 2);
    insert(p, 1, 3);
    insert(p, 1, 4);
    insert(p, 2, 3);
    insert(p, 3, 5);
    insert(p, 3, 6);
    insert(p, 4, 5);
    insert(p, 7, 8);
    insert(p, 8, 6);
    return p;
}

Topo topo;

int main(){
    GraphList* p;
    int i;
    p = makeList();
    if (topoSort(p, &topo) == TRUE)
        for (i = 0; i < p->n; i++)
            printf("%d ", topo.vexsno[i]);
    return 0;
}
