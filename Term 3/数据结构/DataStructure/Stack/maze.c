#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sstack.h"

#define MAXNUM 100
typedef char DataType;

// 中缀转后缀
PSeqStack createEmptyStack_seq() {
    PSeqStack pastack = (PSeqStack) malloc(sizeof(struct SeqStack));
    if (pastack == NULL)
        printf("Out of space!! \n");
    else
        pastack->t = -1;
    return pastack;
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

// 计算符号优先级
int priority(char a) {
    if (a == '(') return 0;
    if (a == '+' || a == '-') return 1;
    if (a == '*' || a == '/') return 2;
    return 0;
}

int calcStack(int a, int b, DataType zifu) {
    if (zifu == '+') return a + b;
    if (zifu == '-') return a - b;
    if (zifu == '*') return a * b;
    if (zifu == '/') return a / b;
    return 0;
}

int main() {
    PSeqStack pastack = createEmptyStack_seq();
    char s[100];
    // 以字符串读入中缀表达式
    scanf("%s", s);
    int len = strlen(s);
    int tmp = 0;
    int ans[100] = {}, pos = 0;
    int cal1, cal2, a = 0, b = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            // 用符号分隔数字，用tmp记录数字
            tmp *= 10;
            tmp += s[i] - '0';
        } else {
            // 如果是'('直接压入栈
            if (s[i] == '(') {
                push_seq(pastack, s[i]);
                continue;
            }
            // 如果tmp不是0，打印出tmp（有数打数）
            if (tmp) {
                printf("%d ", tmp);
                ans[pos] = tmp;
                pos++;
            }
            tmp = 0;
            // 如果是')'，把栈依次弹出直至清空
            if (s[i] == ')') {
                while (pastack->t != -1) {
                    if (top_seq(pastack) != '(')
                        printf("%c ", top_seq(pastack));
                    if (pos != 1) {
                        a = ans[pos - 2];
                        b = ans[pos - 1];
                        ans[pos - 2] = calcStack(a, b, top_seq(pastack));
                        pos--;
                    }
                    pop_seq(pastack);
                }
            } else if (priority(s[i]) >= priority(top_seq(pastack))) {
                // 如果当前符号优先级比栈顶优先级高，压入栈
                push_seq(pastack, s[i]);
            } else if ((priority(s[i]) < priority(top_seq(pastack)))) {
                // 如果当前符号优先级比栈顶优先级低，输出栈顶，把当前符号压入栈
                printf("%c ", top_seq(pastack));
                if (pos != 1) {
                    a = ans[pos - 2];
                    b = ans[pos - 1];
                    ans[pos - 2] = calcStack(a, b, top_seq(pastack));
                    pos--;
                }
                pop_seq(pastack);
                push_seq(pastack, s[i]);
            }
        }
    }
    // 打印剩余的tmp
    if (tmp) {
        printf("%d ", tmp);
        ans[pos] = tmp;
        pos++;
    }
    // 清空栈
    while (pastack->t != -1) {
        if (top_seq(pastack) != '(')
            printf("%c ", top_seq(pastack));
        if (pos != 1) {
            a = ans[pos - 2];
            b = ans[pos - 1];
            ans[pos - 2] = calcStack(a, b, top_seq(pastack));
            pos--;
        }
        pop_seq(pastack);
    }
    printf("\n%d\n", ans[0]);
    return 0;
}


// 走迷宫
int maze[][11] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
        1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1,
        1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1,
        1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

int direction[4][2] = {{0,  1},
                       {1,  0},
                       {0,  -1},
                       {-1, 0}};

/*int find(int x1, int y1, int x2, int y2) {
    int next_x, next_y;
    for (int i = 0; i < 4; i++) {
        next_x = x1 + direction[i][0];
        next_y = y1 + direction[i][1];
        //printf("%d %d %d %d\n",x1, y1, next_x, next_y);
        if (next_x == x2 && next_y == y2 && maze[next_x][next_y] == 0) {
            printf("found\n");
            printf("The revers path is:\n");
            printf("the node is: %d %d\n", x2, y2);
            printf("the node is: %d %d\n", x1, y1);
            return 1;
        }
        if (maze[next_x][next_y] == 0) {
            maze[next_x][next_y] = 2;
            if (find(next_x, next_y, x2, y2) == 1) {
                printf("the node is: %d %d\n", x1, y1);
                return 1;
            }
        }
    }
    return 0;
}*/

/*
int find(int x1, int y1, int x2, int y2) {
    //printf("finding: x = %d, y = %d\n", x1, y1);
    if (x1 == x2 && y1 == y2) {
        printf("Found!\n");
        return 1;
    }
    if (maze[x1][y1] == 0) {
        maze[x1][y1] = 2;
        for (int i = 0; i < 4; i++) {
            if (find(x1 + direction[i][0], y1 + direction[i][1], x2, y2) == 1) {
                printf("node: x = %d, y = %d\n", x1 + direction[i][0], y1 + direction[i][1]);
                return 1;
            }
        }
    }
    return 0;
}


int main() {
    int x1, y1, x2, y2;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    if (find(x1, y1, x2, y2) == 1) {
        printf("node: x = %d, y = %d\n", x1, y1);
    }
    return 0;
}
*/
