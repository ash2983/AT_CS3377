
movie: movieSurvey.o findAverage.o findMedian.o findMode.o
	g++ -Wall -o movie movieSurvey.o findAverage.o findMedian.o findMode.o

movieSurvey.o: movieSurvey.cpp findAverage.h findMedian.h findMode.h
	g++ -o movieSurvey.o -c movieSurvey.cpp

findAverage.o: findAverage.cpp
	g++ -o findAverage.o -c findAverage.cpp

findMedian.o: findMedian.cpp
	g++ -o findMedian.o -c findMedian.cpp

findMode.o: findMode.cpp
	g++ -o findMode.o -c findMode.cpp

clean:
	rm *.o
	rm movie
