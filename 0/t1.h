/**
* @Author : zhang
* @create 2022/2/14 14:57
*/




#ifndef OJ_T1_H

#define OJ_T1_H


class t1 {

public:

    static void swap(int* a,int* b);//交换整数值

    int gcd(int a,int b); //求两个正整数的最大公约数

    int getFactorial(int n);//求n阶乘


    /*
     * @Description 汉诺塔
     * @params:
     */
    void hanoi(char x,char y,char z,int n);

    /*
     * @Description 判断回文数
     * @params:
     */
    bool isHui(int n);

    void int_to_string(int n,char* str);//整型转字符串

    /*
     * @Description 约瑟夫环
     * 定义一个bool数组
     */
    void josephus(int N,int M);




};


#endif //OJ_T1_H
