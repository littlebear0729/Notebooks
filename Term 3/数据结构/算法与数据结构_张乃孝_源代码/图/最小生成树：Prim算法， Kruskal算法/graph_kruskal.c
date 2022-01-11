/* ���ڽӾ����ʾ��ͼ��prim�㷨��Դ����*/


#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 6
enum{FALSE,TRUE};

typedef char VexType;
typedef float AdjType;

typedef struct {
    int n;                                           /* ͼ�Ķ������ */
    /*VexType vexs[MAXVEX];                   ������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];           /* ����Ϣ */
} GraphMatrix;

typedef struct {
    int start_vex, stop_vex;              /* �ߵ������յ� */
    AdjType weight;                  /* �ߵ�Ȩ */
} Edge;

Edge mst[5];


#define MAX 1e+8

int kruskal(GraphMatrix  graph, Edge mst[]) {   
    int i, j, num = 0, start, stop;
    float minweight;
    int* status = (int *)malloc(sizeof(int)*graph.n);
    for (i = 0; i < graph.n; i++)
        status[i] = i;
    while (num < graph.n - 1){
        minweight = MAX;
        for (i = 0; i < graph.n-1; i++)
            for (j = i+1; j < graph.n; j++)
                if (graph.arcs[i][j] < minweight){
                    start = i; stop = j;
                    minweight = graph.arcs[i][j];
                }
        if (minweight == MAX) return FALSE;/* ���ܵõ���С������*/
        /* ����start��stop��ɵı߲�������·*/
        if (status[start] != status[stop]){
            mst[num].start_vex = start;
            mst[num].stop_vex = stop;
            mst[num].weight = graph.arcs[start][stop];
            num++;
            j = status[stop];
            for (i = 0; i < graph.n; i++)	
                if(status[i] == j)
                    status[i] = status[start];
        }
        /* ɾ��start��stop��ɵı�*/
        graph.arcs[start][stop] = MAX;
    }		
    return TRUE;/* �ܵõ���С������*/
}

GraphMatrix graph = {
    6,
    {{0,10,MAX,MAX,19,21},
     {10,0,5,6,MAX,11},
     {MAX,5,0,6,MAX,MAX},
     {MAX,6,6,0,18,14},
     {19,MAX,MAX,18,0,33},
     {21,11,MAX,14,33,0}
    }
};

int main(){
    int i;
    if (kruskal(graph,mst) == TRUE)
        for (i = 0; i < graph.n-1; i++)
            printf("(%d %d %.0f)\n", mst[i].start_vex,
                mst[i].stop_vex, mst[i].weight);
    return 0;
}
