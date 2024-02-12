//验证Hash表查找（Hash函数定义、建立，查找，插入）算法
#include "hash.h"
#include "map"

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<<"创建并展示:"<<endl;
    Hash<int, string> a;
    cin>>a;
    cout<<a<<endl;

    cout<<"查找测试(3次):"<<endl;
    int locat;
    string c;
    for(int i=1; i<=3; i++){
        cout<<"输入你想找的字符串的序号:";
        cin>>locat;
        if(a.find(locat,c))
            cout<<c<<endl;
        else
            cout<<"没找到"<<endl;
    }

    cout<<"插入元素并展示:"<<endl;
    a[96] = "hello";
    a.add(44,"world");
    cout<<a<<endl;


    return 0;
}
