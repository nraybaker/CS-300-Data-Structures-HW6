/*******************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #6
	 
	 
	Description of the problem:
		This node class is used to define the properties of the nodes in the
		binary search tree

	Psuedo Code:
	Class Name: Node

		Data:
			phone number - the phone number of the node used as the key
			name - the name the number belongs to
			level - keeps track of the nodes level
			left - the left node pointer
			right - the right node pointer
	
		Mutator Functions:
		
			Function: set_left
				mutator function to set the left pointer to some other node
				Input: where the point should point to
				Outputs: None
				Return: N/A (Just sets the pointer)
				 
			Function: set_right
				mutator function to set a right pointer to some other node
				Input: The node to set the pointer to
				Output: None
				Return: N/A (Just sets the pointer)
				
			Function: set_number
				mutator function to set the number of the node
				Input: the phone number to set the node's number to
				Output: None
				Return: None
			
		
		Accesor Functions:
		
			Funtion: get_left
				Accessor function get the left node the node is pointing to
				Input: None
				Output: None
				Return: Memory location of the node left of the current node
					in the BST
			
			Function: get_right
				Accessor function to access the location of the node right
					of the current node in the BST
				Input: None
				Output: Node
				Return: Memory location of the node right of current node in the BST
			
			Function: get_number
				Accessor function to get the number of the node
				Input: None
				Output: None
				Return:	the phone number
		
			Function: get_name
				Accessor function to get the name of the node
				Input: None
				Output: None
				Return: the name
				
			Function: get_level
				Accessor function to get the level of the node
				Input: None
				Output: None
				Return: the level of the node
		
		
		Class Functions:
			Function: Node
				Default constructor to set name to blank, number to 0 and pointers
					to NULL
				Inputs: None
				Outputs: None
				Return: N/A (defaults to above)
		
			Function: Node
				constructor that number and name
				Inputs: phone number and name
				Outputs: None
				Return: N/A
					number = number passed in
					name = name passed in
				
			Function: compare_name
				compare a given name against the one in the node
				Inputs: a name to compare to
				Outputs: None
				Return: True if same name, false if not
			 
			Function: compare_number
				Compare a number against the one in the node
				Inputs: a given number
				Outputs: None
				Return: 1 if compare number is greater than node number
						0 if compare numbe is equal to the node number
					   -1 if compare number is less than the node number
			
			Function: process
				function that will print the data
				Inputs: None
				Outputs: the data the node contains: phone number and name
				Return: N/A
*/	
#include <iostream>
using namespace std;
typedef long long phone_number;

#ifndef NODE_H
#define NODE_H
//Node class
class Node
{
	//Data for Node class
	phone_number phn_number;
	string name;
	int level;
	Node *left;
	Node *right;
public:
	Node();
	Node(phone_number num, string nme, int lvl);
	void set_left(Node *ptr);
	void set_right(Node *ptr);
	void set_number(phone_number phn_num);
	Node *get_left();
	Node *get_right();
	string get_name();
	phone_number get_number();
	int get_level();
	bool compare_name(string nme_compare);
	int compare_number(phone_number num_compare);
	void process();
};
#endif
