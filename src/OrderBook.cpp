#include "../include/OrderBook.h"
#include <iostream>

OrderBook::OrderBook()
{
  
}

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
  auto it = orderLookup.find(orderId);

  if (it == orderLookup.end()){
    return;
  }

    Order* order = it->second;

    if (order->side == Side::BUY)
    {
        auto bidIt = bids.find(order->price);

        if (bidIt != bids.end())
        {
            PriceLevel & level = bidIt->second;

            level.removeOrder(order);

            if(level.empty()){
                bids.erase(bidIt);
            }

        }
    }
    else 
    {
        auto askIt = asks.find(order->price);

        if (askIt != asks.end())
        {
            PriceLevel& level = askIt->second;

            level.removeOrder(order);

            if (level.empty())
            {
                bids.erase(askIt);
            }
        }
    }
    orderLookup.erase(it);

    delete order;
}




void OrderBook::matchBuy(Order *incoming)
{
    while (incoming->quantity > 0 && !asks.empty())
    {
       auto bestAskIt = asks.begin();
       int askPrice = bestAskIt->first;
       PriceLevel & level = bestAskIt->second;

       
       if (askPrice > incoming->price){
        break;
       }
       
        while (incoming->quantity > 0 && !level.orders.empty())
        {
            Order* resting = level.orders.front();

            int tradeQty = std::min(incoming->quantity, resting->quantity);

            incoming->quantity -= tradeQty;
            resting->quantity -= tradeQty;

            std::cout << "TRADE BUY : "
                      << tradeQty
                      << " @ " << askPrice << std::endl;
            
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

        std::cout << "TRADE SELL: "
                  << tradeQty
                  << " @ " << bidPrice << std::endl;
            
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

    if (order->side == Side::BUY)
    {
        auto& book = bids;

        auto it = book.find(order->price);

        if (it == book.end())
        {
            PriceLevel level(order->price);
            level.addOrder(order);
            book.emplace(order->price, level);
        }
        else
        {
            it->second.addOrder(order);
        }
    }
    else
    {
        auto& book = asks;

        auto it = book.find(order->price);

        if (it == book.end())
        {
            PriceLevel level(order->price);
            level.addOrder(order);
            book.emplace(order->price, level);
        }
        else
        {
            it->second.addOrder(order);
        }
    }
    orderLookup[ order->orderID ] = order;
}


void OrderBook::printBook() const
{
   std::cout << "\nBOOK STATE:\n";

std::cout << "BIDS:\n";
for (auto& [price, level] : bids)
{
    std::cout << price << " -> " << level.orders.size() << "\n";
}

std::cout << "ASKS:\n";
for (auto& [price, level] : asks)
{
    std::cout << price << " -> " << level.orders.size() << "\n";
}

}

