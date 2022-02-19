/******************************************************
** Program: event.h
** Author: Yash Sankanagouda
** Date: 5/23/2021
** Description: Base event class
** Input:
** Output:
******************************************************/
#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <vector>
using namespace std;


class Event{
        

    public:
        string msg;
        char event_letter;
        Event();
        virtual string get_msg();
        virtual void print_msg();     
        ~Event();
     

};

#endif