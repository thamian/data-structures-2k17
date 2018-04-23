#include "node.h"

// Konstruktor.
Node::Node(Node *previous, Node *next, int value) {
    previous_ = previous;
    next_ = next;
    value_ = value;
}

// Get.
Node * Node::getPrevious() {
    return previous_;
}

Node * Node::getNext() {
    return next_;
}

int Node::getValue() {
    return value_;
}

// Set.
void Node::setPrevious(Node *previous) {
    previous_ = previous;
}

void Node::setNext(Node *next) {
    next_ = next;
}

void Node::setValue(int value) {
    value_ = value;
}
