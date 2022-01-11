/* �������ṩ����˳���ʵ���ֵ�������
�Ķ��ַ������㷨*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MAXNUM 100

typedef int KeyType ;

typedef struct {
    KeyType key;                  /* �ֵ�Ԫ�صĹؼ����ֶ�     */
    /*DataType value;             /* �ֵ�Ԫ�ص������ֶ�    */
} DicElement;

typedef struct {
    int n;                          /* n<=MAXNUM��Ϊ�ֵ���Ԫ�صĸ��� */
    DicElement element[MAXNUM];
} SeqDictionary;

/* ���ֵ����ö��ַ����ҹؼ���Ϊkey��Ԫ�� */
int binarySearch(SeqDictionary * pdic, KeyType key, int *position) {
    int low = 0, high = pdic->n-1, mid;

    while(low<=high) {
        mid = (low+high)/2;                   /* ��ǰ�������м�λ�� */
        if(pdic->element[mid].key == key) {   /* �����ɹ� */
            *position = mid;  return TRUE;
        }
        else if (pdic->element[mid].key > key) 
            high = mid-1;                     /* Ҫ������Ԫ��������� */
        else low = mid+1;                     /* Ҫ������Ԫ�����Ұ��� */
    }
    *position=low;
    return FALSE;                            /* ����ʧ�� */
}

SeqDictionary dic={
    10, 1,3,5,7,9,11,13,19,21,30};

int main(){
    int i, position;
    while(1){
        printf("Input the key you want to search: ");
        scanf("%d",&i);
        if(i==0)break;
        if(binarySearch(&dic,i,&position)==TRUE)
            printf("It is the %dth element!\n",position+1);
        else printf("It is not in the dictionary!\n");
    }
    return 0;
}
