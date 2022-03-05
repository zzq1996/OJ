/**
* @Author : zhang
* @create 2022/2/22 16:38
*/

//
// Created by zhang zhiqiang on 2022/2/22.
//


#include "Brute.h"
#include "iostream"
#include "iomanip"

using namespace std;

void Brute::b2_1() {
    for(int i=0;i<10;++i){
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {

//                int a=i*100+j*10+k;
//                int b=j*100+k*10+k;
//                if((a+b)==532){
//                    cout<<i<<" "<<j<<" "<<k<<endl;
//                }

                    //对等式进行化简，减少运算量
                    if( (i*100+110*j+12*k) ==532){
                        cout<<i<<" "<<j<<" "<<k<<endl;
                    }


            }

        }
    }

}

void Brute::b2_2() {

    for(int i=1000;i<10000;++i){

        //法一：挨个求出位数，重组
        int a=i/1000;
        int b=(i/100)%10;
        int c=(i/10)%10;
        int d=i%10;
        if((9*i) == (d*1000+c*100+b*10+a) ){
            cout<<i<<endl;
        }

        //法二：用下面的函数

    }


}

/*
 * @Description 返回一个数的反序数
 */
int Brute::reverse(int x) {
    int i=0;
    while (x!=0){
        i = i * 10;
        i = i + (x % 10);
        x = x/10;
//        cout<<"x:"<<x<<",i:"<<i<<endl;
    }
    return i;

    /*输入：1234
     * x:123,i:4
        x:12,i:43
        x:1,i:432
        x:0,i:4321
     *
     * */
}

/*
 * @Description 对称平方数
 * @params:
 */
void Brute::b2_3() {
    for(int i=1;i<4;++i){
        cout<<i<<endl;
    }
    for (int i = 4; i < 257; ++i) {
        int b=i*i;
        if( (b) == reverse(b)){
            cout<<i<<endl;
        }
    }

}

/*
 * @Description 输出梯形
 * 转化为二重循环，找出行列的规律，首先找出循环数（行、列数）,再找出输出元素与行列的关系
 */
void Brute::b2_4() {
    int h=0;
    cin>>h;
   int col=(h+1)*2;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < col; ++j) {
            if(j < col-(i+2)*2){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

/*
 * @Description 叠筐
 * 首先用一个缓存数组保存要输出的字符阵列，在该数组上完成排版
 */
void Brute::b2_5() {
    char matrix[80][80];
    int n=0;
    char a,b;

    //接收多组数据
    while(cin>>n>>a>>b){

        for (int i = 0; i <= n/2; ++i) {
            int j=n-i-1;
            int length=n-2*i;//当前圈的边长
            char c;//当前圈的填充字符
            if( (n/2-i) %2==0){
                c=a;
            }else{
                c=b;
            }

            //为当前圈赋值
            for (int k = 0; k < length; ++k) {
                matrix[i][i+k]=c;
                matrix[i+k][i]=c;
                matrix[j][j-k]=c;
                matrix[j-k][j]=c;
            }

        }

        //剔除四个角
        if(n!=1){
            matrix[0][0]=' ';
            matrix[0][n-1]=' ';
            matrix[n-1][0]=' ';
            matrix[n-1][n-1]=' ';
        }

        //逐行逐列打印
        for(int i=0;i<n;++i){
            for (int j = 0; j < n; ++j) {
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
    }

//    bool firstCase=true;//第一组数据标志
//    while (scanf("%d%c%c",&n,&a,&b)!=EOF){
//        !firstCase;
//    }




}

/*
 * @Description 判断瑞年
 */
bool IsLeapYear(int year){
    return (year%4==0 && year%100!=0 || ( year%400 ==0));
}

/*
 * @Description 返回该年年数
 */
int NumberOfYear(int year){
    if(IsLeapYear(year)){
        return 366;
    } else{
        return 365;
    }
}

/*
 * @Description 年份对应天数
 */
int daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


void Brute::b2_6() {
    int year=0,month=0,day=0;
    int num=0;
    while(cin>>year>>month>>day) {//接收多组输入数据

        /*法一：判瑞年出错；
         * */
//        int i=0,count=0;
//        if(year%4==0){
//            i=29;
//        }else{
//            i=28;
//        }
//        switch (month) {
//            case 1:count=day;break;
//            case 2:count=day+31;break;
//
//        }

        /*法二：预处理所有年份的天数并保存
         * */


       int row= IsLeapYear(year);//判断瑞年，选择对应行

        for (int i = 0; i < month; ++i) {
            num=num+daytab[row][i];
        }

        num=num+day;
        cout<<num;
    }


}


/*
 * @Description 给出年份和一年中的第几天，算出几月几号
 */
void Brute::b2_7() {
    int year,month=0,day=0,count;
    while(cin>>year>>count){

        int row= IsLeapYear(year);

        //求出月份
        while(count>daytab[row][month]){
            count=count-daytab[row][month];
            month++;
        }

        day=count;

        //格式化输出，前面补0
        cout<<setw(4)<<setfill('0')<<year
            <<"-"<<setw(2)<<setfill('0')<<month
            <<"-"<<setw(2)<<setfill('0')<<day;
    }



}


/*
 * @Description 计算一个日期加上若干天后是什么日期
 */
void Brute::b2_8() {
    int caseNumber,year,month,day,num;//输入数据组数
    cin>>caseNumber;
    while (caseNumber--){
        cin>>year>>month>>day>>num;
        int row= IsLeapYear(year);

        for (int i = 0; i < month; ++i) {
            num=num+daytab[row][i];
        }

        num=num+day;//先计算出这一天是该年的第几天

        //确定年数
        while (num> NumberOfYear(year)){//日期超过了该年
            num=num- NumberOfYear(year);
            year++;
        }



        month=0;
        row= IsLeapYear(year);
        while (num>daytab[row][month]){
            num=num-daytab[row][month];
            month++;
        }


        day=num;

        cout<<setw(4)<<setfill('0')<<year
            <<"-"<<setw(2)<<setfill('0')<<month
            <<"-"<<setw(2)<<setfill('0')<<day;
    }


    }

    /*
     * @Description 剩下的树
     */
void Brute::b2_9() {
    int l=0,m=0;
    bool arr[10001];
    cin>>l>>m;
    for (int i = 0; i <= l; ++i) {
            arr[i]= true;
    }

    int num=l+1;//树的数量

    while (m--){
        int left,right;
        cin>>left>>right;
        for (int i = left; i <= right; ++i) {//包括端点

            if(arr[i]){
                arr[i]= false;
                num--;
            }

        }

    }
    cout<<num;


}

/*
 * @Description 手机按键
 */
void Brute::b2_10() {
    int keyboard[26]={1,2,3,
                      1,2,3,
                      1,2,3,
                      1,2,3,
                      1,2,3,
                      1,2,3,4,
                      1,2,3,
                      1,2,3,4};
    string str;
    while (cin>>str){
        int time=0;
        for (int i = 0; i < str.size(); ++i) {
            time = time+keyboard[str[i]-'a'];
            if(i!=0 &&str[i]-str[i-1]==keyboard[str[i]-'a']-keyboard[str[i-1]-'a']){
                time=time+2;
            }
        }
        cout<<time;
    }

}




void Brute::b2_11() {
    int n=0;
    while( cin>>n){
        if(n==0){
            break;
        }else{
            int count=0;
                while(n!=1){
                    if(n%2==0){
                        n=n/2;
                    }else{
                        n=(3*n+1)/2;
                    }
                    count++;
            }
            cout<<count<<endl;
        }

    }


}



