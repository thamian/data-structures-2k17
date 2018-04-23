#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"

// ArrayList - klasa reprezentująca tablicę.
class ArrayList : public List {

protected:
    int *array_;

public:
    ArrayList();
    ~ArrayList();
    
    void addElement(unsigned int index, int value);
    void addFirstElement(int value);
    void addLastElement(int value);
    
    void removeElement(unsigned int index);
    void removeFirstElement();
    void removeLastElement();
    
    int* findElement(unsigned int index);
    
    int* getArray();
};

#endif // ARRAYLIST_H
