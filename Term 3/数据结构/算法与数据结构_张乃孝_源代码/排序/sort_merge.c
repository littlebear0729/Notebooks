/* ��·�鲢�����㷨��Դ����*/

#include<stdio.h>

#define MAXNUM 100
#define TRUE 1
#define FALSE 0

typedef int KeyType;
typedef int DataType;

typedef struct {
    KeyType key;       /* �������ֶ� */
    /*DataType info;           ��¼�������ֶ� */
} RecordNode;

typedef struct {
    int n;               /* nΪ�ļ��еļ�¼������n<MAXNUM */
    RecordNode record[MAXNUM];
} SortObject;

void merge(RecordNode r[], RecordNode r1[], int low, int m, int high) {
    /* r[low]��r[m]��r[m+1]��r[right]����������� */
    int i = low, j = m + 1, k = low;
    
    while ( i <= m && j <= high ) {    /* �������������εĵ�һ����¼�н�С�� */
        if (r[i].key <= r[j].key)  
            r1[k++] = r[i++];
        else r1[k++] = r[j++];
    }

    while (i <= m) r1[k++] = r[i++];   /* ���Ƶ�һ���ε�ʣ���¼ */
    while (j <= high) r1[k++] = r[j++];/* ���Ƶڶ����ε�ʣ���¼ */

}

/* �� r ��һ�˹鲢������ŵ� r1 �� */
void mergePass(RecordNode r[], RecordNode r1[], int n, int length) {
    int i = 0, j;                     /* lengthΪ���˹鲢�������Ӷεĳ��� */

    while(i + 2*length - 1 < n) {
        merge(r, r1, i, i+length-1, i + 2*length - 1);/* �鲢��length�������Ӷ�*/
        i += 2*length;
    }
    
    if(i + length - 1 < n - 1)        /* ʣ�����Σ���һ�γ���С�� length */
        merge(r, r1, i, i+length-1, n-1);
    else                              /* ��ʣ�µ�һ�θ��Ƶ�����r1 */
        for(j = i; j < n; j++) r1[j] = r[j];
}

void mergeSort(SortObject * pvector) {
    RecordNode record[MAXNUM];
    int length = 1;

    while (length < pvector->n) {
        /* һ�˹鲢��������������record��*/
        mergePass(pvector->record, record, pvector->n, length);
        length *= 2;
        /* һ�˹鲢�������� */
        mergePass(record, pvector->record, pvector->n, length);
        length *= 2;
    }
}

SortObject vector = {8, 49,38,65,97,76,13,27,49};

int main(){
    int i;
    mergeSort(&vector);
    for(i = 0; i < 8; i++)
        printf("%d ", vector.record[i]);
    getchar();
    return 0;
}
