#ifndef CARGOSHIP_H	
#define CARGOSHIP_H	
#include "ship.h"

class CargoShip : public Ship {

private:
	int tonnage; 

public:

	//default constructor 
	CargoShip();

	//constructor 
	CargoShip(int t, string n, string y);

	//accessor 
	int getTonnage();

	//mutator 
	void setTonnage(int t); 

	//print 
	virtual void print(); 
};
#endif
