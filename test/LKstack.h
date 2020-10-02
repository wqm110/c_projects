//
// Created by mac on 2020/10/2.
//
//   链栈

#ifndef CLAS_LKSTACK_H
#define CLAS_LKSTACK_H

#endif //CLAS_LKSTACK_H

typedef struct lknode {
    Datatype data;
    struct lknode *next;
} LkStk;

//1 初始化
void InitLKStack(LkStk *LS) {
    LS = (LkStk *) malloc(sizeof(LkStk));
    LS->next = NULL;                      //建一个空栈
}
