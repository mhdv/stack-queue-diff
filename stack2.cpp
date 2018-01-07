#include "stack2.h"
#include <iostream>
#include <string>
#include <cstdlib>

void emptyStack2Exception();
void noStack2Exception();
void negativeStack2Exception();
void fullStack2Exception();

template <typename T>
MyStack2<T>::MyStack2()
    :size(0)
    ,top(0){}
template <typename T>
MyStack2<T>::~MyStack2(){}

template <typename T>
void MyStack2<T>::tabStack(int n){
    if (n<=0) { negativeStack2Exception(); return; }
    size = n;
    S = new T[size];
    top = 0;
}

template <typename T>
void MyStack2<T>::push(T element){
    if (size<=0) { noStack2Exception(); return; }
    if (top>=size) {
        int x=size*2;
        T *tmp = new T[x];
        for(int i=0; i<size; i++){
            tmp[i]=S[i];
        }
        S=tmp;
        size=x;
    }
    S[top] = element;
    top++;
}

template <typename T>
void MyStack2<T>::pop(){
    if (size<=0) { noStack2Exception(); return; }
    if (top==0) { emptyStack2Exception(); return; }
    S[top-1]=0;
    top--;
}

template <typename T>
void MyStack2<T>::front(){
    if (size<=0) { noStack2Exception(); return; }
    std::cout << S[top-1] << "\t";
}


void emptyStack2Exception(){
    std::cout << "Stos jest juz pusty.\n";
}
void noStack2Exception(){
    std::cout << "Stos nie istnieje.\n";
}
void negativeStack2Exception(){
    std::cout << "Stos musi miec okreslona liczbe elementow!\n";
}
void fullStack2Exception(){
    std::cout << "Proba przekroczenia limitu stosu!\n";
}





template class MyStack2<int>;
