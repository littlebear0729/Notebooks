/* �򻯱�������ķǵݹ��㷨*/


#include<stdio.h>
#include<stdlib.h>
#define MAXNUM     20
#define TRUE 1
#define FALSE 0

struct  NodeBag {  /* ջ��Ԫ�صĶ��� */
    int  s , n ;
    int  r ;          /* r��ֵΪ1,2,3 */
    int  k;
};

typedef struct NodeBag DataType;

struct SeqStack {	  		/* ˳��ջ���Ͷ��� */
    int  t; 			/* ָʾջ��λ�� */
    DataType  s[MAXNUM];
};

typedef struct SeqStack *PSeqStack;	/* ˳��ջ���͵�ָ������ */

PSeqStack  createEmptyStack_seq( void ) {
    PSeqStack pastack;
    pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if (pastack==NULL)
        printf("Out of space!! \n");
    else
        pastack->t=-1;
    return  (pastack);
}

/* ��ջ��ѹ��һԪ��x */
void  push_seq( PSeqStack pastack, DataType x ) {  
    if( pastack->t >= MAXNUM - 1  )
        printf( "Overflow! \n" );
    else {
        pastack->t++;
        pastack->s[pastack->t] = x;
    }
}

/* ɾ��ջ��Ԫ�� */
void  pop_seq( PSeqStack pastack ) {  	
    if (pastack->t == -1 )
        printf( "Underflow!\n" );
    else
        pastack->t--;
}

/* ��pastack��ָ��ջ��Ϊ��ջʱ����ջ��Ԫ�ص�ֵ */
DataType  top_seq( PSeqStack pastack ) {
    return pastack->s[pastack->t];
}

int nknap(int s, int n, int w[]) { 
    struct NodeBag  x; 
    PSeqStack st;   
    int k;
    st = createEmptyStack_seq( );        /* entry0:  ��ʼ������� */
    x.s = s;     x.n = n;    x.r = 1;  
    push_seq(st,x);
entry1:                    /* �ݹ������� */
    x = top_seq(st);
    pop_seq(st);     /* �ú����������ӽ���һ��push_seq��������Ϊ������޸�ջ��Ԫ�� */
    if (x.s == 0) {  
        x.k = TRUE;       
        push_seq(st,x);         
        goto exit2; 
    }
    else if (x.s<0 || (x.s>0 && x.n<1)) {
        x.k = FALSE;
        push_seq(st,x);
        goto exit2;
    }
    else {
        push_seq(st,x);  /* ���ڴ˴���Ҫ��һ�����µݹ飬�������ٴ���ջ */
        x.s = x.s - w[x.n-1];   
        x.n = x.n - 1;     
        x.r = 2;  
        push_seq(st, x);   
        goto entry1;
    }
exit2:                 /* ���ش��� */
    x = top_seq(st);
    pop_seq(st);
    switch (x.r) { 
    case 1:
        free(st);
        return(x.k);
    case 2: goto L3;
    case 3: goto L4; 
    }

L3:                 /* ��������1 */
    if (x.k == TRUE) { 
        x = top_seq(st);
        pop_seq(st); 
        x.k = TRUE;     
        push_seq(st,x);
        printf("result n=%d , w=%d \n", x.n, w[x.n-1]); 
        goto  exit2; 
    }
    else {  
        x = top_seq(st);
        x.s = x.s; 
        x.n = x.n - 1; 
        x.r = 3;  
        push_seq(st,x); 
        goto  entry1; 
    }
L4:                         /* ��������2 */
    k = x.k; 
    x = top_seq(st); 
    pop_seq(st);   
    x.k = k;   
    push_seq(st,x);   
    goto  exit2;
}

int main() {
    int* w;
    int s = 0, n = 0, result = 0, i = 0;
	
    printf("please  input s = ");/*����s*/
    scanf("%d", &s);
    printf("please  input n = ");/*����n*/
    scanf("%d", &n);
    w = (int*)malloc(n*sizeof(int));
    printf("please input the %d numbers(weight):\n", n);/*��������*/
    for (i = 0; i < n; i++)
        scanf("%d", w+i);
    result = nknap(s,n, w);
    if (result == 0)
        printf("no solution!\n");
    return 0;
}

