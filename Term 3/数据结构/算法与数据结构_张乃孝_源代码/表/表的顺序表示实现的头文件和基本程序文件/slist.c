/* ���Ա��˳���ʾ������ʵ��*/

#define _CRT_SECURE_NO_WARNINGS 
/* SeqList.c*/
/*���Ա��˳���ʾ������ʵ��*/

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

PSeqList createNullSeq_String(int m ) {
/* �����µ�˳��� */
    PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
  	if (palist!=NULL){
     palist->element = (DataType*)malloc(sizeof(DataType)*m);
 	 if (palist->element){
       palist->MAXNUM=m;
       palist ->n = 0;					/* �ձ���Ϊ0 */
       return (palist);
      }
   	else free(palist);
    }
    printf("Out of space!!\n");    	/* �洢����ʧ�� */
    return NULL;
}


int  isNullList_seq( PSeqList palist ) {
/*�б�palist��ָ˳����Ƿ�Ϊ�ձ�*/
    return ( palist->n == 0 );
}


int  locate_seq( PSeqList palist, DataType x ){
	int  q;
	for ( q=0; q<palist->n ; q++) if ( palist->element[q] == x)  return (q);
	return  (-1);
}

int insertPre_seq(PSeqList palist,int p,DataType x)  {
	int q;
	if ( palist->n >= palist-> MAXNUM ) {			/* ��� */
		printf("Overflow!\n");
		return ( 0 );
		}
	if ( isNullList_seq(palist) ) {			/*��˳������ */
		palist->element[0] = x;					/* ����Ԫ��x */
		palist->n = 1;				/* Ԫ�ظ���Ϊ1 */
		return ( 1 );
		 }
	if (p<0  ||  p>palist->n  )	{  			/* �������±�Ϊp��Ԫ�� */
		printf("Not exist! \n");  return (0 );
		}
	for(q=palist->n - 1; q>=p; q--)  /* ����λ�ü�֮���Ԫ�ؾ�����һ��λ�� */
		palist->element[q+1] = palist->element[q];
	palist->element[p] = x;					/* ����Ԫ��x */
	palist->n = palist->n + 1;				/* Ԫ�ظ�����1 */
	return ( 1 );
}


int  deleteP_seq( PSeqList palist, int p )/* ��palist��ָ˳�����ɾ���±�Ϊ���Ԫ�� */
{
	int q;
	if (  p<0  ||  p>palist->n - 1 )	
		{
		   printf("Not exist!\n ");
		   return  (0);
		 }
	for(q=p; q<palist->n-1; q++) 	/* ��ɾ��Ԫ��֮���Ԫ�ؾ�ǰ��һ��λ�� */
		palist->element[q] = palist->element[q+1];
	palist->n = palist->n - 1;			/* Ԫ�ظ�����1 */
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
	printf("�������������Ԫ��,��-1 ��β:");
	
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
    






	
