class Stock
{
public:
	Stock(); 
	void add(InventoryItem item);
	~Stock(); 

private:
	InventoryItem *list; // The list of items in stock
	int count; 
	const int arraySize = 5; 
}