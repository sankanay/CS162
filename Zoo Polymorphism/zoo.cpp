/******************************************************
** Program: zoo.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the zoo
** Input:
** Output:
******************************************************/
#include "zoo.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/******************************************************
** Function: Zoo
** Description: zoo constructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Zoo::Zoo(){

    num_animals = 0;
    base_food_cost = 80;
}

/*double Zoo::get_account(){

    return account;

}

void Zoo::set_account(double a){

    account = a;

}

void Zoo::add_account(double a){

    account = account + a;

}

void Zoo::subtract_account(double a){

    account = account - a;

}*/

/******************************************************
** Function: get_num_animals
** Description: get the number of animals
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Zoo::get_num_animals(){

    return num_animals;
}

/******************************************************
** Function: set_num_animals
** Description: store the number of animals 
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::set_num_animals(int na){

    num_animals = na;
}

/******************************************************
** Function: add_animal
** Description: add the purchased animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::add_animal(Animal a){

    int index = 0;
    Animal* newanimals = new Animal[num_animals + 1];

    for(int i = 0; i < num_animals; i++){
        newanimals[i] = animals[i];
    }
    newanimals[num_animals] = a;
    newanimals[num_animals].set_animal_id(num_animals);
    newanimals[num_animals].print();

    if(num_animals > 0){
        delete [] animals;
    }
    
    set_num_animals(num_animals + 1);
    animals = new Animal[num_animals];
    for(int i = 0; i < num_animals; i++){
        animals[i] = newanimals[i];
    }
    cout << "Total number of animals in the zoo " << get_num_animals() << "\n";
    delete [] newanimals;
}

/******************************************************
** Function: remove_animal
** Description: remove the dead animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::remove_animal(Animal a){

    int index = 0;
    Animal* newanimals = new Animal[num_animals - 1];
    cout << "Removing animal:  ";
    a.print();
    for(int i = 0; i < num_animals; i++){
        if(a.get_animal_id() == animals[i].get_animal_id()){
            continue;
        }
        newanimals[index] = animals[i];
        cout << "Retaining Animal:   ";
        newanimals[index].print();
        index++;
    }
    delete [] animals;
    set_num_animals(num_animals - 1);
    animals = new Animal[num_animals];
    for(int i = 0; i < num_animals; i++){
        animals[i] = newanimals[i];
    }
    delete [] newanimals;
}

/******************************************************
** Function: increase_animal_age
** Description: increase animal age per turn
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::increase_animal_age(){
    cout << "Increasing age for " << num_animals << " animals" << "\n";
    for(int i = 0; i < num_animals; i++){
        animals[i].set_age(animals[i].get_age() + 1);
        animals[i].print();
    }
}

/******************************************************
** Function: handle_sick_animal
** Description: Special event to handle sick animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::handle_sick_animal(Player &p){

    cout << "Special Event: Animal got sick! " << endl;

    int i = rand() % num_animals;
    double sick_cost = animals[i].get_sick_expense();
    bool has_money = p.has_money(sick_cost);
    if(has_money){
        p.subtract_account(sick_cost, "Sickness cost");
    }
    else{
        cout << "   No money for the treatment! ";
        animals[i].print();
        cout << " died" << "\n";
        remove_animal(animals[i]);
    }
}

/******************************************************
** Function: adjust_base_food_cost
** Description: adjust the base food cost per turn
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::adjust_base_food_cost(){

    double d = rand() % 40 + 80;
    base_food_cost = (base_food_cost * (d/100));
    cout << "Adjusted Food Cost by " << d << "%, New Base Food Cost: $" << base_food_cost << "\n"; 
    
}

/******************************************************
** Function: purchase_animals
** Description: prompt the user to buy an animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool Zoo::purchase_animals(Player &p){

    int option = 0;
    int count = 0;
    bool suc = true;

    cout << "Which animal would you like to buy?" << "\n";
    cout << "(0 - sealion  1 - tiger  2 - black bear  3 - no animal) ";
    cin >> option;

    if(option == 0 || option == 1 || option == 2){
        cout << "How many would you like to purchase? (1 or 2) ";
        cin >> count;
    }
    else if(option == 3){
        cout << "You did not buy any animal. " << endl;
        return suc;
    }
    
    for(int i = 0; i < count; i++){
        if(option == 0){
            Sealions s;
            suc = handle_purchase_animal(p, s);
        }
        if(option == 1){
            Tigers t;
            suc = handle_purchase_animal(p, t);
        }
        if(option == 2){
            Bears b;
            suc = handle_purchase_animal(p, b);
        }
        if(!suc){
            return suc;
        }
    }
    return suc;
}

/******************************************************
** Function: handle_purchase_animal
** Description: handle the purchase
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool Zoo::handle_purchase_animal(Player &p, Animal a){

    if(p.has_money(a.get_animal_cost())){
        cout << "Purchasing animal: ";
        add_animal(a);
        p.subtract_account(a.get_animal_cost(), "Animal cost");
        return true;
    }
    else{
        cout << "You do not have enough money!" << endl;
        return false;
    }
}

/******************************************************
** Function: check_adult_animals
** Description: check if animal is an adult
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Zoo::check_adult_animals(){

    for(int i = 0; i < num_animals; i++){
        if(animals[i].get_life_phase() == 2){
            return 1;
        }
    }
    return 0;
}

/******************************************************
** Function: handle_birth
** Description: special event to handle the birth of animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::handle_birth(Player &p){

    int counter = check_adult_animals();

    if(counter == 0){
        cout << "There are no adult animals to give birth!" << "\n";
        return;
    }

    int i = 0;
    int l = 0;

    while(l != 2){
        i = rand() % num_animals;
        l = animals[i].get_life_phase();
    }

    int count = animals[i].get_num_babies_count();
    int type = animals[i].get_type();
    cout <<" Special Event: Handle Birth! " << endl;
    for(int i = 0; i < count; i++){
        if(type == 0){
            Sealions s;
            s.set_animal_id(num_animals);
            s.set_parent(animals[i].get_animal_id());
            add_animal(s);
        }
        if(type == 1){
            Tigers t;
            t.set_animal_id(num_animals);
            t.set_parent(animals[i].get_animal_id());
            add_animal(t);
        }
        if(type == 2){
            Bears b;
            b.set_animal_id(num_animals);
            b.set_parent(animals[i].get_animal_id());
            add_animal(b);
        }
    }
}

/******************************************************
** Function: calculate_revenue
** Description: calculate the monthly revenue for the animals
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::calculate_revenue(Player &p){

    double revenue = 0;

    for(int i = 0; i < num_animals; i++){
        revenue = revenue + animals[i].get_revenue();
    }
    p.add_revenue(revenue, "Monthly Revenue");
}

/******************************************************
** Function: attendance_boom
** Description: special event for boom in attendance
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::attendance_boom(Player &p){

    double revenue = 0;
    cout << "Special Event: Attendance Boom!" << endl;
    for(int i = 0; i < num_animals; i++){
        int type = animals[i].get_type();
        if(type == 0){
            revenue = revenue + animals[i].get_revenue();
            double r = rand() % 400 + 150;
            revenue = revenue + r;
        }
    }
    if(revenue == 0){
        cout << "   No additional revenue! There are no sealions!" << endl;
    }
    p.add_account(revenue, "Attendance Boom Revenue");
}

/******************************************************
** Function: special_event
** Description: picking a special event to occur
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::special_event(Player &p){

    int i = rand() % 4 + 1;

    if(i == 1){
        handle_sick_animal(p);
    }
    if(i == 2){
        handle_birth(p);
    }
    if(i == 3){
        attendance_boom(p);
    }
    if(i == 4){
        cout << "No special event happend!" << endl;
    }

}

/******************************************************
** Function: calculate_monthly_food_cost
** Description: calculating the monthly food cost for all the animals
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Zoo::calculate_monthly_food_cost(Player& p){

    double cost = 0;

    for(int i = 0; i < num_animals; i++){
        cost = cost + animals[i].get_food_cost(base_food_cost);
    }
    p.subtract_account_one(cost, "Monthly Food Cost");
}

/******************************************************
** Function: ~Zoo
** Description: zoo destructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Zoo::~Zoo(){

    delete [] animals;
    animals = NULL;
}
