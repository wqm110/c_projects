//
// Created by mac on 2020/9/5.
//
typedef struct {
    int num;
    char name[8];
    char sex[2];
    int age;
    int score;

} Datatype;

typedef struct node {
    DataType data;
    struct node *next;
} Node, *LinkList;