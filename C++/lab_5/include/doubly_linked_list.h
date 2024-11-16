#pragma once

#include <memory_resource>
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;
    std::pmr::polymorphic_allocator<Node> allocator;

public:
    DoublyLinkedList(std::pmr::memory_resource* memory_resource = std::pmr::get_default_resource());
    ~DoublyLinkedList();

    void push_back(const T& value);
    void pop_back();
    void print() const;

    size_t get_size() const { return size; }

    
};

class Iterator {
    private:
        Node* current; 

    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() { return current->data; }
        T* operator->() { return &current->data; }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            current = current->next;
            return temp;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    size_t get_size() const { return size; }


