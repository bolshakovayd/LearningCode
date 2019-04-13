#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(unsigned int initial_size, float initial_value)
        : head(nullptr), tail(nullptr), _size(initial_size) {
    if (initial_size != 0) {
        head = new Node(initial_value, nullptr, nullptr);
    }
    auto *current = head;
    for (int i = 1; i < initial_size; ++i) {
        auto *const temp = current;
        current = new Node(initial_value, temp, nullptr);
        temp->next = current;
    }
    tail = current;
}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList const &other) {
    _size = other._size;
    Node const *temp = nullptr;
    if (other.head != nullptr) {
        head = new Node(other.head->data, nullptr, nullptr);
        temp = other.head->next;
    }

    auto *current = head;
    while (temp != nullptr) {
        auto *const node = new Node(temp->data, head, nullptr);
        current->next = node;
        current = node;
        temp = temp->next;
    }
    tail = current;
}

DoublyLinkedList &DoublyLinkedList::operator=(DoublyLinkedList const &other) {
    auto temp(other);
    swap(*this, temp);
    return *this;
}

void DoublyLinkedList::clear() {
    while (head != nullptr) {
        auto *const temp = head->next;
        delete head;
        head = temp;
    }
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}


unsigned DoublyLinkedList::size() const {
    return _size;
}

bool DoublyLinkedList::empty() const {
    return _size == 0;
}

void DoublyLinkedList::push_back(float val) {
    if (tail == nullptr) {
        tail = new Node(val, nullptr, nullptr);
        head = tail;
    } else {
        auto *const node = new Node(val, tail, nullptr);
        tail->next = node;
        tail = node;
    }
    ++_size;
}

void DoublyLinkedList::push_front(float val) {
    if (head == nullptr) {
        head = new Node(val, nullptr, nullptr);
        tail = head;
    } else {
        auto *const node = new Node(val, nullptr, head);
        head->prev = node;
        head = node;
    }
    ++_size;
}

float DoublyLinkedList::front() const {
    if (empty()) {
        std::cout << "DoublyLinkedList subscript out of range" << std::endl;
        return -1;
    }
    return head->data;
}

float DoublyLinkedList::back() const {
    if (empty()) {
        std::cout << "DoublyLinkedList subscript out of range" << std::endl;
        return -1;
    }
    return tail->data;
}

float DoublyLinkedList::get(unsigned const idx) const {

    if (idx >= _size || idx < 0) {
        std::cout << "DoublyLinkedList subscript out of range" << std::endl;
        return -1;
    }
    return get_node(idx)->data;
}

float DoublyLinkedList::operator[](unsigned const idx) const {
    return get(idx);
}

void DoublyLinkedList::insert_after(unsigned idx, float val) {
    if (idx >= _size || idx < 0) {
        std::cout << "DoublyLinkedList subscript out of range" << std::endl;
        return;
    }
    auto *const temp = get_node(idx);
    if (temp == nullptr) {
        return;
    }
    auto *const node = new Node(val, temp, temp->next);
    if (temp->next != nullptr) {
        temp->next->prev = node;
    }
    temp->next = node;
    ++_size;
}

void DoublyLinkedList::insert_before(unsigned idx, float val) {
    if (idx >= _size || idx < 0) {
        std::cout << "DoublyLinkedList subscript out of range" << std::endl;
        return;
    }
    auto *const temp = get_node(idx);
    if (temp == nullptr) {
        return;
    }
    auto *const node = new Node(val, temp->prev, temp);
    if (temp->prev != nullptr) {
        temp->prev->next = node;
    }
    temp->prev = node;
    ++_size;
}

void DoublyLinkedList::set(unsigned idx, float val) {
    if (idx >= _size || idx < 0) {
        std::cout << "DoublyLinkedList subscript out of range" << std::endl;
        return;
    }
    auto *const node = get_node(idx);
    node->data = val;
}

void DoublyLinkedList::remove(unsigned idx) {
    if (idx >= _size || idx < 0) {
        std::cout << "DoublyLinkedList subscript out of range" << std::endl;
        return;
    }
    auto *const temp = get_node(idx);
    if (temp != nullptr) {
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        --_size;

        if (idx == 0) {
            head = nullptr;
            tail = nullptr;
        }
    }
}

Node *const DoublyLinkedList::get_node(unsigned idx) const {
    if (idx <= _size / 2) {
        auto *temp = head;
        for (int i = 0; i < idx; ++i) {
            temp = temp->next;
        }
        return temp;
    } else {
        auto *temp = tail;
        for (int i = 0; i < _size - idx - 1; ++i) {
            temp = temp->prev;
        }
        return temp;
    }
}

void swap(DoublyLinkedList &l, DoublyLinkedList &r) {
    std::swap(l.head, r.head);
    std::swap(l.tail, r.tail);
    std::swap(l._size, r._size);
}

void print_doubly_linked_list(DoublyLinkedList const &l) {
    auto const *temp = l.head;
    if (temp == nullptr) {
        std::cout << "List is empty";
    }
    while (temp != nullptr) {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << std::endl;
}
