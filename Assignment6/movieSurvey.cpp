#include "findMode.h"
#include "findMedian.h"
#include <iostream>
using namespace std;

int main(){
    movieSurvey();
}

public void movieSurvey(){

  int INTSIZE = sizeOf(int);

  cout << "Enter the amount of students surveyed: " << endl;
  cin >> size;

  int[] *survey = malloc(size);
  int movies;

  for(int student = 0; student < size; student++){
    movies = 0;
    cout << "Enter the amount of movies that student #" << (student + 1) << " has seen: " << endl;
    cin << movies;
    *(survey+student) = movies;
  }

  //return the average of the survey
  cout << "Average movies per student = " << findAverage(*survey) << endl;

  //return the mode
  cout << "Mode of survery = " << findMode(*survey) << endl;

  //return the median
  cout << "Median of survey = " << findMedian(*survey, size) << endl;

}

public int findAverage(int[] *arr, int size){

  int sum = 0;

  for(int index = 0; index < size; index++){
    sum += *(arr+index);
  }

  return (sum/size);
}
