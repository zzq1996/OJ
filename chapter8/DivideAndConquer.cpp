/**
* @Author : zhang
* @create 2022/3/3 19:19
*/



/*
 * @Description 分治
 * 基本步骤：
 *      1、分：把问题分成规模更小的子问题
 *      2、治：将这些规模更小的子问题逐个求解
 *      3、合：将已解决的子问题合并，最终得出"母"问题的解
 */

#include "DivideAndConquer.h"
#include "iostream"

using namespace std;

/*
 * @Description 斐波那契数
 */

//求解第n个斐波那契数
int fib1(int n){
    int f1=1,f2=1;
    if (n==1 || n==2){
        return n-1;
    }else{
        for (int i = 3; i <= n; ++i) {

            int tmp=f1+f2;//计算新的斐波那契数
            f1=f2;//记住前一个斐波那契数
            f2=tmp;//记住新的斐波那契数

        }
        return f2;
    }
}

//递归
int fib2(int n){
    if(n==1||n==2){
        return 1;
    }else{
        return fib2(n-2)+fib2(n-1);
    }
}

void DivideAndConquer::g8_3() {
    int n;
    while (cin>>n){
        cout<<fib2(n)<<endl;
    }
}


/*
 * @Description 二叉树
 * 输出n个结点的二叉树的第m个结点所在的子树的结点数（包括m结点）
 * 将问题分解为求m结点的左、右子树
 */

int countNode(int m,int n){
    if (m>n){//递归出口
        return 0;
    }else{//递归调用
        return 1+ countNode(m*2,n)+ countNode(m*2+1,n);
    }
}

void DivideAndConquer::g8_4() {
    int m,n;
    while (cin>>m>>n){
        cout<<countNode(m,n)<<endl;
    }

}
