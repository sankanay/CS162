/******************************************************
** Program: linked_list.cpp
** Author: Yash Sankanagouda
** Date: 6/6/2021
** Description: Initlialize the linked list class
** Input:
** Output:
******************************************************/
#include "linked_list.h"
#include <iostream>
#include "node.h"
using namespace std;


/******************************************************
** Function: Linked_List
** Description: constructor to assignment values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Linked_List::Linked_List(){

    length = 0;
    head = NULL;
}

/******************************************************
** Function: get_length
** Description: get value of length
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int Linked_List::get_length(){

    cout << length << endl; //print length of linked list
    return length;
}

/******************************************************
** Function: isEmpty
** Description: check is the list is empty
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool Linked_List::isEmpty(){

    if(length == 0){
        return true;
    }
    return false;
}

/******************************************************
** Function: print
** Description: print the linked list
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Linked_List::print(){
    
    if(isEmpty()){
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

/******************************************************
** Function: prime_numbers
** Description: print the prime numbers from list
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Linked_List::prime_numbers(){

    cout <<  "Prime numbers: ";
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp->val == 0 || temp->val == 1){
        }
        else{
            bool prime = true;
            for(int j = 2; j <= (temp->val)/2; j++){
                if((temp->val) % j == 0){
                    prime = false;
                    break;
                }
            }
            if(prime){
                cout << temp->val << " ";
                count++;
            }
        }
        temp = temp->next;
    }
    cout << endl;
    cout << "There are " << count << " prime numbers." <<  endl;
}

/******************************************************
** Function: clear
** Description: clear the list and reset length
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Linked_List::clear(){

    cout << "Linked list length: " << length << endl;
    length = 0;
    Node *temp_curr = head;
    Node *temp_next = NULL;
    cout << "Clearing list..." << endl;
    while(temp_curr != NULL){
        temp_next = temp_curr->next;
        delete temp_curr;
        temp_curr = temp_next;
    }
    print();
}

/******************************************************
** Function: push_front
** Description: push the list in front
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

unsigned int Linked_List::push_front(int data){

    if(isEmpty()){
        Node *temp = new Node();
        temp->val = data;
        temp->next = NULL;
        head = temp;
    }
    else{
        Node *temp = new Node();
        temp->val = data;
        temp->next = head;
        head = temp;  
    }
    return length++;
}

/******************************************************
** Function: push_back
** Description: push the list bakc to original position
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

unsigned int Linked_List::push_back(int data){

    if(isEmpty()){
        Node *temp = new Node();
        temp->val = data;
        temp->next = NULL;
        head = temp;
    }
    else{
        Node *temp_curr = head;
        while(temp_curr->next != NULL){
            temp_curr = temp_curr->next;
        }
        Node *temp = new Node();
        temp->val = data;
        temp->next = NULL;
        temp_curr->next = temp;
    }
    return length++;
}

/******************************************************
** Function: insert
** Description: ability to insert a node
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

unsigned int Linked_List::insert(int data, unsigned int index){

    Node *pre = NULL;
    Node *post = NULL;
    Node *current = head;
    int counter = 1;

    while(counter != index && current != NULL){
        if(counter == (index - 1)){
            pre = current;
        }
        if(counter == index){
            post = current;
        }
        current = current->next;
        counter++;
    }
    Node *temp = new Node();
    temp->val = data;
    temp->next = post;
    pre->next = temp;
    length++;
}

/******************************************************
** Function: sort_ascending
** Description: function to call the merge sort for ascending
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Linked_List::sort_ascending(){

    cout << "Sorted in ascending: ";
    merge_sort(&head, 'a');
    print();
    prime_numbers();

}

/******************************************************
** Function: sort_descending
** Description: function to call the merge sort for descending
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Linked_List::sort_descending(){

    cout << "Sorted in descending: ";
    merge_sort(&head, 'd');
    print();
    prime_numbers();

}

/******************************************************
** Function: split_list
** Description: splits the list to perform merge sort
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Linked_List::split_list(Node* a, Node** f, Node** b){      //https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort

    Node* ptr1;
    Node* ptr2;
    ptr2 = a;
    ptr1 = a->next;
    while (ptr1 != NULL) { //ptr1 and ptr2 is incrmented
        ptr1 = ptr1->next;
        if (ptr1 != NULL) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }
    *f = a;
    *b = ptr2->next; // ptr2 is middle
    ptr2->next = NULL;
}

/******************************************************
** Function: merge_sortedList
** Description: recursively sort
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Node* Linked_List::merge_sortedList(Node* a, Node* b, char option){

    Node* result = NULL;

    // Base Cases
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if(option == 'a'){
    // recursively merging two lists
        if (a->val <= b->val){
        //if (lst1->val >= lst2->val){
            result = a;
            result->next = merge_sortedList(a->next, b, option);
        }
        else {
            result = b;
            result->next = merge_sortedList(a, b->next, option);
        }
    }
    else if(option == 'd'){
        if (a->val >= b->val){
            result = a;
            result->next = merge_sortedList(a->next, b, option);
        }
        else {
            result = b;
            result->next = merge_sortedList(a, b->next, option);
        }
    }
    return result;
}

/******************************************************
** Function: merge_sort
** Description: puts the functions to sort together
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void Linked_List::merge_sort(Node** temp, char option){
    Node* head = *temp;
    Node* ptr1;
    Node* ptr2;

    // Base Case
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Splitting list
    split_list(head, &ptr1, &ptr2);

    merge_sort(&ptr1, option);
    merge_sort(&ptr2, option);

    *temp = merge_sortedList(ptr1, ptr2, option);
}

/******************************************************
** Function: Linked_List
** Description: de allocated the values
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

Linked_List::~Linked_List(){

    length = 0;
    head = NULL;

}