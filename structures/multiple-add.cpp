#include "list.h"

void List::multipleAdd(int times, std::ifstream &file, bool random) {
    
    int index, value;
    
    // Random.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDistribution(-__INT_MAX__ - 1, __INT_MAX__);
    
    if (random) {
        
        for (int i = 0; i < times; i++) {
        
            std::uniform_int_distribution<> indexDistribution(0, size_);
            int index = indexDistribution(gen);
            
            value = valueDistribution(gen);
            addElement(index, value);
        }
        return;
    }
    
    int input;
    int size;
    file >> size;
    
    for (int i = 0; (file >> input) && (i < times && i < size); i++) {
        
        std::uniform_int_distribution<> indexDistribution(0, size_);
        int index = indexDistribution(gen);
        
        addElement(index, input);
    }
    
    file.clear();
    file.seekg(0, std::ios::beg);
}

void List::multipleAddFirst(int times, std::ifstream &file, bool random) {
    
    int value;
    
    // Random.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDistribution(-__INT_MAX__ - 1, __INT_MAX__);
    
    if (random) {
        for (int i = 0; i < times; i++) {
            
            value = valueDistribution(gen);
            addFirstElement(value);
        }
        return;
    }
    
    int input;
    int size;
    file >> size;
    
    for (int i = 0; (file >> input) && (i < times && i < size); i++) {
        
        addFirstElement(input);
    }
    
    file.clear();
    file.seekg(0, std::ios::beg);
}

void List::multipleAddLast(int times, std::ifstream& file, bool random) {
    
    int value;
    
    // Random.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDistribution(-__INT_MAX__ - 1, __INT_MAX__);
    
    if (random) {
        for (int i = 0; i < times; i++) {
            
            value = valueDistribution(gen);
            addLastElement(value);
        }
        return;
    }
    
    int input;
    int size;
    file >> size;
    
    for (int i = 0; (file >> input) && (i < times && i < size); i++) {
        
        addLastElement(input);
    }
    
    file.clear();
    file.seekg(0, std::ios::beg);
}
