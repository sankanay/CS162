/******************************************************
** Program: wumpus.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the wumpus class
** Input:
** Output:
******************************************************/
#include "wumpus.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Wumpus
** Description: constructor to assignment values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Wumpus::Wumpus(){

    msg  = "You smell a terrible stench..";
    event_letter = 'W';

}

/******************************************************
** Function: get_msg
** Description: return the msg to events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string Wumpus::get_msg(){

    return msg;
}

/******************************************************
** Function: print_msg
** Description: print the msg to events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Wumpus::print_msg(){

    cout << msg << endl;

}