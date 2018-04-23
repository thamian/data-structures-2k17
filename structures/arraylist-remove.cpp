#include "arraylist.h"

void ArrayList::removeElement(unsigned int index) {
    
    if (!size_)
        return;
    
    int newSize = size_ - 1;
    int *newArray = new int[newSize];
    
    if (!newSize) {                                         // gdy nowy rozmiar ma być 0
        
        delete [] array_;
        array_ = NULL;
        size_--;
        return;
    }
    
    if (!index) {
        
        removeFirstElement();
        return;
    }
    
    if (index >= size_) {
        
        removeLastElement();
        return;
    }
    
    else {
        
        for (int i = 0; i < index; i++) {
        
            newArray[i] = array_[i];
        }
    
        for (int i = index; i < newSize; i++) {
        
            newArray[i] = array_[i + 1];
        }
        
        delete [] array_;
        array_ = newArray;
        size_--;
    }
}

void ArrayList::removeFirstElement() {
    
    if (!size_)
        return;
        
    int newSize = size_ - 1;
    int *newArray = new int[newSize];
    
    if (!newSize) {                                         // gdy nowy rozmiar ma być 0
        
        delete [] array_;
        array_ = NULL;
        size_--;
        return;
    }
    
    for (int i = 0; i < newSize; i++) {
        
        newArray[i] = array_[i + 1];
    }
    
    delete [] array_;
    array_ = newArray;
    size_--;
}

void ArrayList::removeLastElement() {
    
    if (!size_)
        return;
        
    int newSize = size_ - 1;
    int *newArray = new int[newSize];
    
    if (!newSize) {                                         // gdy nowy rozmiar ma być 0
        
        delete [] array_;
        array_ = NULL;
        size_--;
        return;
    }
    
    for (int i = 0; i < newSize; i++) {
        
        newArray[i] = array_[i];
    }
    
    delete [] array_;
    array_ = newArray;
    size_--;
}
