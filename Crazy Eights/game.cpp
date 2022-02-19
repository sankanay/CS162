/******************************************************
** Program: game.cpp
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Accomplishes the strutcure of the game
** Input:
** Output:
******************************************************/
#include "game.h"
#include "player.h"
#include <iostream>
#include <string>
using namespace std;

/******************************************************
** Function: shuffle
** Description: shuffles the deck
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Game::shuffle(){

    deck.shuffle();

}

/******************************************************
** Function: get_player_name
** Description: return the name of the players and store it into the index
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
string Game::get_player_name(int currentplayerindex){

    return players[currentplayerindex].get_name();
}

/******************************************************
** Function: set_player
** Description: set the players names
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Game::set_player(){

    string player_name;
    cout << "Enter player 1 name: " << endl;
    cin >> player_name;
    players[0].set_name(player_name);
    players[1].set_name("CPU");
    //give players the topmost 7 cards
    set_player_hand();
    deck_has_cards();
}

/******************************************************
** Function: print_player_hand
** Description: print the players hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Game::print_player_hand(){
    players[0].get_hand().print();
}

/******************************************************
** Function: set_player_hand
** Description: print both the players hand
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Game::set_player_hand(){

    cout << "Player one hand assignment: " << "\n";
    deck.get_random_cards_one(players[0]);
    players[0].get_hand().print();

    cout << "Player two hand assignment: " << "\n";
    deck.get_random_cards_one(players[1]);
    players[1].get_hand().print();
}

/******************************************************
** Function: deal_a_card
** Description: deal a card from the deck
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Game::deal_a_card(){

    Card c = deck.draw_card();
    c.print();
    deck_has_cards();
    return c;
}

/******************************************************
** Function: will_play
** Description: print the current card in play
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
bool Game::will_play(Card currentcard, int player){

    cout << "Current Card: ";
    currentcard.print();
    bool play = players[player].will_play(currentcard);
    return play;
}

/******************************************************
** Function: get_current_card
** Description: assigned the value into deck and return the value into c
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Card Game::get_current_card(){

    Card c = deck.draw_card();
    return c;
}

Card Game::get_player_card(int player, Card currentcard, int current_suit){

    if(player == 1){
        Card c = players[player].player_place_card(currentcard, current_suit);
        return c;
    }
    else if (player == 0){
        Card c = players[player].human_player_place_card(currentcard, current_suit);
    }
    
}

/******************************************************
** Function: adjust_player_hand
** Description: Before and after the cpu plays the card
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
void Game::adjust_player_hand(Card c, int player){

    cout << "Before adjusting player hand: " << "\n";
    players[player].get_hand().print();
    players[player].add_card(c);
    cout << "After adjusting player hand: " << "\n";
    players[player].get_hand().print();
    
}

/******************************************************
** Function: determne_winner
** Description: determines the winner of the game
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
bool Game::determne_winner(int currentplayer){

    if(players[currentplayer].get_hand().get_card_count() == 0){
        cout << "Player " << currentplayer << " is the winner! " << "\n";
        return true;
    }
    if(deck.get_card_count() == 0){
        int currentplayercards = players[currentplayer].get_hand().get_card_count();
        int otherplayer = -1;
        if(currentplayer == 0){
            otherplayer = 1;
        }
        else{
            otherplayer = 0;
        }
        int otherplayercards = players[otherplayer].get_hand().get_card_count();
        if(currentplayercards < otherplayercards){
            cout << "Player " << currentplayer << " is the winner! " << "\n";
            return true;
        }
    }
    return false;
}

/******************************************************
** Function: deck_has_cards
** Description: Prints out the number of cards that are left in the deck
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
bool Game::deck_has_cards(){

    if(deck.get_card_count() > 0){
        cout << "Deck has cards:  " << deck.get_card_count() << "\n";
        return true;
    }
    else{
        return false;
    }
}

/******************************************************
** Function: alternate_player
** Description: Alternates between the players
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int Game::alternate_player(int currentplayerindex){
    if(currentplayerindex == 0){
        currentplayerindex = 1;
    }
    else{
        currentplayerindex = 0;
    }
    return currentplayerindex;
}

/******************************************************
** Function: check_crazy_eight
** Description: Checks to see if a crazy card exists
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
int Game::check_crazy_eight(Card currentcard, int currentplayerindex){

    int option = -1;
    if(currentcard.get_rank() == 8){
        if(currentplayerindex == 0){
            cout << "You have played a crazy eight card, what suit would you like to pick? (0 - Hearts 1 - Diamonds 2 - Clubs 3 - Spades) " << "\n";
            cin >> option;
            while(cin.fail() == 1 || (cin.fail() == 0 && (option < 0 || option > 3))){
                cout << "Invalid input! Enter again: " << endl;
                option = 0;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> option;
            }
        }
        else if(currentplayerindex == 1){
            cout << "CPU played crazy eight!" << "\n";
            option == rand() % 4 + 1;
        }
    }
    return option;
}

/******************************************************
** Function: ~Game
** Description: Game destructor to deallocate the memory from players
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
//Game::~Game(){

    //delete &players[0];
    //delete &players[1];
//}
