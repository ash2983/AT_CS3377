#include "InventoryItem.cpp"

class Stock
{
public:
	Stock(); 
	void add(InventoryItem item);
	void add(char* d, double c, int u);
	~Stock();
	InventoryItem getItem(int i);  
	int getCount(); 
	InventoryItem& operator[](int i); 

private:
	InventoryItem *list; // The list of items in stock
	int count; 
	const int arraySize = 5; 
}; 
