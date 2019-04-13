#pragma once

struct Node {
    explicit Node(float const data, Node *const prev, Node *const next);

    Node *copy() const;

    float data;
    Node *prev;
    Node *next;
};
