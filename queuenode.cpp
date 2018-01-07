#include <iostream>
#include <string>
#include <cstdlib>
#include "queuenode.h"

template <typename T>
void MyQueueNode<T>::push(const T &e){
    MyNode<T>* v = new MyNode<T>;
    v->element = e;
    v->next = nullptr;
    if(MyStackNode<T>::head==nullptr) MyStackNode<T>::head = v;
    else tail->next = v;
    tail = v;
}

template class MyQueueNode<int>;
