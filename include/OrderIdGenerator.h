#pragma once

#include <atomic>
#include <cstdint>

class OrderIdGenerator {

    public:
        static std::atomic<uint64_t> currentId;

    private:
        static uint64_t next();
};