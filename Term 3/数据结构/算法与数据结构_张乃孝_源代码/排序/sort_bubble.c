/* ����������㷨Դ����*/

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


void  bubbleSort(SortObject * pvector) {
    int i, j, noswap; 
    RecordNode temp, *data = pvector->record;

    for(i = 0; i < pvector->n-1; i++) {         /* ��n-1������ */
        noswap = TRUE;                          /* �ý�����־ */
        for (j = 0; j < pvector->n-i-1; j++)    /* ��ǰ���ɨ�� */
            if (data[j+1].key < data[j].key) {  /* ������¼ */
                temp = data[j]; 
                data[j] = data[j+1];
                data[j+1] = temp;
                noswap = FALSE;
            }
        if ( noswap ) break;    /* ��������δ������¼�������㷨���� */
    }
}

SortObject vector={8, 49,38,65,97,76,13,27,49};

int main(){
    int i;
    bubbleSort(&vector);
    for(i = 0; i < 8; i++)
        printf("%d ", vector.record[i]);
    getchar();
    return 0;
}
