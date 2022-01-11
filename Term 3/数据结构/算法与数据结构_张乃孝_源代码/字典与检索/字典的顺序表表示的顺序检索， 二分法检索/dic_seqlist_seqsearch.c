/* �������ṩ����˳���ʵ���ֵ�������
��˳������㷨*/


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

/*���ֵ���˳������ؼ���Ϊkey��Ԫ��*/
int seqSearch(SeqDictionary * pdic, KeyType key, int * position) {
    int i;
    for(i = 0; i < pdic->n; i++)   /* ��ͷ��ʼ���ɨ��  */
        if(pdic->element[i].key == key) {
            *position = i;
            return TRUE;          /* �����ɹ� */
        }
    *position = i;
    return FALSE;                 /* ����ʧ�� */
}


SeqDictionary dic = {
    10, 
    1,3,5,7,9,11,13,19,21,30
};

int main() {
    int i, position;

    while(1){
        printf("Input the key you want to search:");
        scanf("%d",&i);
        if (i == 0) break;
        if (seqSearch(&dic,i,&position) == TRUE)
            printf("It is the %dth element!\n", position+1);
        else printf("It is not in the dictionary!\n");
    }
    
    getchar();
    return 0;
}
