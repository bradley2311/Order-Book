#include "../include/Trade.h"

Trade::Trade (
   uint64_t buyId,
   uint64_t sellId,
   int p, 
   int q
)
:
   buyOrderId(buyId),
   sellOrderId(sellId),
   price(p),
   quantity(q)
{
}


