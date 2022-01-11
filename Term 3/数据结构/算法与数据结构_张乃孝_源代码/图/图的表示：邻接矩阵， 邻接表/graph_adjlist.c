/*  ��ͼ�ڽӱ��ʾʵ�ֵ�һЩ��������*/

#include<stdio.h>
#define MAXVEX 20
#define NON -1

typedef char VexType;

typedef float AdjType;

typedef int Vertex;

struct EdgeNode;
typedef struct EdgeNode * PEdgeNode;
typedef struct EdgeNode * EdgeList;

struct EdgeNode {
    int endvex;			/* ���ڶ����ֶ� */
    AdjType weight;		/* �ߵ�Ȩ���Ǵ�Ȩͼ����ʡ�� */
    PEdgeNode nextedge;	/* ���ֶ� */
};	                    /* �߱��еĽ�� */
					
typedef struct {
    VexType vertex;		/* ������Ϣ */
    EdgeList edgelist;	/* �߱�ͷָ�� */
} VexNode;               /* ������еĽ�� */

typedef struct {
	int n;				/* ͼ�Ķ������ */
	VexNode vexs[MAXVEX];
} GraphList;

int firstVertex(GraphList* pgraph) {    
    return pgraph->n == 0 ? NON : 0;
}

int nextVertex(GraphList* pgraph,int n) {    
    return n == pgraph->n-1 ? NON : n+1;
}

int firstAdjacent(GraphList* pgraph, int i) {
    if (pgraph->vexs[i].edgelist != NULL)
        return pgraph->vexs[i].edgelist->endvex;
    else return NON; 
}  

int nextAdjacent(GraphList* pgraph, int i, int j) {
    PEdgeNode p;
    for (p = pgraph->vexs[i].edgelist; p != NULL; p = p->nextedge)
        if (p->endvex == j) {
            if (p->nextedge != NULL)
                return p->nextedge->endvex;
            else 
                return NON;
        }
    return NON; 
}   


int main() {
    return 0;
}
