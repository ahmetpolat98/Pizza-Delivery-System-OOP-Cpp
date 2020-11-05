#include <iostream>
#include <string>
#include "order.h"

using namespace std;


Order::Order(string name, Pizza *piz, string *drink){
    customer = name;
    this->pizza_head = piz;
    this->next = NULL;
    this->drink = drink;
}

Order::Order(string name, Pizza *piz){
    customer = name;
    this->pizza_head = piz;
    this->next = NULL;
    this->drink = NULL;
    how_many_drink = 0;
}

Order::~Order(){
    //cout << "Order silindi" << endl; //
}

double Order::getPrice(){
    double total_price = 0;

    Pizza *iter = this->pizza_head;

    while (iter != NULL)
    {
        if (iter->size.compare("small") == 0){
            total_price += 15;
        }
        else if(iter->size.compare("medium") == 0){
            total_price += 20;
        }
        else if(iter->size.compare("big") == 0){
            total_price += 25;
        }
        iter = iter->next;
    }

    if(how_many_drink > 0){
        for(int i = 0; i < how_many_drink; i++){
            if(drink[i].compare("Cola") == 0){
                total_price += 4;  
            }
            else if(drink[i].compare("Soda") == 0){
                total_price += 2;  
            }
            else if(drink[i].compare("Ice tea") == 0){
                total_price += 3;  
            }
            else if(drink[i].compare("Fruit juice") == 0){
                total_price += 3.5;  
            }
        }
    }
    cout << customer << "'s order: "; //
    return total_price;   
}

void Order::printOrder(){

    Pizza *iter = this->pizza_head;

    cout << "-------------" << endl;
    cout << customer << "'s order" << endl << endl;

    while(iter != NULL){
        cout << iter->name << "(" ;
        for(int i = 0; i < iter->size_of_ingredients; i++){
            cout << iter->ingredients[i] << ", ";
        }
        cout << ")" << endl << "size: " << iter->size << ", crust: " << iter->crust_type << endl << endl;

        iter = iter->next;
    }

    if(how_many_drink > 0){
        for(int i = 0; i < how_many_drink; i++){
            cout << "1 " << drink[i] << ", ";
        }
        cout << endl << endl;
    }
    cout << "-------------" << endl;
}

void Order::setNumberDrink(int n){
    this->how_many_drink = n;
    
}