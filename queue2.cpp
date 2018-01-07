#include "queue2.h"
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
void MyQueue2<T>::push(T element){
    if (MyStack2<T>::size<=0) { std::cout << "Stos nie istnieje.\n"; return; }
    if (MyStack2<T>::top>=MyStack2<T>::size) {
        int x=MyStack2<T>::size*2;
        T *tmp = new T[x];
        for(int i=0; i<MyStack2<T>::size; i++){
            tmp[i]=MyStack2<T>::S[i];
        }
        MyStack2<T>::S = tmp;
        MyStack2<T>::size = x;
    }
    for(int i=MyStack2<T>::top; i>0; i--){
        MyStack2<T>::S[i]=MyStack2<T>::S[i-1];
    };
    MyStack2<T>::S[0]=element;
    MyStack2<T>::top++;
}

template class MyQueue2<int>;
