//
// Created by xiaodian& on 2022/11/4.
//

#ifndef EXP_CODING_TREE_H
#define EXP_CODING_TREE_H

#include "iostream"
using namespace std;

//验证二叉排序树上的查找（创建、查找、插入）算法
typedef int elemtype;

class tree {
private:
    typedef struct trnode{
        elemtype data;
        trnode *lchild, *rchild, *parent;
    }trnode, *pnode;

    pnode root;
    int size;


    void destroy(pnode &);
    void copy(pnode &, const pnode &);

//一些真正的实现代码在这里（创建和插入的真正实现在public中）
    //查找
    pnode seek(const pnode &, const elemtype &) const;
    bool intree(const pnode &, const elemtype &) const;


    //遍历
    void BFP(const pnode &);      //广度优先遍历
    void pre_show_recursion(const pnode &);  //先序递归实现
    void ird_show_recursion(const pnode &);  //中序递归实现
    void lrd_show_recursion(const pnode &);  //后续递归实现

public:
    tree();
    ~tree();
    tree(const tree &);
    tree & operator=(const tree &);

//实验（2） 二叉排序树上的查找算法——创建、查找、插入
    //创建
        //为下面的友元函数——重载“>>”运算符，也可通过add函数一个一个添加以创建
    //查找
    bool intree(const elemtype &) const;    //查找某数是否在树中，若在返回真，否则假
    pnode seek(const elemtype &) const;     //某数若在，返回节点（结构体）
    //插入
    bool add(const elemtype &);             //添加结点


//关于二叉排序树的更多方法在sy5文件下的Tree_01中
//这里还有一个展示用的遍历实现 和 两个基础功能

    void display_recursion();               //先、中、后序递归实现
    int len(){return size;}                 //结点数
    bool empty(){return size == 0;}   //是否为空树

    friend istream & operator>>(istream &, tree &);  //输入树，第一个数为想加多少个
    friend ostream & operator<<(ostream &, tree &);  //递增展示树
};




#endif //EXP_CODING_TREE_H
