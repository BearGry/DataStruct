//
// Created by xiaodian& on 2023/2/18.
//

#ifndef EXP_CODING_STACK_H
#define EXP_CODING_STACK_H


#include "iostream"
#include "cstdlib"
#define INIT_SIZE 14
#define EXPAND 5
using namespace std;

template<typename elemtype>
class stack{
private:
    elemtype *base;
    int size;
    int top;

    bool expand(){
        elemtype *newbase = (elemtype *) realloc(base, (size+EXPAND)* sizeof(elemtype));
        if(newbase){
            base = newbase;
            size += EXPAND;
            return true;
        }
        return false;
    }

public:
    stack();
    ~stack();

    void clear(){top = 0;}
    bool empty(){return top == -1;}
    int length(){return top+1;}

    bool gettop(elemtype &elem);
    bool push(const elemtype& elem);
    bool pop(elemtype& elem);
};

template<typename elemtype>
stack<elemtype>::stack() {
    base = (elemtype *)malloc(INIT_SIZE* sizeof(elemtype));
    top = -1;
    size = INIT_SIZE;
}

template<typename elemtype>
stack<elemtype>::~stack() {
    free(base);
}

template<typename elemtype>
bool stack<elemtype>::gettop(elemtype &elem) {
    if(top == -1)
        return false;
    elem = base[top];
    return true;
}

template<typename elemtype>
bool stack<elemtype>::push(const elemtype &elem) {
    if(top == size-1){
        if(!expand())
            return false;
    }
    base[++top] = elem;
    return true;
}

template<typename elemtype>
bool stack<elemtype>::pop(elemtype &elem) {
    if(top == -1)
        return false;
    elem = base[top--];
    return true;
}



#endif //EXP_CODING_STACK_H
