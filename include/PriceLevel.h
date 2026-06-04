#pragma once

#include <list>
#include "Order.h"

class PriceLevel
{   
public:
    int price;

    std::list <Order*> orders;

    explicit PriceLevel(int price);

    void addOrder(Order *order);

    void removeOrder(Order *order);

    bool empty () const;

};
