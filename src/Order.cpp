#include "../include/Order.h"

// order implementation
Order::Order (
    uint64_t id,
    Side s,
    int p,
    int q,
    uint64_t ts
)
    :orderID(id),
    side(s),
    price(p),
    quantity(q),
    timestamp(ts)
{
}
