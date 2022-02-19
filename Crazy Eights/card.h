/******************************************************
** Program: card.h
** Author: Yash Sankanagouda
** Date: 4/24/2021
** Description: Contains the Card class function
** Input:
** Output:
******************************************************/
#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card{
    private:
    int suit = -1;
    int rank = -1;

    public:
    Card();
    Card(int, int);
    int get_suit();
    int get_rank();
    void set_suit(int);
    void set_rank(int);
    void print();
};

#endif