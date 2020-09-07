//
// Created by mac on 2020/8/19.
//
#include <stdio.h>
# include <stdlib.h>
#include "Linear.h"
#include "LinearL.h"

void list_continue_save() {
    //线性表的连续存储
    DataType stu, stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8;
    stu.num = 19;
    stu1.num = 20;
    stu3.num = 17;
    stu2.num, stu4.num = 21;
    stu5.num, stu6.num = 22;
    stu7.num, stu8.num = 23;

    L = InsertSeqList(L, stu, 1);
    L = InsertSeqList(L, stu1, 2);
    L = InsertSeqList(L, stu2, 3);
    L = InsertSeqList(L, stu3, 4);
    L = InsertSeqList(L, stu4, 5);
    L = InsertSeqList(L, stu5, 6);
    L = InsertSeqList(L, stu6, 7);
    LocateSeqlist(L, stu4);
}

int main() {

    list_continue_save();
    //线性表的 链式存储
    return 0;
}

