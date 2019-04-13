#pragma once

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    int height;
};
