#include "LinkedList.h"
#include <iostream>
using namespace std; 

int main(){

	//Create a list of integers
	cout << "Let's create our Linked List object! " << endl;
	LinkedList *test;
	test = new LinkedList();
	cout << "Linked List created succesfully!" << endl; 

	//Add five integers to the list
	cout << "Now, let's add 5 integers to our new Linked List {8, 4, 2, 7, 4}:";
	test -> add(8);
	test -> add(4);
	test -> add(2);
	test -> add(7);
	test -> add(4); 
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

	//test iterator
	cout << "Now, let's test our iterator: " <<endl; 
	LinkedList::Iterator it = test -> begin();

	while(it != test -> end()){
		cout << *it << " " << endl; 
		it++; 
	}
	cout << endl << "Seems our iterator works well enough! " << endl; 

	//Done!
	cout << "Hooray! Everything works fine so far. Let's empty our Linked List and exit the program. " << endl;
	test -> empty(); 
	test -> display(); 

	return 0; 
}
