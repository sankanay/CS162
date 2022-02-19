/******************************************************
** Program: node.h
** Author: Yash Sankanagouda
** Date: 6/6/2021
** Description: Base node class
** Input:
** Output:
******************************************************/

#ifndef NODE_H
#define NODE_H

class Node {
   public:
      int val;    // the value that this node stores
      Node *next; // a pointer to the next node in the list
      // you can add constructors or other functionality if you find it useful or necessary
      Node();
      ~Node();


};


#endif