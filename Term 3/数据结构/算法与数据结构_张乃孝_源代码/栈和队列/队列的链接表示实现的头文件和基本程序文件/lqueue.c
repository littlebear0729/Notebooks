/*�������ӱ�ʾ����������*/

#include<stdio.h>
#include<stdlib.h>

#include "lqueue.h"

/*����һ���ն���*/
PLinkQueue  createEmptyQueue_link( ) { 	
    PLinkQueue plqu = (PLinkQueue )malloc(sizeof(struct LinkQueue));
    if (plqu != NULL)
        plqu->f = plqu->r = NULL;
    else
        printf("Out of space!! \n");
  		
    return (plqu);
}

/*�ж����ӱ�ʾ�����Ƿ�Ϊ�ն���*/ 
int  isEmptyQueue_link( PLinkQueue plqu ) {
    return (plqu->f == NULL);
}


/*������*/
void  enQueue_link( PLinkQueue plqu, DataType x) { 
    PNode p = (PNode )malloc( sizeof( struct Node ) );
    if ( p == NULL  )
        printf("Out of space!");
    else { 
        p->info = x;
        p->link = NULL;
        if (plqu->f == NULL)
            plqu->f = p;
        else
            plqu->r->link = p;

        plqu->r = p;
    }
}

/*������*/
void  deQueue_link( PLinkQueue plqu ) { 
    PNode   p;
    if( plqu->f == NULL )
        printf( "Empty queue.\n " );
    else { 
        p = plqu->f;
        plqu->f = plqu->f->link;
        free(p);
    }
}

/* �ڷǿն��������ͷԪ�� */
DataType  frontQueue_link( PLinkQueue plqu ) { 
    return (plqu->f->info);
}

