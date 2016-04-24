/*******************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #6
	 
	 
	Psuedo Code:
	Class Name: BST
	 
		Data:
			root - will point to the root
		 
		Class Functions:
			
			Function: BST
				Default contructor
				Input: None
				Output: None
				Return: NA 
					Just creates the binary search tree with root set to NULL
			
			Function: ~BST
				Deconstructor - destroys the tree
				Input: None
				Output: None
				Return: N/A 
					IDestroys the tree
				
			Function: get_root
				Returns the root of the tree
				Input: None
				Output: None
				Return: root of the tree
				
			Function: search
				searches for a node in the tree with a given key
				Input: the key to search for and the leaf to start the search on
				Output: None
				Return: the node if found or NULL if not found
			
			Function: insert (public)
				insert a node with data into the tree
				Input: the phone number key and the name the number belongs to
				Output: None
				Return: None
					Starts the insert algorithm and calls the private insert
						function if needed

			Function: insert (private)
				continues insert function on a different node
				Input: phone number key, name, and node to insert from
					level that keeps track of the node's level
				Output: None
				Return: None
					Used for the recursion of the insert function
				
			Function: delete_node (public)
				Begins the delete algorithm on the root of the tree
				Input: the phone number as a key
				Output: N/A
				Return: N/A | Starts the delete algorithm and searches for 
					the node to delete, if not found will recursively call the 
					private delete function to continue searching for the node to
					delete
					
			Function: delete_node (private)
				continues the delete_node function on a different node
				Input: the phone number as a key, and the node to start the search
					from
				Output: N/A
				Return: Node to become the new root of the subtree
					Recursively searches for the new node and will replace that node
					according to some algorithm
					
			Function: traverse_preorder
				traverses the tree in preorder printing the data of each node
				Input: the node to start the preorder traversal from
				Output: the data from the node in preorder
				Return: None
					Recursively prints the tree in preorder
					
			Function: traverse_inorder
				traverses the tree in inorder printing the data of each node
				Input: the node to start the inorder traversal from
				Output: the data from the node in inorder
				Return: None
					Recursively prints the tree in inorder
					
			Function: traverse_postorder
				traverses the tree in postorder printing the data of each node
				Input: the node to start the postorder traversal from
				Output: the data from the node in postorder
				Return: None
					Recursively prints the tree in postorder
					
			Function: level_order
				used to print the tree to a file called tree.dat in indented notation
					in preorder
				Input: the node to start from
				Output: None
				Return: None
					Places the nodes onto a queue in preorder and prints them to the 
						file
			
			Function: print_tree
				used to call the level_order function
				Input: none
				Output: only what level_order prints
				Return: None
				
			Function: destroy_tree (private)
				called by the ~BST destructor function to destroy the tree
				Input: the node to begin destroying the tree from
				Output: None
				Return: None
					Destroys the tree
					
			Function: min_value_node (private)
				called by the delete_node function to find the leftmost node
					of the subtree
				Input: the node the find the leftmost node from
				Output: None
				Return: the leftmost node		
*/
#include "node.hpp"
typedef long long phone_number;
#ifndef BST_H
#define BST_H
class BST
{
	Node *root;

	
	void destroy_tree(Node* leaf);
	void insert(phone_number key, string nme, Node* leaf, int lvl);
	Node* delete_node(Node* root, phone_number key);
	Node* min_value_node(Node* node);
public:
	BST();
	~BST();
	Node* get_root();
	Node* search(phone_number key, Node* leaf);
	void insert(phone_number key, string nme);
	void delete_node(phone_number key);
	void traverse_preorder(Node* leaf);
	void traverse_postorder(Node* leaf);
	void traverse_inorder(Node* leaf);
	void level_order(Node* n);
	void print_tree();
};
#endif

