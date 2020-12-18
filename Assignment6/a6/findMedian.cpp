#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

int findMedian(int *arr, int size){

  int INTSIZE = sizeof(int);

  //check if size is even or odd and act accordingly
  if( size % 2 == 0 ){
    int *lowerMidIndex = (int*) malloc(INTSIZE);
    *lowerMidIndex = (size/2) - 1;

    int *median1 = (int*) malloc(INTSIZE);
    *median1 = *(arr + *lowerMidIndex);

    int *higherMidIndex = (int*) malloc(INTSIZE);
    *higherMidIndex = (size/2);

    int *median2 = (int*) malloc(INTSIZE);
    *median2 = *(arr + *higherMidIndex);

    int *median = (int*) malloc(INTSIZE);
    *median = (*median1 + *median2)/2;
    
    return *median;
  }else{
    int *midIndex = (int*) malloc(INTSIZE);
    *midIndex = (size/2);

    int *median = (int*) malloc(INTSIZE);
    *median = *(arr + *midIndex);
    
    return *median;
  }

}

