#include "../include/PriceLevel.h"

PriceLevel::PriceLevel(int price) : price(price)
{
}

void PriceLevel::addOrder(std::unique_ptr<Order> order)
{
    orders.push_back(std::move(order));
}

void PriceLevel::removeOrder(uint64_t orderId)
{
    for (auto it = orders.begin(); it != orders.end(); ++it)
    {
        if ((*it)->orderID == orderId)
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
