cmake_minimum_required(VERSION 3.15)

project(OrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra")

include_directories(include)

add_executable(OrderBook

    src/OrderBookTests.cpp
    src/Order.cpp
    src/PriceLevel.cpp
    src/OrderBook.cpp
    src/MatchingEngine.cpp
    src/Trade.cpp
    src/OrderIdGenerator.cpp
)