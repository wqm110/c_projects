//
// Created by mac on 2020/8/19.
//
#include <stdio.h>
# include <stdlib.h>
#include "Linear.h"
#include "LinearL.h"
#include "Seqstack.h"


void list_link_save(DataType stu, DataType stu2, DataType stu3) {
    //线性表的链式存储

    LinkList LL = InitiateLinkList();//建链

}

void list_continue_save(DataType stu, DataType stu1, DataType stu2, DataType stu3, DataType stu4, DataType stu5,
                        DataType stu6, DataType stu7, DataType stu8) {
    //线性表的连续存储

    L = InsertSeqList(L, stu, 1);
    L = InsertSeqList(L, stu1, 2);
    L = InsertSeqList(L, stu2, 3);
    L = InsertSeqList(L, stu3, 4);
    L = InsertSeqList(L, stu4, 5);
    L = InsertSeqList(L, stu5, 6);
    L = InsertSeqList(L, stu6, 7);
    L = InsertSeqList(L, stu7, 7);
    L = InsertSeqList(L, stu8, 7);
    DeleteSeqlist(L, 8);
    LocateSeqlist(L, stu7);
}

int main() {
    DataType stu, stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8;
    stu.num = 19;
    stu1.num = 20;
    stu3.num = 17;
    stu2.num, stu4.num = 21;
    stu5.num, stu6.num = 22;
    stu7.num, stu8.num = 23;
/**
 * 线性表的一些基本操作
 * */
//    list_continue_save(stu, stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8);
//    list_link_save(stu, stu1, stu2);


//    LinkList head = InitiateLinkList();
//    InsertLinkList(head, stu, 1);
//    InsertLinkList(head, stu1, 2);
//    InsertLinkList(head, stu2, 3);
//    InsertLinkList(head, stu7, 4);
//    LengthLinkList(head);
//    LocateLinkList(head, stu8);
//    DeleteLinkList(head,1);
//    LinkList new1 = CreateLinkList1();
//    LengthLinkList(new1);
//    printf("name%s", new1->data.name);
/**
 * 栈的一些操作
 * */


    Push(stk, stu1);
    ShowStack(stk);
    Push(stk, stu);
    ShowStack(stk);
    Push(stk, stu3);
    ShowStack(stk);
    Push(stk, stu3);
    ShowStack(stk);
    Push(stk, stu3);
    ShowStack(stk);
    Pop(stk);
    ShowStack(stk);
    return 0;
}



