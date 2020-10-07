//
// Created by mac on 2020/10/7.
//

#ifndef TEST_PRIME_H
#define TEST_PRIME_H

#endif //TEST_PRIME_H

/**
 * 试卷中的练习题
 * */
//1
int Prime() {
    /*判断输入的数字是否为素数*/
    //是 返回1
    //不是返回0
    int num, i;
    printf("请输入一个用以判断是否为素数的数字:\n");
    scanf("%d", &num);
    if (num == 1) {
        return 0;       //数学规定1 不是素数
    }
    for (i = 2; i < num; i++) {//在本身和1 之间又一个能被整除的 则不是素数
        if (num % i == 0) {
            printf("%d不是素数。\n", num);
            return 0;   //不是素数
        }
    }
    printf("%d是素数。\n", num);
    return 1;           //是素数
}

//2
/**
 * 1-2+3-4+5-...-100
 * */
int OneToHundred_AddAndMinus() {
    int i, sum = 0;
    for (i = 1; i <= 100; i++) {       //生成 1 到100 的数字
        if (i % 2 == 0) sum = sum - i;// 减偶数
        else sum = sum + i;           // 加奇数
    }
    printf("1-2+3-4+5-...-100 = %d\n", sum);
    return sum;
}

/**
 * 1/2+3/4+4/5+...+99/100
 * */
int OneToHundred_division() {
    double sum = 0.0;             //保存结果
    double i;                  //当前值
    for (i = 1; i < 100; i++) {    //i取值范围 为 1-99
//        printf("%f\n",i);
        sum = sum + i / (i + 1);
//        printf("%f,%f,%f,%f\n",i,i+1,i/(i+1),sum);
    }
    printf("1/2+3/4+4/5+...+99/100 = %f\n", sum);
    return sum;
}