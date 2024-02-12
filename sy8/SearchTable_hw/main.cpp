//验证并设计顺序表的查找（顺序查找、折半查找）算法
#include "StaticSearchTable.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//实验测试
    //测试3次——顺序查找
    cout<<"顺序查找(测试3次):"<<endl;
    StaticSearchTable<int, 8> a;
    int key;
    for(int i=1; i<=3; i++){
        cout<<"输入你想找的数:";
        cin>>key;
        cout<<"位于: "<<a.sq_search(key)<<endl;
    }
    //测试3次——折半查找
    cout<<"折半查找(测试3次):"<<endl;
    a.heap_sort();
    cout<<"排序后的序列:"<<endl;
    cout<<a<<endl;
    for(int i=1; i<=3; i++){
        cout<<"输入你想找的数:";
        cin>>key;
        cout<<"位于: "<<a.half_search(key)<<endl;
    }

    return 0;
}
