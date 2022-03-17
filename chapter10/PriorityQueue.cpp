/**
* @Author : zhang
* @create 2022/3/4 20:57
*/




#include "PriorityQueue.h"
#include "queue"
#include "iostream"

using namespace std;

/*
 * @Description 优先队列模版（STL-priority_queue）
 * 特点：底层用堆实现，默认采用大根堆，只能通过top()访问当前队列中优先级最高的元素
 * 应用场景：
 *      1、求解顺序问题
 *      2、哈夫曼树
 *
 */
void PriorityQueue::J10_0() {
    priority_queue<int> Q;//定义一个优先级队列，数值最大的优先级最高（放在队头）
    Q.push(20);
    Q.push(100);
    Q.push(30);
    Q.push(4);

    cout<<"Q.top:"<<Q.top()
        <<",Q.size:"<<Q.size()<<endl;


    while (!Q.empty()) {
        cout<<Q.top()<<endl;
        Q.pop();
    }

}


/*
 * @Description 输出复数
 * 复数的模：实部与虚部的平方和的正的平方根的值
 * 输入POP; INSERT操作，按照题目要求输出
 * 始终输出队列中模最大的复数
 */

struct complex{
    int real;//实部

    int imag;//虚部

    //构造函数
    complex(int a,int b){
        this->real=a;
        this->imag=b;
    }

    //程序无法比较结构体大小，需重载小于号
    bool operator< (complex c) const{
        return real*real+imag*imag<c.real*c.real+c.imag*c.imag;
    }

};

/*
 * @Description 实现函数
 */
void PriorityQueue::J10_5() {

    int n;//输入行数
    cin>>n;
        priority_queue<complex> Q;
        while (n--){
            string str;
            cin>>str;

            if (str=="Pop"){

                if (Q.empty()){
                    cout<<"empty"<<endl;
                }else{
                    complex current=Q.top();
                    Q.pop();
                    cout<<current.real<<"+"<<current.imag<<"*i"<<endl;
                    cout<<"SIZE="<<Q.size()<<endl;
                }

            }else{
                int a,b;

                //当输入为"Insert 1+i2"时，这样获取a、b的值
                scanf("%d+i%d",&a,&b);

//                cin>>a>>b;
                Q.push(complex(a,b));
                cout<<"SIZE="<<Q.size()<<endl;
            }

        }

}


/*
 * @Description 输出哈夫曼树的权值
 * 路径的长度：从任一结点到达另一结点所经过的边的个数
 *
 * 哈夫曼树的求法：
 *      1、将所有结点放入集合K
 *      2、若集合K中的剩余结点数>1，则取出其中最小的两个结点，将它们两个构成某个新结点的左右子结点，设这个新结点的权值为两个子结点的权值和，并将该新结点放入集合K
 *      3、若集合K中仅有一个结点，则该结点为构造出的哈夫曼树的根结点。
 *      4、所有中间结点的权值和，即为该哈夫曼树的带权路径长度。
 *
 * 输入：叶结点的个数和叶结点的权值
 * 输出：权值
 */

void PriorityQueue::J10_6() {
    int n=0;

    while (cin>>n){
        //重新定义优先队列，采用小根堆实现
        priority_queue< int , vector<int> , greater<int> > Q;

        //数字越小，优先级越高
        while (n--){
            int x;
            cin>>x;
            Q.push(x);
        }

        int answer=0;

        while (1<Q.size()){

            int a=Q.top();
            Q.pop();

            int b=Q.top();
            Q.pop();

            answer=answer+a+b;//取两个最小的数相加

            Q.push(a+b);//将a+b的值重新入队

        }

        cout<<answer<<endl;
    }


}
