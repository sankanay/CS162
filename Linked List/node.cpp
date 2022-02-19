/******************************************************
** Program: node.cpp
** Author: Yash Sankanagouda
** Date: 6/6/2021
** Description: Initlialize the node class
** Input:
** Output:
******************************************************/
#include "node.h"
#include <iostream>
using namespace std;

/******************************************************
** Function: Node
** Description: constructor to assignment values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Node::Node(){

    val = 0;
    next = NULL;
}

/******************************************************
** Function: ~Node
** Description: destructor to delete pointer
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/
Node::~Node(){

    delete next;

}


