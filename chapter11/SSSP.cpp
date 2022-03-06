/**
* @Author : zhang
* @create 2022/3/6 09:52
*/



#include "SSSP.h"
#include "iostream"
#include "vector"
#include "queue"

using namespace std;


/*
 * @Description 单源最短路径
 * 将s作为源点，利用Dijkstra算法（贪心）
 */

const int K_Max=200;
const int K_INF=INT_MAX;//无穷设为很大的数


struct Edge{

    int to;//终点
    int length;//长度
    Edge(int t,int l){
        this->to=t;
        this->length=l;
    }

};


struct Point{
    int number;//点的编号
    int distance;//源点到该点的距离

    Point(int n,int d){
        this->number=n;
        this->distance=d;
    }

    //重载<比较符
    bool operator< (const Point& p) const{
        return distance>p.distance;//距离小的优先级高
    }
};


vector<Edge> graph[K_Max];//邻接表实现的图
int dis[K_Max];//源点到各点的距离


/*
 * @Description Dijkstra算法
 * s为源点
 */
void Dijkstra(int s){
    priority_queue<Point> myQueue;
    dis[s]=0;

    myQueue.push(Point(s,dis[s]));
    while (!myQueue.empty()){
        int u=myQueue.top().number;
        myQueue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v=graph[u][i].to;
            int d=graph[u][i].length;
            if (dis[v]>dis[u]+d){
                dis[v]=dis[u]+d;
                myQueue.push(Point(v,dis[v]));
            }
        }
    }
}


/*
 * @Description 主函数
 * 输入：3 3 （结点数、路径数）
        0 1 1
        0 2 3
        1 2 1
        0 2（源/终结点）
   输出：2
 */
void SSSP::K11_6() {

    int n,m;
    while (cin>>n>>m){
        memset(graph,0,sizeof(graph));
        fill(dis,dis+n,K_INF);

        while (m--){
            int from,to,length;
            cin>>from>>to>>length;
            graph[from].push_back(Edge(to,length));
            graph[to].push_back(Edge(from,length));

        }

        int s,t;
        cin>>s>>t;
        Dijkstra(s);

        if (dis[t]==K_INF){
            dis[t]=-1;
        }

        cout<<dis[t]<<endl;
    }

}


/*
 * @Description 附加长度和代价的最短路径
 * 输出最短长度及花费；若长度相同，输出花费最少的
 */

struct Edge2{
    int to;//终点
    int length;//长度
    int price;
    Edge2(int t,int l,int p){
        this->to=t;
        this->length=l;
        this->price=p;
    }
};

vector<Edge2> graph2[K_Max];
int cost[K_Max];


/*
 * @Description Dijkstra算法
 * s为源点
 */
void Dijkstra2(int s){
    priority_queue<Point> myQueue;
    dis[s]=0;
    cost[s]=0;

    myQueue.push(Point(s,dis[s]));

    while (!myQueue.empty()){
        int u=myQueue.top().number;//离源点最近的点
        myQueue.pop();
        for (int i = 0; i < graph2[u].size(); ++i) {

            int v=graph2[u][i].to;
            int d=graph2[u][i].length;
            int p=graph2[u][i].price;

            if ((dis[v]==dis[u]+d && cost[v]>cost[u]+p)
                    || dis[v]>dis[u]+d ){
                dis[v]=dis[u]+d;
                cost[v]=cost[u]+p;
                myQueue.push(Point(v,dis[v]));
            }
        }
    }

}


void SSSP::K11_7() {

    int n,m;
    while (cin>>n>>m){
        if (n==0 && m==0){
            break;
        }
        memset(graph2,0,sizeof(graph2));
        fill(dis,dis+n+1,K_INF);
        fill(cost,cost+n+1,K_INF);

        while (m--){
            int from,to,length,price;
            cin>>from>>to>>length>>price;
            graph2[from].push_back(Edge2(to,length,price));
            graph2[to].push_back(Edge2(from,length,price));

        }
        int s,t;//起点与终点
        cin>>s>>t;
        Dijkstra2(s);
        cout<<dis[t]<<" "<<cost[t]<<endl;

    }

}
