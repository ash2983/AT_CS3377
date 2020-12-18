#include <iostream>
#include <string.h>
#include "ship.h"
#include "cruiseship.h"
#include "CargoShip.h"
using namespace std; 

int main(){

	//Demonstrate the classes in a program that has an array of Ship pointers.(Need to be dynamic, of
	//type Ship pointers, in order to show case polymorphism) 
	cout << "Time to test our ship classes! We'll start by initializing an array of Ship objects: " << endl; 

	//The array elements should be initialized
	//with the addresses of dynamically allocated Ship,  CruiseShip, and CargoShip objects
	Ship *test[3]; 
	test[0] = new Ship();
	test[1] = new CruiseShip(); 
	test[2] = new CargoShip();

	//The program should then
	//step through the array, calling each object’s print function. The size of the array does not matter, as
	//long as you create one of each.
	cout << "Next, we'll test each object's print function: ";

	for(int i = 0; i < 3; i++){
		test[i] -> print(); 
	}

	cout << "Ship objects created! Next, we'll test our mutator methods to change their attributes. " << endl;
	test[0] -> setName("Annie");
	test[0] -> setYear("1900"); 
	test[0] -> print(); 

	CruiseShip* beth = (CruiseShip*) test[1]; 
	beth -> setName("Beth");
	beth -> setYear("1810"); 
	beth -> setMaxPassengers(500);
	beth -> print(); 

	CargoShip* candice = (CargoShip*) test[2];
	candice -> setName("Candice");
	candice -> setYear("1710"); 
	candice -> setTonnage(700);
	candice -> print(); 
 
 	cout << "Looks like each object type works, it's time to end our program!" << endl;
	return 0; 

}
