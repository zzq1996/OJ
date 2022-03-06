/**
* @Author : zhang
* @create 2022/3/5 20:01
*/

//
// Created by zhang zhiqiang on 2022/3/5.
//


#include "HashTable.h"
#include "map"
#include "iostream"

using namespace std;


/*
 * @Description Map
 * 将关键字和值形成一对映射，由关键字查找值。
 */
void HashTable::J10_0() {
    //映射的定义，参数1：关键字(key)类型、参数2：值(value)类型
    map<string,int> myMap;

    //添加元素的两种方式
    // map重载了[ ]运算符，故可通过[key]访问元素
    myMap["Emma"]=67;
    myMap.insert(pair<string,int>("Benedict",100));
    myMap.insert(pair<string,int>("Bob",60));


    //对值的访问
    cout<<"myMap size:"<<myMap.size()
        <<"\nEmma score:"<<myMap["Emma"]//由关键字key输出对应信息value
        <<"\nBenedict score:"<<myMap.at("Benedict")
        <<"\nthe size of map:"<<myMap.size()<<endl;

//        myMap size:3
//        Emma score:67
//        Benedict score:100
//        the size of map:3



    //构造迭代器，遍历map
    map<string,int>::iterator mapIterator;
    for (mapIterator = myMap.begin(); mapIterator != myMap.end(); ++mapIterator) {
        cout<<"the score of "<<mapIterator->first<<":"<<mapIterator->second<<endl;
    }

//    the score of Benedict:100
//    the score of Bob:60
//    the score of Emma:67


    //查找元素，保存在迭代器
    mapIterator=myMap.find("Bob");
    cout<<"the score of "<<mapIterator->first<<":"<<mapIterator->second<<endl;

//    the score of Bob:60


    //清空map
    myMap.clear();

    cout<<"myMap is empty:"<<myMap.empty()<<endl;

//    myMap is empty:1

}




/*
 * @Description 查找学生信息
 * 输入N个学生信息，进行M次查找
 * 输入："01 丽江 男 21"
 *
 * 由学号输出学生信息
 *
 * 虽然是查找问题，但可由学号唯一确定学生，故采用map保存学生信息
 * 该题为单一映射
 */
void HashTable::J10_7() {

    map<string,string> student;

    //输入学生信息
    int n=0;
    cin>>n;//保存学生个数
    getchar();//吃掉回车
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin,str);//保存完整学生信息

        int pos=str.find(" ");//分界点
        string key=str.substr(0,pos);//保存学号作为关键字
        student[key]=str;//向映射student添加元素，其中学号作为key，完整信息作为value
    }

    //输出学生信息
    int m=0;
    cin>>m;
    for (int i = 0; i < m; ++i) {
        string key;
        cin>>key;
        string answer=student[key];
        if (answer.empty()){
            answer="No answer!";
        }
        cout<<answer<<endl;
    }

}



/*
 * @Description 魔咒词典
 * 输入：[魔法名字] 魔法功能（词典中均唯一）
 * 输出：由名字/功能输出功能/名字
 */
void HashTable::J10_8() {

    string str;

    map<string,string> dictionary;


    //输入词典
    while (getline(cin,str)){//整行接收字典

        if (str=="@END@"){
            break;
        }

        int pos=str.find("]");//魔咒与功能的分界点，string下标从0开始
        string key=str.substr(0,pos+1);//取出魔咒
        string value=str.substr(pos+2);//取出功能

        //为了实现双射，同时保存魔咒与功能
        //substr(int pos,int len),pos：开始下标；len：长度
        dictionary[key]=value;
        dictionary[value]=key;

    }

    //输出结果
    int n=0;
    cin>>n;
    getchar();
    while (n--){
        string key;
        getline(cin,key);
        string answer=dictionary[key];
        if (answer==""){
            answer="what?";
        }else if (answer[0]=='['){
            answer=answer.substr(1,answer.size()-2);
        }

        cout<<answer<<endl;
    }


}


/*
 * @Description 字串计算
 * 输入：01字符串，输出次数大于1的每个字串出现的个数，并按字典序排序
 *
 * 将字串当关键字（key），其出现的次数作为映射值（value），遍历整个字符串中的字串，每次将字串的映射值数加1
 *
 * map底层为红黑树，在内部仍会按关键字进行排序
 */
void HashTable::J10_9() {

    string str;

    while (cin>>str){

        map<string,int> number;

        //注意这种依次取str的字串的方法
        for (int i = 0; i <= str.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string key=str.substr(j,i-j);
//                cout<<"i:"<<i<<",j:"<<j<<",key:"<<key<<endl;
                /*
                 * 字符串：10101
                        i:1,j:0,key:1
                        i:2,j:0,key:10
                        i:2,j:1,key:0
                        i:3,j:0,key:101
                        i:3,j:1,key:01
                        i:3,j:2,key:1
                        i:4,j:0,key:1010
                        i:4,j:1,key:010
                        i:4,j:2,key:10
                        i:4,j:3,key:0
                        i:5,j:0,key:10101
                        i:5,j:1,key:0101
                        i:5,j:2,key:101
                        i:5,j:3,key:01
                        i:5,j:4,key:1
                */

                number[key]++;//映射值+1
            }

        }

        //定义迭代器，遍历输出value>1的key
        map<string,int>::iterator it;
        for (it=number.begin();it!= number.end();++it) {
            if (1<it->second){
                cout<<it->first<<" "<<it->second<<endl;
            }
        }



    }


}
