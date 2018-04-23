#include "ui.h"

UI::UI() {
    
    // Wiadomość powitalna.
    message_[0] = "Struktury danych i złożoność obliczeniowa - projekt 1\nby Damian Korzekwa\n\n";
    
    // Lista dostępnych opcji.
    message_[1] = "__________________________________________________\n\n0 - Wyświetlenie dostępnych opcji\n1 - Wczytywanie pliku\n2 - Operacje dla tablicy\n3 - Operacje dla listy dwukierunkowej\n4 - Operacje dla kopca binarnego\n5 - Wyjście z programu\n__________________________________________________\n\n";
    
    // Nazwy struktur.
    message_[2] = "\nTablica\n";
    message_[3] = "\nLista dwukierunkowa\n";
    message_[4] = "\nKopiec binarny\n";
    
    // Lista dostępnych opcji dla menu tablicy i listy dwukierunkowej.
    message_[6] = "__________________________________________________\n\n0 - Wyświetlenie dostępnych opcji\n1 - Wyświetlenie struktury\n2 - Dodawanie elementów\n3 - Usuwanie elementów\n4 - Wyszukiwanie elementów\n5 - Powrót do menu głównego\n__________________________________________________\n\n";
    
    // Komunikaty obsługi plików.
    message_[7] = "\nProszę podać ścieżkę dostępu do pliku: ";
    message_[8] = "\nPlik został wczytany poprawnie!\n\n";
    
    // Komunikaty
    message_[9] = "\nPowrót do menu głównego\n\n";
    message_[10] = "\nZakończono";
    message_[11] = "\nProszę podać tryb dodawania (pojedyncze/wielokrotne, 0/1): ";
    message_[12] = "\nProszę podać wartość: ";
    message_[13] = "\nProszę podać miejsce dodawania: (początek/indeks/koniec, 0/1/2): ";
    message_[14] = "\nProszę podać indeks: ";
    message_[15] = "\nProszę podać ilość dodawań: ";
    message_[16] = "\nCzy dodać z pliku? (T/N): ";
    message_[17] = "\nProszę podać tryb usuwania (pojedyncze/wielokrotne, 0/1): ";
    message_[18] = "\nProszę podać miejsce usuwania: (początek/indeks/koniec, 0/1/2): ";
    message_[19] = "\nProszę podać ilość usunięć: ";
    
    // Komunikaty błędów.
    errorMessage_[0] = "\nERROR: Polecenie nie zostało rozpoznane!\n\n";
    errorMessage_[1] = "\nERROR: Plik nie został wczytany!\n\n";
}

void UI::showMessage(unsigned int index) {
    
    std::cout << message_[index];
}

void UI::showErrorMessage(unsigned int index) {
    
    std::cerr << errorMessage_[index];
}


void UI::showText(std::string text) {
    
    std::cout << text << "\n";
}

int UI::getNumber() {
    
    std::string input;
    std::cin >> input;
    
    for (int i = 0; i < input.length(); i++) {
        
        if (input[i] < 48 || input[i] > 57)             // Sprawdzenie, czy wprowadzony ciąg znaków jest liczbą dodatnią.
            return -1;
    }
    
    int numberInput = atoi(input.c_str());              // Konwersja ciągu do zmiennej typu int.
    return numberInput;
}

int UI::getNumber(unsigned int index) {
    
    std::string input;
    
    std::cout << message_[index];
    std::cin >> input;
    
    for (int i = 0; i < input.length(); i++) {
        
        if (input[i] < 48 || input[i] > 57)             // Sprawdzenie, czy wprowadzony ciąg znaków jest liczbą dodatnią.
            return -1;
    }
    
    int numberInput = atoi(input.c_str());              // Konwersja ciągu do zmiennej typu int.
    return numberInput;
}

std::string UI::getInput() {
    
    std::string input;
    std::cin >> input;
    
    return input;
}

std::string UI::getInput(unsigned int index) {

    std::cout << message_[index];

    std::string input;
    std::cin >> input;
    
    return input;
}

char UI::getChar(unsigned int index) {

    std::cout << message_[index];

    std::string input;
    std::cin >> input;
    
    return input[0];
}

void UI::showStructure(ArrayList *arrayList) {
    
    int *array = arrayList->getArray();
    
    if (array == NULL) {
    
        std::cout << "\nPodana struktura nie zawiera elementów\n\n";
        return;
    }
    
    std::cout << "\n";
    
    for (int i = 0; i < arrayList->getSize(); i++) {
        
        std::cout << "[" << i << "]\t" << array[i] << "\n"; 
    }
    
    std::cout << "\n";
}

void UI::showStructure(LinkedList *linkedList) {
    
    if (!linkedList->getSize()) {
        
        std::cout << "\nPodana struktura nie zawiera elementów\n\n";
        return;
    }
        
    Node *currentElement = linkedList->getHead();
    std::cout << "\n[0]\t\t"<< currentElement->getValue() << "\t\t|[HEAD]";
    
    for (int i = 1; i < linkedList->getSize(); i++) {
        
        currentElement = currentElement->getNext();
        std::cout << "\n[" << i << "]\t\t" << currentElement->getValue() << "\t\t|";
    }
    
    std::cout << "[TAIL]\n\n";
}

