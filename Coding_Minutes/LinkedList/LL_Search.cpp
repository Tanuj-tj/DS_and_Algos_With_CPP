/*
Search
======

Complete the function which checks whether a given key is present in the Linked List or not!
Input
(lhe linked list is already created at the head pointer, you don't need to write any other functions
except the one given)
head
1 -> 2 -> 3 -> 4 -> 5 ->6 ->7
Key = 4

Output
true
Since 4 is present in the linked list, we return true.

*/

#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};


bool isPresent(node * head, int key){
    //Complete this function 
    
    node* temp = head;
    
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    
    return false;
    
    
    
    
}