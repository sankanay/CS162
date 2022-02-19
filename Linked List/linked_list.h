/******************************************************
** Program: linked_list.h                                                                                             
** Author: Yash Sankanagouda
** Date: 6/6/2021
** Description: Base linked list class
** Input:
** Output:
******************************************************/
#ifndef LINKED_H
#define LINKED_H
#include "node.h"

class Linked_List {
   private:
      unsigned int length;
      Node *head;
   public:
      Linked_List();
      int get_length();
      bool isEmpty();
      void print();
      void prime_numbers();
      void clear(); 
      unsigned int push_front(int); 
      unsigned int push_back(int); 
      unsigned int insert(int, unsigned int); 
      void sort_ascending(); 
      void sort_descending(); 
      void split_list(Node*, Node**, Node**);
      Node* merge_sortedList(Node*, Node*, char);
      void merge_sort(Node**, char);
      ~Linked_List();
};

#endif