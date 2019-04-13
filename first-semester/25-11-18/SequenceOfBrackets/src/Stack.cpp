#include "Stack.h"

Stack::Stack() : head(nullptr), count(0) {}

void Stack::push(int data) {
    Node *temp = new Node;
    temp->next = head;
    temp->data = data;

    head = temp;
    count++;
}

int Stack::pop() {
    if (head == nullptr) {
        return 0;
    }
    int poppedData = head->data;

    Node *temp = head;
    head = temp->next;
    delete temp;

    count--;

    return poppedData;
}

bool Stack::isEmpty() {
    return !(bool) count;
}

Stack::~Stack() {
    delete head;
}
