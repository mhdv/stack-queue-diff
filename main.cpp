#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <time.h>
#include "stack.h"
#include "stack2.h"
#include "stack3.h"
#include "queue.h"
#include "queue2.h"
#include "queue3.h"
#include "stacknode.h"
#include "queuenode.h"
// funckje "poboczne" do wyswietlania stosu/kolejki
void showStack1(MyStack1<int> s);
void showQueue1(MyQueue1<int> s);
void showStack2(MyStack2<int> s);
void showQueue2(MyQueue2<int> s);
void showStack3(MyStack3<int> s);
void showQueue3(MyQueue3<int> s);
void timeMeasure(time_t beginning);
const int ilosc=100000;
int k[ilosc];



// main w ktorym mierzone sa czasy poszczegolnych implementacji


// w komentarzach funkcje wyswietlania zawartosci
// brak komentarzy opisujacych poszczegolne elementy
// std::cout'y wskazuja co robi dany fragment kodu

int main()
{
    for(int i=0; i<ilosc; i++){
        k[i]=std::rand()%100;
    }

    // STL #############

    time_t ksstart = clock();
    // a'la kolejka na STLu
    std::list<int> kolejkastl;
    for(int i=0; i<ilosc; i++){
        kolejkastl.push_back(k[i]);
    }
    std::cout << "Kolejka na STL'u: \n";
//    for(int i=0; i<ilosc; i++){
//        std::list<int> tmp2stl = kolejkastl;
//        std::cout << kolejkastl.front() << "\t";
//        kolejkastl.pop_front();
//    }
    timeMeasure(ksstart);
    std::cout << "\n";

    time_t ssstart = clock();
    // a'la stos na STLu
    std::list<int> listastl;
    for(int i=0; i<ilosc; i++){
        listastl.push_front(k[i]);
    }
    std::cout << "Stos na STL'u: \n";
//    for(int i=0; i<ilosc; i++){
//        std::list<int> tmpstl = listastl;
//        std::cout << listastl.front() << "\t";
//        listastl.pop_front();
//    }
    timeMeasure(ssstart);
    std::cout << "\n";

    // Z LISTY DRUGIEJ #############

    time_t knstart = clock();
    // kolejka na liscie z listy 2'iej
    MyQueueNode<int>* kolejkawezel = new MyQueueNode<int>;
    for(int i=0; i<ilosc; i++){
        kolejkawezel->push(k[i]);
    }
    std::cout << "Kolejka na bazie listy drugiej: \n";
//    kolejkawezel->displayList();
    timeMeasure(knstart);
    std::cout << "\n";

    time_t snstart = clock();
    // stos na liscie z listy 2'iej
    MyStackNode<int>* stoswezel = new MyStackNode<int>;
    for(int i=0; i<ilosc; i++){
        stoswezel->push(k[i]);
    }
    std::cout << "Stos na bazie listy drugiej: \n";
//    stoswezel->displayList();
    timeMeasure(snstart);
    std::cout << "\n";

    // TABLICE Z INKREMENTACJA #############

    time_t k3start = clock();
    //test kolejki z inkrementacja size=size+C, DOMYSLNIE C=500
    MyQueue3<int> kolejka3;
    kolejka3.tabStack(1);
    for(int i=0; i<ilosc; i++){
        kolejka3.push(k[i]);
    }
    std::cout << "Kolejka na tablicy z inkrementacja o C: \n";
//    showQueue3(kolejka3);
    timeMeasure(k3start);
    std::cout << "\n";

    time_t s3start = clock();
    //test stosu z inkrementacja size=size+C, DOMYSLNIE C=500
    MyStack3<int> stos3;
    stos3.tabStack(1);
    for(int i=0; i<ilosc; i++){
        stos3.push(k[i]);
    }
    std::cout << "Stos na tablicy z inkrementacja o C: \n";
//    showStack3(stos3);
    timeMeasure(s3start);
    std::cout << "\n";

    // TABLICE Z INKREMENTACJA X2 #############

    time_t k2start = clock();
    //test kolejki z inkrementacja x2
    MyQueue2<int> kolejka2;
    kolejka2.tabStack(1);
    for(int i=0; i<ilosc; i++){
        kolejka2.push(k[i]);
    }
    std::cout << "Kolejka na tablicy z inkrementacja x2: \n";
//    showQueue2(kolejka2);
    timeMeasure(k2start);
    std::cout << "\n";

    time_t s2start = clock();
    //test stosu z inkrementacja x2
    MyStack2<int> stos2;
    stos2.tabStack(1);
    for(int i=0; i<ilosc; i++){
        stos2.push(k[i]);
    }
    std::cout << "Stos na tablicy z inkrementacja x2: \n";
//    showStack2(stos2);
    timeMeasure(s2start);
    std::cout << "\n";

    // TABLICE Z PREDEFINIOWANYM ROZMIAREM #############

    time_t k1start = clock();
    //test kolejki
    MyQueue1<int> kolejka;
    kolejka.tabStack(ilosc);
    for(int i=0; i<ilosc; i++){
        kolejka.push(k[i]);
    }
    std::cout << "Kolejka na tablicy z danym rozmiarem: \n";
//    showQueue1(kolejka);
    timeMeasure(k1start);
    std::cout << "\n";

    time_t s1start = clock();
    //test stosu
    MyStack1<int> stos;
    stos.tabStack(ilosc);
    for(int i=0; i<ilosc; i++){
        stos.push(k[i]);
    }
    std::cout << "Stos na tablicy z danym rozmiarem: \n";
//    showStack1(stos);
    timeMeasure(s1start);
    std::cout << "\n";
    return 0;
}












void showStack1(MyStack1<int> s){
    MyStack1<int> tmp = s;
    for(int i=0; i<s.getTop(); i++){
        tmp.front();
        tmp.pop();
    }
}

void showQueue1(MyQueue1<int> s){
    MyQueue1<int> tmp = s;
    for(int i=0; i<s.getTop(); i++){
        tmp.front();
        tmp.pop();
    }
}

void showStack2(MyStack2<int> s){
    MyStack2<int> tmp;
    tmp = s;
    for(int i=0; i<s.getTop(); i++){
        tmp.front();
        tmp.pop();
    }
}

void showQueue2(MyQueue2<int> s){
    MyQueue2<int> tmp = s;
    for(int i=0; i<s.getTop(); i++){
        tmp.front();
        tmp.pop();
    }
}

void showStack3(MyStack3<int> s){
    MyStack3<int> tmp;
    tmp = s;
    for(int i=0; i<s.getTop(); i++){
        tmp.front();
        tmp.pop();
    }
}

void showQueue3(MyQueue3<int> s){
    MyQueue3<int> tmp = s;
    for(int i=0; i<s.getTop(); i++){
        tmp.front();
        tmp.pop();
    }
}

void timeMeasure(time_t beginning){
    time_t stop = clock();
    std::cout << (stop-beginning)/(CLOCKS_PER_SEC/1000);
}
