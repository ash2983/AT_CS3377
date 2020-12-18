#ifndef SHIP_H	
#define SHIP_H	
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std; 

class Ship{

protected:
	string name; 
	string year; 

public: 

	//default constructor 
	Ship();

	//filled constructor
	Ship(string n, string y);

	//accesor method for name 
	string getName();

	//mutator method for name 
	void setName(string n); 

	//acessor method for year
	string getYear();

	//mutator method for name 
	void setYear(string y);

	//virtual print method 
	virtual void print();

};
#endif 
