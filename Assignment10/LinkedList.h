#include <iostream>
using namespace std; 

class LinkedList{

private:

	//create inner node class
	struct ListNode{
		int data; 
		struct ListNode *next; 
	}; 

	//head node
	ListNode *head;

public:
	//constructor 
	LinkedList();
	//add item to end of list
	void add(int n);
	//display list 
	void display();
	//remove an integer
	void remove(int n); 
	//empty the list 
	void empty(); 

	class Iterator{
	private:
		ListNode* current; 
	public: 
		//constructors 
		Iterator(); 
		Iterator(ListNode* node);
		Iterator begin();
		Iterator end(); 
		operator=(Node* node); 
		operator++(); 
		operator++(int);
		operator!=(const Iterator& iterator); 
		operator*(); 
	}

}