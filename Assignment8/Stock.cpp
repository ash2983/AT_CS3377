#include "Stock.h" 
using namespace std; 

//Stock contructor 
Stock::Stock(){
	list = new InventoryItem[arraySize]; 
	count = 0; 
}

//empty deconstructor 
Stock::~Stock(){

}

//overload the [] operator 
InventoryItem& Stock::operator[](int index){

	if(index > count || index < 0)
		throw invalid_argument("Index is out of bounds.");

	return list[index];
}

//overload << operator 
ostream& operator<<(ostream& out, Stock& s){
	
	cout << "Current Stock: " << endl; 

	for(int i = 0; i < count; i++){
		cout << "Item: " << s[i].getDescription(); 
		cout << " Cost: " << s[i].getCost();
		cout << " Amount: " << s[i].getUnits();
		cout << " Number of Articles: " << s[i].getNumberArticles() << endl; 
	}

	return out; 
}

//add item to stock 
void Stock::add(InventoryItem item){

	if(count >= arraySize)
		throw illegal_argument("Stock is full.");

	list[count] = item; 
	count++; 
}