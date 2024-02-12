//验证二叉排序树上的查找（创建、查找、插入）算法
#include "tree.h"

int main(){
    cout<<"创建并展示:"<<endl;
    tree a;
    //创建
       //参考序列4 3 1 6 16 8 27 2（8个数）
    cin>>a;
    //中序遍历展示
    cout<<a<<endl;

    cout<<endl;

    //查找
    cout<<"查找:"<<endl;
    if(a.intree(4)){
        cout<<a.seek(4)->data<<" is in the tree."<<endl;
    } else
        cout<<a.seek(4)->data<<" is not in the tree."<<endl;

    cout<<endl;

    //插入
    //原本就有的插入——舍弃
    cout<<"插入:"<<endl;
    a.add(8);
    cout<<a<<endl;
    //原本没有的插入——插入
    a.add(14);
    cout<<a<<endl;

    cout<<endl;

    //遍历一遍
    cout<<"遍历一遍:"<<endl;
    a.display_recursion();
}