#pragma once

#include "Node.h"

class AVLTree {
    Node *root;

public:
    explicit AVLTree(int data);

    bool dfs(int data, Node *node);

    bool bfs(int data, Node *node);

    Node *find(int data, Node *node);

    void height(Node *node);

    int difference(Node *node);

    Node *turnRight(Node *node);

    Node *turnLeft(Node *node);

    Node *balance(Node *node);

    Node *insert(int data, Node *node);

    void deleteTree(Node *n);

    ~AVLTree();
};
