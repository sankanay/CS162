/******************************************************
** Program: prog.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Contains the flow of the game
** Input:
** Output:
******************************************************/
#include "zoo.h"
#include "player.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: main
** Description: contains the flow of the game
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int main(){

    cout << endl;
    cout << "Initializing player..." << "\n";
    Player p;
    cout << "Initializing zoo..." << "\n";
    Zoo z;

    bool play = true;
    while(play){
        cout << endl;
        cout << "**************START OF MONTH**************" << "\n";
        if(p.has_money(0) == 0){
            play = false;
            cout << "The Zoo went bankrupt!" << endl;
        }
        //purchase animals
        p.print();
        cout << "\n";
        if(p.has_money(0) > 0){
            bool suc = z.purchase_animals(p);  
        }
        //p.print();
        cout << "\n";
        //increase zoo animals age
        z.increase_animal_age();
        //special event: sick, birth, boom, none
        cout << "\n";
        z.special_event(p);
        //calculate revenue
        cout << "\n";
        z.calculate_revenue(p);
        cout << "\n";
        z.calculate_monthly_food_cost(p);
        cout << "\n";
        z.adjust_base_food_cost();
        cout << "\n";
        p.print();   
    }
    return 0;
}