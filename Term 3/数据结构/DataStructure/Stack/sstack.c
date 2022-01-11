#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>

#define MMAXNUM 100

#include "sstack.h"

PSeqStack createEmptyStack_seq() {
    PSeqStack pastack = (PSeqStack) malloc(sizeof(struct SeqStack));
    if (pastack == NULL)
        printf("Out of space!! \n");
    else
        pastack->t = -1;
    return pastack;
}

struct MySeqStack {
    int t;
    int m;
    int *s;
};

typedef struct MySeqStack MySeqStack, *PMySeqStack;

PMySeqStack createEmpty_seq(int m) {
    PMySeqStack mySeqStack = (PMySeqStack) malloc(sizeof(struct MySeqStack));
    if (mySeqStack == NULL)
        printf("Out of space!! \n");
    else {
        mySeqStack->t = -1;
        mySeqStack->m = m;
    }

    return mySeqStack;
}

/*判断pastack所指的栈是否为空栈，当pastack所指的栈为空栈时，则返回1，否则返回0*/
int isEmptyStack_seq(PSeqStack pastack) {
    return pastack->t == -1;
}

/* 在栈中压入一元素x */
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

int isEmpty_Seq(PSeqStack pastack) {
    return (pastack->t==-1);
}

int conversion(char *s) {
    int m = 0;
    int t = 1;
    int r = 0;
    DataType x;
    PSeqStack pastack = createEmptyStack_seq();
    while (s[m] != '\0') {
        x = s[m] - '0';
        push_seq(pastack, x);
        m = m + 1;

    }

    while (pastack->t != -1) {

        r = t * top_seq(pastack) + r;
        pop_seq(pastack);
        t = t * 10;

    }
    return (r);


}

int Fibonacci(int n) {
    int result = 0;
    int x;
    PSeqStack s = createEmptyStack_seq();
    push_seq(s, n);
    while (!isEmptyStack_seq(s)) {
        x = top_seq(s);
        pop_seq(s);
        if (x == 1 || x == 0)
            result = result + x;
        else {
            push_seq(s, x - 1);
            push_seq(s, x - 2);
            //printf("Move from %c---> to %c\n",A,C);
        }
    }
    return (result);


}

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        printf("move %d piece from %c to %c\n", n, a, b);
        return 1;
    }
    int ans = 0;
    printf("move %d piece from %c to %c via %c\n", n, a, b, c);
    ans += hanoi(n - 1, a, b, c);
    ans += hanoi(1, a, c, b);
    ans += hanoi(n - 1, b, c, a);
    return ans;
}

int hanoi_stack(int n, PSeqStack pa, PSeqStack pb, PSeqStack pc) {
    if (n == 1) {
        push_seq(pb, pa->s[pa->t]);
        if (!isEmpty_Seq(pa)) pop_seq(pa);
        return 1;
    }
    int ans = 0;
    ans += hanoi_stack(n - 1, pa, pb, pc);
    ans += hanoi_stack(1, pa, pc, pb);
    ans += hanoi_stack(n - 1, pb, pc, pb);
    return ans;
}

int main() {
    /*int i;
    for (i = 1; i <= 10; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
    int f[100] = {0, 1};
    for (i = 2; i <= 10; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (i = 1; i <= 10; i++) {
        printf("%d ", f[i]);
    }*/

    int n;
    scanf("%d", &n);
    char a = 'A', b = 'B', c = 'C';
    hanoi(n, a, c, b);

    PSeqStack pa = createEmptyStack_seq(), pb = createEmptyStack_seq(), pc = createEmptyStack_seq();
    for (int i = n; i >= 1; i--) {
        push_seq(pa, i);
    }
    printf("%d", hanoi_stack(n, pa, pc, pb));
    return 0;
}

