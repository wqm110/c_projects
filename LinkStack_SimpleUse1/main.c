//
// Created by mac on 2020/10/3.
//
#include <stdbool.h>
#include "stdio.h"

const int maxsize = 50;


typedef struct seqstack {
    char data[maxsize];
    int top;
} SeqStack;

bool EmptyStack(SeqStack *pSeqstack);

int InitStack(SeqStack *stk) {
    stk->top = 0;
    return 1;
}

int PushStack(SeqStack *stk, char ch) {
//    printf("%c 进栈了。\n", ch);
//    char  c = ch;
    if (stk->top == maxsize - 1) {
        printf("沾满.\n");
        return 0;
    } else {
//        printf("..");
        stk->top++;
        stk->data[stk->top] = ch;
        return 1;
    }
}

//求阶乘 递归
int n_n_1(int n) {
    if (n == 1) return 1;
    else return n * n_n_1(n - 1);
}


int main() {
    //顺序栈
//    SeqStack *stk;
//    int i;
//    char ch;
//    InitStack(stk);
//    for (ch = 'A'; ch <= 'Z'; ch++) {
//        PushStack(stk, ch);
//    }
//    while (!EmptyStack(stk)){
//        ch = stk->top[stk->data];
//        stk->top--;
//    }
//        return 0;
//递归
    int b = n_n_1(31);
    printf("%d", b);
}

bool EmptyStack(SeqStack *s) {
    if (s->top == 0) {
        return 1;
    } else {
        return 0;
    }
}
