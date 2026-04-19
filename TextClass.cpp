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
        throw std::out_of_range("Empty List");
    }

    return head->data;
}

void TextClass::removeHead(){
    if(head == nullptr){
        throw std::out_of_range("Empty List");
    }

    Node * temp = head;
    head = head->next;

    if(head == nullptr){
        tail = nullptr;
    }

    delete temp;
}

void TextClass::addTail(char value){
    Node * newTail = new Node;
    newTail->data = value;
    newTail->next = nullptr;

    if(tail == nullptr){
        head = newTail;
        tail = newTail;
    }
    else{
        tail->next = newTail;
        tail = newTail;
    }
}

char TextClass::getTail() const{
    if(tail == nullptr){
        throw std::out_of_range("Empty List");
    }

    return tail->data;
}

void TextClass::removeTail(){
    if(tail == nullptr){
        throw std::out_of_range("Empty List");
    }

    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    //find node before tail
    Node* prev = head;
    while(prev->next != tail){
        prev = prev->next;
    }

    delete tail;
    tail = prev;
    tail->next = nullptr;
}

std::string TextClass::displayList() const{
    std::string result;
    Node* temp = head;

    while(temp != nullptr){
        result += temp->data;
        result += ' ';
        temp = temp->next;
    }

    return result;
}

bool TextClass::find(char value) const{
    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == value){
            return true;
        }

        temp = temp->next;
    }

    return false;
}

bool TextClass::findRemove(char value){
    if (head == nullptr) {
        return false;
    }

    if (head->data == value) {
        removeHead();
        return true;
    }

    Node* prev = head;
    while (prev->next != nullptr && prev->next->data != value) {
        prev = prev->next;
    }

    if (prev->next == nullptr) {
        return false;
    }

    Node* target = prev->next;

    if (target == tail) {
        removeTail();
        return true;
    }

    prev->next = target->next;
    delete target;
    return true;
}