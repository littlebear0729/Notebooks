/*�ַ�����˳���ʾ*/

#include<stdio.h>
#include<stdlib.h>

#define  MAXNUM  80   	/* �����������ַ�������������Ҫ���� */
struct SeqString { 		/* ˳�򴮵����� */
    int   n;			/*���ĳ���n<MAXNUM */
    char  c[MAXNUM];
};
 
typedef  struct SeqString  *PSeqString;

/*������˳��*/
PSeqString createNullStr_seq( void ) { 
    PSeqString pstr = (PSeqString)malloc(sizeof(struct SeqString));	/* ���봮�ռ� */
    if (pstr == NULL)
        printf("Out of space!!\n");
    else
        pstr->n = 0;
    return (pstr);
}

/* ����һ���ַ�������C�Ĵ�s��ʼ���� */
PSeqString createStr_seq( char *s ) {
    char *p, *q; 
    PSeqString pstr = (PSeqString)malloc(sizeof(struct SeqString));	/* ���봮�ռ� */
    if (pstr == NULL) 
        printf("Out of space!!\n");
    else {  
        for ( p = q = pstr->c; *s != '\0' && p - q < MAXNUM; )
            *p++ = *s++;
        pstr->n = p - q;
    }

    return pstr;
}

/*�жϴ�s�Ƿ�Ϊ�մ�����Ϊ�մ����򷵻�1�����򷵻�0*/
int IsNullStr (PSeqString s) {
    return s->n == 0;
}

/*���ش�s�ĳ���*/
int length (PSeqString s) {
    return s->n;
}

/* ���s��ָ��˳���е�i(i>0)���ַ���ʼ����ȡj���ַ������ɵ��Ӵ� */
PSeqString subStr_seq(PSeqString s,int i,int j) {
    int k;
    PSeqString s1 = createNullStr_seq( );	 /* ����һ�մ� */
    if (s1==NULL) return (NULL);
    if ( i > 0 && i <= s->n && j > 0 ) {
        if ( s->n < i+j-1 )  j = s->n-i+1; /*����i��ʼȡ����j���ַ�,����ȡ������ȡ����*/ 
        for (k = 0; k < j; k++)
            s1->c[k] = s->c[i+k-1];
        s1->n = j;
    }
    return s1;
}

/*���ؽ���s1��s2ƴ����һ�𹹳�һ���´�*/
PSeqString concat (PSeqString s1, PSeqString s2 ) {
    PSeqString s;
    int k;
    if( s1->n + s2->n > MAXNUM) {
        printf("overflow\n");
        return NULL;
    }
    
    s = createNullStr_seq( );	/* ����һ�մ� */
    for(k = 0; k < s1->n; k++)
        s->c[k] = s1->c[k];
    for(k = s1->n; k < s1->n + s2->n; k++)
        s->c[k] = s2->c[k - s1->n];
    s->n = s1->n + s2->n;
    return s;
}

/* �����Ӵ�ƥ���㷨����p��ָ�Ĵ���t��ָ�Ĵ��е�һ�γ���ʱ,*/
/* p��ָ���ĵ�һ��Ԫ����t��ָ�Ĵ��е����(�����±�+1) */
int index0( PSeqString t, PSeqString p ) {
    int i = 0, j = 0;/*��ʼ��*/

    while (i < p->n && j < t->n)    /*�����Ƚ�*/
        if (p->c[i] == t->c[j]) { /* ����ƥ����һ���ַ� */
            i++; j++;
        }        
        else { /* �������Ӵ���i��jֵ���ݣ����¿�ʼ��һ��ƥ�� */
            j -= i - 1; i = 0;
        }

    if (i >= p->n) /* ƥ��ɹ�������p�е�һ���ַ���t�е���� */
        return( j - p->n + 1);
    else return 0;             /* ƥ��ʧ�� */
}

/*int index (s1,s2 )
�����s2��s1���Ӵ��������s2�ڴ�s1�е�һ�γ��ֵ�λ��. �μ�ģʽƥ��*/

/* ����next������next�ĵ�һ��Ԫ��next[0]�ĵ�ַ */
void makeNext(PSeqString p, int *next) {
    int i = 0,k = -1;   /* ��ʼ�� */
    next[0] = -1;          

    while (i < p->n-1) {            /* ����next[i+1] */
        while (k >= 0 && p->c[i] != p->c[k])/* �ҳ�p0~pi��������ͬ��ǰ��׺����k */
            k = next[k];
        i++; k++;
        if (p->c[i] == p->c[k])           /* ��дnext[i]��ͬʱ���Ǹ��� */
            next[i] = next[k];
        else next[i] = k;
    }
}

/* �޻��ݵ��Ӵ�ƥ���㷨����p��ָ�Ĵ���t��ָ�Ĵ��е�һ�γ��֡�*/
/* �г����Ƿ���p��ָ������Ԫ����t��ָ���е���ţ���1��ʼ����û��ʱ����0 */
int index(PSeqString t, PSeqString p) {
    int i = 0, j = 0;   /* ��ʼ�� */
    int next[MAXNUM];   /* �ڲ��������� */     

    makeNext(p, next);  /* ��ʲôʱ����next���飬���Կ��ǲ�ͬ��ʽ */ 
    while (i < p->n && j < t->n)         /*�����Ƚ�*/
        if ( i == -1 || p->c[i] == t->c[j] ) {  /* ����ƥ����һ�ַ� */
            i++; j++;
        } 
        else i = next[i];                       /* j���䣬i���� */

    if (i >= p->n)
        return( j - p->n + 1); /* ƥ��ɹ�������p�е�һ���ַ���t�е���� */
    else return 0;             /* ƥ��ʧ�� */
}

