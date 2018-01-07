#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>
#include<cstdlib>
template <typename T>
class MyQueueNode;
template <typename T>
class MyStackNode;

template <typename T>
class MyNode{
private:
    T element; // zawartosc elementu
    MyNode<T>* next; // wskaznik na nastepny element
    friend class MyStackNode<T>; // lista zaprzyjaznionych klas
    friend class MyQueueNode<T>;
public:
    T getElement() {return element;} // zwraca element
    MyNode<T>* getNext() {return next;} // zwraca next
    void setElement(T newE) {element=newE;} // ustala element
    void setNext(MyNode<T> newN) {next=newN;} // ustala next
};


#endif // NODE_H
