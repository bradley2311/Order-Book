#pragma once

#include <cstdint> 

class Trade {

    public:
        uint64_t buyOrderId;
        uint64_t sellOrderId;

        int price;
        int quantity;

    Trade(
        uint64_t buyId,
        uint64_t sellId,
        int price,
        int quantity
    );
};