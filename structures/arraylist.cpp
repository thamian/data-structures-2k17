#include "arraylist.h"

// Konstruktor.
ArrayList::ArrayList() {
    array_ = NULL;
    size_ = 0;
}

// Destruktor.
ArrayList::~ArrayList() {
    delete [] array_;
}

// Wyszukiwanie elementów.
int* ArrayList::findElement(unsigned int index) {
    
    int *currentElement = &array_[index];
    
    if (index >= size_)
        currentElement = NULL;
    
    return currentElement;
}

// Get.
int* ArrayList::getArray() {
    return array_;
}
