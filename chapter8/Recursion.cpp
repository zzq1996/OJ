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
