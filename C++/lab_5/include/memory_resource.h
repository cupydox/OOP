#pragma once

#include <memory_resource>
#include <list>
#include <cstddef>
#include <stdexcept>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
private:
    std::byte* memory_pool;                
    std::size_t block_size;          
    std::size_t total_blocks;             
    std::list<std::byte*> free_blocks;   

    void* do_allocate(std::size_t bytes, std::size_t alignment) override;

    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

public:
    FixedBlockMemoryResource(std::size_t block_size, std::size_t block_count);

    ~FixedBlockMemoryResource();
};
