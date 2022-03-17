/**
* @Author : zhang
* @create 2022/2/22 16:07
*/




#include "Init.h"
#include "iostream"
using namespace std;

void Init::a1_1() {
    //对单行测试用例
    int a=0,b=0;
    cin>>a>>b;
    cout<<a+b;

    //对多行测试用例
//    while (cin>>a>>b){
//
//    }

}


/*
 * @Description 利润计算
 *
 * 题目描述：企业发放的奖金根据利润提成。利润低于或等于100000元的，奖金可提10%;
利润高于100000元，低于200000元（100000<I≤200000）时，低于100000元的部分按10％提成，高于100000元的部分，可提成 7.5%;
200000<I≤400000时，低于200000元部分仍按上述办法提成，（下同），高于200000元的部分按5％提成；
400000<I≤600000元时，高于400000元的部分按3％提成；

600000<I≤1000000时，高于600000元的部分按1.5%提成；
I>1000000时，超过1000000元的部分按1%提成。从键盘输入当月利润I,求应发奖金总数。

 踩过的坑：
    1、没看懂题意，计算方法出错
    2、没有使用宏定义，程序很繁琐
    3、1.5% != 0.15
    4、用递归会更好
 *
 */

#define profit_1 100000
#define profit_2 200000
#define profit_4 400000
#define profit_6 600000
#define profit_10 1000000

void Init::a1_2() {

    int bonus=0;
    int profit=0;
    while (cin>>profit){
        if (profit<=profit_1){
            bonus=profit*0.1;

        }else if(profit>=profit_1 && profit<=profit_2){
            bonus=(profit-profit_1)*0.075+profit_1*0.1;

        }else if(profit>=profit_2 && profit<=profit_4){
            bonus=(profit-profit_2)*0.05+profit_1*0.175;

        }else if(profit>profit_4 && profit<=profit_6){
            bonus=(profit-profit_4)*0.03+profit_2*0.05+profit_1*0.175;
        }else if(profit>profit_6 && profit<=profit_10){
            bonus=(profit-profit_6)*0.015+profit_2*0.08+profit_1*0.175;
        }else if(profit>=profit_10){
            bonus=(profit-profit_10)*0.01+profit_4*0.015+profit_2*0.08+profit_1*0.175;
        }

        cout<<bonus<<endl;
    }

}
