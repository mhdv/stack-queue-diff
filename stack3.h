#ifndef STACK3_H
#define STACK3_H

#include <iostream>
#include <string>
#include <cstdlib>


template <typename T>
class MyStack3{
protected:
    int size, top;
    T *S;
public:
    MyStack3();
    ~MyStack3();
    void tabStack(int n);
    void push(T element);
    void pop();
    void front();

    //akcesor do TOP
    int getTop(){return top;}
};

#endif // STACK3_H
