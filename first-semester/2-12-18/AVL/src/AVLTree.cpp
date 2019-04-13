#include "AVLTree.h"

#include <queue>

AVLTree::AVLTree(int data) {
    root = new Node;
    root->data = data;
    root->right = nullptr;
    root->left = nullptr;
    root->height = 1;
}

bool AVLTree::dfs(int data, Node *node) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == data) {
        return true;
    }
    if (dfs(data, node->left)) {
        return true;
    }
    return dfs(data, node->right);
}

bool AVLTree::bfs(int data, Node *node) {
    std::queue<Node *> A;
    A.push(root);
    while (!A.empty()) {
        Node *temp = A.back();
        A.pop();
        if (temp->data == data) {
            return true;
        }
        if (node->left != nullptr) {
            A.push(temp->left);
        }
        if (node->right != nullptr) {
            A.push(temp->right);
        }
    }
    return false;
}

Node *AVLTree::find(int data, Node *node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->data == data) {
        return node;
    }
    if (node->data > data) {
        return find(data, node->left);
    }
    if (node->data < data) {
        return find(data, node->right);
    }
}

void AVLTree::height(Node *node) {
    int hLeft;
    int hRight;
    if (node->left != nullptr) {
        hLeft = node->left->height;
    } else {
        hLeft = 0;
    }
    if (node->right != nullptr) {
        hRight = node->right->height;
    } else {
        hRight = 0;
    }
    if (hLeft < hRight) {
        node->height = hRight + 1;
    } else {
        node->height = hLeft + 1;
    }
}

int AVLTree::difference(Node *node) {
    if (node != nullptr) {
        return node->right->height - node->left->height;
    } else {
        return 0;
    }
}

Node *AVLTree::turnRight(Node *node) {
    Node *p = node->right;
    node->right = p->left;
    p->left = node;
    height(node);
    height(p);
    return p;
}

Node *AVLTree::turnLeft(Node *node) {
    Node *p = node->left;
    node->left = p->right;
    p->right = node;
    height(node);
    height(p);
    return p;
}

Node *AVLTree::balance(Node *node) {
    height(node);
    if (difference(node) == 2) {
        if (difference(node->right) < 0) {
            node->right = turnLeft(node->right);
        }
        return turnRight(node);
    }
    if (difference(node) == -2) {
        if (difference(node->left) > 0) {
            node->left = turnRight(node->left);
        }
        return turnLeft(node);
    }
    return node;
}

Node *AVLTree::insert(int data, Node *node) {
    if (node == nullptr) {
        node = new Node;
        node->data = data;
        node->right = nullptr;
        node->left = nullptr;
        node->height = 1;
    } else {
        if (data > node->data) {
            if (node->right != nullptr) {
                node->right = insert(data, node->right);
            } else {
                node->right = new Node;
                node->right->data = data;
                node->right->right = nullptr;
                node->right->left = nullptr;
            }
        } else {
            if (node->left != nullptr) {
                node->left = insert(data, node->left);
            } else {
                node->left = new Node;
                node->left->data = data;
                node->left->right = nullptr;
                node->left->left = nullptr;
            }
        }
    }
    return balance(node);
}

void AVLTree::deleteTree(Node *n) {
    if (n == nullptr) {
        return;
    }
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
}

AVLTree::~AVLTree() {
    deleteTree(root);
}
