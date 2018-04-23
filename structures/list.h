#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <random>
#include <iostream>
#include <ios>

// List - klasa nadrzędna dla tablicy (ArrayList) i listy dwukierunkowej (LinkedList).
class List {
    
protected:
    unsigned int size_;
    
public:
    virtual void addElement(unsigned int index, int value) = 0;
    virtual void addFirstElement(int value) = 0;
    virtual void addLastElement(int value) = 0;
    
    virtual void removeElement(unsigned int index) = 0;
    virtual void removeFirstElement() = 0;
    virtual void removeLastElement() = 0;
    
    void multipleAdd(int times, std::ifstream &file, bool random);
    void multipleAddFirst(int times, std::ifstream &file, bool random);
    void multipleAddLast(int times, std::ifstream &file, bool random);
    
    void multipleRemove(int times);
    void multipleRemoveFirst(int times);
    void multipleRemoveLast(int times);

    unsigned int getSize();
};

#endif // LIST_H
