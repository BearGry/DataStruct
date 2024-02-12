//
// Created by xiaodian& on 2022/10/29.
//

#ifndef SY_2_LIST_H
#define SY_2_LIST_H

#include "iostream"
using namespace std;

typedef int elemtype;

//线性表-链表-单链表
class list {
private:
    typedef struct node{
        elemtype data;
        node *next;
    }node,*pnode;

    pnode head;
    int length;
public:
    list();
    ~list();
    list(const list &);
    list & operator=(const list &);

    int len(){return length;}
    bool empty(){return (length==0)? true : false;}
    void clear();

    //实验二的函数（还包括最后的友元函数）
    bool head_add(const elemtype &);
    bool insert(int, const elemtype &);
    bool dele(int, elemtype &);
    elemtype & operator[](int);

    //实验一的函数
    void cut(const elemtype & mink, const elemtype & maxk);

    friend ostream & operator<<(ostream &, const list &);
};


#endif //SY_2_LIST_H












