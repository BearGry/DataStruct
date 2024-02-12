//
// Created by xiaodian& on 2022/11/4.
//

#ifndef EXP_CODING_QUEUE_H
#define EXP_CODING_QUEUE_H

#include "iostream"
using namespace std;

//（循环队列）表示队列，解决队空、队满判断条件相同的矛盾，
// 实现基于循环队列的存储结构的基本操作，初始化、队空/满判断，入队、出队、取队头元素、求队列长度等，对所写出的算法进行时间复杂度分析
template<typename elemtype, int n>
class queue{
private:
    elemtype data[n];
    int front;
    int rear;
    int count;
public:
    //front和rear分别指向队列头和尾处的下标，初始空队列情况二者都为-1
    queue(): front(-1), rear(-1), count(0) {};

    bool empty() const {return rear == -1;}    //判断队空
    bool full() const {return (rear+1)%n == front;}   //判断队满
    int size() const {return count;}   //求队长
    void clear() {front = rear = -1; count = 0;}

    //入队
    bool push(const elemtype & elem){
        //队满返回false;
        if((rear+1)%n == front)
            return false;
        //加入队尾；
        //队空
        if(rear == -1)
            front = rear = 0;
        else
            rear = (rear+1)%n;

        data[rear] = elem;
        count++;
        return true;
    }
    //出队
    bool pop(){
        //队空返回false;
        if(rear == -1)
            return false;
        //队不空，出队；
        //如果只有一个元素，要置空；
        if(front == rear)
            front = rear = -1;
            //其他情况直接出队就可以了；
        else
            front = (front+1)%n;

        count--;
        return true;
    }
    //取队头元素
    elemtype & top(){
        return data[front];
    }
    const elemtype & top() const{
        return data[front];
    }
    //取队尾元素
    elemtype & back(){
        return data[rear];
    }
    const elemtype & back() const{
        return data[rear];
    }
};



#endif //EXP_CODING_QUEUE_H
