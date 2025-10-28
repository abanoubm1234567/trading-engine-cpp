#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <iostream>
#include <vector>
#include "Order.h"

class OrderBook{

private:
    std::vector<Order> bids;
    std::vector<Order> asks;
public:

    void print_order(Order order){
        std::cout<<"Order ID: "<<order.id<<"\tAmount: "<<order.amount
            <<"\tPrice: "<<order.price<<"\tType: "
            <<(order.type ? "Bid" : "Ask")<<std::endl;
    }

    void print_book(){
      std::cout<<"\nAsks:\n";
      for(int i = 0; i<asks.size(); i++){
          std::cout<<(i+1)<<". ";
          print_order(asks[i]);
      }
      std::cout<<"\n\nBids:\n";
      for(int i = 0; i<bids.size(); i++){
          std::cout<<(i+1)<<". ";
          print_order(bids[i]);
      }
    }

    void process_order(Order order){
        if (order.type){
            bids.push_back(order);
        }
        else {
            asks.push_back(order);
        }
    }
};

#endif
