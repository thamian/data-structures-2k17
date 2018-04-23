#include "linkedlist.h"

void LinkedList::addElement(unsigned int index, int value) {
    
    // 
    // addElement - dodaje element do listy
    // 
    // - Indeksy są nieujemne.
    // - Przy dodawaniu pierwszego elementu HEAD i TAIL są jednakowe (indeks nie ma wtedy znaczenia).
    // - Jeśli indeks jest zerem, to elementy są dodawane na początek listy.
    // - Jeśli indeks jest większy niż rozmiar listy, to elementy dodawane są na koniec.
    // - Jeśli indeks mieści się w rozmiarze listy, to element "zastąpi" obecny element o podanym indeksie (lista przesunie się w prawo).
    // 
    // 
    
    Node *newElement;
    Node *previous = NULL;
    Node *next = NULL;
    
    if (!size_) {                                            // gdy rozmiar listy jest równy 0
        
        newElement = new Node(previous, next, value);
        
        head_ = newElement;
        tail_ = head_;
        
        size_++;
        return;
    }
    
    if (!index) {
        
        addFirstElement(value);
        return;
    }
    
    if (index >= size_) {
        
        addLastElement(value);
        return;
    }
    
    else {
        
        Node *currentElement = findElement(index);
        
        previous = currentElement->getPrevious();
        next = currentElement;
        
        newElement = new Node(previous, next, value);
        
        previous->setNext(newElement);
        next->setPrevious(newElement);
        
        size_++;
    }
}

void LinkedList::addFirstElement(int value) {                    // dodawanie elementów na początek listy
    
    Node *newElement;
    Node *previous = NULL;
    Node *next = NULL;
    
    if (!size_) {                                            // gdy rozmiar listy jest równy 0
        
        newElement = new Node(previous, next, value);
        
        head_ = newElement;
        tail_ = newElement;
        
        size_++;
        return;
    }
    
    next = head_;                                            // następny element dodawanego elementu jest obecnym HEAD
        
    newElement = new Node(previous, next, value);
        
    next->setPrevious(newElement);                          // poprzedni element następnego elementu względem nowego HEAD (lub poprzedni obecnego HEAD)
    head_ = newElement;                                      // nowy element staje się nowym HEAD
    
    size_++;
}

void LinkedList::addLastElement(int value) {                    // dodawanie elementów na koniec listy
    
    Node *newElement;
    Node *previous = NULL;
    Node *next = NULL;
    
    if (!size_) {                                            // gdy rozmiar listy jest równy 0
        
        newElement = new Node(previous, next, value);
        
        head_ = newElement;
        tail_ = newElement;
        
        size_++;
        return;
    }
    
    previous = tail_;                                        // poprzedni element dodawanego elementu jest obecnym TAIL
        
    newElement = new Node(previous, next, value);
        
    previous->setNext(newElement);                          // następny element poprzedniego elementu względem nowego TAIL (lub następny obecnego TAIL)
    tail_ = newElement;                                      // nowy element staje się nowym TAIL
    
    size_++;
}
