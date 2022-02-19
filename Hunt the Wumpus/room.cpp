/******************************************************
** Program: room.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the room class
** Input:
** Output:
******************************************************/
#include "room.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Room
** Description: constructor to assignment values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Room::Room(){

    special_event = NULL;
    event = ' ';
    player = ' ';
    wumpus = ' ';
    escape = ' ';
    row = -1;
    col = -1;
    id = " ";

}

/******************************************************
** Function: set_event
** Description: pointer to set event
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Room::set_event(char e){

    this->event = e;

    if(e == 'W'){
        special_event = new Wumpus();
    }
    if(e == 'P'){
        special_event = new Pit();
    }
    if(e == 'B'){
        special_event = new Bats();
    }
    if(e == 'G'){
        special_event = new Gold();
    }
    if(e == ' '){
        delete special_event;
        special_event = NULL;
        
    }
}

/******************************************************
** Function: get_event
** Description: return event
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

char Room::get_event(){

    return event;
}

/******************************************************
** Function: set_player
** Description: set player value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Room::set_player(char p){

    player = p;
    
}

/******************************************************
** Function: get_player
** Description: return player value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

char Room::get_player(){

    return player;
}

/******************************************************
** Function: set_escape
** Description: set escape value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Room::set_escape(char e){

    escape = e;
    
}

/******************************************************
** Function: get_escape
** Description: return escape value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

char Room::get_escape(){

    return escape;
}

/******************************************************
** Function: set_grid_location
** Description: set grid location
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Room::set_grid_location(int x, int y){

    row = x;
    col = y;
    
}

/******************************************************
** Function: get_grid_location_x
** Description: get x value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Room::get_grid_location_x(){

    return row;
}

/******************************************************
** Function: get_grid_location_y
** Description: get y value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Room::get_grid_location_y(){

    return col;
}

/******************************************************
** Function: set_id
** Description: set id value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Room::set_id(string i){

    id = i;
    
}

/******************************************************
** Function: get_id
** Description: return id
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string Room::get_id(){

    return id;
}

/******************************************************
** Function: get_message
** Description: point special event to print the message
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Room::get_message(){

    special_event->print_msg();
}

/******************************************************
** Function: get_row
** Description: return row
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Room::get_row(){

    return row;
}

/******************************************************
** Function: get_col
** Description: return col
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Room::get_col(){

    return col;
}

/******************************************************
** Function: ~Room
** Description: deallocate memory
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Room::~Room(){

    delete special_event;
    special_event = NULL;

}



