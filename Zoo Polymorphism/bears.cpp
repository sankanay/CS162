/******************************************************
** Program: bears.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the black bears class
** Input:
** Output:
******************************************************/
#include "bears.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Bears
** Description: Constructor for bears class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Bears::Bears(){

    age = 0;
    animal_cost = 5000;
    food_cost_mult = 3;
    revenue = 0.1;
    babies_at_time = 2;
    sick_mult = 0.5;
    type = 2;
}

/******************************************************
** Function: get_food_cost
** Description: get the food cost for bears
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Bears::get_food_cost(){

    return (base_food_cost * food_cost_mult);
}

/******************************************************
** Function: get_food_cost
** Description: get the adjusted food cost for bears
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Bears::get_food_cost(double base){

    return (base * food_cost_mult);
}

/******************************************************
** Function: get_revenue
** Description: get revenue based of age
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Bears::get_revenue(){

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

double Bears::get_sick_expense(){

    int l = get_life_phase();

    if(l == 0){
        return ((animal_cost * sick_mult) * 2);
    }
    else{
        return (animal_cost * sick_mult);
    }
}

/******************************************************
** Function: ~Bears
** Description: bears destructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Bears::~Bears(){

    food_cost_mult = 0;
    revenue = 0;
    babies_at_time = 0;
    sick_mult = 0;
}
