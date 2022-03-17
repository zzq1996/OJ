/**
* @Author : zhang
* @create 2022/3/5 20:01
*/




/*
 * @Description 散列表
 *      ——根据关键字（key）直接进行访问的数据结构，通过建立关键字和存储位置的直接映射关系（map），便可利用关键码直接访问元素。
 *
 * 映射（map）
 *      ——将关键字（key）和值（value）形成一对映射后进行绑定存储的容器
 *      ——用红黑树实现，内部有序
 *      ——查找效率为O(n*lgn)
 *
 *  无序映射（unordered_map）
 *      ——用散列表实现
 *      ——查找效率为O(1)
 */


#ifndef OJ_HASHTABLE_H

#define OJ_HASHTABLE_H


class HashTable {

public:

    /*
     * @Description 映射的基本操作
     */
    void J10_0();


    /*
     * @Description 查找学生信息
     */
    void J10_7();


    /*
     * @Description 魔咒词典
     */
    void J10_8();

    /*
    * @Description 字串计算
    */
    void J10_9();


};


#endif //OJ_HASHTABLE_H
