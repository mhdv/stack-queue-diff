#ifndef QUEUE3_H
#define QUEUE3_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "stack3.h"

template <typename T>
class MyQueue3: public MyStack3<T>{
public:
    void push(T element);
};


#endif // QUEUE3_H
