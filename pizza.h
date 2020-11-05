#ifndef pizza
#define pizza

#include <iostream>
#include <string>

using namespace std;

class Pizza{
    friend class Order;
    friend class Orderlist;

    private:
        string name;
        string size;
        string crust_type;
        string *ingredients;

        int size_of_ingredients;

        Pizza *next;
    
    public:
        Pizza();
        Pizza(string, string, int);
        Pizza(Pizza &);
        ~Pizza();
        void showPizza();
        void nextEkle();

};

#endif