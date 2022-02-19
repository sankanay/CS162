/******************************************************
** Program: deck.h
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Contains the Deck class function
** Input:
** Output:
******************************************************/
#ifndef DECK_H
#define DECK_H
#include "card.h"
#include "hand.h"
#include "player.h"
#include <string>

using namespace std;

class Deck{
    private:
    Card cards[52];
    int n_cards;
    int hearts = 0;
    int diamonds = 1;
    int clubs = 2;
    int spades = 3;
    int ace = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int six = 6;
    int seven = 7;
    int eight = 8;
    int nine = 9;
    int ten = 10;
    int jack = 11;
    int queen = 12;
    int king = 13;

    public:
    Deck();
    void shuffle();
    void print_cards();
    const Card draw_card();
    void remove_card(Card);
    void get_random_cards(Hand&);
    int get_card_count();
    void set_cards_count(int);
    void get_random_cards_one(Player&);
    ~Deck();
    //void set_cards(Card*);

};

#endif