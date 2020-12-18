/*
Part 1 - In statistics, the mode of a set of values is the value that occurs most often.
Write a function that finds the mode of a set of values. This will be the value with the greatest
frequency.

 If none of the data is repeats more than once, it should return -1.

Use a dynamically allocated memory for the data.

The function should accept the data array passed by reference.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

int findMode(int *arr, int size){

 
  int* mode = (int*) (malloc(sizeof(int)));
  int* element = (int*) (malloc(sizeof(int)));
  int* innerElement = (int*) (sizeof(int));
  int* count = (int*) (sizeof(int));
  int* maxCount = (int*) (sizeof(int));

  //loop through the array
  for(int index = 0; index < size; index++){
    *element = *(arr + index);
    *count = 0;

      cout << "OUTER LOOP" << endl; 

      //loop through array
      for(int inner = 0; inner < index; inner++){
        *innerElement = *(arr + inner);

        cout << "INNER LOOP" << endl; 
        //if occurances of element found, increase frequency
        if(*innerElement == *element)
          *count = (*count) + 1;

      }
 
      //check if frequency is more than current mode
      if(*count > *maxCount){
        *maxCount = *count;
        *mode = *element;
      }

  }

  cout << "RETURN" << endl; 
  //return the mode with largest frequency
  if(*maxCount != 0){
    return *mode;

  //or return -1 if there is no such mode
  }else{
    return -1;
  }
}

int main(){

int size = 3; 
int *array = new int[3]; 
array[0] = 1; 
array[1] = 2;
array[2] = 2;

cout << "mode = " << findMode(array, size) <<endl; 
return 0; 
}

