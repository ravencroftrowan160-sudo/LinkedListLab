
#ifndef TEXTCLASS_HPP
#define TEXTCLASS_HPP

#include <stdexcept>//for exceptions

struct Node{
    char data;
    Node* next;
};

class TextClass{
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    //constructor/destructor
    TextClass();
    ~TextClass();

    void addHead(char value);
    char getHead() const;
    void removeHead();
};

#endif