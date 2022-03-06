/**
* @Author : zhang
* @create 2022/3/6 16:03
*/

/*
 * @Description 拓扑排序
 * 基本思想：
 *    1、从DAG中选择入度为0的顶点，并输出
 *    2、删除该顶点及其所有以它为起点的边
 *    3、重复（1）、（2）直到图为空，或图中不存在入度为0的点
 */
#ifndef OJ_TOPOLOGICALSORT_H

#define OJ_TOPOLOGICALSORT_H


class TopologicalSort {

public:

    /*
     * @Description Legal or Not
     */
    void K11_8();

    /*
     * @Description 确定比赛名次
     */
    void K11_9();

};


#endif //OJ_TOPOLOGICALSORT_H
