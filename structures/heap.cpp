#include "heap.h"

void Heap::rebuildUp() {
    
    int k = size_ - 1;
        
    while (k > 0) {
        
        if (array_[k] > array_[(k - 1) / 2]) {
            
            int arrayK = array_[k];
            
            array_[k] = array_[(k - 1) / 2];
            array_[(k - 1) / 2] = arrayK;
            
            k = (k - 1) / 2;
        }
        
        else {
            return;
        }
    }
}

void Heap::rebuildDown() {
    
    if (!size_)
        return;
    
    int k = 0;
    int tmp;
    
    while (k < size_) {
        
        if (2 * k + 2 < size_) {       // jeśli syn istnieje
            
            // sprawdzenie warunku kopca
            if (array_[k] < array_[2 * k + 1] || array_[k] < array_[2 * k + 2]) {
                
                if (array_[2 * k + 1] > array_[2 * k + 2]) {
                    tmp = array_[k];
                    array_[k] = array_[2 * k + 1];
                    array_[2 * k + 1] = tmp;
                    
                    k = 2 * k + 1;
                }
                
                else {
                    tmp = array_[k];
                    array_[k] = array_[2 * k + 2];
                    array_[2 * k + 2] = tmp;
                    
                    k = 2 * k + 2;
                }
            }
            
            else {
                return;
            }
        }
        
        else if (2 * k + 1 < size_) {
            
            if (array_[k] < array_[2 * k + 1]) {
                tmp = array_[k];
                array_[k] = array_[2 * k + 1];
                array_[2 * k + 1] = tmp;
                    
                k = 2 * k + 1;
            }
            
            else {
                return;
            }
        }
        
        else {
            return;
        }
    }
}

void Heap::push(int value) {
    
    addLastElement(value);
    rebuildUp();
}

void Heap::pop() {
    
    removeFirstElement();
    rebuildDown();
}

void Heap::removeFirstElement() {
    
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
    
    newArray[0] = array_[newSize];
    
    for (int i = 1; i < newSize; i++) {
        
        newArray[i] = array_[i];
    }
    
    delete [] array_;
    array_ = newArray;
    size_--;
}

void Heap::multiplePush(int times, std::ifstream& file, bool random) {
    
    int value;
    
    // Random.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDistribution(-__INT_MAX__ - 1, __INT_MAX__);
    
    if (random) {
        for (int i = 0; i < times; i++) {
            
            value = valueDistribution(gen);
            push(value);
        }
        return;
    }
    
    int input;
    int size;
    file >> size;
    
    for (int i = 0; (file >> input) && (i < times && i < size); i++) {
        
        push(input);
    }
    
    file.clear();
    file.seekg(0, std::ios::beg);
}

void Heap::multiplePop(int times) {
    
    for (int i = 0; i < times; i++) {
        pop();
    }
}
