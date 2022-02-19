/******************************************************
** Program: prog.cpp
** Author: Yash Sankanagouda
** Date: 4/10/2021
** Description:  Read the spellbooks and its spells and organize them
** Input: Command line arguements
** Output: The file
******************************************************/
#include "spell.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/******************************************************
** Function: main
** Description: get the text file from the command line arguments and call functions
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int main(int argc, char *argv[]){

    string filename;
    bool get_file = false;

    if(argc != 2){
        get_file = true;
    }
    else if(argc == 2){
        string s(argv[1]);
        if(s != "spellbooks.txt"){
            get_file = true;
        }
        else{
            filename = s;
        }
    }
    if(get_file){
        filename = " ";
        while(filename != "spellbooks.txt"){
            cout << "Invlid filename! Re-enter: " << endl;
            cin >> filename;
        }
    }

    read_input_file(filename);

    return 0;
}