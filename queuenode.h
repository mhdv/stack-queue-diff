#ifndef QUEUENODE_H
#define QUEUENODE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "stacknode.h"


template <typename T>
class MyQueueNode: public MyStackNode<T>{
public:
    void push(const T& e);
protected:
    MyNode<T>* tail;
};

#endif // QUEUENODE_H
