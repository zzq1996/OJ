/**
* @Author : zhang
* @create 2022/3/2 21:05
*/

//
// Created by zhang zhiqiang on 2022/3/2.
//


#include "Power.h"
#include "iostream"

using namespace std;

/*
 * @Description 求A^B的最后三位数
 * 任意一个整数n都可分解为若干个2^k之和
 */

/*
 * @Description 返回最后三位数
 * mod:取最后mod位
 */
int fastExponentiation(int a,int b,int mod){

    int answer=1;//初始化为1

    while (b!=0){//不断将b转为二进制数
        
        //若b为奇数，
        if(b%2 == 1){//若当前位为1，累乘a的2^k次幂
            answer=answer*a;
            answer=answer%mod;//求后三位
        }
        //若b为偶数，a不断平方，然后对中间值取模
        b=b/2;
        a=a*a; //a不断平方
        a=a%mod;
    }
    return answer;
}


void Power::f6_10() {
    int a,b;
    while (cin>>a>>b){
        if (a==0 && b==0){
            break;
        }
        cout<<fastExponentiation(a,b,1000)<<endl;
    }

}


/*
 * @Description 矩阵乘积
 * 按照矩阵乘法模拟模拟即可
 */
void Power::f6_11() {

    int a[2][3],b[3][2];

    //注意这种遍历方式
    for (auto & i : a) {
        for (int & j : i) {
            cin>>j;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin>>b[i][j];
        }
    }

    //这里可遍历输出矩阵
    cout<<(a[0][0]*b[0][0]+a[0][1]*b[1][0]+a[0][2]*b[2][0])<<" "
            <<(a[0][0]*b[0][1]+a[0][1]*b[1][1]+a[0][2]*b[2][1])<<endl
            <<(a[1][0]*b[0][0]+a[1][1]*b[1][0]+a[1][2]*b[2][0])<<" "
            <<(a[1][0]*b[0][1]+a[1][1]*b[1][1]+a[1][2]*b[2][1]);
}


/*
 * @Description 求n*n矩阵的k次幂
 * 思路：1、定义结构体Matrix，保存矩阵数组、行数、列数
 *           2、实现两个矩阵乘法，在矩阵幂中被调用
 *           3、实现矩阵幂函数，在测试用例中被调用
 * 
 */

//定义结构体
struct Matrix{
    
    //二位矩阵matrix为结构体的成员变量
    int matrix[10][10];
    
    int row,col;
    
    //构造函数
    Matrix(int row,int  col){
        this->row=row;//行
        this->col=col;//列
    }
    
};


//矩阵乘法函数，这里的行参和返回值都是结构体Matrix类型的x，y
Matrix multiply(Matrix x,Matrix y){
    
    Matrix answer(x.row,y.col);//新建矩阵保存结果
    for (int i = 0; i < answer.row; ++i) {
        for (int j = 0; j < answer.col; ++j) {
            
            answer.matrix[i][j]=0;//初始化成员变量

            //计算矩阵乘法
            for (int k = 0; k < x.col; ++k) {
                answer.matrix[i][j] = answer.matrix[i][j]
                                                        +x.matrix[i][k]*y.matrix[k][j];
            }
        }
    }

    return answer;
    
}


//输出矩阵
void printMatrix(Matrix matrix){
    for (int i = 0; i < matrix.row; ++i) {
        for (int j = 0; j < matrix.col; ++j) {
            if (j != 0){
                cout<<" ";
            }
            cout<<matrix.matrix[i][j];
        }
        cout<<endl;
    }
}


//矩阵x的k次幂
Matrix fastExponentiation(Matrix x,int k){
    //构造一个Matrix结构体，并使用行参x的值初始化成员对象row，col
    Matrix answer(x.row,x.col);

    //将结构体answer内的对象matrix初始化为单位矩阵E
    for (int i = 0; i < answer.row; ++i) {
        for (int j = 0; j < answer.col; ++j) {
            if (i==j){
                answer.matrix[i][j]=1;
            }else{
                answer.matrix[i][j]=0;
            }
        }
    }

    while (k!=0){//不断将k转为二进制

        if (k%2==1){//累乘x的2^k次幂
            answer= multiply(answer,x);
        }

        k=k/2;
        x= multiply(x,x);//x不断平方
    }

    return answer;
}




void Power::f6_12() {
    
    int n,k;
    while(cin>>n>>k){

        //新建结构体并为成员对象赋值
        Matrix x(n,n);

        //初始化结构体x内的成员对象matrix数组
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
            cin>>x.matrix[i][j];
            }
        }


        Matrix answer= fastExponentiation(x,k);
        printMatrix(answer);
    }

//    int a[n][n];
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin>>a[i][j];
//        }
//    }

}
