#include "tree.h"

//实验（1）
//创建二叉树可由友元函数重载">>"运算符，或add函数逐一添加元素
//实验（2）
void display();                         //四种顺序展示 非递归实现
void display_recursion();               //先、中、后序递归实现
//实验（3）
int nodes();                            //叶子结点数目的递归算法
//实验（4）
int deep();                             //二叉树深度的递归算法
//实验（5）
bool similar(const tree &);             //二叉树相似的递归算法
//实验（6）
void reverse();                         //左右子树交换的递归算法
//实验（7）
//在实验二的display()中有层序遍历算法
//实验（8）
bool complete();                        //完全二叉树判断

int main(){
    //创建
    tree a;
    cin>>a;


    cout<<"递归与非递归的先、中、后序遍历 层序遍历 展示:"<<endl;
    a.display(); //非递归
    cout<<endl;
    a.display_recursion(); //递归
    cout<<endl;

    cout<<endl;

    cout<<"叶子节点数目:"<<endl;
    cout<<a.nodes()<<endl;
    cout<<"二叉树的深度:"<<endl;
    cout<<a.deep()<<endl;

    cout<<endl;

    cout<<"二叉树相似:"<<endl;
    tree b;
    cout<<"(1)、相似性检验:（输入一个不相似的）"<<endl;
    cin>>b;
    if(a.similar(b))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    b.clear();//清空函数检验
    cout<<"(2)、相似性检验:（输入一个相似的）"<<endl;
    cin>>b;
    if(a.similar(b))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    cout<<endl;

    cout<<"左右子树交换的检验:"<<endl;
    a.reverse();
    cout<<a<<endl;//中序原本应为递增，现在应为递减序列

    cout<<endl;

    cout<<"完全二叉树判断:"<<endl;
    if(a.complete())
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    cout<<"重新输入以检测另一种情况（完全性的）:"<<endl;
    a.clear();
    cin>>a;
    if(a.complete())
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}