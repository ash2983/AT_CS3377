#include "ship.h"
#include "CargoShip.h"

//default constructor 
	CargoShip::CargoShip(): Ship(){
		tonnage = 0; 
	}

	//constructor 
	CargoShip::CargoShip(int t, string n, string y) : Ship(n, y){
		tonnage = t; 
	}

	//accessor 
	int CargoShip::getTonnage(){
		return tonnage; 
	}

	//mutator 
	void CargoShip::setTonnage(int t){
		tonnage = t; 
	}

	//print 
	void CargoShip::print(){
		cout << "-----------------------" << endl;
		cout << "Name: " << name << endl;
		cout <<"Max Carrying Capacity: " << tonnage << " tons" << endl; 
		cout << "-----------------------" << endl;
	}
