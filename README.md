````md
# Low Latency Order Book Engine

A high-performance electronic trading order book and matching engine written in modern C++.

This project is designed to simulate the core components of a financial exchange matching engine, with a focus on:
- low latency
- efficient memory usage
- cache-friendly data structures
- deterministic execution
- scalable architecture

The engine supports:
- limit orders
- market orders
- FIFO matching
- order cancellation
- partial fills
- bid/ask price levels
- trade generation

---

# Features

## Implemented / Planned Features

### Core Engine
- Limit order support
- Market order support
- FIFO (price-time priority)
- Bid and ask books
- Partial order fills
- Full order fills
- Trade execution generation
- Fast order lookup
- Order cancellation

### Performance-Oriented Design
- Integer-based pricing
- O(1) order lookup
- O(log N) price insertion
- Minimal object copying
- Pointer-based order storage
- Separation of matching logic and storage

### Future Low-Latency Optimizations
- Memory pools
- Custom allocators
- Lock-free queues
- Intrusive linked lists
- Cache-aware containers
- Multi-threaded gateways
- NUMA-aware architecture

---

# What Is an Order Book?

An order book is the core data structure used by electronic exchanges to track buy and sell orders for a financial instrument.

The system maintains:
- **Bids** → buy orders
- **Asks** → sell orders

Orders are matched using:
1. **Price Priority**
2. **Time Priority (FIFO)**

Example:

```text
BIDS                  ASKS
------------------------------
101 x 50              102 x 25
100 x 80              103 x 60
99  x 20              104 x 10
```

If a new buy order enters at price `102`, it matches the best ask immediately.

---

# Architecture

## High-Level Design

```text
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
```

---

# Project Structure

```text
OrderBookProject/
│
├── include/
│   ├── Order.h
│   ├── OrderTypes.h
│   ├── PriceLevel.h
│   ├── OrderBook.h
│   ├── MatchingEngine.h
│   ├── Trade.h
│   ├── OrderIdGenerator.h
│   ├── MemoryPool.h
│   └── Utils.h
│
├── src/
│   ├── Order.cpp
│   ├── PriceLevel.cpp
│   ├── OrderBook.cpp
│   ├── MatchingEngine.cpp
│   ├── Trade.cpp
│   ├── OrderIdGenerator.cpp
│   ├── MemoryPool.cpp
│   └── main.cpp
│
├── tests/
│   └── OrderBookTests.cpp
│
├── CMakeLists.txt
│
└── README.md
```

---

# Core Components

## Order

Represents a single market instruction.

Fields:
- order ID
- side (buy/sell)
- price
- quantity
- timestamp

---

## Price Level

Represents all orders resting at a specific price.

Example:

```text
100 -> [Order1][Order2][Order3]
```

Orders are stored FIFO.

---

## Order Book

Maintains:
- bid side
- ask side
- order lookup table
- matching logic

---

## Matching Engine

Responsible for:
- receiving orders
- validating orders
- routing to the order book
- triggering execution

---

# Matching Logic

The engine follows standard exchange rules:

## Buy Orders
- Match against lowest ask first

## Sell Orders
- Match against highest bid first

## FIFO Priority
Orders at the same price execute in arrival order.

---

# Data Structures

| Component | Structure |
|---|---|
| Bid Book | `std::map<int, PriceLevel, std::greater<int>>` |
| Ask Book | `std::map<int, PriceLevel>` |
| Order Queue | `std::list<Order*>` |
| Order Lookup | `std::unordered_map<uint64_t, Order*>` |

---

# Complexity Goals

| Operation | Complexity |
|---|---|
| Add Order | O(log N) |
| Cancel Order | O(1) |
| Best Bid/Ask | O(1) |
| Match Execution | O(1) per fill |

---

# Why Integer Pricing?

Floating-point arithmetic can introduce:
- rounding errors
- inconsistent comparisons
- slower execution

Instead of:

```text
101.25
```

the engine stores:

```text
10125
```

(cents or ticks)

---

# Build Instructions

## Requirements

- C++17 or newer
- CMake 3.15+
- GCC / Clang / MSVC

---

# Build Using CMake

## Linux / macOS

```bash
mkdir build
cd build

cmake ..
make
```

Run:

```bash
./OrderBookProject
```

---

## Windows (Visual Studio)

```bash
mkdir build
cd build

cmake ..
```

Open generated `.sln` file in Visual Studio.

---

# Example Usage

```cpp
MatchingEngine engine;

auto* order = new Order(
    OrderIdGenerator::next(),
    Side::BUY,
    100,
    50,
    1
);

engine.submitOrder(order);
```

---

# Example Trade Flow

## Existing Book

```text
ASKS
100 x 25
101 x 30
```

## Incoming Order

```text
BUY 40 @ 101
```

## Result

```text
Trade 25 @ 100
Trade 15 @ 101
```

Remaining ask:

```text
101 x 15
```

---

# Performance Goals

This project is intended as a foundation for studying:
- exchange systems
- high-frequency trading infrastructure
- low-latency C++
- memory-efficient data structures

Target future optimizations:
- microsecond latency
- lock-free communication
- preallocated memory
- branch prediction optimization
- cache-line alignment

---

# Future Enhancements

## Matching Features
- Stop orders
- Iceberg orders
- Hidden liquidity
- Auction matching
- Multi-symbol support

## Networking
- TCP gateway
- UDP multicast market data
- FIX protocol support
- Binary exchange protocols

## Reliability
- Snapshot recovery
- Event journaling
- Persistence
- Replay engine

## Performance
- Custom allocators
- Lock-free ring buffers
- NUMA optimization
- Kernel bypass networking

---

# Educational Goals

This project is ideal for learning:
- modern C++
- systems programming
- financial exchange architecture
- memory management
- performance engineering
- concurrent systems design

---

# References and Learning Resources

## Exchange Architecture
- NASDAQ Trading Technology  
  https://www.nasdaq.com/solutions/trading-technology

- CME Globex Overview  
  https://www.cmegroup.com/trading/globex.html

## FIX Protocol
- FIX Trading Community  
  https://www.fixtrading.org/

## Low-Latency Systems
- Intel Low Latency Tuning Guide  
  https://www.intel.com/content/www/us/en/developer/articles/technical/low-latency-optimization.html

## C++ Performance
- CppReference  
  https://en.cppreference.com/

---

# License

This project is intended for:
- educational use
- systems programming practice
- exchange simulation research

Modify and use freely for learning purposes.
````
