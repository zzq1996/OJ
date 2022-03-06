/**
* @Author : zhang
* @create 2022/3/6 10:02
*/


#include "UnionFind.h"
#include "iostream"

using namespace std;


/*
 * @Description 畅通工程
 * 输入N个城市，和已存在的M条路
 * 输出还需多少条路
 *
 * 对已建成的道路，将道路连接的城市所在的集合进行合并，表示这两个集合中的所有结点已经连通
 * 对所有的道路重复该操作，最后计算所有的结点被保存到几个集合中
 */

int father[1000];//父亲结点
int height[1000];//结点高度

int inDegree[1000];//入度
bool f_visit[1000];//标记

//初始化（可复用）
void initial(int n){

    for (int i = 0; i <= n ; ++i) {
        father[i]=i;//每个结点的父亲为自己
        height[i]=0;//每个结点的高度为0
    }

}


//查找根结点（可复用）
int Find(int x){

    //路径压缩
    if (x != father[x]){
        father[x]= Find(father[x]);
    }

    return father[x];
}


//合并集合（可复用）
void Union(int x,int y){
    x= Find(x);
    y= Find(y);

    if (x!=y){//矮树作为高树的子树

        if (height[x]<height[y]){
            father[x]=y;
        }else if (height[y]<height[x]){
            father[y]=x;
        }else{
            father[y]=x;
            height[x]++;
        }

    }
}


void UnionFind::K11_1() {

    int n=0,m=0;
    while (cin>>n){
        if (n==0){
            break;
        }
        cin>>m;

        initial(n);//初始化

        while (m--){
            int x,y;
            cin>>x>>y;
            Union(x,y);//合并集合
        }
        int answer=-1;

        for (int i = 1; i <= n; ++i) {
            if (Find(i)==i){//集合数目
                answer++;
            }
        }

        cout<<answer<<endl;
    }
}


/*
 * @Description 连通图
 * 输入无向图的顶点数N和边数M，所有边，判其是否连通
 *
 * 不断合并图中边相连的两个点所属的集合，最后计算出的集合个数便是连通分量个数
 */


void UnionFind::K11_2() {

    int n=0,m=0;
    while (cin>>n){
        if (n==0){
            break;
        }
        cin>>m;

        initial(n);

        while (m--){
         int x,y;
         cin>>x>>y;
         Union(x,y);//合并集合
        }

        int component=0;//连通分量

        for (int i = 1; i <= n; ++i) {

            if (Find(i)==i){//集合数目
                component++;
            }

        }

        if (component==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;

        }

    }
}


/*
 * @Description is it a tree?
 * 1、由判断各点的入度是否符合要求
 * 2、判断各个结点属于同一集合
 */
void initial2(){
    for (int i = 0; i < 1000; ++i) {
        father[i]=i;
        height[i]=0;
        inDegree[i]=0;
        f_visit[i]= false;
    }
}


bool isTree(){

    bool flag=true;

    int component=0;//连通分量数目

    int root=0;//根结点数目

    for (int i = 0; i < 1000; ++i) {
        if (!f_visit[i]){
            continue;
        }
        if (father[i]==i){
            component++;
        }
        if (inDegree[i]==0){
            root++;
        }else if (inDegree[i]>1){//入度不满足要求
            flag= false;
        }
    }

    if (component!=1 || root!=1){//不满足树定义
        flag= false;
    }

    if (component==0 && root==0){//空集也是树
        flag= true;
    }

    return flag;

}

void UnionFind::K11_3() {

    int x=0,y=0;
    int caseNum=0;
    initial2();
    while (cin>>x>>y){
        if (x==-1 && y==-1){
            break;
        }
        if (x==0 && y==0){
            if (isTree()){
                cout<<"case "<<++caseNum<<" is a tree."<<endl;
            }else{
                cout<<"case "<<++caseNum<<" is not a tree."<<endl;
            }

            initial2();
        } else{
            Union(x,y);
            inDegree[y]++;
            f_visit[x]= true;
            f_visit[y]= true;
        }


    }


}



/*
 * @Description 利用Kruskal算法求最小生成树
 * 输入结点数即相互间的权值，输出最短距离
 *
 * 递增遍历边，若边的两个顶点分属不同集合，则将该边的两个顶点分属的集合合并
 * 遍历所有边后，若图连通，则存在最小生成树，否则不存在
 */


/*
 * @Description 新建边结构体
 */
struct Edge{
    int from;
    int to;
    int length;

    //重载<操作符
    bool operator< (const Edge& e) const{
        return length<e.length;
    }

};


Edge edge[100*100];//边集
int father2[100];//父亲结点
int height2[100];//结点高度

//初始化（可复用）
void initial2(int n){

    for (int i = 0; i <= n ; ++i) {
        father2[i]=i;//每个结点的父亲为自己
        height2[i]=0;//每个结点的高度为0
    }

}


//kruskal算法
int Kruskal(int n,int edgeNum){

    initial2();
    sort(edge,edge+edgeNum);//按权值排序
    int sum=0;

    for (int i = 0; i < edgeNum; ++i) {
        Edge current=edge[i];

        if (Find(current.from) != Find(current.to)){
            Union(current.from,current.to);
            sum=sum+current.length;
        }

    }

    return sum;

}


/*
 * @Description 实现函数
 */
void UnionFind::K11_4() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        int edgeNum=n*(n-1)/2;
        for (int i = 0; i < edgeNum; ++i) {
            cin>>edge[i].from>>edge[i].to>>edge[i].length;
        }
        int answer= Kruskal(n,edgeNum);
        cout<<answer<<endl;
    }
}



/*
 * @Description 输入结点数和修建状态
 *
 */
void UnionFind::K11_5() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        int edgeNum=n*(n-1)/2;
        for (int i = 0; i < edgeNum; ++i) {
            int status;
            cin>>edge[i].from>>edge[i].to>>edge[i].length;
            if (status==1){
                edge[i].length=0;
            }
        }
        int answer= Kruskal(n,edgeNum);
        cout<<answer<<endl;
    }
}


