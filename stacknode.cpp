#include<iostream>
#include<string>
#include<cstdlib>
#include"node.h"
#include"stacknode.h"

void emptyStackNodeException();
void noStackNodeException();


template<typename T>
MyStackNode<T>::MyStackNode() // konstruktor
    :head(NULL)    {}

template<typename T>
MyStackNode<T>::~MyStackNode() // destruktor
    {}

// DODAJE ELEMENT

template<typename T>
void MyStackNode<T>::push(const T &e){
    MyNode<T>* v = new MyNode<T>; // tworzy wezel
    v->element = e; // instrukcje ustalajace kazdy nowy element na head
    v->next = head;
    head = v;
}

// USUWA ELEMENT GLOWY

template<typename T>
void MyStackNode<T>::pop(){
    if(MyStackNode<T>::empty()) { emptyStackNodeException(); return;}
    MyNode<T>* old = head; // wezel pomocniczy
    head = old->next;
    delete old; // usuwanie wezla pomocniczego
}

// ZWRACA PRAWDE JESLI STOS JEST PUSTY

template<typename T>
bool MyStackNode<T>::empty(){ // funkcja zwracajaca prawde jesli stos jest pusty
    if(head==NULL) return true;
    else return false;
}

// WYSWIETLA GLOWE STOSU

template<typename T>
void MyStackNode<T>::front(){ // wyswietla head
    if(MyStackNode<T>::empty()) { emptyStackNodeException(); return;}
    std::cout << head->getElement();
    std::cout << "\n";
}

// WYSWIETLA CALA ZAWARTOSC STOSU

template<typename T>
void MyStackNode<T>::displayList(){ // wyswietla caly stos
    if(MyStackNode<T>::empty()) { emptyStackNodeException(); return;}
    MyNode<T>* tmp = new MyNode<T>; // tworzy wezel pomocniczy
    tmp=head; // ustawia wezel pomocniczy na head naszego stosu
    do{
        std::cout << tmp->getElement();
        tmp=tmp->getNext();
        std::cout << "\t";
    }while(tmp!=nullptr);
    delete tmp; // usuwa wezel pomocniczy
}

void emptyStackNodeException(){
    std::cout << "Stos jest pusty..\n";
}

void noStackNodeException(){
    std::cout << "Uwaga, stos nie istnieje!\n";
}

//########################
template class MyStackNode<int>;
template class MyStackNode<double>;
template class MyStackNode<float>;
template class MyStackNode<std::string>;
