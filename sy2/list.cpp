//
// Created by xiaodian& on 2022/10/29.
//
#include "list.h"

list::list()
{
    head = nullptr;
    length = 0;
}
list::~list()
{
    pnode p;
    p = head;
    while(p){
        head = head->next;
        delete p;
        p = head;
    }
}
list::list(const list & a)
{
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
list & list::operator=(const list & a)
{
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

bool list::head_add(const elemtype & elem)
{
    pnode p = new node;
    if(p == nullptr)
        return false;
    length++;
    p->data = elem;
    p->next = head;
    head = p;
    return true;
}

bool list::insert(int pos, const elemtype & elem)
{
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

bool list::dele(int pos, elemtype & elem)
{
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

//删除单链表中大于mink小于maxk的值
void list::cut(const elemtype & mink, const elemtype & maxk)
{
    //如果没有元素或者输入非法即小值大于等于大值，直接退出
    if(length == 0 || mink>=maxk)
        return;
    //找到第一个其下一个结点中数据的值大于mink的结点（即结点指针）p
    //注意：如果第一个就该删的话，后期应该处理一下。
    //这里这样寻找是因为单链表的删除操作，需要其前驱（当然也有不需要前驱的实现，但其也有缺点，如删除最后一个结点的操作不易进行）
    pnode p = head;
    while(p->next != nullptr && p->next->data <= mink)
        p = p->next;
    if(p->next == nullptr)//不存在则直接退出
        return;
    pnode t = p->next;//结点指针t指向该删除的起点

    //接着那个位置继续往后找，找到第一个数据值大于maxk的结点（即结点指针）q
    pnode q = p->next;
    while(q != nullptr && q->data < maxk)
        q = q->next;
    p->next = q;//把该删除的部分分离，留下的部分首尾相接
    //这一步是释放删除结点的空间
    pnode d;
    while(t != q){
        d = t;
        t = t->next;
        delete d;
        length--;//注意有效元素个数的变化
    }
    //弥补注意：如果头也应该删去，则删去
    if(head->data>mink && head->data<maxk){
        t = head;
        head = head->next;
        delete t;
        length--;
    }
}

elemtype & list::operator[](int pos)
{
    pos++;
    if(pos<=0 || pos>length)
        exit(0);
    pnode p = head;
    for(int i=1,end=pos-1; i<=end; i++)
        p = p->next;
    return p->data;
}

void list::clear()
{
    this->~list();
    head = nullptr;
    length = 0;
}

ostream & operator<<(ostream & cout, const list & l)
{
    list::pnode p = l.head;
    for(int i=1; i<=l.length; i++){
        cout<<p->data<<' ';
        p = p->next;
    }
    return cout;
}










