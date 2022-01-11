/* ֱ��ѡ��������㷨Դ����*/

#include<stdio.h>

#define MAXNUM 100
#define TRUE 1
#define FALSE 0
typedef int KeyType;
typedef int DataType;

typedef struct {
    KeyType key;         /* �������ֶ� */
    /*DataType info;     ��¼�������ֶ� */
} RecordNode;

typedef struct {
    int n;               /* nΪ�ļ��еļ�¼������n<MAXNUM */
    RecordNode record[MAXNUM];
} SortObject;

void  selectSort(SortObject * pvector) {   /* �����������ֱ��ѡ������ */
    int i, j, k;
    RecordNode temp, *data = pvector->record;

    for( i = 0; i < pvector->n-1; i++ ) {  /* ��n-1��ѡ������ */
        k = i;
        for (j = i+1; j < pvector->n; j++) /* �����������ҳ���������С�ļ�¼Rk*/
            if (data[j].key < data[k].key) k = j;
        if (k != i) {                      /* ��¼Rk��Ri���� */
            temp = data[i];
            data[i] = data[k];
            data[k] = temp;
        }     
    }
}

SortObject vector={8, 49,38,65,97,76,13,27,49};

int main(){
    int i;
    selectSort(&vector);
    for(i = 0; i < 8; i++)
        printf("%d ", vector.record[i]);
    getchar();
    return 0;
}
