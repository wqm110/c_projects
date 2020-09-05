//
// Created by mac on 2020/9/5.
//
typedef struct {
    int num;
    char name[8];
    char sex[2];
    int age;
    int score;

} Stu;

typedef struct node {
    char data;
    struct node *next;
} Node, *LinkList;