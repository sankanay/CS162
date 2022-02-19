/******************************************************
** Program: pit.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the pit class
** Input:
** Output:
******************************************************/
#include "pit.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Pit
** Description: constructor to assignment values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Pit::Pit(){

    msg  = "You feel a breeze..";
    event_letter = 'P';

}

/******************************************************
** Function: get_msg
** Description: return the msg to events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string Pit::get_msg(){

    return msg;
}

/******************************************************
** Function: print_msg
** Description: print the msg to events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Pit::print_msg(){

    cout << msg << endl;

}

Pit::~Pit(){

    msg = " ";

}