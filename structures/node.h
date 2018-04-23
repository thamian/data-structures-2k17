#ifndef NODE_H
#define NODE_H

// Node - element listy dwukierunkowej (LinkedList).
struct Node {
    
private:
    Node *previous_;
    Node *next_;
    int value_;
    
public:
    Node(Node *previous, Node *next, int value);
    
    Node * getPrevious();
    Node * getNext();
    int getValue();
    
    void setPrevious(Node *previous);
    void setNext(Node *next);
    void setValue(int value);
};

#endif // NODE_H
