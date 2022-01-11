/* ͼ�Ĺؼ�·��������㷨*/


#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
#define TRUE 1
#define FALSE 0

typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode * PEdgeNode;
typedef struct EdgeNode * EdgeList;
typedef float AdjType;

struct EdgeNode {
    int endvex;			/* ���ڶ����ֶ� */
    AdjType weight;
    PEdgeNode nextedge;	/* ���ֶ� */
};						/* �߱��еĽ�� */

typedef struct {
    /*VexType vertex;*/		/* ������Ϣ */
    EdgeList edgelist;		/* �߱�ͷָ�� */
} VexNode;				/* ������еĽ�� */

typedef struct {
    int n;				/* ͼ�Ķ������ */
    VexNode vexs[MAXVEX];
} GraphList;


typedef struct {
    /*VexType vexs[MAXVEX];*/	/* ������Ϣ */	
    int vexsno[MAXVEX];		/* �����ڶ�����е��±�ֵ */
} Topo;


/* ���ͼ�����ж������� */
/* ���������������ڽӱ� */
void findInDegree(GraphList* g, int *inDegree) {
    int i; 
    PEdgeNode p;        

    for (i = 0; i < g->n; i++)
        inDegree[i] = 0;

    for (i = 0; i < g->n; i++) {
        p = g->vexs[i].edgelist;
        while(p) {
            inDegree[p->endvex]++; 
            p = p->nextedge; 
        }
    }
}

void makeNewAOV(EdgeList p, int* indegree, int* top) {
    int k;

    while (p) {                       /* ɾ���Ըö���Ϊ���ı� */
        k = p->endvex; 
        indegree[k]--;
        if (indegree[k] == 0) {         /* ���µ����Ϊ��ı���ջ */
            indegree[k] = *top;
            *top = k; 
        }
        p = p->nextedge;
    }
}

/* ���������㷨*/
int topoSort(GraphList * paov, Topo * ptopo) {
    EdgeList p;
    int i, j, nodeno = 0, top = -1;
    int indegree[MAXVEX];

    findInDegree(paov, indegree);    /* ���ͼ�����ж������� */
    for (i = 0; i < paov->n; i++)
        if (indegree[i] == 0) {        /* �����Ϊ��Ķ�����ջ */ 
            indegree[i] = top; top = i;
        }

    while (top != -1) {                /* ջ��Ϊ�� */
        j = top;
        top = indegree[top];               /* ȡ����ǰջ��Ԫ�� */
        /*ptopo->vexs[nodeno]=paov->vexs[j].vertex;*/ /* ����Ԫ����������������� */
        ptopo->vexsno[nodeno++] = j;
        p = paov->vexs[j].edgelist;    /* ȡ��Ԫ�ر߱��еĵ�һ���߽�� */
        /*ɾ���ý��,�����µ�AOV��*/
        /*��indegree��������޸�*/
        makeNewAOV(p, indegree, &top);
    }

    if (nodeno < paov->n) {       /* AOV���д��ڻ�· */
        printf("The aov network has a cycle\n");
        return FALSE;
    }
    
    return TRUE;
}

void insert(GraphList* p,int a,int b,float weight){
    EdgeList pp;
    PEdgeNode temp;
    temp = (PEdgeNode)malloc(sizeof(EdgeNode));
    temp->endvex = b;
    temp->nextedge = NULL;
    temp->weight = weight;
    pp = p->vexs[a].edgelist;
    if (pp == NULL)
        p->vexs[a].edgelist = temp;
    else {
        while (pp->nextedge != NULL)
            pp = pp->nextedge;
        pp->nextedge = temp;
    }
}
	
/* �ڽӱ�Ĺ���*/
GraphList* makeList(){
    GraphList* p;
    int i;
    p = (GraphList*)malloc(sizeof(GraphList));
    p->n = 9;
    for (i = 0; i < p->n; i++)
        p->vexs[i].edgelist = NULL;
    insert(p,0,1,6);
    insert(p,0,2,4);
    insert(p,0,3,5);
    insert(p,1,4,1);
    insert(p,2,4,1);
    insert(p,3,5,2);
    insert(p,4,6,9);
    insert(p,4,7,7);
    insert(p,5,7,4);
    insert(p,6,8,2);
    insert(p,7,8,4);
    return p;
}

int CriticalPath(GraphList * paoe);

/* ������*/
int main(){
    GraphList* p;
    /*int i;*/
    p = makeList();
    /*if(topoSort(p,&topo)==TRUE)
        for(i=0;i<p->n;i++)
            printf("%d ",topo.vexsno[i]);*/
    if (CriticalPath(p) == FALSE)
        printf("There is no critical path!\n");
    return 0;
}


/*******************************************/
#define MAXEDGE 100 

/* ��������ee*/
void countee(GraphList* paoe,Topo* ptopo, AdjType* ee) {
    int i, j, k;
    EdgeList p;

    for (i = 0; i < paoe->n; i++) ee[i] = 0;
    for (k = 0; k < paoe->n; k++) {       /* ���¼�vj���ܵ����緢��ʱ��ee(j) */
        i = ptopo->vexsno[k];
        p = paoe->vexs[i].edgelist;
        while (p != NULL) {
            j = p->endvex;
            if (ee[i] + p->weight > ee[j])
                ee[j] = ee[i] + p->weight;
            p = p->nextedge;
        }
    }
}


/* ��������le*/
void countle(GraphList * paoe,Topo* ptopo, AdjType* ee, AdjType* le) {
    int i, j, k;
    EdgeList p;
    for (i = 0; i < paoe->n; i++)         /* ���¼�vi�������ٷ���ʱ��le(i) */
        le[i] = ee[paoe->n - 1];
    for (k = paoe->n - 2; k >= 0; k--) {
        i = ptopo->vexsno[k];
        p = paoe->vexs[i].edgelist;
        while (p != NULL) {
            j = p->endvex;
            if( le[j] - p->weight < le[i] )
                le[i] = le[j] - p->weight;
            p = p->nextedge;
        }
    }
}

/* ��������e,l��������*/
void counte_l(GraphList * paoe,Topo* ptopo, AdjType* ee,
                AdjType* le, AdjType* e, AdjType* l) {
    int i, j, k = 0;
    EdgeList p;
    /* ��ak�����翪ʼʱ��e(k)������ʼʱ��l(k) */
    for (i = 0; i < paoe->n; i++) {
        p = paoe->vexs[i].edgelist;
        while (p != NULL) {
            j = p->endvex;
            e[k] = ee[i];
            l[k] = le[j] - p->weight;
            if (e[k] == l[k])
                printf("<v%2d, v%2d>, ", i, j);
            k++;
            p = p->nextedge;
        }
    }
}

/* �ؼ�·���㷨*/
int CriticalPath(GraphList * paoe) {
    AdjType ee[MAXVEX], le[MAXVEX], l[MAXEDGE], e[MAXEDGE];
    Topo topo;
    if (topoSort(paoe, &topo) == FALSE)               /* ��AOE����һ���������� */
        return FALSE;
    countee(paoe, &topo, ee); /*��������ee*/
    countle(paoe, &topo, ee, le);/*��������le*/
    counte_l(paoe, &topo, ee, le, e, l);/*��������e,l��������*/
    printf("\n");
    return TRUE;
}
