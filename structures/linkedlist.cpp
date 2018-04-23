#include "linkedlist.h"

// Konstruktor.
LinkedList::LinkedList() {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

// Destruktor.
LinkedList::~LinkedList() {
    
    Node *currentElement = head_;
    Node *nextElement;
    
    for (int i = 0; i < size_; i++) {
        
        nextElement = currentElement->getNext();
        delete currentElement;
        currentElement = nextElement;
    }
}

// Wyszukiwanie elementów w liście.
Node * LinkedList::findElement(unsigned int index) {
    
    Node *currentElement;
    
    if (index >= size_)
        return NULL;
        
    if (index < size_/2) {                                   // dostosowanie wyszukiwania - dla mniejszych od index - od head, dla reszty od tail
        
        currentElement = head_;                              // index = 0, dlatego for od 1
        for (int i = 1; i <= index; i++) {
            
            currentElement = currentElement->getNext();
        }
        return currentElement;
    }
    
    else {
        
        currentElement = tail_;                              // index = size - 1, dlatego for od size - 2
        for (int i = size_ - 2; i >= index; i--) {
            
            currentElement = currentElement->getPrevious();
        }
        return currentElement;
    }
}

// Get.
Node * LinkedList::getHead() {
    return head_;
}

Node * LinkedList::getTail() {
    return tail_;
}
