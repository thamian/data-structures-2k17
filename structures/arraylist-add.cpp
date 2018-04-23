#include "arraylist.h"

void ArrayList::addElement(unsigned int index, int value) {

    if (!index) {    
        addFirstElement(value);
        return;
    }
    
    if (index >= size_) {
        addLastElement(value);
        return;
    }
    
    else {
        
        int newSize = size_ + 1;
        int *newArray = new int[newSize];
        
        for (int i = 0; i < index; i++) {
        
            newArray[i] = array_[i];
        }
    
        newArray[index] = value;
    
        for (int i = index + 1; i < newSize; i++) {
        
            newArray[i] = array_[i - 1];
        }
        
        delete [] array_;
        array_ = newArray;
        size_++;
    }
}

void ArrayList::addFirstElement(int value) {
    
    int newSize = size_ + 1;
    int *newArray = new int[newSize];
    
    newArray[0] = value;
    
    for (int i = 1; i < newSize; i++) {
        
        newArray[i] = array_[i - 1];
    }
    
    delete [] array_;
    array_ = newArray;
    size_++;
}

void ArrayList::addLastElement(int value) {
    
    int newSize = size_ + 1;
    int *newArray = new int[newSize]; 
    
    for (int i = 0; i < size_; i++) {
        
        newArray[i] = array_[i];
    }
    
    newArray[size_] = value;
    
    delete [] array_;
    array_ = newArray;
    size_++;
}
