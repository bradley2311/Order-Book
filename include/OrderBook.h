#pragma once 

#include <map>
#include <unordered_map>

#include "../include/PriceLevel.h"
#include "../include/Trade.h"

class OrderBook {

   private:
    
   std::map <int, PriceLevel, std::greater<int>> bids;

   std::map <int,PriceLevel> asks;

   std::unordered_map<uint64_t, Order*> orderLookup;


   public:
    OrderBook();

    void addOrder( Order * order);

    void cancelOrder (uint64_t orderId);

    void match (Order * incomingOrder);

    void printBook () const;

};
