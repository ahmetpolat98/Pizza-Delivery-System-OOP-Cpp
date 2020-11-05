#include <iostream>
#include <string>
#include "pizza.h"

using namespace std;

Pizza::Pizza(){
    cout << "parametresiz olustu" << endl; //
    
    name = "default name";
    size = "medium";
	crust_type = "normal";
	ingredients = new string[1];
	ingredients[0] = "mozeralla";
    size_of_ingredients = 1;
    this->next = NULL;
}

Pizza::Pizza(string size, string crust_type, int pizza_type){
    cout << "parametreli olustu" << endl; //

    this->size = size;
    this->crust_type = crust_type;
    ingredients = new string[6];
    size_of_ingredients = 6;
    this->next = NULL;

    if (pizza_type == 1)
    {
        this->name = "Chicken Pizza";

        this->ingredients[0] = "mozerella";
		this->ingredients[1] = "chicken";
		this->ingredients[2] = "mushroom";
		this->ingredients[3] = "corn";
		this->ingredients[4] = "onion";
		this->ingredients[5] = "tomato";
    }
    else if (pizza_type == 2)
    {
        this->name = "Broccoli Pizza";

        this->ingredients[0] = "mozerella";
		this->ingredients[1] = "broccoli";
		this->ingredients[2] = "pepperoni";
		this->ingredients[3] = "olive";
		this->ingredients[4] = "corn";
		this->ingredients[5] = "onion";
    }
    else if (pizza_type == 3)
    {
        this->name = "Sausage Pizza";

        this->ingredients[0] = "mozerella";
		this->ingredients[1] = "sausage";
		this->ingredients[2] = "tomato";
		this->ingredients[3] = "olive";
		this->ingredients[4] = "mushroom";
		this->ingredients[5] = "corn";
    }     
}

Pizza::Pizza(Pizza &changePizza){

    int input;
    bool input_check = true;

    while (input_check)
    {
        cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;
        for (int i = 0; i < changePizza.size_of_ingredients; i++){
            cout << (i + 1) << ". " << changePizza.ingredients[i] << endl;
        }
        cout << "Press 0 to save it" << endl;

        cin >> input;

        if(input == 0){
            input_check = false;
        }
        else if(input > 0 && input <= changePizza.size_of_ingredients){
            for(int i = input; i < changePizza.size_of_ingredients; i++ ){
                changePizza.ingredients[i - 1] = changePizza.ingredients[i];               
            }
            changePizza.size_of_ingredients -= 1;
        }
        else
        {
            cout << "invalid entry" << endl;
        }                    
    }
    this->name = changePizza.name;
    this->size = changePizza.size;
    this->crust_type = changePizza.crust_type;
    this->size_of_ingredients = changePizza.size_of_ingredients;
    this->ingredients = changePizza.ingredients;
    this->next = changePizza.next;
    
}

Pizza::~Pizza(){
    //cout << this->name << " nesne silindi" << endl; //
}

//silinecek
void Pizza::showPizza(){
    cout << "isim: " << name << endl;
    cout << "size: " << size << endl;
    cout << "crust type: " << crust_type << endl;
    for (int i = 0; i < size_of_ingredients; i++){
        cout << (i + 1) << ". " << ingredients[i] << endl;
    }

    if(this->next != NULL){
        cout << "next null degil" << endl; //
        cout << this->next->name << endl; //
    }
    else{
        cout << "next null" << endl;    //
    }
    
}

//silinecek
void Pizza::nextEkle(){
    this->next = new Pizza;
}