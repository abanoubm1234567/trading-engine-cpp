#include "OrderBook.h"
#include "Trade.h"
#include <cstdint>
#include <iostream>

void OrderBook::print_order(Order order){
    std::cout<<"Order ID: "<<order.id<<"\tAmount: "<<order.amount
        <<"\tPrice: "<<order.price<<std::endl;
}

void OrderBook::print_book(){
  uint64_t i{1}; //variable for printing order number (list number)
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

void OrderBook::process_order(Order order){
    //check if there is a match, and then create a trade if there is
    if (order.type){ //is a BID
        if (!asks.empty() && asks.begin()->first <= order.price) { //match for a BID found
            Order matchingOrder = asks.begin()->second.front();
            //three scenarios can occur here: there are equal quantities in the bid and ask orders, or bid has higher or ask has higher
            if (order.amount < matchingOrder.amount){ //the amount from the incoming order is less than currently in book
              OrderBook::create_trade(order.id, matchingOrder.id, order.amount, matchingOrder.price);
              matchingOrder.amount = matchingOrder.amount - order.amount;
              return;
            }
            else if (order.amount > matchingOrder.amount) { //amount in book is less than the incoming order
              OrderBook::create_trade(order.id, matchingOrder.id, matchingOrder.amount, matchingOrder.price);
              order.amount = order.amount - matchingOrder.amount;

            }
            else {
            
            }
        }
    }
    else { //is an ASK
    
    }
    //no match, order is placed into the order book to be matched at a later time
    if (order.type){ //is a BID
        bids[order.price].push_back(order);
    }
    else { // is an ASK
        asks[order.price].push_back(order);
    }
}

void OrderBook::create_trade( uint64_t bidOrderID, uint64_t askOrderID, uint64_t amount, uint64_t price){

  Trade newTrade = {++OrderBook::tradeID, bidOrderID, askOrderID, amount, price};
  OrderBook::trade_history.push_back(newTrade);

}
