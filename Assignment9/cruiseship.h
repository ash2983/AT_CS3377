#ifndef CRUISESHIP_H	
#define CRUISESHIP_H	
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std; 

class CruiseShip : public Ship {

private:
	int maxP; 

public:

	//default constructor
	CruiseShip();

	CruiseShip(int m, string n, string y);

	//accessor function
	int getMaxPassengers();

	//mutator function
	void setMaxPassengers(int m);

	//print function 
	virtual void print();

};
#endif