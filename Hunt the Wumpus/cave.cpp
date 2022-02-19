/******************************************************
** Program: cave.cpp
** Author: Yash Sankanagouda
** Date: 5/9/2021
** Description: Initializes the cave class
** Input:
** Output:
******************************************************/

#include "cave.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Cave
** Description: Constructor for cave class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Cave::Cave(){

    player_start_x = -1;
    player_start_y = -1;
    player_x = -1;
    player_y = -1;
    gold_count = 0;
    num_arrows = 3;
    wumpus_dead = false;
    player_dead = false;
    game = false;

}

/******************************************************
** Function: Cave
** Description: Constructor for cave class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Cave::Cave(int r, int c){

    rows = r;
    cols = c;
    player_start_x = -1;
    player_start_y = -1;
    player_x = -1;
    player_y = -1;
    gold_count = 0;
    num_arrows = 3;
    wumpus_dead = false;
    player_dead = false;
    game = false;

}

/******************************************************
** Function: print_cave
** Description: prints the cave with rooms
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::print_cave(bool debug){

    for(int i = 0; i <= (cols * 6) ;i++){
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j <= cols; j++){
            string p = player_room(i, j);
            if (i % 2 == 0 && j % 2 == 0){
                if(!debug){
                    cout << "| " << p << " " << "  ";
                }
                else if(debug){
                    string r = room_event(i, j);
                    cout << "| " << p << r << "  ";
                }
            }
            else if (i % 2 == 1 && j % 2 == 1){
                if(!debug){
                    cout << "| " << p << " " << "  ";
                }
                else if(debug){
                    string r = room_event(i, j);
                    cout << "| " << p << r << "  ";
                }
            }
            else{
                if(!debug){
                    cout << "| " << p << " " << "  ";
                }
                else if(debug){
                    string r = room_event(i, j);
                    cout << "| " << p << r << "  ";
                }
            }
            p.clear();
        }
        cout << endl;
        for(int i = 0; i <= (cols * 6) ;i++){
            cout << "-";
        }
        cout << endl;
    }
    cout << endl;
}

/******************************************************
** Function: player_room
** Description: players start position
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string Cave::player_room(int x, int y){

    string s = " ";

    for(int i = 0; i < rooms.size(); i++){
        if(rooms[i].get_row() == x && rooms[i].get_col() == y){
            s = rooms[i].get_player();
            return s;
        }
    }
    return s;
}

/******************************************************
** Function: room_event
** Description: rooms with random events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string Cave::room_event(int x, int y){

    string s = " ";

    for(int i = 0; i < rooms.size(); i++){
        if(rooms[i].get_row() == x && rooms[i].get_col() == y){
            s = rooms[i].get_event();
            return s;
        }
    }
    return s;
}

/******************************************************
** Function: init_player_position
** Description: initialize the player start and escpae room
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::init_player_position(){

    int x = 0;
    int y = 0;

    srand(time(NULL));
    x = rand() % rows;
    srand(time(NULL));
    y = rand() % cols;

    player_start_x = x;
    player_x = x;
    player_start_y = y;
    player_y = y;
}

/******************************************************
** Function: setup_rooms
** Description: create rooms
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::setup_rooms(){

    for(int i = 0; i < rows; i++){
        for(int k = 0; k < cols; k++){
            Room r;
            r.set_grid_location(i, k);
            string x = to_string(i) + to_string(k);
            r.set_id(x);
            if(player_x == i && player_y == k){
                r.set_player('*');
            }
            rooms.push_back(r);
            if(r.get_player() != ' '){
                vacant_rooms.push_back(x);
            }
        }
    }
}


int Cave::get_rand_room(){

    int i = 0;
    srand(time(NULL));
    i = rand() % (rows * cols);
    while(rooms[i].get_event() != ' ' || rooms[i].get_player() != ' '){
        i = rand() % (rows * cols);
    }

    return i;
}


/******************************************************
** Function: init_events
** Description: initialize the events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::init_events(){

    int i = 0;
    /*i = rand() % (rows * cols);
    while(rooms[i].get_event() != ' ' || rooms[i].get_player() != ' '){
        i = rand() % (rows * cols);
    }*/
    i = get_rand_room();
    rooms[i].set_event('G');
    remove_vacant_room(rooms[i].get_id());

    //i = rand() % (rows * cols);
    i = get_rand_room();
    rooms[i].set_event('B');
    remove_vacant_room(rooms[i].get_id());
    //i = rand() % (rows * cols);
    i = get_rand_room();
    rooms[i].set_event('B');
    remove_vacant_room(rooms[i].get_id());

    //i = rand() % (rows * cols);
    i = get_rand_room();
    rooms[i].set_event('P');
    remove_vacant_room(rooms[i].get_id());
    //i = rand() % (rows * cols);
    i = get_rand_room();
    rooms[i].set_event('P');
    remove_vacant_room(rooms[i].get_id());

    //i = rand() % (rows * cols);
    i = get_rand_room();
    rooms[i].set_event('W');
    remove_vacant_room(rooms[i].get_id());

}

