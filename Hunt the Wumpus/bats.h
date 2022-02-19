/******************************************************
** Program: bats.h
** Author: Yash Sankanagouda
** Date: 5/23/2021
** Description: Base bats class
** Input:
** Output:
******************************************************/
#ifndef BATS_H
#define BATS_H
#include "event.h"
#include <iostream>
#include <vector>
using namespace std;


class Bats : public Event{
    private:
        //string msg;
        //char event_letter;

    public:
        Bats();
        string get_msg();
        void print_msg();   
        ~Bats();
        




};

#endif