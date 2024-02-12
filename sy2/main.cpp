#include "list.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    list a;
    for(int i=13; i>0; i-=2)//实验（2）测试
        a.head_add(i);
    cout<<"实验二测试结果:"<<endl;
    cout<<a<<endl;
    elemtype t;
    a.insert(5,999);
    cout<<a<<endl;
    a.dele(5,t);
    cout<<t<<endl;
    cout<<a<<endl;
//    cout<<a.len()<<endl;
    cout<<"实验一测试结果:"<<endl;//实验（1）测试
    cout<<a<<endl;
    cout<<"1.删除中间结点的例子(mink=4,maxk=11):"<<endl;
    a.cut(4,11);
    cout<<a<<endl;
    cout<<"2.删除包含第一个结点的例子(mink=-1,maxk=2):"<<endl;
    a.cut(-1,2);
    cout<<a<<endl;
    cout<<"3.删除包含最后一个结点的例子(mink=8,maxk=14):"<<endl;
    a.cut(8,14);
    cout<<a<<endl;


    //复制构造、赋值函数测试（与实验题目无关）
//    list b = a;
//    cout<<b<<endl;
//    b.head_add(0);
//    a = b;
//    cout<<a<<endl;
//
//    a.clear();
//    cout<<a.len()<<endl;

    return 0;
}
