/* ���ڽӾ����ʾ��ͼ��Dijkstra�㷨��Դ����*/

#include<stdio.h>
#define MAXVEX    100
                       
typedef char VexType;
typedef float AdjType;

typedef struct {
    int n;                                           /* ͼ�Ķ������ */
    VexType vexs[MAXVEX];                   /* ������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];           /* ����Ϣ */
} GraphMatrix;

typedef struct {
    VexType vertex;        /* ������Ϣ */
    AdjType length;        /* ���·������ */
    int prevex;           /* ��v0����vi(i=1,2,��n-1)�����·����vi��ǰ������ */
} Path;

Path dist[6];                    /* nΪͼ�ж������*/

#define MAX 1e+8

void init(GraphMatrix* pgraph, Path dist[]) {
    int i; 
    dist[0].length = 0;
    dist[0].prevex = 0;      
    dist[0].vertex = pgraph->vexs[0];

    pgraph->arcs[0][0] = 1;                    /* ��ʾ����v0�ڼ���U�� */

    for(i = 1; i < pgraph->n; i++) {             /* ��ʼ������V-U�ж���ľ���ֵ */
        dist[i].length=pgraph->arcs[0][i];
        dist[i].vertex=pgraph->vexs[i];
        if (dist[i].length != MAX)
            dist[i].prevex=0;
        else  dist[i].prevex= -1;
    }
}


void dijkstra(GraphMatrix graph, Path dist[]) {
    int i,j,minvex;
    AdjType min;
	init(&graph,dist); /* ��ʼ������ʱ����U��ֻ�ж���v0*/
    for(i = 1; i < graph.n; i++) {
        min=MAX;	minvex=0;
        for (j = 1; j < graph.n; j++) /*��V-U��ѡ������ֵ��С����*/
            if( graph.arcs[j][j] == 0 && dist[j].length < min ) {
                min=dist[j].length;  minvex=j;  
            }

        if(minvex == 0) break;	/* ��v0û��·������ͨ������V-U�еĶ��� */
        graph.arcs[minvex][minvex] = 1;	/* ����V-U��·����С�Ķ���Ϊminvex */
        for (j = 1; j < graph.n; j++) {	/* ��������V-U�еĶ�������·�� */
            if(graph.arcs[j][j] == 1)  continue;
            if(dist[j].length > dist[minvex].length + graph.arcs[minvex][j]) {
                dist[j].length = dist[minvex].length + graph.arcs[minvex][j];
                dist[j].prevex = minvex;
            }
        }
    }
}

GraphMatrix graph;

void initgraph(){
    int i,j;
    graph.n=6;
    for (i = 0; i < graph.n; i++)
        for (j = 0; j < graph.n; j++)
            graph.arcs[i][j] = (i == j ? 0 : MAX);
    graph.arcs[0][1] = 50;
    graph.arcs[0][2] = 10;
    graph.arcs[1][2] = 15;
    graph.arcs[1][4] = 5;
    graph.arcs[2][0] = 20;
    graph.arcs[2][3] = 15;
    graph.arcs[3][1] = 20;
    graph.arcs[3][4] = 35;
    graph.arcs[4][3] = 30;
    graph.arcs[5][3] = 3;
    graph.arcs[0][4] = 45;
}

int main(){
    int i;
    initgraph();
    dijkstra(graph, dist);
    for (i = 0; i < graph.n; i++)
        printf("(%.0f %d)", dist[i].length,dist[i].prevex);
    return 0;
}



