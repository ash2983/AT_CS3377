#include "LinkedList.h"

	//constructor 
	template <typename T>
	LinkedList::LinkedList(){
		head = NULL; 
	}

	//add item to proper spot in list
	template <typename T>
	void LinkedList::add(T n){

		//create the new node item
		ListNode *item;
		item = new ListNode();
		item -> data = n; 
		item -> next = NULL; 

		//if list empty, add as head
		if(!head){
			head = item; 
		}else{
			
			ListNode *current = head; 
			ListNode *prev = NULL; 

			//loop through nodes until you find the proper placement 
			while((current) && ((current -> data) < n)){
				prev = current; 
				current = current -> next; 
			}

			//re-assign node addresses
			item -> next = current; 

			//if there is a previous node, reassign next location 
			//otherwise, new item is the new head node 
			if(prev){
				prev -> next = item; 
			}else{
				head = item; 
			}
		}
 
	}

	//display list 
	template <typename T>
	void LinkedList::display(){

		ListNode *temp; 
		temp = head; 
		int count = 0; 

		cout << "List Contains: " << endl; 

		while(temp){
			cout << "----------------------------------" << endl; 
			cout << "Index: " << count << " Item: " << temp -> data << endl;  
			cout << "----------------------------------" << endl; 
			count++; 
			temp = temp -> next; 
		}
	}

	//remove an integer
	template <typename T>
	void LinkedList::remove(T n){

		//do nothing if list empty
		if(!head){
			return; 
		//check if head is removed value 
		}else if(head -> data == n){

			head = head -> next; 

		}else{

			ListNode *current; 
			current = head; 
			ListNode *prev;
			prev = NULL;  

			//loop through values for removed value
			while ((current) && (current -> data != n)){
				prev = current; 
				current = current -> next; 
			}

			//if removed value not found, print and do nothing
			if(!current){
				cout << "Value not found in list" << endl; 
				return; 
			}

			//reassign addresses
			if(prev)
				prev -> next = current -> next; 

			//delete node
			delete(current); 

		}
 
	} 

	//empty the list 
	template <typename T>
	void LinkedList::empty(){

		//if list is empty, job done go home 
		if(!head){
			cout << "List is already empty." << endl;
			return; 
		}

		ListNode *current; 
		current = head; 
		ListNode *prev;
		prev = NULL;  

		//loop through values for removed value
		while (current){
			prev = current; 
			current = current -> next; 
			delete(prev); 
		}

		if(head)
			head = NULL; 

		cout << "Items deleted, list is empty" << endl; 

	}

	template <typename T>
	LinkedList::ListNode* LinkedList::getHead(){
		return head; 
	}

	template <typename T>
	//some of this code was used from geeksforgeeks.org
	LinkedList::Iterator::Iterator(){
		current = NULL; 
	}

	template <typename T>
	LinkedList::Iterator::Iterator(ListNode* n){
		current = n; 
	}

	template <typename T>
	LinkedList::Iterator::Iterator(LinkedList& list){
		current = list.getHead();
		 
	}

	template <typename T>
	//I borrowed some of this from geeksforgeeks.org
	LinkedList::Iterator LinkedList::begin(){
		return Iterator(*this);
	}
	
	//this was also taken from geeksforgeeks.org
	template <typename T>
	LinkedList::Iterator LinkedList::end(){
		return Iterator();
	}

	template <typename T>
	//this was also taken from geeksforgeeks.org
	LinkedList::Iterator& LinkedList::Iterator::operator=(ListNode* n){
		this -> current = n;
		return *this; 
	}

	template <typename T>
	//this was also taken from geeksforgeeks.org
	LinkedList::Iterator& LinkedList::Iterator::operator++(){
		if(current)
			current = current -> next; 

		return *this; 
	}

	template <typename T>
	//I got this from geeksforgeeks.org
	LinkedList::Iterator LinkedList::Iterator::operator++(int){
		Iterator iterator = *this; 
		++*this; 
		return iterator; 
	}

	//I got this from geeksforgeeks.org
	template <typename T>
	bool LinkedList::Iterator::operator!=(const Iterator& iterator){
		return current != iterator.current; 
	}
	
	template <typename T>
	//I got this from geeksforgeeks.org
	T LinkedList::Iterator::operator*(){
		return current -> data; 
	}
