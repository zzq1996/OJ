/**
* @Author : zhang
* @create 2022/3/6 17:15
*/


/*
 * @Description 关键路径
 * AOE：边代表活动，有些活动可并行
 * 关键路径：从源点（入度为0）到汇点（出度为0）的最长路径
 *
 * 将求关键路径转换为求每个活动的最早开始时间和最晚开始时间
 *    ——最早开始时间：其先序活动的最晚完成时间
 *    ——最晚开始时间：其全部后序活动的最早开始时间减去该活动所花费的时间
 */


#ifndef OJ_CRITICALPATH_H

#define OJ_CRITICALPATH_H


class CriticalPath {
public:

    /*
     * @Description Instructions Arrangement
     */
    void K11_10();

    /*
     * @Description P3
     */
    void K11_11();

};


#endif //OJ_CRITICALPATH_H
