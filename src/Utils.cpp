#include "../include/Utils.h"

#include <iostream>
#include <chrono>

uint64_t Utils::getCurrentTimestamp()
{

    auto now = std::chrono::system_clock::now();

    auto duration = now.time_since_epoch();

     auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

     return milliseconds;
    
}