#include "linkedlist.h"

void LinkedList::removeElement(unsigned int index) {
    
    if (!size_)
        return;
    
    if (!index) {
        
        removeFirstElement();
        return;
    }
    
    if (index >= size_) {
        
        removeLastElement();
        return;
    }
    
    else {
        
        Node *previous;
        Node *next;
        
        Node *currentElement = findElement(index);
        
        previous = currentElement->getPrevious();
        next = currentElement->getNext();
        
        previous->setNext(next);
        next->setPrevious(previous);
        
        delete currentElement;
        
        size_--;
    }
}

void LinkedList::removeFirstElement() {
    
    if (!size_)
        return;
    
    Node *next = head_->getNext();
    
    delete head_;
    head_ = next;
    
    if (size_ == 1) {
        
        tail_ = head_;
    }
    size_--;
}

void LinkedList::removeLastElement() {
    
    if (!size_)
        return;
    
    Node *previous = tail_->getPrevious();
    
    delete tail_;
    tail_ = previous;
    
    if (size_ == 1) {
        
        head_ = tail_;
    }
    size_--;
}
