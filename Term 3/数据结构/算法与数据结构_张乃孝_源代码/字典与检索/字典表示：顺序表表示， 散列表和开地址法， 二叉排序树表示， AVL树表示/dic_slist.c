/* �������ṩ����˳���ʵ���ֵ�Ĵ洢��ʾ����*/

#define MAXNUM 100

typedef int KeyType ;

typedef int DataType;

typedef struct {
    KeyType key;                  /* �ֵ�Ԫ�صĹؼ����ֶ�     */
    DataType value;             /* �ֵ�Ԫ�ص������ֶ�    */
} DicElement;

typedef struct {
    int n;                          /* n<=MAXNUM��Ϊ�ֵ���Ԫ�صĸ��� */
    DicElement element[MAXNUM];
} SeqDictionary;


int main(){
    return 0;
}
