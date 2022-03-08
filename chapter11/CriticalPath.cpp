/**
* @Author : zhang
* @create 2022/3/6 17:15
*/




#include <vector>
#include "CriticalPath.h"
#include "iostream"
#include "queue"

using namespace std;


/*
 * @Description 安排指令执行顺序
 * 输入N个指令，M个依赖关系，执行一条指令花费1ns
 * 输出执行的最短时间
 */

const int C_MAX=1001;
const int INF=INT_MAX;

struct C_Edge{
    int to;//终点
    int length;//距离
    C_Edge(int t,int l){
        this->to=t;
        this->length=l;
    }

};


vector<C_Edge> C_graph[C_MAX];

int earliest[C_MAX];//最早开始时间

int latest[C_MAX];//最晚开始时间

int C_inDegree[C_MAX];//入度

void criticalPath(int n){
    vector<int> topology;//存储拓扑序列
    queue<int> node;

    for (int i = 0; i < n; ++i) {
        if (C_inDegree[i] == 0){
            node.push(i);
            earliest[i]=1;//所有源点的最早开始时间初始化为1（指令执行时间1ns）
        }
    }

    while (!node.empty()){
        int u=node.front();
        topology.push_back(u);
        node.pop();

        for (int i = 0; i < C_graph[u].size(); ++i) {
            int v=C_graph[u][i].to;
            int l=C_graph[u][i].length;

            earliest[v]= max(earliest[v],earliest[u]+l);

            C_inDegree[v]--;
            if (C_inDegree[v] == 0){
                node.push(v);
            }
        }

    }

    for (int i = topology.size()-1; i >= 0; --i) {
        int u= topology[i];

        if (C_graph[u].size() == 0){
            latest[u]=earliest[u];//汇点的最晚开始时间初始化
        }else{
            latest[u]=INF;//非汇点的最晚开始时间初始化
        }

        for (int j = 0; j < C_graph[u].size(); ++j) {
            int v=C_graph[u][j].to;
            int l=C_graph[u][j].length;
            latest[u]= min(latest[u],latest[v]-l);

        }

    }

}


/*
 * @Description 主程序
 */
void CriticalPath::K11_10() {
    int n=0,m=0;
    while (cin>>n>>m){
        memset(C_graph,0,sizeof(C_graph));
        memset(earliest,0,sizeof(earliest));
        memset(latest,0,sizeof(latest));
        memset(C_inDegree,0,sizeof(C_inDegree));

        while (m--){
            int from,to,length;
            cin>>from>>to>>length;
            C_graph[from].push_back(C_Edge(to,length));
            C_inDegree[to]++;
        }

        criticalPath(n);
        int answer=0;
        for (int i = 0; i < n; ++i) {
            answer= max(answer,earliest[i]);
        }
        cout<<answer<<endl;
    }

}







/*
 * @Description 输出最晚完成实验的时间
 */

const int C_MAX2=1e5+7;
const int INF2=INT_MAX;
const int MOD=1e9+7;

vector<int> C_graph2[C_MAX2];

int C_inDegree2[C_MAX2];//入度

long long earliest2[C_MAX2];//最早开始时间
long long latest2[C_MAX2];//最晚开始时间
long long time2[C_MAX2];//花费时间


long long criticalPath2(int n){

    vector<int> topology;//拓扑排序
    queue<int> node;

    for (int i = 1; i <= n; ++i) {
        if (C_inDegree2[i] == 0){
            node.push(i);
        }
    }

    long long totalTime=0;//总耗时

    while (!node.empty()){

        int u=node.front();
        topology.push_back(u);
        node.pop();

        for (int i = 0; i < C_graph2[u].size(); ++i) {

            int v=C_graph2[u][i];
            earliest2[v]= max(earliest2[v],earliest2[u]+ time2[u]);
            C_inDegree2[v]--;

            if (C_inDegree2[v] == 0){
                node.push(v);
                totalTime= max(totalTime,earliest2[v]+time2[v]);
            }

        }

        for (int i = topology.size()-1; i >=0 ; --i) {
            int u=topology[i];
            if (C_graph2[u].size() == 0){
                latest2[u]=totalTime-time2[u];
            }else{
                latest2[u]=INF2;
            }

            for (int j = 0; j < C_graph2[u].size(); ++j) {
                int v = C_graph2[u][j];
                latest2[u] = min(latest2[u],latest2[v]-time2[u]);
            }

        }

        return totalTime;
    }


}


/*
 * @Description 主程序
 * 输入：
 *  7 5
    11 20 17 10 11 17 17
    5 4
    6 1
    7 3
    2 4
    2 1
  输出：
    0
    -6859
 *
 *
 */
void CriticalPath::K11_11() {

    int n=0,m=0;
    while (cin>>n>>m){

        memset(C_graph2,0,sizeof(C_graph2));
        memset(earliest2,0,sizeof(earliest2));
        memset(latest2,0,sizeof(latest2));
        memset(C_inDegree2,0,sizeof(C_inDegree2));
        memset(time2,0,sizeof(time2));


        for (int i = 1; i <= n; ++i) {
//            scanf("%lld",&time2[i]);
            cin>>time2[i];
        }

        while (m--){
            int from,to;
//            scanf("%d%d",&from,&to);
            cin>>from>>to;
            C_graph2[from].push_back(to);
            C_inDegree2[to]++;
        }

        long long totalTime= criticalPath2(n);
        long long answer=1;

        for (int i = 1; i <= n; ++i) {
            answer = answer * (latest2[i]-earliest2[i]+1);
            answer = answer % MOD;
        }

        printf("%lld\n%lld\n",totalTime,answer);

    }


}
