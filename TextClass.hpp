
#ifndef TEXTCLASS_HPP
#define TEXTCLASS_HPP

#include <stdexception>//for exceptions

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
    
};