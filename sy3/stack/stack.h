//
// Created by xiaodian& on 2022/11/17.
//

#ifndef EXP_CODING_STACK_H
#define EXP_CODING_STACK_H

#include "iostream"
using namespace std;


//线性表-链表
template<typename elemtype>
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
    virtual ~list();
    list(const list &);
    list & operator=(const list &);

    int len(){return length;}
    bool empty(){return (length==0)? true : false;}

    bool head_add(const elemtype &);
    bool insert(int, const elemtype &);
    bool dele(int, elemtype &);
    elemtype & operator[](int);
    void clear();

};

//栈
template<typename elemtype>
class Stack : public list<elemtype>{
private:
    bool head_add(const elemtype &);
    bool insert(int, const elemtype &);
    bool dele(int, elemtype &);
    elemtype & operator[](int);
public:
    bool push(const elemtype &);
    elemtype & top();
    bool pop();
};

template<typename elemtype>
list<elemtype>::list() {
    head = nullptr;
    length = 0;
}

template<typename elemtype>
list<elemtype>::~list() {
    pnode p;
    p = head;
    while(p){
        head = head->next;
        delete p;
        p = head;
    }
}

template<typename elemtype>
list<elemtype>::list(const list<elemtype> & a) {
    if(a.length == 0){
        length = 0;
        head = nullptr;
        return;
    }
    pnode p = a.head;
    pnode t,prior;
    length = a.length;
    for(int i=1; i<=a.length; i++){
        t = new node;
        t->data = p->data;
        t->next = nullptr;
        if(i == 1){
            head = t;
            prior = t;
        }
        else{
            prior->next = t;
            prior = t;
        }
        p = p->next;
    }
}

template<typename elemtype>
list<elemtype> &list<elemtype>::operator=(const list<elemtype> & a) {
    if(this == &a)
        return *this;
    this->~list();
    if(a.length == 0){
        length = 0;
        head = nullptr;
        return *this;
    }
    pnode p = a.head;
    pnode t,prior;
    length = a.length;
    for(int i=1; i<=a.length; i++){
        t = new node;
        t->data = p->data;
        t->next = nullptr;
        if(i == 1){
            head = t;
            prior = t;
        }
        else{
            prior->next = t;
            prior = t;
        }
        p = p->next;
    }
    return *this;
}

template<typename elemtype>
bool list<elemtype>::head_add(const elemtype & elem) {
    pnode p = new node;
    if(p == nullptr)
        return false;
    length++;
    p->data = elem;
    p->next = head;
    head = p;
}

template<typename elemtype>
bool list<elemtype>::insert(int pos, const elemtype & elem) {
    if(pos<=0 || pos>length+1)
        return false;

    pnode t = new node;
    if(t == nullptr)
        return false;
    t->data = elem;
    t->next = nullptr;
    length++;
    if(pos == 1){
        t->next = head;
        head = t;
        return true;
    }
    pnode p = head;
    for(int i=1, end=pos-2; i<=end; i++)
        p = p->next;
    t->next = p->next;
    p->next = t;
    return true;
}

template<typename elemtype>
bool list<elemtype>::dele(int pos, elemtype & elem) {
    if(pos<=0 || pos>length)
        return false;
    length--;
    if(pos == 1){
        elem = head->data;
        pnode t = head;
        head = head->next;
        delete t;
        return true;
    }
    pnode p = head;
    for(int i=1,end=pos-2; i<=end; i++)
        p = p->next;
    elem = p->next->data;
    pnode del = p->next;
    p->next = p->next->next;
    delete del;
    return true;
}

template<typename elemtype>
elemtype &list<elemtype>::operator[](int pos) {
    pos++;
    if(pos<=0 || pos>length)
        exit(0);
    pnode p = head;
    for(int i=1,end=pos-1; i<=end; i++)
        p = p->next;
    return p->data;
}

template<typename elemtype>
void list<elemtype>::clear() {
    this->~list();
    head = nullptr;
    length = 0;
}


template<typename elemtype>
elemtype &Stack<elemtype>::top() {
    return list<elemtype>::operator[](0);
}

template<typename elemtype>
bool Stack<elemtype>::pop() {
    elemtype t;
    return list<elemtype>::dele(1,t);
}

template<typename elemtype>
bool Stack<elemtype>::push(const elemtype & elem) {
    return list<elemtype>::head_add(elem);
}

#endif //EXP_CODING_STACK_H
