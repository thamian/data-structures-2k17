#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "structures/list.h"
#include "structures/arraylist.h"
#include "structures/linkedlist.h"
#include "structures/heap.h"
#include <ctime>

class UI {
    
    std::string message_[30];
    std::string errorMessage_[2];
    
    std::ofstream pomiary;
    
public:
    UI();
    
    void showMessage(unsigned int index);
    void showErrorMessage(unsigned int index);
    void showText(std::string text);
    
    int getNumber();
    int getNumber(unsigned int index);
    char getChar(unsigned int index);
    
    std::string getInput();
    std::string getInput(unsigned int index);
    
    void showStructure(ArrayList *arrayList);
    void showStructure(LinkedList *linkedList);
    void showStructure(Heap *heap);
    
    void structureMenu(List *list, std::ifstream &file);
    void heapMenu(Heap *heap, std::ifstream &file);
};

#endif // UI_H
