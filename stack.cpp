#include "stack.h"
#include <iostream>
#include <string>
#include <cstdlib>

void emptyStackException();
void noStackException();
void negativeStackException();
void fullStackException();
//konstruktor-destruktor
template <typename T>
MyStack1<T>::MyStack1()
    :size(0)
    ,top(0){}
template <typename T>
MyStack1<T>::~MyStack1(){}

//inicjuje tablice, nadaje jej rozmiar
template <typename T>
void MyStack1<T>::tabStack(int n){
    if (n<=0) { negativeStackException(); return; }
    size = n;
    S = new T[size];
    top = 0;
}

//dodaje element do tablicy
template <typename T>
void MyStack1<T>::push(T element){
    if (size<=0) { noStackException(); return; }
    if (top>=size) { fullStackException(); return; }
    S[top] = element;
    top++;
}

//usuwa element z tablicy
template <typename T>
void MyStack1<T>::pop(){
    if (size<=0) { noStackException(); return; }
    if (top==0) { emptyStackException(); return; }
    S[top-1]=0;
    top--;
}

//wyswietla aktualny pierwszy element
template <typename T>
void MyStack1<T>::front(){
    if (size<=0) { noStackException(); return; }
    std::cout << S[top-1] << "\t";
}





//wyswietlanie komunikatu wyjatkow
void emptyStackException(){
    std::cout << "Stos jest juz pusty.\n";
}
void noStackException(){
    std::cout << "Stos nie istnieje.\n";
}
void negativeStackException(){
    std::cout << "Stos musi miec okreslona liczbe elementow!\n";
}
void fullStackException(){
    std::cout << "Proba przekroczenia limitu stosu!\n";
}





template class MyStack1<int>;
