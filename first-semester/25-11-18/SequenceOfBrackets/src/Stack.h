#pragma once

#include "Node.h"

class Stack {
    Node *head;
    int count;
public:
    Stack();

    void push(int data);

    int pop();

    bool isEmpty();

    ~Stack();
};
