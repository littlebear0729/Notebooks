/* 线性表的单链表表示*/
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


int deleteV_link(LinkList llist, DataType x) 
{    

    PNode p, q;	
    p = llist;
    if(p==NULL) return 0 ;
    while( p->link != NULL && p->link->info != x )
      p = p->link;	/*找值为x的结点的前驱结点的存储位置 */     
    if( p->link == NULL ) {	/* 没找到值为x的结点 */
        printf("Not exist!\n ");	
		return 0 ;
		}
    else {
    	 q = p->link;
         p->link = q->link;  free( q ); return 1 ;
    	} 

}


PNode  locate_link(LinkList llist, DataType x )
	/* 在llist带有头结点的单链表中找第一个值为x的结点存储位置 */
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
		printf("\n第 %d 个数据元素为:%d",i,list->link->info);
		list=list->link;
		i++;
	}
	printf("\n");



}

int  isNullList_link(LinkList llist)
/* 判断llist带有头结点的单链表是否是空链表 */
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
	printf("建立线性表,请输入表中数据元素,以-1 结尾:");   
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



 

