#include "../include/MatchingEngine.h"

MatchingEngine::MatchingEngine()
{
}

void MatchingEngine::submitOrder(Order *order)
{
    orderbook.addOrder(order);
}

void MatchingEngine::cancelOrder(uint64_t orderId)
{
    orderbook.cancelOrder(orderId);
}


