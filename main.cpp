#include <iostream>
#include "homework/H2/combi.h"
#include "time.h"

using namespace std;


int main() {

    clock_t start,end;//定义clock_t变量
    start = clock();  //开始时间

//    combi().unRec1(20,6);
    combi().rec(10,5);

    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;  //输出时间（单位：ｓ

    return 0;
}
