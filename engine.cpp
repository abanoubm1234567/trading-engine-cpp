#include "Order.h"
#include "OrderBook.h"
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

#define BID true
#define ASK false

int main(){

    OrderBook book;
    uint64_t id = 1;
    std::string input;
    while (true) {
        std::cout<<">";
        std::getline(std::cin,input);

        std::stringstream ss(input);

        char command;

        ss >> command;
        Order myOrder;

        switch (command) {
        case 'B':
            myOrder.type = BID;
            try {
                ss >> input;
                myOrder.amount = std::stoi(input);
                ss >> input ;
                myOrder.price = std::stoi(input);
                book.process_order(myOrder);
                myOrder.id = id++;
            } catch (...){
                std::cout<<"Error Occured"<<std::endl;
            }
            break;
        case 'A':
            myOrder.type = ASK;
            try {
                ss >> input;
                myOrder.amount = std::stoi(input);
                ss >> input ;
                myOrder.price = std::stoi(input);
                book.process_order(myOrder);
                myOrder.id = id++;
            } catch (...) { 
                std::cout<<"Error Occured"<<std::endl;
            }
            break;
        case 'Q':
            std::cout<<"Quitting..."<<std::endl;
            return 0;
        case 'P':
            book.print_book();
            break;
        default:
            std::cout<<"Unknown Command. Try again."<<std::endl;
        }

    }

    return 0;
}
