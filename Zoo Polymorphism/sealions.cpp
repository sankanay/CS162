/******************************************************
** Program: sealions.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the sealions class
** Input:
** Output:
******************************************************/
#include "sealions.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Sealions
** Description: Constructor for sealions class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Sealions::Sealions(){

    age = 0;
    animal_cost = 800;
    food_cost_mult = 1;
    revenue = 0.2;
    babies_at_time = 1;
    sick_mult = 0.5;
    type = 0;

}

/******************************************************
** Function: get_food_cost
** Description: get the food cost for sealions
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Sealions::get_food_cost(){

    return (base_food_cost * food_cost_mult);
}

/******************************************************
** Function: get_food_cost
** Description: get the adjusted food cost for sealions
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Sealions::get_food_cost(double base){

    return (base * food_cost_mult);
}

/******************************************************
** Function: get_revenue
** Description: get revenue based of age
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Sealions::get_revenue(){

    int l = get_life_phase();

    if(l == 0){
        return ((animal_cost * revenue) * 2);
    }
    else{
        return (animal_cost * revenue);
    }
}

/******************************************************
** Function: get_sick_expense
** Description: get sick expense based of age
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Sealions::get_sick_expense(){

    int l = get_life_phase();

    if(l == 0){
        return ((animal_cost * sick_mult) * 2);
    }
    else{
        return (animal_cost * sick_mult);
    }
}

/******************************************************
** Function: ~Sealions
** Description: sealions destructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Sealions::~Sealions(){

    food_cost_mult = 0;
    revenue = 0;
    babies_at_time = 0;
    sick_mult = 0;
}


