#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.h"

//funkcja dziedziczy po stack.h
//przeslania tylko funkcje push (kod w pliku queue.cpp)

template <typename T>
class MyQueue1: public MyStack1<T>{
public:
    void push(T element);
};

#endif // QUEUE_H
