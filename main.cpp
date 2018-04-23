#include <iostream>
#include <fstream>
#include <string>
#include <ios>

#include "structures/list.h"
#include "structures/heap.h"
#include "ui.h"

int main(int argc, char **argv) {
    
    UI *userInterface = new UI();
    
    std::ifstream file;
    
    ArrayList *arrayList = new ArrayList();
    LinkedList *linkedList = new LinkedList();
    Heap *heap = new Heap();
    
    userInterface->showMessage(0);                      // Wiadomość powitalna
    userInterface->showMessage(1);                      // i lista dostępnych opcji.
    
    bool exit = false;
    while (!exit) {                                     // Główna pętla programu.
        
        std::cout << "@> ";
        switch (userInterface->getNumber()) {
            
            case 0 : {                                          // Wyświetlenie dostępnych opcji.
                
                userInterface->showMessage(1);
                
            } break;
            
            case 1 : {                                          // Wczytywanie pliku.
                
                file.close();                                       // Zamknięcie otwartego pliku 
                file.open(userInterface->getInput(7).c_str());      // i wczytanie nowego.
                
                if (file)
                    userInterface->showMessage(8);
                
                else
                    userInterface->showErrorMessage(1);
                
            } break;
            
            case 2 : {                                          // Menu do wykonywania operacji na tablicy.
                
                userInterface->structureMenu(arrayList, file);
                
            } break;
            
            case 3 : {                                          // Menu do wykonywania operacji na liście dwukierunkowej.
                
                userInterface->structureMenu(linkedList, file);
                
            } break;
            
            case 4 : {                                          // Menu do wykonywania operacji na kopcu binarnym.
                
                userInterface->heapMenu(heap, file);
                
            } break;
            
            case 5 : {                                          // Wyjście z programu.
                
                userInterface->showMessage(10);
                exit = true;
                
            } break;
            
            default : {                                         // Wykrycie nieprawidłowej instrukcji.
                
                userInterface->showErrorMessage(0);
                
            } break;
        }
    }
    
    delete userInterface;
    
    delete arrayList;
    delete linkedList;
    delete heap;
    
    return 0;
}
