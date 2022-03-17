/**
* @Author : zhang
* @create 2022/3/3 15:49
*/



/*
 * @Description 贪心算法
 * 特点：
 *          1、适用于组合优化问题
 *          2、总是作出局部最优解
 *
 * 要求：
 *      1、问题具有最优子结构性质——即一个问题的最优解包含其子问题的最优解
 *      2、该问题无后效性
 *
 * 关键：构建贪心策略
 */



#include "Greed.h"
#include "iostream"

using namespace std;

/*
 * @Description 鸡兔同笼
 * 没想到除4之后对2取余
 */
void Greed::g7_1() {
    int num;//脚的数量
    while (cin>>num){
        if(num%2 == 0){
//            cout<<num/4<<" "<<num/2<<endl;
            cout<<num/4+(num%4)/2<<" "<<num/2<<endl;
        }
    }
}


/*
 * @Description 买咖啡
 * 将咖啡的重量和价格封装在结构体中，保存在数组
 * 定义排序方式，优先购买性价比高的咖啡
 *
 * 难点：构建结构体，进行排序。
 */

const int MAX=1000;

//新建结构体，保存咖啡重量和价格
struct JavaBean{
    double weight;
    double cost;
};


JavaBean arr[MAX];

//定义排序函数，用于指定sort排序方式
bool compare(JavaBean javaBean1,JavaBean javaBean2){
    return ((javaBean1.weight/javaBean1.cost)>(javaBean2.weight/javaBean2.cost));
}

void Greed::g7_2() {
    int m,n;
    while (cin>>m>>n){
        //输入重量和价格
        for (int i = 0; i < n; ++i) {
            cin>>arr[i].weight>>arr[i].cost;
        }

        //按照性价比降序
        sort(arr,arr+n, compare);

        double answer=0;//能够购买的咖啡重量

        for (int i = 0; i < n; ++i) {

            if (m>=arr[i].cost){//如果能全部买下
                m=m-arr[i].cost;
                answer=answer+arr[i].weight;
            }else{//买不了这么多
                answer=answer+arr[i].weight * (m/arr[i].cost);
            }
        }
        cout<<answer<<endl;

    }

}


/*
 * @Description 薛姐姐的枪
 * 思路：要使a[i]-b[j]最大化，只需将a[n]，b[m]排序，依次用最大的-最小的
 */

const int MAXN=100001;
long long gun[MAXN];
long long monster[MAXN];

bool compare2(long long x,long long y){
    return x>y;
}


void Greed::g7_3() {
    int caseNum;//n,m分别为枪的数量和怪物的数量
    cin>>caseNum;
    while (caseNum--){
        int n,m;
        cin>>n>>m;

        //为枪赋值
        for (int i = 0; i < n; ++i) {
            cin>>gun[i];
        }
        //为怪物赋值
        for (int i = 0; i < m; ++i) {
            cin>>monster[m];
        }

        //sort默认升序排列
        sort(gun,gun+n, compare2);
        sort(monster,monster+m);

        long long answer=0;

        for (int i = 0; i < n; ++i) {
            //注意这里退出循环的条件：怪物没有了/出现赋值
            if (i>=m || gun[i]<=monster[i]){
                break;
            }

            answer=answer+(gun[i]-monster[i]);
        }

        cout<<answer;
    }
}


/*
 * @Description 看尽量多的完整节目
 * 在最优解中，观看的第一个节目一定是结束时间最早的（保证剩余观看时间最大化）
 * 思路：
 *      对所有的节目按照结束时间的早晚进行排序，然后按照这一顺序逐一对节目进行判断：
 *          1、若当前时间可看完该节目（当前时间小于该节目的开始时间），则选择该节目，并将当前时间改为该节目的结束时间
 *          2、若当前时间不可看完该节目，则判断下一个
 *
 */

//构建结构体，保存节目信息
struct show{
    int start;
    int end;
};

show show_arr[100];//新建数组，保存节目

//按结束时间升序排序
bool compare_show(show x,show y){
    return x.end<y.end;
}

void Greed::g7_4() {

    int n;//n为节目数量

    while (cin>>n){
        if (n==0){
            break;
        }

        //初始化节目清单
        for (int i = 0; i < n; ++i) {
            cin>>show_arr[i].start>>show_arr[i].end;
        }

        //按照结束时间升序排序，结束时间越短，剩余观看时间越长
        sort(show_arr,show_arr+n, compare_show);

        int current_time=0;//设置当前时间

        int answer=0;

        for (int i = 0; i < n; ++i) {

            if (current_time<=show_arr[i].start){//可以完整看完该节目
                current_time=show_arr[i].end;//修改当前时间
                answer++;//看的节目数加1
            }

        }

        cout<<answer<<endl;

    }

}


/*
 * @Description 在岛之间架桥
 */
void Greed::g7_5() {



}
