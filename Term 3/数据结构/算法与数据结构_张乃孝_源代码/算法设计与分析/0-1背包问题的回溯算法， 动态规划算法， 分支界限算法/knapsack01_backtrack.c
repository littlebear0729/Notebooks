/* 0/1��������Ļ��ݷ��㷨*/

#include<stdio.h>

#define NUM 4

/* m Ϊ��������w Ϊ������Ʒ��������p Ϊ������Ʒ�ļ�ֵ��n Ϊ��Ʒ��������
   �������� x��i Ϊ�ݹ���� */
void solve(double m, int n, double p[], double w[], int x[], int i){
    static double max = 0;
    static double totalweight = 0;
    static int x1[NUM];
    if (i == n){
        int i;
        double sum;
        for (sum = 0, i = 0; i < n; i++)
            sum += x1[i] * p[i];
        if (sum > max) {
            max = sum;
            for (i = 0; i < n; i++) x[i] = x1[i];
        }
        return;
    }
    x1[i] = 0;/* ��x1[i]��Ϊ0 */
    solve(m, n, p, w, x, i + 1);
    if (totalweight + w[i] <= m){
        x1[i] = 1;/* ��x1[i]��Ϊ1 */
        totalweight += w[i];
        solve(m, n, p, w, x, i + 1);
        totalweight -= w[i];
    }
}

#define NUM 4

double m = 15;
double w[] = {2, 4, 6, 9};
double p[] = {10, 10, 12, 18};
int x[NUM];

int main(){
    int i;
    solve(m, NUM, p, w, x, 0);
    for (i = 0; i < NUM; i++)
        printf("x%d = %d  ", i+1, x[i]);
    getchar();
    return 0;
}
