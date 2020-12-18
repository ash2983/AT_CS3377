#include "ship.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 
//default constructor 
	Ship::Ship(){
		name = ""; 
		year = "0000";
	}

	//filled constructor
	Ship::Ship(string n, string y){
		name = n; 
		year = y; 
	}

	//accesor method for name 
	string Ship::getName(){
		return name; 
	}

	//mutator method for name 
	void Ship::setName(string n){
		name = n;  
	}

	//acessor method for year
	string Ship::getYear(){
		return year; 
	}

	//mutator method for name 
	void Ship::setYear(string y){
		year = y; 
	}

	//virtual print method 
	void Ship::print(){
		cout << "-----------------------" << endl;
		cout << "Name: " << name << endl; 
		cout << "Year: " << year << endl; 
		cout << "-----------------------" << endl;
	}
