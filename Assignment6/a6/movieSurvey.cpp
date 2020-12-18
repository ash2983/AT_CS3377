#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "findMedian.h"
#include "findMode.h"
#include "findAverage.h"

using namespace std; 

void movieSurvey(){

  //instantiate variables
  int INTSIZE = sizeof(int);
  int size; 

  //collect array size 
  cout << "Enter the amount of students surveyed: " << endl;
  cin >> size;

  //prepare dynamic array
  int *survey = (int*) malloc(INTSIZE*size);
  int movies;

  //assign movies per student using user input 
  for(int student = 0; student < size; student++){
    movies = 0;
    cout << "Enter the amount of movies that student #" << (student + 1) << " has seen: " << endl;
    cin >> movies;
    *(survey+student) = movies;
  }

  //return the average of the survey
  cout << "Average movies per student = " << findAverage(survey, size) << endl;

  //return the mode
  cout << "Mode of survery = " << findMode(survey, size) << endl;

  //return the median
  cout << "Median of survey = " << findMedian(survey, size) << endl;

}


int main(){
	movieSurvey();
	return 0; 
}
