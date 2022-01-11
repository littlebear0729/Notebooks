/*ջ���ӱ�ʾ����������*/

#include<stdio.h>
#include<stdlib.h>

#include "lstack.h"

/*������ջ�ṹ�ռ䣬����һ������ջ������ָ�������ջ��ָ��*/
PLinkStack  createEmptyStack_link(void) {
    PLinkStack plstack;
    plstack = (PLinkStack )malloc( sizeof(struct LinkStack));
    if (plstack != NULL)
        plstack->top = NULL;
    else
        printf("Out of space! \n");    
    return plstack;
}

/*�е�����ʽջ�Ƿ�Ϊ��ջ*/
int  isEmptyStack_link( PLinkStack plstack ) {
    return plstack->top == NULL;
}

/* ��ջ��ѹ��һԪ��x */
void push_link( PLinkStack plstack, DataType x ) {	
    PNode  p;
    p = (PNode)malloc( sizeof( struct Node ) );
    if ( p == NULL  )
        printf("Out of space!\n");
    else {	
        p->info = x;
        p->link = plstack->top;
        plstack->top = p;
    }
}

/*��ջ*/
void  pop_link( PLinkStack plstack ) { 	  
    if( isEmptyStack_link( plstack ) )
        printf( "Empty stack pop.\n" );
    else {	
        PNode p = plstack->top;
        plstack->top = plstack->top->link;
        free(p);
    }
}

/* �Էǿ�ջ��ջ��Ԫ�� */
DataType top_link( PLinkStack plstack ) {
    return plstack->top->info;
}

