#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#define MMAXNUM 100
#include "sstack.h"

PSeqStack  createEmptyStack_seq(  ) {  
    PSeqStack pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if (pastack==NULL)
        printf("Out of space!! \n");
    else
        pastack->t = -1;
    return pastack;
}

/*�ж�pastack��ָ��ջ�Ƿ�Ϊ��ջ����pastack��ָ��ջΪ��ջʱ���򷵻�1�����򷵻�0*/
int  isEmptyStack_seq( PSeqStack pastack ) {
    return pastack->t == -1;
}

/* ��ջ��ѹ��һԪ��x */
void  push_seq( PSeqStack pastack, DataType x ) {  
    if( pastack->t >= MAXNUM - 1  )
        printf( "Stack Overflow! \n" );
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
DataType top_seq( PSeqStack pastack ) {
    return pastack->s[pastack->t];
}



int conversion(char*s)
{
	int m=0;
	int t=1;
	int r=0;
	DataType x;
	PSeqStack  pastack=createEmptyStack_seq(   );
	while(s[m]!='\0')
	{
		x=s[m]-'0';
		push_seq(   pastack,  x );
		m=m+1;

	}
     
	while(pastack->t!=-1)
	{
		
		r=t* top_seq(   pastack )+r;
		pop_seq(   pastack ) ;
		t=t*10;

	}
	return(r);


 

}
Fibonacci(int n )
{
	int result=0; int x;
	PSeqStack s=createEmptyStack_seq();
	push_seq(s,n);
	while(!isEmptyStack_seq(s))
	{
		x=top_seq( s );
		pop_seq( s ) ;
		if(x==1||x==0)
		result=result+x;
		else
		{
			push_seq(s,x-1);
			push_seq(s,x-2);
			//printf("Move from %c---> to %c\n",A,C);
		}
	}
		return(result) ;
		
	
}
void main()
{
	int n=Fibonacci(10 );
	printf("n=%d",n);
	getchar();
}

