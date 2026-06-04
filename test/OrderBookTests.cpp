#include <iostream>

#include "../include/MatchingEngine.h"
#include "../include/Order.h"
#include "../include/OrderIdGenerator.h"

int main() {

    MatchingEngine engine;

    auto* order1 = new Order(
        OrderIdGenerator::next(),
        Side::BUY,
        100,
        50,
        1
    );

    engine.submitOrder(order1);

    return 0;
}