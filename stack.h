#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <cstdlib>


//opisy funkcji w pliku cpp

template <typename T>
class MyStack1{
protected:
    int size, top;
    T *S;
public:
    MyStack1();
    ~MyStack1();
    void tabStack(int n);
    void push(T element);
    void pop();
    void front();

    //akcesor do TOP
    int getTop(){return top;}
};

#endif // STACK_H
