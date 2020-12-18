class InventoryItem
{
	public:
	//Dummy Constructor 
	InventoryItem(); 
	// Constructor
	InventoryItem(char *desc, double cost, int units);
	// Destructor
	~InventoryItem();
	const char *getDescription() const;
	double getCost() const;
	int getUnits() const;
	static int getNumberArticles(); 
	bool purchase(); 

	private:
	char *description; // The item description
	double cost; // The item cost
	int units; // Number of units on hand
	static int number_articles; //how item articles are sold 
};
