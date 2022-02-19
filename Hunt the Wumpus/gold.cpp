#include "gold.h"
#include <iostream>
using namespace std;

Gold::Gold(){

    msg  = "You see a glimmer nearby..";
    event_letter = 'G';

}

string Gold::get_msg(){

    return msg;
}

void Gold::print_msg(){

    cout << msg << endl;

}