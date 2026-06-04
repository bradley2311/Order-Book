#pragma once

#include <cstdint>
#include "OrderType.h"

class Order {

public:
    uint64_t orderID;
    Side side;
    int price;
    int quantity;

    uint64_t timestamp;

    Order(
    uint64_t id,
    Side side,
    int price,
    int quantity,
    uint64_t timestamp
);

};





