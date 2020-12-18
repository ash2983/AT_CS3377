
output: InventoryItem_main.o Stock.o InventoryItem.o
	g++ -o output InventoryItem_main.o Stock.o InventoryItem.o 

InventoryItem_main.o: InventoryItem_main.cpp Stock.h InventoryItem.h 
	g++ -o InventoryItem_main.o -c InventoryItem_main.cpp

Stock.o: Stock.cpp Stock.h 
	g++ -o Stock.o -c Stock.cpp

InventoryItem.o: InventoryItem.cpp InventoryItem.h 
	g++ -o InventoryItem.o -c InventoryItem.cpp

clean: 
	rm *.o 
	rm output
