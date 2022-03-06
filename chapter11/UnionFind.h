/**
* @Author : zhang
* @create 2022/3/6 10:02
*/


/*
 * @Description 并查集（Union Find）
 * 常用功能：
 *   1、判断任意两个元素是否属于同一集合（Find）
 *   2、按照要求合并不同的集合（Union）
 *       ——通常将树低的并向数高的
 * 路径压缩：在查找某个特定结点的根结点的同时，将其与根结点之间的所有结点都直接指向根结点
 */

#ifndef OJ_UNIONFIND_H

#define OJ_UNIONFIND_H


class UnionFind {
public:

    /*
     * @Description 畅通工程
     */
    void K11_1();

    /*
     * @Description 连通图
     */
    void K11_2();

    /*
     * @Description Is it a tree?
     */
    void K11_3();

    /*
     * @Description 最小公路长度
     */
    void K11_4();


    /*
     * @Description 最小公路长度
     */
    void K11_5();

};


#endif //OJ_UNIONFIND_H
