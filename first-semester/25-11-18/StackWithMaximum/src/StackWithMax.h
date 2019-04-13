#pragma once

#include "Node.h"
#include "Stack.h"

class StackWithMax {
    Node *head;
    int count;
    Stack maxElStack;

public:
    StackWithMax();

    void push(int data);

    void pop();

    int top();

    bool isEmpty();

    int getMax();

    ~StackWithMax();
};
