//
// Created by xiaodian& on 2022/10/29.
//

#include "SeqList.h"

inline void SeqList::expand()
{
    SeqList a(size+EXPAND);
    for(int i=0; i<length; i++)
        a.base[i] = base[i];
    a.length = length;
    *this = a;
}
SeqList::SeqList(int n)
{
    base = new ElemType [n];
    length = 0;
    size = n;
}
SeqList::SeqList(const SeqList & seqList)
{
    length = seqList.length;
    size = seqList.size;
    base = new ElemType [size];
    for(int i=0; i<length; i++)
        base[i] = seqList.base[i];
}
SeqList::~SeqList()
{
    if(base == nullptr)
        return;
    delete [] base;
    length = 0;
    size = 0;
}
SeqList & SeqList::operator=(const SeqList & seqList)
{
    if(this == &seqList)
        return *this;
    delete [] base;
    length = seqList.length;
    size = seqList.size;
    base = new ElemType [size];
    for(int i=0; i<length; i++)
        base[i] = seqList.base[i];
}

bool SeqList::insert(int pos, const ElemType & elem)
{
    if(pos<1 || pos>length+1)
        return false;
    if(length == size)
        expand();
    for(int i=length-1,end=pos-1; i>=end; i--)
        base[i+1] = base[i];
    base[pos-1] = elem;
    length++;
    return true;
}

bool SeqList::add(const ElemType & elem)
{
    if(length == size)
        expand();
    base[length] = elem;
    length++;
    return true;
}

bool SeqList::dele(int pos, ElemType & elem)
{
    elem = base[pos-1];
    for(int i=pos,end=length-1; i<=end; i++)
        base[i-1] = base[i];
    length--;
    return true;
}
bool SeqList::dele(int pos)
{
    for(int i=pos,end=length-1; i<=end; i++)
        base[i-1] = base[i];
    length--;
    return true;
}

ElemType & SeqList::operator[](int pos)
{
    return base[pos];
}
const ElemType & SeqList::operator[](int pos) const
{
    return base[pos];
}

void SeqList::revert()
{
    int i=0,j=length-1;
    while(i<j){
        swap(base[i],base[j]);
        i++; j--;
    }
}

void SeqList::sort(int u, int v)
{
    int mid = position(u,v);
    if(u<mid-1)
        sort(u,mid-1);
    if(mid+1<v)
        sort(mid+1,v);
}

int SeqList::position(int s, int e) {
    ElemType t = base[s];
    while(s<e){
        for(; e>s && base[e]>=t; e--);
        base[s] = base[e];
        for(; s<e && base[s]<=t; s++);
        base[e] = base[s];
    }
    base[s] = t;
    return s;
}

void SeqList::sort() {
    if(length>1)
        sort(0,length-1);
}

void SeqList::add_sq(const ElemType & elem)
{
    sort();
    for(int i=0; i<length; i++)
        if(elem<=base[i]){
            insert(i+1,elem);
            return;
        }
    add(elem);
}

SeqList operator+(const SeqList & a, const SeqList & b)
{
    int i;
    SeqList c(a.length+b.length);
    for(i=0; i<a.length; i++)
        c.base[i] = a.base[i];
    for(int j=0; j<b.length; j++)
        c.base[i++] = b.base[j];
    c.length = a.length+b.length;
    return c;
}
SeqList operator^(const SeqList & a, const SeqList & b)
{
    SeqList e;
    SeqList c = a;
    SeqList d = b;
    c.sort(); d.sort();
    int i=0,j=0;
    while(i<=c.length-1 && j<=d.length-1){
        if(c.base[i]<=d.base[j]){
            e.add(c.base[i]);
            i++;
        }
        else{
            e.add(d.base[j]);
            j++;
        }
    }
    while(i<=c.length-1){
        e.add(c.base[i++]);
    }
    while (j<=d.length-1){
        e.add(d.base[j++]);
    }
    return e;
}

ostream & operator<<(ostream & out, const SeqList & a)
{
    out<<"[";
    for(int i=0,end=a.length-1; i<end; i++)
        out<<a.base[i]<<",";
    if(a.length-1>=0)
        out<<a.base[a.length-1];
    out<<']';
    return out;
}













































































































































































































































