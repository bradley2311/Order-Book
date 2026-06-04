Low Latency Order Book Engine

A high-performance electronic trading order book and matching engine written in modern C++.

This project is designed to simulate the core components of a financial exchange matching engine, with a focus on:

low latency
efficient memory usage
cache-friendly data structures
deterministic execution
scalable architecture

The engine supports:

limit orders
market orders
FIFO matching
order cancellation
partial fills
bid/ask price levels
trade generation

Features
Implemented / Planned Features
Core Engine
Limit order support
Market order support
FIFO (price-time priority)
Bid and ask books
Partial order fills
Full order fills
Trade execution generation
Fast order lookup
Order cancellation
Performance-Oriented Design
Integer-based pricing
O(1) order lookup
O(log N) price insertion
Minimal object copying
Pointer-based order storage
Separation of matching logic and storage
Future Low-Latency Optimizations
Memory pools
Custom allocators
Lock-free queues
Intrusive linked lists
Cache-aware containers
Multi-threaded gateways
NUMA-aware architecture

OrderBook Example:

BIDS                  ASKS
------------------------------
101 x 50              102 x 25
100 x 80              103 x 60
99  x 20              104 x 10

Architecture: 

Client Orders
      ↓
Matching Engine
      ↓
Order Book
 ┌──────────────┐
 │ Bid Book     │
 │ Ask Book     │
 └──────────────┘
      ↓
Trade Generation
