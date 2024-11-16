#include <gtest/gtest.h>
#include "../include/memory_resource.h"
#include "../include/doubly_linked_list.h"

TEST(DoublyLinkedList, PushBack) {
    FixedBlockMemoryResource memory_resource(64, 10);
    DoublyLinkedList<int> list(&memory_resource);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    ASSERT_EQ(list.get_size(), 3);
}

TEST(DoublyLinkedList, PopBack) {
    FixedBlockMemoryResource memory_resource(64, 10);
    DoublyLinkedList<int> list(&memory_resource);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_back();

    ASSERT_EQ(list.get_size(), 2);
}

TEST(DoublyLinkedList, SizeAfterMultiplePushes) {
    FixedBlockMemoryResource memory_resource(64, 10);
    DoublyLinkedList<int> list(&memory_resource);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    ASSERT_EQ(list.get_size(), 5); 
}

TEST(DoublyLinkedList, SizeAfterPushPopAlternation) {
    FixedBlockMemoryResource memory_resource(64, 10);
    DoublyLinkedList<int> list(&memory_resource);

    list.push_back(100);
    list.pop_back();
    list.push_back(200);
    list.push_back(300);
    list.pop_back();

    ASSERT_EQ(list.get_size(), 1); 
}

TEST(DoublyLinkedList, SizeAfterPushPop) {
    FixedBlockMemoryResource memory_resource(64, 10);
    DoublyLinkedList<int> list(&memory_resource);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_back();
    list.pop_back();
    list.push_back(40);

    ASSERT_EQ(list.get_size(), 2);
}
