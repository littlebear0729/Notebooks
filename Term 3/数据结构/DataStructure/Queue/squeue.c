/* 队列的顺序表示：函数定义 */


#include "squeue.h"
#include "../Stack/sstack.h"

PSeqStack createEmptyStack_seq() {
    PSeqStack pastack = (PSeqStack) malloc(sizeof(struct SeqStack));
    if (pastack == NULL)
        printf("Out of space!! \n");
    else
        pastack->t = -1;
    return pastack;
}

/*创建一个空队列*/
PSeqQueue createEmptyQueue_seq(void) {
    PSeqQueue paqu = (PSeqQueue) malloc(sizeof(struct SeqQueue));
    if (paqu == NULL)
        printf("Out of space!! \n");
    else
        paqu->f = paqu->r = 0;
    return paqu;
}

void printSeqQueue(PSeqQueue paqu) {
    int i;
    for (i = paqu->f; i < paqu->r; i++) {
        printf("%d ", paqu->q[i]);
    }
}

void push_seq(PSeqStack pastack, DataType x) {
    if (pastack->t >= MAXNUM - 1)
        printf("Stack Overflow! \n");
    else {
        pastack->t++;
        pastack->s[pastack->t] = x;
    }
}

/* 删除栈顶元素 */
void pop_seq(PSeqStack pastack) {
    if (pastack->t == -1)
        printf("Underflow!\n");
    else
        pastack->t--;
}

/* 当pastack所指的栈不为空栈时，求栈顶元素的值 */
DataType top_seq(PSeqStack pastack) {
    return pastack->s[pastack->t];
}

int isEmptyStack_seq(PSeqStack pastack) {
    return pastack->t == -1;
}

/*判队列是否为空队列*/
int isEmptyQueue_seq(PSeqQueue paqu) {
    return paqu->f == paqu->r;
}

/* 在队列中插入一元素x */
void enQueue_seq(PSeqQueue paqu, DataType x) {
    if ((paqu->r + 1) % MAXNUM == paqu->f)
        printf("Full queue.\n");
    else {
        paqu->q[paqu->r] = x;
        paqu->r = (paqu->r + 1) % MAXNUM;
    }
}

/* 删除队列头部元素 */
void deQueue_seq(PSeqQueue paqu) {
    if (paqu->f == paqu->r)
        printf("Empty Queue.\n");
    else
        paqu->f = (paqu->f + 1) % MAXNUM;
}

int main() {
//   mazePath(1, 1, 6, 9);
//   getchar();
    int n;
    PSeqStack pastack = createEmptyStack_seq();
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        push_seq(pastack, t);
    }
    PSeqQueue paqu = createEmptyQueue_seq();
    n = pastack->t;
    while (!isEmptyStack_seq(pastack)) {
        int t = top_seq(pastack);
        enQueue_seq(paqu, t);
        pop_seq(pastack);
    }
    printSeqQueue(paqu);
    return 0;
}
