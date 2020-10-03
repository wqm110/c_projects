//
// Created by mac on 2020/10/2.
//
//   链栈

#ifndef CLAS_LKSTACK_H
#define CLAS_LKSTACK_H

#endif //CLAS_LKSTACK_H

typedef struct lknode {
    DataType data;
    struct lknode *next;
} LkStk;

//1 初始化
LkStk *InitLKStack(LkStk *LS) {
    printf("初始化链栈。\n");
    LS = (LkStk *) malloc(sizeof(LkStk));
    LS->next = NULL;                      //建一个空栈
    return LS;
}

//2 判断栈空
int EmptyLKStack(LkStk *LS) {
    if (LS->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

//3 进栈
LkStk *PullLKStack(LkStk *LS, DataType x) {
    if (x.num >= 1 && x.num <= 198) {
        printf("进栈：%c\n", x.num);
    } else {
        printf("进栈：%d\n", x.num);
    }
    LkStk *temp;
    temp = (LkStk *) malloc(sizeof(LkStk));
    temp->data = x;
    temp->next = LS->next;
    LS->next = temp;
    return LS;
}

//4 出栈
LkStk *PopLKStack(LkStk *LS) {
    if (EmptyLKStack(LS)) {
        printf("空栈。");
    } else {
        LkStk *top = LS->next;
        LS->next = top->next;
        if (top->data.num >= 1 && top->data.num <= 198) {
            printf("出栈：%c\n", top->data.num);
        } else {
            printf("出栈：%d\n", top->data.num);
        }
        free(top);

        return LS;
    }
}

//5取栈顶元素
DataType GetTopLKStack(LkStk *LS) {
    if (!EmptyLKStack(LS)) {
        DataType top = LS->next->data;
        return top;
    } else {
        printf("空链栈。");
    }
}

//6 栈的遍历
void ViewLinkStrack(LkStk *LS) {
    if (!EmptyLKStack(LS)) {
        while (LS->next != NULL) {
            DataType top = LS->next->data;
            printf(("num:%s,name:%s.\n", top.num > 1 && top.num < 199 ? "%c" : "%d"), top.num, top.name);
            LS->next = LS->next->next;
        }
        printf("\n");
    }else{
        printf("kong..");
    }
}

//7 栈的应用 链栈 逆置
void ReverseLKStack(LkStk *LS) {
    LkStk *new_lk = InitLKStack(LS);
    while (LS->next != NULL) {
        new_lk = PopLKStack(LS);

    }
//    while (new_lk->next != NULL) {
//        new_lk = PopLKStack(new_lk);
//    }
}

//8 课本上的 链栈逆置
LkStk *ReverseList(LkStk *head) {
    printf("翻转，，\n");
    LkStk *LS_inRevs,*p;
    DataType x;
    p = InitLKStack(LS_inRevs);

    while (head->next != NULL) {
        x = GetTopLKStack(head);
        p = PullLKStack(p, x);
        head = head->next;
    }

    return p;
}