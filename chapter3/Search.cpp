/**
* @Author : zhang
* @create 2022/2/26 15:09
*/

//
// Created by zhang zhiqiang on 2022/2/26.
//


#include "Search.h"
#include "iostream"

using namespace std;

void Search::c3_4() {
    int n,x;
    cin>>n>>x;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int index=-1;
    for (int i = 0; i < n; ++i) {
        if(arr[i]==x){
            index=i;
        }
    }
    cout<<index;

}

/*
 * @Description 二分查找（对有序数组）
 * int *arr为指向数组的指针
 */
bool binarySearch(const int *arr,int n,int target){
    int left=0,right=n-1;
    while (left<=right){

        int middle=(left+right)/2;

        if(arr[middle]<target){
            left=middle+1;

        }else if(arr[middle]>target){
            right=middle-1;

        } else{
            return true;
        }
    }
    return false;
}


/*
 * @Description 查找
 * 输入：数组 a[1...n]、查找次数m，查找数字b[1...m]
 *
 */
void Search::c3_5() {

    //保存输入的数组
    int n=0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    //保存带查找的元素
    int m=0;
    cin>>m;
    int search[m];
    for (int i = 0; i < m; ++i) {
        cin>>search[i];
    }

    //法一：顺序查找
//    for (int i = 0; i < m; ++i) {
//        string str="NO";
//        for (int j = 0; j < n; ++j) {
//            if(search[i]==arr[j]){
//                str="YES";
//                break;
//            }
//        }
//        cout<<str<<endl;
//    }

    //法二：先排序，再二分查找
    sort(arr,arr+n);
    for (int i = 0; i < m; ++i) {
        if(binarySearch(arr,n,search[i])){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}


