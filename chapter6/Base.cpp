/**
* @Author : zhang
* @create 2022/3/1 19:56
*/

//
// Created by zhang zhiqiang on 2022/3/1.
//


#include "Base.h"
#include "iostream"
#include "vector"

using namespace std;

/*
 * @Description 十进制整数转二进制
 * 方法：除2取余，逆序排序
 */
void Base::f6_1() {
    unsigned int n=0;
    while (cin>>n){
        if(n==0){
            break;
        }else{
            vector<int> binary;
            while (n!=0){
                binary.push_back(n%2);
                n=n/2;
            }
            //注意：这里是逆序输出
            for (int i = binary.size()-1; i >= 0; --i) {
                cout<<binary[i];
            }
            cout<<endl;
        }
    }
}


/*
 * @Description 30位的非负十进制数转二进制
 * 用字符串模拟数字，对字符串模拟的数字进行对2取模和对2整除运算
 * ——取余：直接用最低位对2取模
 * ——整除：定义函数完成
 *  char转int：char-‘0’
    int转char：int+‘0’
 *
 */

/*
 * @Description 重写一个函数完成字符串的除法
 * 对字符串str进行除2运算
 *
 * 返回的字符串：pos位置后的str字串即整除后的整数部分
 *
 * string字符串从0开始
 *
 * 输入： cout<<divide("12345",2);
 * 输出：current:1,str[0]:0,reminder:1
        current:12,str[1]:6,reminder:0
        current:3,str[2]:1,reminder:1
        current:14,str[3]:7,reminder:0
        current:5,str[4]:2,reminder:1
        str:06172
        pos:1
        6172
 *
 */

string divide(string str,int x){

    int reminder=0;//保留余数

    //把字符串从高位到低位逐位除以2
    for (int i = 0; i < str.size(); ++i) {

        int current=reminder*10+str[i]-'0';
//        cout<<"current:"<<current;
        str[i]=current / x+'0';//str[i]保存的是整除2后的数
//        cout<<",str["<<i<<"]:"<<str[i];
        reminder = current % x;//若不能整除，则保留余数
//        cout<<",reminder:"<<reminder<<endl;
    }

    int pos=0;
//    cout<<"str:"<<str<<endl;
    while(str[pos]=='0'){//寻找首个非0下标
        pos++;
    }
//    cout<<"pos:"<<pos<<endl;
    return str.substr(pos);//删除前置多余0

}


/*
 * @Description 字符串转2进制
 */
void Base::f6_2() {

    string str;
    while (cin>>str){

        vector<int> binary;

        while(str.size()!=0){

            int last=str[str.size()-1]-'0';//获取最低位的值
            binary.push_back(last%2);//将最低位对2取模的结果存入向量
            str= divide(str,2);//对2整除，更新字符串
        }

        //逆序输出向量
        for (int i = binary.size()-1; i >=0; --i) {
            cout<<binary[i];
        }
        cout<<endl;
    }

}


/*
 * @Description 输出二进制逆序数
 */
void Base::f6_3() {
    string str;
    while (cin>>str){

        vector<int> binary;

        while(str.size()!=0){

            int last=str[str.size()-1]-'0';//获取最低位的值
            binary.push_back(last%2);//将最低位对2取模的结果存入向量
            str= divide(str,2);//对2整除，更新字符串
        }

        int sum=0,base=1;
        for (int i = binary.size()-1; i >= 0; --i) {
            sum=sum+binary[i]*base;
            base=base*2;
        }

        cout<<sum<<endl;

    }


}

/*
 * @Description M进制转N进制
 * 先转为10进制，再转为N进制
 * 注意：1、进制大于10时，需实现字符与数字之间的转换
 *           2、将十进制数转为N进制数的方法
 */

//数字转字符
char intToChar(int x){
    if (x<10){
        return x+'0';
    }else{
        return x-10+'a';
    }

}


void Base::f6_4() {
    int M=0,N=0;
    string str;
    while (cin>>M>>N>>str){
        string str1;
        int base=1;//转换的基数
        long long num=0;//定义long long类型保存转换的十进制数

        //将M进制的str转为10进制的num
        for (int i = 0; i < str.size(); ++i) {
            num=num+(str[i]-'0')*base;
            base=base*M;
        }
//        cout<<"十进制数为："<<num<<endl;

        //将num转为N进制
        //不断对N求余，求商，即可得到从低位到高位上的数
        vector<char> answer;
        while (num!=0){
            answer.push_back(intToChar(num % N));
            num=num/N;
        }
        //逆序输出向量数组
        for (int i = answer.size()-1; i >= 0 ; --i) {
            cout<<answer[i];
        }
        cout<<endl;
    }

}




