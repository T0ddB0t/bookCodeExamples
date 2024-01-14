#include "doubleLL.h"

template <class T>
void DLList<T>::addToDTail(const T& el){
    if(tail != 0){
        tail = new Node<T>(el, 0, tail);
        tail->prev->next = tail;
    }
    else head = tail = new Node<T>(el);
}
template <class T>
T DLList<T>::deleteFromDTail(){
    T el = tail->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    }else{
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return el;
}