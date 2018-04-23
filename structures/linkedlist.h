#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list.h"
#include "node.h"

// LinkedList - lista dwukierunkowa
class LinkedList : public List {
    
    Node *head_;
    Node *tail_;
    
public:
    LinkedList();
    ~LinkedList();
    
    void addElement(unsigned int index, int value);
    void addFirstElement(int value);
    void addLastElement(int value);
    
    void removeElement(unsigned int index);
    void removeFirstElement();
    void removeLastElement();
    
    Node * findElement(unsigned int index);
    
    Node * getHead();
    Node * getTail();
};

#endif // LINKEDLIST_H
