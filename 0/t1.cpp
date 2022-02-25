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


/*
 * @Description TODO
 */
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


/*
 * @Description 求两个正整数的最大公因数
 */
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


/*
 * @Description 汉诺塔
 */
void t1::hanoi(char x, char y, char z, int n) {
    if(n==1){
        cout<<"1:"<<x<<"→"<<y<<endl;
    }else{
        hanoi(x,z,y,n-1);
        cout<<n<<":"<<x<<"→"<<y<<endl;
        hanoi(z,y,x,n-1);
    }
}


/*
 * @Description 回文数
 */
bool t1::isHui(int n) {

    //法一：翻转后比较
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


    //法二：用数组实现
    int count=1,y=n;

    bool r=true;

    if(n/10==0){
        r=false;
    }else{
        while(y/10!=0){//求出x的位数
            y=y/10;
            count++;
        }
    }

    //新建一个数组保存各个位数
    int a[count];

    //控制变量，取x的各位位数
    int i=1;
    //定义两个指针分别指向数组的头/尾，控制遍历条件并赋值
    for(int *p=&a[count-1],*q=&a[0] ; p>=q ; --p){
        *p = (n%(i*10))/(i);
        i=i*10;
    }
    //定义两个指针分别指向数组的头/尾，比较元素是否相同
    for(int *p=&a[0],*q=&a[count-1];p<=q;p++,q--){
        if(*p != *q){
            r=false;
        }
    }
    return r;


}


/*
 * @Description 求n！
 */
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


/*
 * @Description TODO
 */
void t1::int_to_string(int n, char *str) {
    //char转int：char-‘0’
    //int转char：int+‘0’

    int count=1,y=n;
    if(n>=0){//非负数
        if(n/10!=0){
            while(y/10!=0){//求出x的位数
                y=y/10;
                count++;
            }
            int i=1;//控制变量，取x的各位位数
            for(int h=1;h<count;h++){
                i=i*10;
            }
            for(int j=0;j<count;j++){//通过指针访问数组元素
                *(str+j)=(n/i)+'0';
                n=n%i;
                i=i/10;
            }
        }else{
            //一位数
            *str=n+'0';
        }

        //for(intj=0;j<count;j++){//通过指针访问数组元素
        //cout<<*(str+j);
        //}

    }else{//负数
        *str='-';
        int m=-n,o=-n;
        count=1;
        if(m/10!=0){
            while(o/10!=0){//求出x的位数
                o=o/10;
                count++;
            }
            int i=1;//控制变量，取x的各位位数
            for(int h=1 ; h<count ; h++){
                i=i*10;
            }
            for(int j=1 ; j<=count ; j++){//通过指针访问数组元素
                *(str+j)=(m/i)+'0';
                m=m%i;
                i=i/10;
            }
        }else{
            //一位数
            *(str+1)=n+'0';
        }
        //for(intj=0;j<=count;j++){//通过指针访问数组元素
        //cout<<*(str+j);
        //}
    }

}



