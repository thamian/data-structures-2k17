#include "list.h"

void List::multipleRemove(int times) {
    
    int index;
    
    // Random.
    std::random_device rd;
    std::mt19937 gen(rd());
    
    for (int i = 0; i < times; i++) {
        
        std::uniform_int_distribution<> indexDistribution(0, size_);
        int index = indexDistribution(gen);
            
        removeElement(index);
    }
}

void List::multipleRemoveFirst(int times) {
    
    for (int i = 0; i < times; i++) {
        removeFirstElement();
    }
}

void List::multipleRemoveLast(int times) {
    
    for (int i = 0; i < times; i++) {
        removeLastElement();
    }
}
