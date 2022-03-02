/**
* @Author : zhang
* @create 2022/3/2 17:20
*/

//
// Created by zhang zhiqiang on 2022/3/2.
//


#include <vector>
#include "Prime.h"
#include "math.h"
#include "iostream"

using namespace std;



/*
 * @Description 判定素数
 */

//判定函数
bool isPrime(int x){
     bool b= true;
     if(x<2){
         return false;
     }else{
         for (int i = 2; i <= sqrt(x); ++i) {
             if(x%i==0){
                 b= false;
                 break;
             }
         }
         return b;
     }
 }




void Prime::f6_7() {
    int num;
    while (cin>>num){
        if (isPrime(num)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}

/*
 * @Description 素数遍历法：若当前整数没有因为它是某个小于其的素数的倍数而被标记为素数，
 *                                              则判定其为素数，并标记它所有的倍数为素数。
 */

const int MAXN=10001;
vector<int> prime;//保存质数
bool isPrime1[MAXN];//标记数组


//素数筛选法求出2-10000内的所有素数。
// 当输入n时，依次判断1～n这个区间内的素数是否符合题目条件
void initial(){
    for (int i = 0; i < MAXN; ++i) {
        isPrime1[i]= true;
    }

    isPrime1[0]= false;
    isPrime1[1]= false;

    for (int i = 2; i < MAXN; ++i) {

        if (!isPrime1[i]){//非质数跳过
            continue;
        }

        prime.push_back(i);

        //质数的倍数为非质数，这里从i*i开始标记
        for (int j = i*i; j <MAXN ; j=j+i) {
            isPrime1[j]= false;
        }

    }


}


void Prime::f6_8() {
    initial();
    int n;
    while (cin>>n){

        bool isOutput= false;//判断是否有输出

        for (int i = 0; i < prime.size() && prime[i] < n; ++i) {

            if (prime[i] % 10  == 1){
                isOutput= true;
                cout<<prime[i]<<" ";
            }

        }

        if (!isOutput){
            cout<<"-1";
        }

        cout<<endl;


    }

}
