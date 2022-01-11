/*栈链接表示：函数定义*/

#include<stdio.h>
#include<stdlib.h>

#include "lstack.h"

/*申请链栈结构空间，创建一空链接栈，返回指向空链接栈的指针*/
PLinkStack createEmptyStack_link(void) {
    PLinkStack plstack;
    plstack = (PLinkStack) malloc(sizeof(struct LinkStack));
    if (plstack != NULL)
        plstack->top = NULL;
    else
        printf("Out of space! \n");
    return plstack;
}

/*判单链形式栈是否为空栈*/
int isEmptyStack_link(PLinkStack plstack) {
    return plstack->top == NULL;
}

/* 在栈中压入一元素x */
void push_link(PLinkStack plstack, DataType x) {
    PNode p;
    p = (PNode) malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Out of space!\n");
    else {
        p->info = x;
        p->link = plstack->top;
        plstack->top = p;
    }
}

/*出栈*/
void pop_link(PLinkStack plstack) {
    if (isEmptyStack_link(plstack))
        printf("Empty stack pop.\n");
    else {
        PNode p = plstack->top;
        plstack->top = plstack->top->link;
        free(p);
    }
}

/* 对非空栈求栈顶元素 */
DataType top_link(PLinkStack plstack) {
    return plstack->top->info;
}

void ten2two(int ten) {
    PLinkStack pLinkStack = createEmptyStack_link();
    while (ten != 0) {
        push_link(pLinkStack, ten % 2);
        ten /= 2;
    }
    while (!isEmptyStack_link(pLinkStack)) {
        printf("%d", pLinkStack->top->info);
        pop_link(pLinkStack);
    }
}

int ten2two2(int ten) {
    if (ten == 0 || ten == 1) {
        printf("%d", ten);
        return ten;
    } else {
        ten2two(ten / 2);
        printf("%d", ten % 2);
    }
}

int main() {


    return 0;
}