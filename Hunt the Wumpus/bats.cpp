/******************************************************
** Program: bats.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the bats class
** Input:
** Output:
******************************************************/
#include "bats.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Bats
** Description: constructor to assignment values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Bats::Bats(){

    msg  = "You hear wings flapping..";
    event_letter = 'B';

}

/******************************************************
** Function: get_msg
** Description: return the msg to events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string Bats::get_msg(){

    return msg;
}

/******************************************************
** Function: print_msg
** Description: print the msg to events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Bats::print_msg(){

    cout << msg << endl;

}

/******************************************************
** Function: ~Bats
** Description: destructor
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Bats::~Bats(){

    msg.clear();

}  

