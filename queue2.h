#ifndef QUEUE2_H
#define QUEUE2_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "stack2.h"

template <typename T>
class MyQueue2: public MyStack2<T>{
public:
    void push(T element);
};


#endif // QUEUE2_H
