/******************************************************
** Program: hand.h
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Contains the Hand class function
** Input:
** Output:
******************************************************/
#ifndef HAND_H
#define HAND_H
#include "card.h"
#include <string>

using namespace std;

class Hand {
  private:
    Card* cards;
    int n_cards;

  public:
    Hand();
    void set_cards(Card*);
    void set_card(int, int, int);
    void set_cards_count(int);
    int get_card_count();
    void remove_card(Card);
    //~Hand();
    Hand(const Hand&);
    Hand& operator= (const Hand&);
    void print();
    void add_card(Card);
    bool card_by_suit_exist(Card);
    bool card_by_rank_exist(Card);
    bool card_crazy_exist();
    Card get_card_by_suit(Card);
    Card get_card_by_rank(Card);
    Card get_card_crazy();
    Card* get_cards();
    Card human_get_card_by_suit(Card);
    Card human_get_card_by_rank(Card);
    Card human_get_card_by_crazy(); 
};

#endif