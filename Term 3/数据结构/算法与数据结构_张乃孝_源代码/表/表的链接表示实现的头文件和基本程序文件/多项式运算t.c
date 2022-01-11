/* ���Ա�ĵ������ʾ������ʵ��*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* �������ӱ�Ԫ�����͡�Ӧ������Ҫ���� */
typedef struct{float f;int n;}  DataType;

struct Node;					  /* ������������ */
typedef  struct Node  *PNode;	  /* ���ָ������ */
typedef  struct Node  *LinkList;  /* ���������� */

struct  Node { 					  /* ��������ṹ */
    DataType  info;
    PNode     link;
};

/* ����һ����ͷ���Ŀ����� */
LinkList createNullList_link( void );

/* ��llist��ͷ���ĵ��������±�Ϊi��(��i+1��)���ǰ����Ԫ��x */
int insert_link(LinkList llist, int i, DataType x);

/* ��llist����ͷ���ĵ�������ɾ����һ��ֵΪx�Ľ�� */
int  delete_link( LinkList llist, DataType x );

/* ��llist����ͷ���ĵ��������ҵ�һ��ֵΪx�Ľ��洢λ�� */
PNode  locate_link(LinkList llist, DataType x );

/* �ڴ���ͷ���ĵ�����llist�����±�Ϊi��(��i+1��)���Ĵ洢λ�� */
/* ���������±�Ϊi��(��i+1��)Ԫ��ʱ������ֵΪNULL */
PNode  find_link( LinkList llist, int i );

/* �ж�llist����ͷ���ĵ������Ƿ��ǿ����� */
int  isNullList_link( LinkList llist);


/* ����һ����ͷ���Ŀ����� */
LinkList  createNullList_link( void ) {   
    LinkList llist;
    llist = (LinkList)malloc( sizeof( struct Node ) );	/* �����ͷ���ռ� */
    if( llist != NULL ) llist->link = NULL;
    return llist;
}

/* ��llist��ͷ���ĵ��������±�Ϊi��(��i+1��)���ǰ����Ԫ��x */
int insert_link(LinkList llist, int i, DataType x) { 
    PNode p = llist, q;
    int j;
    for (j = 0 ; p != NULL && j < i; j++)		/* ���±�Ϊi-1��(��i��)��� */
        p = p->link;
 	  
    if (j != i) {								/* i<1���ߴ��ڱ� */
        printf("Index of link-list is out of range.\n");
  	 	return 0;
    }
 	  
    q = (PNode)malloc( sizeof( struct Node ) );	/* �����½�� */
    if( q == NULL ) { 
        printf( "Out of space!\n" );
        return 0;
    }
    									/* ���������� */
    q->info = x;
    q->link = p->link;
    p->link = q;						/* ע��þ�������Ͼ��ִ�� */
    return 1 ;
}
int insertPost_link(LinkList llist,PNode p , DataType x) { 
    PNode q = (PNode)malloc( sizeof( struct Node ) );	/* �����½�� */
    if( q == NULL ) { 
        printf( "Out of space!\n" );
        return 0;
    }
    									/* ���������� */
    q->info = x;
    q->link = p->link;
    p->link = q;						/* ע��þ�������Ͼ��ִ�� */
    return 1 ;
}

int insertEnd_link(LinkList llist,  DataType x) { 
    PNode q =llist;
    while(q->link!=NULL)
    q=q->link ;
    insertPost_link(  llist,q ,   x);
}
 
PNode locatePre_link( LinkList llist, PNode p ) { 
    PNode p1;
    p1=llist;
    
    while ( p1!=NULL&&p1->link!=p)
        p = p->link;
    return p1;
}

 
/* �ж�llist����ͷ���ĵ������Ƿ��ǿ����� */
int  isNullList_link( LinkList llist) {     
    return llist == NULL || llist->link == NULL;
    
    
}

int length(LinkList list)
{
	int n=0;
	PNode p=list->link;
	while(!p)
	{n++;p=p->link;
	}
	return n;
	
} 
DataType retrive(LinkList llist,int i)
{
	int j;
	PNode p=llist;
	for(j=1;j<=i;j++)
	p=p->link;
	return p->info;
	
}
void ADD(LinkList f,LinkList g,LinkList s) 
{  
	 DataType  a,b,x; 
     int i=1,j=1; 
     while(i<=length(f) && j<=length(g) ) 
	 {     
		 a=retrive(f,i); b=retrive(g,j); 
         if(a.n == b.n) 
			 {      
				     x.f=a.f+b.f; 
                     if(x.f!=0)  
						 insertEnd_link( s,  x) ; 
					 i++;  j++; 
			} 
            else {
				if(a.n > b.n) { insertEnd_link(s,  a) ; i++ ; }  
				else{ insertEnd_link(s,  b) ; j++;} 
			 } 
		for(;i<=length(f);i++) {
			 a = retrive (f  , i); 
			 insertEnd_link(s,  a) ;
		 } 
        for(;j<=length(g) ; j++) {
		     b=retrive (g,j);  insertEnd_link( s,b);  
	     } 
      }  
}

//printf	
	
	
	
	
	  
main(){
	int i, j; int n;
	LinkList f=createNullList_link();
	LinkList g=createNullList_link();
	LinkList s=createNullList_link();
	printf("�����һ������ʽ������");scanf("%d", &n);
	printf("�����һ������ʽ,��ָ���Ӹߵ��͵Ĵ���");
	
	DataType x;
	for(i=1;i<=n;i++) 
	{
		scanf("%f %d",&x.f ,&x.n);
		insertEnd_link(  f,    x);
		
		
		
	}
	printf("����ڶ�������ʽ������"); scanf("%d", &n);
	printf("����ڶ�������ʽ,��ָ���Ӹߵ��͵Ĵ���");
	for(i=1;i<=n;i++) 
	{
		scanf("%f %d",&x.f ,&x.n);
		insertEnd_link(  g,    x);
		
		
		 
	}
	ADD(f,g,s);
	getchar();
}
