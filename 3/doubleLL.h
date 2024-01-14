#ifndef DOUBLE_LL
#define DOUBLE_LL

#include <iostream>

template <class T>
class Node{
public:
    T info;
    Node *next, *prev;
    Node(){
        next = prev = 0;
    }
    Node(const T& el, Node *n = 0, Node *p = 0){
        info = el; next = n; prev = p;
    }
};

template <class T>
class DLList{
protected: 
    Node<T> *head, *tail;
public:
    void addToDTail(const T&);
    T deleteFromDTail();
    bool isEmpty(){
        return head == 0;
    }
};

#endif