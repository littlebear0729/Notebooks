/* ���������ÿ���ַ�������ײ��ɢ�б�ʾ����,
�ṩ���ֵ��һЩ��������*/

#include<stdio.h>

#define null -1                 /* nullΪ�ս���� */
#define TRUE 1
#define FALSE 0

#define REGION_LEN 13

typedef int KeyType;
typedef int DataType;

typedef struct {
    KeyType key;                /* �ֵ�Ԫ�صĹؼ����ֶ�     */
    DataType value;             /* �ֵ�Ԫ�ص������ֶ�    */
} DicElement;

typedef struct {
    int m;                      /* m=REGION_LEN��Ϊ�������򳤶� */
    DicElement element[REGION_LEN];
} HashDictionary;

int h(KeyType key){
    return key % REGION_LEN;
}

int linearSearch(HashDictionary * phash, KeyType key, int *position) {
    int inc, d = h(key);                    /* dΪɢ�е�ַ��ɢ�к���Ϊh(key) */
    for (inc = 0; inc < phash->m; inc++) {
        if (phash->element[d].key == key) { /* �����ɹ� */
            *position = d;                
            return TRUE;
        }
        else if (phash->element[d].key == null) {/* ����ʧ�ܣ��ҵ�����λ�� */
            *position = d;                              
            return FALSE;
        }
        d = (d+1) % phash->m;
    }

    *position = -1;                         /* ɢ�б���� */

    return FALSE;
}

int linearInsert(HashDictionary *phash, KeyType key) {
    int position;
    if(linearSearch(phash, key, &position) == TRUE )/* ɢ�б������йؼ���Ϊkey �Ľ��*/
        printf("Find\n");
    else if(position != -1)    
        phash->element[position].key = key;     /* �����㣬���Զ�value�ֶεĸ�ֵ */
    else return FALSE;                          /* ɢ�б���� */
    return TRUE;
}


int main(){
    return 0;
}
			
