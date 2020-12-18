
movie: movieSurvey.o findMedian.o findMode.o
	g++ -o movie movieSurvey.o findMedian.o findMode.o

movieSurvey.o: movieSurvey.cpp
	g++ -o movieSurvey.o -c movieSurvey.cpp

findMedian.o: findMedian.cpp
	g++ -o findMedian.o -c findMedian.cpp

findMode.o: findMode.cpp
	g++ -o findMode.o -c findMode.cpp

clean:
	rm *.o
	rm movie
