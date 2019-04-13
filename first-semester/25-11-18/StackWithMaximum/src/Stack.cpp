#include "Stack.h"

Stack::Stack() : head(nullptr), count(0) {}

void Stack::push(int data) {
    Node *temp = new Node;
    temp->next = head;
    temp->data = data;
    head = temp;
    count++;
}

void Stack::pop() {
    if (head == nullptr) {
        return;
    }

    Node *temp = head;
    head = temp->next;
    delete temp;

    count--;
}

bool Stack::isEmpty() {
    return !(bool) count;
}

Stack::~Stack() {
    delete head;
}

int Stack::top() {
    return head->data;
}
