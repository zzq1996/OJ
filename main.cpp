#include <iostream>
#include <iterator>
#include "time.h"
#include "homework/H3_RoundRobinTable/schedule.h"
#include "vector"

using namespace std;


int main() {

    clock_t start,end;//定义clock_t变量
    start = clock();  //开始时间

    int k;
    cout<<"输入运动员的人数:";
    cin >> k;
    int ** p = new int*[k];
    //赛程表初始化
    for (int i = 0; i < k; i++)
    {
        p[i] = new int[k];
        p[0][i] = i + 1;
        p[i][0] = i + 1;
    }
    //运行函数
    schedule().Table(p, 0, 0, k);
    //输出结果
    cout << "循环赛日程表（递归法）:" << endl;
    for (int i = 0; i < k; i++)
    {
        copy(p[i], p[i] + k, ostream_iterator<int>(cout, " "));
        cout << endl;
    }


    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;  //输出时间（单位：ｓ

    return 0;
}
