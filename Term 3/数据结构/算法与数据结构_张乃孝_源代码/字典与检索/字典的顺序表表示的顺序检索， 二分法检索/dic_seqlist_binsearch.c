/* 本程序提供了用顺序表实现字典的情况下
的二分法检索算法*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MAXNUM 100

typedef int KeyType ;

typedef struct {
    KeyType key;                  /* 字典元素的关键码字段     */
    /*DataType value;             /* 字典元素的属性字段    */
} DicElement;

typedef struct {
    int n;                          /* n<=MAXNUM，为字典中元素的个数 */
    DicElement element[MAXNUM];
} SeqDictionary;

/* 在字典中用二分法查找关键码为key的元素 */
int binarySearch(SeqDictionary * pdic, KeyType key, int *position) {
    int low = 0, high = pdic->n-1, mid;

    while(low<=high) {
        mid = (low+high)/2;                   /* 当前检索的中间位置 */
        if(pdic->element[mid].key == key) {   /* 检索成功 */
            *position = mid;  return TRUE;
        }
        else if (pdic->element[mid].key > key) 
            high = mid-1;                     /* 要检索的元素在左半区 */
        else low = mid+1;                     /* 要检索的元素在右半区 */
    }
    *position=low;
    return FALSE;                            /* 检索失败 */
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
