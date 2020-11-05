#ifndef order
#define order

#include <iostream>
#include <string>
#include "pizza.h"
using namespace std;

class Order{
    friend class Orderlist;
    private:
        string customer;
        Pizza *pizza_head;
        string *drink;
        int how_many_drink;
        Order *next;

    public:
        Order(string, Pizza *, string *);
        Order(string, Pizza *);
        ~Order();
        double getPrice();
        void printOrder();

        void setNumberDrink(int);
        
};


#endif