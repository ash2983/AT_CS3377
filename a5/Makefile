dynpipe: dynpipe.o
	g++ -o dynpipe dynpipe.o 

dynpipe.o: DynPipe.cpp
	g++ -o dynpipe.o -c DynPipe.cpp

TwoPipesTwoChildren.o: TwoPipesTwoChildren.cpp
	g++ -o TwoPipesTwoChildren.o -c TwoPipesTwoChildren.o

TwoPipesThreeChildren.o: TwoPipesThreeChildren.cpp
	g++ -o TwoPipesThreeChildren.o -c TwoPipesThreeChildren.cpp

clean:
	rm *.o
	rm dynpipe
