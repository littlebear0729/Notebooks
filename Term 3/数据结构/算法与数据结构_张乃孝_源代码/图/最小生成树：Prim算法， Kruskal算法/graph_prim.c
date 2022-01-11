/* ���ڽӾ����ʾ��ͼ��Kruskal�㷨��Դ����*/


#include<stdio.h>
#define MAXVEX 6

typedef char VexType;

typedef float AdjType;

typedef struct {
    int n;                          /* ͼ�Ķ������ */
    /*VexType vexs[MAXVEX];         ������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];   /* ����Ϣ */
} GraphMatrix;

typedef struct{
    int start_vex, stop_vex;        /* �ߵ������յ� */
    AdjType weight;                 /* �ߵ�Ȩ */
} Edge;

Edge mst[5];

#define MAX 1e+8

void prim(GraphMatrix * pgraph, Edge mst[]) {
    int i, j, min, vx, vy; 
    float weight, minweight; Edge edge;

    for (i = 0; i < pgraph->n-1; i++) {
        mst[i].start_vex = 0;
        mst[i].stop_vex = i+1;
        mst[i].weight = pgraph->arcs[0][i+1];
    }

    for (i = 0; i < pgraph->n-1; i++) {               /* ��n-1���� */
        minweight = MAX;  min = i;
        for (j = i; j < pgraph->n-1; j++)/* �����б�(vx,vy)(vx��U,vy��V-U)��ѡ����̵ı� */
            if(mst[j].weight < minweight) {
                minweight = mst[j].weight; 
                min = j;
            }

        /* mst[min]����̵ı�(vx,vy)(vx��U, vy��V-U)����mst[min]������С������ */
        edge = mst[min];  
        mst[min] = mst[i];   
        mst[i] = edge;
        vx = mst[i].stop_vex;            /* vxΪ�ռ�����С�������Ķ�����±� */

        for(j = i+1; j < pgraph->n-1; j++) { /* ����mst[i+1]��mst[n-1] */
            vy=mst[j].stop_vex; weight = pgraph->arcs[vx][vy];
            if (weight < mst[j].weight) {
                mst[j].weight = weight;  
                mst[j].start_vex = vx;
            }
        }
    }
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
    prim(&graph,mst);
    for (i = 0; i < graph.n-1; i++)
        printf("(%d %d %.0f)\n", mst[i].start_vex,
                mst[i].stop_vex, mst[i].weight);
    return 0;
}
