/******************************************************
** Program: prog.cpp                                                                                           
** Author: Yash Sankanagouda
** Date: 6/6/2021
** Description: flow of the program
** Input:
** Output:
******************************************************/
#include <iostream>
using namespace std;
#include "linked_list.h"

/******************************************************
** Function: main
** Description: flow of the program
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int main(){

    int i = 0;
    char option = 'y';
    Linked_List list;

    while(option == 'y'){
        cout << "Enter a number: ";
        cin >> i;
        list.push_front(i);
        cout << "Do you want another num (y or n): ";
        cin >> option;
    }
    cout << "Your Linked List is: ";
    list.print();
    cout << "Linked list length: ";
    list.get_length();

    cout << "Sort ascending or descending (a or d): ";
    cin >> option;

    if(option == 'a'){
        
        list.sort_ascending();
    }
    else if(option == 'd'){
        
        list.sort_descending();
    }
    list.clear();

    return 0;
}