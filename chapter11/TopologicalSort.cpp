/**
* @Author : zhang
* @create 2022/3/6 16:03
*/



#include <cstring>
#include "TopologicalSort.h"
#include "iostream"
#include "vector"
#include "queue"

using namespace std;

/*
 * @Description 判断师徒关系是否合法
 * 转换为有向图中是否有环？即 是否存在拓扑排序？
 *
 * 将入度为0的点放入队列/栈中
 *
 * 注意计算入度的方法
 */

const int MAX=500;

vector<int> K_graph[MAX];//定义一个向量数组，名称为graph

int K_inDegree[MAX];//入度

/*
 * @Description 拓扑排序
 * 输入n为顶点个数
 */
bool topologicalSort(int n){

    queue<int> node;//定义队列，保存入度为0的结点序号

    for (int i = 0; i < n; ++i) {

        if (K_inDegree[i]==0){
            node.push(i);
        }
    }

    int num=0;//拓扑序列顶点个数

    while (!node.empty()){
        int u=node.front();
        node.pop();

        num++;//拓扑序列顶点个数加1

        for (int i = 0; i < K_graph[u].size(); ++i) {
            int v=K_graph[u][i];
            K_inDegree[v]--;//后继顶点入度减1

            if (K_inDegree[v]==0){
                node.push(v);
            }

        }
    }
    return n==num;//判断能否产生拓扑序列

}


/*
 * @Description 主程序
 */
void TopologicalSort::K11_8() {
    int n=0,m=0;
    while (cin>>n>>m){
        if (n==0 && m==0){
            break;
        }

        memset(K_graph,0,sizeof(K_graph));
        memset(K_inDegree,0,sizeof(K_inDegree));

        while (m--){
            int from,to;
            cin>>from>>to;

            K_graph[from].push_back(to);//初始化图

            K_inDegree[to]++;//初始化入度
        }
        if (topologicalSort(n)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }



}


/*
 * @Description 按照规定输出DAG图的拓扑序列
 * 采用优先队列，确保输出编号小的在前的序列
 */

vector<int> K_graph2[MAX];
int K_inDegree2[MAX];//入度

/*
 * @Description 拓扑排序
 * 返回向量
 */

vector<int> topologicalSort2(int n){
    vector<int> topology;
    priority_queue<int,vector<int>,greater<int>> node;

    for (int i = 1; i <= n; ++i) {//这里的i从1开始

        if (K_inDegree2[i] == 0){
            node.push(i);//将入度为0的结点压入优先队列
        }

    }

    while (!node.empty()){
        int u=node.top();
        node.pop();
        topology.push_back(u);//加入拓扑序列

        for (int i = 0; i < K_graph2[u].size(); ++i) {
            int v=K_graph2[u][i];
            K_inDegree2[v]--;//后继结点入度减1
            if (K_inDegree2[v] == 0){
                node.push(v);
            }
        }

    }
    return topology;

}

/*
 * @Description 主程序
 */
void TopologicalSort::K11_9() {

    int n=0,m=0;
    while (cin>>n>>m){
        memset(K_graph2,0,sizeof(K_graph2));
        memset(K_inDegree2,0,sizeof(K_inDegree2));
        while (m--){
            int from,to;
            cin>>from>>to;
            K_graph2[from].push_back(to);
            K_inDegree2[to]++;
        }
        vector<int> answer= topologicalSort2(n);
        for (int i = 0; i < answer.size(); ++i) {
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }

}
