/**
* @Author : zhang
* @create 2022/2/14 14:57
*/

//
// Created by zhang zhiqiang on 2022/2/14.
//


#include "t1.h"
#include "iostream"

using namespace std;

void t1::swap(int* a, int* b) {

    //法一：借助中间变量
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;

    //法二
//    *a=*a+*b;
//    *b=*a-*b;
//    *a=*a-*b;
}




int t1::gcd(int a, int b) {
    int d;
    //法一
    d=(a<=b) ? a : b;
    while (d>1){
        if(a%d==0 && b%d==0){
            break;
        }
        d--;
    }
    return d;

    //法二：辗转相除法
    return (b==0) ? a :  gcd(b,a%b);
}



void t1::hanoi(char x, char y, char z, int n) {
    if(n==1){
        cout<<"1:"<<x<<"→"<<y<<endl;
    }else{
        hanoi(x,z,y,n-1);
        cout<<n<<":"<<x<<"→"<<y<<endl;
        hanoi(z,y,x,n-1);
    }
}

bool t1::isHui(int n) {
    int reversedInteger=0,remainder=0,originalInteger=n;

    //翻转
    while(n!=0)
    {
        remainder=n%10;
        reversedInteger = reversedInteger*10+remainder;
        n=n/10;
        cout<<n<<""<<remainder<<""<<reversedInteger<<endl;
    }

    //判断
    if(originalInteger==reversedInteger){
        cout<<originalInteger<<"是回文数"<<endl;
        return true;
    }else{
        cout<<originalInteger<<"不是回文数"<<endl;
        return false;
    }

}

int t1::getFactorial(int n) {
    int sum=1;

    if(n==0){
        return 1;
    }else if(n<0){
        return -1;
    }else {

        //法一:for循环
        for (int i = 1; i <= n; ++i) {
            sum =sum*i;
        }
        return sum;

        //法二：do-while循环
        do{
            sum=sum*n;
            n--;
        } while (n==0);

        //法三：while循环
        while(n>0){
            sum=sum*n;
            n--;
        }

        //法四：递归
        if(n==0){
            return 1;
        }else{
            return n*getFactorial(n-1);
        }


    }



}



