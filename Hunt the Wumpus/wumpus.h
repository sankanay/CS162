/******************************************************
** Program: wumpus.h
** Author: Yash Sankanagouda
** Date: 5/23/2021
** Description: Base wumpus class
** Input:
** Output:
******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"
#include <iostream>
#include <vector>
using namespace std;

class Wumpus : public Event{
    private:
        //string msg;
        //char event_letter;

    public:
        Wumpus();
        string get_msg();
        void print_msg();

};

#endif