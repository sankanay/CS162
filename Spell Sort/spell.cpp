/******************************************************
** Program: spell.cpp
** Author: Yash Sankanagouda
** Date: 4/10/2021
** Description:  Read the spellbooks and its spells and organize them
** Input: Option to sort and option to print
** Output: Sort of the spellbooks/spells and data outputed
******************************************************/
#include "spell.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/******************************************************
** Function: print_spellbook
** Description: Print the contents of the struct
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void print_spellbook(spellbook* spellbooks, int num_spellbooks, int option){
    
    for(int i = 0; i < num_spellbooks; i++){
        if(option == 1){
            cout << spellbooks[i].title << "    " << spellbooks[i].num_pages << endl;
        }
        if(option == 3){
            cout <<  spellbooks[i].title << "   " << spellbooks[i].avg_success_rate << endl;
        }
    }
}

/******************************************************
** Function: print_spells
** Description: Print the contents of the struct
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void print_spells(spell* spells, int num_allspells){
    
    for(int i = 0; i < num_allspells; i++){
        cout << spells[i].effect << "    " << spells[i].name << endl;
    }
}

/******************************************************
** Function: read_input_file
** Description: Read the contents of the .txt file
** Parameters: n/a
** Pre-conditions: spellbooks.txt
** Post-conditions: n/a
******************************************************/
void read_input_file(string filename){
    ifstream f;
    f.open("spellbooks.txt");
    spellbook* spellbooks;
    spell* allspells;
    int num_spellbooks = 0;
    int num_allspells = 0;

    if(f.fail()){
        cout << "Error opening file!"  << endl;
    }
    else{
        string temp;
        int count = 0;
        while(!f.eof()){            
            if(count == 0){
                getline(f, temp);
                num_spellbooks = atoi(&temp[0]);
                spellbooks = create_spellbooks(num_spellbooks);
            }
            else if(count > 0){
                get_spellbook_data(spellbooks, count - 1, f);
                check_spells(spellbooks, count - 1, f);
            }
            count++;
            if(count > num_spellbooks){
                break;
            }
        }
        f.close();
    }
    num_allspells = get_spell_count(spellbooks, num_spellbooks);
    allspells = new spell[num_allspells];
    create_spell_list(spellbooks, num_spellbooks, allspells);
    get_user_sorting_option(spellbooks, num_spellbooks, allspells, num_allspells);
}

