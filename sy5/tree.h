//
// Created by xiaodian& on 2022/11/3.
//

#ifndef TREE_01_TREE_H
#define TREE_01_TREE_H

#include "iostream"
using namespace std;

typedef int elemtype;

class tree {
private:
    typedef struct trnode{
        elemtype data;
        trnode *lchild, *rchild, *parent;
    }trnode, *pnode;

    pnode root;
    int size;

    typedef enum {FIRST,SECOND} TIME;
    typedef struct lrd{
        pnode p_node;
        TIME time;
    }lrd,ird;
    void destroy(pnode &);
    void copy(pnode &, const pnode &);
    pnode seek(const pnode &, const elemtype &) const;
    bool intree(const pnode &, const elemtype &) const;
    void traverse(pnode &, void visit(elemtype &));

    static void show(elemtype & elem) {cout<<elem<<' ';}

    //遍历
    void pre_show(const pnode &); //先序非递归实现
    void ird_show(const pnode &); //中序非递归实现
    void lrd_show(const pnode &); //后续非递归实现
    void BFP(const pnode &);      //广度优先遍历
    void pre_show_recursion(const pnode &);  //先序递归实现
    void ird_show_recursion(const pnode &);  //中序递归实现
    void lrd_show_recursion(const pnode &);  //后续递归实现

    int nodes(const pnode &);   //叶子数
    int deep(const pnode &);    //树的深度
    bool similar(const pnode &, const pnode &);  //相似性
    void reverse(const pnode &);  //左右子树互换


public:
    tree();
    ~tree();
    tree(const tree &);
    tree & operator=(const tree &);

    int len(){return size;}
    bool empty(){return (size == 0)? true : false;}

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


    //此为一些二叉树的基础实现
    bool add(const elemtype &);             //添加节点
    bool intree(const elemtype &) const;    //某数是否在树中
    pnode seek(const elemtype &) const;     //某数若在，返回节点（结构体）
    bool cut(const elemtype &);             //删除某数
    void traverse(void visit(elemtype &));  //遍历操作,执行visit函数；

    void clear();                           //清空树


    friend istream & operator>>(istream &, tree &);  //输入树，第一个数为想加多少个
    friend ostream & operator<<(ostream &, tree &);  //递增展示树（中序遍历）
};


#endif //TREE_01_TREE_H
