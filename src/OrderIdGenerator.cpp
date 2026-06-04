#include "../include/OrderIdGenerator.h"
#include "OrderIdGenerator.h"

std::atomic<uint64_t>
OrderIdGenerator::currentId {1};


uint64_t OrderIdGenerator::next()
{
    return currentId++;
}