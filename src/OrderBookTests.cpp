#include <iostream>

#include "../include/MatchingEngine.h"
#include "../include/Order.h"
#include "../include/OrderIdGenerator.h"

int main()
{
    MatchingEngine engine;

engine.submitOrder(new Order(1, Side::BUY, 100, 10, 1));
engine.submitOrder(new Order(2, Side::BUY, 101, 10, 2));
engine.submitOrder(new Order(3, Side::BUY, 102, 10, 3));

engine.submitOrder(new Order(4, Side::SELL, 100, 5, 4));
engine.submitOrder(new Order(5, Side::SELL, 101, 10, 5));
engine.submitOrder(new Order(6, Side::SELL, 102, 15, 6));


std::cout << "DONE\n";

    return 0;
}