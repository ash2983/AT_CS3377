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
