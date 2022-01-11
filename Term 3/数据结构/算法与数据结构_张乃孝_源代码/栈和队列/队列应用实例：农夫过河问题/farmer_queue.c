/* �ö��н��ũ�����������㷨*/


#include<stdio.h>
#include<stdlib.h>

#define  MAXNUM   20

typedef int DataType;
struct  SeqQueue {		/* ˳��������Ͷ��� */
    int  f, r;
    DataType q[MAXNUM];
};

typedef struct SeqQueue *PSeqQueue;	/* ˳��������͵�ָ������ */

PSeqQueue createEmptyQueue_seq( void ) {  
    PSeqQueue paqu = (PSeqQueue)malloc(sizeof(struct SeqQueue));
    if (paqu == NULL)
        printf("Out of space!! \n");
    else
        paqu->f = paqu->r = 0;
    return (paqu);
}

int isEmptyQueue_seq( PSeqQueue paqu ) {
    return paqu->f == paqu->r;
}

/* �ڶ����в���һԪ��x */
void  enQueue_seq( PSeqQueue paqu, DataType x ) {
    if ( (paqu->r + 1) % MAXNUM == paqu->f  )
        printf( "Full queue.\n" );
    else {
        paqu->q[paqu->r] = x;
        paqu->r = (paqu->r + 1) % MAXNUM;
    }
}

/* ɾ������ͷ��Ԫ�� */
void  deQueue_seq( PSeqQueue paqu ) {
    if( paqu->f == paqu->r )
        printf( "Empty Queue.\n" );
    else
        paqu->f = (paqu->f + 1) % MAXNUM;
}

/* �Էǿն���,�����ͷ��Ԫ�� */
DataType  frontQueue_seq( PSeqQueue paqu ) {
    return (paqu->q[paqu->f]);
}

int farmer(int location) {
    return 0 != (location & 0x08);
}

int wolf(int location) {
    return 0 != (location & 0x04);
}

int cabbage(int location) {
    return 0 != (location & 0x02);
}

int goat(int location) {
    return 0 !=(location & 0x01);
}

/* ��״̬��ȫ�򷵻�true */
int safe(int location) {
    /* ��԰ײ� */
    if ((goat(location) == cabbage(location)) &&  
          (goat(location) != farmer(location)) )  
        return 0;
    /* �ǳ��� */
    if ((goat(location) == wolf(location)) &&  
          (goat(location) != farmer(location)))  
        return 0;
    return 1;	 /* ����״̬�ǰ�ȫ�� */
}


void farmerProblem( ) {
    int movers, i, location, newlocation;
    int route[16];        /*��¼�ѿ��ǵ�״̬·��*/
    PSeqQueue moveTo; 
    /*׼����ֵ*/
    moveTo = createEmptyQueue_seq( );
    enQueue_seq(moveTo, 0x00);
    for (i = 0; i < 16; i++) route[i] = -1;
    route[0]=0;
    
    /*��ʼ�ƶ�*/
    while (!isEmptyQueue_seq(moveTo)&&(route[15] == -1)) {
        /*�õ����ڵ�״̬*/
        location = frontQueue_seq(moveTo);
        deQueue_seq(moveTo);
        for (movers = 1; movers <= 8; movers <<= 1) {
            /* ũ���������ƶ�����ũ���ƶ���Ҳֻ������ũ��ͬ��Ķ��� */
            if ((0 != (location & 0x08)) == (0 != (location & movers))) {
                newlocation = location^(0x08|movers);
                if (safe(newlocation) && (route[newlocation] == -1)) { 
                    route[newlocation] = location;
                    enQueue_seq(moveTo, newlocation);
                }
            }
        }
    }
    
    /* ��ӡ��·�� */
    if(route[15] != -1) {
        printf("The reverse path is : \n");
        for(location = 15; location >= 0; location = route[location]) { 
            printf("The location is : %d\n",location);
            if (location == 0) return;
        }
    }
    else 
        printf("No solution.\n");
}


int main() {
    farmerProblem( );
    return 0;
}
