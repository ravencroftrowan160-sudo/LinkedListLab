
#ifndef TEXTCLASS_HPP
#define TEXTCLASS_HPP

#include <stdexcept>//for exceptions
#include <string>

struct Node{
    char data;
    Node* next;
};

class TextClass{
private:
    Node* head;
    Node* tail;
    Node* current;
    Node* lastFound;
    
public:
    //constructor/destructor
    TextClass();
    ~TextClass();

    void addHead(char value);
    char getHead() const;
    void removeHead();

    void addTail(char value);
    char getTail() const;
    void removeTail();

    std::string displayList() const;
    bool find(char value) const;
    bool findRemove(char value);

    void append(const TextClass& otherList);
    bool findNext(char value);

    void removeLast();
    void insertLast(char value);

    void thinkSolve(TextClass& otherList);
};

#endif