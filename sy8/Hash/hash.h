//
// Created by xiaodian& on 2022/12/15.
//
//验证Hash表查找（Hash函数定义、建立，查找，插入）算法

#ifndef Hash_Hash_H
#define Hash_Hash_H

#include "iostream"
using namespace std;

template<typename keytype, typename datatype>
class Hash {
private:
    enum {size = 14};
    typedef struct node{
        keytype key;
        datatype data;
        node * next;
    }node,*pnode;

    pnode map[size];

    int hHash(const keytype & key){return key%size;};//Hash函数定义
    void show();
public:
    Hash();
    ~Hash();

    bool find(const keytype & key, datatype & data);
    void add(const keytype & key, const datatype data);
    datatype & operator[](keytype key);

    template<typename keytype2, typename datatype2>
    friend istream & operator>>(istream & in, Hash<keytype2, datatype2> & a);
    template<typename keytype2, typename datatype2>
    friend ostream & operator<<(ostream & out, Hash<keytype2, datatype2> & a);
};

template<typename keytype, typename datatype>
Hash<keytype, datatype>::Hash() {
    for(int i=0; i<size; i++)
        map[i] = nullptr;
}
template<typename keytype, typename datatype>
Hash<keytype, datatype>::~Hash() {
    for(int i=0; i<size; i++){
        if(map[i]){
            while(map[i]){
                pnode t = map[i];
                map[i] = t->next;
                delete t;
            }
        }
    }
}

template<typename keytype, typename datatype>
bool Hash<keytype, datatype>::find(const keytype &key, datatype &data) {
    pnode p = map[hHash(key)];
    while (p){
        if(p->key == key){
            data = p->data;
            return true;
        }
        p = p->next;
    }
    return false;
}


template<typename keytype, typename datatype>
void Hash<keytype, datatype>::add(const keytype &key, const datatype data) {
    pnode p = new node;
    p->key = key;
    p->data = data;
    int address = hHash(key);
    p->next = map[address];
    map[address] = p;
}

template<typename keytype, typename datatype>
datatype &Hash<keytype, datatype>::operator[](keytype key) {
    pnode p = map[hHash(key)];
    while (p){
        if(p->key == key){
            return p->data;
        }
        p = p->next;
    }
    p = new node;
    p->key = key;
    int address = hHash(key);
    p->next = map[address];
    map[address] = p;
    return p->data;
}

template<typename keytype, typename datatype>
istream & operator>>(istream & in, Hash<keytype, datatype> & a){
    cout<<"how many data: ";
    int n;
    in>>n;
    keytype key;
    datatype data;
    for(int i=1; i<=n; i++){
        in>>key>>data;
        a.add(key,data);
    }
    return in;
}


template<typename keytype, typename datatype>
ostream & operator<<(ostream & out, Hash<keytype, datatype> &a){
    a.show();
    return out;
}
template<typename keytype, typename datatype>
inline void Hash<keytype, datatype>::show() {
    pnode p;
    cout<<"{ ";
    for(int i=0; i<size; i++){
        p = map[i];
        while (p){
            cout<<p->key<<":"<<p->data<<" ";
            p = p->next;
        }
    }
    cout<<"}";
}





















#endif //Hash_Hash_H
