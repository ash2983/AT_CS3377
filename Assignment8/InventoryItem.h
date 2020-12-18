class InventoryItem
{
	public:
	// Constructor
	InventoryItem(char *desc, double cost, int units, int number_articles);
	// Destructor
	~InventoryItem();
	const char *getDescription() const;
	double getCost() const;
	int getUnits() const;
	static int getNumberArticles(); 

	private:
	char *description; // The item description
	double cost; // The item cost
	int units; // Number of units on hand
	static int number_articles //how item articles are sold 
}