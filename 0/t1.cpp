/**
* @Author : zhang
* @create 2022/2/14 14:57
*/


#include "t1.h"
#include "iostream"

using namespace std;


/*
 * @Description 交换数值
 */
void t1::swap(int* a, int* b) {

    //法一：借助中间变量
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;

    //法二
//    *a=*a+*b;
//    *b=*a-*b;
//    *a=*a-*b;
}


/*
 * @Description 求两个正整数的最大公因数
 * 两个数的最大公约数 等于 其中较小的数字和两者之间余数的最大公约数
 * GCD（较大数，较小数）= GCD（较小数，二者余数）
 * GCD（被除数，除数）= GCD（除数，余数）
 */
int t1::gcd(int a, int b) {
    int d;
    //法一
    d=(a<=b) ? a : b;
    while (d>1){
        if(a%d==0 && b%d==0){
            break;
        }
        d--;
    }
    return d;

    //法二：辗转相除法
    return (b==0) ? a :  gcd(b,a%b);
}


/*
 * @Description 汉诺塔
 */
void t1::hanoi(char x, char y, char z, int n) {
    if(n==1){
        cout<<"1:"<<x<<"→"<<y<<endl;
    }else{
        hanoi(x,z,y,n-1);
        cout<<n<<":"<<x<<"→"<<y<<endl;
        hanoi(z,y,x,n-1);
    }
}


/*
 * @Description 回文数
 */
bool t1::isHui(int n) {

    //法一：翻转后比较
    int reversedInteger=0,remainder=0,originalInteger=n;

    //翻转
    while(n!=0)
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10+remainder;
        n=n/10;
        cout<<n<<""<<remainder<<""<<reversedInteger<<endl;
    }

    //判断
    if(originalInteger==reversedInteger){
        cout<<originalInteger<<"是回文数"<<endl;
        return true;
    }else{
        cout<<originalInteger<<"不是回文数"<<endl;
        return false;
    }


    //法二：用数组实现
    int count=1,y=n;

    bool r=true;

    if(n/10==0){
        r=false;
    }else{
        while(y/10!=0){//求出x的位数
            y=y/10;
            count++;
        }
    }

    //新建一个数组保存各个位数
    int a[count];

    //控制变量，取x的各位位数
    int i=1;
    //定义两个指针分别指向数组的头/尾，控制遍历条件并赋值
    for(int *p=&a[count-1],*q=&a[0] ; p>=q ; --p){
        *p = (n%(i*10))/(i);
        i=i*10;
    }
    //定义两个指针分别指向数组的头/尾，比较元素是否相同
    for(int *p=&a[0],*q=&a[count-1];p<=q;p++,q--){
        if(*p != *q){
            r=false;
        }
    }
    return r;


    //法三：用字符串保存输入的整数，再比较
    string str;
    while (cin>>str){
        for (int i = str.size()-1; i >=0 ; --i) {
            cout<<str[i];
        }
        cout<<endl;
    }

}


/*
 * @Description 求n！
 */
int t1::getFactorial(int n) {
    int sum=1;

    if(n==0){
        return 1;
    }else if(n<0){
        return -1;
    }else {

        //法一:for循环
        for (int i = 1; i <= n; ++i) {
            sum =sum*i;
        }
        return sum;

        //法二：do-while循环
        do{
            sum=sum*n;
            n--;
        } while (n==0);

        //法三：while循环
        while(n>0){
            sum=sum*n;
            n--;
        }

        //法四：递归
        if(n==0){
            return 1;
        }else{
            return n*getFactorial(n-1);
        }


    }



}


/*
 * @Description 数字转字符串
 */
void t1::int_to_string(int n, char *str) {
    //char转int：char-‘0’
    //int转char：int+‘0’

    int count=1,y=n;
    if(n>=0){//非负数
        if(n/10!=0){
            while(y/10!=0){//求出x的位数
                y=y/10;
                count++;
            }
            int i=1;//控制变量，取x的各位位数
            for(int h=1;h<count;h++){
                i=i*10;
            }
            for(int j=0;j<count;j++){//通过指针访问数组元素
                *(str+j)=(n/i)+'0';
                n=n%i;
                i=i/10;
            }
        }else{
            //一位数
            *str=n+'0';
        }

        //for(intj=0;j<count;j++){//通过指针访问数组元素
        //cout<<*(str+j);
        //}

    }else{//负数
        *str='-';
        int m=-n,o=-n;
        count=1;
        if(m/10!=0){
            while(o/10!=0){//求出x的位数
                o=o/10;
                count++;
            }
            int i=1;//控制变量，取x的各位位数
            for(int h=1 ; h<count ; h++){
                i=i*10;
            }
            for(int j=1 ; j<=count ; j++){//通过指针访问数组元素
                *(str+j)=(m/i)+'0';
                m=m%i;
                i=i/10;
            }
        }else{
            //一位数
            *(str+1)=n+'0';
        }
        //for(intj=0;j<=count;j++){//通过指针访问数组元素
        //cout<<*(str+j);
        //}
    }

}


/*
 * @Description 约瑟夫环
 * N个小孩，报到M离开，输出最后离圈的孩子编号
 */
void t1::josephus(int N, int M) {

    //将该数组看作循环数组，即数组的最后一个元素in_circle(N-1)下一个元素是in_circle(0)
    bool in_circle[N];
    //index表示要报数的小孩的下标，初始值为N-1
    int num_of_children_remained,index;

    //初始化数组in_circle
    for(int i=0;i<N;++i){
        in_circle[i]=true;
    }

    //开始报数
    index=N-1;//从编号为0的小孩开始报数，index为前一个小孩的下标
    num_of_children_remained = N;//报数前圈子中小孩的数量
    while(num_of_children_remained > 1){
        int count=0;
        while(count < M){//对成功的报数进行计数
            index = (index+1)%N;//计算要报数的小孩的编号
            if(in_circle[index]){
                count++;//如果编号为index的小孩在圈子里，则该报数为成功的报数
            }
        }
        in_circle[index] = false;//小孩离开圈子
        num_of_children_remained--;//圈中小孩数减1
    }

    //找到最后一个小孩
    for(index=0 ; index<N ; index++){
        if(in_circle[index]){
            break;
        }
    }
    cout<<"The winner is No."<<index<<"\n";
}




