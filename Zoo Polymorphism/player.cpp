/******************************************************
** Program: tigers.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the player class
** Input:
** Output:
******************************************************/
#include "player.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Player
** Description: player constructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Player::Player(){

    account = 100000;
}

/******************************************************
** Function: get_account
** Description: return the value of the account
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double Player::get_account(){

    return account;
}

/******************************************************
** Function: get_account
** Description: store the value of the account into a variable
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Player::set_account(double a){

    account = a;
}

/******************************************************
** Function: add_account
** Description: adding the revenue to account
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Player::add_account(double a, string s){

    cout << "   Adding: " << s << " $" << a << endl;
    account = account + a;
}

/******************************************************
** Function: subtract_account
** Description: subtracting the revenue to account
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Player::subtract_account(double a, string s){

    cout << "   Subtracting: " << s << " $" << a << endl;
    account = account - a;
}

/******************************************************
** Function: subtract_account_one
** Description: subtracting the revenue to account
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Player::subtract_account_one(double a, string s){

    cout << "Subtracting: " << s << " $" << a << endl;
    account = account - a;
}

/******************************************************
** Function: has_money
** Description: check to see if players have money
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool Player::has_money(double a){

    if(account >= a){
        return true;
    }
    return false;
}

/******************************************************
** Function: add_revenue
** Description: add revenue to account
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Player::add_revenue(double a, string s){

    cout << "Adding: " << s << " $" << a << endl;
    account = account + a;
}

/******************************************************
** Function: print
** Description: how much money is in the account
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Player::print(){

    cout << "Account: $" << account << " available" << endl;
}

/******************************************************
** Function: ~Player
** Description: player destructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Player::~Player(){

    account = 0;
}