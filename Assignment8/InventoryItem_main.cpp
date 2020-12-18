#include "InventoryItem.h"
#include "Stock.h"
#include <iostream>
using namespace std; 

int main(){
	
	//Create a set of inventory objects, with initial cost and units
	InventoryItem apple = new InventoryItem("Apples", 0.67, 62);
	InventoryItem pb = new InventoryItem("Peanut Butter", 2.13, 21);
	InventoryItem cheese = new InventoryItem("Cheese", 1.13, 11);
	InventoryItem milk = new InventoryItem("Milk", 4.95, 14);
	InventoryItem bagel = new InventoryItem("Bagel", 2.43, 26);

	//Add all these items to a stock object.
	Stock grocery = new Stock(); 
	stock.add(apple);
	stock.add(pb);
	stock.add(cheese); 
	stock.add(milk);
	stock.add(bagel); 

	//Make use of the [] and << operator function overloaded.
	cout << "grocery = " << endl; 
	cout << s << endl; ; 

	cout <<"Item at index 3 is: " << s[3]; 

	//use deconstructor to delete stock
	~grocery; 

	return 0; 
}