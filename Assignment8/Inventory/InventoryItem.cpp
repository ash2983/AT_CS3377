#include "InventoryItem.h" 
#include <iostream>
#include <stdexcept>
using namespace std; 

int InventoryItem::number_articles = 0; 

//dummy constructor
InventoryItem::InventoryItem()
{

}

//create constructor outside the InventoryItem class 
InventoryItem::InventoryItem(char *d, double c, int u)
{
	description = d; 
	cost = c; 
	units = u; 
	number_articles++;
	cout << "item created" << endl;
}

//empty deconstructor 
InventoryItem::~InventoryItem(){
	cout << "item deleted" << endl;	
}


//accesor method to return item description
const char* InventoryItem::getDescription() const{
	return description; 
}

//accessor method to return item cost
double InventoryItem::getCost() const{
	return cost; 
}

//accessor method to return item units 
int InventoryItem::getUnits() const{
	return units; 
}

//accesor method that returns number_articles 
int InventoryItem::getNumberArticles(){
	return number_articles; 
}

//purchase method; 
bool InventoryItem::purchase(){

	if(units <= 0)
		throw std::invalid_argument("No more left in stock."); 

	units--; 

	return true; 
}

