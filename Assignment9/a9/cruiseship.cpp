#include "ship.h"
#include "cruiseship.h" 

//default constructor
	CruiseShip::CruiseShip():Ship(){
		maxP = 0; 
	}

	CruiseShip::CruiseShip(int m, string n, string y):Ship(n, y){
		maxP = m; 
		//other variables should be inherited up to the Ship(n, y) constructor 
	}

	//accessor function
	int CruiseShip::getMaxPassengers(){
		return maxP; 
	}

	//mutator function
	void CruiseShip::setMaxPassengers(int m){
		maxP = m; 
	}

	//print function 
	void CruiseShip::print(){
		cout << "-----------------------" << endl;
		cout << "Name: " << name << endl;
		cout<< "Max Passengers: " << maxP << endl; 
		cout << "-----------------------" << endl;
	}
