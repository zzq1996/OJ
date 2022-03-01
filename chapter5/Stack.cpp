/**
* @Author : zhang
* @create 2022/3/1 16:11
*/

//
// Created by zhang zhiqiang on 2022/3/1.
//


#include <iomanip>
#include "Stack.h"
#include "iostream"
#include "stack"

using namespace std;

/*
 * @Description 栈的基本操作
 * 操作受限的线性表，只能由top访问栈顶元素
 */
void Stack::useOfStack() {
    stack<int> mStack;
    for (int i = 0; i < 10; ++i) {
        mStack.push(i);
    }
    cout<<mStack.size();
    int sum=0;
    if(!mStack.empty()){
        sum=sum+mStack.top();
        mStack.pop();
    }
    cout<<sum;
}


/*
 * @Description 逆序输出
 */
void Stack::e5_4() {
    //输入整数序列范围较大，故使用long long
    stack<long long> mStack;
    int n=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        long long num;
        cin>>num;
        mStack.push(num);
    }
    while (!mStack.empty()){
        cout<<mStack.top()<<" ";
        mStack.pop();
    }

}


/*
 * @Description 括号匹配
 * 从左到右遍历字符串，将左括号放入栈中。
 * 遇到右括号：若栈为空，则匹配失败；若栈不为空，弹出栈顶左括号
 * 当字符遍历完成，若栈非空，则左括号匹配失败
 */


void Stack::e5_5() {

    string str;
    while(getline(cin,str)){
        stack<int> mStack;//设置栈存储括号的下标
        string answer(str.size(),' ');//设置输出字符串，初始化为空格
        for (int i = 0; i < str.size(); ++i) {

            if(str[i]=='('){
                mStack.push(i);//注意：这里压入的是左括号的下标


            }else if(str[i]==')'){
                //若栈不为空，则匹配成功
                if(!mStack.empty()){
                    mStack.pop();
                }else{
                    answer[i]='?';
                }
            }
        }

        //对输入字符遍历完成后，判断左括号是否匹配成功
        while (!mStack.empty()){
            answer[mStack.top()]='$';
            mStack.pop();
        }

        cout<<str<<endl<<answer<<endl;
    }



}


/*
 * @Description 简单计算器
 * 设置两个栈；
 * 运算栈中放置"#"，其优先级最低；
 * 表达式尾部添加"$"，其优先级最低；
 * 遍历到运算符，进行优先级比较；
 * 遍历到运算数，直接压栈。
 *
 */

//返回给定字符的优先级
int priority(char c){
    if (c=='#'){
        return 0;
    }else if (c=='$'){
        return 1;
    }else if (c=='+'||c=='-'){
        return 3;
    }

}


//获得下个数字
double getNum(string str,int& index){
    double result=0;

    while (isdigit(str[index])){//判断str[index]是否为非0数字

        result=result*10+str[index]-'0';
        index++;
    }
    return result;

}


//返回计算结果
double calculate(double x,double y,char op){
    double result=0;
    if(op=='+'){
        result=x+y;
    }else if(op=='-'){
        result=x-y;
    }else if(op=='*'){
        result=x*y;
    }else if(op=='/'){
        result=x/y;
    }
    return result;

}

//计算器
void Stack::e5_6() {
    string str;
    while (getline(cin,str)){
        if (str=="0"){
            break;
        }
        int index=0;
        stack<char> oper;
        stack<double> data;
        str=str+'$';
        oper.push('#');
        while (index<str.size()){
            if(str[index]==' '){
                index++;
            }else if(isdigit(str[index])){
                data.push(getNum(str,index));
            }else{
                if(priority(oper.top())< priority(str[index])){
                    oper.push(str[index]);
                    index++;
                }else{
                    double y=data.top();
                    data.pop();
                    double x=data.top();
                    data.pop();
                    data.push(calculate(x,y,oper.top()));
                    oper.pop();
                }

            }

        }

        cout<<fixed<<setprecision(2)<<data.top();
    }

}


