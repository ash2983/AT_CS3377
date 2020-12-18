#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std; 

template <class T>

class LinkedList{

private:

	//create inner node class
	struct ListNode{
		T data; 
		struct ListNode *next; 
	}; 

	//head node
	ListNode *head;

public:
	//constructor 
	LinkedList();
	//add item to end of list
	void add(T n);
	//display list 
	void display();
	//remove an integer
	void remove(T n); 
	//empty the list 
	void empty();
	//accesor method for head
	ListNode* getHead();
	//I used some code from the website provided in the assignment description.
	//I will mention what I used when in the LinkedList.cpp file. 
	//forward declaration for Iterator class
	class Iterator; 
	//create new Iterator 
	Iterator begin();
	//end of Iterator
	Iterator end(); 
	//nested Iterator class here
	class Iterator{
	private:
		ListNode *current;
	public:
		//constructors 
		Iterator();
		Iterator(ListNode *head);
		Iterator(LinkedList& list); 
		//begin method for creating new iterator
		Iterator& operator=(ListNode* node);
		Iterator& operator++();
		Iterator operator++(int); 
		bool operator!=(const Iterator& iterator); 
		int operator*();
	};

};
#endif
