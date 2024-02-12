//
// Created by xiaodian& on 2023/2/18.
//
#include "Stack.h"

int main(){
    stack<char> a;
    char c;
    cin>>c;
    while (c != '#'){
        if(c == '(')
            a.push(c);
        else if(c == ')')
            if(!a.pop(c)){
                cout<<"no"<<endl;
                return 0;
            }
        cin>>c;
    }
    if(a.empty())
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}


























































































