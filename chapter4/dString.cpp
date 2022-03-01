/**
* @Author : zhang
* @create 2022/2/26 15:48
*/

//
// Created by zhang zhiqiang on 2022/2/26.
//

#include "string"
#include "dString.h"
#include "iostream"

using namespace std;

/*
 * @Description 特殊的乘法
 * 将输入的整数转为字符串
 * C++中size和length没啥区别
 * string[i]为char类型，char转int要-'0'，int转char要+'0'
 */
void dString::d4_1() {
    string string1,string2;

    while (cin>>string1>>string2){//接收多组输入数据
        int answer=0;

//        for (int i = 0; i < string1.length(); ++i) {
//            for (int j = 0; j < string2.length(); ++j) {
//                answer=answer+string1[i]*string2[j];
//            }
//        }

        //注意这种写法
        for (char i : string1) {
            for (char j : string2) {
                answer=answer+(i-'0')*(j-'0');
            }
        }
        cout<<answer<<endl;

    }

}

/*
 * @Description 密码翻译
 * 本题的输入是一行字符串，若使用cin，遇到空格就会停止输入；
 * 使用getline()函数获取整行字符串
 */
void dString::d4_2() {
    string str;
    while (getline(cin,str)){

        for (char & i : str) {
            if(i=='z' || i=='Z'){
                i=i-25;
            } else if (i>='a' && i<='z'
                || i>='A' && i<='Z' ){
                i=i+1;
            }
        }
        cout<<str<<endl;
    }

}

/*
 * @Description 简单密码
 * 对字母执行减法后，再对字母个数26取模
 */
void dString::d4_3() {
    string str;
    while (getline(cin,str)){
        if(str!="START" && str!="END" ){
            if(str=="ENDOFINPUT"){
                break;
            }else{
                for (char & i : str) {
                    if(i>='A'&&i<='Z'){
                        i=(i-'A'-5+26)%26+'A';
                    }
                }
                cout<<str<<endl;
            }
        }

    }

}

/*
 * @Description 统计字符
 */
void dString::d4_4() {
    string str1,str2;

    //ASCII为7位比特编码，转换为十进制整数范围：0～127
    int number[128];//定义一个数组记录str2中所有字符出现的频率

    while(getline(cin,str1)){
        if(str1 == "#"){
            break;
        }else{
            getline(cin,str2);

            memset(number,0,sizeof(number));//初始化数组

            //记录str2中所有字符的出现频率
            for(int i =0;i< str2.length();++i){
                number[str2[i]]++;
            }

            //输出str1中字符出现的次数
            for (int i = 0; i < str1.length(); ++i) {
                cout<<str1[i]<<" "<<number[str1[i]];
            }

        }

    }
    

}

/*
 * @Description 统计大写字母出现个数
 * 需定义一个大小为26的数组
 */
void dString::d4_5() {
    int num[26];

    string str1;
    while (getline(cin,str1)){
        memset(num,0,sizeof(num));
        for (int i = 0; i < str1.length(); ++i) {
            if('A'<=str1[i] && str1[i]<='Z'){
                num[str1[i]-'A']++;//str1的元素从A开始
            }
        }
        for (int i = 0; i < 26; ++i) {
            //这里注意强制类型转换
            cout<<char('A'+i)<<":"<<num[i]<<endl;
        }

    }


}


/*
 * @Description KMP算法
 */

const int MAXM=10000;

int nextTable[MAXM];


//创建next表，m为模式串长度
void getNextTable(string pattern){
    int m=pattern.length();
    int j=0;
    nextTable[j]=-1;
    int i=nextTable[j];
    while (j<m){
        if (i==-1 || pattern[j]==pattern[i]){
            i++;
            j++;
            nextTable[j]=i;
        }else{
            i=nextTable[i];
        }
    }

}


//进行kmp匹配，n、m分别为字符串长度
//返回首次匹配成功位置
int kmp(string& text,string& pattern){
    getNextTable(pattern);
    int n=text.length();
    int m=pattern.length();
    int i=0,j=0,number=0;
    while(i<n){

        if (j==-1 || text[i]==pattern[j]){//匹配成功
            i++;
            j++;
        }else{
            j=nextTable[j];//匹配失败
        }


        if(j==m){
            number++;
            j=nextTable[j];
        }
    }

    return number;



}


void dString::d4_6() {

    int caseNum=0;
    cin>>caseNum;
    while(caseNum--){
        int n,m;
        cin>>n>>m;
        string text,pattern;

        //为主串赋值
        for (int i = 0; i < n; ++i) {
            cin>>text[i];
        }
        //为模式串赋值
        for (int i = 0; i < m; ++i) {
            cin>>pattern[i];
        }

        //KMP
        cout<<kmp(text,pattern);
    }


}


