/***************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #6
*/
#include "bst.hpp"
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;

//default constructor
BST::BST()
{
	root = NULL;
}

//destructor
BST::~BST()
{
	destroy_tree(root);
}

//returns root
Node* BST::get_root()
{
	return(root);
}

//public insert function called first and recursively inserts from there
void BST::insert(phone_number key, string nme)
{
	int lvl = 0;
	if(root == NULL)
	{
		Node* node_ptr = new Node(key, nme, lvl);
		root = node_ptr;
	}
	else
	{
		insert(key, nme, root, lvl);
	}	
}

//private insert function to continue inserting
void BST::insert(phone_number key, string nme, Node* leaf, int lvl)
{
	lvl++;
	if(key <= leaf -> get_number())
	{
		if(leaf -> get_left() != NULL)
		{
			insert(key, nme, leaf -> get_left(), lvl);
		}
		else
		{
			Node* node_ptr = new Node(key, nme, lvl);
			leaf -> set_left(node_ptr);
		}
	}
	else
	{
		if(leaf -> get_right() != NULL)
		{
			insert(key, nme, leaf -> get_right(), lvl);
		}	
		else
		{
			Node* node_ptr = new Node(key, nme, lvl);
			leaf -> set_right(node_ptr);
		}
	}
}

//searches for a node matching a key in the tree
Node* BST::search(phone_number key, Node* leaf)
{
	int res = leaf -> compare_number(key);
	if(res == 0)
		return(leaf);
	else if(res == -1)
	{
		if(leaf -> get_left() == NULL)
			return(NULL);
		else
			return(search(key, leaf -> get_left()));
	}
	else if(res == 1)
	{
		if(leaf -> get_right() == NULL)
			return(NULL);
		else
			return(search(key, leaf -> get_right()));
	}
	return(NULL);
}

//traverse tree in preorder
void BST::traverse_preorder(Node* leaf)
{
	if(leaf != NULL)
	{
		leaf -> process();
		traverse_preorder(leaf -> get_left());
		traverse_preorder(leaf -> get_right());
	}
}

//traverse tree in postorder
void BST::traverse_postorder(Node* leaf)
{
	if(leaf != NULL)
	{
		traverse_postorder(leaf -> get_left());
		traverse_postorder(leaf -> get_right());
		leaf -> process();
	}
}

//traverse tree in inorder
void BST::traverse_inorder(Node* leaf)
{
	if(leaf != NULL)
	{
		traverse_inorder(leaf -> get_left());
		leaf -> process();
		traverse_inorder(leaf -> get_right());
	}
}

//loops down the tree to find leftmost node
Node* BST::min_value_node(Node* leaf)
{
    Node* current = leaf;
 
    // loop down to find the leftmost leaf
    while (current -> get_left() != NULL)
        current = current -> get_left();
 
    return(current);
}

//begins deleting a node matching a key
void BST::delete_node(phone_number key)
{
   root = delete_node(root, key);
}

//continues deleting a node matching a key
Node* BST::delete_node(Node* leaf, phone_number key)
{
    if(leaf == NULL)
		return(leaf);
 
    if(key < leaf -> get_number())
        leaf -> set_left(delete_node(leaf -> get_left(), key));
 
    else if(key > leaf -> get_number())
        leaf -> set_right(delete_node(leaf -> get_right(), key));
 
    else
    {
        if(leaf -> get_left() == NULL)
        {
            Node* temp = leaf -> get_right();
            delete(leaf);
            return(temp);
        }
        else if(leaf -> get_right() == NULL)
        {
            Node *temp = leaf -> get_left();
            delete(leaf);
            return(temp);
        }
 
        Node* temp = min_value_node(leaf -> get_right());
 
        leaf -> set_number(temp -> get_number());
 
        leaf -> set_right(delete_node(leaf -> get_right(), temp -> get_number()));
    }
    return(leaf);
}

//destroys the tree
void BST::destroy_tree(Node* leaf)
{
    if(leaf != NULL)
    {
       destroy_tree(leaf -> get_left());
       destroy_tree(leaf -> get_right());
       delete(leaf);
    }
}

//prints to file named "tree.dat" printing in indent notation in preorder
void BST::level_order(Node* n)
{
   queue<Node*> q;
   ofstream outfile;
   outfile.open("tree.dat", ios::trunc);
   q.push(n);
	
   while (!q.empty())
   {
       Node* v = q.front();
       int lvl = v -> get_level();
       while(lvl != 0)
       {
       		outfile << "     ";
       		lvl--;
       }
       
       
       outfile << v -> get_number() << " - " << v -> get_name() << endl;

       if (v -> get_left() != NULL)
            q.push(v -> get_left());
       
       if (v -> get_right() != NULL)
            q.push(v -> get_right());
       
       q.pop();   
   }
   outfile.close();
}

//function to start printing tree to file
void BST::print_tree()
{
	level_order(root);
}

