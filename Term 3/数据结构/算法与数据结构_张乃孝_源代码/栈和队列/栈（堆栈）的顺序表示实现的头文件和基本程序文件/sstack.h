/* ˳��ջ��ʾ�����ͺͽ��溯������ */

enum { MAXNUM = 20    /* ջ�����Ԫ�ظ�����Ӧ������Ҫ���� */
};
     
typedef int DataType; /* ջ��Ԫ�����ͣ�Ӧ������Ҫ���� */

struct SeqStack {	  /* ˳��ջ���Ͷ��� */
    int  t; 		  /* ջ��λ��ָʾ */
    DataType  s[MAXNUM];
};

typedef  struct SeqStack SeqSack, *PSeqStack;	/* ˳��ջ���ͺ�ָ������ */ 

/*����һ����ջ;Ϊջ�ṹ����ռ䣬����ջ��������ֵΪ-1*/
PSeqStack  createEmptyStack_seq( void );

/*�ж�pastack��ָ��ջ�Ƿ�Ϊ��ջ����pastack��ָ��ջΪ��ջʱ���򷵻�1�����򷵻�0*/
int  isEmptyStack_seq( PSeqStack pastack );

/* ��ջ��ѹ��һԪ��x */
void  push_seq( PSeqStack pastack, DataType x );

/* ɾ��ջ��Ԫ�� */
void  pop_seq( PSeqStack pastack );

/* ��pastack��ָ��ջ��Ϊ��ջʱ����ջ��Ԫ�ص�ֵ */
DataType  top_seq( PSeqStack pastack );

