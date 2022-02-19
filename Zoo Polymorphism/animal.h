/******************************************************
** Program: animal.h
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Base animal class
** Input:
** Output:
******************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;

class Animal{
    protected:
        int BABY = 0;
        int ADOL = 1;
        int ADULT = 2;
        int age;
        double animal_cost;
        double food_cost;
        double revenue;
        int type;
        int life;
        double base_food_cost= 80;
        int animal_id;
        int babies_at_time = 0;
        int parent;
        double sick_mult;
        double food_cost_mult = 0;
    
    public:
        Animal();
        int get_age();
        void set_age(int);
        double get_animal_cost();
        void set_animal_cost(double);
        double get_food_cost(double);
        void set_food_cost(double);
        double get_revenue();
        void set_revenue(double);
        int get_num_babies_count();
        void set_num_babies_count(int);
        int get_type();
        void set_type(int);
        int get_life_phase();
        double get_base_food_cost();
        void set_base_food_cost(double);
        void adjust_food_cost();
        void print();
        int get_animal_id();
        void set_animal_id(int);
        virtual double get_sick_expense();
        int get_parent();
        void set_parent(int);
        ~Animal();
};

#endif