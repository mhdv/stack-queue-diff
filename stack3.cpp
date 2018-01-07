#include "stack3.h"
#include <iostream>
#include <string>
#include <cstdlib>

void emptyStack3Exception();
void noStack3Exception();
void negativeStack3Exception();
void fullStack3Exception();

template <typename T>
MyStack3<T>::MyStack3()
    :size(0)
    ,top(0){}
template <typename T>
MyStack3<T>::~MyStack3(){}

template <typename T>
void MyStack3<T>::tabStack(int n){
    if (n<=0) { negativeStack3Exception(); return; }
    size = n;
    S = new T[size];
    top = 0;
}

template <typename T>
void MyStack3<T>::push(T element){
    if (size<=0) { noStack3Exception(); return; }
    if (top>=size) {
        size=size+1;
        T *tmp = new T[size];
        for(int i=0; i<size-1; i++){
            tmp[i]=S[i];
        }
        delete [] S;
        S=tmp;
    }
    S[top] = element;
    top++;
}

template <typename T>
void MyStack3<T>::pop(){
    if (size<=0) { noStack3Exception(); return; }
    if (top==0) { emptyStack3Exception(); return; }
    S[top-1]=0;
    top--;
}

template <typename T>
void MyStack3<T>::front(){
    if (size<=0) { noStack3Exception(); return; }
    std::cout << S[top-1] << "\t";
}


void emptyStack3Exception(){
    std::cout << "Stos jest juz pusty.\n";
}
void noStack3Exception(){
    std::cout << "Stos nie istnieje.\n";
}
void negativeStack3Exception(){
    std::cout << "Stos musi miec okreslona liczbe elementow!\n";
}
void fullStack3Exception(){
    std::cout << "Proba przekroczenia limitu stosu!\n";
}





template class MyStack3<int>;
