//
// Created by xiaodian& on 2022/11/12.
//
#include "queue_stack.h"

int main(){
    //实验一的测试-中心对称的字符序列的检验
    cout<<"实验一的测试-中心对称的字符序列的检验(4次,以'#'作为结束标志):"<<endl;
    for(int times=1; times<=4; times++){
        bool flag = true;
        Stack<char> b;
        queue<char, 14> c;
        char t;
        cin>>t;
        //以'#'为结束标志
        while(t!='#'){
            b.push(t);
            c.push(t);

            cin>>t;
        }
        //队列从头取，栈从尾取，以此检测是否中心对称
        for(int i=1,end=c.size()/2; i<=end; i++){
            //如果有一个不相等，说明不是
            if(b.top() != c.top()){
                flag = false;
                break;
            }
            b.pop();
            c.pop();
        }
        //从中间划分成两部分，前后依次相等，说明是中心对称
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

////实验二的测试-初始化、队空/满判断，入队、出队、取队头元素、求队列长度
//    cout<<"实验二的测试:"<<endl;
//    //队列装满
//    queue<int, 6> a;
//    for(int i=0; i<=5; i++)
//        a.push(i);
//    //检测队满情况下的push函数
//    if(a.push(6))
//        cout<<"wrong"<<"、";
//    else
//        cout<<"right"<<"、";
//    //检测只有一个空位置时的push函数
//    a.pop();
//    a.push(6);
//    //检测取队首元素
//    cout<<a.top()<<"、";
//    //检测队满函数 和 弹出函数
//    if(a.full()){
//        for(int i=1; i<=6; i++)
//            a.pop();
//    }
//    //检测队空函数
//    if(a.empty())
//        cout<<"right"<<"、";
//    else
//        cout<<"wrong"<<"、";
//    //检测求队列长度的函数
//    for(int i=1; i<=8; i++){
//        a.push(1);
//        cout<<a.size()<<"、";
//    }
//    //检测清空函数
//    a.clear();
//    if(a.empty())
//        cout<<a.size()<<endl;

    return 0;
}