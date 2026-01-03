#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <cstdint>
#include <deque>
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

private:
    std::map<std::uint64_t, std::list<Order>> bids; //map to queues containing bids
    std::map<std::uint64_t, std::list<Order>> asks; //map to queues containing asks
    std::unordered_map<std::uint64_t, std::list<Order>::iterator> lookup_map;
public:

    void print_order(Order order){
        std::cout<<"Order ID: "<<order.id<<"\tAmount: "<<order.amount
            <<"\tPrice: "<<order.price<<std::endl;
    }

    void print_book(){
      uint64_t i = 1; //variable for printing order number (list number)
      std::cout<<"======Current Orders======\nAsks:\n";
      if (asks.empty()) std::cout<<"No asks\n";
      for(const auto& item: asks){
          for(Order currentOrder: item.second){
            std::cout<<(i++)<<". ";
            print_order(currentOrder);
          }
      }
      std::cout<<"\nBids:\n";
      if (bids.empty()) std::cout<<"No bids\n";
      i = 1;
      for(const auto& item: bids){
          for(Order currentOrder: item.second){
            std::cout<<(i++)<<". ";
            print_order(currentOrder);
          }
      }
      std::cout<<"=========================="<<std::endl;
    }

    void process_order(Order order){
        //check if there is a match, and then create a trade if there is
        
        //no match, order is placed into the order book to be matched at a later time
        if (order.type){
            bids[order.price].push_back(order);
        }
        else {
            asks[order.price].push_back(order);
        }
    }
};

#endif
