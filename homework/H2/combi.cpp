/**
* @Author : zhang
* @create 2022/10/7 19:06
*/
#include <iterator>
#include "combi.h"
#include "iostream"
#include "deque"
#include "vector"


using namespace std;

/*
 * @Description 递归实现
 */

//定义一个双端队列容器(double-ended queue)
deque<int> result;

//定义向量容器，保存二进制数
vector<int> binary;


/*
 * @Description 递归输出k个数的组合
 *
 */
void combi::rec(int n, int k) {
    if(result.size() < k) {
        for(int m = n; m >= 1; --m) {
            result.push_back(m);//在序列的尾部添加一个元素
            rec(m - 1, k);
            result.pop_back();//移除容器头部的元素
        }
    } else {
        copy(result.begin(), result.end(),
             ostream_iterator<int>(cout,","));
        cout << endl;
    }
}

/*
 * @Description 非递归输出k个数的组合
 *
 */
void combi::unRec1(int n, int k) {
    int i=(1<<k)-1;
    int j=(1<<n)-(1<<(n-k));
//    cout<<"i:"<<i<<",j:"<<j<<endl;
    for (int l = i; l <= j; ++l) {
        binary.clear();
        getBinary(l);//将l转为二进制数
        isResult(k);//判断并输出
    }
}


/*
 * @Description 获取二进制串并将其保存在向量容器
 *
 */
void combi::getBinary(int n) {

    while (n!=0){
        binary.push_back(n%2);
        n=n/2;
    }

//    //逆序输出向量
//    for (int i = binary.size()-1; i >=0; --i) {
//        cout<<binary[i];
//    }
//    cout<<endl;
}


/*
 * @Description 遍历二进制串，满足条件输出其下标
 *
 */
void combi::isResult(int k) {

    int count=0;//统计‘1’的个数
    vector<int> location;

    for (int i = binary.size()-1; i >= 0 ; --i) {
        if (binary[i]==1){
            location.push_back(i);//保存‘1’的下标位置
            count++;
        }
    }
    if (count==k){
        for (int i = location.size()-1; i >= 0; --i) {
            cout<<location[i]+1<<" ";
        }
        cout<<endl;
    }

}


/*
 * @Description 若k=3，可用3重循环嵌套输出组合
 *
 */

void combi::unRec2(int n, int k) {

    int* a=new int[n];
    for (int i = 0; i < n; ++i) {
        a[i]=i+1;
    }

    for (a[1] = 1; a[1] <= n; ++a[1]) {
        for(a[2]=a[1]+1; a[2]<=n; ++a[2]){
            for(a[3]=a[2]+1; a[3]<=n; ++a[3]){
                cout<<a[1]<<","<<a[2]<<","<<a[3]<<endl;
            }
        }
    }

}