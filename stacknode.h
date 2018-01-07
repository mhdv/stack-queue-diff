#ifndef STACKNODE_H
#define STACKNODE_H

#include<iostream>
#include<string>
#include<cstdlib>
#include"node.h"


// opisy w pliku .cpp

template <typename T>
class MyStackNode{
public:
    MyStackNode();
    ~MyStackNode();
    bool empty();
    void displayList();
    void front();
    void push(const T& e);
    void pop();
protected:
    MyNode<T>* head;
};


#endif // STACKNODE_H
