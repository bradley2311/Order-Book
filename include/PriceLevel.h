#pragma once

#include <list>
#include "Order.h"
#include <memory>

class PriceLevel
{   
public:
    int price;

    std::list<std::unique_ptr<Order>> orders;

    explicit PriceLevel(int price);

    void addOrder(std::unique_ptr<Order> order);

    void removeOrder(uint64_t orderId);

    bool empty () const;

};
