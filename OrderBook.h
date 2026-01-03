#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include "Order.h"
#include "Trade.h"

class OrderBook{
public:
    void print_order(Order order);
    void print_book();
    void process_order(Order order);
    void create_trade(uint64_t bidOrderID, uint64_t askOrderID, uint64_t amount, uint64_t price);
private:
    uint64_t tradeID{0};
    std::map<uint64_t, std::list<Order>, std::greater<uint64_t>> bids; //map to queues containing bids
    std::map<uint64_t, std::list<Order>> asks; //map to queues containing asks
    std::unordered_map<uint64_t, std::list<Order>::iterator> lookup_map; //map for quick deletion
    std::vector<Trade> trade_history; //vector for completed trades
};

#endif
