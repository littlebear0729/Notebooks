/* �û��ݷ������ʿ����������㷨*/


#include<stdio.h>
#include<stdlib.h>

#define NUM 6			/*����Ϊn*n��*/

#define MAXNUM NUM * NUM        /* ջ�����Ԫ�ظ��� */

struct Node {
    int x, y, d;
};

typedef struct Node DataType;

struct  SeqStack {	  		/* ˳��ջ���Ͷ��� */
    int t; 			/* ָʾջ��λ�� */
    DataType  s[MAXNUM];
};

typedef  struct SeqStack  *PSeqStack;	/* ˳��ջ���͵�ָ������ */

PSeqStack  createEmptyStack_seq( void ) {
    PSeqStack pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if (pastack==NULL)
        printf("Out of space!! \n");
    else
        pastack->t = -1;
    return  pastack;
}

int  isEmptyStack_seq( PSeqStack pastack ) {
    return pastack->t == -1;
}

/* ��ջ��ѹ��һԪ��x */
void  push_seq( PSeqStack pastack, DataType x ) {
    if( pastack->t >= MAXNUM - 1  )
        printf( "Overflow! \n" );
    else {
        pastack->t++;
        pastack->s[pastack->t] = x;
    }
}

/* ɾ��ջ��Ԫ�� */
void  pop_seq( PSeqStack pastack ) {
  	if (pastack->t == -1 )
        printf( "Underflow!\n" );
    else
        pastack->t--;
}

/* ��pastack��ָ��ջ��Ϊ��ջʱ����ջ��Ԫ�ص�ֵ */
DataType top_seq( PSeqStack pastack ) {
    return (pastack->s[pastack->t]);
}


int area[NUM][NUM];			/*n*n����*/

/*�����λ��(i,j)�˸����������*/
int direction[8][2] = {-1,2,-2,1,-2,-1,-1,-2,1,-2,2,-1,2,1,1,2};

int inarea(int x, int y) { /*����(x,y)��������*/
    return x >= 0 && x < NUM && y >= 0 && y < NUM;
}

void init_area(int n, int a[][n]) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            a[i][j] = 0;/*��ʼ��,0��ʾδ������*/
}

void path(int x0, int y0) { /*��ʼλ��Ϊ(x0,y0)*/
    int i, j, k;
    int g, h;
    int step;/*��������������*/
    DataType element;
    PSeqStack st = createEmptyStack_seq( );
    init_area(NUM, area);

    area[x0][y0] = 1; /*1��ʾ��λ��������*/
    element.x = x0;	  
    element.y = y0;
    element.d = -1;
    push_seq(st, element);   						/* ��ʼ���ջ */
    step = 1;
    do {
        element = top_seq(st);
        pop_seq(st);
        i = element.x;
        j = element.y;
        area[i][j] = 1;
        for (k = element.d+1; k < 8 && step < MAXNUM; k++) {/* ������̽ÿ������ */
            g = i + direction[k][0];
            h = j + direction[k][1];
            if (inarea(g,h) == 1 && area[g][h] == 0) {
                area[g][h] = 1;
                step++;
                element.x = i;	  
                element.y = j;
                element.d = k;
                push_seq(st, element);  			/* ��ջ */
                i = g;     							/* ��һ��ת���ɵ�ǰ�� */
                j = h;
                k = -1;
            }
        }
        if (step < MAXNUM) {
            area[i][j] = 0;
            step--;
        }
    } while(!isEmptyStack_seq(st) && step < MAXNUM);
	
    if (step < MAXNUM)
        printf("cannot find the path !\n");
    else {
        printf("the reverse path is :\n");
        printf(" %d , %d\n", g, h);
        while(!isEmptyStack_seq(st)) {
            element = top_seq(st);
            pop_seq(st);
            printf(" %d , %d\n", element.x, element.y);
        }
    }
}

int main() {
    int x0, y0;
    printf("please input the position (x0,y0) \nx0 = ");
    scanf("%d", &x0);
    printf("y0 = ");
    scanf("%d", &y0);
    path(x0, y0);
    getchar(); getchar();
    return 0;
}








