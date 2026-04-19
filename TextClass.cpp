#include "TextClass.hpp"

TextClass::TextClass():head(nullptr), tail(nullptr), current(nullptr), lastFound(nullptr){

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

void TextClass::append(const TextClass& otherList){
    Node* temp = otherList.head;

    while(temp != nullptr){
        addTail(temp->data);
        temp = temp->next;
    }
}

bool TextClass::findNext(char value){
    if(head == nullptr){
        return false;
    }

    if(current == nullptr){
        current = head;
    }

    Node* start = current;
    do {
        if (current->data == value) {
            lastFound = current;       // ← add this line
            current = current->next;
            if (current == nullptr) {
                current = head;
            }
            return true;
        }

        current = current->next;
        if (current == nullptr) {
            current = head;
        }
    } while (current != start);

    return false;
}

void TextClass::removeLast(){
    if(lastFound == nullptr){
        return;
    }

    if(lastFound == head){
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        delete lastFound;
    }
    else{
        Node* temp = head;
        while(temp->next != lastFound){
            temp = temp->next;
        }
        temp->next = lastFound->next;

        if(lastFound == tail){
            tail = temp;
        }
        delete lastFound;
    }

    lastFound = nullptr;
    current = nullptr;
}

void TextClass::insertLast(char value){
    if(lastFound == nullptr){
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    if(lastFound == head){
        newNode->next = head;
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != lastFound){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = lastFound;
    }
}

void TextClass::thinkSolve(TextClass& otherList){
    Node* temp1 = head;
    Node* temp2 = otherList.head;

    while(temp1 != nullptr && temp2 != nullptr && temp1->data == temp2->data){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    addTail(' ');
    addTail('a');
    addTail('n');
    addTail('d');
    addTail(' ');

    while(temp2 != nullptr){
        addTail(temp2->data);
        temp2 = temp2->next;
    }
}