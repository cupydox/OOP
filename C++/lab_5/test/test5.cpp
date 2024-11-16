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

TEST(DoublyLinkedList, PrintList) {
    FixedBlockMemoryResource memory_resource(64, 10);
    DoublyLinkedList<int> list(&memory_resource);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    std::ostringstream oss;
    list.print();
    ASSERT_EQ(oss.str(), "10 20 30\n");
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
