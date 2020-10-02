//
// Created by mac on 2020/9/30.
//  轻松学c语言 代码

#include <stdio.h>

#define x 10

void ver_() {
    //变量
    //先声明 再使用
    //变量名 必须符合规范 不能使用关键字
    int b, c, d;
    char e, f, g;
    //变量的编译 是 通过 名 找到 地址 然后读取其中的值
    //extern 语句的作用是告诉语句该变量是在该程序的其他块中完成定义的
//    extern int a;
//    printf("%d", a);
}

void con_() {
    //常量
    //常量的类型通常有 整形，浮点型，字符型，字符串型，和符号常量
    const int a1;
    const int a2 = 19;
    const int a3, a4;
    const float f1, f3, f4;
    const int AGE = 100;
    printf("My name is Donkey I'm %d years old.\n", AGE);
    printf("const 定义的是 某种特定类型的常量。.\n", AGE);
//    const 定义的 变量不可修改
//    a2 = 10;  这是错误的
//#define x 10  定义到文件开头 ，符号常量定义方式
    printf("这是符号常量%d\n", x);
}

//第一个C语言程序
int main() {
    int a = 1;
    printf("数字:%d\n", a);
    ver_();
    con_();
}


