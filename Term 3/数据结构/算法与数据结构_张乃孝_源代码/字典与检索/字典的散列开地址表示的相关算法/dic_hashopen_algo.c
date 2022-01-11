/* ���������ÿ���ַ��ʵ��ɢ�еļ����㷨*/

#include<stdio.h>

#define TRUE 1
#define FALSE 0

#define null    -1     /* nullΪ�ս���� */
#define REGION_LEN 13

typedef int KeyType;

typedef struct {
    KeyType key;                  /* �ֵ�Ԫ�صĹؼ����ֶ�     */
    /*DataType value;             /* �ֵ�Ԫ�ص������ֶ�    */
} DicElement;

typedef struct {
    int m;                   /* m=REGION_LEN��Ϊ�������򳤶� */
    DicElement element[REGION_LEN];
} HashDictionary;

int h(KeyType key){
    return key % REGION_LEN;
}

int linearSearch(HashDictionary * phash, KeyType key, int *position)  {
    int d = h(key), inc;                  /* dΪɢ�е�ַ��ɢ�к���Ϊh(key) */

    for (inc = 0; inc < phash->m; inc++) {
        if (phash->element[d].key == key) {
            *position = d;                /* �����ɹ� */
            return TRUE;
        }
        else if (phash->element[d].key == null) {
            *position = d;                /* ����ʧ�ܣ�Ҳ�ҵ�����λ�� */
            return FALSE;
        }
        d = (d+1) % phash->m;
    }

    *position = -1;                       /* ɢ�б���� */
    return FALSE;
}

int linearInsert(HashDictionary *phash, KeyType key) {
    int position;
    if(linearSearch(phash, key, &position) == TRUE )/* ���йؼ���Ϊkey�Ľ��*/
        printf("Find\n");
    else if(position != -1) {   
        phash->element[position].key = key; /* �����㣬��Ӧ��value�ֶθ�ֵ */
    }
    else  return FALSE;                    /* ɢ�б���� */

    return TRUE;
}

HashDictionary dic;

int main(){
    int i, position, key;
    dic.m = REGION_LEN;
    for (i = 0; i < REGION_LEN; i++)
        dic.element[i].key = null;
    while (1) {
        printf("Input 1 to insert element\n"
                "2 to search element\n"
                "else to exit\nWhat do you want to do?");
        scanf("%d",&i);
        if (i == 1){
            printf("Input the key you want to insert:");
            scanf("%d", &key);
            if (linearInsert(&dic, key) == FALSE)
                printf("There is no space!\n");
        }
        else if (i == 2){
            printf("Input the key you want to search:");
            scanf("%d", &key);
            if(linearSearch(&dic, key, &position) == TRUE)
                printf("It is the %dth element!\n", position+1);
            else printf("It is not in the dictionary!\n");
        }
        else break;
    }
    return 0;
}
			
