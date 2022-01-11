/* shell������㷨Դ���� */

#include<stdio.h>

#define MAXNUM 100
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

void  shellSort(SortObject * pvector, int d) {	/* �����������Shell���� */
    int i, j, inc; 
    RecordNode temp, *data = pvector->record;
    
    for (inc = d; inc > 0; inc /= 2) {
        /* inc Ϊ����shell�������� */
        for (i = inc; i < pvector->n; i++) { 
            temp = data[i];          	/* ����������¼Ri*/ 
            for (j = i-inc; j >= 0 && temp.key < data[j].key; j -= inc)
                data[j+inc] = data[j];	/* ���Ҳ���λ�ã���¼���� */
            data[j+inc] = temp;			/* �����¼Ri */
        }
    }
}


SortObject vector={8,49,38,65,97,76,13,27,49};

int main(){
    int i;
    shellSort(&vector,4);
    for(i=0;i<8;i++)
        printf("%d ",vector.record[i]);
    getchar();
    return 0;
}


