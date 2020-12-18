/*
Part 1 - In statistics, the mode of a set of values is the value that occurs most often.
Write a function that finds the mode of a set of values. This will be the value with the greatest
frequency.

 If none of the data is repeats more than once, it should return -1.

Use a dynamically allocated memory for the data.

The function should accept the data array passed by reference.
*/

public int findMode(int[] * arr){

  int INTSIZE = sizeOf(int);
  int* limit  = malloc(INTSIZE);
  int* mode = malloc(INTSIZE);
  int* element = malloc(INTSIZE);
  int* innerElement = malloc(INTSIZE);
  int* count = malloc(INTSIZE);
  int* maxCount = malloc(INTSIZE);

  //loop through the array
  for(int index = 0; index < limit; index++){
    *element = *(arr + index);
    *count = 0;

      //loop through array
      for(int inner = 0; inner < index; inner++){
        *innerElement = *(arr + inner);

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

  //return the mode with largest frequency
  if(*maxCount != 0){
    return *mode;

  //or return -1 if there is no such mode
  }else{
    return -1;
  }

}

//###########################################################################
//###########################################################################

/*
Another statistics function is called median. The median of a set of values is the value that lies in the
middle when the values are arranged in sorted order. If the set has an even number of values, then the
median is taken to be the average of the two middle values.
Write a function that determines the median of a sorted array. The function should take an array of
numbers and an integer indicating the size of the array and return the median of the values in the
array. You may assume the array is already sorted. Use pointer notation, and data passed by
reference.
*/

public int findMedian(int[] *arr, int size){

  int INTSIZE = sizeOf(int);
  //check if size is even or odd and act accordingly
  if( size % 2 == 0 ){
    int *lowerMidIndex = malloc(INTSIZE);
    *lowerMidIndex = (size/2);
    int *median1 = malloc(INTSIZE);
    *median1 = *(arr+lowerMidIndex);
    int *higherMidIndex = malloc(INTSIZE);
    *higherMidIndex = (size/2) + 1;
    int *median2 = malloc(INTSIZE);
    *median2 = *(arr+higherMidIndex);
    int *median malloc(INTSIZE);
    *median = (*median1 + *median2)/2;
    return *median;
  }else{
    int *midIndex = malloc(INTSIZE);
    *midIndex = (size/2) + 1;
    int *median = malloc(INTSIZE);
    *median = *(arr+midIndex);
    return *median;
  }

}

//##############################################################################
//##############################################################################
/*
Write a program that can be used to gather statistical data about the number of movies college
students see in a month. The program should ask the user how many students were surveyed and
dynamically allocate an array of that size. The program should then allow the user to enter the
number of movies each student has seen. The program should then calculate the average, median, and
mode of the values entered, using the two functions you developed in part 1 and 2
*/
public int movieSurvey(){

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
