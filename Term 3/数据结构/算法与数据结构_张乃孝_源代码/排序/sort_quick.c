/* ����������㷨Դ����*/

#include<stdio.h>

#define MAXNUM 100
#define TRUE 1
#define FALSE 0
typedef int KeyType;
typedef int DataType;

typedef struct {
    KeyType key;         /* �������ֶ� */
    /*DataType info;        ��¼�������ֶ� */
} RecordNode;

typedef struct {
    int n;               /* nΪ�ļ��еļ�¼������n<MAXNUM */
    RecordNode record[MAXNUM];
} SortObject;

void quickSort(SortObject * pvector, int l, int r) {
    int i, j;
    RecordNode temp, *data = pvector->record;
    
    if (l >= r) return;   /* ֻ��һ����¼���޼�¼������������ */

    i = l;  j = r;  temp = data[i];

    while (i != j) {        /* Ѱ��Rl������λ�� */
        while( data[j].key >= temp.key && j > i )
            j--;         /* ��������ɨ�裬���ҵ�1��������С��temp.key�ļ�¼ */
        if (i < j) data[i++] = data[j];   

        while( data[i].key <= temp.key && j > i )
            i++;         /* ��������ɨ�裬���ҵ�1�����������temp.key�ļ�¼ */
        if (i < j) data[j--] = data[i];
    }

    data[i] = temp;                 /* �ҵ�Rl������λ�� */
    quickSort(pvector, l, i-1);                 /* �ݹ鴦�������� */
    quickSort(pvector, i+1, r);            /* �ݹ鴦�������� */
}

SortObject vector = {8, 49,38,65,97,76,13,27,49};

int main(){
    int i;
    quickSort(&vector, 0, 7);
    for(i = 0; i < 8; i++)
        printf("%d ", vector.record[i]);
    getchar();
    return 0;
}
