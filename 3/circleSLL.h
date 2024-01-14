#include <iostream>
//#include <fstream>

#ifndef CIRCLESSL_H
#define CIRCLESSL_H


class Node{
public:
    int info;
    Node* next;
    //Node(int el){info = el;}
    Node(int el, Node* ptr = 0){info = el; next = ptr;}
};


class CircleSLL{
public:
    ~CircleSLL(){
        for(Node *p; !isEmpty();){
            p = head->next;
            delete head;
            head = p;
        }
    }
    void addToTail(int);
    void addToHead(int);
    bool isEmpty(){
        return 0 == head;
    }
    void printList();
    int delFromTail();
    int delFromHead();
    int countNodes();
private:
    Node *head, *tail;
};



void CircleSLL::addToTail(int el){
    if(!isEmpty()){
        tail = new Node(el);
        tail->next = tail;
    }else{
        tail->next = new Node(el, tail->next);
        tail = tail->next;
    }
}

#endif