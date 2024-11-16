#include "include/memory_resource.h"
#include "include/doubly_linked_list.h"

int main() {
    constexpr size_t block_size = 64;
    constexpr size_t block_count = 10;

    FixedBlockMemoryResource memory_resource(block_size, block_count);

    DoublyLinkedList<int> list(&memory_resource);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::cout << "List content: ";
    list.print();

    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();

    return 0;
}
