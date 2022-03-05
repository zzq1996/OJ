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
 */
void HashTable::J10_7() {

    map<string,string> student;
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
 */
void HashTable::J10_8() {


}


/*
 * @Description 字串计算
 */
void HashTable::J10_9() {

}
