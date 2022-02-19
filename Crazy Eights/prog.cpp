/******************************************************
** Program: prog.cpp
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: main function of the whole code
** Input: n/a
** Output: the players turns
******************************************************/
#include "card.h"
#include "game.h"
#include "player.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: main
** Description: Puts the flow of the game all together
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int main(){ //This is the flow of the game, so it is very hard to reduce the number of lines. This function is 34 lines.

    //start the game, init the deck, shuffle the deck
    Game mygame;
    int current_suit = -1;
    //init the players
    mygame.set_player();
    bool alternate = true;
    int currentplayerindex = 0;
    //get current card for the game
    Card currentcard = mygame.deal_a_card();
    while(alternate){
        //first player's turn
        cout << "----------------------------------------------------" << endl;
        cout << "Player " << mygame.get_player_name(currentplayerindex) << " turn" << "\n";
        bool winner = false;
        bool play = mygame.will_play(currentcard, currentplayerindex); //check if player has cards to play
        bool loop_play = true;
        while(loop_play){        
            if(play){
                currentcard = mygame.get_player_card(currentplayerindex, currentcard, current_suit);
                if(current_suit > -1){
                    current_suit = -1;
                }
                current_suit = mygame.check_crazy_eight(currentcard, currentplayerindex);
                loop_play = false; 
                cout << "Player " << mygame.get_player_name(currentplayerindex) << " plays card: " << "\n";
                currentcard.print();
                winner = mygame.determne_winner(currentplayerindex);
            }
            else{
                bool deck_cards = mygame.deck_has_cards();
                if(deck_cards){
                    cout << "Player has no card! Draws a card! " << "\n";
                    Card c = mygame.deal_a_card();              
                    mygame.adjust_player_hand(c, currentplayerindex);
                    play = mygame.will_play(currentcard, currentplayerindex);            
                }
                else{
                    winner = mygame.determne_winner(currentplayerindex);
                    break;
                }
            }
        }
        if(winner){
            alternate = false;
        }
        else{
            currentplayerindex = mygame.alternate_player(currentplayerindex);
        }
    }
    return 0;
}