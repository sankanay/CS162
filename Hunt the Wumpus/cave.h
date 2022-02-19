/******************************************************
** Program: cave.h
** Author: Yash Sankanagouda
** Date: 5/23/2021
** Description: Base cave class
** Input:
** Output:
******************************************************/
#ifndef CAVE_H
#define CAVE_H
#include "room.h"
#include <iostream>
#include <vector>
using namespace std;

class Cave{
    private:
        int rows;
        int cols;
        int player_start_x;
        int player_start_y;
        int player_x;
        int player_y;
        int gold_count;
        int num_arrows;
        bool wumpus_dead;
        bool player_dead;
        bool game;
        vector<Room> rooms;
        vector<string> vacant_rooms;

    public:
        Cave();
        Cave(int, int);
        void print_cave(bool);
        string player_room(int, int);
        int get_rand_room();
        void init_player_position();
        string room_event(int, int);
        string display_player_event(string, string);
        void setup_rooms();
        void init_events();
        void remove_vacant_room(string);
        bool position_valid(int, int);
        void display_adjacent_event();
        void display_room_msg(int, int);
        void move_player(char);
        void new_player_pos(int, int);
        void check_room_events();
        int player_option();
        void player_action();
        char get_player_direction();
        void get_player_fire_arrow();
        bool check_wumpus(int, int);
        void hunt(bool);
        void check_winner();
        void move_wumpus();
        ~Cave();
        




};

#endif