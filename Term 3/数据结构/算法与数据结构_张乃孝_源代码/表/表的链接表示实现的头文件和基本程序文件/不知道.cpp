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

void PNode xun(LinkList palist)
{
	PNode q=palist->link;
	while(q->link!=NULL)
	q=q->link;
	return(q);
}
void LinkList insert_link(LinkList palist,LinkList pblist)
{
	PNode p=pblist->link;
	PNode q=xun(palist);
	for(p=pblist->link;p!=NULL;p=p->link)
	{
		if(locate_link(oalist,p->info)==NULL)
		{
			insertPost_link(palist,xun(palist),p->info);
			q=q->link;
		}
	}
	return palist;
}

int main()
{
	LinkList palist,pblist;
	int i,n;
	DataType x;
	palist=createNullList_link();
	pblist=createNullList_link();
	PNode p1=palist,p2=pblist;
	printf("�������Ա�1����-1��β��\n");
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)break;
		insertPost_link(palist,p1,x);
		p1=p1->link;
	}
	printf("�������Ա�2����-1��β��\n");
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)break;
		insertPost_link(palist,p1,x);
		p1=p1->link;
	}
	printflist(palist);
	printflist(pblist);
}
