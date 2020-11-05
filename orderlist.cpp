#include <iostream>
#include <string>
#include "orderlist.h"
#include "pizza.h"

using namespace std;


Orderlist::Orderlist(){
    number_of_orders = 0;
    head = NULL;
}

Orderlist::~Orderlist(){
    //cout << "orderlist silindi" << endl ; //
}

void Orderlist::takeOrder(){

    string customer_name, pizza_size, pizza_crust_type, *temp_drink = NULL, *iter_drink;
    int pizza_menu, amount_pizza, selected_drink, amount_of_drink;

    cout << "Please enter your name" << endl;
    cin >> customer_name;

    cout << "Pizza Menu" << endl;
    cout << "1. Chicken Pizza (mozarella, chicken, mushroom, corn, olive, onion, tomato)" << endl;
    cout << "2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)" << endl;
    cout << "3. Sausage Pizza (mozarella, sausage, tomato, , olive, mushroom, corn)" << endl;
    cin >> pizza_menu;

    cout << "Select size: small (15 TL), medium (20 TL), big (25 TL) " << endl;
    cin >> pizza_size;

    cout << "Select crust type: thin, normal, thick" << endl;
    cin >> pizza_crust_type;

    cout << "Enter the amount: " << endl;
    cin >> amount_pizza;

    Pizza temp_pizza(pizza_size, pizza_crust_type, pizza_menu);

    Pizza *temp_head = new Pizza(temp_pizza);

    Pizza *iter = temp_head;

    for(int i = 0; i < (amount_pizza - 1); i++){
        Pizza temp_pizza(pizza_size, pizza_crust_type, pizza_menu);
        iter->next = new Pizza(temp_pizza);
        iter = iter->next;
    }

    cout << "Please choose a drink:" << endl;
    cout << "0. no drink" << endl;
    cout << "1. cola 4 TL" << endl;
    cout << "2. soda 2 TL" << endl;
    cout << "3. ice tea 3 TL" << endl;
    cout << "4. fruit juice 3.5 TL" << endl;
    cout << "Press -1 for save your order" << endl;

    cin >> selected_drink;
    amount_of_drink = 0;

    if(selected_drink != 0){

        while (selected_drink != -1)
        {
            if(selected_drink <= 4 && selected_drink > 0){

                amount_of_drink += 1;
                iter_drink = temp_drink;
                temp_drink = new string[amount_of_drink];

                if(iter_drink != NULL){
                    for(int i = 0; i < (amount_of_drink - 1); i++){
                        temp_drink[i] = iter_drink[i];
                    }                   
                }

                if(selected_drink == 1){
                    temp_drink[amount_of_drink - 1] = "Cola";
                }
                else if(selected_drink == 2){
                    temp_drink[amount_of_drink - 1] = "Soda";
                }
                else if(selected_drink == 3){
                    temp_drink[amount_of_drink - 1] = "Ice tea";
                }
                else if(selected_drink == 4){
                    temp_drink[amount_of_drink - 1] = "Fruit juice";
                }
            }
            else
            {
                cout << "invalid entry" << endl;
            }
            cin >> selected_drink;
        }        
    }
    cout << "Your order is saved, it will be delivered when it is ready..." << endl;

    if(head == NULL){
        if(amount_of_drink == 0){
            head = new Order(customer_name, temp_head);
        }
        else
        {
            head = new Order(customer_name, temp_head, temp_drink);
            head->setNumberDrink(amount_of_drink);
        }      
    }
    else
    {
        Order *iter_order = head;

        while (iter_order->next != NULL)
        {
            iter_order = iter_order->next;
        }
        if(amount_of_drink == 0){
            iter_order->next = new Order(customer_name, temp_head);
        }
        else
        {
            iter_order->next = new Order(customer_name, temp_head, temp_drink);
            iter_order->next->setNumberDrink(amount_of_drink);
        }           
    }
    number_of_orders += 1;
}

void Orderlist::listOrders(){
    if(head == NULL){
        cout << "There is no order" << endl;
    }
    else
    {
        int i = 1;
        Order *iter = head;
        while (iter != NULL)
        {
            cout << i << endl;
            iter->printOrder();
            iter = iter->next;
            i += 1;
        }      
    }
}

void Orderlist::deliverOrders(){
    string name;
    double total_price = 0;

    listOrders();

    if (head != NULL)
    {
        cout << "Please write the customer name in order to deliver his/her order: " ;
        cin >> name;
        cout << "Following order is delivering..." << endl;

        Order *iter = head;

        while (iter != NULL)
        {
            if(iter->customer.compare(name) == 0){
                iter->printOrder();
                total_price = iter->getPrice();
                cout << "Total price: " << total_price << endl;
                break;
            }
            iter = iter->next;
        }
        if(total_price == 0){
            cout << "Order not found" << endl;
        }
        else
        {
            cout << "Do you have a promotion code? (y/n)" << endl;
            string prom_code, check_prom;
            cin >> check_prom;

            if (check_prom.compare("y") == 0)
            {
                cout << "Enter the promotion code: " << endl;
                cin >> prom_code;
                
                if(prom_code.compare("student") == 0){
                        total_price = (total_price * 90) / 100;
                        cout << "Total price: " << total_price << endl;
                }
                else
                {
                    cout << "invalid prom code" << endl;
                }
                                                 
            }
            
            if(iter == head){
                head = iter->next;
                delete iter;
            }
            else
            {
                Order *temp = head;
                while (temp->next != iter)
                {
                    temp = temp->next;
                }
                temp->next = iter->next;
                delete iter;
            }
            cout << "The order is delivered successfully!" << endl;
            
        }
    }
}
