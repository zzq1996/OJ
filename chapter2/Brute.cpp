/**
* @Author : zhang
* @create 2022/2/22 16:38
*/

//
// Created by zhang zhiqiang on 2022/2/22.
//


#include "Brute.h"
#include "iostream"

using namespace std;

void Brute::b2_1() {
    for(int i=0;i<10;++i){
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {

//                int a=i*100+j*10+k;
//                int b=j*100+k*10+k;
//                if((a+b)==532){
//                    cout<<i<<" "<<j<<" "<<k<<endl;
//                }

                    //对等式进行化简，减少运算量
                    if( (i*100+110*j+12*k) ==532){
                        cout<<i<<" "<<j<<" "<<k<<endl;
                    }


            }

        }
    }

}

void Brute::b2_2() {

    for(int i=1000;i<10000;++i){

        //法一：挨个求出位数，重组
        int a=i/1000;
        int b=(i/100)%10;
        int c=(i/10)%10;
        int d=i%10;
        if((9*i) == (d*1000+c*100+b*10+a) ){
            cout<<i<<endl;
        }

        //法二：用下面的函数

    }


}

int Brute::reverse(int x) {
    int i=0;
    while (x!=0){
        i = i * 10;
        i = i + (x % 10);
        x = x/10;
    }
    return i;
}
