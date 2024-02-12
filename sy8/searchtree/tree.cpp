//
// Created by xiaodian& on 2022/11/4.
//
#include "tree.h"
#include "queue.h"

////因为树是动态内存分配，所以要进行清除、创建等操作就应该传指针；

inline void tree::destroy(pnode & tree)
{
    if(tree != nullptr){
        destroy(tree->lchild);
        destroy(tree->rchild);
        delete tree;
    }
}
inline void tree::copy(pnode & tree1,const pnode & tree2)
{
    if(tree2 != nullptr){
        tree1 = new trnode;
        tree1->data = tree2->data;
        copy(tree1->lchild,tree2->lchild);
        copy(tree1->rchild,tree2->rchild);
        if(tree1->rchild != nullptr)
            tree1->rchild->parent = tree1;
        if(tree1->lchild != nullptr)
            tree1->lchild->parent = tree1;
    }
    else
        tree1 = nullptr;
}
inline tree::pnode tree::seek(const pnode & t, const elemtype & elem) const
{
    if(t == nullptr)
        return nullptr;
    if(t->data == elem)
        return t;
    if(t->data < elem)
        return seek(t->rchild, elem);
    return seek(t->lchild, elem);
}
inline bool tree::intree(const pnode & t, const elemtype & elem) const
{
    if(t == nullptr)
        return false;
    if(t->data == elem)
        return true;
    if(t->data < elem)
        return intree(t->rchild, elem);
    return intree(t->lchild, elem);
}

inline void tree::BFP(const pnode & t)
{
    queue<pnode, 95> a;
    a.push(t);
    pnode b;
    while(a.empty() == false){
        b = a.top();
        cout<<b->data<<' ';
        a.pop();
        if(b->lchild != nullptr)
            a.push(b->lchild);
        if(b->rchild != nullptr)
            a.push(b->rchild);
    }
}
void tree::pre_show_recursion(const pnode & t)
{
    if(t != nullptr){
        cout<<t->data<<" ";
        pre_show_recursion(t->lchild);
        pre_show_recursion(t->rchild);
    }
}
void tree::ird_show_recursion(const pnode & t)
{
    if(t != nullptr){
        ird_show_recursion(t->lchild);
        cout<<t->data<<" ";
        ird_show_recursion(t->rchild);
    }
}
void tree::lrd_show_recursion(const pnode & t)
{
    if(t != nullptr){
        lrd_show_recursion(t->lchild);
        lrd_show_recursion(t->rchild);
        cout<<t->data<<" ";
    }
}




tree::tree()
{
    root = nullptr;
    size = 0;
}
tree::~tree()
{
    destroy(root);
}
tree::tree(const tree & t)
{
    if(t.root == nullptr){
        root = nullptr;
        size = 0;
        return;
    }
    copy(root,t.root);
    root->parent = nullptr;
    size = t.size;
}
tree & tree::operator=(const tree & t)
{
    if(this == &t)
        return *this;
    destroy(root);
    if(t.root == nullptr){
        root = nullptr;
        size = 0;
        return *this;
    }
    copy(root,t.root);
    root->parent = nullptr;
    size = t.size;
    return *this;
}

tree::pnode tree::seek(const elemtype & elem) const
{
    return seek(root,elem);
}

bool tree::intree(const elemtype & elem) const
{
    return intree(root,elem);
}

bool tree::add(const elemtype & elem)
{
    if(intree(elem))
        return true;
    pnode t = new trnode;
    if(t == nullptr)
        return false;
    size++;
    t->data = elem;
    t->lchild = t->rchild = t->parent = nullptr;
    if(root == nullptr){
        root = t;
        root->parent = nullptr;
        return true;
    }
    pnode p;
    p = root;
    while(1){
        if(p->data < elem){
            if(p->rchild == nullptr){
                p->rchild = t;
                t->parent = p;
                return true;
            } else{
                p = p->rchild;
            }
        }else{
            if(p->lchild == nullptr){
                p->lchild = t;
                t->parent = p;
                return true;
            } else{
                p = p->lchild;
            }
        }
    }
}



void tree::display_recursion()
{
    if(size == 0)
        return;
    cout<<"PreOrder_Display:"<<endl;
    pre_show_recursion(root);
    cout<<endl;
    cout<<"InOrder_Display:"<<endl;
    ird_show_recursion(root);
    cout<<endl;
    cout<<"LrdOrder_Display:"<<endl;
    lrd_show_recursion(root);
    cout<<endl;
    cout<<"BFP_Display:"<<endl;
    BFP(root);
    cout<<endl;
}



istream & operator>>(istream & cin, tree & t)
{
    cout<<"How many node do you want to add: ";
    int n;
    cin>>n;
    if(n == 0){
        cout<<"Ok."<<endl;
        return cin;
    }
    cout<<"Then input the node_value:"<<endl;
    elemtype elem;
    for(int i=1; i<=n; i++){
        cin>>elem;
        t.add(elem);
    }
    return cin;
}
ostream & operator<<(ostream & cout, tree & t)
{
    t.ird_show_recursion(t.root);
    return cout;
}


