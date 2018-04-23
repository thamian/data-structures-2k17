#ifndef HEAP_H
#define HEAP_H

#include "arraylist.h"

class Heap : public ArrayList {
    
    void rebuildUp();
    void rebuildDown();
    
public:
    void push(int value);
    void pop();
    
    void removeFirstElement() override;
    
    void multiplePush(int times, std::ifstream& file, bool random);
    void multiplePop(int times);
};

#endif // HEAP_H
