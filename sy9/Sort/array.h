//
// Created by xiaodian& on 2022/12/15.
//

#ifndef EIGHT_ARRAY_H
#define EIGHT_ARRAY_H
#include "iostream"
using namespace std;

template<typename comp, int n>
class array {
private:
    comp data[n+2];
    int length;

    int partition(int i, int j);
    void build_heap(int s, int e);
    void combine(int i, int j, int k);

public:
    array();

    int len(){return length;}

    //插入类排序：
    // 直接插入排序、希尔排序
    void insert_sort();
    void shell_sort();

    //交换类排序：
    // 冒泡排序、快速排序
    void bubble_sort();
    void quick_sort(int i = 1, int j = n);

//    选择类排序：
//    简单选择排序、堆排序
    void select_sort();
    void heap_sort();

//    归并类排序：
//    递归和非递归形式的归并排序
    void merge();
    void merge_rec(int i = 1, int j = n);


    template<typename c, int m>
    friend ostream & operator<<(ostream & out, array<c,m> & st);
};


template<typename comp, int n>
array<comp, n>::array() {
    length = n;
    cout<<"input the data ("<<length<<"):"<<endl;
    for(int i=1; i<=length; i++)
        cin>>data[i];
}

template<typename comp, int n>
ostream & operator<<(ostream & out, array<comp,n> & st)
{
    for(int i=1; i<=st.length; i++)
        out<<st.data[i]<<" ";
    return out;
}



//插入类排序
//直接插入排序
template<typename comp, int n>
void array<comp, n>::insert_sort() {
    int j;
    for(int i=2; i<=length; i++){
        if(data[i] < data[i-1]){
            data[0] = data[i];
            for(j=i-1; data[0] < data[j]; j--)
                data[j+1] = data[j];
            data[j+1] = data[0];
        }
    }
}
//希尔排序
template<typename comp, int n>
void array<comp, n>::shell_sort() {
    int len = length/2;
    int k;
    for(;len>=1; len/=2){
        for(int j=len+1; j<=length; j++){
            if(data[j] < data[j-len]){
                data[0] = data[j];
                for(k=j-len; k>0 && data[0] < data[k]; k-=len)
                    data[k+len] = data[k];
                data[k+len] = data[0];
            }
        }
    }
}

//交换排序
//冒泡排序
template<typename comp, int n>
void array<comp, n>::bubble_sort() {
    //如果已经有序，则可直接退出
    bool out;
    for(int i=1; i<length; i++){
        out = true;//每一趟开始的时候都可能已经有序——如果这一趟中没有一次交换则可说明，所以每一趟开始前都更新一下
        for(int j=1,end=length-i; j<=end; j++){
            if(data[j] > data[j+1]){
                swap(data[j], data[j+1]);
                out = false;
            }
        }
        if(out)
            return;
    }
}

//快速排序
template<typename comp, int n>
void array<comp, n>::quick_sort(int i, int j) {
    //产生一个全局有序，且左边的都小于它，右边的都大于它
    int locat = partition(i,j);
    //前面的递归调用排序
    if(i<locat-1)//递归终止条件
        quick_sort(i,locat-1);
    //后面的递归调用排序
    if(locat+1<j)//递归终止条件
        quick_sort(locat+1,j);
}

template<typename comp, int n>
int array<comp, n>::partition(int i, int j) {
//    通过一次遍历（i到j区间内的遍历），把原本i位置上的元素归位——全局有序
    data[0] = data[i];
    while(i<j){
        for(;j>i && data[j]>=data[0]; j--);
        data[i] = data[j];
        for(;i<j && data[i]<=data[0]; i++);
        data[j] = data[i];
    }
    data[i] = data[0];
    return i;//返回其全局有序的位置
}

//选择类排序
//简单选择排序
template<typename comp, int n>
void array<comp, n>::select_sort() {
    int min;
    int idx;
    for(int i=1; i<length; i++){
        min = data[i];
        idx = i;
        for(int j=i+1; j<=length; j++)
            if(data[j] < min){
                min = data[j];
                idx = j;
            }
        swap(data[i], data[idx]);
    }
}
//  堆排序
template<typename comp, int n>
void array<comp, n>::heap_sort() {
    for(int i=length/2; i>0; i--)
        build_heap(i,length);
    for(int i=length; i>1; i--){
        swap(data[1], data[i]);
        build_heap(1,i-1);
    }
}

template<typename comp ,int n>
void array<comp, n>::build_heap(int s, int e) {
    if(2*s > e)
        return;
    int idx = 2*s;
    if(idx+1<=e && data[idx+1]>data[idx])
        idx++;
    if(data[s] >= data[idx])
        return;
    swap(data[s],data[idx]);
    build_heap(idx,e);
}

//  归并排序-递归版
template<typename comp, int n>
void array<comp, n>::merge_rec(int i,int j) {
    if(i == j)
        return;
    int local = (i+j)/2;
    merge_rec(i,local);
    merge_rec(local+1,j);
    combine(i,local+1,j);
}

template<typename comp, int n>
void array<comp, n>::combine(int i, int j, int k) {
    comp t[k-i+1];
    int p=0;
    int lend;
    for(lend=j-1; i<=lend && j<=k;){
        if(data[i] <= data[j])
            t[p++] = data[i++];
        else
            t[p++] = data[j++];
    }
    while(i<=lend)
        t[p++] = data[i++];
    while(j<=k)
        t[p++] = data[j++];
    for(int i=k; p>0;)
        data[i--] = t[--p];
}



#endif //EIGHT_ARRAY_H
