#include "../include/doubly_linked_list.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::pmr::memory_resource* memory_resource)
    : head(nullptr), tail(nullptr), size(0), allocator(memory_resource) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        allocator.deallocate(current, 1);
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = allocator.allocate(1);
    new (new_node) Node(value);
    if (!tail) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    ++size;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (!tail) return;

    Node* old_tail = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    allocator.deallocate(old_tail, 1);
    --size;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template class DoublyLinkedList<int>; 
