//插入类排序：直接插入排序、希尔排序
//交换类排序：冒泡排序、快速排序
//选择类排序：简单选择排序、堆排序
//归并类排序：递归和非递归形式的归并排序
#include "array.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    //没打注释的是写实验报告的，其他的也可以去掉注释运行

//    cout<<"插入类排序：直接插入排序、希尔排序:"<<endl;
//    cout<<"insert_sort"<<endl;
//    array<int, 11> c;
//    a.insert_sort();
//    cout<<a<<endl;
//
//    cout<<"shell_sort"<<endl;
//    array<int ,11> d;
//    b.shell_sort();
//    cout<<b<<endl;


    cout<<"交换类排序：冒泡排序、快速排序:"<<endl;
    cout<<"bubble_sort"<<endl;
    array<int, 11> a;
    a.bubble_sort();
    cout<<a<<endl;

    cout<<"quick_sort"<<endl;
    array<int, 11> b;
    b.quick_sort();
    cout<<b<<endl;


//    cout<<"选择类排序：简单选择排序、堆排序:"<<endl;
//    cout<<"select_sort"<<endl;
//    array<int, 11> e;
//    a.select_sort();
//    cout<<a<<endl;
//
//    cout<<"heap_sort"<<endl;
//    array<int, 11> f(e);//测试一下-数组元素在默认的复制构造函数中也可以赋值
//    b.heap_sort();
//    cout<<b<<endl;


//    cout<<"归并类排序：递归和非递归形式的归并排序(这里只实现了递归形式的):"<<endl;
//    cout<<"merge_rec_sort"<<endl;
//    array<int, 11> g;
//    a.merge_rec();
//    cout<<a<<endl;


    return 0;
}
