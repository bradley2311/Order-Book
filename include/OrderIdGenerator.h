#pragma once

#include <atomic>
#include <cstdint>

class OrderIdGenerator {

    private:
        static std::atomic<uint64_t> currentId;
    public:
        static uint64_t next();
};