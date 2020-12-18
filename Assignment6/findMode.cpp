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
