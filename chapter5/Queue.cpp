/**
* @Author : zhang
* @create 2022/3/1 12:54
*/

//
// Created by zhang zhiqiang on 2022/3/1.
//


#include <iomanip>
#include "Queue.h"
#include "queue"
#include "iostream"
#include "stack"

using namespace std;

/*
 * @Description 队列操作
 * 队列元素的访问：只能直接获取队头与队尾元素，无法遍历
 */
void Queue::useOfQueue() {
    queue<int> mQueue;//定义int型队列
    //向队头插入元素
    for (int i = 0; i < 10; ++i) {
        mQueue.push(i);
    }
    cout<<"queue front:"<<mQueue.front()
        <<",queue back:"<<mQueue.back()
        <<",queue size:"<<mQueue.size();
    //从队尾删除元素
    mQueue.pop();



}

/*
 * @Description 约瑟夫环
 * 循环队列求解，输出出圈序号
 * 将queue队首元素弹出后，再将其压入队列尾部
 */
void Queue::e5_2() {
    int n,m,p;
    while(cin>>n>>p>>m) {
        if (n == 0 && m == 0 && p == 0) {
            break;
        } else {
            queue<int> mQueue;

            //依次加入队列，n个小孩的编号为1...n
            for (int i = 1; i <= n; ++i) {
                mQueue.push(i);
            }

            //将编号为p的小孩放在队首，先将队头元素出队，再依次放入队尾
            for (int i = 1; i < p; ++i) {
                mQueue.push(mQueue.front());
                mQueue.pop();
            }

            while (!mQueue.empty()) {
                //从队头（第p个小孩开始，将报到m的出队）
                for (int i = 1; i < m; i++) {
//                    cout<<"队头："<<mQueue.front()<<endl;
                    mQueue.push(mQueue.front()); //将第m个小孩之前的小孩压入队列
                    mQueue.pop();//调整循环队列

                }

                if (mQueue.size() == 1) {//最后一个输出不同
                    cout << mQueue.front() << endl;
                } else {
                    cout << mQueue.front() << ",";
                }

                mQueue.pop();
            }
        }
    }

}

/*
 * @Description  猫狗收容所
 * 定义两个队列实现猫狗
 * 每次把动物放入队列时，要添加次序标志。
 */

//结构体动物，存储收养次序（注意这种方法）
struct animal{
    int number;
    int order;

    //构造函数
    animal(int n,int o){
        n=number;
        o=order;
    }

};

void Queue::e5_3() {
    queue<animal> cat;
    queue<animal> dog;
    int n=0,order=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int method,type;
        cin>>method>>type;

        if(method==1){//有动物进入收容所

            if(type>0){
                dog.push(animal(type,order++));
            }else{
                cat.push(animal(type,order++));
            }
        }else{//有人收养动物
            if (type==0 && !dog.empty() && !cat.empty()){
                if (dog.front().order<cat.front().order){
                    cout<<dog.front().number;
                    dog.pop();
                }else{
                    cout<<cat.front().number;
                    cat.pop();
                }
            }else if(type==0 && dog.empty() && !cat.empty()){
                cout<<cat.front().number;
                cat.pop();
            }else if(type==0 && !dog.empty() &&cat.empty()){
                cout<<dog.front().number;
                dog.pop();
            }else if(type==1 && !dog.empty()){
                cout<<dog.front().number;
                dog.pop();
            }else if(type==-1 && !cat.empty()){
                cout<<cat.front().number;
                cat.pop();
            }


        }

        cout<<endl;

    }
}