void UI::showStructure(Heap *heap) {
    
    if (!heap->getSize())
        return;
    
    std::cout << "\nINFO: [rodzic]wartość[indeks]\n\n\n\n";
    
    int j = 1;
    int c = 1;
    
    int size = heap->getSize();
    
    for (int i = 0; 2 * i + 1 < size || i - 1 / 2 <= 0; i++) {
        
        if (i == c) {
            
            j = j * 2;
            c += j;
            std::cout << "------------------------------\n\n";
        }
        
        std::cout << " - - - - - - || " << heap->getArray()[i] << "[" << i << "]\n\n";
        if (2 * i + 1 < size) {
            
            std::cout << heap->getArray()[2 * i + 1] << "[" << 2 * i + 1 << "] ||- - - - - - -|| ";
        }
        
        if (2 * i + 2 < size) {
            
            std::cout << heap->getArray()[2 * i + 2] << "[" << 2 * i + 2 << "]";
        }
        std::cout << "\n\n\n";
    }
}

// Potwór spaghetti...
void UI::structureMenu(List *list, std::ifstream &file) {
    
    if (dynamic_cast<ArrayList*>(list) != NULL)
        showMessage(2);
        
    if (dynamic_cast<LinkedList*>(list) != NULL)
        showMessage(3);
    
    pomiary.open("list.txt");
    
    showMessage(6);
    
    bool exit = false;
    while (!exit) {
    
        std::cout << "@> #: ";
        switch (getNumber()) {
        
            case 0 : {
                
                showMessage(6);                                 // Wyświetlenie listy dostępnych opcji.
                
            } break;
        
            case 1 : {                                          // Wyświetlenie struktury.
                
                if (dynamic_cast<ArrayList*>(list) != NULL)
                    showStructure(dynamic_cast<ArrayList*>(list));
                    
                if (dynamic_cast<LinkedList*>(list) != NULL)
                    showStructure(dynamic_cast<LinkedList*>(list));
                
            } break;
        
            case 2 : {                                          // Dodawanie elementów.
                
                switch (getNumber(11)) {
                
                    case 0 : {                                          // Dodawanie pojedynczego elementu.
                        
                        std::string input;
                        int inputValue;
                        
                        input = getInput(12);
                        
                        try {
                            inputValue = std::stoi(input);
                            
                        } catch (std::exception &e) {
                            
                            showErrorMessage(0);
                            break;
                        }
                                       
                        switch (getNumber(13)) {
                        
                            case 0 : {  list->addFirstElement(inputValue);  } break;
                        
                            case 1 : {                                          // Dodawanie na zadanym indeksie.
                            
                                int indexValue;
                                
                                input = getInput(14);
                                
                                try {
                                    indexValue = std::stoi(input);
                            
                                } catch (std::exception &e) {
                            
                                    showErrorMessage(0);
                                    break;
                                }
                            
                                list->addElement(indexValue, inputValue);
                                
                            } break;
                            
                            case 2 : {  list->addLastElement(inputValue);   } break;
                            
                            default : { showErrorMessage(0);                } break;
                        }
                    
                    } break;
                    
                    case 1 : {                                          // Dodawanie wielokrotne.
                    
                        std::string input;
                        int inputTimes;
                        char inputChar;
                        bool random;
                        
                        input = getInput(15);
                        
                        try {
                            inputTimes = std::stoi(input);
                             
                        } catch (std::exception &e) {
                            
                            showErrorMessage(0);
                            break;
                        }
                        
                        inputChar = getChar(16);
                        
                        if (inputChar == 'T') {
                            random = false;
                        }
                        
                        else if (inputChar == 'N') {
                            random = true;
                        }
                        
                        else {
                        
                            showErrorMessage(0);
                            break;
                        }
                                       
                        switch (getNumber(13)) {
                        
                            case 0 : {  list->multipleAddFirst(inputTimes, file, random);   } break;
                        
                            case 1 : {  list->multipleAdd(inputTimes, file, random);        } break;
                            
                            case 2 : {  list->multipleAddLast(inputTimes, file, random);    } break;
                            
                            default : { showErrorMessage(0);                                } break;
                        }
                        
                    } break;
                
                    default : { showErrorMessage(0);    } break;
                }
            
            } break;
            
            case 3 : {                                          // Usuwanie elementów.
                
                switch (getNumber(17)) {
                
                    case 0 : {                                          // Usuwanie pojedynczego elementu.
                                       
                        switch (getNumber(18)) {
                        
                            case 0 : {  list->removeFirstElement(); } break;
                        
                            case 1 : {                                          // Usuwanie z podanego indeksu.
                            
                                int indexValue;
                                std:: string input = getInput(14);
                                
                                try {
                                    indexValue = std::stoi(input);
                            
                                } catch (std::exception &e) {
                            
                                    showErrorMessage(0);
                                    break;
                                }
                            
                                list->removeElement(indexValue);
                                
                            } break;
                            
                            case 2 : {  list->removeLastElement();  } break;
                            
                            default : { showErrorMessage(0);        } break;
                        }
                    
                    } break;
                    
                    case 1 : {                                          // Usuwanie wielokrotne.
                    
                        std::string input;
                        int inputTimes;
                        
                        input = getInput(19);
                        
                        try {
                            inputTimes = std::stoi(input);
                             
                        } catch (std::exception &e) {
                            
                            showErrorMessage(0);
                            break;
                        }
                                       
                        switch (getNumber(18)) {
                        
                            case 0 : {  list->multipleRemoveFirst(inputTimes);  } break;
                        
                            case 1 : {  list->multipleRemove(inputTimes);       } break;
                            
                            case 2 : {  list->multipleRemoveLast(inputTimes);   } break;
                            
                            default : { showErrorMessage(0);                    } break;
                        }
                        
                    } break;
                
                    default : { showErrorMessage(0);    } break;
                }
                
            } break;
            
            case 4 : {                                          // Wyszukiwanie elementów.
                
                std::string input;
                unsigned int inputTimes;
                input = getInput(20);
                
                try {
                    inputTimes = std::stoi(input);
                             
                } catch (std::exception &e) {
                            
                    showErrorMessage(0);
                    break;
                }
                
                for (int i = 0; i < inputTimes; i++) {
                
                    std::cout << "fdsf";
                }
                
            } break;
            
            case 5 : {                                          // Powrót do menu głównego.
                
                showMessage(9);
                exit = true;
                
            } break;
        
            default : {
            
                showErrorMessage(0);
            
            } break;
        }
    }
}

