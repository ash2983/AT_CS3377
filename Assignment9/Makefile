
out: main.o ship.o cruiseship.o CargoShip.o	
	g++ -o out main.o ship.o cruiseship.o CargoShip.o

main.o: movieSurvey.cpp
	g++ -o movieSurvey.o -c movieSurvey.cpp

ship.o: findMedian.cpp ship.h 
	g++ -o findMedian.o -c findMedian.cpp

cruiseship.o: findMode.cpp ship.h cruiseship.h
	g++ -o findMode.o -c findMode.cpp

CargoShip.o: CargoShip.cpp ship.h CargoShip.h
	g++ -o CargoShip.o -c CargoShip.cpp

clean:
	rm *.o
	rm out