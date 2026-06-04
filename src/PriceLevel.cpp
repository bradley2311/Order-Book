#include "../include/PriceLevel.h"

PriceLevel::PriceLevel(int price) : price(price)
{
}

void PriceLevel::addOrder(Order *order)
{
    orders.push_back(order);
}

void PriceLevel::removeOrder(Order *order)
{
    orders.remove(order);
}

bool PriceLevel::empty() const
{
    return orders.empty();
}
