/* �ö�̬�滮������������㷨*/


#include<stdio.h>

int combinat(int m, int n) {
    int i, j;
    int mat[100][100];
    if (n == 0 || m == n)
        return 1;     
    else {
        for (j = 0; j < n; j++) {
            mat[0][j] = 1;
            for (i = 1; i <= m-n; i++)
                if (j == 0)
                    mat[i][j] = i+1;
                else
                    mat[i][j] = mat[i-1][j] + mat[i][j-1];
        }              			
        return (mat[m-n][n-1]);       /* ���ؼ���õ��Ľ�� */
    }
}

int main() {
    printf("m=%d  ,n=%d  ,combinat=%d\n", 10, 2, combinat(10, 2));
    printf("m=%d  ,n=%d  ,combinat=%d\n", 5, 3, combinat(5, 3));
    printf("m=%d  ,n=%d  ,combinat=%d\n", 6, 1, combinat(6, 1));
    printf("m=%d  ,n=%d  ,combinat=%d\n", 4, 2, combinat(4, 2));
    return 0;
}
