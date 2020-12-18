#include "Stock.h" 
#include <iostream>
#include <stdexcept>

using namespace std; 

//Stock contructor 
Stock::Stock(){
	list = new InventoryItem[arraySize]; 
	count = 0;
	cout << "Stock created." << endl; 
}

//empty deconstructor 
Stock::~Stock(){
	cout << "Stock deleted." << endl;
}

InventoryItem Stock::getItem(int i ){
	return list[i]; 
}

int Stock::getCount(){
	return count; 
}

//overload the [] operator 
InventoryItem& Stock::operator[](int index){

	if(index > count || index < 0)
		throw invalid_argument("Index is out of bounds.");

	return list[index];
}

//overload << operator 
ostream& operator<<(ostream& os, Stock& s){
	
	os << "Current Stock: " << endl; 

	for(int i = 0; i < s.getCount(); i++){
		os << "Item: " << s.getItem(i).getDescription(); 
		os << " Cost: " << s.getItem(i).getCost();
		os << " Amount: " << s.getItem(i).getUnits();
		os << " Number of Articles: " << s.getItem(i).getNumberArticles() << endl; 
	}

	return os; 
}

//add item to stock 
void Stock::add(InventoryItem item){

	if(count >= arraySize)
		throw std::invalid_argument("Stock is full.");

	list[count] = item; 
	count++; 
}

//add item to stock 
void Stock::add(char *d, double c, int u){

	if(count >= arraySize)
		throw std::invalid_argument("Stock is full.");

	InventoryItem* item = new InventoryItem(d, c, u);

	list[count] = *item; 
	count++; 
}
