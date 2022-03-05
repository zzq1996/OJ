/**
* @Author : zhang
* @create 2022/3/4 20:52
*/

//
// Created by zhang zhiqiang on 2022/3/4.
//


#include "BinarySearchTree.h"
#include "iostream"

using namespace std;


/*
 * @Description 二叉排序树
 * 输入：结点数N和N个结点
 * 输出：输入该结点对应的父结点值
 */

//新建BST结点结构体
struct BST{
    int data;
    BST* leftChild;
    BST* rightChild;

     BST(int x){//构造函数
        this->data=x;
        leftChild= nullptr;
        rightChild= nullptr;
    }
};

/*
 * @Description 插入数值，构造二叉树
 *
 * 这里采用递归方式建树，可不必等树完全建好再输出每个结点的父结点；
 * 可在插入时用一个变量记录父结点的值，在建树的同时输出父结点的值
 *
 * x：输入的数值
 * father：初始值为-1，在递归调用中更新
 */
BST* insert(BST* root,int x,int father){

    if (root== nullptr){//创建新结点

        root=new BST(x);

        cout<<father<<endl;//输出父结点

    } else if(x<root->data){//插入左子树
        root->leftChild= insert(root->leftChild,x,root->data);
    } else{//插入右子树
        root->rightChild= insert(root->rightChild,x,root->data);
    }

    return root;
}

/*
 * @Description 主程序
 */
 void BinarySearchTree::J10_3() {
    int n;
    while (cin>>n){
        BST* root= nullptr;
        for (int i = 0; i < n; ++i) {
            int x;
            cin>>x;
            root= insert(root,x,-1);
        }
    }
}




/*
 * @Description 将输入整数建立BST，并遍历输出
 */


/*
 * @Description 建立二叉排序树
 *
 */
BST* insert(BST* root,int x){

    if (root== nullptr){//创建新结点
        root=new BST(x);

    }else if (x<root->data){//插入左子树
        root->leftChild= insert(root->leftChild,x);

    }else{//插入右子树
        root->rightChild= insert(root->rightChild,x);

    }

    return root;

}

/*
 * @Description 前序遍历
 */

BST* preOrder(BST* root){

    if (root!= nullptr){
        cout<<root->data;
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
//    cout<<endl;

}


/*
 * @Description 中序遍历
 */

BST* inOrder(BST* root){

    if (root!= nullptr){
        inOrder(root->leftChild);
        cout<<root->data;
        inOrder(root->rightChild);
    }
//    cout<<endl;

}


/*
 * @Description 前序遍历
 */

BST* postOrder(BST* root){

    if (root!= nullptr){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        cout<<root->data;
    }
//    cout<<endl;
}


/*
 * @Description  主程序
 */
void BinarySearchTree::J10_4() {

    int n;
    while (cin>>n){
        BST* root= nullptr;

        for (int i = 0; i < n; ++i) {//逐个插入，建立BST
            int data;
            cin>>data;
            root= insert(root,data);
        }

        preOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        postOrder(root);
        cout<<endl;

    }



}