/******************************************************
** Program: room.h
** Author: Yash Sankanagouda
** Date: 5/23/2021
** Description: Base room class
** Input:
** Output:
******************************************************/
#ifndef ROOM_H
#define ROOM_H
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include <iostream>
#include <vector>
using namespace std;


class Room{
    private:
        Event *special_event;
        char event;
        char player;
        char wumpus;
        char escape;
        int row;
        int col;
        string id;

    public:
        Room();
        void set_event(char);
        char get_event();
        void set_player(char);
        char get_player();
        void set_escape(char);
        char get_escape();
        void set_grid_location(int, int);
        int get_grid_location_x();
        int get_grid_location_y();
        void set_id(string);
        string get_id();
        void get_message();
        int get_row();
        int get_col();
        ~Room();
        

           
     

};

#endif