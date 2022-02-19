/******************************************************
** Program: hand.cpp
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Initializing each players hand
** Input:
** Output:
******************************************************/
#include "hand.h"
#include "card.h"
#include <iostream>
#include <string>

using namespace std;

/******************************************************
** Function: Hand
** Description: create the array for the hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Hand::Hand(){

    cards = new Card[7];
    n_cards = 7;
}

/******************************************************
** Function: set_cards
** Description: create the array for the hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Hand::set_cards(Card* newcards){

    cards = new Card[7];
    n_cards = 7;
    for(int i = 0; i < n_cards; i++){
        cards[i] = newcards[i];
    }
}

/******************************************************
** Function: set_card
** Description: setup the position of the card 
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Hand::set_card(int rank, int suit, int pos){

    cards[pos].set_rank(rank);
    cards[pos].set_suit(suit);
}

/******************************************************
** Function: set_cards_count
** Description: assign the value to a variable 
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Hand::set_cards_count(int c){

    n_cards = c;
}

/******************************************************
** Function: get_cards_count
** Description: return the value of the number of cards
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int Hand::get_card_count(){

    return n_cards;
}

/******************************************************
** Function: ~Hand
** Description: destructor for the class Hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
/*Hand::~Hand(){ //The code breaks whenever I try to delete the memory of the cards

    delete [] cards; //assigned memory in constructor by creating array but the delete is causing problem
    cards = NULL;
}*/

