//
// Created by mac on 2020/9/29.
//栈
//


#include "stdio.h"


#ifndef TEST_SEQSTACK_H
#define TEST_SEQSTACK_H

#endif //TEST_SEQSTACK_H
const int maxsize = 6;
typedef struct seqstack {
    DataType data[maxsize];
    int top;
} SeqStk;

//1 初始化
int InitStack(SeqStk *stk) {
    stk->top = 0;
    return 1;
}

//2 判断栈空
int EmptyStack(SeqStk *stk) {
    //若栈为空，返回值1，否则返回0
    if (stk->top == 0)
        return 1;
    else return 0;
}

//3进栈
int Push(SeqStk *stk, DataType x) {
    //若栈未满，元素x进栈stk中，否则提示出错信息
    if (stk->top == maxsize - 1) {   //判断栈是否满
        error("栈已满");
        return 0;
    } else {
        stk->top++;                //栈未满 top+1
        stk->data[stk->top] = x;     //元素x进栈
        return 1;
    }
}

//4 出栈
int Pull(SeqStk *stk) {
    if (EmptyStack(stk)) {
//        error();
        exit("空栈");
        return 0;
    } else {
        stk->top--;

        return 1;
    }
}