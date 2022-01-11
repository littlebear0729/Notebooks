/* ���ڽӾ����ʾͼ�����������㷨*/


#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
#define TRUE 1
#define FALSE 0
					
typedef char VexType;
typedef int AdjType;
typedef struct {
    int n;								/* ͼ�Ķ������ */
    /*VexType vexs[MAXVEX];*/				/* ������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];		/* ����Ϣ */
} GraphMatrix;

typedef struct {
    /*VexType vexs[MAXVEX];*/	/* ������Ϣ */	
    int vexsno[MAXVEX];		/* �����ڶ�����е��±�ֵ */
} Topo;

/* ���ͼ�����ж������� */
/* ���������������ڽӱ� */
void findInDegree(GraphMatrix* g, int *inDegree) {
    int i, j;       
    for (i = 0; i < g->n; i++) {
        inDegree[i] = 0;
        for (j = 0; j < g->n; j++)
            if (g->arcs[j][i]) ++inDegree[i];
    }
}

void makeNewAOV(GraphMatrix* g, int p, int* indegree, int* top) {
    int k;
    for (k = 0; k < g->n; k++)/* ɾ���Ըö���Ϊ���ı� */
        if (g->arcs[p][k]) {
            indegree[k]--;
            if (indegree[k] == 0) {         /* ���µ����Ϊ��ı���ջ */
                indegree[k] = *top;
                *top = k; 
            }
        }
}

int topoSort(GraphMatrix * paov, Topo * ptopo) {
    int i, j, nodeno = 0, top = -1;
    int indegree[MAXVEX];

    findInDegree(paov, indegree); /* ���ͼ�����ж������� */

    for (i = 0; i < paov->n; i++)
        if (indegree[i] == 0) {          /* �����Ϊ��Ķ�����ջ */ 
            indegree[i] = top; top = i;
        }

    while (top != -1) {                           /* ջ��Ϊ�� */
        j = top;
        top = indegree[top];               /* ȡ����ǰջ��Ԫ�� */
        /*ptopo->vexs[nodeno] = paov->vexs[j];*/ /* ����Ԫ����������������� */
        ptopo->vexsno[nodeno++] = j;
        /* ȡ��Ԫ�ر߱��еĵ�һ���߽�� */
        /* ɾ���ý��,�����µ�AOV�� */
        /* ��indegree��������޸� */
        makeNewAOV(paov, j, indegree, &top);
    }
    if (nodeno < paov->n) {        /* AOV���д��ڻ�· */
        printf("The aov network has a cycle\n");
        return FALSE;
    }
    return TRUE;
}

/* �����ڽӾ���*/
GraphMatrix* makeMatrix(){
    GraphMatrix* p;
    int i,j;
    p = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    p->n = 9;
    for (i = 0; i < p->n; i++)
        for (j = 0; j < p->n; j++)
            p->arcs[i][j] = 0;
    p->arcs[0][2] = 1;
    p->arcs[0][7] = 1;
    p->arcs[1][2] = 1;
    p->arcs[1][3] = 1;
    p->arcs[1][4] = 1;
    p->arcs[2][3] = 1;
    p->arcs[3][5] = 1;
    p->arcs[3][6] = 1;
    p->arcs[4][5] = 1;
    p->arcs[7][8] = 1;
    p->arcs[8][6] = 1;
    return p;
}

Topo topo;

int main(){
    int i;
    GraphMatrix* p;
    p = makeMatrix();
    if (topoSort(p, &topo) == TRUE)
        for (i = 0; i < p->n; i++)
            printf("%d ", topo.vexsno[i]);
    return 0;
}
