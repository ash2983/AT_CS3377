#include "LinkedList.h"
#include "string.h"
#include <iostream>
using namespace std; 

int main(){

	//Create a list of 3 integers
	cout << "Let's create our Linked List object with three integers! " << endl;
	LinkedList *test;
	test = new LinkedList();
	test -> add(1);
	test -> add(2);
	test -> add(3);
	cout << "Linked List created succesfully!" << endl; 

	//Add five integers to the list
	cout << "Now, let's add 5 integers to our new Linked List {8, 4, 2, 7, 4}:" << endl;
	test -> add(4);
	test -> add(5);
	test -> add(6);
	test -> add(7);
	test -> add(8); 
	cout << "Integers added succesfully!" << endl; 

	//Display the list,
	cout << "Now, let's take a look at what our Linked List looks like: " << endl; 
	test -> display(); 

	//Remove a selected integer
	cout << "Isn't our list pretty? Now let's remove 4 from our list. " << endl; 
	test -> remove(4); 

	//Display the list
	cout << "Let's look at our list and make sure everything worked correctly: " << endl; 
	test -> display(); 

	//Empty list
	cout << "Done! Now let's empty our list and move on." < endl; 
	test -> empty(); 

	//make a list of three strings
	cout << "Cool! Now let's make a list of 3 strings." << endl; 
	LinkedList *test2;
	test2 = new LinkedList();
	test2 -> add("Apple");
	test2 -> add("Orange");
	test2 -> add("Pear");

	//add 5 strings to list 
	cout << "Success! Now, let's add 5 strings to our list." << endl; 
	test2 -> add("Pineapple");
	test2 -> add("Plum");
	test2 -> add("Peach");
	test2 -> add("Lemon");
	test2 -> add("Grape");

	//display list
	cout << "Let's look at our list and make sure everything worked correctly: " << endl; 
	test2 -> display(); 

	// Remove a selected string
	cout << "Let's remove Apple from our list." << endl; 
	test2 -> remove("Apple");

	//Display the list
	cout << "Is it gone?" << endl;
	test2 -> display(); 

	//Empty the list and exit
	cout << "Seems like everything is in tip top shape! Let's empty the list and exit our program!" << endl; 
	test2 -> empty(); 

	return 0; 
}	
