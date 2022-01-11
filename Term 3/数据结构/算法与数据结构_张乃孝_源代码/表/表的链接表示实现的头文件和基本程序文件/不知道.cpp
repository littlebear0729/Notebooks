#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "llist.h"


LinkList  createNullList_link( void )
/* 创建一个带头结点的空链表 */
{  
	LinkList llist;
	llist = (LinkList)malloc( sizeof( struct Node ) );		/* 申请表头结点空间 */
    if( llist != NULL )
			llist->link = NULL;
	return (llist);
}

int insert_link(LinkList llist, int i, DataType x)
/* 在llist带头结点的单链表中下标为i的(第i+1个)结点前插入元素x */
{ 
	PNode p,q;
 	int j;
 	p = llist;
 	j = 0;
 	while (p!=NULL && j<i)	{/* 找下标为i-1的(第i个)结点 */
		p=p->link;  j++;
	 }
	if (j!=i){
		printf("The value of i=%d is not reasonble.\n",i);
		return(0);
		}
	q = (PNode)malloc( sizeof( struct Node ) );	/* 申请新结点 */
	if( q == NULL ){
		printf( "Out of space!!!\n" );
		return(0);
		}
	else{
		/* 插入链表中 */
		q->info = x;
		q->link = p->link;
		p->link = q;							/* 注意该句必须在上句后执行 */
		return(1);
		}
}

int  insertPost_link(LinkList	llist, PNode p, DataType	x) {
	PNode  q = (PNode)malloc(sizeof(struct Node));	/*申请新结点*/ 
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
	printf("建立线性表1，以-1结尾：\n");
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)break;
		insertPost_link(palist,p1,x);
		p1=p1->link;
	}
	printf("建立线性表2，以-1结尾：\n");
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
