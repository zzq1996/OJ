/**
* @Author : zhang
* @create 2022/3/3 18:22
*/

//
// Created by zhang zhiqiang on 2022/3/3.
//


/*
 * @Description 递归
 * 含义：函数直接或间接调用自身
 * 构成递归的条件：
 *      1、子问题与原始问题相同，且规模更小
 *      2、不能无限制地调用本身，必须有一个递归出口
 */

#include "Recursion.h"
#include "iostream"


using namespace std;


/*
 * @Description 求n的阶乘（递归）
 */

long long int f(int x){
    if(x==0){//0!是最底层的子问题，该子问题不可继续分解且易于求解。故为递归出口
        return 1;
    } else{
        return x* f(x-1);//递归调用
    }
}

void Recursion::h8_1() {
    int n;
    while (cin>>n){
        long long answer= f(n);
        cout<<answer<<endl;
    }

}


/*
 * @Description 汉诺塔
 * 并不关注具体的移动方法，而是将当前问题与规模更小的问题联系起来，并利用这一关系确定递推关系式
 */

long long f2(int n){
    if (n==1){
        return 2;
    }else{
        return 3* f2(n-1)+2;
    }
}

void Recursion::h8_2() {
    int n;
    while (cin>>n){
        cout<<f2(n)<<endl;
    }

}

/*
 * @Description 母牛问题
 *
 * 问题描述：有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
 *
 * 解题思路：关键是找到年数与母牛数量的关系
 *  —— 第n年的母牛数量=第（n-1）年的母牛数+第（n-3）年母牛数
 *  —— 注意画出生成图的方式
 *
 * 法一：递归
 *
 *
 * 法二：使用数组记录第i年的母牛数量
 *  —— 仍然用母牛数量公式构造数组
 *
 *
 */

/*
 * @Description 定义递归函数，返回第year年的母牛数量
 */
int num_of_cow1(int year){

    if (year==1){
        return 1;
    }else if (year==2){
        return 2;
    }else if (year==3){
        return 3;
    }else if (year==4){
        return 4;
    } else{
        return num_of_cow1(year-1)+ num_of_cow1(year-3);
    }

}

/*
 * @Description 使用数组记录第i年的母牛数量
 */
int num_of_cow2(int year){

    //初始化记录母牛数量的数组
    int numOfCow[100]={0,1,2,3,4};

    //构造数组
    for (int i = 5; i <100 ; ++i) {
        numOfCow[i]=numOfCow[i-1]+numOfCow[i-3];
    }

    return  numOfCow[year];

}

/*
 * @Description 主程序
 * 输入0退出
 */
void Recursion::h8_3() {
    int year=0;

    while (cin>>year){
        if (year==0){
            break;
        }else{
            cout<<num_of_cow2(year)<<endl;
        }
    }

}
