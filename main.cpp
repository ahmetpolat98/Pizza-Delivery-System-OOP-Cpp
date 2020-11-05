#include <iostream>
#include <string>

#include "pizza.h"
#include "order.h"
#include "orderlist.h"

using namespace std;


int main(){

    int select;
    Orderlist main;

    while (select != 4)
    {
        cout << "Welcome to Polat Pizza" << endl;
        cout << "1. Add an order" << endl;
        cout << "2. List orders" << endl;
        cout << "3. Deliver order" << endl;
        cout << "4. Exit" << endl;

        cin >> select;

        if (select == 1)
        {
            main.takeOrder();
        }
        else if (select == 2)
        {
            main.listOrders();
        }
        else if (select == 3)
        {
            main.deliverOrders();
        }     
    }
    cout << "Goodbye...";
    
    return 0;
}