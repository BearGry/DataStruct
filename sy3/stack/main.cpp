//
// Created by xiaodian& on 2022/11/17.
//

#include "stack.h"
#include "queue"

bool solve1();
bool solve2();

int main()
{
    cout<<"实验一的测试-用栈实现括号匹配的检验（测试三次，每次以#作为输入结束标志）:"<<endl;
    for(int i=1; i<=3; i++){
        if(solve1())
            cout<<"yes";
        else
            cout<<"no";
        cout<<endl;
        getchar();
    }

    cout<<"实验二的测试-用栈实现形如$a+b@b+a\\#$的中心对称的字符序列的检验（测试三次，每次以#作为输入结束标志）:"<<endl;
    for(int i=1; i<=3; i++){
        if(solve2())
            cout<<"yes";
        else
            cout<<"no";
        cout<<endl;
        getchar();
    }

    return 0;
}

bool solve1()
{
    char t;
    cin>>t;
    Stack<char> blacket;
    while(t != '#'){
        if(t == '(')
            blacket.push('(');
        else if(t == ')'){
            if(blacket.empty())
                return false;
            else
                blacket.pop();
        }
        cin>>t;
    }
    return blacket.empty();
}
bool solve2()
{
    char t;
    cin>>t;
    Stack<char> a,b,c;
    while (t != '#'){
        a.push(t);
        b.push(t);
        cin>>t;
    }
    int count = a.len();
    for(int i=1; i<=count; i++){
        c.push(a.top());
        a.pop();
    }
    count = count/2;
    for(int i=1; i<=count; i++){
        if(b.top() == c.top()){
            b.pop();
            c.pop();
        } else  return false;
    }
    return true;
}