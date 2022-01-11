/*  ��ͼ�ڽӾ����ʾʵ�ֵ�һЩ��������*/



#define MAXVEX 20
#define NON -1

typedef char VexType;

typedef float AdjType;

typedef struct {
    int n;                                 /* ͼ�Ķ������ */
    VexType vexs[MAXVEX];                 /*  ������Ϣ */
    AdjType arcs[MAXVEX][MAXVEX];           /* ����Ϣ */
} GraphMatrix;

int firstVertex(GraphMatrix* pgraph) {    
    return pgraph->n == 0 ? NON : 0;
}

int nextVertex(GraphMatrix* pgraph,int n) {    
    return n == pgraph->n-1 ? NON : n+1;
}

int firstAdjacent(GraphMatrix* pgraph, int i) {
    int k;
    for (k = 0; k < pgraph->n; k++)
        if(pgraph->arcs[i][k] != 0) return k;
    return NON; 
}  

int  nextAdjacent(GraphMatrix* pgraph, int i, int j) {
    int k;
    for (k = j+1; k < pgraph->n; k++)
        if (pgraph->arcs[i][k] != 0) return k;
    return NON; 
}   


int main() {
    return 0;
}
