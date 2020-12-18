#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

//quick function to find average and complete the assignment 
int findAverage(int* arr, int size){

	int sum = 0; 

	//find sum of array values 
	for(int index = 0; index < size; index++){
		sum += *(arr + index);
	}

	//return the average of the array
	return (sum/size); 


}
