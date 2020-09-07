//
// Created by mac on 2020/9/5.
//
/// 线性表 顺序表 结构定义//

#ifndef C_PROJECTS_LINEAR_H
#define C_PROJECTS_LINEAR_H

#endif //C_PROJECTS_LINEAR_H

/**
 * 本部分以学生为例
 **/
typedef struct {
    int num;
    char name[8];
    char sex[2];
    int age;
    int score;

} DataType;
/**
 * 结构体
 * */

const int Maxsize = 10;   // 数据最大长度
typedef struct {
    DataType data[Maxsize];
    int length;
} SeqList;
SeqList L;

/**
 * 线性表的基本运算
 * */

SeqList InsertSeqList(SeqList L, DataType x, int i) {
    printf("I'm in Linear.h：length%d\n", L.length);
    if (L.length == Maxsize) exit(0);
    if (i > L.length + 1 || i < 1) exit(-1);
//    int j = L.length;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];//依次后移
        printf("move left\n");
    }
    L.data[i - 1] = x;//元素x 置入到 下表为i-1的位置
    L.length++;
    return L;
}

/**
 *
 * 删除运算
 *
 * */
SeqList DeleteSeqlist(SeqList L, int i) {
    if ((i < 1) || (i > L.length)) exit("位置非法\0");
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
        printf("i 后面的迁移一位%d\n", j);
    }
    L.length--;
    return L;
}

/**
 * 定位
 */
int LocateSeqlist(SeqList L, DataType x) {
    int i = 0;
    printf("要在%d中查找\n", L.length);
    while ((i <= L.length) && (L.data[i].num != x.num)) {
        printf("\t当前正在查找第%d个\n", i);
        i++;
        printf("\t不是我要查找的，我要去找下一个了\n");
    }
    if (i < L.length) {
        printf("结果：找到了他在第%d位", i);
        return i;
    } else {
        printf("结果：没找到你想要的，%d", x.num);
        return 0;
    }

}