/******************************************************
** Function: remove_vacant_room
** Description: remove empty rooms for events
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::remove_vacant_room(string id){

    for(int i = 0; i < vacant_rooms.size(); i++){
        if(vacant_rooms[i] == id){
            vacant_rooms.erase(vacant_rooms.begin() + i);
            return;
        }
    }
}

/******************************************************
** Function: position_valid
** Description: make sure the player can move in that direction
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool Cave::position_valid(int x, int y){

    if(x > (rows - 1) || x < 0 || y > (cols - 1) || y < 0){
        return false;
    }
    return true;
}

/******************************************************
** Function: display_adjacent_event
** Description: print the appropriate message
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::display_adjacent_event(){

    int x, y = 0;
    //up
    x = player_x - 1;
    y = player_y;
    if(position_valid(x, y)){
        display_room_msg(x, y);
    }
    //down
    x = player_x + 1;
    y = player_y;
    if(position_valid(x, y)){
        display_room_msg(x, y);
    }
    //left
    x = player_x;
    y = player_y - 1;
    if(position_valid(x, y)){
        display_room_msg(x, y);
    }
    //right
    x = player_x;
    y = player_y + 1;
    if(position_valid(x, y)){
        display_room_msg(x, y);
    }

}

/******************************************************
** Function: display_room_msg
** Description: message when player is in the room
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::display_room_msg(int x, int y){

    for(int i = 0; i < rooms.size(); i++){
        if(rooms[i].get_row() == x && rooms[i].get_col() == y){
            if(rooms[i].get_event() != ' '){
                rooms[i].get_message();
            }
        }
    }
}

/******************************************************
** Function: move_player
** Description: move the player in direction
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::move_player(char option){
    //w,a,s,d
    //up,left,down,right
    int x, y = 0;

    if(option == 'w' || option == 'W'){
        x = player_x - 1;
        y = player_y;
        if(position_valid(x, y)){
            new_player_pos(x, y);
        }
    }
    if(option == 's' || option == 'S'){
        x = player_x + 1;
        y = player_y;
        if(position_valid(x, y)){
            new_player_pos(x, y);
        }
    }
    if(option == 'a' || option == 'A'){
        x = player_x;
        y = player_y - 1;
        if(position_valid(x, y)){
            new_player_pos(x, y);
        }
    }
    if(option == 'd' || option == 'D'){
        x = player_x;
        y = player_y + 1;
        if(position_valid(x, y)){
            new_player_pos(x, y);
        }
    }
    check_room_events();
}

/******************************************************
** Function: new_player_pos
** Description: mark the players position on the grid
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::new_player_pos(int new_x, int new_y){

    for(int i = 0; i < rooms.size(); i++){
        if(rooms[i].get_row() == player_x && rooms[i].get_col() == player_y){
            rooms[i].set_player(' ');
        }
        if(rooms[i].get_row() == new_x && rooms[i].get_col() == new_y){
            rooms[i].set_player('*');
        }
    }
    player_x = new_x;
    player_y = new_y;
    
}

/******************************************************
** Function: check_room_events
** Description: check the events in the room
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::check_room_events(){

    for(int i = 0; i < rooms.size(); i++){
        if(rooms[i].get_row() == player_x && rooms[i].get_col() == player_y){
            if(rooms[i].get_event() == 'G'){
                cout << "You picked up the gold!" << endl;
                gold_count++;
                rooms[i].set_event(' ');
            }
            if(rooms[i].get_event() == 'B'){
                cout << "A super bat picked you up!" << endl;
                cout << "Moving to a different room!" << endl;
                rooms[i].set_event(' ');
                srand(time(NULL));
                int x = rand() % rows;
                srand(time(NULL));
                int y = rand() % cols;
                new_player_pos(x, y);
            }
            if(rooms[i].get_event() == 'P'){
                cout << "You fell in the pit and died!" << endl;
                rooms[i].set_event(' ');
                player_dead = true;
                game = true;
                return;
            }
            if(rooms[i].get_event() == 'W'){
                cout << "The Wumpus ate you! You died!" << endl;
                rooms[i].set_event(' ');
                player_dead = true;
                game = true;
                return;
            }
        }
    }
}

/******************************************************
** Function: player_option
** Description: check to see what player wants to do
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Cave::player_option(){

    bool valid = false;
    int option = 0;

    while(!valid){
        cout << "Would you like to move (1) or shoot (2) : ";
        cin >> option;
        if(option < 1 || option > 2){
            cout << "Invalid option, select again: ";
        }
        else{
            if(option == 2 && num_arrows <= 0){
                cout << "You have no arrows, select move: ";
                valid = false;
            }
            else{
                valid = true;
            }
        }
    }
    return option;
}

/******************************************************
** Function: player_action
** Description: perform the player action
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::player_action(){

    int option = player_option();

    if(option == 1){
        char direction = get_player_direction();
        move_player(direction);
        if(!player_dead){
            display_adjacent_event();
        }
    }
    else if(option == 2){
        get_player_fire_arrow();
    }
}

/******************************************************
** Function: get_player_direction
** Description: get players direction
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

char Cave::get_player_direction(){

    bool valid = false;
    char direction = ' ';

    while(!valid){
        cout << "W - up | S - down | A - left | D - right : ";
        cin >> direction;
        if(direction != 'W' && direction != 'S' && direction != 'A' && direction != 'D' && direction != 'w' && direction != 's' && direction != 'a' && direction != 'd' ){
            cout << "Invalid option, select again: " << endl;
        }
        else{
            valid = true;
        }

    }
    return direction;
}

/******************************************************
** Function: get_player_fire_arrow
** Description: fire the players arrow
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::get_player_fire_arrow(){

    num_arrows = num_arrows - 1;
    int missed_count = 0;

    if(num_arrows < 1){
        cout << "You do not have any more arrows!" << endl;
    }

    char direction = get_player_direction();

    int x = player_x;
    int y = player_y;

    if(direction == 'w' || direction == 'W'){
        for(int i = 0; i < 3; i++){
            x = x - 1;
            y = y;
            if(position_valid(x, y) && check_wumpus(x, y)){
                cout << "You have killed the Wumpus! " << endl;
                wumpus_dead = true;
                return;
            }
            else{
                cout << "You missed the Wumpus!" << endl;
                missed_count++;
            }
        }
    }
    if(direction == 's' || direction == 'S'){
        for(int i = 0; i < 3; i++){
            x = x + 1;
            y = y;
            if(position_valid(x, y) && check_wumpus(x, y)){
                cout << "You have killed the Wumpus!" << endl;
                wumpus_dead = true;
                return;
            }
            else{
                cout << "You missed the Wumpus!" << endl;
                missed_count++;
            }
        }
    }
    if(direction == 'a' || direction == 'A'){
        for(int i = 0; i < 3; i++){
            x = x;
            y = y - 1;
            if(position_valid(x, y) && check_wumpus(x, y)){
                cout << "You have killed the Wumpus!" << endl;
                wumpus_dead = true;
                return;
            }
            else{
                cout << "You missed the Wumpus!" << endl;
                missed_count++;
            }
        }
    }
    if(direction == 'd' || direction == 'D'){
        for(int i = 0; i < 3; i++){
            x = x;
            y = y + 1;
            if(position_valid(x, y) && check_wumpus(x, y)){
                cout << "You have killed the Wumpus!" << endl;
                wumpus_dead = true;
                return;
            }
            else{
                cout << "You missed the Wumpus!" << endl;
                missed_count++;
            }
        }
    }
    if(missed_count == 3){
        move_wumpus();
    }
}

/******************************************************
** Function: move_wumpus
** Description: move wumpus if it wakes up
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::move_wumpus(){

    srand(time(NULL));
    int i = rand() % 100 + 1;
    string id = " ";

    if(i <= 75){
        cout << "You woke up the Wumpus, it moved to a different room!" << endl;
        for(int i = 0; i < rooms.size(); i++){
            if(rooms[i].get_event() == 'W'){
                rooms[i].set_event(' ');
                id = rooms[i].get_id();
                break;
            }
        }
        for(int i = 0; i < rooms.size(); i++){
            if(rooms[i].get_player() == ' ' && rooms[i].get_event() == ' '){
                int j = rand() % 100 + 1;
                if(j < 50){
                    rooms[i].set_event('W');
                    remove_vacant_room(rooms[i].get_id());
                    break;
                }
            }
        }
        vacant_rooms.push_back(id);
    }
}

/******************************************************
** Function: check_wumpus
** Description: check if wumpus exists
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool Cave::check_wumpus(int x, int y){

    for(int i = 0; i < rooms.size(); i++){
        if(rooms[i].get_row() == x && rooms[i].get_col() == y){
            if(rooms[i].get_event() == 'W'){
                rooms[i].set_event(' ');
                return true;
            }
        }
    }
    return false;
}

/******************************************************
** Function: hunt
** Description: flow of the game
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::hunt(bool debug){

    init_player_position();
    setup_rooms();
    init_events();
    print_cave(debug);
    do{
        cout << "Arrow count: " << num_arrows << endl;
        cout << "Gold count: " << gold_count << endl;
        display_adjacent_event();
        player_action();
        print_cave(debug);
        check_winner();
    }while(game != true);

}

/******************************************************
** Function: check_winner
** Description: see if player won
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Cave::check_winner(){

    if(gold_count == 1 || wumpus_dead == true){
        if(player_x == player_start_x && player_y == player_start_y){
            cout << "You escaped the cave successfully and won!" << endl;
            game = true;
        }
    }
}

/******************************************************
** Function: ~Cave
** Description: delete memory
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Cave::~Cave(){

    rooms.erase(rooms.begin(), rooms.end());
    rooms.shrink_to_fit();

    vacant_rooms.erase(vacant_rooms.begin(), vacant_rooms.end());
    vacant_rooms.shrink_to_fit();

}




