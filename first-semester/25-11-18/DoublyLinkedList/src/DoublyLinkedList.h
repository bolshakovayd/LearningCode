#pragma once

#include "Node.h"

#include <iostream>

class DoublyLinkedList {
public:
    explicit DoublyLinkedList(unsigned initial_size = 0, float initial_value = 0.0);

    DoublyLinkedList(DoublyLinkedList const &other);

    DoublyLinkedList &operator=(DoublyLinkedList const &other);

    ~DoublyLinkedList();

    unsigned size() const;

    bool empty() const;

    void clear();

    void push_back(float val);

    void push_front(float val);

    // first element of list
    float front() const;

    // last element of list
    float back() const;

    float get(unsigned const idx) const;

    float operator[](unsigned const idx) const;

    void insert_after(unsigned idx, float val);

    void insert_before(unsigned idx, float val);

    void set(unsigned idx, float val);

    void remove(unsigned idx);

private:
    Node *const get_node(unsigned idx) const;

    friend void swap(DoublyLinkedList &l, DoublyLinkedList &r);

    // print full list separated by a space using std::cout
    friend void print_doubly_linked_list(DoublyLinkedList const &l);

    Node *head;
    Node *tail;
    unsigned _size;
};
