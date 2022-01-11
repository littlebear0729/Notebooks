/* 本程序提供了用顺序表实现字典的存储表示定义*/
#include <stdlib.h>
#include <stdio.h>

#define MAXNUM 100

typedef char KeyType;

typedef int DataType;

typedef struct {
    KeyType key;                  /* 字典元素的关键码字段     */
    DataType value;             /* 字典元素的属性字段    */
} DicElement;

typedef struct {
    int n;                          /* n<=MAXNUM，为字典中元素的个数 */
    DicElement element[MAXNUM];
} SeqDictionary;

SeqDictionary createSeqDic() {
    SeqDictionary s;
    s.n = 0;
    int n, i;
    printf("how many elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("input key, value: ");
        char k;
        int v;
        scanf(" %c, %d", &k, &v);
        s.n++;
        s.element[i].key = k;
        s.element[i].value = v;
    }
    return s;
}

void printDic(SeqDictionary s) {
    int i;
    for (i = 0; i < s.n; i++) {
        printf("key: %c, value: %d\n", s.element[i].key, s.element[i].value);
    }
}

DataType queryDic(SeqDictionary s, KeyType k) {
    int i;
    for (i = 0; i < s.n; i++) {
        if (k == s.element[i].key) {
            printf("Value found!\n");
            return s.element[i].value;
        }
    }
    return -1;
}

int main() {
    SeqDictionary s = createSeqDic();
    printDic(s);
    printf("input query key: ");
    KeyType k;
    scanf(" %c", &k);
    DataType v = queryDic(s, k);
    if (v != -1) {
        printf("Key: %c, Value: %d", k, v);
    } else {
        printf("Key not found!");
    }
    return 0;
}
