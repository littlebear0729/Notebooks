/*  用图邻接矩阵表示实现的一些基本运算*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXVEX 20
#define NON -1

typedef char VexType;

typedef int AdjType;

typedef struct {
    int n;                                 /* 图的顶点个数 */
    VexType vexs[MAXVEX];                 /*  顶点信息 */
    AdjType arcs[MAXVEX][MAXVEX];           /* 边信息 */
} GraphMatrix;

int visited[MAXVEX];

int firstVertex(GraphMatrix *pgraph) {
    return pgraph->n == 0 ? NON : 0;
}

int nextVertex(GraphMatrix *pgraph, int n) {
    return n == pgraph->n - 1 ? NON : n + 1;
}

int firstAdjacent(GraphMatrix *pgraph, int i) {
    int k;
    for (k = 0; k < pgraph->n; k++)
        if (pgraph->arcs[i][k] != 0) return k;
    return NON;
}

int nextAdjacent(GraphMatrix *pgraph, int i, int j) {
    int k;
    for (k = j + 1; k < pgraph->n; k++)
        if (pgraph->arcs[i][k] != 0) return k;
    return NON;
}

void initMatrix(GraphMatrix *matrix) {
    int i, j;
    for (i = 0; i < MAXVEX; i++) {
        for (j = 0; j < MAXVEX; j++) {
            matrix->arcs[i][j] = 0;
        }
    }
}

GraphMatrix createMatrix() {
    GraphMatrix matrix;
    // initMatrix(&matrix);
    memset(matrix.arcs, 0, sizeof(matrix.arcs));
    int i, j, n;
    printf("input number of point: ");
    scanf("%d", &n);
    matrix.n = n;
    for (i = 0; i < n; i++) {
        printf("input %dth of point's name: ", i + 1);
        scanf(" %c", &matrix.vexs[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            printf("is %c and %c connected?(1 or 0): ", matrix.vexs[i], matrix.vexs[j]);
            int tmp;
            scanf(" %d", &tmp);
            matrix.arcs[i][j] = tmp;
            matrix.arcs[j][i] = tmp;
        }
    }
    return matrix;
}

void printMatrix(GraphMatrix *matrix) {
    int i, j, n;
    n = matrix->n;
    for (i = 0; i < n; i++) {
        printf("%d point: %c\n", i + 1, matrix->vexs[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix->arcs[i][j] != 0) {
                printf("%c and %c are connected\n", matrix->vexs[i], matrix->vexs[j]);
            }
        }
    }
    printf("matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix->arcs[i][j]);
        }
        printf("\n");
    }
}

void dfs(GraphMatrix *matrix, int p) {
    int p1;
    visited[p] = 1;
    printf("%c", matrix->vexs[p]);
    for (p1 = firstAdjacent(matrix, p); p1 != NON; p1 = nextAdjacent(matrix, p, p1)) {
        if (!visited[p1])
            dfs(matrix, p1);
    }
}

void dft(GraphMatrix *matrix) {
    int p;
    for (p = firstVertex(matrix); p != NON; p = nextVertex(matrix, p))
        if (!visited[p])
            dfs(matrix, p);
}

int main() {
    memset(visited, 0, sizeof(visited));
    GraphMatrix matrix = createMatrix();
    printMatrix(&matrix);
    dft(&matrix);
    return 0;
}
