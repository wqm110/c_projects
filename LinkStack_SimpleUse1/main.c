//
// Created by mac on 2020/10/3.
//
#include "stdio.h"

const int maxsize = 50;
typedef struct seqstack {
    char data[maxsize];
    int top;
} SeqStack;

int InitStack(SeqStack *stk) {
    stk->top = 0;
    return 1;
}

SeqStack *PushStack(SeqStack *stk, char ch) {
    if (stk->top != 0) {
        int top = stk->top + 1;
        stk->data[top] = ch;
    } else {
        InitStack(stk);
        stk->data[0] = ch;
    }
    printf("%c 进栈了。\n", ch);
    return stk;
}

int main() {
    SeqStack *stk;
    int i;
    char ch;
    InitStack(stk);
    for (ch = 'A'; ch <= 'Z'; ch++) {
        PushStack(stk, ch);
    }
    printf("%c,,,,,", stk->data[9]);
    return 0;
}