#include "Stock.cpp"
#include <iostream>
using namespace std; 

int main(){
	
	//Create a stock object
	Stock* groceries = new Stock();

	//add items to stock object
	groceries -> add("Bread", 1.14, 23);
	groceries -> add("Beef", 6.32, 15);
	groceries -> add("Pepper", 3.78, 45);
	groceries -> add("Apple", 0.74, 67);
	groceries -> add("Milk", 4.35, 32);

	//initialize variables for buying method 
	bool buyer = true; 
	char yn; 
	int choice; 

	//loop through options while buyer wants to purchase 
	while(buyer){

		//ask buyer if they want to look at inventory
		cout << "Would you like to see our inventory? (y/n): " << endl; 
		cin >> &yn; 

		//if buyer answered yes, show inventory
		if(yn == 'y' || yn == 'Y'){
			cout << *groceries; 
		}

		//ask what buyer wants to purchase
		cout << "What would you like to purchase {Bread = 1, Beef = 2, Pepper = 3, Apple = 4, Milk = 5}? " << endl;
		cin >> choice; 

		//use if/else statements to edit InventoryItems in Stock
		switch(choice){
			case 1:
				(*groceries)[0].purchase();
				break;
			case 2:
				(*groceries)[1].purchase();
				break;
			case 3:
				(*groceries)[2].purchase();
				break;
			case 4:
				(*groceries)[3].purchase();
				break;
			case 5:
				(*groceries)[4].purchase();
			default:
				cout << "Sorry, we don't have that item in stock." << endl;
				break; 
		}

		//ask if buyer wants to make another purchase
		cout << "Would you like to make another purchase? (y/n): " << endl; 
		cin >> &yn; 

		//if buyer answered yes, prepare to restart the loop
		if(yn == 'y' || yn == 'Y'){
			buyer = true; 
		}else{
			buyer = false;
		}

	}

	//delete objects
	delete(groceries); 

	//add items to new stock object
	return 0; 
}
