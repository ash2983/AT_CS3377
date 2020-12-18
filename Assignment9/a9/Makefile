
out: main.o ship.o cruiseship.o CargoShip.o	
	g++ -o out main.o ship.o cruiseship.o CargoShip.o

main.o: main.cpp
	g++ -o main.o -c main.cpp

ship.o: ship.cpp 
	g++ -o ship.o -c ship.cpp

cruiseship.o: cruiseship.cpp
	g++ -o cruiseship.o -c cruiseship.cpp

CargoShip.o: CargoShip.cpp
	g++ -o CargoShip.o -c CargoShip.cpp

clean:
	rm *.o
	rm out
