/******************************************************
** Program: player.cpp
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Setting up the players and getting their input options
** Input:
** Output:
******************************************************/
#include "player.h"
#include "hand.h"
#include <iostream>
#include <string>
using namespace std;

/******************************************************
** Function: set_name
** Description: setting up for the names for my players
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Player::set_name(string playername){

    name = playername;

}

/******************************************************
** Function: get_name
** Description: return the name of the players
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
string Player::get_name(){

    return name;
}

/******************************************************
** Function: set_hand
** Description: setting up for the hand for my players
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Player::set_hand(Hand h){

    hand = h;

}

/******************************************************
** Function: get_hand
** Description: return the value of the hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Hand Player::get_hand(){

    return hand;

}

/******************************************************
** Function: add_card
** Description: add the card to the hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Player::add_card(Card c){

    hand.add_card(c);

}

/******************************************************
** Function: discard_card
** Description: remove the card from the hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Player::discard_card(Card c){

    hand.remove_card(c);

}

/******************************************************
** Function: will_play
** Description: to see if the cards exist and return the value
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
bool Player::will_play(Card currentcard){

    //find if card exist by suit
    bool suit_card = hand.card_by_suit_exist(currentcard);
    //find if card exist by rank
    bool rank_card = hand.card_by_rank_exist(currentcard);
    //find if crazy eight card exists
    bool crazy_card = hand.card_crazy_exist();

    return (suit_card || rank_card || crazy_card);

}

/******************************************************
** Function: player_place_Card
** Description: Where the CPU plays its card
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Player::player_place_card(Card currentcard, int current_suit){//this function is over 20 lines due to print statements, without them is would be
                                                                //just about 20 lines. I cannot make this any shorts, it works our better when it is in the same function.

    bool suit_card = hand.card_by_suit_exist(currentcard);
    bool rank_card = hand.card_by_rank_exist(currentcard);
    bool crazy_card = hand.card_crazy_exist();
    if(current_suit != -1){
        rank_card = false;
        crazy_card = false;
    }
    cout << "Before adjusting hand cards : " << "\n";
    hand.print();
    cout << "****************************" << "\n";
    cout << suit_card << " " << rank_card << " " << crazy_card << endl;
    if(suit_card){
        Card c = hand.get_card_by_suit(currentcard);
        discard_card(c);
        cout << "*** After adjusting hand cards: *** " << "\n";
        hand.print();
        cout << "*********************************** " << endl;
        return c;
    }
    if(rank_card){
        Card c = hand.get_card_by_rank(currentcard);
        discard_card(c);
        cout << "*** After adjusting hand cards: *** " << "\n";
        hand.print();
        cout << "*********************************** " << endl;
        return c;
    }
    if(crazy_card){
        Card c = hand.get_card_crazy();
        discard_card(c);
        cout << "*** After adjusting hand cards: *** " << "\n";
        hand.print();
        cout << "*********************************** " << endl;
        return c;
    }
    Card c; //dummy card
    return c;
}

/******************************************************
** Function: human_player_place_Card
** Description: Where the user plays their card
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Player::human_player_place_card(Card currentcard, int current_suit){//this function is over 20 lines due to print statements, without them is would be
                                                                                //just about 20 lines. I cannot make this any shorts, it works our better when it is in the same function.

    bool suit_card = hand.card_by_suit_exist(currentcard);
    bool rank_card = hand.card_by_rank_exist(currentcard);
    bool crazy_card = hand.card_crazy_exist();
    if(current_suit != -1){
        cout << "current suit block  " << current_suit << "\n";
        rank_card = 0;
        crazy_card = 0;
    }
    cout << "*** Currrent Hand Cards: ***" << "\n";
    hand.print();
    cout << "****************************" << "\n";
    int option = get_player_option(suit_card, rank_card, crazy_card);
    if(option == 1 && suit_card == 1){
        Card c = hand.human_get_card_by_suit(currentcard);
        discard_card(c);
        cout << "*** After adjusting hand cards: *** " << "\n";
        hand.print();
        cout << "*********************************** " << endl;
        return c;
    }
    if(option == 2 && rank_card == 1){
        Card c = hand.human_get_card_by_rank(currentcard);
        discard_card(c);
        cout << "*** After adjusting hand cards: *** " << "\n";
        hand.print();
        cout << "*********************************** " << endl;
        return c;
    }
    if(option == 3 && crazy_card == 1){
        Card c = hand.human_get_card_by_crazy();
        discard_card(c);
        cout << "*** After adjusting hand cards: *** " << "\n";
        hand.print();
        cout << "*********************************** " << endl;
        return c;
    }
}

/******************************************************
** Function: get_player_option
** Description: What option the player would like to perform
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int Player::get_player_option(bool suit_card, bool rank_card, bool crazy_card){//this function is over 20 lines due to the error handling and print statements, without them is would be
                                                                                //just about 20 lines
    int option = 0;
    bool valid = false;
    cout << "You have a card that can be played..." << endl;
    while(!valid){
        cout << "Select your option (1 - suit) (2 - rank) (3 - crazy): ";
        cin >> option;
        while(cin.fail() == 1 || (cin.fail() == 0 && (option < 1 || option > 3))){
            cout << "Invalid input! Enter again: " << endl;
            option = 0;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> option;
        }
        if(option == 1){
            if(suit_card == 0){
                cout << "You don't have a suit card to play! Pick a different option: ";
                valid = false;
            }
            else{
                valid = true;
                return option;
            }
        }
        else if(option == 2) {
            if(rank_card == 0){
                cout << "You don't have a rank card to play! Pick a different option: ";
                valid = false;
            }
            else{
                valid = true;
                return option;
            }
        }
        else if(option == 3){
            if(crazy_card == 0){
                cout << "You don't have a crazy card to play! Pick a different option: ";
                valid = false;
            }
            else{
                valid = true;
                return option;
            }
        }
    }
    
    return option;
}

Player::~Player(){

    //delete hand;
}
