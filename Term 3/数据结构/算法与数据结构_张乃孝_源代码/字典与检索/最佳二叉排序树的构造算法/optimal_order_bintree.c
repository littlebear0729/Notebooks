/* ��Ѷ����������Ǿ�����Ѽ���Ч�ʵĶ���������,
�������ṩ����Ѷ����������Ĺ��췽��*/

#include<stdio.h>
#define MAXVALUE 1e8
#define N 10

void opticBTree(float p[], float q[], float *c[], float *w[], int *r[], int n) {
    int k0, i, j, k, m; float min;

    for (i = 0; i <= n; i++)                /* �������������� */
        for (j = 0; j <= i; j++)
            c[i][j] = w[i][j] = r[i][j] = 0;

    for (i = 0; i <= n; i++) {              /* ����w[i][j] */
        w[i][i] = q[i];
        for (j = i+1; j <= n; j++)
            w[i][j] = w[i][j-1] + p[j] + q[j];
    }

    for (j = 1; j <= n; j++) {               /* ����һ���ڲ�������Ѷ��������� */
        c[j-1][j] = w[j-1][j]; r[j-1][j] = j;
    }

    for (m = 2; m <= n; m++)                 /* ����m��������Ѷ��������� */
        for (i = 0; i <= n-m; i++) {
            j = i+m; min = MAXVALUE; k0 = i+1;

            for (k = i+1; k <= j; k++)  /* ��i<k��j��Χ�ڣ��ҳ�ʹC(i,k-1)+C(k,j)��С��k��*/
                if ( c[i][k-1] + c[k][j] < min) {
                    min = c[i][k-1] + c[k][j]; k0 = k;
                }
            c[i][j] = w[i][j] + min; 
            r[i][j] = k0;
        }
}

int main() {
    float p[] = {0,1,5,4,3};
    float q[] = {5,4,3,2,1};
    float *cc[N];
    float *ww[N];
    int *rr[N];
    float c[N][N], w[N][N];
    int r[N][N];
    int i, j;
    for(i = 0; i < N; i++) {
        cc[i] = c[i];
        ww[i] = w[i];
        rr[i] = r[i];
    }
    opticBTree(p, q, cc, ww, rr, 4);
    for (i = 0; i < 4; i++) {
        for(j = i+1; j <= 4; j++)
            printf("%d ", r[i][j]);/*��ӡ����r*/
        putchar('\n');
    }
    for (i = 0; i <= 4; i++) {
        for (j = i; j <= 4; j++)
            printf("%.0f ", w[i][j]);/*��ӡ����w*/
        putchar('\n');
    }
    for (i = 0; i < 4; i++) {
        for (j = i+1; j <= 4; j++)
            printf("%.0f ", c[i][j]);/*��ӡ����c*/
        putchar('\n');
    }
    getchar();
    return 0;
}
