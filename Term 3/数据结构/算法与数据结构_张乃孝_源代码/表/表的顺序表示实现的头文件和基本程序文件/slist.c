/* 线性表的顺序表示：函数实现*/

#define _CRT_SECURE_NO_WARNINGS 
/* SeqList.c*/
/*线性表的顺序表示：函数实现*/

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

PSeqList createNullSeq_String(int m ) {
/* 创建新的顺序表 */
    PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
  	if (palist!=NULL){
     palist->element = (DataType*)malloc(sizeof(DataType)*m);
 	 if (palist->element){
       palist->MAXNUM=m;
       palist ->n = 0;					/* 空表长度为0 */
       return (palist);
      }
   	else free(palist);
    }
    printf("Out of space!!\n");    	/* 存储分配失败 */
    return NULL;
}


int  isNullList_seq( PSeqList palist ) {
/*判别palist所指顺序表是否为空表。*/
    return ( palist->n == 0 );
}


int  locate_seq( PSeqList palist, DataType x ){
	int  q;
	for ( q=0; q<palist->n ; q++) if ( palist->element[q] == x)  return (q);
	return  (-1);
}

int insertPre_seq(PSeqList palist,int p,DataType x)  {
	int q;
	if ( palist->n >= palist-> MAXNUM ) {			/* 溢出 */
		printf("Overflow!\n");
		return ( 0 );
		}
	if ( isNullList_seq(palist) ) {			/*空顺序表插入 */
		palist->element[0] = x;					/* 插入元素x */
		palist->n = 1;				/* 元素个数为1 */
		return ( 1 );
		 }
	if (p<0  ||  p>palist->n  )	{  			/* 不存在下标为p的元素 */
		printf("Not exist! \n");  return (0 );
		}
	for(q=palist->n - 1; q>=p; q--)  /* 插入位置及之后的元素均后移一个位置 */
		palist->element[q+1] = palist->element[q];
	palist->element[p] = x;					/* 插入元素x */
	palist->n = palist->n + 1;				/* 元素个数加1 */
	return ( 1 );
}


int  deleteP_seq( PSeqList palist, int p )/* 在palist所指顺序表中删除下标为ｐ的元素 */
{
	int q;
	if (  p<0  ||  p>palist->n - 1 )	
		{
		   printf("Not exist!\n ");
		   return  (0);
		 }
	for(q=p; q<palist->n-1; q++) 	/* 被删除元素之后的元素均前移一个位置 */
		palist->element[q] = palist->element[q+1];
	palist->n = palist->n - 1;			/* 元素个数减1 */
	return ( 1 );
}

DataType retrive_seq(PSeqList list,int p)
{
	if(p>=0&&p<list->n)
		return(list->element[p]);
	return(-1);

}

void print_list(PSeqList llist)
{
	int i;

	for (i = 0; i<llist->n; i++)
		printf("%d ", llist->element[i]);
	printf("\n");

}




main()
{
	PSeqList palist= createNullSeq_String(11);
    DataType x;
	int i,p;
	/***for(p=0;p<10;p++)
	{
		scanf("%d ", &x);
		insertPre_seq( palist, p, x);

	}****/
	printf("请输入表中数据元素,以-1 结尾:");
	
	i = 0;
	while (1)
	{


		scanf("%d", &x);
		if (x == -1) break;
		insertPre_seq(palist, i, x);
		i++;
	}
	print_list(palist);
    getchar();
	
}
    






	
