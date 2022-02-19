/******************************************************
** Program: game.h
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Contains the Game class function
** Input:
** Output:
******************************************************/
#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"

using namespace std;

class Game {
  private:
    Deck deck; //changed variable from cards to deck for better readability
    Player players[2];
    Deck uppile;

  public:
    void shuffle();
    void set_player();
    string get_player_name(int);
    void set_player_hand();
    Card deal_a_card();
    void print_player_hand();
    bool will_play(Card, int);
    Card get_current_card();
    Card get_player_card(int, Card, int);
    void adjust_player_hand(Card, int);
    bool determne_winner(int);
    bool deck_has_cards();
    int alternate_player(int);
    int check_crazy_eight(Card, int);
    //Game();

};

#endif