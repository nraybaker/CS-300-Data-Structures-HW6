/***************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #6
*/
#include "node.hpp"
#include "bst.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//typedef to make more readable since phone numbers are stored as long long
typedef long long phone_number;

int main()
{
	cout.precision(10);
	BST bst;
	
	bool state = true;
	do
	{
		int option;
		do
		{
			//Creating menu with options
			cout << "Please select an option number: " << endl;
			cout << "(1) Add a name and phone number to the tree" << endl;
			cout << "(2) Delete a number from the tree" << endl;
			cout << "(3) Search for a number within the tree" << endl;
			cout << "(4) Traverse tree and print to screen in pre-order" << endl;
			cout << "(5) Traverse tree and print to screen in in-order" << endl;
			cout << "(6) Traverse tree and print to screen in post-order" << endl;
			cout << "(0) Press 0 to quit" << endl;
			cin >> option;
			cout << endl;
			if(!((option == 1) | (option == 2) | (option == 3) | (option == 4) | (option == 5) | (option == 6) | (option == 0)))
			{	
				cerr << "Invalid option entered, please enter from (1, 2, 3, 4, 5, 6, or 0)" << endl;
			};
		} while(!((option == 1) | (option == 2) | (option == 3) | (option == 4) | (option == 5) | (option == 6) | (option == 0)));
		
		switch(option)
		{
			//option 1: add to tree
			case 1:
			{
				phone_number num;
				string name;
				cout << "Enter number to add: ";
				cin >> num;
				cout << endl;
				
				cin.ignore();
				cout << "Enter name to add: ";
				getline(cin, name);
				cout << endl << endl;
				
				bst.insert(num, name);
				break;
			}
			
			//option 2 delete from tree
			case 2:
			{
				phone_number num;
				cout << "Enter number to delete: ";
				cin >> num;
				cout << endl << endl;
				
				bst.delete_node(num);
				break;
			}
			
			//option 3: search in tree
			case 3:
			{
				phone_number num;
				cout << "Enter number to search for: ";
				cin >> num;
				cout << endl;
				
				Node* n = bst.search(num, bst.get_root());
				if(n != NULL)
					cout << n -> get_name() << " " << n -> get_number() << endl;
				else
					cout << "Number not found in tree." << endl;
				cout << endl;
				break;
			}
			
			//option 4: traverse in preorder
			case 4:
			{
				bst.traverse_preorder(bst.get_root());
				cout << endl;
				break;
			}
			
			//option 5: traverse in inorder
			case 5:
			{
				bst.traverse_inorder(bst.get_root());
				cout << endl;
				break;
			}
			
			//option 6: traverse in postorder
			case 6:
			{
				bst.traverse_postorder(bst.get_root());
				cout << endl;
				break;
			}
			
			//option 0: exit options
			case 0:
			{
				state = false;
				cout << "Quitting Program and printing tree to file in pre-order" << endl;
				break;
			}
		}
	}while(state);
	
	//print tree to file "tree.dat"
	bst.print_tree();
	
	return(0);
}
