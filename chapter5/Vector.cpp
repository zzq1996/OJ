/**
* @Author : zhang
* @create 2022/3/1 11:11
*/




#include "Vector.h"
#include "vector"
#include "iostream"

using namespace std;

void Vector::useOfVector() {

    vector<int> mVector;//定义一个vector


    for (int i = 0; i < 5; ++i) { //向尾部逐一添加元素，"0 1 2 3 4 "
        mVector.push_back(i);
    }

    //在头部插入3个15，"15 15 15 0 1 2 3 4 "
    mVector.insert(mVector.begin(),3,15);

    //删除尾部元素，"15 15 15 0 1 2 3 "
    mVector.pop_back();

    //输出：1，下标从0开始
    cout<<"the 5th element of mVector:"<<mVector[4]<<endl;

    //输出：7
    cout<<"the size of mVector:"<<mVector.size()<<endl;

    //删除第5后续的元素
    mVector.erase(mVector.begin()+5,mVector.end());


    //定义迭代器，遍历向量，输出：15 15 15 0 1
    vector<int>::iterator it;
    for (it = mVector.begin();  it!=mVector.end() ; it++) {
        cout<<*it<<" ";
    }

    cout<<endl;

    //遍历向量，输出：15 15 15 0 1
    for (int i : mVector) {
        cout<<i<<" ";
    }


    //清空
    mVector.clear();

}


/*
 * @Description 完数与盈数
 * 数量未知，使用vector保存完数与盈数
 *
 */

//构建函数，返回因子之和
int Sum(int x){
    int sum=0;
    for (int i = 1; i < x; ++i) {
        if(x%i==0){
            sum=sum+i;
        }
    }
    return sum;
}

void Vector::e5_1() {
    vector<int> G;
    vector<int> E;
    for (int i = 2; i <= 60; ++i) {
        if(i==Sum(i)){
//            cout<<"p:"<<i<<endl;
            E.push_back(i);
        }else if(i< Sum(i)){
//            cout<<i<<endl;
            G.push_back(i);
        }
    }

    cout<<"E:";
    for (int i = 0; i < E.size()-1; ++i) {
        cout<<E[i]<<" ";
    }
    cout<<E[E.size()-1]<<endl<<"G:";

    for (int i = 0; i < G.size()-1; ++i) {
        cout<<G[i]<<" ";
    }
    cout<<G[G.size()-1];

}
