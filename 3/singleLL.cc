#include <iostream>
#include "singlell.h"

IntSLList::~IntSLList() {
    for(IntNode *p; !isEmpty();){
        p = head->next;
        delete head;
        head = p;
    }
}
void IntSLList::addToHead(int el){
    head = new IntNode(el, head);
    if(tail == 0)
        tail = head;
}
void IntSLList::addToTail(int el){
    if(tail != 0){
        tail->next = new IntNode(el);
        tail = tail->next;
    }else head = tail = new IntNode(el);
}
int IntSLList::deleteFromHead(){
    if(!isEmpty())
        throw("Empty");
    int el = head->info;
    IntNode *tmp = head;
    if(head == tail)
        head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}
int IntSLList::deleteFromTail(){
    int el = tail->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    }
    else{
        IntNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    return el;
}
void IntSLList::deleteNode(int el){
    if(head != 0)
        if(head== tail && el == head->info){
            delete head;
            head = tail = 0;
        }
        else if(el == head->info){
            IntNode *tmp = head->next;
            head = head->next;
            delete tmp;
        }
        else{
            IntNode *pred, *tmp;
            for(pred = head, tmp = head->next;
                tmp != 0 && !(tmp->info == el);
                pred = pred->next, tmp = tmp->next);
            if(tmp != 0){
                pred->next = tmp->next;
                if(tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
}
bool IntSLList::isInList(int el) const {
    IntNode *tmp;
    for(tmp = head; tmp != 0 && !(tmp->info == el); tmp ->next);
    return tmp != 0;
}