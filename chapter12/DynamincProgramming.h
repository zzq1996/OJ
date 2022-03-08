/**
* @Author : zhang
* @create 2022/3/8 15:00
*/

/*
 * @Description 动态规划
 * 将已解决子问题的答案保存下来，在需要子问题答案的时候可直接获得，避免重复计算
 */


#ifndef OJ_DYNAMINCPROGRAMMING_H

#define OJ_DYNAMINCPROGRAMMING_H


class DynamincProgramming {

public:


    /*
     * @Description 递推求解
     *      ——N阶楼梯上楼
     */
    void L12_1();

    /*
     * @Description 最大连续子序列和
     */
    void L12_2();

    /*
     * @Description 最大子矩阵
     */
    void L12_3();


    /*
     * @Description 最长递增子序列
     */
    void L12_4();


    /*
     * @Description 最大上升子序列和
     */
    void L12_5();


    /*
     * @Description 最长公共子序列（Longest Common Subsequence,LCS）
     */
    void L12_6();

    /*
     * @Description 0-1背包
     * 点菜问题
     */
    void L12_7();

    /*
     * @Description 完全背包
     * Piggy-Bank
     */
    void L12_8();


    /*
     * @Description 多重背包
     * 买大米
     */
    void L12_9();


    /*
     * @Description The Triangle
     */
    void L12_10();


    /*
     * @Description Monkey Banana Problem
     */
    void L12_11();



};


#endif //OJ_DYNAMINCPROGRAMMING_H