/******************************************************
** Function: create_spell_list
** Description: Create the list for the spells and its contents
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void create_spell_list(spellbook* spellbooks, int num_spellbooks, spell* allspells){

    int count = 0;
    for(int i = 0; i < num_spellbooks; i++){
        for(int j = 0; j < spellbooks[i].num_spells; j++){
            allspells[count] = spellbooks[i].s[j];
            count++;
        }
    }
}

/******************************************************
** Function: create_spell_count
** Description: Count the number of spells under each spellbook
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int get_spell_count(spellbook* spellbooks, int num_spellbooks){

    int num_spells = 0;
    for(int i = 0; i < num_spellbooks; i++){
        num_spells = num_spells + spellbooks[i].num_spells;
    }
    return num_spells;
}

/******************************************************
** Function: sort_spells_by_effect
** Description: Sort the spells based of their effect
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void sort_spells_by_effect(spell* allspells, int num_allspells){

    struct spell temp;
    for(int i = 0; i < num_allspells; i++){
        for(int j = i + 1; j < num_allspells; j++){
            if(allspells[i].effect > allspells[j].effect){
                    temp = allspells[i];
                    allspells[i] = allspells[j];
                    allspells[j] = temp;
            }
        }
    }
}

/******************************************************
** Function: get_option
** Description: Get the option that the user would like to perform
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int get_option(){
    int option;
    cout << "Which option would you like to choose?" << endl;
    cout << "Sort spellbooks by number of pages (Press 1):" << endl;
    cout << "Group spells by their effect (Press 2):" << endl;
    cout << "Sort spellbooks by average success rate (Press 3):" << endl;
    cout << "Quit (Press 4:)" << endl;
    cin >> option;
    while(cin.fail() == 1 || (cin.fail() == 0 && (option > 4 || option < 1))){
        cout << "Invalid input! Enter again: " << endl;
        option = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> option;
    }
    return option;
}

/******************************************************
** Function: get_print_option
** Description: Get the option one how the data should be printed
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int get_print_option(){
    int print;
    cout << "How would you like the information displayed?" << endl;
    cout << "Print to screen (Press 1):" << endl;
    cout << "Print to file (Press 2):" << endl;
    cin >> print;
    while(cin.fail() == 1 || (cin.fail() == 0 && (print > 4 || print < 1))){
        cout << "Invalid input! Enter again: " << endl;
        print = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> print;
    }
    return print;
}

/******************************************************
** Function: get_user_sorting_option
** Description: Perform the action based on the option choice
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void get_user_sorting_option(spellbook* spellbooks, int num_spellbooks, spell* allspells, int num_allspells){

    int option = 0;
    int print = 0;
    bool loop = true;

    while(loop){
        option = get_option();
        if(option == 4){
            delete_spellbook_data(spellbooks, allspells, num_spellbooks);
            break;
        }    

        if(option == 1 || option == 3){
            sort_spellbooks(spellbooks, num_spellbooks, option);
        }
        if(option == 2){
            sort_spells_by_effect(allspells, num_allspells);
        }

        print = get_print_option();

        if(print == 1){
            print_to_screen(spellbooks, num_spellbooks, allspells, num_allspells, option);
        }
        if(print == 2){
            print_to_file(spellbooks, num_spellbooks, allspells, num_allspells, option);
        }
    }
}

/******************************************************
** Function: print_to_screen
** Description: Perform the action based on the option choice
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void print_to_screen(spellbook* spellbooks, int num_spellbooks, spell* allspells, int num_allspells, int option){

    if(option == 1 || option == 3){
        print_spellbook(spellbooks, num_spellbooks, option);
    }
    if(option == 2){
        print_spells(allspells, num_allspells);
    }
}

/******************************************************
** Function: print_spellbook_to_file
** Description: To print the spellbooks onto the file
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void print_spellbook_to_file(spellbook* spellbooks, int num_spellbooks, int option, fstream &ofile){

    ofile << "*****************************SEPARATOR*************************************" << endl;
    for(int i = 0; i < num_spellbooks; i++){
        ofile << spellbooks[i].title;
        ofile << " ";
        if(option == 1){
            ofile << spellbooks[i].num_pages;
        }
        if(option == 3){
            ofile << spellbooks[i].avg_success_rate;
        }
        ofile << endl;
    }
}

/******************************************************
** Function: print_spell_to_file
** Description: To print the spells onto the file
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void print_spell_to_file(spell* spells, int num_allspells, int option, fstream &ofile){

    ofile << "*****************************SEPARATOR*************************************" << endl;
    for(int i = 0; i < num_allspells; i++){
        ofile << (spells[i].effect);
        ofile << " ";
        ofile << spells[i].name;
        ofile << endl;
    }
}

/******************************************************
** Function: print_to_file
** Description: To print the action performed onto the file
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void print_to_file(spellbook* spellbooks, int num_spellbooks, spell* allspells, int num_allspells, int option){

    string file_name;
    cout << "Please provide desired filename: ";
    cin >> file_name;

    fstream ofile;
    ofstream output;

    ofile.open(file_name, ofile.out|ofile.app);

    if(ofile){
        cout << "Appended requested information to the following file: " << file_name << endl;
        if(option == 1 || option == 3){
            print_spellbook_to_file(spellbooks, num_spellbooks, option, ofile);
        }
        if(option == 2){
            print_spell_to_file(allspells, num_allspells, option, ofile);
        }
        ofile.close();
    }
}

/******************************************************
** Function: sort_spellbooks
** Description: To sort the spellbooks based on the number of pages and the success rate
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void sort_spellbooks(spellbook* spellbooks, int num_spellbooks, int option){

    struct spellbook temp;
    for(int i = 0; i < num_spellbooks; i++){
        for(int j = i + 1; j < num_spellbooks; j++){
            if((option == 1 && spellbooks[i].num_pages > spellbooks[j].num_pages) ||
                (option == 3 && spellbooks[i].avg_success_rate > spellbooks[j].avg_success_rate)){
                    temp = spellbooks[i];
                    spellbooks[i] = spellbooks[j];
                    spellbooks[j] = temp;
            }
        }
    }
}

/******************************************************
** Function: check_spells
** Description: To see how many spells are under each spellbook and calculate average success rate
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void check_spells(spellbook* spellbooks, int index, ifstream &f){

    spellbook s = spellbooks[index];
    float avg_success_rate = 0;

    int num_spells = s.num_spells;
    spell *spells = create_spells(num_spells);
    for(int i = 0; i < num_spells; i++){
        get_spell_data(spells, i, f);
        avg_success_rate = avg_success_rate + spells[i].success_rate;
    }
    avg_success_rate = avg_success_rate/num_spells;
    spellbooks[index].avg_success_rate = avg_success_rate;
    spellbooks[index].s = spells;
}

/******************************************************
** Function: create_spellbooks
** Description: Create array for the struct
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
spellbook* create_spellbooks(int num_spellbooks){

    return new spellbook[num_spellbooks];
}

/******************************************************
** Function: get_spellbook_data
** Description: Scan the information from the text and assign it to the values in the struct
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void get_spellbook_data(spellbook* spellbooks, int index, ifstream &f){

    string temp;
    struct spellbook s;
    int count = 0;
    getline(f, temp);
    //Wacky_Witch_Handbook Gretchen 1344 19 3
    stringstream ss(temp);
    while(count < 5 ){
        string str;
        getline(ss, str, ' ');
        if(count == 0){
            s.title = str;
        }
        else if(count == 1){
            s.author = str;
        }
        else if(count == 2){
            s.num_pages = atoi(&str[0]);
        }
        else if(count == 3){
            s.edition = atoi(&str[0]);
        }
        else if(count == 4){
            s.num_spells = atoi(&str[0]);
        }
        count++;
    }
    spellbooks[index] = s;
}

/******************************************************
** Function: create_spells
** Description: Create array for the struct
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
spell* create_spells(int num_spells){

    return new spell[num_spells];
}

/******************************************************
** Function: get_spell_data
** Description: Scan the information from the text and assign it to the values in the struct
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void get_spell_data(spell* spells, int index, ifstream &f){

    string temp;
    spell s;
    int count = 0;
    getline(f, temp);
    stringstream ss(temp);
    while(ss.good()){
        string str;
        getline(ss, str, ' ');
        if(count == 0){
            s.name = str;
        }
        else if(count == 1){
            s.success_rate = atol(&str[0]);
        }
        else if(count == 2){
            s.effect = str;
        }
        count++;
    }
    spells[index] = s;
}

/******************************************************
** Function: delete_spellbook_data
** Description: Delete memory to free up space
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void delete_spellbook_data(spellbook* spellbooks, spell* allspells, int num_spells){

    for(int i = 0; i < num_spells; i++){
        delete [] spellbooks[i].s;
    }
    delete [] spellbooks;
    delete [] allspells;
}