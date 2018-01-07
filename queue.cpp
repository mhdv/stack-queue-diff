#include "queue.h"
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
void MyQueue1<T>::push(T element){
    if (MyStack1<T>::size<=0) { std::cout << "Stos nie istnieje.\n"; return; }
    if (MyStack1<T>::top>=MyStack1<T>::size) { std::cout << "Proba przekroczenia limitu stosu!\n"; return; }
    for(int i=MyStack1<T>::top; i>0; i--){
        MyStack1<T>::S[i]=MyStack1<T>::S[i-1];
    };
    MyStack1<T>::S[0]=element;
    MyStack1<T>::top++;
}

template class MyQueue1<int>;
