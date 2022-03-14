/**
* @Author : zhang
* @create 2022/3/4 18:19
*/

//
// Created by zhang zhiqiang on 2022/3/4.
//


#include "BinaryTree.h"
#include "iostream"

using  namespace std;


/*
 * @Description 二叉树的遍历
 * 建立：按照二叉树的定义进行递归建树
 * 输入：先序遍历字符串，以指针方式存储，"#"表示空格
 * 输出：该二叉树的中序遍历序列
 */

//二叉树结点
struct TreeNode{

    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;

    //结点的构造函数
    TreeNode(char c){
        this->data=c;
        leftChild= nullptr;
        rightChild= nullptr;
    }

};

/*
 * @Description 递归建立二叉树
 *
 *
 * position参数的类型是整型引用，而非整型变量
 *      ——引用类型：变量的别名
 *      ——引用类型的行参和实参共享同一内存空间
 *
 *
 *
 */
TreeNode* build(int& position,string str){

    char c=str[position++];

    if (c=='#'){
        return nullptr;
    }

    TreeNode* root=new TreeNode(c);//创建根结点，这里对结点的赋值过程在构造函数中完成

    root->leftChild= build(position,str);//创建左子树

    root->rightChild= build(position,str);//创建右子树

    return root;

}

/*
 * @Description 中序遍历函数
 */
void inOrder(TreeNode* treeNode){
    if (treeNode!= nullptr){

        inOrder(treeNode->leftChild);

        cout<<treeNode->data<<" ";

        inOrder(treeNode->rightChild);

    }
}


void BinaryTree::J10_1() {

    string str;
    while (cin>>str){

        int position=0;//标记字符串处理位置

        TreeNode* root= build(position,str);
        inOrder(root);
        cout<<endl;
    }

}


/*
 * @Description 输出二叉树的后序遍历——"X E D G A F "
 *
 *
 * 输入：前序和中序——"FDXEAG  XDEFAG"
 * 关键是寻找切分点，递归构建左右子树
 */

//建立二叉树
TreeNode* build2(string str1,string str2){

    if (str1.length()==0){//返回空树
        return nullptr;
    }

    char c=str1[0];//当前字符

    TreeNode* root=new TreeNode(c);

    int position=str2.find(c);//寻找切分点

    root->leftChild= build2(str1.substr(1,position),str2.substr(0,position));

    root->rightChild= build2(str1.substr(position+1),str2.substr(position+1));

    return root;

}



//后序遍历
void postOrder(TreeNode* root){
    if (root!= nullptr){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        cout<<root->data<<" ";
    }
}


//后序输出该二叉树
void BinaryTree::J10_2() {
    string str1,str2;
    while (cin>>str1>>str2){
        TreeNode* root= build2(str1,str2);
        postOrder(root);
        cout<<endl;
    }
}






