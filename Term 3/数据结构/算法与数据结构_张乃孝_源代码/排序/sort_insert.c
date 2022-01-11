/* ֱ�Ӳ���������㷨Դ����*/

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

void insertSort(SortObject * pvector) { /* �����������ֱ�Ӳ������� */
    int i, j;
    RecordNode temp;
    RecordNode *data = pvector->record;

    for( i = 1; i < pvector->n; i++ ) { /* ���β����¼R1, R2��Rn-1 */
        temp = data[i]; 
        for ( j = i-1; temp.key < data[j].key && j >= 0; j-- )
            /* �ɺ���ǰ�Ҳ���λ�� �����������ki�ļ�¼���� */
            data[j+1] = data[j];
        if( j != i-1 ) data[j+1] = temp;
    }
}

SortObject vector = {10, 
    49, 38, 65, 97, 76, 13, 27, 49, 50, 101};

int main(){
    int i;
    insertSort(&vector);
    for(i = 0; i < vector.n; i++)
        printf("%d ", vector.record[i]);
    getchar();
    return 0;
}


