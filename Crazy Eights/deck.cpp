/******************************************************
** Program: deck.cpp
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Creating the dekc and shuffling it
** Input:
** Output:
******************************************************/
#include "deck.h"
#include "card.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <string>
using namespace std;

/******************************************************
** Function: Deck
** Description: constructor for deck, init the deck
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Deck::Deck(){

    int suits[] = {hearts, diamonds, clubs, spades};
    int ranks[] = {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
    for(int i = 0; i < 52; i++){
        cards[i] = Card(suits[i/13], ranks[i % 13]);
    }
    set_cards_count(52);
    shuffle();
}

/******************************************************
** Function: shuffle
** Description: shuffles the deck
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Deck::shuffle(){

    for(int i = 0; i < 52; i++){
        Card temp;
        int pos = rand() % 52;
        temp = cards[i];
        cards[i] = cards[pos];
        cards[pos] = temp;
    }
}

/******************************************************
** Function: print_cards
** Description: prints the cards
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Deck::print_cards(){

    for(int i = 0; i < 52; i++){
        cards[i].print();
    }
}

/******************************************************
** Function: draw_card
** Description: copy construtcor to copy the values onto another object
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
const Card Deck::draw_card(){

    bool valid = false;
    int i = 0;
    Card c;
    while(!valid){
        i = rand() % n_cards;
        if((cards[i].get_rank() == -1) && (cards[i].get_suit() == -1)){
            valid = false;
        }
        else{
            valid = true;
            c.set_rank(cards[i].get_rank());
            c.set_suit(cards[i].get_suit());
            cards[i].set_rank(-1);
            cards[i].set_suit(-1);
            set_cards_count(n_cards - 1); 
        }
    }
    return c;
}

/******************************************************
** Function: remove_card
** Description: function to remove the card 
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Deck::remove_card(Card c){

    c.print();
    for(int i = 0; i < n_cards; i++){
        if((cards[i].get_rank() == c.get_rank()) && (cards[i].get_suit() == c.get_suit())){
            cards[i].set_rank(-1);
            cards[i].set_suit(-1);
        }
    }
    n_cards--;
    print_cards();
}

/******************************************************
** Function: set_cards_count
** Description: sets the value of n_cards 
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Deck::set_cards_count(int i){

    n_cards = i;
}

/******************************************************
** Function: get_card_count
** Description: returns the value of n_cards 
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int Deck::get_card_count(){

    return n_cards;
}

/******************************************************
** Function: get_random_cards
** Description: setting the cards up
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Deck::get_random_cards(Hand &h){

    Card tempcards[52] = {};
    Card r_cards[7] = {};
    for(int k = 0; k < n_cards; k++){
        if(k < 7){
            r_cards[k] = cards[k];
        }
        else{
            tempcards[k - 7] = cards[k];
        }
    }
    Card* cardptr = &r_cards[0];
    h.set_cards_count(7);
    h.set_cards(cardptr);    
    h.print();
    for(int i = 0; i < n_cards; i++){
        cards[i] = tempcards[i];
    }
    n_cards = n_cards - 7;
}

/******************************************************
** Function: get_random_cards_one
** Description: setting the cards up
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Deck::get_random_cards_one(Player &p){

    int index = 0;
    p.get_hand().set_cards_count(7);
    for(int i = (n_cards - 1); i > 0; i--){
        if(index < 7){
            if((cards[i].get_rank() != -1) && (cards[i].get_suit() != -1)){
                p.get_hand().set_card(cards[i].get_rank(), cards[i].get_suit(), index);
                cards[i].set_rank(-1);
                cards[i].set_suit(-1);
                index++;
            }
        }
        else{
            break;
        }
    }
    set_cards_count(n_cards - 7);
}

/******************************************************
** Function: ~Deck
** Description: destroctor for the class Deck
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Deck::~Deck(){

    //delete [] cards;
    //cards = NULL;
}