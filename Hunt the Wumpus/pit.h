/******************************************************
** Program: pit.h
** Author: Yash Sankanagouda
** Date: 5/23/2021
** Description: Base pit class
** Input:
** Output:
******************************************************/
#ifndef PIT_H
#define PIT_H
#include "event.h"
#include <iostream>
#include <vector>
using namespace std;


class Pit : public Event{
    private:
        //string msg;
        //char event_letter;

    public:
        Pit();
        string get_msg();
        void print_msg();   
        ~Pit();
        




};

#endif