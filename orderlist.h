#ifndef orderlist
#define orderlist

#include <iostream>
#include <string>
#include "order.h"

using namespace std;

class Orderlist{

    private:
        int number_of_orders;
        Order *head;
    
    public:
        Orderlist();
        ~Orderlist();
        void takeOrder();
        void listOrders();
        void deliverOrders();
        
};



#endif