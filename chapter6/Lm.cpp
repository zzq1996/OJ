/**
* @Author : zhang
* @create 2022/3/2 16:23
*/




#include "Lm.h"
#include "iostream"

using namespace std;

/*
 * @Description 最大公约数
 */
//法一：欧几里得
int Lm::f6_5_1(int x,int y) {
    while (cin>>x>>y){
        if (y==x){
            return x;
        } else{
            return f6_5_1(y,x%y);
        }
    }
}


//法二：
int Lm::f6_5_2(int x, int y) {
    int d ;
    d=(x<=y)?x:y;
    while(d>1){
        if(x%d==0 && y%d==0){
            break;
        }
        d--;
    }
    return d;
}


/*
 * @Description 最小公倍数（除0外）
 */

//返回a，b的最大公约数
int GCD(int a,int b){
    if (b==0){
        return a;
    }else{
        return GCD(b,a%b);
    }

}

//a，b的最大公倍数为：（a*b）/最大公约数
void Lm::f6_6() {
    int a,b;
    while (cin>>a>>b){
        cout<<a*b/ GCD(a,b);
    }

}




