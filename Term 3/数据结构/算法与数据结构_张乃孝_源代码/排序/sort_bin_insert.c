/* ���ַ�����������㷨Դ����*/

#include<stdio.h>

#define MAXNUM 100
typedef int KeyType;
typedef int DataType;

typedef struct {
    KeyType key;       /* �������ֶ� */
    /*DataType info;   ��¼�������ֶ� */
} RecordNode;

typedef struct {
    int n;               /* nΪ�ļ��еļ�¼������n<MAXNUM */
    RecordNode record[MAXNUM];
} SortObject;

void binSort(SortObject * pvector) {      /* ����������ж��ַ��������� */
    int i, j, left, mid, right;
    RecordNode temp;
    RecordNode *data = pvector->record;
    
    for( i = 1; i < pvector->n; i++ ) {
        temp = data[i];
        left = 0;  right = i-1;           /* ��������������¡��Ͻ��ֵ */
        while (left <= right) {
            mid = (left + right)/2;       /* midָ��������������м�λ�� */
            if (temp.key < data[mid].key)
                right = mid-1;            /* ����Ԫ��Ӧ���������� */
            else left = mid+1;            /* ����Ԫ��Ӧ���������� */
        }
        for (j = i-1;  j >= left;  j--)
            data[j+1] = data[j];          /* �����������ki�ļ�¼���� */
        if (left != i) data[left] = temp;
    }
}

SortObject vector={10, 49,38,65,97,76,13,27,49,50,101};

int main(){
    int i;
    binSort(&vector);
    for(i = 0; i < vector.n; i++)
        printf("%d ", vector.record[i]);
    getchar();
    return 0;
}
