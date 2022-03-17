/**
* @Author : zhang
* @create 2022/3/4 12:31
*/



/*
 * @Description 宽度优先搜索（Breadth First Search，BFS）：不断优先访问当前结点的邻居
 * 常用于搜索最优值问题
 * 将搜索问题转换为对状态的搜索
 *
 * 1、确定求解问题中的状态，通过状态的扩展，遍历所有状态，从中寻找答案
 * 2、状态扩展方式：对先扩展得到的状态先进行下一次状态扩展
 *      ————实现方式：队列（每次取队头的状态进行扩展，得到的状态依次放入队尾）
 * 3、有效状态：避免无效的状态扩展
 * 4、标记：标记状态是否有效
 */


#include "BFS.h"
#include "queue"
#include "iostream"

using namespace std;


void BFS::I9_0() {



}

/*
 * @Description 找到牛的最短时间
 * key：
 *      1、设置状态为二元组(n,t)，其中n为农夫坐标，t为从起点N到坐标点n所耗费的时间
 *              查找空间：所有可能出现的状态
 *              查找目标：在查找空间里找当n为K时，t为达到这个状态的最小值
 *              一分钟内的合法状态：(n-1,t+1),(n+1,t+1),(2n,t+1)
 *      2、从初始状态（N,0）开始宽度优先搜索，找到（K,t）时，t最短
 *               ——形象上看像是层序遍历
 *      3、构建状态结构体，注意实现细节
 */

//起点N(0<=N<=100000)
const int MAX1=100001;

//新建结构体，保存状态信息
struct Status{

    int n,t;

    Status(int n,int t){
        this->n=n;
        this->t=t;
    }

};

bool visit[MAX1];//标记某一点是否被访问，初始化为false


int BFS1(int n,int k){

    queue<Status> Q;

    Q.push(Status(n,0));//压入初始状态

    visit[n]= true;//标记点n已被访问


    //压入新状态后，立刻标记该状态已被访问
    while (!Q.empty()){//当队里元素不为空

        Status current = Q.front();//保存队头元素
        Q.pop();

        if (current.n==k){
            return current.t;
        }

        for (int i = 0; i < 3; ++i) {
            Status next(current.n,current.t+1);//将当前状态的后三种状态压入队列

            if (i==0){
                next.n=next.n+1;
            }else if (i==1){
                next.n=next.n-1;
            }else{
                next.n=2*next.n;
            }

            if (next.n<0 || next.n>=MAX1 || visit[next.n]){//新状态不合法
                continue;
            }

            Q.push(next);//压入新状态

            visit[next.n]= true;//该点已被访问

        }

    }

}

void BFS::I9_1() {
    int N,K;
    while (cin>>N>>K){
        memset(visit, false,sizeof(visit));//初始化标记数组
        cout<<BFS1(N,K)<<endl;
    }
}


/*
 * @Description 找n(1<=n<=200)的倍数m，满足m(不超过100位)由0和1组成
 * 法一：对n的倍数进行枚举，筛选出m
 * 法二：判断只由0和1组成的数是否是n的倍数（搜索空间更小）
 * ————将0和1组成的数字num作为一个搜索状态，
 *              能由num扩展得到的状态有两个：10*num和10*num+1，
 *              扩展的数字一定比之前大，故不需要标记数组。
 *
 *
 */

void BFS2(int n){
    queue<long long> Q;

    Q.push(1);

    //这里的退出循环条件不对
    while (!Q.empty()){

        long long current=Q.front();//保存当前队头并弹出
        Q.pop();

        if (current % n ==0){//若原队头为n的倍数

            cout<<current<<endl;

        }

        Q.push(current*10);

        Q.push(current*10+1);

    }

}


void BFS::I9_2() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        BFS2(n);
    }



}


