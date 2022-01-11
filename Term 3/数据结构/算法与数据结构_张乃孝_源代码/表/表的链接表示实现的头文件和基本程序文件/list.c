/* ���Ա�ĵ������ʾ*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "llist.h"


LinkList  createNullList_link( void )
/* ����һ����ͷ���Ŀ����� */
{  
	LinkList llist;
	llist = (LinkList)malloc( sizeof( struct Node ) );		/* �����ͷ���ռ� */
    if( llist != NULL )
			llist->link = NULL;
	return (llist);
}

int insert_link(LinkList llist, int i, DataType x)
/* ��llist��ͷ���ĵ��������±�Ϊi��(��i+1��)���ǰ����Ԫ��x */
{ 
	PNode p,q;
 	int j;
 	p = llist;
 	j = 0;
 	while (p!=NULL && j<i)	{/* ���±�Ϊi-1��(��i��)��� */
		p=p->link;  j++;
	 }
	if (j!=i){
		printf("The value of i=%d is not reasonble.\n",i);
		return(0);
		}
	q = (PNode)malloc( sizeof( struct Node ) );	/* �����½�� */
	if( q == NULL ){
		printf( "Out of space!!!\n" );
		return(0);
		}
	else{
		/* ���������� */
		q->info = x;
		q->link = p->link;
		p->link = q;							/* ע��þ�������Ͼ��ִ�� */
		return(1);
		}
}
int  insertPost_link(LinkList	llist, PNode p, DataType	x) {
	PNode  q = (PNode)malloc(sizeof(struct Node));	/*�����½��*/ 
	if (q == NULL) {
		printf("Out of Space!\n");  
		return 0;
	}
	else {
		q->info = x;
		q->link = p->link;  p->link = q;  return 1;
	}
}


int deleteV_link(LinkList llist, DataType x) 
{    

    PNode p, q;	
    p = llist;
    if(p==NULL) return 0 ;
    while( p->link != NULL && p->link->info != x )
      p = p->link;	/*��ֵΪx�Ľ���ǰ�����Ĵ洢λ�� */     
    if( p->link == NULL ) {	/* û�ҵ�ֵΪx�Ľ�� */
        printf("Not exist!\n ");	
		return 0 ;
		}
    else {
    	 q = p->link;
         p->link = q->link;  free( q ); return 1 ;
    	} 

}


PNode  locate_link(LinkList llist, DataType x )
	/* ��llist����ͷ���ĵ��������ҵ�һ��ֵΪx�Ľ��洢λ�� */
{
	PNode p;
	if (llist==NULL)  return(NULL);
	p = llist->link;
	while( p != NULL && p->info != x )
		p = p->link;
	return (p);
}


 
int length_link(LinkList llist)
{
	int i=0;
	LinkList list=llist;
	while(list->link!=NULL)
	{
		list=list->link;
		i++;
	}
	return i;


}



void printflist(LinkList llist)
{
	int i=1;
	LinkList list;
	list=llist;
	while(list->link!=NULL)
	{
		printf("\n�� %d ������Ԫ��Ϊ:%d",i,list->link->info);
		list=list->link;
		i++;
	}
	printf("\n");



}

int  isNullList_link(LinkList llist)
/* �ж�llist����ͷ���ĵ������Ƿ��ǿ����� */
{
	if (llist == NULL)
		return(1);
	else
		return (llist->link == NULL);

}

PNode	locatePre_link (LinkList llist, PNode p)
 { 
  PNode p1;
  if(llist==NULL) return NULL;  p1=llist;
  while(p1!=NULL && p1->link!=p) 
    p1=p1->link; 
  return p1;
}

int main()
{
	LinkList list;
	int i,n;
	//int Action_choice;
	DataType x;
	
	list=  createNullList_link(  );
	PNode p=list;
	printf("�������Ա�,�������������Ԫ��,��-1 ��β:");   
	i=0;
	while(1)
	{
	  

	scanf("%d",&x);
	if(x==-1) break;
	insertPost_link(list,p ,x);
	p=p->link;
	}
	printflist(list);  
    printf("\n\n\n");
	

	
}



 

