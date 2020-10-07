//
// Created by WQM on 2020/10/7.
//

#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

#endif //TEST_QUEUE_H
/**
 *
 * 队列
 *
 *
 * 基本运算
 * （1）初始化队列 InitQueue（Q）
 * （2）判断队列空 EmptyQueue（Q）
 * （3）入队列    EnQueue(Q,x)
 * (4)出队列     OutQueue（Q）
 * (5)取对列首元素 GetHead（Q）
 *
 *
 * */

/**
 * 队列的顺序实现
 *
 * 1）初始化队列 InitSeQueue（Q）
 * （2）判断队列空 EmptySeQueue（Q）
 * （3）入队列    EnSeQueue(Q,x)
 * (4)出队列     OutSeQueue（Q）
 * (5)取对列首元素 GetSeHead（Q）
 * */

typedef struct seqqueue {
    DataType data[Maxsize];
    int front, rear;
} SeqQueue;


//1 InitSeQueue（Q）
SeqQueue InitSeQueue(SeqQueue SQ) {
    printf("InitSeQueue.\n");
    SQ.front = 0;
    SQ.rear = 0;
    return SQ;
}

//2 EmptySeQueue
int EmptySeQueue(SeqQueue SQ) {
    if (SQ.rear - SQ.front == 0) {
        printf("空队列。\n");
        return 1;
    } else {
        printf("非空队列.\n");
        return 0;
    }
}

// 3）入队列    EnSeQueue(SeqQueue SQ,DataType x)
SeqQueue EnSeQueue(SeqQueue SQ, DataType x) {
    printf("入队列.\n");
    if (SQ.rear < Maxsize - 2) {
        SQ.rear += 1;
        SQ.data[SQ.rear] = x;
        return SQ;
    } else {
        printf("沾满");
//        exit(0);
        return SQ;
    }
}

//4 出队列     OutSeQueue（Q）
SeqQueue OutSeQueue(SeqQueue SQ) {
    printf("出队列。\n");
    if (!EmptySeQueue(SQ)) {
        int position = 1;
//        DataType front, tail;
//        front = SQ.data[SQ.front];
//        tail = SQ.data[SQ.rear];
        while (position <= SQ.rear) { //从第二个到队列尾部全部前移
            SQ.data[position - 1] = SQ.data[position];
            position += 1;
        }
        SQ.rear = SQ.rear - 1;
        //剩余位置全部向前移动

        return SQ;
    } else
        return SQ;
}

// 5 取对列首元素 GetSeHead（Q）
DataType GetSeHead(SeqQueue SQ) {
    DataType top;
    if (!EmptySeQueue(SQ)) {
        top = SQ.data[SQ.front];
        return top;
    } else {
        printf("空队列无法出队列。\n");
        exit(0);
    }
}