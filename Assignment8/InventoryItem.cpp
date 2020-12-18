#include "InventoryItem.h" 
#include <iostream>
using namespace std; 

//create constructor outside the InventoryItem class 
InventoryItem::InventoryItem(char *d, double c, int u, int n)
{
	description = d; 
	cost = c; 
	units = u; 
	number_articles++; 
}

//empty deconstructor 
InventoryItem::~InventoryItem(){
	
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
static int InventoryItem::getNumberArticles(){
	return number_articles; 
}
