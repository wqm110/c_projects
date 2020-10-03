//
// Created by mac on 2020/9/29.
//连续栈
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

SeqStk * InitStackFull() {
    printf("初始化栈。。。\n");
    SeqStk *stk = malloc(sizeof(SeqStk));
    stk->top = 0;
    return stk;
}

//2 判断栈空
int EmptyStack(SeqStk *stk) {
    //若栈为空，返回值1，否则返回0
    if (stk->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

//3进栈
int Push(SeqStk *stk, DataType x) {
    printf("pushing...\n");
    //若栈未满，元素x进栈stk中，否则提示出错信息
    if (stk->top == maxsize - 1) {   //判断栈是否满
        printf("栈已满");
        return 0;
    } else {
        stk->top++;                //栈未满 top+1
        stk->data[stk->top] = x;     //元素x进栈
        return 1;
    }
}

//4 出栈
int Pop(SeqStk *stk) {
    if (EmptyStack(stk)) {
//        error();
        printf("空栈下溢");
        return 0;
    } else {
        stk->top--;
        return 1;
    }
}

//5 取出栈顶元素
DataType GetTop(SeqStk *stk) {
    if (EmptyStack(stk)) {
        const DataType NULLData;
        return NULLData;
    } else {
        return stk->data[stk->top];

    }
}

//6 显示全部
void ShowStack(SeqStk *stk) {
    if (!EmptyStack(stk)) {
        printf("show\n");
        while (stk->top > 0) {
            DataType topData;                       //栈顶临时变量
            topData = stk->data[stk->top--];        //取出栈顶元素
            printf("%d : %d\n", stk->top, topData.num);//打印
        }
    } else{
        printf("空栈。\n");
    }
}

