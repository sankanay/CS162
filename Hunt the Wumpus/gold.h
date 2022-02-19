#ifndef GOLD_H
#define GOLD_H
#include "event.h"
#include <iostream>
#include <vector>
using namespace std;


class Gold : public Event{
    private:
        //string msg;
        //char event_letter;

    public:
        Gold();
        string get_msg();
        void print_msg();   
        




};

#endif