/* ��������㷨Դ����*/

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

/* �������Ϊ��ʹ�������� */ 
#define leftChild(i) (2*(i)+1)

void  sift(SortObject * pvector, int i, int n) {
    int child; 
    RecordNode temp = pvector->record[i], *data = pvector->record;

    child = leftChild(i);      /* Rchild��R0������Ů */
    while(child<n) {
        if (child < n-1 && data[child].key < data[child+1].key)
            child++;           /* child ָ��Ri��������Ů��������ϴ�Ľ�� */
        if (temp.key < data[child].key) {
            data[i] = data[child]; 
            i = child;  child = leftChild(i);/* child���������λ�ã���������*/
        }
        else break;            /* �������� */
    }
    data[i] = temp;            /* ����¼Ri������ȷλ�� */
}

void  heapSort(SortObject * pvector) {    /* �Լ�¼R0��Rn-1���ж����� */
    int i, n = pvector->n;
    RecordNode temp, *data = pvector->record;
    
    for (i = n/2-1; i >= 0; i--)
        sift(pvector, i, n);              /* ������ʼ�� */
    for (i = n-1; i > 0; i--) {           /* ����n-1�˶����� */
        temp = data[0];                   /* ��ǰ�Ѷ���¼�����һ����¼���� */
        data[0] = data[i];
        data[i] = temp;
        sift(pvector, 0, i);              /* ��R0��Ri-1�ؽ��� */
    }
}

SortObject vector={8, 49,38,65,97,76,13,27,49};

int main(){
    int i;
    heapSort(&vector);
    for(i = 0; i < 8; i++)
        printf("%d ", vector.record[i]);
    getchar(); 
    return 0;
}
