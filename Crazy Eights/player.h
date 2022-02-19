/******************************************************
** Program: player.h
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Contains the Player class function
** Input:
** Output:
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"

using namespace std;

class Player{
  private:
  Hand hand;
  string name;

  public:
  void set_name(string);
  string get_name();
  void set_hand(Hand);
  Hand get_hand();
  void add_card(Card);
  void discard_card(Card);
  bool will_play(Card);
  Card player_place_card(Card, int);
  Card human_player_place_card(Card, int);
  int get_player_option(bool, bool, bool);
  ~Player();

};

#endif