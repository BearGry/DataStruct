//
// Created by xiaodian& on 2022/10/29.
//

#include "SeqList.h"


SeqList::SeqList(): length(0) {}

SeqList::SeqList(const SeqList & seqList)
{
    length = seqList.length;
    for(int i=0; i<length; i++)
        base[i] = seqList.base[i];
}
SeqList::~SeqList() {}

SeqList & SeqList::operator=(const SeqList & seqList)
{
    if(this == &seqList)
        return *this;
    length = seqList.length;
    for(int i=0; i<length; i++)
        base[i] = seqList.base[i];
}

bool SeqList::insert(int pos, const ElemType & elem)
{
    if(length == MAX_SIZE)
        return false;
    if(pos<1 || pos>length+1)
        return false;
    for(int i=length-1,end=pos-1; i>=end; i--)
        base[i+1] = base[i];
    base[pos-1] = elem;
    length++;
    return true;
}

bool SeqList::add(const ElemType & elem)
{
    if(length == MAX_SIZE)
        return false;
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
void SeqList::sort()
{
    if(length>1)
        sort(0,length-1);
}

bool SeqList::add_sq(const ElemType & elem)
{
    if(length == MAX_SIZE)
        return false;
    sort();
    for(int i=0; i<length; i++)
        if(elem<=base[i]){
            insert(i+1,elem);
            return true;
        }
    add(elem);
    return true;
}

SeqList operator+(const SeqList & a, const SeqList & b)
{
    int i;
    SeqList c;
    if(a.length == MAX_SIZE){
        return a;
    }
    else{
        for(i=0; i<a.length; i++)
            c.base[i] = a.base[i];
        for(int j=0; j<b.length && i<MAX_SIZE; j++)
            c.base[i++] = b.base[j];
        c.length = i;
        return c;
    }

}
SeqList operator^(const SeqList & a, const SeqList & b)
{
    int f=0;
    SeqList e;
    SeqList c = a;
    SeqList d = b;
    c.sort(); d.sort();
    int i=0,j=0;
    while(i<=c.length-1 && j<=d.length-1 && f<MAX_SIZE){
        if(c.base[i]<=d.base[j]){
            e.base[f++]=c.base[i];
            i++;
        }
        else{
            e.base[f++]=d.base[j];
            j++;
        }
    }
    while(i<=c.length-1 && f<MAX_SIZE){
        e.base[f++]=c.base[i++];
    }
    while (j<=d.length-1 && f<MAX_SIZE){
        e.base[f++]=d.base[j++];
    }
    e.length = f;
    return e;
}

ostream & operator<<(ostream & cout, const SeqList & a)
{
    cout<<"[";
    for(int i=0,end=a.length-1; i<end; i++)
        cout<<a.base[i]<<",";
    if(a.length-1>=0)
        cout<<a.base[a.length-1];
    cout<<']';
    return cout;
}













































































































































































































































