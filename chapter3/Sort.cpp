/**
* @Author : zhang
* @create 2022/2/25 19:31
*/




#include <algorithm>
#include "Sort.h"
#include "iostream"

using namespace std;

void Sort::b3_1() {

    int arr[100],n=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    sort(&arr[0],&arr[0]+n);//输入起始地址和结束地址，默认升序排序

    sort(arr,arr+n,greater<int>());//降序排序

    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}


/*
 * @Description 成绩排序
 * 指定排序方式
 */


//封装为一个结构体
struct Student1{
    int number;
    int score;
};

//定义排序函数，对一组基本类型进行排序
bool compare(Student1 x,Student1 y){
    if(x.score==y.score){
        return x.number<y.number;
    }else{
        return x.score<y.score;
    }
}

void Sort::b3_2() {
    Student1 arr[100];
    int n=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i].number>>arr[i].score;
    }
    sort(arr,arr+n, compare);//注意这种写法
    for (int i = 0; i < n; ++i) {
        cout<<arr[i].number<<" "<<arr[i].score<<endl;
    }

}

/*
 * @Description 成绩排序
 * 指定排序方式
 */

//定义结构体，多定义一个变量满足题意
struct Student2{
    string name;
    int score;
    int order;//记录输入次序
};

//定义降序排序
bool compareDescending(Student2 x,Student2 y){
    if (x.score==y.score){
        return x.order<y.order;
    }  else{
        return x.score>y.score;
    }
}

//定义升序排序
bool compareAscending(Student2 x,Student2 y){
    if (x.score==y.score){
        return x.order<y.order;
    }  else{
        return x.score<y.score;
    }
}



void Sort::b3_3() {
    int n=0,type=0;
    cin>>n>>type;
    Student2 arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i].name>>arr[i].score;
        arr[i].order=i;
    }
    if(type==0){
        sort(arr,arr+n, compareDescending);
    }else{
        sort(&arr[0],&arr[0]+n, compareAscending);
    }

    for (int i = 0; i < n; ++i) {
        cout<<arr[i].name<<" "<<arr[i].score<<endl;
    }

}
