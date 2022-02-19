/******************************************************
** Program: tigers.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the tigers class
** Input:
** Output:
******************************************************/
#include "tigers.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Tigers
** Description: Constructor for tigers class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Tigers::Tigers(){

    age = 0;
    animal_cost = 10000;
    food_cost_mult = 5;
    revenue = 0.1;
    babies_at_time = 3;
    sick_mult = 0.5;
    type = 1;
}

/******************************************************
** Function: get_food_cost
** Description: get the food cost for tigers
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Tigers::get_food_cost(){

    return (get_base_food_cost() * food_cost_mult);
}

/******************************************************
** Function: get_food_cost
** Description: get the adjusted food cost for tigers
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Tigers::get_food_cost(double base){

    return (base * food_cost_mult);
}

/******************************************************
** Function: get_revenue
** Description: get revenue based of age
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Tigers::get_revenue(){

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

double Tigers::get_sick_expense(){

    int l = get_life_phase();

    if(l == 0){
        return ((animal_cost * sick_mult) * 2);
    }
    else{
        return (animal_cost * sick_mult);
    }
}

/******************************************************
** Function: ~Tigers
** Description: tigers destructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Tigers::~Tigers(){

    food_cost_mult = 0;
    revenue = 0;
    babies_at_time = 0;
    sick_mult = 0;
}
