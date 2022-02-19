/******************************************************
** Program: player.h
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Class for the player
** Input:
** Output:
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player{
    public: 
        double account;

        Player();
        double get_account();
        void set_account(double);
        void add_account(double, string);
        void subtract_account(double, string);
        void subtract_account_one(double, string);
        bool has_money(double);
        void add_revenue(double, string);
        void print();
        ~Player();

};

#endif