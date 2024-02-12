#include "function.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<<"test:"<<endl;
    for(int times=1; times<=3; times++){
        string infix;
        cin>>infix;

        Stack<double> numb; //数字栈
        Stack<char> mark;   //运算符栈
        char t_char,t_next_char;
        double t_num;
        for(int i=0,end=infix.length(); i<end; i++){
            t_char = infix[i];
            //下面的if部分是将 数 存入数字栈中的操作，因为不知道数是几位，所以需要往后判断，这里支持输入的是小数
            if(t_char>='0' && t_char<='9'){
                t_num = t_char - '0';
                int division = 1;
                bool flag = false;
                t_next_char = infix[++i];
                while(t_next_char>='0' && t_next_char<='9' || t_next_char == '.'){
                    if(t_next_char == '.'){
                        flag = true;
                        t_next_char = infix[++i];
                        continue;
                    }
                    t_num = t_num*10 + t_next_char - '0';
                    if(flag)
                        division *= 10;
                    t_next_char = infix[++i];
                }
                numb.push(t_num/division);//把数压入数字栈，然后直接退出即可
                i--;
                continue;
            }
            //如果是 数 的话，本次循环就结束了，进入下一次循环中，如果是运算符，则进行下面的操作
            //关键函数-运算
            calculate(mark,numb,t_char);
        }
        //最后把运算符栈中的元素全部弹出运算，即可运算出结果
        while(mark.empty() == false){
            t_char = mark.top();
            calculate_heart(numb,t_char);
            mark.pop();
        }
        cout<<numb.top()<<endl;
    }


    return 0;
}
