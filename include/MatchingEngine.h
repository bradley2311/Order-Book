#pragma once

#include "../include/OrderBook.h"


class  MatchingEngine {

    private:
        OrderBook orderbook;
    
    public:
        MatchingEngine();
        
        void submitOrder (Order * order);

        void cancelOrder (uint64_t orderId);

};