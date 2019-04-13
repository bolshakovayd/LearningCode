#include "StackWithMax.h"

#include <iostream>

StackWithMax::StackWithMax() : head(nullptr), count(0) {}

void StackWithMax::push(int data) {
    Node *temp = new Node;
    temp->next = head;
    temp->data = data;
    head = temp;
    count++;
    if (count == 1 || data >= maxElStack.head->data) {
        maxElStack.push(data);
    }
}

void StackWithMax::pop() {
    if (head == nullptr) {
        std::cout << "\nStack is empty.";
        return;
    }

    Node *temp = head;
    head = temp->next;

    if (temp->data == maxElStack.head->data) {
        maxElStack.pop();
    }

    delete temp;

    count--;
}

int StackWithMax::top() {
    if (head == nullptr) {
        std::cout << "\nStack is empty.";
        return 0;
    }
    return head->data;
}

bool StackWithMax::isEmpty() {
    return !(bool) count;
}

int StackWithMax::getMax() {
    if (!count) {
        std::cout << "\nStack is empty: ";
        return 0;
    }
    return maxElStack.top();
}

StackWithMax::~StackWithMax() {
    delete head;
}
