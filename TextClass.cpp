#include "TextClass.hpp"

TextClass::TextClass():head(nullptr), tail(nullptr), current(nullptr){

}

TextClass::~TextClass(){
    while(head != nullptr){
        removeHead();
    }
}

void TextClass::addHead(char value){
    Node* newHead = new Node;
    newHead->data = value;
    newHead->next = head;

    head = newHead;

    if(tail == nullptr){
        tail = head;
    }
}

char TextClass::getHead() const{
    if(head == nullptr){
        throw std::out_of_range("List is empty");
    }

    return head->data;
}

void removeHead(){
    if(head == nullptr){
        throw std::out_of_range("List is empty");
    }

    Node * temp = head;
    head = head->next;

    if(head == nullptr){
        tail == nullptr
    }

    delete temp;
}