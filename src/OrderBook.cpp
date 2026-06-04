#include "../include/OrderBook.h"
#include <iostream>

void OrderBook::addOrder(Order *order) 
{
    if (order->side == Side::BUY){
        matchBuy(order);
    }else 
    {
        matchSell(order);
    }
}


void OrderBook::cancelOrder(uint64_t orderId)
{
}


void OrderBook::matchBuy(Order *incoming)
{
    while (incoming->quantity > 0 && !asks.empty())
    {
       auto bestAskIt = asks.begin();
       int askPrice = bestAskIt->first;
       PriceLevel & level = bestAskIt->second;

       
       if (askPrice > incoming->price)
        break;
       
        while (incoming->quantity > 0 && !level.orders.empty())
        {
            Order* resting = level.orders.front();

            int tradeQty = std::min(incoming->quantity, resting->quantity);

            incoming->quantity -= tradeQty;
            resting->quantity -= tradeQty;

            std::cout << "TRADE SELL: "
                      << tradeQty
                      << "@ " << askPrice << std::endl;
            
            if (resting->quantity == 0){
                orderLookup.erase(resting->orderID);
                level.orders.pop_front();
                delete resting;
            }            
        }

        if (level.orders.empty()){
            asks.erase(bestAskIt);
        } 
    }

    if (incoming-> quantity > 0){

        insertOrder(incoming);
    }  

}


void OrderBook::matchSell(Order *incoming)
{
    while (incoming->quantity > 0 && !bids.empty()){

        auto bestBidIt = bids.begin();
        int bidPrice = bestBidIt->first;
        PriceLevel& level = bestBidIt->second;

        if (bidPrice > incoming->price)
            break;

    while (incoming-> quantity > 0 && !level.orders.empty())
    {
        Order* resting = level.orders.front();

        int tradeQty = std::min(incoming->quantity, resting->quantity);

        incoming->quantity -= tradeQty;
        resting->quantity -= tradeQty;

        std::cout << "TRADE SELL:"
                  << tradeQty
                  << "@ " << bidPrice << std::endl;
            
        if (resting->quantity ==0){
            orderLookup.erase(resting->quantity);
            level.orders.pop_front();
            delete resting;
        }  
    }

     if (level.orders.empty())
        {
        bids.erase(bestBidIt); 
        }
  
}
    if (incoming->quantity > 0)
    {
        insertOrder(incoming);
    }

}

void OrderBook::insertOrder(Order *order)
{
}

void OrderBook::printBook() const
{
}

