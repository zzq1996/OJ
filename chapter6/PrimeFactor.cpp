/**
* @Author : zhang
* @create 2022/3/2 20:50
*/




#include "PrimeFactor.h"
#include <cmath>
#include <iostream>
#include "vector"

using namespace std;

const int MAXN=sqrt(1e9)+1;

vector<int> prime;//保存质数

/*
 * @Description 素数筛除法
 */
void initial(){
    bool isPrime[MAXN];//标记数组

    for (int i = 0; i < MAXN; ++i) {//初始化数组
        isPrime[i]= true;
    }
    isPrime[0]= false;
    isPrime[1]= false;

    for (int i = 2; i < MAXN; ++i) {

        if(!isPrime[i]){//非质数跳过
            continue;
        }

        prime.push_back(i);

        for (int j = i*i; j <MAXN ; j=j+i) {
            isPrime[j]= false;//质数的倍数为非质数
        }

    }

}

void PrimeFactor::f6_9() {
    initial();
    int n;
    while (cin>>n){
        int answer=0;

        for (int i = 0; i < prime.size() && prime[i]<n; ++i) {
            int factor=prime[i];

            while (n%factor == 0){//不断试除
                n=n/factor;
                answer++;//统计其幂指数
            }

        }
        if (n>1){//还存在一个质因数
            answer++;
        }
        cout<<answer<<endl;

    }



}
