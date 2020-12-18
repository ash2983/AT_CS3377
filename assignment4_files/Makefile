#Makefile for Assignment 4

G = g++
C_FLAG = -c
ALL_FILES = main.cpp Automobile.cpp Car.cpp SUV.cpp Truck.cpp
O_FILES = ${ALL_FILES:.cpp=.o}

main: $(O_FILES)
	$(G) -o main $(O_FILES) 

main.o:  
	$(G) $(C_FLAG) main.cpp Car.h SUV.h Truck.h

Automobile.o:
	$(G) $(C_FLAG) Automobile.cpp

Car.o:
	$(G) $(C_FLAG) Car.cpp

SUV.o:
	$(G) $(C_FLAG) SUV.cpp

Truck.o:
	$(G) $(C_FLAG) Truck.cpp

depend:
	$(G)-MM $(ALL_FILES) > Makefile.dep 

Makefile.dep:
	touch Makefile.dep

clean:
	rm -f main *.o

include Makefile.dep
