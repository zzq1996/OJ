/**
* @Author : zhang
* @create 2022/3/4 14:36
*/

//
// Created by zhang zhiqiang on 2022/3/4.
//


#include "DFS.h"
#include "iostream"
#include "stack"

using namespace std;


/*
 * @Description 找一条骑士可遍历棋盘的路径
 * 骑士在8*8的棋盘上走日，在所有可行的路径中输出字母排序最小的解
 * 搜索三元组(x,y,step)，(x,y)是当前坐标，step是从起点走到该点经过的步数
 * 需要搜索到的最终目标状态为(x,y,step)，其中step=p*q
 *
 *
 */


const int MAX2=30;
int p,q;//棋盘参数
bool visit1[MAX2][MAX2];//标记矩阵

int direction[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},
                     {-2,1},{2,1},{-1,2},{1,2}};

bool DFS1(int x,int y,int step,string ans){
    if (step==p*q){//搜索成功
        cout<<ans<<endl<<endl;
        return true;
    }else{
        for (int i = 0; i < 8; ++i) {//遍历邻居结点
            int nx=x+direction[i][0];//扩展状态坐标
            int ny=y+direction[i][1];
            char col=ny+'A';//该点编号
            char row=nx+'1';

            if (nx<0 || nx>=p || ny<0 || ny>=q || visit1[nx][ny]){
                continue;
            }

            visit1[nx][ny]= true;//标记该点

            if (DFS1(nx,ny,step+1,ans+col+row)){
                return true;
            }
            visit1[nx][ny]= false;//取消标记
        }

    }
    return false;
}

void DFS::I9_3() {
    int n,caseNumber=0;
    cin>>n;
    while (n--){
        cin>>p>>q;
        memset(visit1,false,sizeof(visit1));
        cout<<"Scenario #"<<++caseNumber<<":"<<endl;
        visit1[0][0]= true;//标记A1点
        if (!DFS1(0,0,1,"A1")){
            cout<<"impossible"<<endl<<endl;
        }
    }

}

/*
 * @Description 给出长度各异的木棍，判断能否相连成正方形
 * 计算出总长度/4，求出边长side，将边长排序依次凑side
 * 输入：测试用例数，木棍数，木棍长度
 * 搜索三元组（sum,number,position）
 *      sum：当前拼凑的木坤长度
 *      number：已拼凑成边长的数量（搜到3即可）
 *      position：当前木棍的编号
 * 搜索过程中的剪枝：
 *      1、总长度不能被4整除
 *      2、某条木棍长度大于side
 *      3、拼凑中发现某长度的木棍无法构成当前边，再遇等长木棍即可跳过（需排序）
 */

const int Max=25;
int side;//边长
int m;//棍子数目
int sticks[Max];//记录棍子长度
bool visit2[Max];//标记数组

//定义排序规则，sort默认升序
bool compare1(int x,int y){
    return x>y;
}

/*
 * @Description 判断能否连成正方形
 *
 *  *  sum：当前拼凑的木坤长度
 *      number：已拼凑成边长的数量（搜到3即可）
 *      position：当前木棍的编号
 */
bool DFS2(int sum,int number,int position){
    if (number==3){
        return true;
    }
    int sample=0; //剪枝（拼凑中发现某长度的木棍无法构成当前边，再遇等长木棍即可跳过（需排序））
    for (int i = position; i <m ; ++i) {

        if (visit2[i] || sum+sticks[i]>side || sticks[i]==sample){
            continue;
        }

        visit2[i] = true;

        if (sum+sticks[i] == side){//凑成一条边

            if (DFS2(0,number+1,0)){
                return true;
            }else{
                sample=sticks[i];//记录失败棍子长度
            }

        }else{//凑不成一条边

            if (DFS2(sum+sticks[i],number,i+1)){
                return true;
            }else{
                sample=sticks[i];//记录失败棍子长度
            }

        }

        visit2[i]= false;

    }

    return false;
}




void DFS::I9_4() {

    int n;
    cin>>n;
    while (n--){
        int length=0;//棍子总长度
        cin>>m;//木棍数目
        for (int i = 0; i < m; ++i) {
            cin>>sticks[i];
            length=length+sticks[i];
        }

        memset(visit2, false,sizeof visit2);

        if (length%4 != 0){//剪枝（总长度不能被4整除）
            cout<<"no"<<endl;
            continue;
        }

        side=length/4;//得到边长
        sort(sticks,sticks+m, compare1);//降序排序

        if (sticks[0]>side){//剪枝（某条木棍长度大于side）
            cout<<"no"<<endl;
            continue;
        }

        if (DFS2(0,0,0)){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }

    }
}

/*
 * @Description 在8*8的棋盘上放8个皇后，使其不相互攻击
 * 法一 枚举：
 *      ——从64个格子中选一个子集，使得子集恰好有8个格子，且任意两个选出的格子都不在同一行、同一列或同一对角线上
 *      ——64个格子的子集有2^64个
 *  法二 组合：
 *      ——从64个格子中选8个格子
 * 回溯法（backtracking）：一边生成可能的排列，一边检查
 *      ——恰好每行每列各放置一个皇后，用C[x]表示第x行皇后的列编号，则变成全排列生成问题
 *      ——递归函数不再调用它自身，而是返回上一层调用
 */


void search(int cur){
    int tot=0,n=8;
    int C[8];
    bool vis[8][8];//表示已经放置的皇后占据了哪些行、列、对角线
    memset(vis, false,sizeof (vis));
    if (cur==n){
        tot++;
    } else{
        for (int i = 0; i < n; ++i) {
            //利用二维数组直接判断
            if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){
                C[cur]=i;//将第一个皇后放在第一行第一列
                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]= true;
                search(cur+1);
                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]= false;
            }
        }

    }

    for (int i = 0; i < sizeof C; ++i) {
        cout<<C[i]<<endl;
    }
}

void DFS::I9_5() {

//    search(0);

}
