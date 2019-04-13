#pragma once

#include "Node.h"

struct Stack {
    Node *head;
    int count;

    Stack();

    void push(int data);

    void pop();

    int top();

    bool isEmpty();

    ~Stack();
};