/******************************************************
** Function: print
** Description: print function for the hand class
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Hand::print(){

    for(int i = 0; i < n_cards; i++){
        cards[i].print();
    }
}

/******************************************************
** Function: add_card
** Description: What card stays and what card doesn't
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Hand::add_card(Card c){

    int index = 0;
    Card* newcards = new Card[n_cards + 1];
    cout << "Card to add:  ";
    c.print();
    for(int i = 0; i < n_cards; i++){
        newcards[i] = cards[i];
        cout << "Retaining card:  ";
        newcards[i].print();
    }
    newcards[n_cards] = c;
    cout << "adding card:  ";
    newcards[n_cards].print();
    delete [] cards;
    set_cards_count(n_cards + 1);
    cards = new Card[n_cards];
    for(int i = 0; i < n_cards; i++){
        cards[i].set_rank(newcards[i].get_rank());
        cards[i].set_suit(newcards[i].get_suit());
    }
}

/******************************************************
** Function: remove_card
** Description: What card stays and what card doesn't
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Hand::remove_card(Card c){

    int index = 0;
    Card* newcards = new Card[n_cards - 1];
    cout << "Card to remove:  ";
    c.print();
    for(int i = 0; i < n_cards; i++){
        if((cards[i].get_rank() == c.get_rank()) && (cards[i].get_suit() == c.get_suit())){
            continue;
        }
        newcards[index] = cards[i];
        cout << "Retaining card:  ";
        newcards[index].print();
        index++;
    }
    delete [] cards;
    set_cards_count(n_cards - 1);
    cards = new Card[n_cards];
    for(int i = 0; i < n_cards; i++){
        cards[i].set_rank(newcards[i].get_rank());
        cards[i].set_suit(newcards[i].get_suit());
    }
}

/******************************************************
** Function: card_by_suit_exist
** Description: imlpementation to check if a suit match exists
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
bool Hand::card_by_suit_exist(Card currentcard){

    for(int i = 0; i < n_cards; i++){
        if(cards[i].get_suit() == currentcard.get_suit()){
            cout << "FOUND SUIT MATCH" << "\n";
            return true;
        }
    }
    cout << "NO suit MATCH FOUND " << "\n";
    return false;
}

/******************************************************
** Function: card_by_rank_exist
** Description: imlpementation to check if a rank match exists
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
bool Hand::card_by_rank_exist(Card currentcard){

    for(int i = 0; i < n_cards; i++){
        if(cards[i].get_rank() == currentcard.get_rank()){
            cout << "FOUND RANK MATCH" << "\n";
            return true;
        }
    }
    cout << "NO rank MATCH FOUND " << "\n";
    return false;
}

/******************************************************
** Function: card_crazy_exist
** Description: imlpementation to check if a crazy match exists
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
bool Hand::card_crazy_exist(){

    for(int i = 0; i < n_cards; i++){
        if(cards[i].get_rank() == 8){
            cout << "FOUND CRAZY MATCH" << "\n";
            return true;
        }
    }
    cout << "NO CRAZY MATCH FOUND " << "\n";
    return false;
}

/******************************************************
** Function: get_card_by_suit
** Description: get the suit card for CPU
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Hand::get_card_by_suit(Card currentcard){

    for(int i = 0; i < n_cards; i++){
        if(cards[i].get_suit() == currentcard.get_suit()){
            return cards[i];
        }
    }
    Card c;
    return c;
}

/******************************************************
** Function: human_get_card_by_suit
** Description: get the suit card for user
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Hand::human_get_card_by_suit(Card currentcard){

    int option = 0;
    bool valid = false;
    while(!valid){
        for(int i = 0; i < n_cards; i++){
            if(cards[i].get_suit() == currentcard.get_suit()){
                cout << "Matching card: ";
                cards[i].print();
                cout << "Would you like to play this card? (1 - yes) (0 - no)" << "\n";
                cin >> option;
                if(option == 1){
                    valid = true;
                    return cards[i];
                }
                else{
                    continue;
                }
            }
        }
        cout << "You did not select any card. Pick one: ";
    }
    Card c;
    return c;
}

/******************************************************
** Function: get_card_by_rank
** Description: get the rank card for CPU
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Hand::get_card_by_rank(Card currentcard){

    for(int i = 0; i < n_cards; i++){
        if(cards[i].get_rank() == currentcard.get_rank()){
            return cards[i];
        }
    }
    Card c;
    return c;
}

/******************************************************
** Function: human_get_card_by_rank
** Description: get the rank card for user
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Hand::human_get_card_by_rank(Card currentcard){

    int option = 0;
    bool valid = false;
    while(!valid){
        for(int i = 0; i < n_cards; i++){
            if(cards[i].get_rank() == currentcard.get_rank()){
                cout << "Matching card: ";
                cards[i].print();
                cout << "Would you like to play this card? (1 - yes) (0 - no)" << "\n";
                cin >> option;
                if(option == 1){
                    valid = true;
                    return cards[i];
                }
                else{
                    continue;
                }
            }
        }
        cout << "You did not select any card. Pick one: ";
    }
    Card c;
    return c;
}

/******************************************************
** Function: get_card_crazy
** Description: get the crazy card for CPU
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Hand::get_card_crazy(){

    for(int i = 0; i < n_cards; i++){
        if(cards[i].get_rank() == 8){
            return cards[i];
        }
    }
    Card c;
    return c;
}

/******************************************************
** Function: human_get_card_by_crazy
** Description: get the crazy card for user
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Hand::human_get_card_by_crazy(){

    int option = 0;
    bool valid = false;
    while(!valid){
        for(int i = 0; i < n_cards; i++){
            if(cards[i].get_rank() == 8){
                cout << "Matching card: ";
                cards[i].print();
                cout << "Would you like to play this card? (1 - yes) (0 - no)" << "\n";
                cin >> option;
                if(option == 1){
                    valid = true;
                    return cards[i];
                }
                else{
                    continue;
                }
            }
        }
        cout << "You did not select any card. Pick one: ";
    }
    Card c;
    return c;
}

/******************************************************
** Function: get_cards
** Description: returns the cards array value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card* Hand::get_cards(){
    
    return cards;

}

/******************************************************
** Function: Hand
** Description: assigns the values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Hand::Hand(const Hand &h){

    cards = h.cards;
    n_cards = h.n_cards;

}

/******************************************************
** Function: operator=
** Description: copy constructor to copy onto another object
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Hand& Hand::operator= (const Hand &h){

    if(this != &h){ //make sure they are two different objects
        Card* newcards = new Card[h.n_cards]; //step 1: allocate new memeory
        copy(h.cards, (h.cards + h.n_cards), newcards); //step 2: copy contents
        delete [] cards; //step 3: deallocating the old memeory
        cards = newcards; //step 4: assigning the new memory to the object
        n_cards = h.n_cards; //step 5: copying the new content to variable
    }
    return *this; //step 6: returning the reference of 'this' object (h)
}