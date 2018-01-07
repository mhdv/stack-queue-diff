#ifndef STACK2_H
#define STACK2_H

#include <iostream>
#include <string>
#include <cstdlib>


template <typename T>
class MyStack2{
protected:
    int size, top;
    T *S;
public:
    MyStack2();
    ~MyStack2();
    void tabStack(int n);
    void push(T element);
    void pop();
    void front();

    //akcesor do TOP
    int getTop(){return top;}
};

#endif // STACK2_H
