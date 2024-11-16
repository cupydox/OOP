#include "../include/memory_resource.h"
#include <cassert>

FixedBlockMemoryResource::FixedBlockMemoryResource(std::size_t block_size, std::size_t block_count)
    : block_size(block_size), total_blocks(block_count) {
    memory_pool = new std::byte[block_size * block_count];
    for (std::size_t i = 0; i < block_count; ++i) {
        free_blocks.push_back(memory_pool + i * block_size);
    }
}

FixedBlockMemoryResource::~FixedBlockMemoryResource() {
    delete[] memory_pool;
}

void* FixedBlockMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (bytes > block_size || free_blocks.empty()) {
        throw std::bad_alloc();
    }
    void* block = free_blocks.front();
    free_blocks.pop_front();
    return block;
}

void FixedBlockMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    assert(p >= memory_pool && p < memory_pool + block_size * total_blocks);
    free_blocks.push_back(static_cast<std::byte*>(p));
}

bool FixedBlockMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
