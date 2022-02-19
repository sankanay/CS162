/******************************************************
** Program: sealions.h
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Derived class for sealions
** Input:
** Output:
******************************************************/
#ifndef SEALIONS_H
#define SEALIONS_H
#include "animal.h"
#include <iostream>
using namespace std;

class Sealions : public Animal{
    public:
        int food_cost_mult;
        double revenue_mult;
        int babies_at_time;
        double sick_mult;
        
        Sealions();
        int get_food_cost();
        double get_food_cost(double);
        double get_revenue();
        double get_sick_expense();
        ~Sealions();
};

#endif
