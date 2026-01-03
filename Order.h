#ifndef ORDER_H
#define ORDER_H

#include <cstdint>
struct Order{
    uint64_t id{};
    uint64_t price{};
    uint64_t amount{};
    bool type;
};

#endif
