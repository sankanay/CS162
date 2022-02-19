/******************************************************
** Program: zoo.h
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Class for the zoo
** Input:
** Output:
******************************************************/
#ifndef ZOO_H
#define ZOO_H
#include "animal.h"
#include "player.h"
#include "sealions.h"
#include "tigers.h"
#include "bears.h"
#include <iostream>
using namespace std;

class Zoo{
    public:
        double account;
        int num_animals;
        int base_food_cost;
        Animal* animals;

        Zoo();
        //double get_account();
        //void set_account(double);
        //void add_account(double);
        //void subtract_account(double);
        int get_num_animals();
        void set_num_animals(int);
        void add_animal(Animal);
        void remove_animal(Animal);
        Animal* get_all_animals();
        void increase_animal_age();
        void handle_sick_animal(Player&);
        void adjust_base_food_cost();
        bool purchase_animals(Player&);
        bool handle_purchase_animal(Player&, Animal);
        int check_adult_animals();
        void handle_birth(Player&);
        void calculate_revenue(Player&);
        void attendance_boom(Player&);
        void special_event(Player&);
        void calculate_monthly_food_cost(Player&);
        ~Zoo();

};

#endif

