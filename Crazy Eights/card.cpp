/******************************************************
** Program: card.cpp
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Initializing the cards
** Input:
** Output:
******************************************************/
#include "card.h"
#include <iostream>
#include <string>
using namespace std;

/******************************************************
** Function: Card
** Description: Constructor for card class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card::Card(){

    suit = -1;
    rank = -1;
}

/******************************************************
** Function: Card
** Description: Constructor for card class
** Parameters: n/a
** Pre-conditions: int s, int r
** Post-conditions: n/a
******************************************************/
Card::Card(int s, int r){

    suit = s;
    rank = r;
}

/******************************************************
** Function: get_suit
** Description: returns the value for suit
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int Card::get_suit(){

    return suit;
}

/******************************************************
** Function: get_rank
** Description: returns the value for rank
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int Card::get_rank(){

    return rank;
}

/******************************************************
** Function: set_suit
** Description: sets the value for suit
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Card::set_suit(int s){

    suit = s;
}

/******************************************************
** Function: set_rank
** Description: sets the value for rank
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Card::set_rank(int r){

    rank = r;
}

/******************************************************
** Function: print
** Description: converts the int values of suit to the names
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Card::print(){

    cout << rank;
    if(suit == 0){
        cout << "  Hearts" << "\n";
    }
    if(suit == 1){
        cout << "  Diamonds" << "\n";
    }
    if(suit == 2){
        cout << "  Clubs" << "\n";
    }
    if(suit == 3){
        cout << "  Spades" << "\n";
    }
}
