/* ���е�˳���ʾ�����ͺͺ������� */


//typedef int DataType;
#define MAXNUM 20  //���������Ԫ�ظ���
#define M 10
#define N 10
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x,y;            //�����λ��
     //��·������һ�����ڶ����е��±�
} DataType; 
struct  SeqQueue {	/* ˳��������Ͷ��� */
    int f, r;
    DataType q[MAXNUM];
};

typedef struct SeqQueue SeqQueue, *PSeqQueue;	/* ˳��������ͺ�ָ������ */

/*����һ���ն���*/
PSeqQueue createEmptyQueue_seq( void );

/*�ж����Ƿ�Ϊ�ն���*/
int isEmptyQueue_seq( PSeqQueue paqu );

/* �ڶ����в���һԪ��x */
void enQueue_seq( PSeqQueue paqu, DataType x );

/* ɾ������ͷ��Ԫ�� */
void deQueue_seq( PSeqQueue paqu );

/* �Էǿն���,�����ͷ��Ԫ�� */
DataType frontQueue_seq( PSeqQueue paqu );

