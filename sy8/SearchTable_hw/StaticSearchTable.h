//
// Created by xiaodian& on 2022/12/11.
//

#ifndef SEARCHTABLE_HW_STATICSEARCHTABLE_H
#define SEARCHTABLE_HW_STATICSEARCHTABLE_H

#include "iostream"
using namespace std;

template<typename comp, int n>
class StaticSearchTable {
private:
    comp data[n+1];
    int length;

    int half_search_heart(int low, int high, const comp & key) const;
    void build_heap_3(int s, int e);

public:
    StaticSearchTable();
    int len(){return length;}

//  查找
    //顺序查找
    int sq_search(const comp & key);
    //折半查找——用之前需要先排序
    int half_search(const comp & key) const;

    //排序
    void heap_sort();

    template<typename c, int m>
    friend ostream & operator<<(ostream & out, StaticSearchTable<c,m> & st);
};

template<typename comp, int n>
StaticSearchTable<comp,n>::StaticSearchTable() {
    length = n;
    cout<<"input the data ("<<length<<"):"<<endl;
    for(int i=1; i<=length; i++)
        cin>>data[i];
}

template<typename comp, int n>
ostream & operator<<(ostream & out, StaticSearchTable<comp,n> & st)
{
    for(int i=1; i<=st.length; i++)
        out<<st.data[i]<<" ";
    return out;
}




//顺序查找
template<typename comp, int n>
int StaticSearchTable<comp, n>::sq_search(const comp &key) {
    data[0] = key;//哨兵
    int i;
    for(i=length; data[i]!=key; i--);
    return i;//如果没找到则返回0
}

//折半查找，使用之前要先排序
template<typename comp, int n>
int StaticSearchTable<comp, n>::half_search(const comp &key) const {
    return half_search_heart(1,length,key);
}
template<typename comp, int n>
int StaticSearchTable<comp, n>::half_search_heart(int low, int high, const comp &key) const {
    if(low > high)//查找范围为0，即没找到
        return 0;
    int mid = (low+high)/2;
    if(data[mid] == key)
        return mid;
    if(data[mid] < key)//小了
        return half_search_heart(mid+1,high,key);
    return half_search_heart(low,mid-1,key);
}


//排序
template<typename comp, int n>
void StaticSearchTable<comp, n>::heap_sort() {
    for(int i=(length+1)/3; i>0; i--)
        build_heap_3(i,length);
    for(int i=length; i>1; i--){
        swap(data[1], data[i]);
        build_heap_3(1,i-1);
    }
}
//O(nlog3(n))~O(nln(n))
template<typename comp, int n>
void StaticSearchTable<comp, n>::build_heap_3(int s, int e) {
    if(3*s-1 > e)
        return;
    int idx = 3*s-1;
    int max = data[idx];
    for(int k = idx+1,end = min(idx+2,e); k<=end; k++)
        if(data[k] > max){
            idx = k;
            max = data[k];
        }
    if(data[s] >= max)
        return;
    swap(data[s],data[idx]);
    build_heap_3(idx,e);
}


#endif //SEARCHTABLE_HW_STATICSEARCHTABLE_H
