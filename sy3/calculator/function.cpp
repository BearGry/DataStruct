//
// Created by xiaodian& on 2022/11/17.
//

#include "function.h"

static double cal(double, double, char);

void calculate(Stack<char> & mark, Stack<double> & numb, char t)
{
    //如果是左括号直接压入符号栈中
    if(t == '('){
        mark.push(t);
        return;
    }
    //如果是乘除，则弹出栈顶的运算符进行运算直到遇到 空栈、左括号、或是比乘除运算级更低的加减
    if(t == '*' || t == '/'){
        while(mark.empty() == false){
            char p = mark.top();
            if(p == '+' || p == '-' || p == '(')
                break;
            calculate_heart(numb,p);//运算操作
            mark.pop();
        }
        mark.push(t);
        return;
    }
    //如果是右括号，则弹出栈顶的运算符进行运算直到遇到左括号'（'
    if(t == ')'){
        char p;
        p = mark.top();
        while(p != '('){
            calculate_heart(numb,p);
            mark.pop();
            p = mark.top();
        }
        mark.pop();
        return;
    }
    //如果是加减，则弹出栈顶的运算符进行运算直到遇到 空栈 或 左括号的情况为止
    if(t == '+' || t == '-'){
        char p;
        while (mark.empty() == false){
            p = mark.top();
            if(p != '('){
                calculate_heart(numb,p);
                mark.pop();
                continue;
            }
            break;
        }
        mark.push(t);
    }
}

//calculat_heart函数为运算函数，在数字栈中弹出两个数字，用第二个 运算符 第一个的运算顺序进行运算。cal函数即为辅助用的加减乘除函数
void calculate_heart(Stack<double> & numb, char t)
{
    double b = numb.top();
    numb.pop();
    double a = numb.top();
    numb.pop();
    numb.push(cal(a,b,t));
}
static double cal(double a, double b, char t)
{
    if(t == '+')
        return a+b;
    if(t == '-')
        return a-b;
    if(t == '*')
        return a*b;
    if(t == '/'){
        if(b == 0.0){
            cout<<"0 can't be divided."<<endl;
            exit(0);
        }
        return a/b;
    }
}
