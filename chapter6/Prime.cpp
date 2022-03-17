/**
* @Author : zhang
* @create 2022/3/2 17:20
*/


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

vector<int> prime1;//保存质数

bool isPrime1[MAXN];//标记数组


//素数筛选法求出2-10000内的所有素数。
// 当输入n时，依次判断1～n这个区间内的素数是否符合题目条件
void initial1(){
    for (int i = 0; i < MAXN; ++i) {
        isPrime1[i]= true;
    }

    isPrime1[0]= false;
    isPrime1[1]= false;

    for (int i = 2; i < MAXN; ++i) {

        if (!isPrime1[i]){//非质数跳过
            continue;
        }

        prime1.push_back(i);

        //质数的倍数为非质数，这里从i*i开始标记
        for (int j = i*i; j <MAXN ; j=j+i) {
            isPrime1[j]= false;
        }

    }


}


void Prime::f6_8() {
    initial1();
    int n;
    while (cin>>n){

        bool isOutput= false;//判断是否有输出

        for (int i = 0; i < prime1.size() && prime1[i] < n; ++i) {

            if (prime1[i] % 10  == 1){
                isOutput= true;
                cout<<prime1[i]<<" ";
            }

        }

        if (!isOutput){
            cout<<"-1";
        }

        cout<<endl;


    }

}


/*
 * @Description 完数的判断
 *
 * 因为走了弯路，所以记录一下
 *
 * 题目描述：一个数如果恰好等于不包含它本身所有因子之和，这个数就称为"完数"。 例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。 编程序找出N之内的所有完数，并按下面格式输出其因子
 *
 * 输出格式：
 *  6 its factors are 1 2 3
    28 its factors are 1 2 4 7 14
    496 its factors are 1 2 4 8 16 31 62 124 248


    法一：
        1、找出所有完数并放入向量
        2、依次求出完数的因子，并输出

        bool get(int x){
            int sum=1;
            for (int i = 2; i <= sqrt(x); ++i) {
                if (x%i==0){
                    sum=sum+i+(x/i);
                }

            }
            return sum==x;
        }


        void put(int x){
            vector<int> v;
            for (int i = x-1; i >= 1; --i) {
                if ((x%i)==0){
                    v.push_back(i);
                }
            }
            cout<<x<<" its factors are ";
            for (int i = v.size()-1; i >=0 ; --i) {
                cout<<v[i]<<" ";
            }
        }


    int main() {
        int n;
        while (cin>>n){
            for (int i = 2; i < n; ++i) {
                vector<int> num;
                if (get(i)){
                    num.push_back(i);
                }
                for (int j = 0; j < num.size(); ++j) {
                    put(num[j]);
                    cout<<endl;
                }
            }
        }
        return 0;
    }

    法二：
        一边遍历，一边保存完数的因子，最后在判断其是否为完数，是则输出

        ————这个方法耗时反而增加了-_-b
 *
 */


void Prime::f6_13() {

    int n;
    while (cin>>n){
        for (int i = 2; i < n; ++i) {
            vector<int> factor;//保存当前数的因子
            int sum=0;//保存当前数的因子和
            for (int j = 1; j < i-1; ++j) {

                if (i%j==0){
                    factor.push_back(j);
                    sum=sum+j;
                }
            }
            if (sum==i){
                cout<<i<<" its factors are ";
                for (int j : factor) {
                    cout<<j<<" ";
                }
                cout<<endl;
            }

        }
    }

}


