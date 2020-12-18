out: main.o LinkedList.o
	g++ -o out main.o LinkedList.o

main.o: main.cpp LinkedList.h
	g++ -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

clean:
	rm *.o 
	rm out
