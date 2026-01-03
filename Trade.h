#ifndef TRADE_H
#define TRADE_H

#include <cstdint>
struct Trade{
    uint64_t tradeID;
    uint64_t sellID;
    uint64_t askID;
    uint64_t amount;
    uint64_t price;
};

#endif