void UI::heapMenu(Heap* heap, std::ifstream& file) {
    
    showMessage(4);
    showMessage(6);
    
    bool exit = false;
    while (!exit) {
    
        std::cout << "@> #: ";
        switch (getNumber()) {
        
            case 0 : {  showMessage(6);         } break;    // Wyświetlenie listy dostępnych opcji.
        
            case 1 : {  showStructure(heap);    } break;    // Wyświetlenie struktury.
        
            case 2 : {                                          // Dodawanie elementów.
                
                switch (getNumber(11)) {
                
                    case 0 : {                                          // Dodawanie pojedynczego elementu.
                        
                        std::string input;
                        int inputValue;
                        
                        input = getInput(12);
                        
                        try {
                            inputValue = std::stoi(input);
                            
                        } catch (std::exception &e) {
                            
                            showErrorMessage(0);
                            break;
                        }
                        
                        heap->push(inputValue);
                    
                    } break;
                    
                    case 1 : {                                          // Dodawanie wielokrotne.
                    
                        std::string input;
                        int inputTimes;
                        char inputChar;
                        bool random;
                        
                        input = getInput(15);
                        
                        try {
                            inputTimes = std::stoi(input);
                             
                        } catch (std::exception &e) {
                            
                            showErrorMessage(0);
                            break;
                        }
                        
                        inputChar = getChar(16);
                        
                        if (inputChar == 'T') {
                            random = false;
                        }
                        
                        else if (inputChar == 'N') {
                            random = true;
                        }
                        
                        else {
                        
                            showErrorMessage(0);
                            break;
                        }
                                       
                        heap->multiplePush(inputTimes, file, random);
                        
                    } break;
                
                    default : { showErrorMessage(0);    } break;
                }
            
            } break;
            
            case 3 : {                                          // Usuwanie elementów.
                
                switch (getNumber(17)) {
                
                    case 0 : {                                          // Usuwanie pojedynczego elementu.
                                       
                        heap->pop();
                    
                    } break;
                    
                    case 1 : {                                          // Usuwanie wielokrotne.
                    
                        std::string input;
                        int inputTimes;
                        
                        input = getInput(19);
                        
                        try {
                            inputTimes = std::stoi(input);
                             
                        } catch (std::exception &e) {
                            
                            showErrorMessage(0);
                            break;
                        }
                                       
                        heap->multiplePop(inputTimes);
                        
                    } break;
                
                    default : { showErrorMessage(0);    } break;
                }
                
            } break;
            
            case 4 : {                                          // Wyszukiwanie elementów.
                
                std::string input;
                unsigned int inputTimes;
                input = getInput(20);
                
                try {
                    inputTimes = std::stoi(input);
                             
                } catch (std::exception &e) {
                            
                    showErrorMessage(0);
                    break;
                }
                
                for (int i = 0; i < inputTimes; i++) {
                
                    std::cout << "fdsf";
                }
                
            } break;
            
            case 5 : {                                          // Powrót do menu głównego.
                
                showMessage(9);
                exit = true;
                
            } break;
        
            default : {
            
                showErrorMessage(0);
            
            } break;
        }
    }
}
