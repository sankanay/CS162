/******************************************************
** Program: animal.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the animal class
** Input:
** Output:
******************************************************/

#include "animal.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Animal
** Description: Constructor for animal class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Animal::Animal(){

    age = 0;
    animal_cost = 0;
    food_cost = 0;
    revenue = 0;
    base_food_cost = 80;
    BABY = 0;
    ADOL = 1;
    ADULT = 2;
}

/******************************************************
** Function: get_age
** Description: returns the age
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Animal::get_age(){

    return age;
}

/******************************************************
** Function: set_age
** Description: sets the age to variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_age(int a){

    age = a;
}

/******************************************************
** Function: get_animal_cost
** Description: returns the animal cost
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Animal::get_animal_cost(){

    return animal_cost;
}

/******************************************************
** Function: set_animal_cost
** Description: sets the animal cost a to variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_animal_cost(double ac){

    animal_cost = ac;
}

/******************************************************
** Function: get_food_cost
** Description: setting up the food cost for each animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Animal::get_food_cost(double base_food_cost){


    if(type == 0){
        food_cost_mult = 1;
    }
    if(type == 1){
        food_cost_mult = 5;
    }
    if(type == 2){
        food_cost_mult = 3;
    }
    
    return (base_food_cost * food_cost_mult);

}

/******************************************************
** Function: set_food_cost
** Description: storing food cost into a variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_food_cost(double fc){

    food_cost = fc;
}

/******************************************************
** Function: get_revenue
** Description: setting up the revenue for each animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Animal::get_revenue(){

    int l = get_life_phase();
    if(get_type() == 0){
        animal_cost = 800;
        revenue = 0.2;
    }
    if(get_type() == 1){
        animal_cost = 10000;
        revenue = 0.1;
    }
    if(get_type() == 2){
        animal_cost = 5000;
        revenue = 0.1;
    }

    if(l == BABY){
        return ((animal_cost * revenue) * 2);
    }
    else{
        return (animal_cost * revenue);
    }

}

/******************************************************
** Function: set_revenue
** Description: storing revenue into variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_revenue(double r){

    revenue = r;
}

/******************************************************
** Function: get_num_babies_count
** Description: setting up the number of babies for each animal
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Animal::get_num_babies_count(){

    //return babies_at_time;
    if(get_type() == 0){
        return 1;
    }
    if(get_type() == 1){
        return 3;
    }
    if(get_type() == 2){
        return 2;
    }
}

/******************************************************
** Function: set_num_babies_count
** Description: store number of babies into a variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_num_babies_count(int nb){

    babies_at_time = nb;
}

/******************************************************
** Function: get_type
** Description: return the animal type
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Animal::get_type(){

    return type;
}

/******************************************************
** Function: set_type
** Description: store the animal type into a varibale
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_type(int t){

    type = t;
}

/******************************************************
** Function: get_life_phase
** Description: find out what stage of life the animal is in
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Animal::get_life_phase(){

    if(age < 6){
        return BABY; //baby
    }
    else if(age > 6 && age < 48){
        return ADOL; //adolescnece
    }
    else{
        return ADULT; //adult
    }
}

/******************************************************
** Function: get_base_food_cost
** Description: return the food cost for stage of life
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Animal::get_base_food_cost(){

    return base_food_cost;
}

/******************************************************
** Function: set_base_food_cost
** Description: Store the food cost for stage of life into variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_base_food_cost(double bfc){

    base_food_cost = bfc;
}

/******************************************************
** Function: adjust_food_cost
** Description: Adjust the base food cost
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::adjust_food_cost(){

    int i = rand() % 120 + 80;

    double c = get_base_food_cost();

    c = c + (c * (i/100));

    set_base_food_cost(c);

}

/******************************************************
** Function: print
** Description: print out the animals name
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::print(){

    if(get_type() == 0){
        cout << "   Sea Lion, Age " << get_age() << "\n";
    }
    if(get_type() == 1){
        cout << "   Tigers, Age " << get_age() << "\n";
    }
    if(get_type() == 2){
        cout << "   Black Bears, Age " << get_age() << "\n";
    }
}

/******************************************************
** Function: get_animal_id
** Description: return the animals id
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Animal::get_animal_id(){

    return animal_id;
}
        
/******************************************************
** Function: set_animal_id
** Description: store the animals id into a variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_animal_id(int id){

    animal_id = id;
}

/******************************************************
** Function: get_sick_expense
** Description: get sick expense for all animals
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Animal::get_sick_expense(){

    if(get_type() == 0){
        animal_cost = 800;
        sick_mult = 0.5;
    }
    if(get_type() == 1){
        animal_cost = 10000;
        sick_mult = 0.5;
    }
    if(get_type() == 2){
        animal_cost = 5000;
        sick_mult = 0.5;
    }
    int l = get_life_phase();
    if(l == BABY){
        return ((animal_cost * sick_mult) * 2);
    }
    else{
        return (animal_cost * sick_mult);
    }
}

/******************************************************
** Function: get_parent
** Description: return the parent
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Animal::get_parent(){

    return parent;

}

/******************************************************
** Function: set_parent
** Description: store the parent into a variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Animal::set_parent(int prnt){

    parent = prnt;

}

/******************************************************
** Function: ~Animal
** Description: Animal destructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Animal::~Animal(){

    BABY = 0;
    ADOL = 0;
    ADULT = 0;
    age = 0;
    animal_cost = 0;
    food_cost = 0;
    revenue = 0;
    type = 0;
    life = 0;
    base_food_cost = 0;
    animal_id = 0;
    babies_at_time = 0;
    parent = 0;
    sick_mult = 0;
    food_cost_mult = 0;
    
}