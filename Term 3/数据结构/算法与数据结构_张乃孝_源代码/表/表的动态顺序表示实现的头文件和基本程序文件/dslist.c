/* ���Ա��˳���ʾ������ʵ��*/

#include <stdio.h>
#include <stdlib.h>

#include "dslist.h"

PSeqList createNullList_seq( void ) { 	
    PSeqList lp = (PSeqList)malloc(sizeof(struct SeqList));
    if (lp != NULL) {
        lp->elems = (DataType*)malloc(sizeof(DataType)*NBASE);
        if (lp->elems) {
            lp->n = 0;          /*�ձ���Ϊ0 */
            lp->nmax = NBASE;
            return lp;
        }
        else free(lp);
    }
    printf("Out of space!\n");  /*�洢����ʧ��*/
    return NULL;
}

/*��palist��ָ˳������±�Ϊp��Ԫ��֮ǰ����Ԫ��x*/
int insert_seq(PSeqList lp, int p, DataType x) {  
    int q;
    if ( p < 0 || p > lp->n ) { /* �������±�Ϊp��Ԫ�� */
        printf("Index of seq-list is out of range! \n");
        return FALSE;
    }
    if ( lp->n == lp->nmax ) { 	/* �洢���� */
        DataType *dp =          /* �洢������һ�� */
            (DataType*)realloc(lp->elems, lp->nmax*2*sizeof(DataType));
        if (dp == NULL) { 		/* �ռ�ľ���ԭ��Ԫ�ػ���ԭ�� */
            printf("Seq-list overflow!\n");
            return FALSE;
        }
        lp->elems = dp;
        lp->nmax *= 2;
    }
    
    for(q = lp->n - 1; q >= p; q--)  	/* ����λ�ü�֮���Ԫ�ؾ�����һ��λ�� */
        lp->elems[q+1] = lp->elems[q];
        
    lp->elems[p] = x;				/* ����Ԫ��x */
    lp->n++;			/* Ԫ�ظ�����1 */
    return TRUE;
}

/*��lp��ָ˳�����ɾ���±�Ϊ���Ԫ��*/
int delete_seq( PSeqList lp, int p ) { 
    int q;
    if (p < 0 || p > lp->n-1 ) { 	/* �������±�Ϊp��Ԫ�� */
        printf("Index of seq-list is out of range!\n ");
        return FALSE;
    }
	
    for(q = p; q < lp->n - 1; q++) 	/* ��ɾ��Ԫ��֮���Ԫ�ؾ�ǰ��һ��λ�� */
	    lp->elems[q] = lp->elems[q+1];
	    
    lp->n--;			/* Ԫ�ظ�����1 */
    return TRUE;
}

/*��x��lp��ָ˳����е��±�*/
int locate_seq(PSeqList lp, DataType x) { 
    int q;
    for ( q = 0; q < lp->n; q++ )
        if (lp->elems[q] == x) return q;
    return  -1;
}

/* ��lp��ָ˳������±�Ϊp��Ԫ��ֵ */
DataType  retrieve_seq( PSeqList lp, int p ) { 
    if ( p >= 0 && p < lp->n )	/* �����±�Ϊp��Ԫ�� */
        return lp->elems[p];
    	
    printf("Index of seq-list is out of range.\n ");
    return SPECIAL;                 /* ����һ��˳�����û�е�����ֵ */
}

int isNullList_seq( PSeqList lp ) {
    return lp->n == 0;
}


