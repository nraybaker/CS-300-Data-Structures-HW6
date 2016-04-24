/***************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #6
*/
#include "node.hpp"
#include <iostream>
using namespace std;
typedef long long phone_number;

//Default constructor
Node::Node()
{
	phn_number = 0;
	name = " ";
	level = 0;
	left = NULL;
	right = NULL;
}

//Non-default constructor
Node::Node(phone_number num, string nme, int lvl)
{
	phn_number = num;
	name = nme;
	level = lvl;
	left = NULL;
	right = NULL;
}

//set_left mutator function
void Node::set_left(Node *ptr)
{
	left = ptr;
}

//set_right mutator function
void Node::set_right(Node* ptr)
{
	right = ptr;
}

//set_number mutator function
void Node::set_number(phone_number phn_num)
{
	phn_number = phn_num;
}

//get_left accessor function
Node* Node::get_left()
{
	return(left);
}

//get_right accessor function
Node* Node::get_right()
{
	return(right);
}

//get_name accessor function
string Node::get_name()
{
	return(name);
}

//get_number accessor function
phone_number Node::get_number()
{
	return(phn_number);
}

//get_level accessor function
int Node::get_level()
{
	return(level);
}

//compares number in node with a given number
int Node::compare_number(phone_number num_compare)
{
	if(phn_number < num_compare)
		return(1);
	else if(phn_number > num_compare)
		return(-1);
	else
		return(0);
}

//compares name in node with a given name
bool Node::compare_name(string nme_compare)
{
	if(name == nme_compare)
		return(true);
	else
		return(false);
}

void Node::process()
{
	cout << name << " - " << phn_number << endl;
}



