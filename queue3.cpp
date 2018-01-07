#include "queue3.h"
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
void MyQueue3<T>::push(T element){
    if (MyStack3<T>::size<=0) { std::cout << "Stos nie istnieje.\n"; return; }
    if (MyStack3<T>::top>=MyStack3<T>::size) {
        MyStack3<T>::size=MyStack3<T>::size+1;
        T *tmp = new T[MyStack3<T>::size];
        for(int i=0; i<MyStack3<T>::size-1; i++){
            tmp[i]=MyStack3<T>::S[i];
        }
        delete [] MyStack3<T>::S;
        MyStack3<T>::S = tmp;
    }
    for(int i=MyStack3<T>::top; i>0; i--){
        MyStack3<T>::S[i]=MyStack3<T>::S[i-1];
    };
    MyStack3<T>::S[0]=element;
    MyStack3<T>::top++;
}

template class MyQueue3<int>;
