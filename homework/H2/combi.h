//
// Created by zhang on 10/7/22.
//

#ifndef OJ_COMBI_H
#define OJ_COMBI_H

/*
 * @Description 从1...n取出k个数的组合(k=1，…，n)，输出不同的组合
 */

class combi {

public:
    static void rec(int n,int k);
    static void unRec1(int n,int k);
    static void unRec2(int n,int k);
    static void getBinary(int n);
    static void isResult(int k);
};


#endif //OJ_COMBI_H
