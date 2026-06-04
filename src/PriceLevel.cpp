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
     for( auto it = orders.begin(); it != orders.end(); ++it)
  {
        if (*it == order)
        {
            orders.erase(it);
            return;
        }
  }
}

bool PriceLevel::empty() const
{
    return orders.empty();
}
