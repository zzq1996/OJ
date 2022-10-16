//
// Created by zhang on 10/3/22.
//

#include "topology.h"
#include "iostream"
//#include "omp.h"

using namespace std;


int topoCount=0;//记录满足拓扑数


/*
 * @Description 主函数
 */
void topology::CountTp1(int n) {
    //初始化长度为2^n+1的数组T
//    int T_size=int(pow(2,n)+1);
    int T_size=(1<<n)+1;//存储集族f的数组T的元素数量
    int* T;//初始化长度为2^n+1的数组T
    T = new int[T_size]();//申请保存集族的数组

//    int SumFamily=int(pow(2,pow(2,n)-2));
    int SumFamily=1<<((1<<n)-2);//可行集族的总数

    int topoCount=0;//记录满足拓扑数

    for (int f = 0; f < SumFamily; ++f) {
        Family(T,f,n);
        if(IsTP(T)){
            topoCount++;
            outTP(T);
        }
    }
    cout<<topoCount<<endl;
}

/*
 * @Description 把集族f变成数组T
 */
void topology::Family(int* T,int f,int n) {
    T[0]=1;
    for (int i = 1; f!= 0; i++) {
        if(f&1){
            T[++T[0]]=i;
        }
        f = f>>1;
    }
//    T[++T[0]]=int(pow(2,n)-1);
    T[++T[0]]=(1<<n)-1;
}



/*
 * @Description 搜索A是否在T中
 */
bool topology::InFamily(int* T,int A) {
    int left=1,right=T[0];
    while (left<=right){
        int middle=(left+right)/2;
        if(T[middle]<A){
            left=middle+1;
        }else if(T[middle]>A){
            right=middle-1;
        } else{
            return true;
        }
    }
    return false;
}



/*
 * @Description 判断T是否为拓扑
 */
bool topology::IsTP(int* T) {
    for (int i = 2; i < T[0]; ++i) {
        for (int j = i+1; j <= T[0]; ++j) {
            //若T[i]与T[j]的交或并不在T中，则返回false
            bool in= InFamily(T,T[i]&T[j]);
            bool uni= InFamily(T,T[i]|T[j]);
            if (!(in && uni)){
                return false;
            }
        }
    }
    return true;
}



/*
 * @Description 输出拓扑T
 */
void topology::outTP(int* T) {
    for (int i = 0; i <= T[0]; ++i) {
        cout<<T[i]<<" ";
    }
    cout<<endl;
}


/*
 * @Description 递归生成可行集族（P个数取q个数的组合）
 */

void topology::comb1(int* T,int p, int q) {
    if (q == 0) {
        if (IsTP(T)) {
            //输出拓扑并计数
            outTP(T);
            topoCount++;
        }
    } else {
        for (int i = q; i <= p; ++i) {
            T[q + 1] = i;
            comb1(T,i - 1, q - 1);
        }
    }
}



/*
 * @Description tp
 */
void topology::CountTp2(int n) {
    //初始化长度为2^n+1的数组T
    int T_size = (1 << n) + 1;//存储集族f的数组T的元素数量
    int* T;
    T = new int[T_size]();
    //最大子集（全集）为2^n-1
    int Xn = (1 << n) - 1;

    for (int m = 0; m < Xn; ++m) {
        T[0] = m + 2;//集族的长度
        T[1] = 0;
        T[T[0]] = Xn;
        comb1(T,Xn - 1, m);
    }
    cout << topoCount << endl;
}

/*
 * @Description 主函数3
 */


void topology::CountTp3(int n) {
    //初始化长度为2^n+1的数组T
    int T_size = (1 << n) + 1;//存储集族f的数组T的元素数量
    //最大子集（全集）为2^n-1
    int Xn = (1 << n) - 1;
    int* T;


#pragma omp parallel for
    {
        for (int m = 0; m < Xn; ++m) {
            T = new int[T_size]();
            T[0] = m + 2;//集族的长度
            T[1] = 0;
            T[T[0]] = Xn;
            comb2(T, Xn - 1, m);
        }
    }

    cout << topoCount << endl;

}

/*
 * @Description 使用OpenMP实现并行计算
 *
 */
void topology::comb2(int* T,int p, int q) {
    if (q == 0) {
        if (IsTP(T)) {
            //输出拓扑并计数
#pragma omp  critical
            outTP(T);
            topoCount++;
        }
    } else {
        for (int i = q; i <= p; ++i) {
            T[q + 1] = i;
            comb2(T,i - 1, q - 1);
        }
    }
}