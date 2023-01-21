//
// Created by zhang on 10/3/22.
//

#ifndef OJ_TOPOLOGY_H
#define OJ_TOPOLOGY_H

/* 问题描述：
 *  输入：集合的元素数n
 *  输出：所有拓扑及数量
 *
 * 实验要求：
 *  1、记录不同n程序运行时间
 *  2、把函数InFamily改成二分查找
 *  3、不用集族编码，修改程序，n可大于5
 * */


class topology {

public:
    static void CountTp1(int n);//主函数1
    static void Family(int* T,int f,int n);//把集族f变成数组T
    static bool InFamily(int* T,int A);//搜索A是否在T中
    static bool IsTP(int* T);//判断T是否为拓扑
    static void outTP(int* T);//输出拓扑T
    static void comb1(int* T,int p,int q);//递归生成可行集族（P个数取q个数的组合）
    static void CountTp2(int n);//主函数2
    static void CountTp3(int n);//主函数3
    static void comb2(int* T,int p,int q);//递归生成可行集族（P个数取q个数的组合）

};


#endif //OJ_TOPOLOGY_H
